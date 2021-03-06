<p align="center">
<img src="img/header.png" width="70%" style="margin-left: 50%; margin-right: 50%;">
</p>

# Wakumi Hardware Monitoring System
A client-server style HMS offering sensor info from windows WMI etc. to a platform independent frontend client. The client-server app communication is based on apache and php. WakumiHMS also serves as a remote console of client computers for superusers.

# Usage
This project came up to me while finding a solution to display hardware info such as CPU/GPU temps on an in-case monitor connected to a raspberry pi. Using the pi as a server running the WakumiHMS server app (which is essentially a browser) on bootup is convenient and smooth. Besides the rest of the pi's resources could easily be used through remote consoling on WakumiHMS. The same concept can be realized by WakumiHMS as long as you have a web server and a client computer. Installing the client app on the client computer enables Wakumi to post its hardware data to the server app, which also has a frontend to display it.

# References
All referenced codes are commented with sources inline. Some opensource modules used are listed here:

<a href="https://ultralig.ht/">Ultalight HTML UI Engine</a> - Frontend UIs

<a href="https://charat.me/en/genesis/">Charat Genesis</a> - Design Elements (Virtual Character Image)

<a href="https://dmitrybaranovskiy.github.io/raphael/">Raphaël—JavaScript Library</a> - UI Engine

<a href="https://github.com/WLyKan/jQuery.circleProgressBar">JQuery.circleProgressBar</a> - UI Elements (Circular Progress Bars)

<a href="https://www.behance.net/gallery/31234507/Open-source-Loading-GIF-Icons-Vol-1">Open source Loading GIF Icons Vol-1</a> - UI Elements (Loading Gif)
