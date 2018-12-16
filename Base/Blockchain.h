#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Block.h"

using namespace std;


class Blockchain
{
public:
	Blockchain(int diff);

	static int leadingZeros(string s);

	int difficulty;

	bool isChainValid();

	int printLength();

	vector<Block> chain;

	vector<string> minedVals;

	void addBlock(Block b, string minedVal);
};

