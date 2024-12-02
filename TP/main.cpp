#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    // Untuk digit terakhir NIM sisa 3, kita pakai "S T R U K T U R D A T A"
    char data[] = {'A', 'T', 'A', 'D', 'R', 'U', 'T', 'K', 'U', 'R', 'T', 'S'};
    int length = sizeof(data) / sizeof(data[0]);

    cout << "Isi stack awal: ";
    for (int i = 0; i < length; i++) {
        push(S, data[i]);
    }
    printInfo(S);

    // Pop untuk mencetak elemen "D A T A"
    cout << "Isi stack setelah pop: ";
    for (int i = 0; i < 8; i++) {
        pop(S); 
    }
    printInfo(S);

    return 0;
}
