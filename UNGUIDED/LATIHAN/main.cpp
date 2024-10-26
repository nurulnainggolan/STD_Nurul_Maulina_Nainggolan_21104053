#include "doublelist.h"
#include <vector>  // untuk menyimpan elemen hasil pencarian
#include <iostream>

using namespace std;

int main() {
    List L;
    CreateList(L);

    infotype dataKendaraan;

    // Input data kendaraan
    for (int i = 0; i < 4; i++) {
        cout << "Masukkan nomor polisi: ";
        cin >> dataKendaraan.no_pol;
        cout << "Masukkan warna kendaraan: ";
        cin >> dataKendaraan.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> dataKendaraan.thnBuat;

        address P = allocate(dataKendaraan);
        insertLast(L, P);
    }

    cout << "\nData List Awal:\n";
    printInfo(L);

    // Pencarian nomor polisi tertentu
    string cariNopol;
    cout << "\nMasukkan nomor polisi yang dicari: ";
    cin >> cariNopol;

    // Menyimpan hasil pencarian ke dalam vector untuk pilihan penghapusan
    vector<address> hasilCariList;
    address temp = L.First;
    int count = 0;

    // Mencari semua elemen yang cocok dengan nomor polisi
    while (temp != nullptr) {
        if (temp->info.no_pol == cariNopol) {
            hasilCariList.push_back(temp);
            count++;
            cout << "Data " << count << ":\n";
            cout << "Nomor Polisi: " << temp->info.no_pol << endl;
            cout << "Warna       : " << temp->info.warna << endl;
            cout << "Tahun       : " << temp->info.thnBuat << endl;
        }
        temp = temp->next;
    }

    // Pencarian dan penghapusan berdasarkan nomor polisi
    string cariNopolHapus;
    cout << "\nMasukkan nomor polisi yang ingin dihapus: ";
    cin >> cariNopolHapus;

    // Menyimpan hasil pencarian ke dalam vector untuk menghapus semua entri dengan nomor polisi yang sama
    vector<address> hasilCariListHapus;
    temp = L.First; // Reset temp untuk pencarian baru
    bool found = false;

    // Cari semua elemen dengan nomor polisi yang sesuai
    while (temp != nullptr) {
        if (temp->info.no_pol == cariNopolHapus) {
            hasilCariListHapus.push_back(temp);
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "\nNomor polisi tidak ditemukan!" << endl;
    } else {
        // Tampilkan data yang akan dihapus
        cout << "\nDitemukan " << hasilCariListHapus.size() << " data dengan nomor polisi " << cariNopolHapus << ".\n";
        for (auto &P : hasilCariListHapus) {
            // Menghapus setiap elemen yang ditemukan
            if (P == L.First) {
                deleteFirst(L, P);
            } else if (P == L.Last) {
                deleteLast(L, P);
            } else {
                deleteAfter(P->prev, P);
            }
            cout << "Data dengan nomor polisi " << P->info.no_pol << " berhasil dihapus.\n";
            dealocate(P);
        }
    }

    cout << "\nData List Setelah Penghapusan:\n";
    printInfo(L);

    return 0;
}
