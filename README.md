<img src="img/header.png" width="80%" style="margin-left: auto; margin-right: auto;">
# Wakumi Hardware Monitoring System
A client-server style HMS offering sensor info from windows WMI etc. to a platform independent frontend client. The client-server app communication is based on apache and php. WakumiHMS also serves as a remote console of client computers for superusers.

# Usage
This project came up to me while finding a solution to display hardware info such as CPU/GPU temps on an in-case monitor connected to a raspberry pi. Using the pi as a server running the WakumiHMS server app (which is essentially a browser) on bootup is convenient and smooth. Besides the rest of the pi's resources could easily be used through remote consoling on WakumiHMS. The same concept can be realized by WakumiHMS as long as you have a web server and a client computer. Installing the client app on the client computer enables Wakumi to post its hardware data to the server app, which also has a frontend to display it.

# References
All referenced codes are commented with sources inline. Some opensource modules used are listed here:

<a href="https://ultralig.ht/">Ultalight HTML UI Engine</a>