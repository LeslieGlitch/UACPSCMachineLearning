/*
    Backpropagation.cpp

    Implementation file for Backpropagation class
    Class intended to backpropagate through a
    node structure following the path of greatest
    gradient descent
*/

#include "Backpropagation.hpp"
#include <cmath>

double Backpropagation::backPropagate(Link*& list, const double& x, const double& bias, double slope) {
    if (list->getSucc() == nullptr) {
        // End of leaf node, slope = Activation function
        slope = std::abs(std::tanh(x) + bias);
        list->setValue(slope);
        return slope;
    } else {
        list = list->getSucc();
        slope = 10 * backPropagate(list, x, bias, slope);
        list = list->getPrev();
        list->setValue(slope);
        return slope;
    }
}
