
#include <ros/ros.h>
#include <std_msgs/String.h>
void talker() {
    // 初始化ROS节点
    ros::init(ros::MULTI_THREAD_NODE, "talker");

    // 创建节点句柄
    ros::NodeHandle nh;

    // 创建发布者，发布到名为"hello_ros_topic"的话题，消息类型为std_msgs::String，队列大小为10
    ros::Publisher pub = nh.advertise<std_msgs::String>("hello_ros_topic", 10);

    // 设置发布频率为10Hz
    ros::Rate rate(10);

    while (ros::ok()) {
        // 创建要发布的消息对象
        std_msgs::String msg;
        msg.data = "Hello, ROS!";

        // 发布消息
        pub.publish(msg);

        // 输出日志信息，类似于Python中的rospy.loginfo
        ROS_INFO("Sent message: %s", msg.data.c_str());

        // 按照设定的频率休眠
        rate.sleep();
    }
}

int main(int argc, char** argv) {
    try {
        talker();
    } catch (ros::Exception& e) {
        // 捕获并处理异常，这里简单打印异常信息
        ROS_ERROR("Exception occurred: %s", e.what());
    }

    return 0;
}
