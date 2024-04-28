/*
    main.cpp
    Leslie Wollitz

    Test file for Backpropagation class
*/

#include "Link.hpp"
#include "Backpropagation.hpp"
#include <iostream>
#include <string>

// Settings
const double START_NUM = 0.5;
const int NUM_ITERATIONS = 3;
const double BIAS = 100.0;
const double START_SLOPE = 100.0;
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

    // Create list with a range of value
    Link* list2 = new Link(0.0);
    for (int i = 1; i <= 10; ++i) {
        list2 = list2->insert(list2, new Link(i / 10.0));
    }/*
    // Return list2 to start
    while (list2->getPrev() != nullptr) {
        list2 = list2->getPrev();
    }*/

    // Backpropagate
    double output = Backpropagation::backPropagate(list2, BIAS, START_SLOPE);

    // Return list2 to start
    while (list2->getPrev() != nullptr) {
        list2 = list2->getPrev();
    }
    
    // Print data to user
    list->print_all(list);
    std::cout << std::endl;
    list2->print_all(list2);
    std::cout << std::endl;
    std::cout << "Final backpropagation output: " << output << std::endl;
    return 0;
}

double customFunc(double val) {
    return val / 2;
}
