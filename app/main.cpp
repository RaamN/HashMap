#include <iostream>
#include <string>
#include <sstream>
#include "HashMap.hpp"
#include "Inputs.hpp"

int main()
{
	std::string line;
	std::string input0; std::string input1; std::string input2; std::string input3;
	HashMap hm;
	bool debug_mode = false;

	while(true)
	{
		line.clear();
		input0.clear();
		input1.clear();
		input2.clear();
		input3.clear();

		std::getline(std::cin, line);
		
		string_parser(line, input0, input1, input2, input3);

		if(input0 == "CREATE" and input3 == "")
		{
			command_Create(input1, input2, hm);
		}

		else if(input0 == "LOGIN" and input1 == "COUNT" and input2 == "" and debug_mode == true)
		{
			command_LoginCount(hm);
		}

		else if(input0 == "LOGIN" and input3 == "")
		{
			command_Login(input1, input2, hm);
		}

		else if(input0 == "REMOVE" and input2 == "")
		{
			command_Remove(input1, hm);
		}

		else if(input0 == "CLEAR" and input1 == "")
		{
			command_Clear(hm);
		}

		else if(input0 == "DEBUG" and input1 == "ON" and input2 == "")
		{
			command_DebugOn(debug_mode);
		}

		else if(input0 == "DEBUG" and input1 == "OFF" and input2 == "")
		{
			command_DebugOff(debug_mode);
		}

		else if(input0 == "BUCKET" and input1 == "COUNT" and input2 == "" and debug_mode == true)
		{
			command_BucketCount(hm);
		}

		else if(input0 == "LOAD" and input1 == "FACTOR" and input2 == "" and debug_mode == true)
		{
			command_LoadFactor(hm);
		}

		else if(input0 == "MAX" and input1 == "BUCKET" and input2 == "SIZE" and input3 == "" and debug_mode == true)
		{
			command_MaxBucketSize(hm);
		}

		else if(input0 == "QUIT" and input1 == "")
		{
			break;
		}

		else
		{
			std::cout << "INVALID" << std::endl;
		}

	}

	std::cout << "GOODBYE" << std::endl;
	
    return 0;
}

