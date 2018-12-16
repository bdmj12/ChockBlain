#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Block.h"
#include "Blockchain.h"
#include "picosha2.h"
#include "Miner.h"
#include "Data.h"

#include "SimpleData.h"


using namespace std;
using namespace picosha2;



	int main()
	{

		Blockchain bchain(3);
		Miner miner(1e6);

		Data* d1 = new SimpleData();
		Data* d2 = new SimpleData();
		Data* d3 = new SimpleData();

		Block b1(d1, "0");
		string minedVal1  = miner.mineBlock(bchain,b1);
		bchain.addBlock(b1, minedVal1);

		Block b2(d2, b1.hash);
		string minedVal2 = miner.mineBlock(bchain, b2);
		bchain.addBlock(b2, minedVal2);

		Block b3(d3, b2.hash);
		string minedVal3 = miner.mineBlock(bchain, b3);
		bchain.addBlock(b3, minedVal3);

		cout << bchain.isChainValid() << endl;

		cout << b1.data->toString() << endl;
		cout << b2.data->toString() << endl;
		cout << d2->toString() << endl;


		cin.get();

		return 0;
	}