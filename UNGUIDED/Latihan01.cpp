#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node*next;
};


//menambahkan node di depan
void insertFirst(Node*& head, int nilai) {
    Node* newNode = new Node;
    newNode->data=nilai;
    newNode->next=head;
    head=newNode;
}

//menambahkan node dibelakang
void insertLast(Node*&head, int nilai) {
    Node* newNode = new Node;
    newNode->data=nilai;
    newNode->next=nullptr;

    if (head == nullptr) {
        head=newNode;
    } else {
        Node*temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//mencetak linked list
void cetakLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if(head->next != nullptr) {
            cout << "->";
        }
        head = head->next;
    }
    cout << endl;
}

//menghapus node nilai tertentu
void deleteNode(Node*&head, int nilai) {
    if(head == nullptr) {
        cout << "List Kosong" << endl;
        return;
    }

 //menghapus node pertama 
    if (head->data == nilai) {
        Node*temp = head;
        head = head->next;
        delete temp;
        cout << "Node dengan nilai " << nilai << "berhasil dihapus" << endl;
        return; 
    }
    // Mencari node dengan nilai yang akan dihapus
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr && temp->data != nilai) {
        prev = temp;
        temp = temp->next;
    }

    

    // Hapus node yang ditemukan
    prev->next = temp->next;
    delete temp;
    cout << "Node dengan nilai " << nilai << " berhasil dihapus." << endl;
}



int main() {
    Node*head = nullptr;

    insertFirst(head,10);
    insertLast(head, 20);
    insertFirst(head,5);

    cout << "List Node sebelum dihapus" << endl;
    cetakLinkedList(head);

    //hapus node dengan nilai 10
    deleteNode(head, 10);


    cout << "List Node setelah dihapus" << endl;
    cetakLinkedList(head);

    return 0;

}