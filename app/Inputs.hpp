#ifndef INPUTS_HPP
#define INPUTS_HPP

#include <iostream>
#include <sstream>
#include <string>
#include "HashMap.hpp"

void string_parser(std::string &line, std::string &w0, std::string &w1, std::string &w2, std::string &w3);

void command_Create(std::string &user, std::string &pass, HashMap &hm);

void command_Login(std::string &user, std::string &pass, HashMap &hm);

void command_Remove(std::string &user, HashMap &hm);

void command_Clear(HashMap &hm);

void command_DebugOn(bool &debug);

void command_DebugOff(bool &debug);

void command_LoginCount(HashMap &hm);

void command_BucketCount(HashMap &hm);

void command_LoadFactor(HashMap &hm);

void command_MaxBucketSize(HashMap &hm);

#endif // INPUTS_HPP