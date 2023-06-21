#!/bin/bash
sudo docker run --rm -it --network host --privileged -v /dev/bus/usb:/dev/bus/usb teste
