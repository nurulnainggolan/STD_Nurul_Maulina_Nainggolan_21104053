#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int NIM;
    Mahasiswa* next;
};

class Queue {
public:
    Mahasiswa* front;
    Mahasiswa* back;

    Queue() {
        front = nullptr;
        back = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string nama, int NIM) {
        Mahasiswa* newMahasiswa = new Mahasiswa;
        newMahasiswa->nama = nama;
        newMahasiswa->NIM = NIM;
        newMahasiswa->next = nullptr;

        if (isEmpty()) {
            front = back = newMahasiswa;
        } else {
            // Memasukkan mahasiswa berdasarkan urutan NIM (prioritas NIM terkecil)
            if (NIM < front->NIM) {
                newMahasiswa->next = front;
                front = newMahasiswa;
            } else {
                Mahasiswa* temp = front;
                while (temp->next != nullptr && temp->next->NIM <= NIM) {
                    temp = temp->next;
                }
                newMahasiswa->next = temp->next;
                temp->next = newMahasiswa;

                if (newMahasiswa->next == nullptr) {
                    back = newMahasiswa;
                }
            }
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong." << endl;
        } else {
            Mahasiswa* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong." << endl;
        } else {
            Mahasiswa* temp = front;
            cout << "Data Antrian Mahasiswa:" << endl;
            while (temp != nullptr) {
                cout << "Nama: " << temp->nama << ", NIM: " << temp->NIM << endl;
                temp = temp->next;
            }
        }
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue antrian;
    int pilihan;

    do {
        cout << "\nMenu Antrian Mahasiswa:\n";
        cout << "1. Tambah Mahasiswa ke Antrian\n";
        cout << "2. Hapus Mahasiswa dari Antrian\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string nama;
            int NIM;
            cout << "Masukkan Nama Mahasiswa: ";
            cin.ignore();  // Membersihkan buffer input
            getline(cin, nama);
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> NIM;

            antrian.enqueue(nama, NIM);
            cout << "Mahasiswa berhasil ditambahkan ke antrian.\n";
        } else if (pilihan == 2) {
            antrian.dequeue();
            cout << "Mahasiswa pertama dalam antrian telah dihapus.\n";
        } else if (pilihan == 3) {
            antrian.displayQueue();
        } else if (pilihan == 4) {
            cout << "Keluar dari program.\n";
        } else {
            cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 4);

    return 0;
}
