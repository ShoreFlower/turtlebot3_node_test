#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/String.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
class SubscribeAndPublish  
{  
public:  
	SubscribeAndPublish()  
	{  
		//count = 0;
		//Topic you want to publish  
		tb3_0_vel = node.advertise<geometry_msgs::Twist>("/tb3_0/cmd_vel", 1);
		tb3_1_vel = node.advertise<geometry_msgs::Twist>("/tb3_1/cmd_vel", 1);
		tb3_2_vel = node.advertise<geometry_msgs::Twist>("/tb3_2/cmd_vel", 1);
		tb3_3_vel = node.advertise<geometry_msgs::Twist>("/tb3_3/cmd_vel", 1);
		tb3_4_vel = node.advertise<geometry_msgs::Twist>("/tb3_4/cmd_vel", 1);

		//Topic1 you want to subscribe  
		sub1 = node.subscribe("cmd_vel", 1, &SubscribeAndPublish::callback1, this); 

		// //Topic2 you want to subscribe  
		// sub2 = node.subscribe("cmd_vel", 10, &SubscribeAndPublish::callback2, this);  

		// //Topic3 you want to subscribe  
		// sub3 = node.subscribe("cmd_vel", 10, &SubscribeAndPublish::callback3, this); 

		// //Topic4 you want to subscribe  
		// sub4 = node.subscribe("cmd_vel", 10, &SubscribeAndPublish::callback4, this);  

		// //Topic4 you want to subscribe  
		// sub5 = node.subscribe("cmd_vel", 10, &SubscribeAndPublish::callback5, this);  
		

		// message_filters::Subscriber<geometry_msgs::Twist> sub1(node, "cmd_vel", 1);
		// message_filters::Subscriber<geometry_msgs::Twist> sub2(node, "cmd_vel", 1);
		// message_filters::Subscriber<geometry_msgs::Twist> sub3(node, "cmd_vel", 1);
		// message_filters::Subscriber<geometry_msgs::Twist> sub4(node, "cmd_vel", 1);
		// message_filters::Subscriber<geometry_msgs::Twist> sub5(node, "cmd_vel", 1);
		// message_filters::TimeSynchronizer<geometry_msgs::Twist, geometry_msgs::Twist,geometry_msgs::Twist,geometry_msgs::Twist,geometry_msgs::Twist> sync(sub1, sub2,sub3,sub4,sub5, 10);
		// sync.registerCallback(boost::bind(&callback1, &callback2,&callback3,&callback4,&callback5));

	}  

	void callback1(const geometry_msgs::Twist& Twist1)  
	{  
		// ?????????????????????????????????
		tb3_0_vel.publish(Twist1);
		tb3_1_vel.publish(Twist1);
		tb3_2_vel.publish(Twist1);
		tb3_3_vel.publish(Twist1);
		tb3_4_vel.publish(Twist1);
		//ROS_INFO("%s",&Twist1.angular);
	}  
	void callback2(const geometry_msgs::Twist& Twist2)  
	{  
		// ?????????????????????????????????
		tb3_1_vel.publish(Twist2);
		//ROS_INFO("%s",Twist1.angular);
	}  
	void callback3(const geometry_msgs::Twist& Twist3)  
	{  
		// ?????????????????????????????????
		tb3_2_vel.publish(Twist3);
		//ROS_INFO("%s",Twist1.angular);
	}
	void callback4(const geometry_msgs::Twist& Twist4)  
	{  
		// ?????????????????????????????????
		tb3_3_vel.publish(Twist4);
		//ROS_INFO("%s",Twist1.angular);
	}
	void callback5(const geometry_msgs::Twist& Twist5)  
	{  
		// ?????????????????????????????????
		tb3_4_vel.publish(Twist5);
		//ROS_INFO("%s",Twist1.angular);
	}
	private:  
		ros::NodeHandle node;   
		ros::Publisher tb3_0_vel;
		ros::Publisher tb3_1_vel;
		ros::Publisher tb3_2_vel;
		ros::Publisher tb3_3_vel;
		ros::Publisher tb3_4_vel;
		ros::Subscriber sub1;
		ros::Subscriber sub2; 
		ros::Subscriber sub3;
		ros::Subscriber sub4;
		ros::Subscriber sub5;
		std_msgs::String output;
		int count; 

};//End of class SubscribeAndPublish  

int main(int argc, char** argv)
{
	// ?????????ROS??????
	ros::init(argc, argv, "teleop_node_test");

    // ??????????????????
	ros::NodeHandle node;

	//ros::MultiThreadedSpinner mult(5);//multithreading

	// ??????????????????
	ros::Rate rate(10);
	SubscribeAndPublish Node_Test;

	//????????????
	ros::spin();
	//mult.spin();
	//ros::spin(mult);
	return 0;
};

