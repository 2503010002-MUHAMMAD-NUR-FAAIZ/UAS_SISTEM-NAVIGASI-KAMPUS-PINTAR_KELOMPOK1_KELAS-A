#include <iostream>
#include <string>

using namespace std;

// ==============================
// SISTEM NAVIGASI KAMPUS PINTAR
// ==============================

string toLowerManual(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32; 
        }
    }
    return s;
}

bool ada(string kalimat, string kata) {
    return kalimat.find(kata) != string::npos;
}

// ====================================================
// 1. MODUL QUEUE / ANTREAN (Oleh: Muhammad Nur Faaiz)
// ====================================================














































































































// =================================================================
// 2. MODUL BST / BINARY SEARCH TREE (Oleh: Muhammad Frian Erliana)
// =================================================================















































// ===============================================================
// 3. MODUL LINKED LIST & SINKRONISASI (Oleh: Mohamad Zidni Ilma)
// ===============================================================



























// ================================================
// 4. MODUL GRAPH & DIJKSTRA (Oleh: Muhamad Husni)
// ================================================


















































// void inisialisasiDataKampus() {} // GANTI DAN LENGKAPI OLEH KODINGAN MUHAMMAD ZIDNI


















































































// =====================
// FUNGSI UI MENU UTAMA
// =====================

// void menuDaftarFasilitas() {} // GANTI DAN LENGKAPI KODINGANNYA OLEH MOHAMAD ZIDNI ILMA
















// void menuRuteTerpendek() {} // GANTI DAN LENGKAPI OLEH KODINGANNYA MUHAMMAD HUSNI















// void menuCariInformasiKelas() {} // GANTI DAN LENGKAPI KODINGANNYA OLEH MUHAMMAD FRIAN ERLIANA













































// void menuAntreanLayanan() {} // GANTI DAN LENGKAPI KODINGANNYA OLEH MUHAMMAD NUR FAAIZ











































































int main() {
    inisialisasiGraph();
    inisialisasiDataKampus();
    int pilihan;
    
    do {
        cout << "\n|================================================|" << endl;
        cout << "|          SISTEM NAVIGASI KAMPUS PINTAR         |" << endl;
        cout << "|        UNIVERSITAS PERJUANGAN TASIKMALAYA      |" << endl;
        cout << "|================================================|" << endl;
        cout << "| :                 PILIH MENU                 : |" << endl;
        cout << "|================================================|" << endl;
        cout << "| 1. Daftar Fasilitas                            |" << endl;
        cout << "| 2. Cari Rute Terpendek Antar Lokasi            |" << endl;
        cout << "| 3. Cari Informasi Ruangan Kelas                |" << endl;
        cout << "| 4. Antrean Layanan                             |" << endl;
        cout << "| 5. Keluar                                      |" << endl;
        cout << "|================================================|" << endl;
        cout << " Pilih Menu (1-5): ";
        cin >> pilihan; cin.ignore(); 

        if (pilihan == 1) menuDaftarFasilitas();
        else if (pilihan == 2) menuRuteTerpendek();
        else if (pilihan == 3) menuCariInformasiKelas();
        else if (pilihan == 4) menuAntreanLayanan();
        else if (pilihan == 5) cout << "\nKeluar dari program. Terima kasih!\n";
        else cout << "\nPilihan tidak tersedia! Silakan coba kembali.\n";
    } while (pilihan != 5);
    
    return 0;
}