#include "doublelist.h"

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address allocate(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealocate(address &P) {
    delete P;
}

void printInfo(const List &L) {
    address P = L.First;
    cout << "DATA LIST 1" << endl;
    while (P != nullptr) {
        cout << "no polisi  : " << P->info.no_pol << endl;
        cout << "warna      : " << P->info.warna << endl;
        cout << "tahun      : " << P->info.thnBuat << endl;
        P = P->next;
    }
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }

}


//mencari elemen
address findElm(List L, string no_pol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.no_pol == no_pol) {
            return P; 
        }
        P = P->next;
    }
    return nullptr; 
}

//menghapus elemen
void deleteFirst(List &L, address &P) {
    if (L.First != nullptr) {
        P = L.First;
        if (L.First->next == nullptr) { 
            L.First = nullptr;
            L.Last = nullptr;
        } else {
            L.First = L.First->next;
            L.First->prev = nullptr;
        }
        P->next = nullptr; 
    }
}

void deleteLast(List &L, address &P) {
    if (L.Last != nullptr) {
        P = L.Last;
        if (L.Last->prev == nullptr) { // Jika hanya ada satu elemen
            L.First = nullptr;
            L.Last = nullptr;
        } else {
            L.Last = L.Last->prev;
            L.Last->next = nullptr;
        }
        P->prev = nullptr; // Putuskan hubungan P dari list
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        if (P->next != nullptr) { // Jika P bukan elemen terakhir
            Prec->next = P->next;
            P->next->prev = Prec;
        } else { // Jika P adalah elemen terakhir
            Prec->next = nullptr;
        }
        P->next = nullptr;
        P->prev = nullptr;
    }
}




