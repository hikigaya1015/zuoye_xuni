#!/usr/bin/env python3
#include <ros/ros.h>
#include <practice/MyProperty.h>

// 回调函数，当接收到消息时被调用
void callback(const practice::MyProperty::ConstPtr& data) {
    ROS_INFO("Received: name=%s, class=%d", data->name.c_str(), data->class_value);
}

int main(int argc, char** argv) {
    // 初始化ROS节点
    ros::init(argc, argv, "property_listener");

    // 创建节点句柄
    ros::NodeHandle nh;

    // 创建订阅者，订阅名为"property"的主题，消息类型为practice::MyProperty，回调函数为callback
    ros::Subscriber sub = nh.subscribe("property", 10, callback);
    // 进入循环，等待消息并处理回调函数
    ros::spin();
    return 0;
}