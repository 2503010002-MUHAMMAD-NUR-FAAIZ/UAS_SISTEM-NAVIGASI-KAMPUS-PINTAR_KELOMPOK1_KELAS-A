#include <iostream>
#include <string>

using namespace std;

// TEMPLATE BY LEAD DEVELOPER - FAAIZ

// --- TEMPAT STRUKTUR DATA (DIKERJAKAN SESUAI PEMBAGIAN TUGAS) ---
// 1. Struktur Data Graph (Untuk Rute Terpendek)
// 2. Struktur Data BST (Untuk Cari Info Ruangan)
// 3. Struktur Data Queue (Untuk Antrean Layanan)
// 4. Struktur Data Linked List (Untuk Daftar Gedung)

// DATABASE GEDUNG - HUSNI
struct Gedung {
    string nama;
    string deskripsi;
};

Gedung daftarGedung[] = {
    {"Lab",             "Laboratorium komputer dan praktikum"},
    {"Gedung Mashudi",  "Gedung perkuliahan"},
    {"Gedung Solihin",  "Gedung perkuliahan"},
    {"Kantin",          "Pusat makanan dan minuman kampus"},
    {"Perpustakaan",    "Pusat referensi dan belajar mahasiswa"}
};


int jarak[5][5] = {
    //lab //gm  //gs //kntn //perpus
    {  0,  100,  150,  200,  120 },  // Lab
    {100,    0,   80,  150,   90 },  // Gm
    {150,   80,    0,  100,   70 },  // GS
    {200,  150,  100,    0,  130 },  // Kantin
    {120,   90,   70,  130,    0 },  // Perpus
};

// --- DEKLARASI FUNGSI UTAMA APP --- 
void menuRuteTerpendek() {
	cout << "\n[Modul Graph] --- FITUR RUTE TERPENDEK ---" << endl;
	// TODO: Tugas anggota bagian Graph kerjakan logikanya di sini
	cout << "Fitur ini masih dalan pengembangan...\n";
}

void menuCariInformasi() {
	cout << "\n[Modul BST] --- FITUR CARI INFO FASILITAS ---" << endl;
	// TODO: Tugas anggota bagian BST kerjakan logikanya di sini
	cout << "Fitur ini masih dalam pengembangan...\n";
}

void menuAntreanLayanan() {
	cout << "\n[Modul Queue] --- FITUR ANTREAN LOKET KAMPUS ---" << endl;
	//TODO: Tugas anggota bagian Queue kerjakan logikanya di sini
	cout << "Fitur ini masih dalam pengembangan...\n";
}

void menuDaftarFasilitas() {
	cout << "\n[Modul Linked List] --- DAFTAR SELURUH FASILITAS ---" << endl;
	//TODO: Tugas anggota bagian Linked List kerjakan logikanya di sini
	cout << "Fitur ini masih dalam pengembangan...\n";
}

int main() {
	int pilihan;
	
	do {
		cout << "\n==============================================" << endl;
		cout << "	SISTEM NAVIGASI KAMPUS PINTAR	" << endl;
		cout << "==============================================" << endl;
		cout << "1. Cari Rute Terpendek Antar Gedung" << endl;
		cout << "2. Cari Informasi Ruangan Atau Fasilitas" << endl;
		cout << "3. Ambil Atau Proses Antrean Loket Layanan" << endl;
		cout << "4. Lihat Semua Daftar Fasilitas Kampus" << endl;
		cout << "5. Keluar Aplikasi" << endl;
		cout << "------------------------------------" << endl;
		cout << "Pilih Menu (1-5): ";
		cin >> pilihan;
		
		switch (pilihan) {
			case 1:
				menuRuteTerpendek();
				break;
			case 2:
				menuCariInformasi();
				break;
			case 3:
				menuAntreanLayanan();
				break;
			case 4:
				menuDaftarFasilitas();
				break;
			case 5:
				cout << "\nKeluar dari program.";
				break;
			default:
				cout << "\nPilihan tidak tersedia! Silakan coba kembali.\n";
		}
	} while (pilihan != 5);
	
	return 0;
}

