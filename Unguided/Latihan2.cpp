/*
|2. Sistem Manajemen Buku Perpustakaan
|   Gunakan Multi Linked List untuk menyimpan data anggota perpustakaan dan daftar buku yang dipinjam.
|- Setiap anggota memiliki data: Nama Anggota dan ID Anggota.
|- Setiap buku memiliki data: Judul Buku dan Tanggal Pengembalian.
|
|Instruksi:
|1. Masukkan data anggota berikut:
|- Anggota 1: Nama = "Rani", ID = "A001".
|- Anggota 2: Nama = "Dito", ID = "A002".
|- Anggota 3: Nama = "Vina", ID = "A003".
|
|2. Tambahkan buku yang dipinjam:
|- Buku 1: Judul = "Pemrograman C++", Pengembalian = "01/12/2024" (Untuk Rani).
|- Buku 2: Judul = "Algoritma Pemrograman", Pengembalian = "15/12/2024" (Untuk Dito).
|
|3. Tambahkan buku baru:
|- Buku 3: Judul = "Struktur Data", Pengembalian = "10/12/2024" (Untuk Rani).
|
|4. Hapus anggota Dito beserta buku yang dipinjam.
|5. Tampilkan seluruh data anggota dan buku yang dipinjam */


#include <iostream>
#include <string>

using namespace std;

// Node untuk Buku
struct Buku {
    string judulBuku;
    string tanggalPengembalian;
    Buku* berikut;

    Buku(string judul, string tanggal) : judulBuku(judul), tanggalPengembalian(tanggal), berikut(nullptr) {}
};

// Node untuk Anggota
struct Anggota {
    string namaAnggota;
    string idAnggota;
    Buku* kepalaBuku; 
    Anggota* berikut;

    Anggota(string nama, string id) : namaAnggota(nama), idAnggota(id), kepalaBuku(nullptr), berikut(nullptr) {}
};

// Kelas Multi Linked List
class ManajemenPerpustakaan {
private:
    Anggota* kepala;

public:
    ManajemenPerpustakaan() : kepala(nullptr) {}

    // Tambahkan Anggota
    void tambahAnggota(const string& nama, const string& id) {
        Anggota* anggotaBaru = new Anggota(nama, id);
        anggotaBaru->berikut = kepala;
        kepala = anggotaBaru;
    }

    // Cari Anggota berdasarkan ID
    Anggota* cariAnggota(const string& id) {
        Anggota* sementara = kepala;
        while (sementara) {
            if (sementara->idAnggota == id)
                return sementara;
            sementara = sementara->berikut;
        }
        return nullptr;
    }

    // Tambahkan Buku ke Anggota
    void tambahBukuKeAnggota(const string& id, const string& judulBuku, const string& tanggalPengembalian) {
        Anggota* anggota = cariAnggota(id);
        if (anggota) {
            Buku* bukuBaru = new Buku(judulBuku, tanggalPengembalian);
            bukuBaru->berikut = anggota->kepalaBuku;
            anggota->kepalaBuku = bukuBaru;
        } else {
            cout << "Anggota dengan ID " << id << " tidak ditemukan.\n";
        }
    }

    // Hapus Anggota beserta Buku yang Dipinjam
    void hapusAnggota(const string& id) {
        Anggota* sekarang = kepala;
        Anggota* sebelumnya = nullptr;

        while (sekarang) {
            if (sekarang->idAnggota == id) {
                if (sebelumnya) {
                    sebelumnya->berikut = sekarang->berikut;
                } else {
                    kepala = sekarang->berikut;
                }
                // Hapus semua buku yang dipinjam
                Buku* buku = sekarang->kepalaBuku;
                while (buku) {
                    Buku* hapus = buku;
                    buku = buku->berikut;
                    delete hapus;
                }
                delete sekarang;
                cout << "Anggota dengan ID " << id << " beserta buku-bukunya berhasil dihapus.\n";
                return;
            }
            sebelumnya = sekarang;
            sekarang = sekarang->berikut;
        }
        cout << "Anggota dengan ID " << id << " tidak ditemukan.\n";
    }

    // Tampilkan Data Anggota dan Buku
    void tampilkanData() {
        Anggota* anggota = kepala;
        while (anggota) {
            cout << "Nama Anggota: " << anggota->namaAnggota << ", ID: " << anggota->idAnggota << "\n";
            cout << "  Buku yang Dipinjam:\n";
            Buku* buku = anggota->kepalaBuku;
            if (!buku) {
                cout << "    Tidak ada buku yang dipinjam.\n";
            }
            while (buku) {
                cout << "    - " << buku->judulBuku << " (Pengembalian: " << buku->tanggalPengembalian << ")\n";
                buku = buku->berikut;
            }
            anggota = anggota->berikut;
            cout << endl;
        }
    }
};

int main() {
    ManajemenPerpustakaan perpustakaan;

    // Tambahkan Anggota
    perpustakaan.tambahAnggota("Rani", "A001");
    perpustakaan.tambahAnggota("Dito", "A002");
    perpustakaan.tambahAnggota("Vina", "A003");

    // Tambahkan Buku yang Dipinjam
    perpustakaan.tambahBukuKeAnggota("A001", "Pemrograman C++", "01/12/2024");
    perpustakaan.tambahBukuKeAnggota("A002", "Algoritma Pemrograman", "15/12/2024");

    // Tambahkan Buku Baru
    perpustakaan.tambahBukuKeAnggota("A001", "Struktur Data", "10/12/2024");

    // Hapus Anggota Dito
    perpustakaan.hapusAnggota("A002");

    // Tampilkan Data
    perpustakaan.tampilkanData();

    return 0;
}
