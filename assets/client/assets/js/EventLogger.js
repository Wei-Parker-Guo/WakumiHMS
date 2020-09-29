//This scipt contains method and classes to represent a page's UI events

//the event class
var EventQueue = {
	page_id : document.title,
	queue : []
};

//function call by button to fire event
function FireEvent(event_name){
	EventQueue.queue.push(event_name);
}

//function to get events
function GetQueue(){
	return EventQueue;
}

//function to clear event queue
function ClearQueue(){
	EventQueue.queue = [];
}

//function to insert a event into queue into a certain index
function InsertQueue(index, element){
	EventQueue.queue[index] = element;
}