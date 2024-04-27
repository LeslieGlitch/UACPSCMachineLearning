/*
    main.cpp
    Leslie Wollitz

    Test file for Backpropagation class
*/

#include "Link.hpp"
#include "Backpropagation.hpp"
#include <iostream>
#include <string>

const double START_NUM = 0.5;
const int NUM_ITERATIONS = 3;
double customFunc(double val);

int main() {
    // Create list
    std::string label = "Iter ";
    std::string labelStart = "Iter 0";
    Link* list = new Link(START_NUM, labelStart);
    for (int i=0; i < NUM_ITERATIONS; ++i) {
        std::string labelIter = label + std::to_string(i + 1);
        list = list->insert(list, new Link(customFunc(list->getValue()), labelIter));
    }

    // Print data to user
    list->print_all(list);
    std::cout << std::endl;
    return 0;
}

double customFunc(double val) {
    return val / 2;
}
