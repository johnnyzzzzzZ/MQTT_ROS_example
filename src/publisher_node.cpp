#include <mqtt_router/publisher.hpp>
#include <geometry_msgs/Pose.h>


int main(int argc, char **argv)
{
  ros::init(argc, argv, "subscribe_and_command");
  ros::NodeHandle n;
  json data_name;

  // publish to Thingsboard & AMRMS
  mqttPublisher ioPub("ioPub", "/topic",  "192.168.31.199", 1883);
  //const char* usname = "WdEheRaTNgQpyJyXjEhr";
  //const char* pw = "";
  //ioPub.username_pw_set(usname,pw);
  
  // sampling rate = 4 Hz
  ros::Rate loop_rate(4);
  int value = 0;

  while (ros::ok()){
    data_name["Data"] = value;

    std::string ss = data_name.dump();
    ioPub.send_message(ss.c_str());

    value++;
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}