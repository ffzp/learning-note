#include <ros/ros.h>
#include <ur_rtde/rtde_receive_interface.h>
#include <thread>
#include <chrono>
#include <csignal>
#include <string>
#include <iostream>

using namespace ur_rtde;
using namespace std::chrono;

int main(int argc, char* argv[])
{
ros::init(argc, argv, "robot_move");
ros::NodeHandle n;
//ros::Publisher turtle_vel_pub = n.advertise<ur_rtde::rtde_receive_interface>("/turtle1/cmd_vel", 10);     I can't create a  PUBLISHER!

ros::Rate loop_rate(10);

RTDEControlInterface rtde_control("127.0.0.1");
rtde_control.moveL({-0.143, -0.435, 0.20, -0.001, 3.12, 0.04}, 0.5, 0.2);
return 0;
}
