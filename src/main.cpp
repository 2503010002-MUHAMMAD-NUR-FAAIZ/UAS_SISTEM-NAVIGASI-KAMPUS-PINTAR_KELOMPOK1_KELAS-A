#include <iostream>
#include <string>

using namespace std;

// ==========================================
// UTILITAS GLOBAL (Dibutuhkan semua modul)
// ==========================================
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

// Data Global Navigasi (Agar kodingan Husni & Zidni tidak error)
const int MAX_GEDUNG = 11; 
const int INF = 999999; 
string namaGedung[MAX_GEDUNG] = {
    "Gerbang Utama", "Parkiran Mobil", "Bundaran Kampus", "Gedung Solihin", "Gedung Rektorat", 
    "Ormawa", "Sekretariat UKM", "Parkiran Motor", "Laboratorium", "Perpustakaan", "Gedung Mashudi"
};
int adjMatrix[MAX_GEDUNG][MAX_GEDUNG];

// Deklarasi Awal BST (Agar kodingan Zidni bisa memanggil fungsi Frian)
struct NodeBST;
extern NodeBST* root;
NodeBST* insertBST(NodeBST* node, string nama, string info, string arrRuangan[], int jml);
int cariIndeksGedung(string nama);
void hitungDijkstra(int asal, int tujuan);


// ====================================================
// 1. MODUL QUEUE / ANTREAN (Oleh: Muhammad Nur Faaiz)
// ====================================================
// [FAAIZ: NANTI HAPUS FUNGSI KOSONG INI, GANTI DENGAN KODINGANMU]
void menuAntreanLayanan() {
    cout << "\n[Info] Fitur Antrean belum dimasukkan oleh Faaiz.\n";
}


// =================================================================
// 2. MODUL BST / BINARY SEARCH TREE (Oleh: Muhammad Frian Erliana)
// =================================================================
// [FRIAN: NANTI HAPUS FUNGSI KOSONG INI, GANTI DENGAN KODINGANMU]
void menuCariInformasiKelas() {
    cout << "\n[Info] Fitur BST belum dimasukkan oleh Frian.\n";
}


// ===============================================================
// 3. MODUL LINKED LIST & SINKRONISASI (Oleh: Mohamad Zidni Ilma)
// ===============================================================
// [ZIDNI: NANTI HAPUS FUNGSI KOSONG INI, GANTI DENGAN KODINGANMU]
void inisialisasiDataKampus() {
    // Kosong sementara
}
void menuDaftarFasilitas() {
    cout << "\n[Info] Fitur Linked List belum dimasukkan oleh Zidni.\n";
}


// ================================================
// 4. MODUL GRAPH & DIJKSTRA (Oleh: Muhamad Husni)
// ================================================
// [HUSNI: NANTI HAPUS FUNGSI KOSONG INI, GANTI DENGAN KODINGANMU]
void inisialisasiGraph() {
    // Kosong sementara
}
void menuRuteTerpendek() {
    cout << "\n[Info] Fitur Graph Dijkstra belum dimasukkan oleh Husni.\n";
}


// =====================
// FUNGSI UI MENU UTAMA
// =====================
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

// Stub Sementara Pelengkap Prototype
int cariIndeksGedung(string nama) { return -1; }
void hitungDijkstra(int asal, int tujuan) {}
NodeBST* insertBST(NodeBST* node, string nama, string info, string arrRuangan[], int jml) { return NULL; }
NodeBST* root = NULL;