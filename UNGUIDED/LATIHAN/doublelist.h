#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <string>

using namespace std;

struct kendaraan {
    string no_pol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;

struct ElmList {
    infotype info;
    ElmList* next;
    ElmList* prev;
};

typedef ElmList* address;

struct List {
    address First;
    address Last;
};

// Function prototypes
void CreateList(List &L);
address allocate(infotype x);
void dealocate(address &P);
void printInfo(const List &L);
void insertLast(List &L, address P);

//mencari elemen
address findElm(List L, string no_pol);

//menghapus elemen
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);


#endif
