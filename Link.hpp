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
    std::string value;
    Link* prev;
    Link* succ;
public:
    // Constructor
    /// @param[in] v Value to add
    /// @param[in] p Link to predecessor
    /// @param[in] s Link to successor
    Link(const std::string& v, Link* p, Link* s);

    // insert n before p; return n
    /// @param[in] 
    Link* insert(Link* p, Link* n);

    // insert n after p; return n
    Link *add(Link *p, Link *n);

    // remove *p from list; return p’s successor
    Link *erase(Link *p);

    // find s in list; return nullptr for “not found”
    Link *find(Link *p, const std::string &s);

    // move n positions in list; return nullptr for “not found”
    // positive n moves forward, negative backward
    Link *advance(Link *p, int n);

    void print_all(Link* p);
};

#endif
