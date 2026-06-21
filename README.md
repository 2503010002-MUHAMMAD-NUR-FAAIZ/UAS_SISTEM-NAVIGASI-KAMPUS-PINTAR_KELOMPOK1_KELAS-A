# Sistem Navigasi Kampus Pintar - Kelompok 1 (Kelas A)

> **Proyek UAS Praktikum Algoritma dan Struktur Data**
> Sebuah aplikasi pusat informasi navigasi terintegrasi berbasis *desktop console* (C++) yang menerapkan kombinasi struktur data linear dan non-linear untuk menyelesaikan masalah efisiensi fasilitas, pelacakan rute, dan otomatisasi layanan di lingkungan Universitas Perjuangan Tasikmalaya.

---

## 👥 Tim Pengembang & Kontribusi Kode (Contributors)

Proyek ini dikembangkan secara kolaboratif menggunakan Git Branching Workflow dengan membagi program ke dalam modul independen yang saling terintegrasi melalui *pointer* dan sinkronisasi data global:

* **Muhammad Nur Faaiz** *(Lead Developer / Project Owner)*
  * **NIM:** 2503010002
  * **Modul:** `Queue` (Sistem Antrean Cerdas Layanan Kampus)
  * **Fungsi Utama:** `enqueueAntrean()`, `dequeueAntrean()`, `tampilkanAntrean()`, `cariRuangan()`, `menuAntreanLayanan()`.
  * **Tanggung Jawab:** Perancangan arsitektur dasar `main.cpp`, pembersihan buffer `cin.ignore()`, utilitas penyeragaman huruf `toLowerManual()`, pencocokan substring `ada()`, serta penanganan fungsi otomatisasi rekomendasi ruangan loket berdasarkan teks keperluan mahasiswa.

* **Mohamad Zidni Ilma** *(Software Engineer 1)*
  * **NIM:** 2503010007
  * **Modul:** `Singly Linked List` (Katalog Inventaris Fasilitas Kampus)
  * **Fungsi Utama:** Struct `NodeFasilitas`, `tambahFasilitas()`, `inisialisasiDataKampus()`, `menuDaftarFasilitas()`.
  * **Tanggung Jawab:** Manajemen alokasi memori dinamis berantai untuk seluruh gedung, penyusunan database spasial internal kampus, serta mengimplementasikan **sinkronisasi otomatis hulu-hilir** di mana setiap elemen yang masuk ke Linked List langsung diumpankan (*feeding*) menjadi objek node pohon BST.

* **Muhammad Frian Erliana** *(Software Engineer 2)*
  * **NIM:** 2503010017
  * **Modul:** `Binary Search Tree (BST)` (Pencarian Informasi Ruangan Kelas)
  * **Fungsi Utama:** Struct `NodeBST`, `insertBST()`, `cariDiBST()`, `menuCariInformasiKelas()`.
  * **Tanggung Jawab:** Penyusunan struktur pohon biner terurut alfabetis untuk memotong kompleksitas pencarian nama ruangan/kelas spesifik (seperti lab atau nomor kelas) menjadi $O(\log n)$, serta menjembatani logika penawaran panduan rute otomatis menuju lokasi jika ruangan ditemukan.

* **Muhammad Husni** *(Software Engineer 3)*
  * **NIM:** 2503010009
  * **Modul:** `Graph` & `Algoritma Dijkstra` (Rute Navigasi Terpendek)
  * **Fungsi Utama:** `cariIndeksGedung()`, `inisialisasiGraph()`, `hitungDijkstra()`, `menuRuteTerpendek()`.
  * **Tanggung Jawab:** Representasi denah fisik 11 titik lokasi kampus ke bentuk matriks ketetanggaan (`adjMatrix`), penanganan nilai tak hingga (`INF = 999999`) pada jalur buntu, pencarian bobot jarak terkecil, penelusuran balik (*backtracking*) via array `parent`, dan rekonstruksi urutan jalan sekuensial.

---

## Fitur Utama & Representasi Struktur Data

| No | Fitur Aplikasi | Struktur Data Terpilih | Algoritma / Prinsip Kerja | Alasan Pemilihan Teknik & Keunggulan |
| :--- | :--- | :--- | :--- | :--- |
| **1** | **Katalog Fasilitas Dinamis** | **Singly Linked List** | *Linear Traversal Insertion* | Bersifat dinamis. Sangat efisien dalam penggunaan memori runtime karena alokasi pointer dibuat saat dibutuhkan, mempermudah ekspansi data gedung baru tanpa batasan ukuran kaku array statis. |
| **2** | **Rekomendasi Rute Terpendek** | **Graph** (Adjacency Matrix) | **Algoritma Dijkstra** | Peta kampus direpresentasikan secara akurat dengan 11 Vertex (Gedung) dan Edge berbobot meter. Dijkstra menjamin penemuan rute tercepat/terpendek secara matematis. |
| **3** | **Cari Cepat Info Kelas** | **Binary Search Tree (BST)** | *Binary Search Lookup* & Rekursif | Membaca sub-ruangan (seperti GS 1A, Lab Komputer, Arsip Skripsi) secara **case-insensitive**. Kecepatan pencarian tetap optimal $O(\log n)$ meskipun ribuan ruangan kelas didaftarkan. |
| **4** | **Sistem Antrean Loket** | **Queue** (Linked Queue Pointer) | Prinsip **FIFO** (*First-In, First-Out*) | Mengelola urutan pelayanan administrasi secara adil. Dilengkapi sistem cerdas pembaca teks keperluan untuk disposisi otomatis ke gedung tujuan. |

---

## 🔗 Sinkronisasi & Inter-Module Integration (Kelebihan Sistem)
Aplikasi ini tidak sekadar menumpuk struktur data terpisah, melainkan mengintegrasikannya dalam satu ekosistem logika:
1. **Linked List ➡️ BST:** Fungsi `tambahFasilitas()` milik Zidni secara otomatis memanggil `insertBST()` milik Frian. Database yang diinisialisasi sekali langsung terpetakan ke dalam dua struktur data berbeda.
2. **BST ➡️ Graph / Dijkstra:** Saat user mencari info kelas via menu BST dan data ditemukan, sistem akan mendeteksi nama gedung terkait, mencari indeks numeriknya melalui `cariIndeksGedung()`, lalu langsung menawarkan opsi *direct-routing* untuk memicu algoritma Dijkstra milik Husni tanpa memaksa user mengetik kode lokasi kembali dari awal.
3. **Queue ⬅️ Utilitas String:** Fungsi `cariRuangan()` bertindak sebagai *parser* pintar yang membaca kata kunci keperluan (misal: "ukt" atau "administrasi" diarahkan otomatis ke Ruang BAAK; "praktikum" diarahkan otomatis ke Laboratorium).

---

## 🗺️ Alur & Arsitektur Menu Utama Aplikasi

Eksekusi program terpusat pada perulangan `do-while` di fungsi `main()` dengan peta fungsionalitas menu sebagai berikut:

* **Menu 1: Daftar Fasilitas** Menampilkan semua katalog induk gedung kampus beserta seluruh daftar sub-ruangan/lantai di dalamnya hasil penelusuran berantai dari `headFasilitas`.
* **Menu 2: Cari Rute Terpendek Antar Lokasi**
  Menampilkan daftar kode 11 lokasi (0 = Gerbang Utama s.d 10 = Gedung Mashudi), menerima input titik asal dan tujuan, kemudian memproses visualisasi arah jalan per meter.
* **Menu 3: Cari Informasi Ruangan Kelas**
  Mesin pencari berbasis pohon biner. Menerima keyword kelas secara bebas, menampilkan lokasi gedung, dan menyediakan fitur panduan navigasi instan.
* **Menu 4: Antrean Layanan**
  Gerbang loket digital yang memuat 3 sub-menu internal: (1) Registrasi nomor antrean baru berbasis pencocokan otomatis keperluan, (2) Panggilan & pemrosesan antrean terdepan, (3) Pemantauan sisa daftar antrean aktif.
* **Menu 5: Keluar**
  Menutup alokasi memori program secara aman dan menyudahi aplikasi.

---

## 💻 Cara Kompilasi dan Menjalankan Program

Aplikasi ini murni menggunakan pustaka standar C++ (`<iostream>` dan `<string>`) tanpa library eksternal khusus, menjamin kompatibilitas tinggi pada OS Windows, Linux, maupun macOS.

1. **Clone Repository:**
   ```bash
   git clone [https://github.com/2503010002-MUHAMMAD-NUR-FAAIZ/UAS_SISTEM-NAVIGASI-KAMPUS-PINTAR_KELOMPOK1_KELAS-A.git](https://github.com/2503010002-MUHAMMAD-NUR-FAAIZ/UAS_SISTEM-NAVIGASI-KAMPUS-PINTAR_KELOMPOK1_KELAS-A.git)
   cd UAS_SISTEM-NAVIGASI-KAMPUS-PINTAR_KELOMPOK1_KELAS-A