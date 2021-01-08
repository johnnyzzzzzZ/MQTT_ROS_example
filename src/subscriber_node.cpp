#include <mqtt_router/subscriber.hpp>

#include <stdio.h>
#include <ctype.h>
#include <typeinfo>
#include <cstdlib>

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "mqtt_subscriber");
  ros::NodeHandle nh;

  // subscribe
  mqttSubscriber mySubscriber("mqtt_subscriber", "/topic",  "192.168.31.199", 1883, 50);
  char a = ' ';
  mySubscriber.data = &a;

  ros::Rate loop_rate(4);
  while(ros::ok())
  {
    if(isspace(*mySubscriber.data)){
      ROS_INFO("nothing");
    }
    else{
      //ROS_INFO(mySubscriber.data);
      std::string ss(mySubscriber.data);
      ROS_INFO(ss.c_str());
      
      mySubscriber.data = &a;
    }
    

    ros::spinOnce();
    loop_rate.sleep();
  }
  mosqpp::lib_cleanup();
  return 0;
}