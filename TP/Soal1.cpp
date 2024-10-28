#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Fungsi untuk menambahkan elemen di awal
void insertFirst(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// Fungsi untuk menambahkan elemen di akhir
void insertLast(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Fungsi untuk menampilkan elemen dari depan ke belakang
void displayForward() {
    Node* temp = head;
    cout << "DAFTAR ANGGOTA LIST : ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << "<->";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int firstElement, secondElement, lastElement;

    // Input data sesuai dengan instruksi
    cout << "Masukkan elemen pertama = ";
    cin >> firstElement;
    insertFirst(firstElement);

    cout << "Masukkan elemen kedua = ";
    cin >> secondElement;
    insertFirst(secondElement);

    cout << "Masukkan elemen ketiga = ";
    cin >> lastElement;
    insertLast(lastElement);

    // Tampilkan list dari depan ke belakang
    displayForward();

    return 0;
}
