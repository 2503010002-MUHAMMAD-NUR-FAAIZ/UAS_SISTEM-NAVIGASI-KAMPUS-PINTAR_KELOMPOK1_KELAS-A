#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// --- SISTEM NAVIGASI KAMPUS PINTAR ---
// ============================================================================

// --- TEMPAT STRUKTUR DATA (URUTAN PENGERJAAN & REVISI) ---
// 1. Struktur Data Queue (Untuk Antrean Layanan - Oleh: Faiz)
// 2. Struktur Data Linked List (Untuk Daftar Gedung - Oleh: Zidni)
// 3. Struktur Data BST (Untuk Cari Info Ruangan - Oleh: Frian)
// 4. Struktur Data Graph (Untuk Rute Terpendek - Oleh: Husni)


// ============================================================================
// --- DEKLARASI MODUL & FUNGSI UTAMA APP --- 
// ============================================================================

// 1. MODUL QUEUE (Oleh: Faiz)
// TODO: Definisikan struct NodeQueue, pointer front & rear di sini
void menuAntreanLayanan() {
	cout << "\n[Modul Queue] --- FITUR ANTREAN LOKET KAMPUS ---" << endl;
	// TODO: Tugas Faaiz bagian Queue kerjakan logikanya di sini
	cout << "Fitur ini masih dalam pengembangan...\n";
}


// 2. MODUL LINKED LIST & SINKRONISASI (Oleh: Zidni)
// TODO: Definisikan struct NodeFasilitas dan pointer headFasilitas di sini
void menuDaftarFasilitas() {
	cout << "\n[Modul Linked List] --- DAFTAR SELURUH FASILITAS ---" << endl;
	// TODO: Tugas Zidni bagian Linked List kerjakan logikanya di sini
	cout << "Fitur ini masih dalam pengembangan...\n";
}


// 3. MODUL BST / BINARY SEARCH TREE (Oleh: Frian)
// TODO: Definisikan struct NodeBST dan pointer root di sini
void menuCariInformasi()  {
	cout << "\n[Modul BST] --- FITUR CARI INFO FASILITAS ---" << endl;
	// TODO: Tugas Frian bagian BST kerjakan logikanya di sini
	cout << "Fitur ini masih dalam pengembangan...\n";
}


// 4. MODUL GRAPH & DIJKSTRA (Oleh: Husni)
// TODO: Definisikan matriks ketetanggaan, nilai INF, dan array rute di sini
void menuRuteTerpendek() {
	cout << "\n[Modul Graph] --- FITUR RUTE TERPENDEK ---" << endl;
	// TODO: Tugas Husni bagian Graph kerjakan logikanya di sini
	cout << "Fitur ini masih dalam pengembangan...\n";
}


// ============================================================================
// MAIN FUNCTION (MANAJEMEN MENU UTAMA)
// ============================================================================
int main() {
	int pilihan;
	
	// TODO: Panggil fungsi inisialisasi graph / data kampus di sini nanti
	
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
		
		cin.ignore(); // Membersihkan sisa (\n) dari buffer cin

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
				cout << "\nKeluar dari program. Terima kasih!\n";
				break;
			default:
				cout << "\nPilihan tidak tersedia! Silakan coba kembali.\n";
		}
	} while (pilihan != 5);
	
	return 0;
}