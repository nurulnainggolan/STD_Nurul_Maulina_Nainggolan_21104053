#include "singlelist.h"
#include <iostream>
using namespace std;

// Membuat list kosong
void CreateList(List &L) {
    L.First = nullptr;
}

// Mengalokasikan memori untuk elemen baru
address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}

// Menghapus elemen dari memori
void dealokasi(address P) {
    delete P;
}

// Mencetak semua elemen dalam list
void printInfo(const List &L) {
    address P = L.First;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Menambahkan elemen di awal list
void insertFirst(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
    } else {
        P->next = L.First;
        L.First = P;
    }
}


//mencari elemen
address findElm(const List &L, infotype x) {
    address P = L.First;
    while(P != nullptr) {
        if(P->info == x) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}


//menghitung seluruh elemen
int sumInfo(const List &L) {
    int total =0;
    address P = L.First;
    while (P != nullptr) {
        total += P->info;
        P = P->next;
    }
    return total;
}