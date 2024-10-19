//deklarasi tipe list
#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
using namespace std;
typedef int infotype;
typedef struct elmlist *address;

struct elmlist
{
    infotype info;
    address next;
};
struct List
{
    address first;
};

//membuat list kosong
void createList(List &L);

//membuat elemen menggunakan fungsi allocate
address allocate(infotype x);

//elemen di insert agar menjadi elemen list
void insertFirst(List &L, address P);

//menampilkan isi list
void printinfo(List L);


// New functions
void insertLast(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
address searchInfo(List L, infotype x);

