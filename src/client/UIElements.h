#pragma once
#ifndef CLIENT_UI_ELEMENTS_H
#define CLIENT_UI_ELEMENTS_H


#include <Windows.h>
#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include <AppCore/JSHelpers.h>

using namespace ultralight;

class DOMLoadListener : public LoadListener {
public:
    bool DOM_ready = false;
    DOMLoadListener(Ref<View> view) {
        view->set_load_listener(this);
    }

    virtual ~DOMLoadListener() {}

    ///
    /// Use LoadListener::OnDOMReady to wait for the DOM to load.
    ///
    virtual void OnDOMReady(View* caller,
        uint64_t frame_id,
        bool is_main_frame,
        const String& url) override {
        ///
        /// Initialize the page here with JavaScript.
        ///
        this->DOM_ready = true;
    }
};

//app instance
class MyApp {
public:
    //view instances
    RefPtr<Overlay> overlay_;
    DOMLoadListener* load_listener;
    RefPtr<Overlay> inspec_overlay;
public:
    MyApp(Ref<Window> win) {
        ///
        /// Create an Overlay using the same dimensions as our Window.
        ///
        overlay_ = Overlay::Create(win, win->width(), win->height(), 0, 0);

        ///
        /// Load a file from the FileSystem.
        ///
        ///  **IMPORTANT**: Make sure `file:///` has three (3) forward slashes.
        ///
        overlay_->view()->LoadURL("file:///client/index.html");
        load_listener = new DOMLoadListener(overlay_->view());

        //uncomment this section to do webpage debugging
        //RefPtr<View> inspector_view = overlay_->view()->inspector();
        //inspector_view->Resize(win->width(), win->height() - 500);
        ////create an inspector to debug
        //inspec_overlay = Overlay::Create(win, *inspector_view.get(), 0, 500);
        //inspec_overlay->Focus();
    }

    virtual ~MyApp() {}
};

//enum class for non-general event types
enum class JSEvent
{
    refresh_page,
    undefined
};

//function to determine a non-general event
JSEvent get_event_type(const char* raw) {
    if (strcmp("RefreshPage", raw) == 0) return JSEvent::refresh_page;
    else return JSEvent::undefined;
}

//listener for the entire app
class MainAppListener : public AppListener {
public:
    Ref<App>* main_app;
    MyApp* app;
    bool full_scr = false;
    MainAppListener(Ref<App>* main_app, MyApp* app) {
        this->main_app = main_app;
        this->app = app;
    }

    //function to execute different events from JS results
    void execute_event(const char* event) {
        switch (get_event_type(event))
        {
        case JSEvent::refresh_page:
            app->overlay_->view()->Reload();
            break;
        case JSEvent::undefined:
            break;
        default:
            break;
        }
    }

    //************************************
    //THE UPDATE LOGIC LOOP OF OUR APP
    //************************************
    void OnUpdate() override {
        //evaluate EventLog js to figure out the command queue
        if (this->app->load_listener->DOM_ready) {
            //set up context and interop
            SetJSContext(this->app->overlay_->view()->LockJSContext().get());
            JSObject global = JSGlobalObject();
            JSFunction GetQueue = global["GetQueue"];
            JSFunction ClearQueue = global["ClearQueue"];

            //evaluate get queue to retrieve commands
            if (GetQueue.IsValid()) {
                JSObject event_queue = GetQueue({}).ToObject();
                JSArray queue = event_queue["queue"].ToArray();
                //read events
                for (int i = queue.length() - 1; i >= 0; i--) {
                    String event = queue[i].ToString();

                    //case shut down
                    if (strcmp(event.utf8().data(), "ShutDown") == 0) main_app->get().Quit();

                    //case full screen
                    else if (strcmp(event.utf8().data(), "FullScr") == 0) {
                        HWND window = (HWND)main_app->get().window()->native_handle();
                        //toggle function of fullscreen event
                        if (full_scr) ShowWindow(window, SW_RESTORE);
                        else ShowWindow(window, SW_MAXIMIZE);
                        full_scr = !full_scr;
                    }

                    //case minimize
                    else if (strcmp(event.utf8().data(), "Minimize") == 0) {
                        HWND window = (HWND)main_app->get().window()->native_handle();
                        ShowWindow(window, SW_MINIMIZE);
                    }

                    //other non-general cases for left for our own handler logic
                    else {
                        execute_event(event.utf8().data());
                    }
                }
            }

            //clear events after we have processed all current
            if (ClearQueue.IsValid()) ClearQueue({});
        }
    }
};

//Window resize event listener, enables an overlay in the window to resize dynamically
class ResizeWindowListener : public WindowListener {
public:
    //minimal width/height to shrink to
    uint32_t min_width;
    uint32_t min_height;
    //view instance to apply on
    RefPtr<Overlay> overlay;
    ResizeWindowListener(RefPtr<Overlay> o, uint32_t min_width, uint32_t min_height) {
        this->overlay = o;
        this->min_width = min_width;
        this->min_height = min_height;
    }

    void OnClose() override {

    }

    void OnResize(uint32_t width, uint32_t height) override {
        overlay.get()->Resize(max(min_width, width), max(min_height, height));
    }
};


#endif // !UI_ELEMENTS_CLIENT_H
