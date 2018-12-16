#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\Base\Block.h"
#include "..\Base\Data.h"
#include "..\Base\SimpleData.h"

#include "..\Base\picosha2.h"

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace picosha2;

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BaseTest
{		
	TEST_CLASS(BlockTests)
	{
	public:

		TEST_METHOD(TestInit)
		{
			Data* d = new SimpleData();
			string ph = "hello";
			Block b(d, ph);

			Assert::AreEqual(d->toString(), b.data->toString());
			Assert::AreEqual(ph, b.previousHash);

		}
		
		TEST_METHOD(TestHash)
		{
			Data* d = new SimpleData();
			Block b(d, "0");

			Assert::AreEqual(b.hash, b.calculateHash());

		}

	};
}