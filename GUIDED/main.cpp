#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

// Mendeklarasikan prototype fungsi maks3
/*int maks3(int a, int b, int c);

int main() {
    system("cls"); // Membersihkan layar

    int x, y, z;

    cout << "Masukkan nilai bilangan ke-1 = ";
    cin >> x;

    cout << "Masukkan nilai bilangan ke-2 = ";
    cin >> y;

    cout << "Masukkan nilai bilangan ke-3 = ";
    cin >> z;

    cout << "Nilai maksimumnya adalah = " << maks3(x, y, z) << endl;

    getch(); // Menunggu input dari pengguna sebelum program selesai
    return 0;
}*/

// Badan fungsi maks3
int maks3(int a, int b, int c) {
    // Deklarasi variabel lokal dalam fungsi
    int temp_max = a;

    if (b > temp_max) {
        temp_max = b;
    }
    if (c > temp_max) {
        temp_max = c;
    }

    return temp_max;
}

// #include <iostream>
// #include <conio.h>

// #define MAX 5

// using namespace std;

// int main() {
//     int i, j;
//     float nilai_total, rata_rata;
//     float nilai[MAX];

//     static int nilai_tahun[MAX][MAX] = 
//     {
//         {0, 2, 2, 0, 0},
//         {0, 1, 1, 1, 0},
//         {0, 3, 3, 3, 0},
//         {4, 4, 0, 0, 4},
//         {5, 0, 0, 0, 5},
//     };

//     for (i = 0; i < MAX; i++) {
//         cout << "Masukkan nilai ke - " << i + 1 << ": ";
//         cin >> nilai[i];
//     }

//     cout << endl << "Data nilai siswa:" << endl;

//     for (i = 0; i < MAX; i++) {
//         cout << "Nilai ke-" << i + 1 << " = " << nilai[i] << endl;
//     }

//     cout << endl << "Nilai tahunan:" << endl;

//     for (i = 0; i < MAX; i++) {
//         for (j = 0; j < MAX; j++) {
//             cout << nilai_tahun[i][j];
//         }
//         cout << endl;
//     }

//     getch();

//     return 0;
// }


// #include <iostream>
// #include <conio.h>

// using namespace std;

// int main() {
//     int x, y; // x dan y tipe int
//     int *px; // px merupakan variabel pointer menunjuk ke variabel int
//     x = 87;
//     px = &x;
//     y = *px;

//     cout << "Alamat x= " << &x << endl;
//     cout << "Isi x= " << px << endl;
//     cout << "Isi x= " << x << endl;
//     cout << "Nilai yang ditunjuk x= " << px << endl;
//     cout << "Nilai y= " << y << endl;
//     getch();

//     return 0;
// }