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

// Deklarasi Awal untuk modul bawahnya
int cariIndeksGedung(string nama);
void hitungDijkstra(int asal, int tujuan);


// ===================================================
// 1. MODUL QUEUE / ANTREAN (Oleh: Mohamad Zidni Ilma)
// ===================================================
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
            cout << "|        DAFTAR LOKASI LAYANAN UTAMA KAMPUS      |" << endl;
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


// =================================================================
// 2. MODUL BST / BINARY SEARCH TREE (Oleh: Muhammad Frian Erliana)
// =================================================================

struct NodeBST {
    string namaGedung;
    string kategori; // Sinkron dengan parameter 'kat' dari Zidni
    string daftarRuangan[15];
    int jmlRuangan;
    NodeBST *kiri, *kanan;
};

NodeBST* root = NULL; 

NodeBST* buatNodeBaru(string nama, string kat, string arrRuangan[], int jml) {
    NodeBST* baru = new NodeBST();
    baru->namaGedung = nama;
    baru->kategori = kat;
    baru->jmlRuangan = jml;
    for (int i = 0; i < jml; i++) {
        baru->daftarRuangan[i] = arrRuangan[i];
    }
    baru->kiri = baru->kanan = NULL;
    return baru;
}

// Fungsi Insert ke BST
NodeBST* insertBST(NodeBST* node, string nama, string kat, string arrRuangan[], int jml) {
    if (node == NULL) return buatNodeBaru(nama, kat, arrRuangan, jml);
    
    if (toLowerManual(nama) < toLowerManual(node->namaGedung))
        node->kiri = insertBST(node->kiri, nama, kat, arrRuangan, jml);
    else if (toLowerManual(nama) > toLowerManual(node->namaGedung))
        node->kanan = insertBST(node->kanan, nama, kat, arrRuangan, jml);
        
    return node;
}

// Fungsi Pencarian BST (Diubah mengembalikan NodeBST* agar bisa terintegrasi dengan Rute Husni)
NodeBST* cariBST(NodeBST* node, string namaDicari) {
    if (node == NULL) return NULL;
    
    string keyLower = toLowerManual(namaDicari);
    
    // 1. Cek apakah yang dicari ada di Nama Gedung
    if (ada(toLowerManual(node->namaGedung), keyLower)) return node;
    
    // 2. Cek apakah yang dicari ada di dalam Daftar Ruangan gedung ini (FITUR YANG TADI HILANG)
    for (int i = 0; i < node->jmlRuangan; i++) {
        if (ada(toLowerManual(node->daftarRuangan[i]), keyLower)) {
            return node;
        }
    }
    
    // 3. Telusuri cabang kiri dan kanan
    NodeBST* kiri = cariBST(node->kiri, namaDicari);
    if (kiri != NULL) return kiri;
    
    return cariBST(node->kanan, namaDicari);
}

// Fungsi Menu UI untuk BST (Mengembalikan fitur interaksi panduan rute)
void menuCariInformasiKelas() {
    string kataKunci;
    cout << "\nMasukkan nama gedung/ruangan yang dicari (Misal: Solihin, GS 1A, Lab Komputer): ";
    getline(cin, kataKunci);
    
    if (kataKunci == "") {
        cout << "[Peringatan] Kata kunci pencarian tidak boleh kosong!" << endl;
        return;
    }
    
    cout << "\n[Pencarian BST] Melakukan tracking data untuk '" << kataKunci << "'..." << endl;
    NodeBST* hasil = cariBST(root, kataKunci);
    
    if (hasil != NULL) {
        cout << "\n|================================================|" << endl;
        cout << "|                HASIL PENCARIAN (BST)           |" << endl;
        cout << "|================================================|" << endl;
        cout << "  Gedung   : " << hasil->namaGedung << endl;
        cout << "  Kategori : " << hasil->kategori << endl;
        if (hasil->jmlRuangan > 0) {
            cout << "  Daftar Ruangan Gedung Ini:" << endl;
            for (int i = 0; i < hasil->jmlRuangan; i++) {
                cout << "     -> " << hasil->daftarRuangan[i] << endl;
            }
        } else {
            cout << "  Detail   : Tidak ada informasi ruangan spesifik." << endl;
        }
        cout << "|================================================|" << endl;
        
        // INTEGRASI KE GRAF & DIJKSTRA milik HUSNI
        int idTujuan = cariIndeksGedung(hasil->namaGedung);
        char lihatRute;
        cout << "\nApakah Anda ingin dipandu (melihat rute) menuju gedung ini? (y/n): ";
        cin >> lihatRute;
        
        if ((lihatRute == 'y' || lihatRute == 'Y') && idTujuan != -1) {
            cout << "\nMenuju Menu Rute...\n";
            cout << "|================================================|" << endl;
            cout << "|      PILIH LOKASI ANDA SAAT INI (KODE 0-10)     |" << endl;
            cout << "|================================================|" << endl;
            for (int i = 0; i < MAX_GEDUNG; i++) cout << "  [" << i << "] " << namaGedung[i] << endl;
            cout << "|================================================|" << endl;
            int asal;
            cout << "Lokasi Anda saat ini (Pilih Kode 0-10): ";
            cin >> asal;
            if (asal >= 0 && asal < MAX_GEDUNG) {
                hitungDijkstra(asal, idTujuan);
            } else {
                cout << "\n[Error] Kode lokasi asal tidak valid!" << endl;
            }
        }
    } else {
        cout << "\n[Info] Maaf, data ruangan/kelas '" << kataKunci << "' tidak ditemukan di sistem BST." << endl;
    }
}


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

void menuDaftarFasilitas() {
    cout << "\n|================================================|" << endl;
    cout << "|          DAFTAR SELURUH FASILITAS KAMPUS       |" << endl;
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


// ================================================
// 4. MODUL GRAPH & DIJKSTRA (Oleh: Muhamad Husni)
// ================================================

void inisialisasiGraph() {
    // 1. Set semua jarak menjadi INF (tidak terhubung), kecuali ke node itu sendiri (0)
    for (int i = 0; i < MAX_GEDUNG; i++) {
        for (int j = 0; j < MAX_GEDUNG; j++) {
            if (i == j) adjMatrix[i][j] = 0;
            else adjMatrix[i][j] = INF;
        }
    }

    // 2. Hubungan Jalur Sesuai Denah (Jarak estimasi dalam meter)
   
    // Area Bawah & Masuk
    adjMatrix[0][1] = 50;  adjMatrix[1][0] = 50;   // Gerbang Utama <-> Parkiran Mobil
    adjMatrix[0][2] = 100; adjMatrix[2][0] = 100;  // Gerbang Utama <-> Bundaran Kampus
    
    // Jalur Sisi Kiri (Sesuai garis panjang dari parkiran mobil ke atas)
    adjMatrix[1][9] = 150; adjMatrix[9][1] = 150;  // Parkiran Mobil <-> Perpustakaan
    
    // Area Kanan Bawah (Bundaran ke Rektorat & Solihin)
    adjMatrix[2][4] = 60;  adjMatrix[4][2] = 60;   // Bundaran Kampus <-> Gedung Rektorat
    adjMatrix[2][3] = 80;  adjMatrix[3][2] = 80;   // Bundaran Kampus <-> Gedung Solihin
    adjMatrix[4][3] = 30;  adjMatrix[3][4] = 30;   // Gedung Rektorat <-> Gedung Solihin (Jalur nyambung)
    
    // Persimpangan Tengah Atas dari Bundaran
    adjMatrix[2][8] = 90;  adjMatrix[8][2] = 90;   // Bundaran Kampus <-> Laboratorium
    adjMatrix[2][7] = 80;  adjMatrix[7][2] = 80;   // Bundaran Kampus <-> Parkiran Motor
    
    // Area Kiri Atas
    adjMatrix[8][9] = 60;  adjMatrix[9][8] = 60;   // Laboratorium <-> Perpustakaan
    adjMatrix[8][10] = 80; adjMatrix[10][8] = 80;  // Laboratorium <-> Gedung Mashudi
    
    // Area Kanan Atas
    adjMatrix[7][5] = 40;  adjMatrix[5][7] = 40;   // Parkiran Motor <-> Ormawa
    adjMatrix[3][5] = 70;  adjMatrix[5][3] = 70;   // Gedung Solihin <-> Ormawa (Garis ke atas dari Solihin)
    adjMatrix[5][6] = 100; adjMatrix[6][5] = 100;  // Ormawa <-> Sekretariat UKM (Garis memutar di ujung kanan)
}

int cariIndeksGedung(string nama) {
    string target = toLowerManual(nama);
    for (int i = 0; i < MAX_GEDUNG; i++) {
        if (toLowerManual(namaGedung[i]) == target) {
            return i;
        }
    }
    return -1;
}

void hitungDijkstra(int asal, int tujuan) {
    int dist[MAX_GEDUNG];     // Menyimpan jarak terpendek
    bool visited[MAX_GEDUNG]; // Menandai gedung yang sudah dikunjungi
    int parent[MAX_GEDUNG];   // Untuk melacak rute jalur

    // Inisialisasi awal algoritma Dijkstra
    for (int i = 0; i < MAX_GEDUNG; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[asal] = 0; // Jarak dari asal ke asal adalah 0

    // Proses pencarian rute terpendek
    for (int count = 0; count < MAX_GEDUNG - 1; count++) {
        int minDist = INF, u = -1;

        // Cari node dengan jarak terpendek yang belum dikunjungi
        for (int i = 0; i < MAX_GEDUNG; i++) {
            if (!visited[i] && dist[i] <= minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // Jika tidak ada node tersisa, hentikan
        visited[u] = true;

        // Update jarak node tetangga
        for (int v = 0; v < MAX_GEDUNG; v++) {
            if (!visited[v] && adjMatrix[u][v] != INF && dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
                parent[v] = u; // Catat dari mana kita datang
            }
        }
    }

    // Tampilkan Hasil
    cout << "\n|================================================|" << endl;
    cout << "|               HASIL RUTE TERPENDEK             |" << endl;
    cout << "|================================================|" << endl;

    if (dist[tujuan] == INF) {
        cout << " [Error] Tidak ada jalur dari " << namaGedung[asal] << " ke " << namaGedung[tujuan] << ".\n";
    } else {
        cout << " Asal   : " << namaGedung[asal] << endl;
        cout << " Tujuan : " << namaGedung[tujuan] << endl;
        cout << " Jarak  : " << dist[tujuan] << " Meter\n";
        cout << " Rute   : ";

        // Backtracking (melacak balik rute dari tujuan ke asal)
        int path[MAX_GEDUNG];
        int pathL = 0;
        int curr = tujuan;
        while (curr != -1) {
            path[pathL++] = curr;
            curr = parent[curr];
        }

        // Print rute dari asal ke tujuan
        for (int i = pathL - 1; i >= 0; i--) {
            cout << namaGedung[path[i]];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }
    cout << "|================================================|" << endl;
}

void menuRuteTerpendek() {
    cout << "\n|================================================|" << endl;
    cout << "|      PILIH LOKASI ASAL & TUJUAN (KODE 0-10)    |" << endl;
    cout << "|================================================|" << endl;
    for (int i = 0; i < MAX_GEDUNG; i++) {
        // Format print agar rapi
        if (i < 10) cout << "  [0" << i << "] " << namaGedung[i] << endl;
        else cout << "  [" << i << "] " << namaGedung[i] << endl;
    }
    cout << "|================================================|" << endl;
    
    int asal, tujuan;
    cout << " Masukkan Kode Lokasi Asal   : "; cin >> asal;
    cout << " Masukkan Kode Lokasi Tujuan : "; cin >> tujuan;

    if (asal >= 0 && asal < MAX_GEDUNG && tujuan >= 0 && tujuan < MAX_GEDUNG) {
        hitungDijkstra(asal, tujuan);
    } else {
        cout << "\n[Error] Kode lokasi yang Anda masukkan tidak valid!" << endl;
    }
}


// ==============================================================
// 5. FUNGSI UI MENU UTAMA & INTEGRASI (Oleh: Muhammad Nur Faaiz)
// ==============================================================
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