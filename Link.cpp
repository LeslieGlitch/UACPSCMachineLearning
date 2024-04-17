/*
    Link.cpp

    Implementation file for Link class
    Class intended to create a linear linked
    list of items that can be interacted with
*/

#include "Link.hpp"

Link* Link::insert(Link* p, Link* n) {
    // insert n before p; return n
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
