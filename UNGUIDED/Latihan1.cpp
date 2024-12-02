//Program ini bertujuan untuk memeriksa apakah suatu kalimat adalah polidrome, yaitu kalimat yang dibaca dari 
//depan dan belakang tetap sama dengan menggunakan stack
//bool isPalindrome digunakan untuk mengecek apakah kalimat tersebut adalah polidrome dengan
//menggunakan true false

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>



bool isPalindrome(const std::string &kalimat) {
    std::stack<char> stack;
    std::string kalimatPertama;


    // Masukkan setiap karakter ke dalam stack
    for (char ch : kalimatPertama ) {
        stack.push(ch);
    }

    // Periksa apakah kalimat tersebut palindrome
    for (char ch : kalimatPertama) {
        if (ch != stack.top()) {
            return false;
        }
        stack.pop();
    }
    return true;
}

int main() {
    std::string kalimat;

    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, kalimat);

    if (isPalindrome(kalimat)) {
        std::cout << "Kalimat tersebut adalah palindrome." << std::endl;
    } else {
        std::cout << "Kalimat tersebut bukan palindrome." << std::endl;
    }

    return 0;
}

