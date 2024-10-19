#include <iostream>
#include "list.h"

using namespace std;

//membuat isi list sebanyak 3 elemen yang berisikan 3 digit nim
/*int main() {
    //  1. create list
    List L;
    createList(L);

    // 2. menambahkan angka pertama
    address P;
    int angka1;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
     // 3. funggsi allocate
    P = allocate(angka1);
    //4. memanggil insert first
    insertFirst(L, P);


    // 5. mengecek apakah angka tersebut berhasil menjadi elemen di List.
    cout << "Isi list setelah elemen pertama: ";
    printinfo(L);

    // 6. Buat kembali sintak no 2 s/d 5 untuk data angka kedua dari user
    int angka2;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;
    P = allocate(angka2);
    insertFirst(L, P);

    cout << "Isi list setelah elemen kedua: ";
    printinfo(L);

    // 7. Buat kembali sintak no 2 s/d 5 untuk data angka ketiga dari user
    int angka3;
    cout << "Masukkan angka ketiga: ";
    cin >> angka3;
    P = allocate(angka3);
    insertFirst(L, P);

    cout << "Isi list setelah elemen ketiga: ";
    printinfo(L);
    

    return 0;
}*/


////lopping nomor 7

int main() {
    // 1. Create list
    List L;
    createList(L);

    // 2. Input NIM (assume 10-digit NIM)
    int nim[10];
    cout << "Masukkan NIM per digit" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Digit " << i + 1 << " : ";
        cin >> nim[i];
        address P = allocate(nim[i]);
        insertLast(L, P); // Use insertLast to keep the order
    }

    // 3. Display the list
    cout << "Isi list: ";
    printinfo(L);

    return 0;
}
