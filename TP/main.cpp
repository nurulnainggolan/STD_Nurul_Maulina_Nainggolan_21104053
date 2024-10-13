#include <iostream>
using namespace std;

//menampilakn pointer
/*int main() {
    int x = 10;            
    double y = 20.5;      

    
    cout << "Alamat memori dari x: " << &x << endl;
    cout << "Alamat memori dari y: " << &y << endl;

    return 0;
}*/


//menampilkan nilai melalui pinter
#include <iostream>
using namespace std;

int main() {
    int x = 42;           // Deklarasi variabel x dengan nilai 42
    int* ptr = &x;        // Pointer ptr menyimpan alamat dari variabel x

    // Menampilkan nilai dari variabel x
    cout << "Nilai dari x: " << x << endl;

    // Menampilkan alamat dari variabel x
    cout << "Alamat dari x: " << &x << endl;

    // Menampilkan alamat yang disimpan oleh pointer ptr
    cout << "Alamat yang disimpan di ptr: " << ptr << endl;

    // Menampilkan nilai yang ditunjuk oleh pointer ptr
    cout << "Nilai yang ditunjuk oleh ptr: " << *ptr << endl;

    return 0;
}

