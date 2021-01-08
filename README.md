# MQTT_ROS_example
This is a simple example demostrating the MQTT communication within ROS.



## Dependency
At the beginning, make sure you have already installed the MQTT library in your system.
```
sudo apt install libmosquitto-dev
```
```
sudo apt install libmosquittopp-dev
```

If you do not have installed ROS yet, follow the instruction from [ROS official website](http://wiki.ros.org/melodic/Installation/Ubuntu)

## Installation

1. Install the package in the source folder of your catkin workspace.
```
cd ~/<catkin workspace directory>/src && git clone https://github.com/johnnyzzzzzZ/MQTT_ROS_example.git
```
2. Build the package.
```
cd ~/<catkin workspace directory> && catkin_make
```
3. Source the bash file.
```
echo "source ~/<catkin workspace directory>/devel/setup.bash" >> ~/.bashrc
```

4. Run ros node in seperate terminal.
```
roscore
```

```
rosrun mqtt_router mqtt_router_sub
```

```
rosrun mqtt_router mqtt_router_pub
```


MQTT publisher node would send some message to MQTT subscriber node as shown in the below.

![MQTT Sub/Pub](/image/mqttROS.jpg)

## Other Application
There are some IoT platforms such as google cloud platform, Adafruit, or ThingsBoard which we can use to manage and visualize the data.

We would use [ThingsBoard](https://thingsboard.io/docs/getting-started-guides/helloworld/) as an example to illustrate how to send data from ROS client to the IoT platform via MQTT. Users can choose to build a private cloud on their own machine or use a public one on ThingsBoard website. If you choose to host the patform locally, you could find the [tutorial](https://thingsboard.io/docs/user-guide/install/docker/) on their website and install the platform with Docker easily.

In the figure below, we have a MQTT publisher ROS node sending interger data which can be successfully received by the IoT platform.
![IoT platform](/image/mqttThingsboard.jpg)
