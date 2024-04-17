/*
    Link.cpp

    Implementation file for Link class
    Class intended to create a linear linked
    list of items that can be interacted with
*/

#include "Link.hpp"
#include <iostream>

// Constructor
/// @param[in] v Value to add
/// @param[in] p Link to predecessor
/// @param[in] s Link to successor
Link::Link(const double& v, Link* p, Link* s)
    : value{v}, prev{p}, succ{s} { }

// value getter
double Link::getValue() {
    return value;
}

// prev getter
double Link::getPrev() {
    if (prev != nullptr)
        return prev->value;
    return 88.0;
}

// succ getter
double Link::getSucc() {
    if (succ != nullptr)
        return succ->value;
    return 99.0;
}

// insert n before p; return n
Link* Link::insert(Link* p, Link* n) {
    if (n==nullptr)
        return p;
    if (p==nullptr)
        return n;
    // p comes after n
    n->succ = p;
    if (p->prev)
        p->prev->succ = n;
    // p’s predecessor becomes n’s predecessor
    n->prev = p->prev;
    // n becomes p’s predecessor
    p->prev = n;
    return n;
}

// insert n after p; return n
Link *Link::add(Link *p, Link *n) {
    if (n==nullptr)
        return p;
    if (p==nullptr)
        return n;
    // p comes before n
    n->prev = p;
    if (p->succ)
        p->succ->prev = n;
    // p’s successor becomes n’s successor
    n->succ = p->succ;
    // n becomes p’s successor
    p->succ = n;
    return n;
}

// remove *p from list; return p’s successor
Link *Link::erase(Link *p) {
    if (p == nullptr)
        return nullptr;
    if (p->succ)
        p->succ->prev = p->prev;
    if (p->prev)
        p->prev->succ = p->succ;
    return p->succ;
}

// find s in list; return nullptr for “not found”
Link *Link::find(Link *p, const double &s) {
    while (p) {
        if (p->value == s)
            return p;
        p = p->succ;
    }
    return nullptr;
}

// move n positions in list; return nullptr for “not found”
// positive n moves forward, negative backward
Link *Link::advance(Link *p, int n) {
    if (p == nullptr)
        return nullptr;
    while (0 < n) {
        --n;
        if (p->succ)
            p = p->succ;
        return nullptr;
    }
    while (n < 0) {
        ++n;
        if (p->prev)
            p = p->prev;
        return nullptr;
    }
    return p;
}

void Link::print_all(Link* p) {
    std::cout << "{ ";
    while (p) {
        std::cout << p->value;
        if ((p=p->succ))
            std::cout << ", ";
    }
    std::cout << " }";
    return;
}
