#gmap

# Description 

# Installation

## service




optional : copy the service deamon in the systemd service folder and activate on boot 
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


