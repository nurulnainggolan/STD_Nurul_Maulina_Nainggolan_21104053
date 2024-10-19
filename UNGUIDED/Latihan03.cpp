#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Menambahkan node di depan
void insertFirst(Node*& head, int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = head;
    head = newNode;
}

// Menambahkan node di belakang
void insertLast(Node*& head, int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Mencetak linked list
void cetakLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) {
            cout << "->";
        }
        head = head->next;
    }
    cout << endl;
}

// Fungsi untuk mencari node
bool cariNode(Node* head, int nilai) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == nilai) {
            return true;
        }
        temp = temp->next;
    }
    return false; 
}

// Fungsi untuk menghitung panjang linked list
int hitungPanjang(Node* head) {
    int panjang = 0;
    Node* temp = head;
    while (temp != nullptr) {
        panjang++;
        temp = temp->next;
    }
    return panjang;
}

int main() {
    Node* head = nullptr;

    
    insertFirst(head, 10);
    insertLast(head, 20);
    insertFirst(head, 5);

    
   

    
    int cariNilai = 20;
    if (cariNode(head, cariNilai)) {
        cout << "Node dengan nilai " << cariNilai << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << cariNilai << " tidak ditemukan." << endl;
    }

    // Menghitung panjang linked list
    int panjangList = hitungPanjang(head);
    cout << "Panjang linked list: " << panjangList << endl;

    return 0;
}
