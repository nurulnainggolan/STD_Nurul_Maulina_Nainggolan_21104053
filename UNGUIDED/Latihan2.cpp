//program ini merupakan program untuk menerima sebuah kaliam lalu membalik setiap kata dalam kalimat
//charStack digunakan untuk membalikkan urutan huruf
//setiap kata didorong oleh perintah push ke dalam stack
//kemudian dikeluarkan menggunakan fungsi pop

#include <iostream>
#include <stack>
#include <sstream>

int main() {
    std::string kalimat, kata;

    std::cout << "Masukkan Kalimat: ";
    std::getline(std::cin, kalimat);

    std::stringstream ss(kalimat);
    std::cout << "Data : ";

    // Memisahkan kalimat menjadi kata-kata dan membalik setiap kata
    while (ss >> kata) {
        std::stack<char> charStack;

        // Masukkan setiap huruf dari kata ke dalam stack
        for (char ch : kata) {
            charStack.push(ch);
        }

        // Keluarkan huruf-huruf dari stack untuk membalik kata
        while (!charStack.empty()) {
            std::cout << charStack.top();
            charStack.pop();
        }
        std::cout << " "; // Tambahkan spasi antar kata
    }

    std::cout << std::endl;
    return 0;
}
