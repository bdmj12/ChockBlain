#pragma once

#include "Data.h"
#include <iostream>
#include <string>

using namespace std;

class SimpleData : public Data
{
public:
	SimpleData();

	string toString() override;
};

