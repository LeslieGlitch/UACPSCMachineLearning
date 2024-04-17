/*
    Link.hpp

    Header file for Link class
    Class intended to create a linear linked
    list of items that can be interacted with
*/

#ifndef LINK_HPP
#define LINK_HPP

#include <string>

class Link {
private:
    Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
        : value{v}, prev{p}, succ{s} { }
    std::string value;
    Link* prev;
    Link* succ;
public:
    Link* insert(Link* p, Link* n);
};

#endif
