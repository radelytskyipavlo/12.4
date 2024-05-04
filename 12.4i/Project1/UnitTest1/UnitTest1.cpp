#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestInsert)
		{
			Elem* L = NULL;
			int increaseBy = 5;
			insert(L, 10, increaseBy);
			insert(L, 20, increaseBy);
			Assert::AreEqual(L->info, 15);

			Assert::AreEqual(L->link->info, 25);

			while (L != NULL)
			{
				remove(L);
			}
		}
	};
}