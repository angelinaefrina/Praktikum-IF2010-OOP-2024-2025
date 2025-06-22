#ifndef A_HPP
#define A_HPP

#include <iostream>

class A {
public:
    A(char d); // ctor
    A(const A&); // cctor
    virtual ~A(); // dtor

    A& operator=(const A&); // assignment operator

    void show();
private:
    char data;
};

#endif
