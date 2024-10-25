# Proyek Bioskop

Proyek ini adalah simulasi sistem pemesanan tiket bioskop. Program ini memungkinkan pengguna untuk memilih film, jenis tiket, tanggal pemesanan, dan memberikan diskon berdasarkan hari pemesanan dan status member. Program ini ditulis dalam bahasa C dan diatur menggunakan `Makefile`.

## Struktur Proyek

Berikut adalah file-file yang terdapat dalam proyek ini:

1. **main.c** - File utama yang memanggil berbagai fungsi untuk menjalankan logika program.
2. **bioskop.c** - Berisi fungsi-fungsi utama terkait pemesanan tiket bioskop, seperti memilih film, memilih jenis tiket, menghitung harga, serta mengelola diskon dan pembayaran.
3. **fungsi.c** - Berisi fungsi tambahan untuk validasi tanggal, menghitung hari dalam minggu, dan format output uang dalam rupiah.
4. **Makefile** - Berkas yang digunakan untuk mengautomasi proses kompilasi dan build.

## Fitur Program

- Memilih film dari daftar film yang tersedia dengan harga yang telah ditetapkan.
- Memilih jenis tiket (Reguler, VIP, VVIP) dengan harga yang bervariasi.
- Menginput tanggal pemesanan dengan validasi terhadap format dan nilai tanggal.
- Memberikan diskon 15% pada hari kerja (weekdays) dan 10% jika pengguna adalah member.
- Menghitung total harga dengan diskon yang sesuai.
- Menampilkan format harga dengan pemisah ribuan dan desimal.
- Menghitung kembalian berdasarkan jumlah uang yang dibayarkan oleh pengguna.

## Prasyarat

Sebelum menjalankan program, pastikan Anda telah menginstal GCC compiler dan `make` di sistem Anda. Pada sistem berbasis Unix (Linux/macOS), keduanya dapat diinstal menggunakan package manager (misalnya, `brew`, `apt`, atau `yum`).

## Cara Menjalankan Program

1. Clone repository ini ke komputer Anda:
   ```bash
   git clone https://github.com/username/nama-repo.git
   cd nama-repo

2. Untuk membangun dan menjalankan proyek, gunakan perintah berikut:
   ```bash
    make
   ./bioskop

3. Jika Anda ingin membersihkan file objek dan executable, jalankan:
   ```bash
   make clean

## Struktur Proyek
   ```bash
   |-- main.c          # Fungsi main program
   |-- bioskop.c       # Fungsi pemesanan tiket bioskop
   |-- fungsi.c        # Fungsi tambahan
   |-- Makefile        # Berkas untuk mengautomasi build
   |-- README.md       # Penjelasan proyek ini
   ```

## Contoh Output
   ```bash
   ------------------------------------- Bioskop -------------------------------------
   Program simulasi pemesanan tiket bioskop dengan diskon member dan validasi tanggal. 
   -----------------------------------------------------------------------------------
   Pilih film:
   1. Spiderman - Rp.50000
   2. Batman - Rp.55000
   3. Superman - Rp.60000
   4. Avengers - Rp.70000
   5. Joker - Rp.45000
   Masukkan pilihan Anda (1-5): 3
   Pilih jenis tiket:
   1. Reguler - Rp.30000
   2. VIP - Rp.100000
   3. VVIP - Rp.150000
   Masukkan pilihan Anda (1-3): 2
   Apakah Anda member? (1 untuk Ya, 0 untuk Tidak): 1
   Masukkan tanggal pemesanan (format DD-MM-YYYY): 25-10-2024
   -----------------------------------------------------------------------------------
   Diskon weekday 15% berhasil diterapkan!
   Diskon member 10% berhasil diterapkan!
   -----------------------------------------------------------------------------------
   Total harga: Rp102.000,00
   -----------------------------------------------------------------------------------
   Masukkan jumlah uang yang dibayarkan: 150000
   Kembalian Anda: Rp48.000,00
   -----------------------------------------------------------------------------------
   ```

## Lisensi
  Proyek ini dilisensikan di bawah [MIT License](LICENSE). untuk detail lebih lanjut.