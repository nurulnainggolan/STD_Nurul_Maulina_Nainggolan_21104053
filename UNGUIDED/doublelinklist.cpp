#include <iostream>
#include <string>
using namespace std;

struct Node {
    int idBuku;
    string judulBuku;
    string penulisBuku;
    Node* prev;
    Node* next;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void tambahBuku(int id, string judul, string penulis) {
        Node* newNode = new Node();
        newNode->idBuku = id;
        newNode->judulBuku = judul;
        newNode->penulisBuku = penulis;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    void tampilkanDariAwal() {
        if (head == nullptr) {
            cout << "Daftar buku kosong." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << "ID Buku: " << temp->idBuku << ", Judul Buku: " << temp->judulBuku << ", Penulis: " << temp->penulisBuku << endl;
            temp = temp->next;
        }
    }

    void tampilkanDariAkhir() {
        if (tail == nullptr) {
            cout << "Daftar buku kosong." << endl;
            return;
        }
        Node* temp = tail;
        while (temp != nullptr) {
            cout << "ID Buku: " << temp->idBuku << ", Judul Buku: " << temp->judulBuku << ", Penulis: " << temp->penulisBuku << endl;
            temp = temp->prev;
        }
    }

    ~DoubleLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    DoubleLinkedList list;
    int pilihan, id;
    string judul, penulis;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Tampilkan Semua Buku dari Awal ke Akhir" << endl;
        cout << "3. Tampilkan Semua Buku dari Akhir ke Awal" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan ID Buku: ";
                cin >> id;
                cin.ignore();
                cout << "Masukkan Judul Buku: ";
                getline(cin, judul);
                cout << "Masukkan Penulis Buku: ";
                getline(cin, penulis);
                list.tambahBuku(id, judul, penulis);
                break;
            case 2:
                cout << "Daftar Buku dari Awal ke Akhir:" << endl;
                list.tampilkanDariAwal();
                break;
            case 3:
                cout << "Daftar Buku dari Akhir ke Awal:" << endl;
                list.tampilkanDariAkhir();
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}
