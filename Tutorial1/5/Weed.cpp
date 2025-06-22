#include <iostream>
#include "Weed.hpp"
using namespace std;

// default ctor
Weed::Weed() {
    this->many = 1;
}
// user defined ctor
Weed::Weed(int n) {
    this->many = n;
}
// cctor
Weed::Weed(const Weed &b) {
    this->many = b.many;
}
// dtor
Weed::~Weed(){}

void Weed::step() { 
    for (int i = 0; i < this->many; i++) {
        cout << "kresek...";
    }
    cout << endl;
}