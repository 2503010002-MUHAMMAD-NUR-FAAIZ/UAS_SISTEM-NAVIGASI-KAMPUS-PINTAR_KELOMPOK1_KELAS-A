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
struct NodeQueue {
    string namaMahasiswa;
    string keperluan;
    string tujuanRuangan; 
    NodeQueue* next;
};

NodeQueue* frontQueue = NULL;
NodeQueue* rearQueue = NULL;

void enqueueAntrean(string nama, string keperluan, string tujuan) {
    NodeQueue* baru = new NodeQueue();
    baru->namaMahasiswa = nama;
    baru->keperluan = keperluan;
    baru->tujuanRuangan = tujuan;
    baru->next = NULL;

    if (frontQueue == NULL) {
        frontQueue = rearQueue = baru;
    } else {
        rearQueue->next = baru;
        rearQueue = baru;
    }
    cout << "\n[Sukses] " << nama << " berhasil mengambil nomor antrean untuk " << tujuan << "!" << endl;
}

void dequeueAntrean() {
    if (frontQueue == NULL) {
        cout << "\n[Info] Antrean kosong. Tidak ada antrean layanan saat ini." << endl;
        return;
    }
    
    NodeQueue* temp = frontQueue;
    cout << "\n|================================================|" << endl;
    cout << "|         PANGGILAN ANTREAN LOKET LAYANAN        |" << endl;
    cout << "|================================================|" << endl;
    cout << "  Atas Nama      : " << temp->namaMahasiswa << endl;
    cout << "  Keperluan      : " << temp->keperluan << endl;
    cout << "  Silakan menuju : " << temp->tujuanRuangan << "!" << endl;
    cout << "|================================================|" << endl;

    frontQueue = frontQueue->next;
    if (frontQueue == NULL) rearQueue = NULL;
    delete temp;
}

void tampilkanAntrean() {
    if (frontQueue == NULL) {
        cout << "\n[Info] Saat ini tidak ada antrean layanan." << endl;
        return;
    }
    cout << "\n|================================================|" << endl;
    cout << "|      DAFTAR SISA ANTREAN LAYANAN SAAT INI      |" << endl;
    cout << "|================================================|" << endl;
    NodeQueue* temp = frontQueue;
    int nomor = 1;
    while (temp != NULL) {
        cout << "  " << nomor << ". " << temp->namaMahasiswa << " [" << temp->keperluan << " -> " << temp->tujuanRuangan << "]" << endl;
        temp = temp->next;
        nomor++;
    }
    cout << "|================================================|" << endl;
}

string cariRuangan(string input) {
    string inp = toLowerManual(input);
    
    if (ada(inp, "baak") || ada(inp, "ruang baak") || ada(inp, "krs") || ada(inp, "ktm") || ada(inp, "administrasi") || ada(inp, "ukt")) {
        return "Ruang BAAK (Gedung Solihin Lt 2)";
    } 
    else if (ada(inp, "baumk") || ada(inp, "ruang baumk")) {
    	return "Ruang BAUMK (Gedung Solihin Lt 1)";
	}
    else if (ada(inp, "dekan teknik") || ada(inp, "teknik sipil") || ada(inp, "sipil") || ada(inp, "informatika") || ada(inp, "teknik") || ada(inp, "ft")) {
        return "Ruang Dekan Teknik (Gedung Solihin Lt 1)";
    } 
    else if (ada(inp, "dekan pertanian") || ada(inp, "dekan fp") || ada(inp, "pertanian") || ada(inp, "agribisnis") || ada(inp, "agroteknologi") || ada(inp, "peternakan")) {
        return "Ruang Dekan Pertanian (Gedung Solihin Lt 1)";
    } 
    else if (ada(inp, "dekan fik") || ada(inp, "fik") || ada(inp, "ilmu kesehatan") || ada(inp, "farmasi")) {
        return "Ruang Dekan FIK (Gedung Solihin Lt 1)";
    } 
    else if (ada(inp, "dekan fkip") || ada(inp, "fkip") || ada(inp, "pendidikan bahasa inggris") || ada(inp, "guru") || ada(inp, "pbi") || ada(inp, "pgsd")) {
        return "Ruang Dekan FKIP (Gedung Solihin Lt 1)";
    } 
    else if (ada(inp, "dekan feb") || ada(inp, "feb") || ada(inp, "ekonomi") || ada(inp, "manajemen") || ada(inp, "akuntansi") || ada(inp, "bisnis") || ada(inp, "hukum") || ada(inp, "perhotelan")) {
        return "Ruang Dekan FEB (Gedung Solihin Lt 1)"; 
    }
    else if (ada(inp, "ruang dosen tik") || ada(inp, "ruang tik") || ada(inp, "teknik informatika") || ada(inp, "tik")) {
        return "Ruang Dosen TIK (Gedung Solihin Lt 2)";
    }
    else if (ada(inp, "ruang dosen hukum") || ada(inp, "dosen hukum")) {
        return "Ruang Dosen Hukum (Gedung Solihin Lt 3)";
    }
    else if (ada(inp, "lab") || ada(inp, "laboratorium") || ada(inp, "komputer") || ada(inp, "praktikum") || ada(inp, "seni")) {
        return "Laboratorium (Gedung Laboratorium)";
    }
    else if (ada(inp, "perpus") || ada(inp, "perpustakaan") || ada(inp, "buku") || ada(inp, "skripsi") || ada(inp, "baca")) {
        return "Perpustakaan (Gedung Perpustakaan)";
    }
    else if (ada(inp, "rektor") || ada(inp, "rektorat") || ada(inp, "akademik") || ada(inp, "loket")) {
        return "Pusat Layanan Universitas (Gedung Rektorat)";
    }
    else if (ada(inp, "gm") || ada(inp, "mashudi") || ada(inp, "kelas gm")) {
        return "Ruang Perkuliahan (Gedung Mashudi)";
    }
    
    return "";
}

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













































void menuAntreanLayanan() {
    int subPilihan;
    cout << "\n|================================================|" << endl;
    cout << "|      SISTEM ANTREAN CERDAS LAYANAN KAMPUS      |" << endl;
    cout << "|================================================|" << endl;
    cout << "| 1. Ambil Nomor Antrean Baru                    |" << endl;
    cout << "| 2. Panggil & Proses Antrean Terdepan           |" << endl;
    cout << "| 3. Lihat Daftar Sisa Antrean                   |" << endl;
    cout << "|================================================|" << endl;
    cout << " Pilih Menu (1-3): ";
    cin >> subPilihan; cin.ignore(); 

    if (subPilihan == 1) {
        string nama, keperluan;
        cout << "\nNama Mahasiswa: "; getline(cin, nama);
        cout << "Keperluan Layanan (Contoh: KRS/KTM/Praktikum/Pinjam Buku): "; getline(cin, keperluan);
        
        string tujuanOtomatis = cariRuangan(keperluan);
        string tujuanAkhir = "";
        bool lanjutAntrean = false;
        
        if (tujuanOtomatis != "") {
            cout << "\n[SISTEM CERDAS] Berdasarkan keperluan Anda, sistem menyarankan:" << endl;
            cout << ">>> " << tujuanOtomatis << " <<<" << endl;
            
            char setujuArahan;
            cout << "\nApakah Anda ingin diarahkan ke ruangan tersebut? (y/n): ";
            cin >> setujuArahan; cin.ignore();
            
            if (setujuArahan == 'y' || setujuArahan == 'Y') {
                tujuanAkhir = tujuanOtomatis;
                lanjutAntrean = true;
            }
        } 
        
        if (!lanjutAntrean) {
            cout << "\n|================================================|" << endl;
            cout << "|       DAFTAR LOKASI LAYANAN UTAMA KAMPUS       |" << endl;
            cout << "|================================================|" << endl;
            cout << "  - Ruang BAAK (Gedung Solihin)" << endl;
            cout << "  - Seluruh Ruang Dekan (Gedung Solihin)" << endl;
            cout << "  - Loket Akademik (Gedung Rektorat)" << endl;
            cout << "  - Laboratorium (Gedung Laboratorium)" << endl;
            cout << "  - Perpustakaan (Gedung Perpustakaan)" << endl;
            cout << "|================================================|" << endl;
            
            cout << "Silakan ketik manual nama ruangan tujuan Anda: ";
            string inputManual;
            getline(cin, inputManual);
            
            string hasilValidasi = cariRuangan(inputManual);
            if (hasilValidasi != "") {
                tujuanAkhir = hasilValidasi;
                lanjutAntrean = true;
            } else {
                tujuanAkhir = inputManual;
                lanjutAntrean = true;
            }
        }
        
        if (lanjutAntrean) {
            enqueueAntrean(nama, keperluan, tujuanAkhir);
        }
        
    } 
    else if (subPilihan == 2) {
        dequeueAntrean();
    }
    else if (subPilihan == 3) {
        tampilkanAntrean();
    }
    else {
        cout << "\n[Error] Pilihan tidak valid!" << endl;
    }
}

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