#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

//menambahkan elemen ke dalam linked list
void append(Node*&head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next=nullptr;

    if(head == nullptr) {
        head = newNode;
    } else{
        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next=newNode;
        
    }
}

//menampilkan elemen
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


//mengurutkan linked list
void bubbleSortList(Node* head) {
    if (head ==nullptr) 
    return;

    bool swapped;
    Node* current;
    Node* lastPtr = nullptr;

    do {
        swapped = false;
        current = head;

        while(current->next !=lastPtr) {
            if(current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        lastPtr = current;
    }while (swapped);
}




int main() {
    Node* head = nullptr;
    int value;

    //memasukkan 5 elemen
    cout << "Masukkan 5 elemen integer ke dalam list:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> value;
        append(head, value);
    }

    // Menampilkan list sebelum sorting
    cout << "List sebelum diurutkan: ";
    displayList(head);

    // Mengurutkan list menggunakan Bubble Sort
    bubbleSortList(head);

    // Menampilkan list setelah sorting
    cout << "List setelah diurutkan: ";
    displayList(head);

    return 0;
}
