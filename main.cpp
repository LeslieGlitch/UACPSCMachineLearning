/*
    main.cpp
    Leslie Wollitz

    Test file for Backpropagation class
*/

#include "Link.hpp"
#include "Backpropagation.hpp"
#include <iostream>

const double START_NUM = 0.5;
const int NUM_DIVISIONS = 3;
double customFunc(double val);

int main() {
    // Create list
    Link* list = new Link(START_NUM);
    for (int i=0; i < NUM_DIVISIONS; ++i) {
        list = list->insert(list, new Link(customFunc(list->getValue())));
    }

    // Print data to user
    list->print_all(list);
    std::cout << std::endl;
    return 0;
}

double customFunc(double val) {
    return val / 2;
}
