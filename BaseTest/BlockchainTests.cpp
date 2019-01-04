#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\Base\Block.h"
#include "..\Base\Blockchain.h"


#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BaseTest
{
	TEST_CLASS(BlockchainTests)
	{
	public:

		TEST_METHOD(TestLeadingZeros)
		{
			string s0 = "ksdjgfn";
			string s1 = "0dgnsdlfknv";
			string s4 = "0000dgnsdlfknv";
			string s6 = "000000dgnsdlfknv";
			string s20 = "00000000000000000000";

			int n0 = Blockchain::leadingZeros(s0);
			int n1 = Blockchain::leadingZeros(s1);
			int n4 = Blockchain::leadingZeros(s4);
			int n6 = Blockchain::leadingZeros(s6);
			int n20 = Blockchain::leadingZeros(s20);

			Assert::AreEqual(n0, 0);
			Assert::AreEqual(n1, 1);
			Assert::AreEqual(n4, 4);
			Assert::AreEqual(n6, 6);
			Assert::AreEqual(n20, 20);

		}



	};
}