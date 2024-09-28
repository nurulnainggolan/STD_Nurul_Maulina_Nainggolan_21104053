#ifndef LATIHAN2_CPP
#define LATIHAN2_CPP


#include <iostream>
#include <string>
using namespace std;


string bilTeks(int bil) {
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (bil < 10) {
        return satuan[bil];
    } else if (bil < 20) {
        return belasan[bil - 10];
    } else if (bil < 100) {
        int puluh = bil / 10;
        int sisa = bil % 10;
        return puluhan[puluh] + (sisa != 0 ? " " + satuan[sisa] : "");
    }

    return "Diluar jangkauan";
}

int main() {
    float bil1;
    int bil1Int;

    // Input bilangan pertama
    cout << "Masukkan bilangan: ";
    cin >> bil1;

    // Cek apakah input valid
    if (cin.fail()) {
        cout << "Error: Input bukan angka" << endl;
        return 1; // Mengakhiri program dengan kode error
    }

    // Ubah bilangan pertama ke bentuk integer untuk diubah ke teks
    bil1Int = static_cast<int>(bil1);
    cout << bil1Int << " : " << bilTeks(bil1Int) << endl;

    return 0;
}


#endif // LATIHAN2_CPP
