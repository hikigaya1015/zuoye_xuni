#include <ros/ros.h>
#include <practice/MyProperty.h>

// 主函数，实现消息发布功能
int main(int argc, char** argv) {
    // 初始化ROS节点
    ros::init(argc, argv, "property_talker");

    // 创建节点句柄
    ros::NodeHandle nh;

    // 创建消息发布者，发布到名为"property"的主题，消息类型为practice::MyProperty，队列大小为10
    ros::Publisher pub = nh.advertise<practice::MyProperty>("property", 10);

    // 设置发布频率为1Hz
    ros::Rate rate(1);

    while (ros::ok()) {
        // 创建要发布的消息对象
        practice::MyProperty msg;
        msg.name = "Student";
        msg.class_value = 2023;

        // 发布消息
        pub.publish(msg);

        // 输出发布信息日志
        ROS_INFO("Published: name = %s, class = %d", msg.name.c_str(), msg.class_value);

        // 按照设定频率休眠
        rate.sleep();
    }

    return 0;
}