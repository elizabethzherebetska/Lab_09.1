#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_09.1/var.h"
#include "../Lab_09.1/sum.h"
#include "../Lab_09.1/main.cpp"
#include "../Lab_09.1/var.cpp"
#include "../Lab_09.1/dod.h"
#include "../Lab_09.1/dod.cpp"
#include "../Lab_09.1/sum.cpp"






using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab09
{
	TEST_CLASS(UnitTestLab09)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// Ініціалізація тестових значень
			nsVar::x = 0.5;
			nsVar::eps = 1e-6;

			// Очікуване значення для ln((1 + x) / (1 - x))
			double expected = log((1 + nsVar::x) / (1 - nsVar::x));

			// Виклик функції, яка обчислює суму ряду
			nsSum::sum(); // Обчислює значення S і n

			// Перевірка, чи наближене значення S відповідає очікуваному
			Assert::IsTrue(abs(nsVar::S - expected) < nsVar::eps, L"Тест не пройдено: значення S не відповідає очікуваному значенню.");
		}
	};
}
