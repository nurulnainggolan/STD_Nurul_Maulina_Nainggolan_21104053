#include <iostream>
#include <cmath>
using namespace std;

class Cone {
private:
    double radius; // Jari-jari alas kerucut
    double height; // Tinggi kerucut

public:
    // Konstruktor
    Cone(double r, double h) : radius(r), height(h) {}

    // Menghitung volume kerucut
    double calculateVolume() const {
        return (1.0 / 3.0) * M_PI * pow(radius, 2) * height;
    }

    // Menghitung luas permukaan kerucut
    double calculateSurfaceArea() const {
        double slantHeight = sqrt(pow(radius, 2) + pow(height, 2)); // Menghitung tinggi miring
        return M_PI * radius * (radius + slantHeight); // Luas permukaan
    }
};

int main() {
    // Membuat objek kerucut dengan radius 3 dan tinggi 5
    Cone myCone(3.0, 5.0);

    // Menampilkan hasil perhitungan
    cout << "Volume Kerucut: " << myCone.calculateVolume() << endl;
    cout << "Luas Permukaan Kerucut: " << myCone.calculateSurfaceArea() << endl;

    return 0; // Mengembalikan 0 untuk menunjukkan program selesai
}
