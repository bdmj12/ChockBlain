#pragma once

#include "Blockchain.h"
#include "picosha2.h"

using namespace picosha2;


Blockchain::Blockchain(int diff) :
	difficulty(diff)
{
	cout << "Blockchain created. \n";
}

void Blockchain::addBlock(Block b, string minedVal)
{
	const string h = b.hash + minedVal;
	if (leadingZeros(hash256_hex_string(h)) < difficulty)
	{
		cout << "Block not valid! (not mined) \n";
	}
	else
	{
		cout << "Block added \n";

		chain.push_back(b);

		minedVals.push_back(minedVal);
	}

}

int Blockchain::leadingZeros(string s)
{
	int num = 0;
	for (int i = 0;i < s.length(); i++)
	{
		if (s[i] != '0')
		{
			return num;
		}
		else
		{
			num++;
		}
	}
	return num;
}



bool Blockchain::isChainValid()
{
	for (int i = 0;i < chain.size();i++)
	{

		if (chain.at(i).calculateHash() != chain.at(i).hash)
		{
			cout << chain.at(i).calculateHash() << endl;
			cout << chain.at(i).hash << endl;
			cout << "Chain invalid: block " << i << " hash is incorrect."<< endl;
			return false;
		}
	
		if (leadingZeros(hash256_hex_string(chain.at(i).hash + minedVals.at(i)))<difficulty) 
		{
			cout << "Chain invalid: block " << i << " minedVals do not match! \n";
			return false;
		}

		if (i != 0) {
			if (chain.at(i).previousHash != chain.at(i - 1).hash)
			{
				cout << "Chain invalid: block " << i << "incorrect previous hash."<< endl;

				return false;
			}
		}	
	}
	cout << "Chain valid!" << endl;

	return true;
}

int Blockchain::printLength()
{
	return chain.size();
}

