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

//mencari elemen 
void searchElement(Node* head, int cari_elmn) {
    Node* current = head;
    int position= 1;
    bool found = false;

    while(current != nullptr) {
        if(current->data == cari_elmn) {
            found = true;
            cout << "Elemen ditemukan di alamat: " << current << "pada urutan ke- " << position << endl;
            break;
        }
        current = current->next;
        position++;
    }

    if (!found) {
        cout << "Elemen" << cari_elmn << "tidak ditemukan dalam list!!" << endl;
    }

}




int main() {
    Node* head = nullptr;
    int value;

    //memasukkan 6 elemen
    cout << "Masukkan 6 Elemen ke Dalam List: " << endl;
    for(int i=0; i<6; i++) {
        cout << "Elemen Ke- " << i + 1 << ": ";
        cin >> value;
        append(head, value);
    }

    //memasukkan elemen
    int cari_elm;
    cout << "Masukkan Elemen yang dicari: ";
    cin >> cari_elm;


    //cari elemen dalam linked list
    searchElement(head, cari_elm);

    return 0;
}
