#!/bin/bash

sudo docker run -it ros2-rplidar --network host --privileged -v /dev/bus/usb:/dev/bus/usb