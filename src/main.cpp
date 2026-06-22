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
const int MAX_GEDUNG = 11; 
const int INF = 999999; 

string namaGedung[MAX_GEDUNG] = {
    "Gerbang Utama", "Parkiran Mobil", "Bundaran Kampus", "Gedung Solihin", "Gedung Rektorat", 
    "Ormawa", "Sekretariat UKM", "Parkiran Motor", "Laboratorium", "Perpustakaan", "Gedung Mashudi"
};

int adjMatrix[MAX_GEDUNG][MAX_GEDUNG];

int cariIndeksGedung(string nama) {
    for (int i = 0; i < MAX_GEDUNG; i++) {
        if (namaGedung[i] == nama) return i;
    }
    return -1;
}

// FUNGSI MENYESUAIKAN DENGAN DENAH
void inisialisasiGraph() {
    for (int i = 0; i < MAX_GEDUNG; i++) {
        for (int j = 0; j < MAX_GEDUNG; j++) {
            if (i == j) adjMatrix[i][j] = 0;
            else adjMatrix[i][j] = INF;
        }
    }

    // Jalur Sektor Tengah & Utama (Berdasarkan Garis Lurus Tengah)
    adjMatrix[0][1] = 10; adjMatrix[1][0] = 10;   // Gerbang Utama <-> Parkiran Mobil
    adjMatrix[0][2] = 15; adjMatrix[2][0] = 15;   // Gerbang Utama <-> Bundaran Kampus
    adjMatrix[2][7] = 12; adjMatrix[7][2] = 12;   // Bundaran Kampus <-> Parkiran Motor

    // Jalur Sektor Kiri (Tetap Sesuai Denah)
    adjMatrix[1][9] = 15; adjMatrix[9][1] = 15;   // Parkiran Mobil <-> Perpustakaan
    adjMatrix[9][8] = 20; adjMatrix[8][9] = 20;   // Perpustakaan <-> Laboratorium
    adjMatrix[8][10]= 25; adjMatrix[10][8]= 25;   // Laboratorium <-> Gedung Mashudi
    adjMatrix[2][8] = 18; adjMatrix[8][2] = 18;   // Bundaran Kampus <-> Laboratorium (Akses Tengah-Kiri)

    // Jalur Sektor Kanan (Penyesuaian Rute Bypass & Shortcut Baru)
    adjMatrix[0][4] = 12; adjMatrix[4][0] = 12;   // Gerbang Utama <-> Gedung Rektorat (Akses Bawah)
    adjMatrix[2][3] = 11; adjMatrix[3][2] = 11;   // Bundaran Kampus <-> Gedung Solihin (Koneksi Baru Jalur Tengah)
    adjMatrix[2][5] = 14; adjMatrix[5][2] = 14;   // Bundaran Kampus <-> Ormawa (Koneksi Baru Jalur Atas)
    
    // Koneksi Jalur Bypass Vertikal Baru di Sektor Kanan
    adjMatrix[3][4] = 6;  adjMatrix[4][3] = 6;    // Gedung Solihin <-> Gedung Rektorat
    adjMatrix[3][5] = 10; adjMatrix[5][3] = 10;   // Gedung Solihin <-> Ormawa
    adjMatrix[4][5] = 16; adjMatrix[5][4] = 16;   // Gedung Rektorat <-> Ormawa (Bypass Lurus)
    
    adjMatrix[5][6] = 30; adjMatrix[6][5] = 30;   // Ormawa <-> Sekretariat UKM (Loop Kanan Atas)
}

// void inisialisasiDataKampus() {} // GANTI DAN LENGKAPI OLEH KODINGAN MUHAMMAD ZIDNI
































void hitungDijkstra(int asal, int tujuan) {
    int jarak[MAX_GEDUNG];
    bool dikunjungi[MAX_GEDUNG];
    int parent[MAX_GEDUNG];

    for (int i = 0; i < MAX_GEDUNG; i++) {
        jarak[i] = INF; dikunjungi[i] = false; parent[i] = -1;
    }

    jarak[asal] = 0;

    for (int count = 0; count < MAX_GEDUNG - 1; count++) {
        int minJarak = INF, u = -1;
        for (int v = 0; v < MAX_GEDUNG; v++) {
            if (!dikunjungi[v] && jarak[v] <= minJarak) {
                minJarak = jarak[v]; u = v;
            }
        }
        if (u == -1) break;
        dikunjungi[u] = true;

        for (int v = 0; v < MAX_GEDUNG; v++) {
            if (!dikunjungi[v] && adjMatrix[u][v] != INF && jarak[u] + adjMatrix[u][v] < jarak[v]) {
                jarak[v] = jarak[u] + adjMatrix[u][v]; parent[v] = u;
            }
        }
    }

    if (jarak[tujuan] == INF) {
        cout << "\n[Gagal] Rute tidak ditemukan atau tidak terhubung!" << endl;
    } else {
        cout << "\n|================================================|" << endl;
        cout << "|       HASIL REKOMENDASI RUTE NAVIGASI KAMPUS   |" << endl;
        cout << "|================================================|" << endl;
        cout << "  Total Jarak : " << jarak[tujuan] << " meter" << endl;
        cout << "  Jalur Rute  : ";

        int ruteJalan[MAX_GEDUNG]; int indeks = 0; int saatIni = tujuan;
        while (saatIni != -1) {
            ruteJalan[indeks++] = saatIni; saatIni = parent[saatIni];
        }

        for (int i = indeks - 1; i >= 0; i--) {
            cout << namaGedung[ruteJalan[i]];
            if (i > 0) cout << " -> ";
        }
        cout << "\n|================================================|" << endl;
    }
}

// =====================
// FUNGSI UI MENU UTAMA
// =====================

// void menuDaftarFasilitas() {} // GANTI DAN LENGKAPI KODINGANNYA OLEH MOHAMAD ZIDNI ILMA
















void menuRuteTerpendek() {
    cout << "\n|================================================|" << endl;
    cout << "|   CARI RUTE TERPENDEK ANTAR LOKASI FASILITAS   |" << endl;
    cout << "|================================================|" << endl;
    for (int i = 0; i < MAX_GEDUNG; i++) cout << "  [" << i << "] " << namaGedung[i] << endl;
    cout << "|================================================|" << endl;

    int asal, tujuan;
    cout << "\nMasukkan Kode Lokasi Asal (0-10)   : "; cin >> asal;
    cout << "Masukkan Kode Lokasi Tujuan (0-10) : "; cin >> tujuan;

    if (asal >= 0 && asal < MAX_GEDUNG && tujuan >= 0 && tujuan < MAX_GEDUNG) {
        hitungDijkstra(asal, tujuan);
    } else cout << "\n[Error] Kode lokasi yang dimasukkan tidak valid!" << endl;
}

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