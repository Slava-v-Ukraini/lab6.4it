    #include "pch.h"
    #include "CppUnitTest.h"
    #include "../PR6.4it.cpp"

    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    namespace aayTests
    {
        TEST_CLASS(ArrayTests)
        {
        public:

            TEST_METHOD(TestMax)
            {
                double a[] = { -5.0, 3.0, 10.0, -2.0 };
                int size = sizeof(a) / sizeof(a[0]);
                double expectedMax = 10.0;
                Assert::AreEqual(expectedMax, Max(a, size));
            }

            TEST_METHOD(TestLastPos)
            {
                double a[] = { -5.0, 3.0, -10.0, 4.0, -2.0 };
                int size = sizeof(a) / sizeof(a[0]);
                int expectedLastPos = 3;
                Assert::AreEqual(expectedLastPos, LastPos(a, size));
            }

            TEST_METHOD(TestSumBeforeLastPos)
            {
                double a[] = { -5.0, 3.0, 10.0, -2.0, 4.0, -1.0 };
                int size = sizeof(a) / sizeof(a[0]);
                double expectedSum = -5.0 + 3.0 + 10.0 - 2.0;
                Assert::AreEqual(expectedSum, SumBeforeLastPos(a, size));
            }

            TEST_METHOD(TestCompressArray)
            {
                double a[] = { -30.0, 15.0, 25.0, -5.0, 10.0, 50.0, -20.0 };
                int size = sizeof(a) / sizeof(a[0]);
                double c = 10.0;
                double b = 30.0;

                int newSize = CompressArray(a, size, c, b);

                // Перевірка очікуваного масиву після стиснення
                double expectedArray[] = { -5.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
                Assert::AreEqual(2, newSize);

                for (int i = 0; i < size; i++) {
                    Assert::AreEqual(expectedArray[i], a[i]);
                }
            }

            TEST_METHOD(TestCreate)
            {
                int size = 10;
                double* a = new double[size];
                Create(a, size);

                bool allElementsInRange = true;
                for (int i = 0; i < size; i++) {
                    if (a[i] < -50 || a[i] > 50) {
                        allElementsInRange = false;
                        break;
                    }
                }

                delete[] a;

                Assert::IsTrue(allElementsInRange);
            }
        };
    }
