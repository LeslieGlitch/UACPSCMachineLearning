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
    double value;
    std::string label;
    Link* prev;
    Link* succ;
public:
    // Constructor
    /// @param[in] v Value to add
    /// @param[in] p Link to predecessor
    /// @param[in] s Link to successor
    Link(const double& v, const std::string& label = "", Link* p = nullptr, Link* s = nullptr);

    // value getter
    double getValue();

    // prev getter
    Link* getPrev();

    // succ getter
    Link* getSucc();

    // insert n before p; return n
    /// @param[in] p Reference link
    /// @param[in] n Link to be inserted
    Link* insert(Link* p, Link* n);

    // insert n after p; return n
    /// @param[in] p Reference link
    /// @param[in] n Link to be inserted
    Link *add(Link *p, Link *n);

    // remove *p from list; return p’s successor
    /// @param[in] p Link to erase
    Link *erase(Link *p);

    // find s in list; return nullptr for “not found”
    /// @param[in] p Reference link
    /// @param[in] s Value to search for
    Link *find(Link *p, const double &s);

    // move n positions in list; return nullptr for “not found”
    // positive n moves forward, negative backward
    Link *advance(Link *p, int n);

    void print_all(Link* p);
};

#endif
