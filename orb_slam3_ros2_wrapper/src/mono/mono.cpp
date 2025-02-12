#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "mono-slam-node.hpp"

int main(int argc, char **argv)
{
    if(argc < 3)
    {
        std::cerr << "\nUsage: ros2 run orbslam mono path_to_vocabulary path_to_settings" << std::endl;
        return 1;
    }

    rclcpp::init(argc, argv);
    //IMU_MONOCULAR
    //auto node = std::make_shared<ORB_SLAM3_Wrapper::MonoSlamNode>(argv[1], argv[2], ORB_SLAM3::System::MONOCULAR);
    auto node = std::make_shared<ORB_SLAM3_Wrapper::MonoSlamNode>(argv[1], argv[2], ORB_SLAM3::System::IMU_MONOCULAR);
    std::cout << "============================ " << std::endl;

    auto executor = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();
    executor->add_node(node);
    executor->spin();
    rclcpp::shutdown();

    return 0;
}
