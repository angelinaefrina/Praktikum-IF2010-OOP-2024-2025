#include "BarangElektronik.hpp"

// ctor
BarangElektronik::BarangElektronik(string nama, int berat, int voltase): Barang(nama, berat), voltase(voltase) {}

// methods
int BarangElektronik::getVoltase() const {
    return voltase;
}

string BarangElektronik::getJenis() const {
    return "Elektronik";
}