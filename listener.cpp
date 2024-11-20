#include <ros/ros.h>
#include <std_msgs/String.h>

void callback(const std_msgs::String::ConstPtr& data) {
    ROS_INFO("Received message: %s", data->data.c_str());
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("hello_ros_topic", 1000, callback);
    ros::spin();

    return 0;
}
