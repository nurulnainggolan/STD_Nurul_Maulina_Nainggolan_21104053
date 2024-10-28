#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

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
    cout << "Daftar elemen dari depan ke belakang : ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Fungsi untuk menampilkan elemen dari belakang ke depan
void displayBackward() {
    Node* temp = head;
    if (temp == NULL) return;

    // Pindah ke node terakhir
    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Daftar elemen dari belakang ke depan : ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->prev != NULL) {
            cout << " <-> ";
        }
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    int n, data;

    cout << "Masukkan 4 elemen secara berurutan: ";
    for (int i = 0; i < 4; i++) {
        cin >> data;
        insertLast(data);
    }

    // Tampilkan list dari depan ke belakang
    displayForward();

    // Tampilkan list dari belakang ke depan
    displayBackward();

    return 0;
}
