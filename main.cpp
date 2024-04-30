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
const int NUM_ITERATIONS = 4;
const double BIAS = -0.5;
const double START_SLOPE = 0.5;
double customFunc(double val);

int main() {
    // Create list
    std::string label[] = {"Thor", "Odin", "Freyja", "Asgard"};
    std::string labelStart = "Loki";
    Link* list = new Link(START_NUM, labelStart);
    for (int i=0; i < NUM_ITERATIONS; ++i) {
        list = list->insert(list, new Link(customFunc(list->getValue()), label[i]));
    }

    // Print settings for user
    std::cout << "Settings:\n";
    std::cout << "- Bias: "           << BIAS        << "\n";
    std::cout << "- Starting Slope: " << START_SLOPE << "\n\n";

    // Backpropagate
    double azimuth[] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double output[11];
    double azimuthBest;
    double bestSlope = 99999;
    for (int i = 0; i < 11; ++i) {
        // Return list to start
        while (list->getPrev() != nullptr) {
            list = list->getPrev();
        }

        double outputCurrent = Backpropagation::backPropagate(list, azimuth[i], BIAS, START_SLOPE);
        output[i] = outputCurrent;

        // See if best value
        if (list->getValue() < bestSlope) {
            azimuthBest = azimuth[i];
            bestSlope = list->getValue();
        }

        // Return list to start
        while (list->getPrev() != nullptr) {
            list = list->getPrev();
        }

        // Print data to user
        std::cout << "Azimuth: " << azimuth[i] << "\n";
        list->print_all(list);
        std::cout << std::endl;
        std::cout << "Backpropagation output: "<< output[i];
        std::cout << "\n\n";
    }
    
    // Best results
    std::cout << "The lowest error came from an azimuth of " << azimuthBest << "\n";
    std::cout << "Here, Asgard had a slope of " << bestSlope << "\n";
    
    return 0;
}

double customFunc(double val) {
    return val / 2;
}
