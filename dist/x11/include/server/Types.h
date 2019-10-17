#pragma once
#include <string>

struct UserInfo
{
	std::string userID;
	std::string password;
	std::string	nickname;
	std::string	signaTure;
	std::string	photo;
	std::string	registTime;
	bool		vehicleOnline;
	bool		pcOnline;
	bool		handeldOnline;
	bool		padOnline;
};

struct GroupInfo
{
	std::string groupID;
	std::string	name;
	std::string photo;
	std::string brief;
};

struct ChatMessage
{
	std::string senderID;	//sender
	std::string receiverID;	//userID or groupID
	std::string	content;
	std::string	time;
	bool		p2p;
};

struct CarInfo
{
	std::string userID;
	float availableFuel;
	float averageFuel;
	float totalKm;
	float subKmA;
	float subKmB;
	bool leftFrontDoor;
	bool rightFrontDoor;
	bool leftRearDoor;
	bool rightRearDoor;
	bool leftFrontWindow;
	bool rightFrontWindow;
	bool leftRearWindow;
	bool rightRearWindow;
	bool AC;
	int ACTemp;
	std::string shutdownPhoto;
	bool driving;

};
