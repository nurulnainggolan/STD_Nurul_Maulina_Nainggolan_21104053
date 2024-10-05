#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    const int MAX_X = 5; // Ukuran maksimum untuk dimensi pertama
    const int MAX_Y = 5; // Ukuran maksimum untuk dimensi kedua
    const int MAX_Z = 5; // Ukuran maksimum untuk dimensi ketiga

    // Meminta ukuran array dari user
    cout << "Masukkan ukuran dimensi pertama (x <= " << MAX_X << "): ";
    cin >> x;
    cout << "Masukkan ukuran dimensi kedua (y <= " << MAX_Y << "): ";
    cin >> y;
    cout << "Masukkan ukuran dimensi ketiga (z <= " << MAX_Z << "): ";
    cin >> z;

    // Validasi ukuran
    if (x > MAX_X || y > MAX_Y || z > MAX_Z) {
        cout << "Ukuran melebihi batas maksimum!" << endl;
        return 1;
    }

    // Mendeklarasikan array 3D statis
    int arr[MAX_X][MAX_Y][MAX_Z];

    // Input elemen array dari user
    cout << "Masukkan elemen array 3D:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "arr[" << i << "][" << j << "][" << k << "]: ";
                cin >> arr[i][j][k];
            }
        }
    }

    // Menampilkan elemen array
    cout << "\nElemen dari array 3D:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "arr[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << endl;
            }
        }
    }

    return 0;
}
