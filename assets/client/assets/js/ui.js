
var cpu_paper = Raphael('CPU-circle', $('.CPU-circle').css("width"), $('.CPU-circle').css("height"));

$(function(){ $('.CPU-circle').percentageLoader({
    //percentage value container
    valElement: 'p',
    //ring width
    strokeWidth: 24,
    //background ring color
    bgColor: 'rgba(255,255,255,0.3)',
    //ring color
    ringColor: 'white',
    //text color
    textColor: '#ffffff',
    fontSize: '3.5rem',
    fontWeight: 'normal',
    unit: '°C',
    paper: cpu_paper
}, cpu_paper);});

var gpu_paper = Raphael('GPU-circle', $('.GPU-circle').css("width"), $('.GPU-circle').css("height"));

$(function(){ $('.GPU-circle').percentageLoader({
    //percentage value container
    valElement: 'p',
    //ring width
    strokeWidth: 24,
    //background ring color
    bgColor: 'rgba(255,255,255,0.3)',
    //ring color
    ringColor: 'white',
    //text color
    textColor: '#ffffff',
    fontSize: '3.5rem',
    fontWeight: 'normal',
    unit: '°C'
}, gpu_paper);});

var sys_paper = Raphael('SYS-circle', $('.SYS-circle').css("width"), $('.SYS-circle').css("height"));

$(function(){ $('.SYS-circle').percentageLoader({
    //percentage value container
    valElement: 'p',
    //ring width
    strokeWidth: 24,
    //background ring color
    bgColor: 'rgba(255,255,255,0.3)',
    //ring color
    ringColor: 'white',
    //text color
    textColor: '#ffffff',
    fontSize: '3.5rem',
    fontWeight: 'normal',
    unit: '°C'
}, sys_paper);});
