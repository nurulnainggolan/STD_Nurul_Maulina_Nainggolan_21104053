#ifndef LATIHAN1_CPP
#define LATIHAN1_CPP


#include <iostream>
using namespace std;

int main() {
    float bil1, bil2;

    // Input bilangan pertama
    cout << "Masukkan bilangan pertama: ";
    cin >> bil1;



    // Input bilangan kedua
    cout << "Masukkan bilangan kedua: ";
    cin >> bil2;



    // Menampilkan hasil operasi jika input valid
    cout << "\nHasil penjumlahan: " << bil1 + bil2 << endl;
    cout << "Hasil pengurangan: " << bil1 - bil2 << endl;
    cout << "Hasil perkalian: " << bil1 * bil2 << endl;
    cout << "Hasil pembagian: " << bil1 / bil2 << endl;

    return 0;
}


#endif // LATIHAN1_CPP
