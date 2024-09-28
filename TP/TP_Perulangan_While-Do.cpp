#ifndef TP_PERULANGAN_WHILE-DO_CPP
#define TP_PERULANGAN_WHILE-DO_CPP


#include <iostream>

using namespace std;

int main() {
    int bilangan, asli, jumlah;

    cout << "Masukkan bilangan asli: ";
    cin >> asli;

    bilangan = 1;
    jumlah = 0;
    while (bilangan <= asli) {
        if (bilangan %2 == 0) {
            jumlah += bilangan;
        }
        bilangan++;
    }
    cout << "Jumlah bilangan genap: " << jumlah << endl;
    return 0;
}

#endif // TP_PERULANGAN_WHILE-DO_CPP
