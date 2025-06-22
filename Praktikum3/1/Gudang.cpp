#include "Gudang.hpp"
#include "BarangMakanan.hpp"
#include "BarangElektronik.hpp"
#include "Exception.hpp"
#include <iostream>
using namespace std;

Gudang::Gudang(): kapasitasTotal(DEFAULT_KAPASITAS), tenagaKerja(DEFAULT_TENAGA_KERJA), uang(DEFAULT_UANG), kapasitasTerpakai(0) {}

Gudang::Gudang(int kapasitas, int uang, int tenagaKerja): kapasitasTotal(kapasitas), tenagaKerja(tenagaKerja), uang(uang), kapasitasTerpakai(0) {}

Gudang::~Gudang() {
    for (auto i = daftarBarang.begin(); i != daftarBarang.end(); i++) {
        Barang *x = daftarBarang[i - daftarBarang.begin()];
        delete x;
    }
    daftarBarang.clear();
}

void Gudang::simpanBarang(Barang *barang) {
    try{
        if (barang->getJenis() == "Makanan") {
            BarangMakanan *b = dynamic_cast<BarangMakanan*>(barang);
            if (b->getHariKedaluwarsa() <= 0) {
                BarangKedaluwarsaException e;
                throw e;
            }
        }
        if (kapasitasTerpakai + barang->getBerat() > kapasitasTotal) {
            KapasitasPenuhException e;
            throw e;
        }
        if (uang < 100) {
            UangTidakCukupException e;
            throw e;
        }
        if (tenagaKerja < 1) {
            TenagaKerjaTidakCukupException e;
            throw e;
        }

        daftarBarang.push_back(barang);
        pakaiKapasitas(barang->getBerat());
        pakaiUang(100);
        pakaiTenagaKerja();
        cout << "Barang [" << daftarBarang.size() - 1 << "] " << barang->getNama() << " berhasil disimpan" << endl;
    } catch (BarangKedaluwarsaException e) {
        cout << e.what() << ", buang dulu." << endl;
    } catch (KapasitasPenuhException e) {
        cout << e.what() << ", perluas gudang dulu." << endl;
    } catch (UangTidakCukupException e) {
        cout << e.what() << ", cari pemasukan dulu." << endl;
    } catch (TenagaKerjaTidakCukupException e) {
        cout << e.what() << ", rekrut dulu." << endl;
    }
}


void Gudang::tambahKapasitas(int kg) {
    kapasitasTotal += kg;
}

void Gudang::tambahTenagaKerja(int jumlah) {
    tenagaKerja += jumlah;
}

void Gudang::tambahUang(int jumlah) {
    uang += jumlah;
}

void Gudang::pakaiKapasitas(int kg) {
    try {
        if (kapasitasTerpakai + kg > kapasitasTotal) {
            KapasitasPenuhException e;
            throw e;
        } else {
            kapasitasTerpakai += kg;
        }
    } catch (KapasitasPenuhException e) {
        cout << e.what() << endl;
    }
}

void Gudang::pakaiUang(int jumlah) {
    try {
        if (jumlah > uang) {
            UangTidakCukupException e;
            throw e;
        } else {
            uang -= jumlah;
        }
    } catch (UangTidakCukupException e) {
        cout << e.what() << endl;
    }
}

void Gudang::pakaiTenagaKerja() {
    try {
        if (tenagaKerja < 1) {
            TenagaKerjaTidakCukupException e;
            throw e;
        } else {
            tenagaKerja -= 1;
        }
    } catch (TenagaKerjaTidakCukupException e) {
        cout << e.what() << endl;
    }
}

void Gudang::sebutBarang(int idx) {
    try {
        if (idx < 0 || idx >= daftarBarang.size()) {
            out_of_range e("Index out of range");
            throw e;
        }
        Barang *x = daftarBarang[idx];
        cout << x->getNama() << " - " << x->getJenis() << " - " << x->getBerat() << "kg" << endl;
    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}

void Gudang::statusGudang() const {
    cout << "Status gudang:" << endl;
    cout << "  Kapasitas total: " << kapasitasTotal << " kg" << endl;
    cout << "  Kapasitas terpakai: " << kapasitasTerpakai << " kg" << endl;
    cout << "  Uang: " << uang << endl;
    cout << "  Tenaga kerja: " << tenagaKerja << endl;
    cout << "  Barang:" << endl;
    for (auto i = daftarBarang.begin(); i != daftarBarang.end(); i++) {
        cout <<"    [" << i - daftarBarang.begin() << "] ";
        Barang *x = daftarBarang[i - daftarBarang.begin()];
        cout << x->getNama() << " - " << x->getJenis() << " - " << x->getBerat() << "kg" << endl;
    }
}