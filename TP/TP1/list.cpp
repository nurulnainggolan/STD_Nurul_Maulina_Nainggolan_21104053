//deklarasi tipe list
#include <iostream>
#include "list.h"
using namespace std;

//membuat list kosong
void createList(List &L) {
    first(L) = NULL;
}

//membuat elemen menggunakan fungsi allocate
address allocate(infotype x) {
    address p = new elmlist;
    info(p) = x;
    next(p) = NULL;

    return p;
}

//insertFirst
void insertFirst(List &L, address P) {

    next(P) = first(L);
    first(L) = P;
}

//menampilakn isi list
void printinfo (List L) {
    address p = first(L);
    while (p != NULL) {
        cout << info(p) << ", ";
        p = next(p);
    }

    cout << endl;
}



// InsertLast
void insertLast(List &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        address q = first(L);
        while (next(q) != NULL) {
            q = next(q);
        }
        next(q) = P;
    }
}

// InsertAfter
void insertAfter(List &L, address Prec, address P) {
    if (Prec != NULL) {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

// DeleteLast
void deleteLast(List &L, address &P) {
    if (first(L) != NULL) {
        if (next(first(L)) == NULL) {
            P = first(L);
            first(L) = NULL;
        } else {
            address q = first(L);
            while (next(next(q)) != NULL) {
                q = next(q);
            }
            P = next(q);
            next(q) = NULL;
        }
    }
}

// DeleteAfter
void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && next(Prec) != NULL) {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

// SearchInfo
address searchInfo(List L, infotype x) {
    address p = first(L);
    while (p != NULL) {
        if (info(p) == x) {
            return p;
        }
        p = next(p);
    }
    return NULL;
}
