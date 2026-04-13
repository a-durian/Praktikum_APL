// STUDI KASUS
// Mas Rehan seorang Ceo, ia memiliki perusahaan yang bergerak di bidang rumah
// tangga, saat ini ia sedang kebingungan untuk mengatur stok bahan di gudangnya
// saat ini Mas Rehan memiliki stok (dalam ton) :
// ● Beras (45)
// ● Jagung (60)
// ● Kentang (15)
// ● Singkong(20)
// Sekarang tolong bantu mas rehan untuk membuat:
// 1. Program sorting terbaik agar mampu memudahkan dia untuk mengatur stok dari
// yang paling sedikit

#include <iostream>
#include <string>
using namespace std;
 
struct Stok {
    string nama;
    int jumlah; // dalam ton
};

void insertionSort(Stok arr[], int n) {
    for (int i = 1; i < n; i++) {
        Stok key = arr[i];
        int j = i - 1;
 
        // menggeser elemen yang lebih besar dari key ke kanan
        while (j >= 0 && arr[j].jumlah > key.jumlah) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
 
        // menampilkan kondisi array setelah setiap langkah
        cout << "  Langkah " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k].nama << "(" << arr[k].jumlah << ")";
            if (k < n - 1) cout << " -> ";
        }
        cout << endl;
    }
}
 

void tampilkanStok(Stok arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "  " << arr[i].nama << "|" << arr[i].jumlah << endl;

    }
    cout << endl;
}

int main() {
 
        int n = 4;

    Stok stok[] = {
        {"Beras",   45},
        {"Jagung",  60},
        {"Kentang", 15},
        {"Singkong",20}
    };


 
    cout << ">>>   SISTEM MANAJEMEN STOK GUDANG    <<<" << endl;
    cout << ">>>       Perusahaan Mas Rehan        <<<" << endl;
 
    cout << "\n>> DATA AWAL (Belum Diurutkan) <<" << endl;
    tampilkanStok(stok, n);
 
    cout << "\n>> PROSES INSERTION SORT <<" << endl;
    insertionSort(stok, n);
 
    cout << "\n>> HASIL AKHIR (Diurutkan dari Terkecil) <<" << endl;
    tampilkanStok(stok, n);
 
    cout << "\n [^] Stok berhasil diurutkan dari yang paling sedikit!" << endl;
 
    return 0;
}