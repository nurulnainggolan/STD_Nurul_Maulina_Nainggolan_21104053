#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void menu() {
    cout << "Menu:" << endl;
    cout << "1. Masukkan data" << endl;
    cout << "2. Cari nilai maksimum" << endl;
    cout << "3. Cari nilai minimum" << endl;
    cout << "4. Cari nilai rata-rata" << endl;
    cout << "5. Keluar" << endl;
}

int main() {
    vector<double> data;
    int pilihan;

    while (true) {
        menu();
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        // Validasi pilihan menu
        if (cin.fail()) {
            cin.clear(); 
           
            cout << "Input tidak valid. Silakan coba lagi." << endl;
            continue;
        }

        switch (pilihan) {
            case 1: {
                int jumlah;
                cout << "Masukkan jumlah data yang ingin dimasukkan: ";
                cin >> jumlah;

                // Validasi input jumlah data
                if (cin.fail() || jumlah <= 0) {
                    cin.clear();
                    
                    cout << "Input tidak valid. Jumlah data harus positif." << endl;
                    continue;
                }

                data.clear(); // Mengosongkan data sebelumnya
                for (int i = 0; i < jumlah; ++i) {
                    double input;
                    cout << "Masukkan angka ke-" << (i + 1) << ": ";
                    cin >> input;

                    // Validasi input angka
                    if (cin.fail()) {
                        cin.clear();
                        
                        cout << "Input tidak valid. Harap masukkan angka." << endl;
                        --i; // Mengulangi iterasi untuk memasukkan angka yang benar
                        continue;
                    }

                    data.push_back(input);
                }
                cout << "Data telah dimasukkan." << endl;
                break;
            }
            case 2: {
                if (!data.empty()) {
                    double max_value = numeric_limits<double>::min();
                    for (double num : data) {
                        if (num > max_value) {
                            max_value = num;
                        }
                    }
                    cout << "Nilai maksimum: " << max_value << endl;
                } else {
                    cout << "Data masih kosong. Silakan masukkan data terlebih dahulu." << endl;
                }
                break;
            }
            case 3: {
                if (!data.empty()) {
                    double min_value = numeric_limits<double>::max();
                    for (double num : data) {
                        if (num < min_value) {
                            min_value = num;
                        }
                    }
                    cout << "Nilai minimum: " << min_value << endl;
                } else {
                    cout << "Data masih kosong. Silakan masukkan data terlebih dahulu." << endl;
                }
                break;
            }
            case 4: {
                if (!data.empty()) {
                    double sum = 0.0;
                    for (double num : data) {
                        sum += num;
                    }
                    double avg_value = sum / data.size();
                    cout << "Nilai rata-rata: " << avg_value << endl;
                } else {
                    cout << "Data masih kosong. Silakan masukkan data terlebih dahulu." << endl;
                }
                break;
            }
            case 5: {
                cout << "Keluar dari program." << endl;
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }
    }
    return 0;
}
