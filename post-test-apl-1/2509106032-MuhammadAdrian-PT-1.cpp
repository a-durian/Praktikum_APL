#include <iostream>
using namespace std;

int main(){
    string nama, nim;
    int menu, kesempatan = 3;
    double meter, kilometer, centimeter;

    cout << endl << ">>>>> Silahkan login terlebih dahulu <<<<<" << endl;

    while (kesempatan > 0 && true){
        cout << "> Masukkan nama: "; cin >> nama;
        cout << "> Masukkan NIM 3 digit terakhir: "; cin >> nim;

        if ((nama == "Adrian" || nama == "adrian") && nim == "032"){
            cout << endl;
            cout << ">>>=============================================================================================<<<" << endl;
            cout << ">>> Login berhasil! Selamat datang di program konversi panjang Meter, Centimeter dan Kilometer! <<<" << endl;
            cout << ">>>=============================================================================================<<<" << endl;
            
            while (true) {
                cout << endl << "           >>> Menu Konversi: <<<" << endl;
                cout << "1. Konversi Meter -> Kilometer dan Centimeter"<< endl;
                cout << "2. Konversi Kilometer -> Meter dan Centimeter" << endl;
                cout << "3. Konversi Centimeter -> Meter dan Kilometer"<< endl;
                cout << "4. Keluar" << endl;
                cout << endl << "> Silahkan input nomor yang tersedia di menu [1/2/3/4]: ";
                cin >> menu;

                if (menu == 1) {
                    cout <<endl << "===== Konversi Meter -> Kilometer dan Centimeter =====" << endl << endl;
                    cout << "> Silahkan input berapa Meter yang akan di konversi: ";
                    cin >> meter;
                    double m_to_km = meter / 1000;
                    int m_to_cm = meter * 100;

                    cout << "^ Konversi dari input anda (" << meter << "m) -> " << m_to_km << "km dan " << m_to_cm << "cm" << endl;
                    cout << "~ Kembali ke menu.." << endl;

                } else if (menu == 2) {
                    cout << endl << "===== Konversi Kilometer -> Meter dan Centimeter =====" << endl;
                    cout << "> Silahkan input berapa Kilometer yang akan di konversi: ";
                    cin >> kilometer;
                    int km_to_m = kilometer * 1000;
                    int km_to_cm = kilometer * 100000;

                    cout << "^ Konversi dari input anda (" << kilometer << "km) -> " << km_to_m << "m dan " << km_to_cm << "cm"<< endl;
                    cout << "~ Kembali ke menu.." << endl;

                } else if (menu == 3) {
                    cout << endl << "===== Konversi Centimeter -> Meter dan Kilometer =====" << endl;
                    cout << "> Silahkan input berapa Centimeter yang akan di konversi: "; 
                    cin >> centimeter;
                    double cm_to_m = centimeter / 100;
                    double cm_to_km = centimeter / 100000;

                    cout << "^ Konversi dari input anda (" << centimeter << "cm) -> " << cm_to_m << "m dan " << cm_to_km << "km" << endl;
                    cout << "~ Kembali ke menu.." << endl;

                } else if (menu == 4) {
                    cout << "! Anda memilih untuk keluar dari program !" << endl;
                    cout << "! Program dihentikan !" << endl;
                    break;

                } else {
                    cout << endl << "!! Input gagal. Program dihentikan. !!" << endl;
                    break;
                }
            }
        break;
        } else {
            kesempatan--;
            if (kesempatan > 0) {
                cout << "!! Login gagal, pastikan nama atau NIM benar. Silahkan coba lagi. !!" << endl;
                cout << "! Kesempatan tersisa: " << kesempatan << endl;
            } else {
                cout << "!! Login gagal, kesempatan habis. Silahkan coba lagi nanti. !!" << endl;
            }
        }
    }
    return 0;
}