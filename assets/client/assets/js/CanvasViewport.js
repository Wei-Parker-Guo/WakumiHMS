function draw_default_bg(){
	var canvas = document.getElementById("viewport");
	var context = canvas.getContext("2d");
	context.fillRect(0, 0, 1920, 1080);
}

function initialize_viewport(){
	document.getElementById("statusmsg").innerHTML = "[Viewport] initialized and ready for pipelines.";
	draw_default_bg();
}