#include <iostream>
#include <string>

using namespace std;


struct Node {
    int NIM;
    string Nama;
    Node* next;
};

// menambahkan data mahasiswa
void NewData(Node** head_ref, int NIM, string Nama) {
    Node* new_node = new Node();  
    new_node->NIM = NIM;          
    new_node->Nama = Nama;        
    new_node->next = (*head_ref); 
    (*head_ref) = new_node;      
}

// mencari mahasiswa berdasarkan NIM
void cariMahasiswa(Node* head, int NIM) {
    Node* current = head;  
    while (current != NULL) {
        if (current->NIM == NIM) {
            cout << "Mahasiswa ditemukan: " << current->Nama << endl;
            return;
        }
        current = current->next;
    }
    cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
}

int main() {
    Node* head = NULL; // Linked list kosong
    
    // Menambahkan beberapa data mahasiswa
    NewData(&head, 21104053, "Nurul Maulina");
    NewData(&head, 21104031, "Rido Sihombing");
    NewData(&head, 21104011, "Nabilla Tasya");
    
    // Mencari mahasiswa berdasarkan NIM
    int cariNIM;
    cout << "Masukkan NIM yang ingin dicari: ";
    cin >> cariNIM;
    cariMahasiswa(head, cariNIM);
    
    return 0;
}
