#include <iostream>
#include <string>
#include <sstream>
#include "Inputs.hpp"

void string_parser(std::string &line, std::string &w0, std::string &w1, std::string &w2, std::string &w3)
{
	std::istringstream iss;
	iss.str(line);
	iss >> w0 >> w1 >> w2 >> w3;
}

void command_Create(std::string &user, std::string &pass, HashMap &hm)
{
	if(user == "" || pass == "")
	{
		std::cout << "INVALID" << std::endl;
	}
	else if(hm.contains(user) != true)
	{
		hm.add(user, pass);
		std::cout << "CREATED" << std::endl;
	}
	else
	{
		std::cout << "EXISTS" << std::endl;
	}
}

void command_Login(std::string &user, std::string &pass, HashMap &hm)
{
	if(user == "" || pass == "")
	{
		std::cout << "INVALID" << std::endl;
	}
	else if(hm.contains(user) == true)
	{
		if(hm.value(user) == pass)
		{
			std::cout << "SUCCEEDED" << std::endl;
		}
		else
			std::cout << "FAILED" << std::endl;
	}
	else
		std::cout << "FAILED" << std::endl;
}

void command_Remove(std::string &user, HashMap &hm)
{
	if(user == "")
	{
		std::cout << "INVALID" << std::endl;
	}
	else if(hm.contains(user) == true)
	{
		hm.remove(user);
		std::cout << "REMOVED" << std::endl;
	}
	else
		std::cout << "NONEXISTENT" << std::endl;
}

void command_Clear(HashMap &hm)
{
	hm.clear();
	std::cout << "CLEARED" << std::endl;
}
void command_DebugOn(bool &debug)
{
	if(debug == true)
	{
		std::cout <<"ON ALREADY" << std::endl;
	}
	else
	{
		debug = true;
		std::cout << "ON NOW" << std::endl;
	}
}

void command_DebugOff(bool &debug)
{
	if(debug == false)
	{
		std::cout << "OFF ALREADY" << std::endl;
	}
	else
	{
		debug = false;
		std::cout << "OFF NOW" << std::endl;
	}
}

void command_LoginCount(HashMap &hm)
{
	std::cout << hm.size() << std::endl;
}

void command_BucketCount(HashMap &hm)
{
	std::cout << hm.bucketCount() << std::endl;
}

void command_LoadFactor(HashMap &hm)
{
	std::cout << hm.loadFactor() << std::endl;
}

void command_MaxBucketSize(HashMap &hm)
{
	std::cout << hm.maxBucketSize() << std::endl;
}