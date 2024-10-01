#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 5.2/Lab 5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

double S(double x, double eps, int& n, double s);
double A(double x, int n, double a);

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

       
        TEST_METHOD(TestS_Accuracy)
        {
            double x = 0.5;
            double eps = 1e-5;
            int n = 0;
            double s = 0.0;

            
            double result = S(x, eps, n, s);

            
            double expected = cos(x);

            
            Assert::AreEqual(expected, result, eps, L"TestS failed for x = 0.5");
        }

        
        TEST_METHOD(TestS_Iterations)
        {
            double x = 1.0;
            double eps = 1e-5;
            int n = 0;
            double s = 0.0;

            
            S(x, eps, n, s);

           
            Assert::IsTrue(n > 0, L"TestS failed: number of iterations should be greater than 0");
        }

       
        TEST_METHOD(TestA_Calculation)
        {
            double x = 0.5;
            int n = 1;
            double a = 1.0;

          
            double result = A(x, n, a);

           
            double expected = (-1.0) * ((x * x) / ((2.0 * n) * (2.0 * n - 1.0))) * a;

           
            Assert::AreEqual(expected, result, 1e-6, L"TestA failed for x = 0.5, n = 1");
        }

        TEST_METHOD(TestA_Simple)
        {
            double result = A(2.0, 1, 1.0);
            Assert::IsTrue(result < 0, L"TestA failed: result should be negative");
        }
    };
}

