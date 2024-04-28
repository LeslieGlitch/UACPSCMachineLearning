/*
    Backpropagation.cpp

    Implementation file for Backpropagation class
    Class intended to backpropagate through a
    node structure following the path of greatest
    gradient descent
*/

#include "Backpropagation.hpp"
#include <cmath>

double Backpropagation::backPropagate(Link*& x, double bias, double slope) {
    // implement before stuff
    if (x->getSucc() == nullptr) {
        // Activation function
        return abs(tanh(x->getValue()) - bias);
    } else {
        x = x->getSucc();
        return backPropagate(x, bias, (slope / 10));
    }
}
