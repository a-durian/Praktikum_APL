#include <iostream>
using namespace std;

struct Alamat{
    string jalan;
    string kota;
    string provinsi;

};

struct Mahasiswa{
    int nim;
    string nama;
    float nilai;
    Alamat almt;
};

int main(){
    Mahasiswa mhs;

    mhs.almt.jalan = "Jl. Merdeka No. 123";
    mhs.almt.kota = "Bandung";
    mhs.almt.provinsi = "Jawa Barat";

    mhs.nim = 2509106032;
    mhs.nama = "Muhammad Adrian";
    mhs.nilai = 85.5;

    cout << "NIM: " << mhs.nim << endl;
    cout << "Nama: " << mhs.nama << endl;
    cout << "Nilai: " << mhs.nilai << endl;

    cout << endl;
    cout << "Jalan: " << mhs.almt.jalan << endl;
    cout << "Kota: " << mhs.almt.kota << endl;
    cout << "Provinsi: " << mhs.almt.provinsi << endl;



    return 0;
};