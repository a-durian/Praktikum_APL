#include <iostream>
using namespace std;

int main(){

    // / Contoh deklarasi
    int bilangan[5]; // Array integer, 5 elemen
    string nama[4]; // Array string, 4 elemen
    float nilai[10]; // Array float, 10 elemen

    // / Deklarasi + Inisialisasi langsung
    string buah[4] = {"Jeruk", "Mangga", "Nanas", "Apel"};

    // / Deklarasi array tanpa inisialisasi elemen array
    int angka[3];
    angka[0] = 10;
    angka[1] = 19;
    angka[2] = 30;

    buah[4] = "Rambutan";
    for (int i = 0; i < 5; i++) {
        cout << buah[i] << endl;
    }

    if (panjang == 0) {
        cout << "Belum ada mahasiswa untuk diubah." << endl;
    } else {
    for (int i = 0; i < panjang; i++) {
        cout << "Mahasiswa ke-" << i + 1 << ": " << mahasiswa[i] << endl;
    }
    cout << "Masukkan nomor mahasiswa yang akan diubah: ";
    cin >> index;

    if (index > 0 && index <= panjang) {
        cout << "Masukkan nama baru: ";
        cin.ignore();
        getline(cin, mahasiswa[index - 1]);
        cout << "Data berhasil diubah." << endl;
    } else {
    cout << "Nomor tidak valid." << endl;
    }
    }

    int matriks[3][3] = {
        {1, 2, 3}, // Baris ke-0
        {4, 5, 6}, // Baris ke-1
        {7, 8, 9} // Baris ke-2
    };
    // // Mengakses elemen
    cout << matriks[0][1] << endl;
    cout << matriks[2][0] << endl;
    // Menampilkan seluruh matriks dengan nested loop
    for (int i = 0; i < 3; i++) { // Loop baris
        for (int j = 0; j < 3; j++) { // Loop kolom
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
    for (auto &baris : matriks) { // Iterasi setiap baris (array 1D)
        for (auto &elemen : baris) { // Iterasi setiap elemen dalam baris
            cout << elemen << " ";
        }
        cout << endl;
    }
}