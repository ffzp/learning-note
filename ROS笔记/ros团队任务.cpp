#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
ros::init(argc, argv, "turtle_move_square");
ros::NodeHandle n;
ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

ros::Rate loop_rate(10);

const double pi=3.1415926535;

for (int i=0;i<50;i++)//move1
{
geometry_msgs::Twist velocity;
velocity.linear.x = 0.5;
velocity.angular.z = 0;

turtle_vel_pub.publish(velocity);
ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]",velocity.linear.x,velocity.angular.z);

loop_rate.sleep();
}

for (int i=0;i<50;i++)//swing1
{
geometry_msgs::Twist velocity;
velocity.linear.x = 0;
velocity.angular.z = pi/10;

turtle_vel_pub.publish(velocity);
ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]",velocity.linear.x,velocity.angular.z);

loop_rate.sleep();
}

for (int i=0;i<50;i++)//move2
{
geometry_msgs::Twist velocity;
velocity.linear.x = 0.5;
velocity.angular.z = 0;

turtle_vel_pub.publish(velocity);
ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]",velocity.linear.x,velocity.angular.z);

loop_rate.sleep();
}

for (int i=0;i<50;i++)//swing2
{
geometry_msgs::Twist velocity;
velocity.linear.x = 0;
velocity.angular.z = pi/10;

turtle_vel_pub.publish(velocity);
ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]",velocity.linear.x,velocity.angular.z);

loop_rate.sleep();
}

for (int i=0;i<50;i++)//move3
{
geometry_msgs::Twist velocity;
velocity.linear.x = 0.5;
velocity.angular.z = 0;

turtle_vel_pub.publish(velocity);
ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]",velocity.linear.x,velocity.angular.z);

loop_rate.sleep();
}

for (int i=0;i<50;i++)//swing3
{
geometry_msgs::Twist velocity;
velocity.linear.x = 0;
velocity.angular.z = pi/10;

turtle_vel_pub.publish(velocity);
ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]",velocity.linear.x,velocity.angular.z);

loop_rate.sleep();
}

for (int i=0;i<50;i++)//move4
{
geometry_msgs::Twist velocity;
velocity.linear.x = 0.5;
velocity.angular.z = 0;

turtle_vel_pub.publish(velocity);
ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]",velocity.linear.x,velocity.angular.z);

loop_rate.sleep();
}
return 0;
}

