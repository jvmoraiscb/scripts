#!/bin/bash

sudo docker run -it --rm --network host --privileged -v /dev/bus/usb:/dev/bus/usb brenomcd/rplidar-bridge
