#include <iostream>
using namespace std;

//defenisi tipe data elemen dan pointer ke elemen
struct Elemen 
{
    int data;
    Elemen*next;
};

//defenisi tipe data untuk list
struct List
{
    Elemen*first;
};

//fungsi untuk membuat list kosong
void createList(List&L) {
    L.first = NULL;
}

//Fungsi untuk mengalokasikan elemen baru
Elemen* alokasi(int x) {
    Elemen* P = new Elemen;
    if (P!= NULL) {
        P-> data = x;
        P -> next = NULL;
    }
    return P;
}

//fungsi untuk menambahkan elemen di awal list
void insertFirst(List& L, Elemen* P) {
    P-> next = L.first;
    L.first = P;
}

//Fungsi untuk mencetak semua elemen di list
void printInfo(List L) {
    Elemen* P = L.first;
    while (P != NULL) {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}

//fungsi untuk mencari elemen dengan nilai x
Elemen* findElemen(List L, int x) {
    Elemen* P = L.first;
    while (P != NULL) {
        if (P->data == x) {
            return P; //elemen ditemukan
        }
        P = P-> next;
    }
    return NULL; //elemen tidak ditemukan
}


//Fungsi menghitung total nilai semua elemen dalam list
int sumAllElements(List L) {
    int total = 0;
    Elemen* P = L.first;
    while (P != NULL)
    {
        total += P->data;
        P = P->next;
    }
    return total;
    
}
