#include <iostream>
using namespace std;
// JUDUL: Minecraft Villager Trading Hall

struct Akun {
    string username;
    string password;
};

struct Trade {
    string item_diberi;
    int qty_diberi;
    string item_terima;
    int qty_terima;
};

struct Villager {
    string nama;
    string profesi;
    Trade trades[5]; // Maksimal 5 opsi trade
    int num_trade;
};

struct Inventory {
    string item;
    int jumlah;
};

int main(){
    const int MAX_AKUN = 10; // Maksimal 10 akun
    Akun daftarAkun[MAX_AKUN];
    int jumlahAkun = 2; 

    const int MAX_VILLAGER = 10; // Maksimal 10 villager
    Villager villagers[MAX_VILLAGER];
    int jumlah_villager = 3; 

    const int MAX_INVENTORY = 32; // Maksimal 32 item inventory
    Inventory inventory[MAX_INVENTORY];
    int jumlah_inventory = 6; // Mulai dengan 6 item contoh 

    // Contoh akun
    daftarAkun[0] = {"Adrian", "032"}; // Contoh akun admin
    daftarAkun[1] = {"User1", "123"}; // Contoh akun user

    // Contoh villager
    villagers[0].nama = "Asep";
    villagers[0].profesi = "Farmer";
    villagers[0].trades[0].item_diberi = "Wheat";
    villagers[0].trades[0].qty_diberi = 1;
    villagers[0].trades[0].item_terima = "Emerald";
    villagers[0].trades[0].qty_terima = 1;
    villagers[0].trades[1].item_diberi = "Carrot";
    villagers[0].trades[1].qty_diberi = 4;
    villagers[0].trades[1].item_terima = "Emerald";
    villagers[0].trades[1].qty_terima = 1;
    villagers[0].trades[2].item_diberi = "Emerald";
    villagers[0].trades[2].qty_diberi = 1;
    villagers[0].trades[2].item_terima = "Bread";
    villagers[0].trades[2].qty_terima = 8;
    villagers[0].num_trade = 3;

    villagers[1].nama = "Durian";
    villagers[1].profesi = "Librarian";
    villagers[1].trades[0].item_diberi = "Book";
    villagers[1].trades[0].qty_diberi = 1;
    villagers[1].trades[0].item_terima = "Emerald";
    villagers[1].trades[0].qty_terima = 2;
    villagers[1].trades[1].item_diberi = "Paper";
    villagers[1].trades[1].qty_diberi = 10;
    villagers[1].trades[1].item_terima = "Emerald";
    villagers[1].trades[1].qty_terima = 1;
    villagers[1].trades[2].item_diberi = "Emerald";
    villagers[1].trades[2].qty_diberi = 5;
    villagers[1].trades[2].item_terima = "Enchanted Book of Mending";
    villagers[1].trades[2].qty_terima = 1;
    villagers[1].num_trade = 3;

    villagers[2].nama = "Budi";
    villagers[2].profesi = "Blacksmith";
    villagers[2].trades[0].item_diberi = "Iron";
    villagers[2].trades[0].qty_diberi = 8;
    villagers[2].trades[0].item_terima = "Emerald";
    villagers[2].trades[0].qty_terima = 1;
    villagers[2].trades[1].item_diberi = "Coal";
    villagers[2].trades[1].qty_diberi = 16;
    villagers[2].trades[1].item_terima = "Emerald";
    villagers[2].trades[1].qty_terima = 1;
    villagers[2].trades[2].item_diberi = "Emerald";
    villagers[2].trades[2].qty_diberi = 4;
    villagers[2].trades[2].item_terima = "Diamond Pickaxe";
    villagers[2].trades[2].qty_terima = 1;
    villagers[2].num_trade = 3;

    // Contoh inventory
    inventory[0] = {"Emerald", 10};
    inventory[1] = {"Wheat", 64};
    inventory[2] = {"Iron", 6};
    inventory[3] = {"Coal", 37};
    inventory[4] = {"Paper", 46};
    inventory[5] = {"Book", 12};

    string username, password, yorn, username_baru, password_baru;
    int menu_multiuser, vill_survival_trade, kesempatan = 3;

    cout << endl << "Apakah anda sudah punya akun?[y/n]: " << endl;
    cin >> yorn;
    if (yorn == "y" || yorn == "Y"){
        cout << "Silahkan login terlebih dahulu" << endl;
        
        while (kesempatan > 0) {
            cout << "Masukkan Username: ";
            cin >> username;
            cout << "Masukkan Password: ";
            cin >> password;

            bool loginBerhasil = false;
            for(int i = 0; i < jumlahAkun; i++){
                if(username == daftarAkun[i].username && password == daftarAkun[i].password){
                    loginBerhasil = true;
                    if (username == "Adrian" && password == "032"){ // INI ADMIN ATAU MODE CREATIVE
                        cout << "Mode Creative aktif!" << endl;
                        // DISINI MASUK KE MENU CRUD ADMIN
                        int pilihan_menu_admin;
                        do {
                            cout << "Menu mode Creative:" << endl;
                            cout << "1. Lihat daftar Villager" << endl;
                            cout << "2. Tambah Villager" << endl;
                            cout << "3. Hapus Villager" << endl;
                            cout << "4. Manajemen Trade" << endl;
                            cout << "5. Keluar" << endl;
                            cout << "Pilihan: ";
                            cin >> pilihan_menu_admin;

                            switch (pilihan_menu_admin) {
                                case 1:
                                    if (jumlah_villager > 0) {
                                        cout << "Daftar Villager:" << endl;
                                        for(int i = 0; i < jumlah_villager; i++){
                                            cout << i+1 << ". Nama: " << villagers[i].nama << ", Profesi: " << villagers[i].profesi << endl;
                                            cout << "   Trades:" << endl;
                                            for(int j = 0; j < villagers[i].num_trade; j++){
                                                cout << "   " << j+1 << ". "
                                                     << villagers[i].trades[j].qty_diberi<< "x "
                                                     << villagers[i].trades[j].item_diberi << " for "
                                                     << villagers[i].trades[j].qty_terima << "x "
                                                     << villagers[i].trades[j].item_terima << endl;
                                            }
                                        }
                                    } else {
                                        cout << "Tidak ada Villager yang tersedia." << endl;
                                    }
                                    break;
                                case 2:
                                    if (jumlah_villager < MAX_VILLAGER) {
                                        string nama_baru, profesi_baru, trade_baru;
                                        cout << "Masukkan nama villager baru: ";
                                        cin.ignore();
                                        getline(cin, nama_baru);
                                        cout << "Masukkan profesi villager: ";
                                        getline(cin, profesi_baru);
                                        
                                        villagers[jumlah_villager].nama = nama_baru;
                                        villagers[jumlah_villager].profesi = profesi_baru;
                                        villagers[jumlah_villager].num_trade = 0;
                                        
                                        int jumlah_trade_baru;
                                        cout << "Berapa trades awal yang ingin ditambahkan (1-5)? ";
                                        cin >> jumlah_trade_baru;
                                        
                                        if (jumlah_trade_baru > 0 && jumlah_trade_baru <= 5) {
                                            for(int t = 0; t < jumlah_trade_baru; t++) {
                                                cout << "Masukkan trade " << t+1 << ": ";
                                                int qty_diberikan, qty_diterima
                                                ;
                                                string beri_item, terima_item;
                                                cout << "Masukkan qty barang yang diberikan: ";
                                                cin >> qty_diberikan;
                                                cin.ignore();
                                                cout << "Masukkan nama barang yang diberikan: ";
                                                getline(cin, beri_item);
                                                cout << "Masukkan qty barang yang diterima: ";
                                                cin >> qty_diterima
                                                ;
                                                cin.ignore();
                                                cout << "Masukkan nama barang yang diterima: ";
                                                getline(cin, terima_item);
                                                villagers[jumlah_villager].trades[t].qty_diberi = qty_diberikan;
                                                villagers[jumlah_villager].trades[t].item_diberi = beri_item;
                                                villagers[jumlah_villager].trades[t].qty_terima = qty_diterima
                                                ;
                                                villagers[jumlah_villager].trades[t].item_terima = terima_item;
                                            }
                                            villagers[jumlah_villager].num_trade = jumlah_trade_baru;
                                        } else {
                                            cout << "Jumlah trade tidak valid. Villager ditambahkan tanpa trade." << endl;
                                        }
                                        
                                        jumlah_villager++;
                                        cout << "Villager baru berhasil ditambahkan!" << endl;
                                    } else {
                                        cout << "Maksimal " << MAX_VILLAGER << " villagers sudah tercapai." << endl;
                                    }
                                    break;
                                case 3:
                                    if (jumlah_villager > 0) {
                                        cout << "Masukkan nomor villager yang ingin dihapus (1-" << jumlah_villager << "): ";
                                        int index;
                                        cin >> index;
                                        if (index >= 1 && index <= jumlah_villager) {
                                            for(int i = index-1; i < jumlah_villager-1; i++){
                                                villagers[i] = villagers[i+1];
                                            }
                                            jumlah_villager--;
                                            cout << "Villager berhasil dihapus." << endl;
                                        } else {
                                            cout << "Nomor villager tidak valid." << endl;
                                        }
                                    } else {
                                        cout << "Tidak ada Villager yang tersedia untuk dihapus." << endl;
                                    }
                                    break;
                                case 4:
                                    if (jumlah_villager > 0) {
                                        cout << "Pilih nomor villager untuk di-manage trades (1-" << jumlah_villager << "): ";
                                        int vill_index;
                                        cin >> vill_index;
                                        if (vill_index >= 1 && vill_index <= jumlah_villager) {
                                            int pilihan_trade;
                                            do {
                                                cout << "Manage Trades untuk " << villagers[vill_index-1].nama << ":" << endl;
                                                cout << "1. Tambah Trade" << endl;
                                                cout << "2. Edit Trade" << endl;
                                                cout << "3. Hapus Trade" << endl;
                                                cout << "4. Kembali" << endl;
                                                cout << "Pilihan: ";
                                                cin >> pilihan_trade;
                                                switch (pilihan_trade) {
                                                    case 1:
                                                        if (villagers[vill_index-1].num_trade < 5) {
                                                            int beri_q, terima_q;
                                                            string beri_item, terima_item;
                                                            cout << "Masukkan qty barang yang diberikan: ";
                                                            cin >> beri_q;
                                                            cin.ignore();
                                                            cout << "Masukkan nama barang yang diberikan: ";
                                                            getline(cin, beri_item);
                                                            cout << "Masukkan qty barang yang diterima: ";
                                                            cin >> terima_q;
                                                            cin.ignore();
                                                            cout << "Masukkan nama barang yang diterima: ";
                                                            getline(cin, terima_item);
                                                            villagers[vill_index-1].trades[villagers[vill_index-1].num_trade].qty_diberi = beri_q;
                                                            villagers[vill_index-1].trades[villagers[vill_index-1].num_trade].item_diberi = beri_item;
                                                            villagers[vill_index-1].trades[villagers[vill_index-1].num_trade].qty_terima = terima_q;
                                                            villagers[vill_index-1].trades[villagers[vill_index-1].num_trade].item_terima = terima_item;
                                                            villagers[vill_index-1].num_trade++;
                                                            cout << "Trade berhasil ditambahkan." << endl;
                                                        } else {
                                                            cout << "Maksimal 5 trades per villager." << endl;
                                                        }
                                                        break;
                                                    case 2:
                                                        if (villagers[vill_index-1].num_trade > 0) {
                                                            cout << "Pilih nomor trade untuk edit (1-" << villagers[vill_index-1].num_trade << "): ";
                                                            int trade_id;
                                                            cin >> trade_id;
                                                            if (trade_id >= 1 && trade_id <= villagers[vill_index-1].num_trade) {
                                                                int beri_q, terima_q;
                                                                string beri_item, terima_item;
                                                                cout << "Masukkan qty barang yang diberikan: ";
                                                                cin >> beri_q;
                                                                cin.ignore();
                                                                cout << "Masukkan nama barang yang diberikan: ";
                                                                getline(cin, beri_item);
                                                                cout << "Masukkan qty barang yang diterima: ";
                                                                cin >> terima_q;
                                                                cin.ignore();
                                                                cout << "Masukkan nama barang yang diterima: ";
                                                                getline(cin, terima_item);
                                                                villagers[vill_index-1].trades[trade_id-1].qty_diberi = beri_q;
                                                                villagers[vill_index-1].trades[trade_id-1].item_diberi = beri_item;
                                                                villagers[vill_index-1].trades[trade_id-1].qty_terima = terima_q;
                                                                villagers[vill_index-1].trades[trade_id-1].item_terima = terima_item;
                                                                cout << "Trade berhasil diubah." << endl;
                                                            } else {
                                                                cout << "Nomor trade tidak valid." << endl;
                                                            }
                                                        } else {
                                                            cout << "Tidak ada trade untuk diedit." << endl;
                                                        }
                                                        break;
                                                    case 3:
                                                        if (villagers[vill_index-1].num_trade > 0) {
                                                            cout << "Pilih nomor trade untuk hapus [1-" << villagers[vill_index-1].num_trade << "]: ";
                                                            int trade_id;
                                                            cin >> trade_id;
                                                            if (trade_id >= 1 && trade_id <= villagers[vill_index-1].num_trade) {
                                                                for(int k = trade_id-1; k < villagers[vill_index-1].num_trade-1; k++){
                                                                    villagers[vill_index-1].trades[k] = villagers[vill_index-1].trades[k+1];
                                                                }
                                                                villagers[vill_index-1].num_trade--;
                                                                cout << "Trade berhasil dihapus." << endl;
                                                            } else {
                                                                cout << "Nomor trade tidak valid." << endl;
                                                            }
                                                        } else {
                                                            cout << "Tidak ada trade untuk dihapus." << endl;
                                                        }
                                                        break;
                                                    case 4:
                                                        cout << "Kembali ke menu admin." << endl;
                                                        break;
                                                    default:
                                                        cout << "Pilihan tidak valid." << endl;
                                                }
                                            } while (pilihan_trade != 4);
                                        } else {
                                            cout << "Nomor villager tidak valid." << endl;
                                        }
                                    } else {
                                        cout << "Tidak ada Villager untuk manage trades." << endl;
                                    }
                                    break;
                                case 5:
                                    cout << "Keluar dari menu Admin." << endl;
                                    break;
                                default:
                                    cout << "Pilihan tidak valid. Silahkan coba lagi." << endl;
                            }
                        } while(pilihan_menu_admin != 5);
                        
                    } else { // INI USER BIASA ATAU MODE SURVIVAL
                        // DISINI MASUK KE MENU CRUD USER
                        int pilihan_menu_user;

                        do {
                            cout << "Anda masuk dalam mode Survival" << endl;
                            cout << "1. Tampilkan daftar Villager" << endl;
                            cout << "2. Lihat Inventory" << endl;
                            cout << "3. Keluar" << endl;
                            cout << "Pilihan: ";
                            cin >> pilihan_menu_user;

                            switch (pilihan_menu_user) {
                                case 1:
                                    if (jumlah_villager > 0) {
                                        cout << "Menampilkan daftar Villager..." << endl;
                                        for(int i = 0; i < jumlah_villager; i++){
                                            cout << i+1 << ". Nama: " << villagers[i].nama << ", Profesi: " << villagers[i].profesi << endl;
                                            cout << "   Trades:" << endl;
                                            for(int j = 0; j < villagers[i].num_trade; j++){
                                                cout << "   " << j+1 << ". "
                                                     << villagers[i].trades[j].qty_diberi << "x "
                                                     << villagers[i].trades[j].item_diberi << " for "
                                                     << villagers[i].trades[j].qty_terima << "x "
                                                     << villagers[i].trades[j].item_terima << endl;
                                            }
                                        }
                                        cout << "Pilih Villager untuk melakukan trade [1-" << jumlah_villager << " atau 0 untuk kembali]: ";
                                        cin >> vill_survival_trade;
                                        if (vill_survival_trade >= 1 && vill_survival_trade <= jumlah_villager) {
                                            cout << "Anda memilih Villager: " << villagers[vill_survival_trade-1].nama << endl;
                                            cout << "Trades yang tersedia:" << endl;
                                            for(int t = 0; t < villagers[vill_survival_trade-1].num_trade; t++){
                                                auto &tr = villagers[vill_survival_trade-1].trades[t];
                                                cout << "   " << t+1 << ". "
                                                     << tr.qty_diberi << "x " << tr.item_diberi
                                                     << " for " << tr.qty_terima << "x " << tr.item_terima << endl;
                                            }
                                            // trade selection
                                            int pilihan_trade;
                                            cout << "Pilih trade yang ingin dilakukan (1-" << villagers[vill_survival_trade-1].num_trade << "): ";
                                            cin >> pilihan_trade;
                                            if(pilihan_trade >= 1 && pilihan_trade <= villagers[vill_survival_trade-1].num_trade){
                                                Trade &tr = villagers[vill_survival_trade-1].trades[pilihan_trade-1];
                                                // check inventory for give item
                                                int idxGive = -1, idxRecv = -1;
                                                for(int k=0;k<jumlah_inventory;k++){
                                                    if(inventory[k].item == tr.item_diberi) idxGive = k;
                                                    if(inventory[k].item == tr.item_terima) idxRecv = k;
                                                }
                                                if(idxGive != -1 && inventory[idxGive].jumlah >= tr.qty_diberi){
                                                    inventory[idxGive].jumlah -= tr.qty_diberi;
                                                    if(idxRecv != -1){
                                                        inventory[idxRecv].jumlah += tr.qty_terima;
                                                    } else if(jumlah_inventory < MAX_INVENTORY){
                                                        inventory[jumlah_inventory].item = tr.item_terima;
                                                        inventory[jumlah_inventory].jumlah = tr.qty_terima;
                                                        jumlah_inventory++;
                                                    }
                                                    cout << "Trade sukses: " << tr.qty_diberi << "x " << tr.item_diberi
                                                         << " ditukar menjadi " << tr.qty_terima << "x " << tr.item_terima << "\n";
                                                } else {
                                                    cout << "Anda tidak punya cukup " << tr.item_diberi << " untuk melakukan trade." << endl;
                                                }
                                            } else {
                                                cout << "Pilihan trade tidak valid." << endl;
                                            }
                                        } else if (vill_survival_trade == 0) {
                                            cout << "Kembali ke menu utama." << endl;
                                        } else {
                                            cout << "Pilihan tidak valid." << endl;
                                        }
                                    } else {
                                        cout << "Tidak ada Villager yang tersedia." << endl;
                                    }
                                    break;
                                case 2:
                                    cout << "Menampilkan Inventory..." << endl;
                                    if (jumlah_inventory > 0) {
                                        cout << "Inventory Anda:" << endl;
                                        for(int i = 0; i < jumlah_inventory; i++){
                                            cout << i+1 << ". " << inventory[i].item << " - Jumlah: " << inventory[i].jumlah << endl;
                                        }
                                    } else {
                                        cout << "Inventory kosong." << endl;
                                    }
                                    break;
                                case 3:
                                    cout << "Keluar dari menu Survival." << endl;
                                    break;
                                default:
                                    cout << "Pilihan tidak valid. Silahkan coba lagi." << endl;
                            }
                        } while(pilihan_menu_user != 3);
                    }
                    break;
                }
            }
            if(loginBerhasil){
                break;
            } else {
                cout << "Username atau Password salah! Kesempatan tersisa: " << kesempatan-1 << endl;
                kesempatan--;
            }
        }
        if(kesempatan == 0){
            cout << "Kesempatan login habis. Program dihentikan." << endl;
        }  
    }else if (yorn == "n" || yorn == "N"){
        if(jumlahAkun < MAX_AKUN){
            cout << "Silahkan buat akun dengan memasukkan username dan password yang anda inginkan:" << endl;
            cout << "Masukkan Username: ";
            cin >> username_baru;
            cout << "Masukkan Password: ";
            cin >> password_baru;

            // Simpan ke array
            daftarAkun[jumlahAkun].username = username_baru;
            daftarAkun[jumlahAkun].password = password_baru;
            jumlahAkun++;

            cout << "Akun berhasil dibuat! Silahkan login." << endl;
            // Sekarang bisa lanjut ke login atau langsung masuk
            // langsung masuk sebagai user baru
            cout << "Selamat datang, " << username_baru << "! Anda masuk sebagai user biasa." << endl;
            // DISINI MASUK KE MENU CRUD USER
        } else {
            cout << "Maksimal akun sudah tercapai. Tidak bisa register lagi." << endl;
        }
    } else {
        cout << "Input salah, program dihentikan secara paksa !" << endl;
    }
}