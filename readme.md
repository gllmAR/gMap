#gmap

# Description

*gMap* is a openFrameworks OSC driven mapping software intended to be use and deploy on raspberry pi.
*gMap* is gui-agostic, it is designed to receive OSC messages instead of having a local gui.
*gMap* remember is settings and recall it on launch.

at time of writing, *gMap* only load images, but a working video solution is on the way

# Installation

in your openFrameworks app folder :
git clone



### Dependencies :
grab ofxGLWarper to your addons folder
```
git clone https://github.com/roymacdonald/ofxGLWarper
```
at the time of writing, ofxGLWarper didn't compile, to fix it :

* in scr/ofxGLWarper.cpp change
```
#include "opencv2/calib3d/calib3d_c.h"
```
to
```
#include "ofxOpenCv.h"
```

* in scr/ofxGLWarper.h add:
```
#include "ofxOpenCv.h"
```

clone

## Launch at boot service


copy the service deamon in the systemd service folder and activate on boot
```
sudo cp /home/pi/openFrameworks/apps/myApps/gMap/_service/* /etc/systemd/system/
sudo systemctl daemon-reload
sudo systemctl start ofx-gmap.service
sudo systemctl enable ofx-gmap.service
```

optional : for scrolling posting of the service:
```
sudo journalctl -f -u ofx-gmap
```


# todo

* implement ofOMXplayer as source on raspberry pi
* implement ofxavfondation as source on osx
* compile with appropriate flags depending on the system architectures
* implement streaming to : https://weblog.lkiesow.de/20160215-raspberry-pi-screen-mirroring/
* preset morphing
* separate sources and surfaces
* individual xml for config, sources and geo
