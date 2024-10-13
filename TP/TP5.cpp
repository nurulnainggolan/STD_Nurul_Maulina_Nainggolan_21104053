#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Tambahkan ini untuk menggunakan std::find
using namespace std;

class StudentList {
private:
    vector<string> students;  // Menyimpan daftar nama siswa

public:
    // Menambahkan siswa ke dalam daftar
    void addStudent(const string& name) {
        students.push_back(name);
    }

    // Menghapus siswa dari daftar
    void removeStudent(const string& name) {
        auto it = find(students.begin(), students.end(), name);
        if (it != students.end()) {
            students.erase(it);
        }
    }

    // Menampilkan semua siswa dalam daftar
    void listStudents() const {
        cout << "Daftar Siswa:" << endl;
        for (const auto& student : students) {
            cout << "- " << student << endl;
        }
    }
};

int main() {
    StudentList myClass;  // Membuat objek StudentList

    myClass.addStudent("Ali");
    myClass.addStudent("Budi");
    myClass.addStudent("Citra");

    myClass.listStudents();  // Melihat isi daftar siswa

    myClass.removeStudent("Budi");
    myClass.listStudents();  // Melihat isi daftar siswa setelah menghapus Budi

    return 0;  // Mengembalikan 0 untuk menunjukkan program selesai dengan sukses
}
