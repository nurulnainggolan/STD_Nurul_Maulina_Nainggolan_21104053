#include <iostream>
using namespace std;

// Menampilkan array 2D
void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Menukar dua array 2D pada posisi tertentu
void tukarArray(int arr1[3][3], int arr2[3][3], int row, int col) {
    int temp = arr1[row][col];
    arr1[row][col] = arr2[row][col];
    arr2[row][col] = temp;
}

// Menukar isi dari dua variabel yang ditunjuk oleh pointer
void tukarPointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    
    int array1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int array2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

  
    int x = 10, y = 20;
    int* ptr1 = &x;
    int* ptr2 = &y;

  
    cout << "Array 1 sebelum pertukaran:" << endl;
    tampilArray(array1);

    cout << "Array 2 sebelum pertukaran:" << endl;
    tampilArray(array2);

    
    tukarArray(array1, array2, 1, 1);

   
    cout << "Array 1 setelah pertukaran:" << endl;
    tampilArray(array1);

    cout << "Array 2 setelah pertukaran:" << endl;
    tampilArray(array2);

   
    cout << "Nilai sebelum tukar pointer:" << endl;
    cout << "ptr1: " << *ptr1 << ", ptr2: " << *ptr2 << endl;

   
    tukarPointer(ptr1, ptr2);

    
    cout << "Nilai setelah tukar pointer:" << endl;
    cout << "ptr1: " << *ptr1 << ", ptr2: " << *ptr2 << endl;

    return 0;
}
