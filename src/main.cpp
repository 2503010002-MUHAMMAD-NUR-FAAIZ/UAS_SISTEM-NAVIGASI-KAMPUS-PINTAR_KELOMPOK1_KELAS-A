#include <iostream>
#include <string>

using namespace std;

// ==========================================
// UTILITAS GLOBAL & VARIABEL (Diperlukan Semua)
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

const int MAX_GEDUNG = 11; 
const int INF = 999999; 
string namaGedung[MAX_GEDUNG] = {
    "Gerbang Utama", "Parkiran Mobil", "Bundaran Kampus", "Gedung Solihin", "Gedung Rektorat", 
    "Ormawa", "Sekretariat UKM", "Parkiran Motor", "Laboratorium", "Perpustakaan", "Gedung Mashudi"
};
int adjMatrix[MAX_GEDUNG][MAX_GEDUNG];

// ==========================================
// PROTOTYPE FUNGSI (Pencegah Error Dependency)
// ==========================================
struct NodeBST;
extern NodeBST* root;
int cariIndeksGedung(string nama);
void hitungDijkstra(int asal, int tujuan);
NodeBST* insertBST(NodeBST* node, string nama, string info, string arrRuangan[], int jml);

// ==========================================
// PLACEHOLDER / CANGKANG KOSONG UNTUK ANGGOTA
// ==========================================

// -- Slot Zidni --
void inisialisasiDataKampus() { /* Akan diisi Zidni */ }
void menuDaftarFasilitas() { cout << "\n[Info] Fitur Zidni belum masuk.\n"; }

// -- Slot Husni --
void inisialisasiGraph() { /* Akan diisi Husni */ }
void menuRuteTerpendek() { cout << "\n[Info] Fitur Husni belum masuk.\n"; }

// -- Slot Frian --
void menuCariInformasiKelas() { cout << "\n[Info] Fitur Frian belum masuk.\n"; }

// -- Slot Faiz --
void menuAntreanLayanan() { cout << "\n[Info] Fitur Faiz belum masuk.\n"; }

// ==========================================
// FUNGSI UTAMA (MAIN)
// ==========================================
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

// Stub Sementara agar bisa di-compile
int cariIndeksGedung(string nama) { return -1; }
void hitungDijkstra(int asal, int tujuan) {}
NodeBST* insertBST(NodeBST* node, string nama, string info, string arrRuangan[], int jml) { return NULL; }
NodeBST* root = NULL;