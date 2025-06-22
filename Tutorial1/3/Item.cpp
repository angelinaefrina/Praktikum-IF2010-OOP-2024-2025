#include <iostream>
#include "Item.hpp"
using namespace std;

int Item::totalRevenue = 0;
int Item::totalItems = 0;

// default ctor
Item::Item() : serialNum(++totalItems) {
    this->stock = 0;
    this->price = 0;
    this->sold = 0;
}
// user-defined ctor
Item::Item(int stock, int price) : serialNum(++totalItems) {
    this->stock = stock;
    this->price = price;
    this->sold = 0;
}
// cctor
Item::Item(const Item& p) : serialNum(++totalItems) {
    this->stock = p.stock;
    this->price = p.price;
    this->sold = p.sold;
}
// dtor
Item::~Item() {}

// getter
int Item::getSerialNum() const{
    // cout << this->serialNum << endl;
    return this->serialNum;
}
int Item::getSold() const{
    // cout << this->sold << endl;
    return this->sold;
}
int Item::getPrice() const{
    // cout << this->price << endl;
    return this->price;
}

// method lain
void Item::addStock(int addedStock) {
    this->stock += addedStock;
    // cout << this->stock << endl;
}
void Item::sell(int soldStock) {
    if (soldStock <= this->stock) {
        this->sold += soldStock;
        this->stock -= soldStock;
        totalRevenue += soldStock * this->price;
    } else {
        this->sold += this->stock;
        totalRevenue += this->stock * this->price;
        this->stock = 0;
        
    }
    // cout << this->sold << endl;
    // cout << totalRevenue << endl;
}
void Item::setPrice(int newPrice) {
    this->price = newPrice;
    // cout << this->price << endl;
}
