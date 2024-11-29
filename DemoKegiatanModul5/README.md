# 📘 Program Data Nilai Mahasiswa

### 🎯 Deskripsi

Selamat datang di **Program Data Nilai Mahasiswa**! 🎉 Program ini dirancang khusus untuk membantu kalian, para mahasiswa, mengelola dan menganalisis data nilai. Dengan program ini, kamu bisa:

- Memasukkan nama dan nilai mahasiswa untuk tiga mata pelajaran: **Matematika**, **Fisika**, dan **Kimia**.
- Melihat data mahasiswa dalam urutan alfabet.
- Mengetahui rata-rata nilai per mata pelajaran dan rata-rata keseluruhan.

Sederhana, mudah digunakan, dan pastinya membantu banget untuk belajar coding C sambil mempraktikkan logika pemrograman! 🚀

---

### 🌟 Fitur Utama

1. **Validasi Nama**  
   Pastikan nama mahasiswa hanya berisi huruf dan spasi. Kalau salah, tenang aja, program kasih tahu kok!
2. **Validasi Nilai**  
   Nilai yang dimasukkan harus angka antara **0-100**. Program nggak bakal biarkan kamu salah input.
3. **Statistik Nilai**
   - Rata-rata nilai **Matematika**, **Fisika**, dan **Kimia**.
   - Rata-rata keseluruhan nilai mahasiswa.
4. **Data Berurut**  
   Nama mahasiswa akan diurutkan otomatis berdasarkan alfabet.
5. **Tampilan Tabel Menarik**  
   Data disajikan dalam tabel rapi dan berwarna untuk memudahkan pembacaan.

---

### 🔧 Cara Menggunakan

#### 1. **Persiapan**

- Pastikan komputer kamu sudah terinstal **GCC** (GNU Compiler Collection). Biasanya sudah ada kalau kamu pakai Linux atau macOS. Kalau pakai Windows, bisa instal **MinGW**.

#### 2. **Kompilasi Program**

- Gunakan perintah ini untuk memulai:
  ```bash
  make
  ```

#### 3. **Jalankan Program**

- Setelah kompilasi selesai, cukup ketik:
  ```bash
  make run
  ```

#### 4. **Membersihkan File Hasil Kompilasi**

- Kalau mau hapus file sementara hasil kompilasi, cukup ketik:
  ```bash
  make clean
  ```

---

### 🎓 Contoh Penggunaan

#### **Input:**

```
Masukkan jumlah mahasiswa: 2
Masukkan nama mahasiswa: Surya
Nilai untuk Alice Smith:
Masukkan nilai Matematika untuk Surya (0-100): 88
Masukkan nilai Fisika untuk Surya (0-100): 90
Masukkan nilai Kimia untuk Surya (0-100): 92

Masukkan nama mahasiswa: Chicka
Nilai untuk John Doe:
Masukkan nilai Matematika untuk Chicka (0-100): 85
Masukkan nilai Fisika untuk Chicka (0-100): 87
Masukkan nilai Kimia untuk Chicka (0-100): 89
```

#### **Output:**

```
============================================================================
| Nama Mahasiswa     | Matematika | Fisika     | Kimia      | Rata-rata    |
----------------------------------------------------------------------------
| Chicka             | 85.00      | 87.00      | 89.00      | 90.00        |
| Surya              | 88.00      | 90.00      | .00        | 87.00        |
============================================================================
Rata-rata per mata pelajaran:
  - Matematika: 86.50
  - Fisika    : 88.50
  - Kimia     : 90.50

Rata-rata keseluruhan nilai mahasiswa: 88.50
```

---

### 📂 Struktur Proyek

```plaintext
.
├── Makefile           # File untuk proses kompilasi
├── main.c             # Fungsi utama program
├── utility.c          # Fungsi-fungsi pendukung (helper)
├── utility.h          # Header file untuk utility
├── input.c            # Fungsi untuk menerima input
├── input.h            # Header file untuk input
├── output.c           # Fungsi untuk menampilkan data
├── output.h           # Header file untuk output
├── calculation.c      # Fungsi perhitungan statistik
├── calculation.h      # Header file untuk perhitungan
└── README.md          # Dokumentasi proyek
```

---

### 🧑‍💻 Kenapa Program Ini Penting?

Sebagai mahasiswa, memahami cara kerja program modular seperti ini sangat penting untuk:

- Melatih logika dan pemrograman terstruktur.
- Belajar pemisahan tanggung jawab (modularisasi) dalam kode.
- Menerapkan validasi input untuk menangani kesalahan.

Program ini nggak hanya membantu belajar pemrograman C, tapi juga membiasakan kamu dengan **best practices** dalam pemrograman.

---

### ✍️ Tentang Pengembang

- **Nama**: [suryahipersomniaa](https://www.instagram.com/suryahipersomniaa/)
- **Email**: [LearnWithSuryaa](mailto:davindra514@gmail.com?subject=Feedback%20Program%20Data%20Nilai%20Mahasiswa&body=Halo%20Davindra,%0A%0ASaya%20ingin%20memberikan%20feedback%20tentang%20program%20Data%20Nilai%20Mahasiswa%20yang%20saya%20gunakan.%0A%0A%5BTuliskan%20pesan%20Anda%20di%20sini%5D%0A%0ATerima%20kasih!)
- **Catatan**: Program ini dibuat dengan semangat berbagi ilmu dan mempermudah belajar pemrograman dasar.

---

Semoga program ini bermanfaat dan selamat belajar! 🎉
