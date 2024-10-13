#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float nilaiUTS;
    float nilaiUAS;
    float nilaiTugas;
    float nilaiAkhir;
};

// Fungsi untuk menghitung nilai akhir mahasiswa
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    const int MAX_MAHASISWA = 10;
    Mahasiswa mahasiswa[MAX_MAHASISWA];
    int jumlahMahasiswa;

    cout << "Masukkan jumlah mahasiswa (maksimal 10): ";
    cin >> jumlahMahasiswa;

    if (jumlahMahasiswa > MAX_MAHASISWA) {
        cout << "Jumlah mahasiswa melebihi batas maksimal." << endl;
        return 1;
    }

    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << ":" << endl;
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, mahasiswa[i].nama);
        cout << "Masukkan NIM: ";
        getline(cin, mahasiswa[i].nim);
        cout << "Masukkan Nilai UTS: ";
        cin >> mahasiswa[i].nilaiUTS;
        cout << "Masukkan Nilai UAS: ";
        cin >> mahasiswa[i].nilaiUAS;
        cout << "Masukkan Nilai Tugas: ";
        cin >> mahasiswa[i].nilaiTugas;

        // Menghitung nilai akhir menggunakan fungsi
        mahasiswa[i].nilaiAkhir = hitungNilaiAkhir(mahasiswa[i].nilaiUTS, mahasiswa[i].nilaiUAS, mahasiswa[i].nilaiTugas);
    }

    // Menampilkan data mahasiswa
    cout << "\nData Mahasiswa:" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << ":" << endl;
        cout << "Nama: " << mahasiswa[i].nama << endl;
        cout << "NIM: " << mahasiswa[i].nim << endl;
        cout << "Nilai UTS: " << mahasiswa[i].nilaiUTS << endl;
        cout << "Nilai UAS: " << mahasiswa[i].nilaiUAS << endl;
        cout << "Nilai Tugas: " << mahasiswa[i].nilaiTugas << endl;
        cout << "Nilai Akhir: " << mahasiswa[i].nilaiAkhir << endl;
    }

    return 0;
}
