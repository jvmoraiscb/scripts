FROM ros:noetic

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
apt-get -y install python3-pip ros-noetic-rosbridge-suite

RUN pip3 install --upgrade scikit-learn numpy

RUN rosdep update

RUN mkdir -p ros-workspace/src

COPY ros-packages/ /ros-workspace/src

RUN chmod +x /ros-workspace/src/leg_monitoring/scripts/leg_laser.py

RUN . /opt/ros/noetic/setup.sh && \
cd ros-workspace && \
catkin_make

RUN printf "roslaunch rosbridge_server rosbridge_websocket.launch &\nsleep 5\nrosrun speed_bridge speed &\nsleep 5\nroslaunch leg_monitoring rplidar_and_leg_monitoring.launch" > ~/run.sh && \
chmod +x ~/run.sh

CMD . /opt/ros/noetic/setup.sh && \
. /ros-workspace/devel/setup.sh && \
cd && ./run.sh
