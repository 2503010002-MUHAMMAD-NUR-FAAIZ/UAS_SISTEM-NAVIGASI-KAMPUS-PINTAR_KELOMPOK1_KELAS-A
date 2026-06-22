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
struct NodeFasilitas {
    string namaFasilitas;
    string kategori; 
    string daftarRuangan[15];
    int jmlRuangan;
    NodeFasilitas* next;
};

NodeFasilitas* headFasilitas = NULL;

void tambahFasilitas(string nama, string kat, string arrRuangan[], int jml) {
    NodeFasilitas* baru = new NodeFasilitas();
    baru->namaFasilitas = nama;
    baru->kategori = kat;
    baru->jmlRuangan = jml;
    for(int i = 0; i < jml; i++) baru->daftarRuangan[i] = arrRuangan[i];
    baru->next = NULL;
    
    if (headFasilitas == NULL) headFasilitas = baru;
    else {
        NodeFasilitas* temp = headFasilitas;
        while (temp->next != NULL) temp = temp->next;
        temp->next = baru; 
    }
    root = insertBST(root, nama, kat, arrRuangan, jml);
}



























// ================================================
// 4. MODUL GRAPH & DIJKSTRA (Oleh: Muhamad Husni)
// ================================================
























void inisialisasiDataKampus() {
    string kosong[1] = {""}; 
    
    string r_solihin[] = {
        "Lantai 1: Kelas GS 1A-1J, Ruang BAUMK, Seluruh Ruang Dekan (Teknik, FP, FIK, FKIP, FEB)", 
        "Lantai 2: Kelas GS 2A-2J, Ruang BAAK, Ruang Dosen Teknik Informatika", 
        "Lantai 3: Kelas GS 3A-3J, Ruang Dosen Hukum"
    };
    string r_lab[] = {"Lab Seni Budaya", "Lab Komputer", "Lab Teknik Sipil"};
    string r_rektorat[] = {"Lantai 1: Loket Academic", "Lantai 2: Ruang Rektorat"};
    
    string r_mashudi[] = {
        "Lantai 1: Kelas GM 1A-1J", 
        "Lantai 2: Kelas GM 2A-2J",
        "Lantai 3: Kelas GM 3A-3J",
        "Lantai 4: Kelas GM 4A-4J"
    };

    string r_perpus[] = {"Ruang Baca", "Rak Buku Utama", "Arsip Skripsi"};

    tambahFasilitas(namaGedung[0], "Akses Masuk", kosong, 0);
    tambahFasilitas(namaGedung[1], "Fasilitas Umum", kosong, 0); 
    tambahFasilitas(namaGedung[2], "Titik Persimpangan", kosong, 0);
    tambahFasilitas(namaGedung[3], "Ruang Perkuliahan & Layanan", r_solihin, 3);
    tambahFasilitas(namaGedung[4], "Pusat Layanan Universitas", r_rektorat, 2);
    tambahFasilitas(namaGedung[5], "Pusat Organisasi", kosong, 0);
    tambahFasilitas(namaGedung[6], "Kegiatan Mahasiswa", kosong, 0);
    tambahFasilitas(namaGedung[7], "Fasilitas Umum", kosong, 0);
    tambahFasilitas(namaGedung[8], "Laboratorium", r_lab, 3);
    tambahFasilitas(namaGedung[9], "Pusat Referensi", r_perpus, 3);
    tambahFasilitas(namaGedung[10], "Ruang Perkuliahan", r_mashudi, 4); 
}

























// void inisialisasiDataKampus() {} // GANTI DAN LENGKAPI OLEH KODINGAN MUHAMMAD ZIDNI





























void menuDaftarFasilitas() {
    cout << "\n|================================================|" << endl;
    cout << "|          DAFTAR SELURUH FASILITAS KAMPUS        |" << endl;
    cout << "|================================================|" << endl;
    NodeFasilitas* temp = headFasilitas; int nomor = 1;
    while (temp != NULL) {
        cout << "  " << nomor << ". " << temp->namaFasilitas << " [" << temp->kategori << "]" << endl;
        if(temp->jmlRuangan > 0) {
            for(int i = 0; i < temp->jmlRuangan; i++) {
                cout << "     -> " << temp->daftarRuangan[i] << endl;
            }
        }
        temp = temp->next; nomor++;
    }
    cout << "|================================================|" << endl;
}




















































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