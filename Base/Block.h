#pragma once

#include <string>
#include <chrono>
#include <iostream>
#include "Data.h"

using namespace std;

class Block
{
public:
	Block(Data* dat, string prevHash);

	string previousHash;
	string hash;
	
	string calculateHash();

	chrono::milliseconds timestamp;
	
	Data* data;
};

