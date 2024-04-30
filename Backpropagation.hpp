/*
    Backpropagation.hpp

    Header file for Backpropagation class
    Class intended to backpropagate through a
    node structure following the path of greatest
    gradient descent
*/

#ifndef BACKPROPAGATION_HPP
#define BACKPROPAGATION_HPP

#include "Link.hpp"

class Backpropagation {
public:
    // Backpropagation function
    /// @param[in] x List to be traversed
    /// @param[in] bias The bias
    /// @param[in] slope Starting slope of the backpropagation
    static double backPropagate(Link*& list, const double& x, const double& bias, double slope);
};

#endif