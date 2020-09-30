// WakumiHMS.cpp : Defines the entry point for the application.
//

#include <iostream>

//Global Data
#include "GlobalInfo.h"

//UI Pipeline (Ultralight HTML Engine)
#include <AppCore/Monitor.h>
#include "UIElements.h"

using namespace ultralight;

//function to create the main app
void app_create(Ref<App>& main_app) {
    //create main window to fit as a fullscreen resolution size
    Monitor* main_monitor = main_app->main_monitor();
    auto main_window = Window::Create(main_monitor, floor(main_monitor->width() / main_monitor->scale()),
        floor(main_monitor->height() / main_monitor->scale()), false, kWindowFlags_Borderless);
    //set title of this window
    char title_buf[64];
    sprintf_s(title_buf, "%s [version%s]", GlobalInfo::title, GlobalInfo::version);
    main_window->SetTitle(title_buf);
    //set window to app
    main_app->set_window(main_window);
    //create myapp instance
    MyApp* my_app = new MyApp(main_window);
    //set up resize listener for main contents
    ResizeWindowListener* main_wind_listener = new ResizeWindowListener(my_app->overlay_, main_window->width() / 2, main_window->height() / 2);
    main_window->set_listener(main_wind_listener);
    //set up listener for the whole app
    MainAppListener* main_app_listener = new MainAppListener(&main_app, my_app);
    main_app->set_listener(main_app_listener);
}

int main(int argc, char* argv[]) {

    //***********************************
    //APPLICATION SETUP
    //***********************************

    //create main app
    Ref<App> main_app = App::Create();
    app_create(main_app);

    //***********************************
    //APPLICATION RUN
    //***********************************

    //run
    main_app->Run();

    return 0;
}
