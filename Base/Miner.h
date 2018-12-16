#pragma once

#include "Block.h"
#include "Blockchain.h"
#include <iostream>
#include <string>


using namespace std;

class Miner
{
public:
	Miner(int num);

	int numAttempts;

	string mineBlock(Blockchain chain, Block b);
};

