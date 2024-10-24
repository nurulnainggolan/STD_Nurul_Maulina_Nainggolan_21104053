#ifndef SINGLELIST_H
#define SINGLELIST_H

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

// Membuat list kosong
void CreateList(List &L);

// Mengalokasikan memori untuk elemen baru
address alokasi(infotype x);

// Menghapus elemen dari memori
void dealokasi(address P);

// Mencetak info dari elemen list
void printInfo(const List &L);

// Menambahkan elemen di awal list
void insertFirst(List &L, address P);

//mencari elemen
address findElm(const List &L, infotype x);

// menghitung jumlah total seluruh elemen
int sumInfo(const List &L);

#endif
