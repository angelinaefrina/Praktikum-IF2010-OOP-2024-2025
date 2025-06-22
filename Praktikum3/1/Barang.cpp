#include "Barang.hpp"

// ctor
Barang::Barang(string nama, int berat): nama(nama), berat(berat) {}

// dtor
Barang::~Barang() {}

// methods
string Barang::getNama() const {
    return nama;
}

int Barang::getBerat() const {
    return berat;
}