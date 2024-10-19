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

// Menghapus node dengan nilai 10
void deleteNode(Node*& head) {
    if (head == nullptr) {
        return;
    }

    // Jika node pertama yang memiliki nilai 10
    if (head->data == 10) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Mencari node dengan nilai 10
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr && temp->data != 10) {
        prev = temp;
        temp = temp->next;
    }

    // Hapus node dengan nilai 10
    prev->next = temp->next;
    delete temp;
}


int main() {
    Node* head = nullptr;

    insertFirst(head, 10);
    insertLast(head, 20);
    insertFirst(head, 5);

    cout << "List Node sebelum dihapus: " << endl;
    cetakLinkedList(head);

    // Hapus node dengan nilai 10
    deleteNode(head);

    cout << "List Node setelah dihapus: " << endl;
    cetakLinkedList(head);

    return 0;
}
