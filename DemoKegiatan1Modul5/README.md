# 🍎 **Program Input Nama Buah**

## Deskripsi
Program ini dibuat untuk memungkinkan pengguna memasukkan daftar nama buah dengan validasi input. Nama buah yang dimasukkan akan disimpan, ditampilkan, dan diurutkan secara alfabetis. Program ini menggunakan bahasa pemrograman C dengan pendekatan modular dan pemisahan kode menggunakan file header dan implementasi.

---

## 📂 **Struktur Proyek**

```
ProgramInputNamaBuah/
│
├── main.c                # File utama untuk menjalankan program
├── fungsi.c              # Berisi implementasi fungsi terkait input, validasi, dan manipulasi data
├── fungsi.h              # Header untuk mendeklarasikan fungsi-fungsi dari fungsi.c
├── utils.c               # Berisi fungsi utilitas seperti tampilan dan validasi tambahan
├── utils.h               # Header untuk fungsi utilitas
├── Makefile              # Skrip untuk mengatur kompilasi dan menjalankan proyek
└── README.md             # Dokumentasi proyek
```

---

## 🛠️ **Instalasi dan Persiapan**

### Prasyarat
Pastikan Anda memiliki kompiler C seperti `gcc` yang terinstal di sistem Anda.

### Instalasi
1. Clone atau unduh kode program dari repository jika tersedia.
2. Buka terminal di direktori proyek.
3. Jalankan perintah `make` untuk mengompilasi proyek:

```bash
make
```

### Jalankan Program
Setelah berhasil dikompilasi, jalankan program dengan perintah:

```bash
make run
```

---

## 💻 **Penggunaan**

1. Jalankan program dengan perintah `make run`.
2. Program akan meminta Anda memasukkan jumlah buah yang ingin Anda masukkan (maksimal **10 buah**).
3. Selanjutnya, Anda akan diminta memasukkan nama buah satu per satu.
   - Input hanya valid jika:
     - Nama tidak kosong.
     - Nama tidak melebihi panjang karakter yang diperbolehkan (maksimal **20 karakter**).
     - Nama hanya berisi huruf dan spasi.
4. Setelah semua input selesai, program akan menampilkan daftar nama buah dalam urutan yang sama seperti dimasukkan, lalu mengurutkan daftar nama buah secara alfabetis.
5. Anda akan melihat daftar nama buah yang sudah terurut.

---

## ⚙️ **Fungsi Utama**

### 1. Validasi Input
Program akan memeriksa setiap input nama buah yang Anda masukkan untuk memastikan:
- Tidak kosong.
- Tidak melebihi panjang maksimal.
- Hanya mengandung huruf dan spasi.

### 2. Input Nama Buah
Pengguna dapat memasukkan daftar nama buah melalui prompt yang diberikan.

### 3. Tampilkan Daftar Buah
Program akan menampilkan nama buah dalam dua fase:
1. Daftar seperti inputan awal.
2. Daftar yang sudah diurutkan secara alfabetis.

---

## 🧩 **Fitur**

✅ **Validasi Input:** Memastikan hanya nama buah yang valid yang diterima.  
✅ **Input Nama Buah:** Memungkinkan pengguna memasukkan daftar nama buah.  
✅ **Urutkan Buah:** Nama buah akan diurutkan secara alfabetis setelah semua nama dimasukkan.  
✅ **Modularisasi Kode:** Menggunakan pemisahan kode dengan file header dan implementasi untuk manajemen kode yang lebih rapi dan reusable.

---

## 📜 **Lisensi**

Program ini bersifat open-source dan bebas digunakan untuk belajar dan pengembangan. Jika Anda menggunakannya sebagai referensi, silakan berikan kredit kepada pengembangnya.

---

## ✉️ **Kontak**

Jika Anda memiliki masukan, pertanyaan, atau ingin berkolaborasi, hubungi saya di:

- **Email**: [LearnWithSuryaa](mailto:davindra514@gmail.com?subject=Feedback%20Program%20Data%20Nilai%20Mahasiswa&body=Halo%20Davindra,%0A%0ASaya%20ingin%20memberikan%20feedback%20tentang%20program%Input%20Nama%20Buah%20yang%20saya%20gunakan.%0A%0A%5BTuliskan%20pesan%20Anda%20di%20sini%5D%0A%0ATerima%20kasih!)

---

Selamat menggunakan program ini! 🚀  
Terima kasih sudah menggunakan proyek ini untuk belajar pemrograman C. 😊