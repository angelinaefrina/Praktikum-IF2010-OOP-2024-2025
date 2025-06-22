#include <iostream>
#include <array>
#include <cmath>
using namespace std;

template<class K, class V>
class KeyValue {
    private:
        static const int MAX_SIZE = 10;
        array<K, MAX_SIZE> keys;
        array<V, MAX_SIZE> values;
        int size;
    public:
        KeyValue() : size(0) {} // ctor
        KeyValue(const KeyValue& other) { // cctor
            keys = other.keys;
            values = other.values;
            size = other.size;
        }
        ~KeyValue() {} // dtor

        // methods
        void set(const K& key, const V& value) {
            for (int i = 0; i < size; i++) {
                if (keys[i] == key) { // kalo key ada dalam array
                    values[i] = value;
                    return;
                }
            }
            if (size < MAX_SIZE) { // kalo key belom ada dalam array, tambahkan
                keys[size] = key;
                values[size] = value;
                size++;
            } else {
                cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            }
        }

        void display(const K& key) const {
            for (int i = 0; i < size; i++) {
                if (keys[i] == key) {
                    cout << values[i] << endl;
                    return;
                }
            }
            cout << "Key tidak ditemukan!" << endl;
        }

};


// template specialization
template <typename V>
class KeyValue<double, V> {
    private:
        static const int MAX_SIZE = 10;
        array<double, MAX_SIZE> keys;
        array<V, MAX_SIZE> values;
        int size;
    public:
        KeyValue() : size(0) {} // ctor
        KeyValue(const KeyValue& other) { // cctor
            keys = other.keys;
            values = other.values;
            size = other.size;
        }
        ~KeyValue() {} // dtor

        // methods
        void set(double key, const V& value) {
            for (int i = 0; i < size; i++) {
                if (fabs(keys[i] - key) < 0.01) { // kalo key ada dalam array cek dulu toleransiya
                    values[i] = value;
                    return;
                }
            }
            if (size < MAX_SIZE) { // kalo key belom ada dalam array, tambahkan
                keys[size] = key;
                values[size] = value;
                size++;
            } else {
                cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            }
        }

        void display(double key) const {
            for (int i = 0; i < size; i++) {
                if (fabs(keys[i] - key) < 0.01) {
                    cout << values[i] << endl;
                    return;
                }
            }
            cout << "Key tidak ditemukan!" << endl;
        }

};

// int main() {
//     KeyValue<int, string> kv;
//     kv.set(1, "Alice");
//     kv.set(2, "Bob");
//     kv.set(3, "Charlie");
//     kv.display(1);
//     kv.display(2);
//     kv.display(3);

//     // Specialization for double
//     KeyValue<double, string> kvDouble;
//     kvDouble.set(1.01, "X");
//     kvDouble.display(1.01);
//     kvDouble.set(1.012, "Y");
//     kvDouble.display(1.01);
//     kvDouble.display(1.02);

//     return 0;
// }

