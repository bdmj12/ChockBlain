#pragma once

#include "Miner.h"
#include "picosha2.h"

using namespace picosha2;




Miner::Miner(int num) :
	numAttempts(num)
{
}

string Miner::mineBlock(Blockchain chain, Block b)
{
	for (int i = 0;i<numAttempts;i++)
	{
		string s = to_string(rand());
		const string attempt = b.hash + s;
		if (Blockchain::leadingZeros(hash256_hex_string(attempt)) >= chain.difficulty)
		{
			return  s;
		}

	}
	cout << "Block not mined \n";
	return " ";
}