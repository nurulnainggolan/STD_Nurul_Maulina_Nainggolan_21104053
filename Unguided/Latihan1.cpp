/* 
|Latihan 1.
|Manajemen Data Pegawai dan Proyek
|Buatlah program menggunakan Multi Linked List untuk menyimpan data pegawai dan
|proyek yang dikelola setiap pegawai.
|- Setiap pegawai memiliki data: Nama Pegawai dan ID Pegawai.
|- Setiap proyek memiliki data: Nama Proyek** dan **Durasi (bulan).
|Instruksi:
|1. Masukkan data pegawai berikut:
|- Pegawai 1: Nama = "Andi", ID = "P001".
|- Pegawai 2: Nama = "Budi", ID = "P002".
|- Pegawai 3: Nama = "Citra", ID = "P003".
|2. Tambahkan proyek ke pegawai:
|- Proyek 1: Nama = "Aplikasi Mobile", Durasi = 12 bulan (Untuk Andi).
|- Proyek 2: Nama = "Sistem Akuntansi", Durasi = 8 bulan (Untuk Budi).
|- Proyek 3: Nama = "E-commerce", Durasi = 10 bulan (Untuk Citra).
|3. Tambahkan proyek baru:
|- Proyek 4: Nama = "Analisis Data", Durasi = 6 bulan (Untuk Andi).
|4. Hapus proyek "Aplikasi Mobile" dari Andi.
|5. Tampilkan data pegawai dan proyek mereka.
*/


#include <iostream>
#include <string>

using namespace std;

// Node untuk Proyek
struct Proyek {
    string namaProyek;
    int durasi; 
    Proyek* berikut;

    Proyek(string nama, int dur) : namaProyek(nama), durasi(dur), berikut(nullptr) {}
};

// Node untuk Pegawai
struct Pegawai {
    string namaPegawai;
    string idPegawai;
    Proyek* kepalaProyek; 
    Pegawai* berikut;

    Pegawai(string nama, string id) : namaPegawai(nama), idPegawai(id), kepalaProyek(nullptr), berikut(nullptr) {}
};

// Kelas Multi Linked List
class ManajemenPegawaiProyek {
private:
    Pegawai* kepala;

public:
    ManajemenPegawaiProyek() : kepala(nullptr) {}

    // Tambahkan Pegawai
    void tambahPegawai(const string& nama, const string& id) {
        Pegawai* pegawaiBaru = new Pegawai(nama, id);
        pegawaiBaru->berikut = kepala;
        kepala = pegawaiBaru;
    }

    // Cari Pegawai berdasarkan ID
    Pegawai* cariPegawai(const string& id) {
        Pegawai* sementara = kepala;
        while (sementara) {
            if (sementara->idPegawai == id)
                return sementara;
            sementara = sementara->berikut;
        }
        return nullptr;
    }

    // Tambahkan Proyek ke Pegawai
    void tambahProyekKePegawai(const string& id, const string& namaProyek, int durasi) {
        Pegawai* pegawai = cariPegawai(id);
        if (pegawai) {
            Proyek* proyekBaru = new Proyek(namaProyek, durasi);
            proyekBaru->berikut = pegawai->kepalaProyek;
            pegawai->kepalaProyek = proyekBaru;
        } else {
            cout << "Pegawai dengan ID " << id << " tidak ditemukan.\n";
        }
    }

    // Hapus Proyek dari Pegawai
    void hapusProyekDariPegawai(const string& id, const string& namaProyek) {
        Pegawai* pegawai = cariPegawai(id);
        if (pegawai) {
            Proyek* sekarang = pegawai->kepalaProyek;
            Proyek* sebelumnya = nullptr;

            while (sekarang) {
                if (sekarang->namaProyek == namaProyek) {
                    if (sebelumnya) {
                        sebelumnya->berikut = sekarang->berikut;
                    } else {
                        pegawai->kepalaProyek = sekarang->berikut;
                    }
                    delete sekarang;
                    cout << "Proyek " << namaProyek << " berhasil dihapus dari Pegawai " << pegawai->namaPegawai << ".\n";
                    return;
                }
                sebelumnya = sekarang;
                sekarang = sekarang->berikut;
            }
            cout << "Proyek " << namaProyek << " tidak ditemukan pada Pegawai " << pegawai->namaPegawai << ".\n";
        } else {
            cout << "Pegawai dengan ID " << id << " tidak ditemukan.\n";
        }
    }

    // Tampilkan Data Pegawai dan Proyek
    void tampilkanData() {
        Pegawai* pegawai = kepala;
        while (pegawai) {
            cout << "Nama Pegawai: " << pegawai->namaPegawai << ", ID: " << pegawai->idPegawai << "\n";
            cout << "  Proyek:\n";
            Proyek* proyek = pegawai->kepalaProyek;
            if (!proyek) {
                cout << "    Tidak ada proyek.\n";
            }
            while (proyek) {
                cout << "    - " << proyek->namaProyek << " (" << proyek->durasi << " bulan)\n";
                proyek = proyek->berikut;
            }
            pegawai = pegawai->berikut;
            cout << endl;
        }
    }
};

int main() {
    ManajemenPegawaiProyek manajemen;

    // Tambahkan Pegawai
    manajemen.tambahPegawai("Andi", "P001");
    manajemen.tambahPegawai("Budi", "P002");
    manajemen.tambahPegawai("Citra", "P003");

    // Tambahkan Proyek ke Pegawai
    manajemen.tambahProyekKePegawai("P001", "Aplikasi Mobile", 12);
    manajemen.tambahProyekKePegawai("P002", "Sistem Akuntansi", 8);
    manajemen.tambahProyekKePegawai("P003", "E-commerce", 10);

    // Tambahkan Proyek Baru
    manajemen.tambahProyekKePegawai("P001", "Analisis Data", 6);

    // Hapus Proyek
    manajemen.hapusProyekDariPegawai("P001", "Aplikasi Mobile");

    // Tampilkan Data
    manajemen.tampilkanData();

    return 0;
}
