#include <iostream>
#include <cmath>
using namespace std;

struct Akun {
    string username;
    string password;
};

struct Trade {
    string item_diberi;
    int jumlah_diberi;
    string item_terima;
    int jumlah_terima;
};

struct Villager {
    string nama;
    string profesi;
    Trade trades[5]; 
    int num_trade;
};

struct Inventory {
    string item;
    int jumlah;
};

const int MAX_AKUN = 5;
Akun daftar_akun[MAX_AKUN];
int jumlah_akun;

const int MAX_VILLAGER = 10;
Villager villagers[MAX_VILLAGER];
int jumlah_villager;

const int MAX_INVENTORY = 32;
Inventory inventory[MAX_INVENTORY];
int jumlah_inventory;

string username, password, yorn, username_baru, password_baru;
int menu_multiuser, vill_survival_trade;

void dataVillager(int &jml_akun, int &jml_villager, int &jml_inventory){
    jml_akun = 2; 
    jml_villager = 3; 
    jml_inventory = 6; 

    daftar_akun[0] = {"Adrian", "032"}; //akun admin
    daftar_akun[1] = {"Duriann", "67"}; // akun user

    villagers[0].nama = "Asep";
    villagers[0].profesi = "Farmer";
    villagers[0].trades[0].item_diberi = "Wheat";
    villagers[0].trades[0].jumlah_diberi = 24;
    villagers[0].trades[0].item_terima = "Emerald";
    villagers[0].trades[0].jumlah_terima = 1;
    villagers[0].trades[1].item_diberi = "Carrot";
    villagers[0].trades[1].jumlah_diberi = 12;
    villagers[0].trades[1].item_terima = "Emerald";
    villagers[0].trades[1].jumlah_terima = 1;
    villagers[0].trades[2].item_diberi = "Emerald";
    villagers[0].trades[2].jumlah_diberi = 1;
    villagers[0].trades[2].item_terima = "Bread";
    villagers[0].trades[2].jumlah_terima = 4;
    villagers[0].num_trade = 3;

    villagers[1].nama = "Hayes";
    villagers[1].profesi = "Librarian";
    villagers[1].trades[0].item_diberi = "Book";
    villagers[1].trades[0].jumlah_diberi = 17;
    villagers[1].trades[0].item_terima = "Emerald";
    villagers[1].trades[0].jumlah_terima = 2;
    villagers[1].trades[1].item_diberi = "Paper";
    villagers[1].trades[1].jumlah_diberi = 10;
    villagers[1].trades[1].item_terima = "Emerald";
    villagers[1].trades[1].jumlah_terima = 1;
    villagers[1].trades[2].item_diberi = "Emerald";
    villagers[1].trades[2].jumlah_diberi = 67;
    villagers[1].trades[2].item_terima = "Enchanted Book of Mending";
    villagers[1].trades[2].jumlah_terima = 1;
    villagers[1].num_trade = 3;

    villagers[2].nama = "Budi";
    villagers[2].profesi = "Blacksmith";
    villagers[2].trades[0].item_diberi = "Iron";
    villagers[2].trades[0].jumlah_diberi = 8;
    villagers[2].trades[0].item_terima = "Emerald";
    villagers[2].trades[0].jumlah_terima = 1;
    villagers[2].trades[1].item_diberi = "Coal";
    villagers[2].trades[1].jumlah_diberi = 16;
    villagers[2].trades[1].item_terima = "Emerald";
    villagers[2].trades[1].jumlah_terima = 1;
    villagers[2].trades[2].item_diberi = "Emerald";
    villagers[2].trades[2].jumlah_diberi = 67;
    villagers[2].trades[2].item_terima = "Diamond Pickaxe";
    villagers[2].trades[2].jumlah_terima = 1;
    villagers[2].num_trade = 3;

    inventory[0] = {"Emerald", 10};
    inventory[1] = {"Wheat", 64};
    inventory[2] = {"Iron", 6};
    inventory[3] = {"Coal", 37};
    inventory[4] = {"Paper", 46};
    inventory[5] = {"Book", 12};
}

void urutkanNama(Villager arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].nama > arr[j+1].nama) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void urutkanTrade(Villager arr[], int n) {
    // loop tiap villager
    for (int v = 0; v < n; v++) {
        // bubble sort trades[] milik villager ke-v
        for (int i = 0; i < arr[v].num_trade - 1; i++) {
            for (int j = 0; j < arr[v].num_trade - i - 1; j++) {
                if (arr[v].trades[j].jumlah_diberi < arr[v].trades[j+1].jumlah_diberi) {
                    swap(arr[v].trades[j], arr[v].trades[j+1]);
                }
            }
        }
    }
}

void urutkanProfesi(Villager arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].profesi > arr[j+1].profesi) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// NEWWWWW NEWWW
void linearSearchNama(Villager* arr, int* n) {
    string keyword;
    cout << " [>] Masukkan nama Villager yang dicari: ";
    cin.ignore();
    getline(cin, keyword);
 
    bool ditemukan = false;
    for (int i = 0; i < *n; i++) { // melakukan iterasi satu per satu dari awal
        if (arr[i].nama == keyword) {// bandingkan nama dengan keywordnya
            cout << " [^] Villager ditemukan di index ke-" << i << "!" << endl;
            cout << "     Nama    : " << arr[i].nama << endl;
            cout << "     Profesi : " << arr[i].profesi << endl;
            cout << "     Trades  :" << endl;
            for (int j = 0; j < arr[i].num_trade; j++) {
                cout << "       " << j+1 << ". "
                     << arr[i].trades[j].jumlah_diberi << "x " << arr[i].trades[j].item_diberi
                     << " for "
                     << arr[i].trades[j].jumlah_terima << "x " << arr[i].trades[j].item_terima << endl;
            }
            ditemukan = true;
            break; // berhenti setelah ditemukan pertama kali
        }
    }
    if (!ditemukan) {
        cout << " [!] Villager dengan nama \"" << keyword << "\" tidak ditemukan." << endl;
    }
}

void jumpSearchJumlah(Inventory* arr, int* n) {
    int target;
    cout << " [>] Masukkan jumlah item inventory yang dicari: ";
    cin >> target;
 
    // menguruutkan sementara salinan inventory berdasarkan jumlah (syarat Jump Search)
    Inventory temp[MAX_INVENTORY];
    for (int i = 0; i < *n; i++) temp[i] = arr[i];// menyalin ke array sementara
    for (int i = 0; i < *n - 1; i++) { // bubble sort ascending
        for (int j = 0; j < *n - i - 1; j++) {
            if (temp[j].jumlah > temp[j+1].jumlah) swap(temp[j], temp[j+1]);
        }
    }
 
    //proses Jump search pada array sementara yang sudah terurut
    int step = (int)sqrt((double)*n);  // ukuran lompatan = sqrt(n)
    int prev = 0;
 
    //  selama blok < target, lompat per blok
    while (temp[min(step, *n) - 1].jumlah < target) {
        prev = step;
        step += (int)sqrt((double)*n);
        if (prev >= *n) { // sudah batas array woy
            cout << " [!] Item dengan jumlah " << target << " tidak ditemukan." << endl;
            return;
        }
    }
 
    //Linear search di dalam blok yang ditemukan
    bool ditemukan = false;
    while (temp[prev].jumlah <= target && prev < *n) {
        if (temp[prev].jumlah == target) { 
            cout << " [^] Item ditemukan: " << temp[prev].item
                 << " - Jumlah: " << temp[prev].jumlah << endl;
            ditemukan = true;
        }
        prev++;
    }
    if (!ditemukan) {
        cout << " [!] Item dengan jumlah " << target << " tidak ditemukan." << endl;
    }
}

void menuSearching() {
    int pilihan_search;
    do {
        cout << endl;
        cout << ">>>==========================================<<<" << endl;
        cout << ">>>            MENU SEARCHING                <<<" << endl;
        cout << ">>>==========================================<<<" << endl;
        cout << "||| 1. Cari Villager by Nama                 |||" << endl;
        cout << "||| 2. Cari Inventory by Jumlah              |||" << endl;
        cout << "||| 0. Kembali                               |||" << endl;
        cout << ">>>==========================================<<<" << endl;
        cout << " [>] Pilihan: "; cin >> pilihan_search;
 
        switch (pilihan_search) {
        case 1:
            linearSearchNama(villagers, &jumlah_villager);
            break;
        case 2:
            jumpSearchJumlah(inventory, &jumlah_inventory);
            break;
        case 0:
            cout << " [^] Kembali ke menu sebelumnya.." << endl;
            break;
        default:
            cout << " [!] Pilihan tidak valid." << endl;
        }
    } while (pilihan_search != 0);
}

void menuTrade(){
    int vill_index;
    if (jumlah_villager > 0) {
        cout << " [>] Pilih nomor villager untuk di-manage trades [1-" << jumlah_villager << "]: ";
        try {
            cin >> vill_index;
            if (cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                throw runtime_error(" [!] Input tidak valid. Kembali ke menu sebelumnya. ");
            }
            if (vill_index >= 1 && vill_index <= jumlah_villager) {
                int pilihan_trade;
                do {
                    cout << endl;
                    cout << ">>>========================================<<<" << endl;
                    cout << ">>> Manage Trades untuk " << villagers[vill_index-1].nama << ": <<<" << endl;
                    cout << ">>>========================================<<<" << endl;
                    cout << "||| 1. Tambah Trade                        <<<" << endl;
                    cout << "||| 2. Edit Trade                          <<<" << endl;
                    cout << "||| 3. Hapus Trade                         <<<" << endl;
                    cout << "||| 4. Kembali                             <<<" << endl;
                    cout << ">>>========================================<<<" << endl;
                    cout << " [>] Pilihan: "; cin >> pilihan_trade;
                    switch (pilihan_trade) {
                    case 1:
                        if (villagers[vill_index-1].num_trade < 5) { 
                            int beri_jmlh, terima_q;
                            string beri_item, terima_item;
                            cout << " [>] Masukkan jumlah barang yang diberikan: "; cin >> beri_jmlh; cin.ignore();
                            cout << " [>] Masukkan nama barang yang diberikan: "; getline(cin, beri_item);
                            cout << " [>] Masukkan jumlah barang yang diterima: "; cin >> terima_q; cin.ignore();
                            cout << " [>] Masukkan nama barang yang diterima: "; getline(cin, terima_item);
                            
                            villagers[vill_index-1].trades[villagers[vill_index-1].num_trade].jumlah_diberi = beri_jmlh;
                            villagers[vill_index-1].trades[villagers[vill_index-1].num_trade].item_diberi = beri_item;
                            villagers[vill_index-1].trades[villagers[vill_index-1].num_trade].jumlah_terima = terima_q;
                            villagers[vill_index-1].trades[villagers[vill_index-1].num_trade].item_terima = terima_item;
                            villagers[vill_index-1].num_trade++;
                            cout << " [^] Trade berhasil ditambahkan." << endl;
                        } else {
                            cout << " [!] Maksimal 5 trades per villager." << endl;
                        }
                        break;
                    case 2:
                        if (villagers[vill_index-1].num_trade > 0) {
                            cout << "> Pilih nomor trade untuk edit [1-" << villagers[vill_index-1].num_trade << "]: ";
                            int trade_id;
                            try {
                                cin >> trade_id;
                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(1000, '\n');
                                    throw runtime_error(" [!] Input tidak valid. kembali ke menu sebelumya..");
                                }
                                if (trade_id >= 1 && trade_id <= villagers[vill_index-1].num_trade) {
                                    int beri_jmlh, terima_q;
                                    string beri_item, terima_item;
                                    cout << " [>] Masukkan jumlah barang yang diberikan: ";cin >> beri_jmlh;cin.ignore();
                                    cout << " [>] Masukkan nama barang yang diberikan: ";getline(cin, beri_item);
                                    cout << " [>] Masukkan jumlah barang yang diterima: ";cin >> terima_q;cin.ignore();
                                    cout << " [>] Masukkan nama barang yang diterima: ";getline(cin, terima_item);
                                    
                                    villagers[vill_index-1].trades[trade_id-1].jumlah_diberi = beri_jmlh;
                                    villagers[vill_index-1].trades[trade_id-1].item_diberi = beri_item;
                                    villagers[vill_index-1].trades[trade_id-1].jumlah_terima = terima_q;
                                    villagers[vill_index-1].trades[trade_id-1].item_terima = terima_item;
                                    cout << " [^] Trade berhasil diubah." << endl;
                                } else {
                                    cout << " [!] Nomor trade tidak valid. " << endl;
                                }
                            } catch ( const runtime_error& e) {
                                cout << e.what() << endl;
                            }
                        } else {
                            cout << " [!] Tidak ada trade untuk diedit. " << endl;
                        }
                        break;
                    case 3:
                        if (villagers[vill_index-1].num_trade > 0) {
                            
                            cout << " [>] Pilih nomor trade untuk hapus [1-" << villagers[vill_index-1].num_trade << "]: ";
                            try {
                                int trade_id;
                                cin >> trade_id;
                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(1000, '\n');
                                    throw runtime_error(" [!] Input tidak valid. kembali ke menu sebelumya..");
                                }
                                if (trade_id >= 1 && trade_id <= villagers[vill_index-1].num_trade) {
                                    for(int k = trade_id-1; k < villagers[vill_index-1].num_trade-1; k++){
                                        villagers[vill_index-1].trades[k] = villagers[vill_index-1].trades[k+1];
                                    }
                                    villagers[vill_index-1].num_trade--;
                                    cout << " [^] Trade berhasil dihapus." << endl;
                                } else {
                                    cout << " [!] Nomor trade tidak valid. " << endl;
                                }
                            } catch (const runtime_error& e){
                                cout << e.what() << endl;
                            }
                        } else {
                            cout << " [!] Tidak ada trade untuk dihapus. " << endl;
                        }
                        break;
                    case 0:
                        cout << " {^} Kembali ke menu admin.." << endl;
                        break;
                    default:
                        cout << " [!] Pilihan tidak valid." << endl;
                    }
                } while (pilihan_trade != 0);
            } else {
                cout << " [!] Nomor villager tidak valid. " << endl;
            }
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    } else {
        cout << " [!] Tidak ada Villager untuk manage trades.!!" << endl;
    }

}

void tampilkanJumlah(int *jml_villager){
    cout << endl << " [^] Total villager saat ini: " << *jml_villager << endl;
}

// Misahin dari menu creative
void tampilkanVillager() {
    if (jumlah_villager > 0) {
        cout << endl;
        cout << ">>>>>=================================<<<<<" << endl;
        cout << ">>>>>         Daftar Villager:        <<<<<" << endl;
        cout << ">>>>>=================================<<<<<" << endl;
        for(int i = 0; i < jumlah_villager; i++){
            cout << i+1 << ". Nama: " << villagers[i].nama << ", Profesi: " << villagers[i].profesi << endl;
            cout << "   Trades:" << endl;
            for(int j = 0; j < villagers[i].num_trade; j++){
                cout << "   " << j+1 << ". "
                << villagers[i].trades[j].jumlah_diberi<< "x "
                << villagers[i].trades[j].item_diberi << " for "
                << villagers[i].trades[j].jumlah_terima << "x "
                << villagers[i].trades[j].item_terima << endl;
            }
        }
        cout << ">>>>>=================================<<<<<" << endl;
        tampilkanJumlah(&jumlah_villager); 
    } else {
        cout << " [!] Tidak ada Villager yang tersedia. " << endl;
    }
}

void menuSorting() {
    int pilihan_sort;
    do {
        cout << endl;
        cout << ">>>======================================<<<" << endl;
        cout << ">>>         MENU SORTING VILLAGER        <<<" << endl;
        cout << ">>>======================================<<<" << endl;
        cout << "||| 1. Urutkan Nama (A -> Z)             |||" << endl;
        cout << "||| 2. Urutkan Jumlah Trade (Descending) |||" << endl;
        cout << "||| 3. Urutkan Profesi (A -> Z)          |||" << endl;
        cout << "||| 0. Kembali ke menu Creative          |||" << endl;
        cout << ">>>======================================<<<" << endl;
        cout << " [>] Pilihan: "; cin >> pilihan_sort;

        switch (pilihan_sort) {
        case 1:
            urutkanNama(villagers, jumlah_villager);
            cout << " [^] Villager diurutkan berdasarkan Nama:" << endl;
            tampilkanVillager();
            break;
        case 2:
            urutkanTrade(villagers, jumlah_villager);
            cout << " [^] Villager diurutkan berdasarkan Jumlah Trade (terbanyak):" << endl;
            tampilkanVillager();
            break;
        case 3:
            urutkanProfesi(villagers, jumlah_villager);
            cout << " [^] Villager diurutkan berdasarkan Profesi:" << endl;
            tampilkanVillager();
            break;
        case 0:
            cout << " [^] Kembali ke menu Creative.." << endl;
            break;
        default:
            cout << " [!] Pilihan tidak valid." << endl;
        }
    } while (pilihan_sort != 0);
}

void menuCreative(){
    dataVillager(jumlah_akun, jumlah_villager, jumlah_inventory);
    int pilihan_menu_admin;
    cout << " [^] Mode Creative aktif!" << endl << endl;
    do {
        cout << endl;
        cout << ">>>==============================<<<" << endl;
        cout << ">>>      Menu mode Creative:     <<<" << endl;
        cout << ">>>==============================<<<" << endl;
        cout << "||| 1. Lihat daftar Villager     |||" << endl;
        cout << "||| 2. Tambah Villager           |||" << endl;
        cout << "||| 3. Hapus Villager            |||" << endl;
        cout << "||| 4. Manajemen Trade           |||" << endl;
        cout << "||| 5. Sorting Villager          |||" << endl;
        cout << "||| 6. Searching                 |||" << endl;
        cout << "||| 0. Keluar                    |||" << endl;
        cout << ">>>==============================<<<" << endl;
        cout << " [>] Pilihan: "; cin >> pilihan_menu_admin;
        switch (pilihan_menu_admin) {
        case 1:
            tampilkanVillager();
            break;
        case 2:
            if (jumlah_villager < MAX_VILLAGER) {
                string nama_baru, profesi_baru, trade_baru;
                cout << " [>] Masukkan nama villager baru: "; cin.ignore(); getline(cin, nama_baru);
                cout << " [>] Masukkan profesi villager: "; getline(cin, profesi_baru);

                villagers[jumlah_villager].nama = nama_baru;
                villagers[jumlah_villager].profesi = profesi_baru;
                villagers[jumlah_villager].num_trade = 0;
                try {
                    int jumlah_trade_baru;
                    cout << " [>] Berapa trades awal yang ingin ditambahkan [1-5]? "; cin >> jumlah_trade_baru;
                    
                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        throw runtime_error(" [!] Input tidak valid. Trade awal di-set ke 0. ");
                        jumlah_trade_baru = 0;
                    }
                    if (jumlah_trade_baru > 0 && jumlah_trade_baru <= 5) {
                        for(int t = 0; t < jumlah_trade_baru; t++) {
                            cout << "> Masukkan trade " << t+1 << ": ";
                            int jumlah_diberikan, jumlah_diterima;
                            string beri_item, terima_item;
                            cout << " [>] Masukkan jumlah barang yang diberikan: "; cin >> jumlah_diberikan; cin.ignore();
                            cout << " [>] Masukkan nama barang yang diberikan: ";getline(cin, beri_item);
                            cout << " [>] Masukkan jumlah barang yang diterima: ";cin >> jumlah_diterima;cin.ignore();
                            cout << " [>] Masukkan nama barang yang diterima: "; getline(cin, terima_item);
                            villagers[jumlah_villager].trades[t].jumlah_diberi = jumlah_diberikan;
                            villagers[jumlah_villager].trades[t].item_diberi = beri_item;
                            villagers[jumlah_villager].trades[t].jumlah_terima = jumlah_diterima;
                            villagers[jumlah_villager].trades[t].item_terima = terima_item;
                        }
                        villagers[jumlah_villager].num_trade = jumlah_trade_baru;
                    } else {
                        cout << " [!] Jumlah trade tidak valid. Villager ditambahkan tanpa trade. " << endl;
                    }
                }catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                jumlah_villager++;
                cout << " [^] Villager baru ditambahkan" << endl;
            } else {
                cout << " [!] Maksimal " << MAX_VILLAGER << " villagers sudah tercapai. " << endl;
            }
            break;
        case 3:
            tampilkanVillager();
            if (jumlah_villager > 0) {
                try {
                    cout << " [>] Masukkan nomor villager yang ingin dihapus [1-" << jumlah_villager << "]: ";
                    int index; cin >> index;
                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        throw runtime_error(" [!] Input tidak valid. Kembali ke menu admin. ");
                    }
                    if (index >= 1 && index <= jumlah_villager) { // jika valid, geser semua villager setelah index ke kiri
                    for(int i = index-1; i < jumlah_villager-1; i++){ 
                        villagers[i] = villagers[i+1];
                    }
                    jumlah_villager--;
                    cout << " [^] Villager berhasil dihapus." << endl;
                } else {
                    cout << " [!] Nomor villager tidak valid. " << endl;
                }
                }catch (const exception& e) {
                    cout << e.what() << endl;
                    break;
                }
            } else {
                cout << " [!] Tidak ada Villager yang tersedia untuk dihapus. " << endl;
            }
            break;
        case 4:
            menuTrade();
            break;
        case 5:
            menuSorting();
            break;
        case 6:
            menuSearching();
            break;
        case 0:
            cout << " [i] Program dihentikan." << endl;
            break;
        default:
            cout << " [!] Pilihan tidak valid. Silahkan coba lagi." << endl;
        }
    } while(pilihan_menu_admin != 0);
}

void menuSurvival(){
    int pilihan_menu_user;
    do {
        cout << ">>>====================================<<<" << endl;
        cout << ">>>   Anda masuk dalam mode Survival   <<<" << endl;
        cout << ">>>====================================<<<" << endl;
        cout << "||| 1. Tampilkan daftar Villager       |||" << endl;
        cout << "||| 2. Lihat Inventory                 |||" << endl;
        cout << "||| 3. Menu Sorting                    |||" << endl;
        cout << "||| 4. Searching                       |||" << endl;
        cout << "||| 0. Keluar                          |||" << endl;
        cout << ">>>====================================<<<" << endl;
        cout << " [>] Pilihan: ";
        cin >> pilihan_menu_user;

        switch (pilihan_menu_user) {
        case 1:
            if (jumlah_villager > 0) {
                cout << ">>>====================================<<<" << endl;
                cout << ">>>    Menampilkan daftar Villager...  <<<" << endl;
                cout << ">>>====================================<<<" << endl;
                for(int i = 0; i < jumlah_villager; i++){
                    cout << i+1 << ". Nama: " << villagers[i].nama << ", Profesi: " << villagers[i].profesi << endl;
                    cout << "   Trades:" << endl;
                    for(int j = 0; j < villagers[i].num_trade; j++){
                        cout << "   " << j+1 << ". "
                        << villagers[i].trades[j].jumlah_diberi << "x "
                        << villagers[i].trades[j].item_diberi << " for "
                        << villagers[i].trades[j].jumlah_terima << "x "
                        << villagers[i].trades[j].item_terima << endl;
                    }
                }
                cout << ">>>====================================<<<" << endl;
                cout << " [>] Pilih Villager untuk melakukan trade [1-" << jumlah_villager << " atau 0 untuk kembali]: ";
                
                try{
                    cin >> vill_survival_trade;
                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        throw runtime_error(" [!] Input tidak valid. Kembali ke menu utama. ");
                        break;
                    }
                    if (vill_survival_trade >= 1 && vill_survival_trade <= jumlah_villager) {
                        Villager* vill_ptr = &villagers[vill_survival_trade-1];
                        cout << "^ Anda memilih Villager: " << villagers[vill_survival_trade-1].nama << endl;
                        cout << ">>>====================================<<<" << endl;
                        cout << ">>>         Trades yang tersedia:      <<<" << endl;
                        cout << ">>>====================================<<<" << endl;
                        for(int t = 0; t < vill_ptr->num_trade; t++){
                            auto &tr = vill_ptr->trades[t];
                            cout << "   " << t+1 << ". "
                                    << tr.jumlah_diberi << "x " << tr.item_diberi
                                    << " for " << tr.jumlah_terima << "x " << tr.item_terima << endl;
                        }
                        // trade program
                        int pilihan_trade;
                        cout << " [>] Pilih trade yang ingin dilakukan [1-" << vill_ptr->num_trade << "]: ";
                        try{
                            cin >> pilihan_trade;
                            if (cin.fail()){
                                cin.clear();
                                cin.ignore(1000, '\n');
                                throw runtime_error(" [!] Input tidak valid. Kembali ke menu utama.");
                                break;
                            }
                            if(pilihan_trade >= 1 && pilihan_trade <= vill_ptr->num_trade){
                                Trade &tr = vill_ptr->trades[pilihan_trade-1];
                                // melihat inventori dari item yang diberi
                                int idx_dberi = -1, idx_dterima = -1;
                                for(int k=0;k<jumlah_inventory;k++){
                                    if(inventory[k].item == tr.item_diberi) idx_dberi = k;
                                    if(inventory[k].item == tr.item_terima) idx_dterima = k;
                                }
                                if(idx_dberi != -1 && inventory[idx_dberi].jumlah >= tr.jumlah_diberi){
                                    inventory[idx_dberi].jumlah -= tr.jumlah_diberi;
                                    if(idx_dterima != -1){
                                        inventory[idx_dterima].jumlah += tr.jumlah_terima;
                                    } else if(jumlah_inventory < MAX_INVENTORY){
                                        inventory[jumlah_inventory].item = tr.item_terima;
                                        inventory[jumlah_inventory].jumlah = tr.jumlah_terima;
                                        jumlah_inventory++;
                                    }
                                    cout << " [^] Trade sukses: " << tr.jumlah_diberi << "x " << tr.item_diberi
                                            << " ditukar menjadi " << tr.jumlah_terima << "x " << tr.item_terima << "\n";
                                } else {
                                    cout << " [!] Anda tidak punya cukup " << tr.item_diberi << " untuk melakukan trade." << endl;
                                }
                            } else {
                                cout << " [!] Pilihan trade tidak valid. !!" << endl;
                            }
                        }catch (const runtime_error& e) {
                            cout << e.what() << endl;
                        }
                    } else if (vill_survival_trade == 0) {
                        cout << " [!] Kembali ke menu utama.. " << endl;
                    } else {
                        cout << " [!] Pilihan tidak valid. " << endl;
                    }
                }catch (const exception& e) {
                    cout << e.what() << endl;
                }
            } else {
                cout << " [!] Tidak ada Villager yang tersedia. " << endl;
            }
            break;
        case 2:
            cout << ">>>====================================<<<" << endl;
            cout << ">>>         Menampilkan Inventory      <<<" << endl;
            cout << ">>>====================================<<<" << endl;
            if (jumlah_inventory > 0) {
                for(int i = 0; i < jumlah_inventory; i++){
                    cout << i+1 << ". " << inventory[i].item << " - Jumlah: " << inventory[i].jumlah << endl;
                }
            } else {
                cout << " [!] Inventory kosong. " << endl;
            }
            break;
        case 3:
            menuSorting();
            break;
        case 4:
            menuSearching();
            break;
        case 0:
            cout << " [^] Keluar dari menu Survival." << endl;
            cout << " [!] Program dihentikan." << endl;
            break;
        default:
            cout << " [!] Pilihan tidak valid. Silahkan coba lagi. " << endl;
        }
    } while(pilihan_menu_user != 0);
}

int login(int kesempatan){
    cout << " [^] Silahkan login terlebih dahulu.." << endl;
    while(kesempatan > 0){
        cout << " [>] Masukkan Username: "; cin >> username;
        cout << " [>] Masukkan Password: "; cin >> password;
        bool login_berhasil = false;
        for(int i = 0; i < jumlah_akun; i++){
            if(username == daftar_akun[i].username && password == daftar_akun[i].password){
                login_berhasil = true;
                if (username == "Adrian" && password == "032"){
                    menuCreative();
                }else{
                    menuSurvival();
                }
                return 1;
            }
        }
        if(!login_berhasil){
            kesempatan--;
            if(kesempatan > 0){
                cout << " [!] Username atau Password salah! Kesempatan tersisa: " << kesempatan << "x" << endl;
                return login(kesempatan);
            } else {
                cout << " [!] Kesempatan habis. Program dihentikan secara paksa " << endl;
                return 0;
            }
        }
    break;
    }
    
    return 0;
}

int registerAkun(int kesempatan2){
    if(jumlah_akun < MAX_AKUN){
        cout << ">>> Silahkan buat akun dengan memasukkan username dan password yang anda inginkan: <<<" << endl;
        cout << " [>] Masukkan Username: "; cin >> username_baru;
        cout << " [>] Masukkan Password: "; cin >> password_baru;

        //Simpan ke array
        daftar_akun[jumlah_akun].username = username_baru;
        daftar_akun[jumlah_akun].password = password_baru;
        jumlah_akun++;
        cout << " [^] Akun berhasil dibuat!" << endl;
        login(3);
    }else {
        cout << " [!] Maaf, jumlah akun sudah mencapai batas maksimal." << endl;
    }
    return 0;
}

int main(){
    dataVillager(jumlah_akun, jumlah_villager, jumlah_inventory);
    int kesempatan_main = 3;
    bool logged_in = false;
    while(kesempatan_main > 0 && !logged_in){
        cout << endl << " [>] Apakah anda sudah punya akun?[y/n]: " << endl; cin >> yorn;
        if (yorn == "y" || yorn == "Y"){
            if(login(3) == 1){
                logged_in = true;
            }
        } else if (yorn == "n" || yorn == "N"){
            registerAkun(3);
            logged_in = true;
        } else {
            kesempatan_main--;
            if(kesempatan_main == 0){
                cout << " [!] Kesempatan habis. Program dihentikan. " << endl;
            }else {
                cout << " [!] Input salah. Silahkan coba lagi. " << endl; 
                cout << " [!] Kesempatan tersisa: " << kesempatan_main << "x " << endl;
            }
        }
    }
    return 0;
}