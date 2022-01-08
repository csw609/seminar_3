#include "ros/ros.h"
#include "seminar_3/SrvTutorial.h"

bool calculation(seminar_3::SrvTutorial::Request &req,
		 seminar_3::SrvTutorial::Response &res){
	res.result = req.a + req.b;

	ROS_INFO("request : x = %ld, y = %ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response : %ld", (long int)res.result);


	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "seminar_srv");
	ros::NodeHandle nh;
	
	ros::ServiceServer service_server = nh.advertiseService("baram_service",calculation);
	ROS_INFO("ready srv server!");
	
	ros::spin();

	return 0;
}
