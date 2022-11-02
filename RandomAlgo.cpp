// RandomAlgo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Demo.h"


int main()
{
    std::cout.precision(3);
    auto start1 = std::chrono::steady_clock::now();
    double msTimer1 = 0.0;
    za::demo::CreateSuccessorGraphTableD();
    auto end1 = std::chrono::steady_clock::now();
    msTimer1 += std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count();
    std::scientific;
    std::cout << "Process time = " << (double)msTimer1 << std::endl;

}

