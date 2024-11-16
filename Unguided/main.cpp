#include <iostream>
#include <limits>
using namespace std;

/// PROGRAM BINARY TREE MODIFIED

// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

// Inisialisasi
void init() {
    root = NULL;
}

// Cek Node
bool isEmpty() {
    return root == NULL;
}

// Buat Node Baru
void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

// Tambah Kiri
Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->left != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

// Tambah Kanan
Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->right != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
    }
    baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

// Ubah Data Tree
void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node) {
        cout << "\nNode yang ingin diganti tidak ada!" << endl;
        return;
    }
    char temp = node->data;
    node->data = data;
    cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
}

// Lihat Isi Data Tree
void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nData node: " << node->data << endl;
}

// Cari Data Tree
void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nData Node: " << node->data << endl;
    cout << "Root: " << root->data << endl;
    string parent;
    parent = parent + node->parent->data;
    cout << "Parent: " << (node->parent ? parent : "(tidak punya parent)") << endl;
    if (node->parent) {
        if (node->parent->left == node && node->parent->right)
            cout << "Sibling: " << node->parent->right->data << endl;
        else if (node->parent->right == node && node->parent->left)
            cout << "Sibling: " << node->parent->left->data << endl;
        else
            cout << "Sibling: (tidak ada sibling)" << endl;
    }
}

// Tampilkan Child
void showChildren(Pohon *node) {
    if (!node) return;
    cout << "\nChild dari " << node->data << ": ";
    if (node->left) cout << "Left: " << node->left->data << " ";
    if (node->right) cout << "Right: " << node->right->data << " ";
    cout << endl;
}

// Tampilkan Descendant
void showDescendants(Pohon *node) {
    if (!node) return;
    if (node->left) {
        cout << node->left->data << " ";
        showDescendants(node->left);
    }
    if (node->right) {
        cout << node->right->data << " ";
        showDescendants(node->right);
    }
}

// Fungsi rekursif untuk memeriksa apakah BST
bool is_valid_bst(Pohon *node, char min_val, char max_val) {
    if (!node) return true;
    if (node->data <= min_val || node->data >= max_val) return false;
    return is_valid_bst(node->left, min_val, node->data) && is_valid_bst(node->right, node->data, max_val);
}

// Fungsi rekursif untuk menghitung simpul daun
int cari_simpul_daun(Pohon *node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

// Menu Program
void menu() {
    char pilihan, data;
    Pohon *node = NULL;

    do {
        cout << "\nMenu:\n";
        cout << "1. Buat Node\n";
        cout << "2. Tambah Kiri\n";
        cout << "3. Tambah Kanan\n";
        cout << "4. Update Node\n";
        cout << "5. Retrieve Node\n";
        cout << "6. Find Node\n";
        cout << "7. Tampilkan Child\n";
        cout << "8. Tampilkan Descendant\n";
        cout << "9. Cek Validitas BST\n";
        cout << "10. Hitung Simpul Daun\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

         switch (pilihan) {
            case '1':
                cout << "Masukkan data root: ";
                cin >> data;
                buatNode(data);
                break;
            case '2':
                cout << "Masukkan data dan parent untuk kiri: ";
                cin >> data >> data;
                node = insertLeft(data, root);
                break;
            case '3':
                cout << "Masukkan data dan parent untuk kanan: ";
                cin >> data >> data;
                node = insertRight(data, root);
                break;
            case '4':
                cout << "Masukkan data baru dan node target: ";
                cin >> data >> data;
                update(data, root);
                break;
            case '5':
                cout << "Retrieve node: ";
                retrieve(root);
                break;
            case '6':
                cout << "Find node: ";
                find(root);
                break;
            case '7':
                cout << "Tampilkan child dari node: ";
                showChildren(root);
                break;
            case '8':
                cout << "Tampilkan descendant dari node: ";
                showDescendants(root);
                cout << endl;
                break;
            case '9':
                cout << "Cek validitas BST: ";
                if (is_valid_bst(root, numeric_limits<char>::min(), numeric_limits<char>::max()))
                    cout << "Valid BST\n";
                else
                    cout << "Tidak Valid BST\n";
                break;
            case 10:  // Corrected case label to an integer
                cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << endl;
                break;
            case '0':
                cout << "Keluar.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != '0');
}

int main() {
    init();
    menu();
    return 0;
}