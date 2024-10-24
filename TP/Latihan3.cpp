#include <iostream>
using namespace std;

// Definisi struktur node
struct Node {
    int data;
    Node* next;
};

// menambahkan elemen 
void insertSorted(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    // Jika list kosong atau nilai yang dimasukkan lebih kecil dari head
    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        Node* prev = nullptr;

        // menyisipkan elemen baru
        while (current != nullptr && current->data < value) {
            prev = current;
            current = current->next;
        }

        // Menyisipkan elemen baru di posisi yang sesuai
        prev->next = newNode;
        newNode->next = current;
    }
}

//  menampilkan elemen-elemen dalam linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int value;

    // Memasukkan 4 elemen 
    cout << "Masukkan 4 elemen integer ke dalam list (urutkan secara manual):" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> value;
        insertSorted(head, value);
    }

    // Menampilkan list setelah input awal
    cout << "List setelah input awal: ";
    displayList(head);

    // memasukkan elemen tambahan
    cout << "Masukkan elemen tambahan yang ingin dimasukkan secara terurut: ";
    cin >> value;
    insertSorted(head, value);

    // Menampilkan list setelah elemen tambahan dimasukkan
    cout << "List setelah elemen tambahan dimasukkan: ";
    displayList(head);

    return 0;
}
