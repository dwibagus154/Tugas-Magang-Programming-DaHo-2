// TODO: implementasi publisher.cpp

#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{

    ros::init(argc, argv, "publisher");

    ros::NodeHandle n;

    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    ros::Rate loop_rate(60);

    while (ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello world ";
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());

        chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}