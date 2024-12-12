#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int jumlahSimpul;

    // Meminta jumlah simpul dari pengguna
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    vector<string> namaSimpul(jumlahSimpul);
    vector<vector<int>> matriksBobot(jumlahSimpul, vector<int>(jumlahSimpul));

    // Memasukkan nama-nama simpul
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Silakan masukkan nama simpul " << i + 1 << ": ";
        cin >> namaSimpul[i];
    }

    // Memasukkan bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << namaSimpul[i] << "--> " << namaSimpul[j] << ": ";
            cin >> matriksBobot[i][j];
        }
    }

    // Mencetak matriks bobot
    cout << endl;
    cout << setw(10) << " ";
    for (const string &nama : namaSimpul) {
        cout << setw(10) << nama;
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << setw(10) << namaSimpul[i];
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << setw(10) << matriksBobot[i][j];
        }
        cout << endl;
    }

    return 0;
}