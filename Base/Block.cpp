#pragma once

#include "Block.h"
#include "picosha2.h"

using namespace picosha2;
using namespace std;
using namespace chrono;

Block::Block(Data* dat, string prevHash) :
		data(dat) , previousHash(prevHash)
			{

	milliseconds timestamp = duration_cast< milliseconds >(
		system_clock::now().time_since_epoch()
		);

	hash = calculateHash();
}

string Block::calculateHash()
{
	const string all = data->toString() + previousHash + to_string(timestamp.count());
	string h = hash256_hex_string(all);
	return h;
}

