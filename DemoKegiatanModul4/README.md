# Program Transaksi Keuangan

Program ini memungkinkan pengguna untuk mencatat dan mengelola transaksi keuangan secara sederhana. Program ini terdiri dari beberapa fitur, termasuk menambah transaksi, melihat riwayat transaksi, menghitung rata-rata transaksi, dan lainnya.

## Fitur Utama

1. **Tambah Transaksi**: Mengizinkan pengguna untuk memasukkan transaksi. Transaksi dapat ditambahkan secara berkala hingga pengguna memasukkan angka `0` untuk menyelesaikan input.
2. **Lihat Riwayat Transaksi**: Menampilkan riwayat transaksi yang telah dicatat sebelumnya dalam format yang terformat dengan mata uang Rupiah (Rp).
3. **Hitung Rata-rata Transaksi**: Menghitung rata-rata dari semua transaksi yang telah dicatat.
4. **Atur Batasan Nilai Transaksi**: Memungkinkan pengguna untuk mengatur batas bawah dan batas atas nilai transaksi yang dapat dicatat.
5. **Tampilkan Total Sementara**: Menampilkan total sementara dari semua transaksi yang telah dicatat.
6. **Tampilkan Jumlah Transaksi**: Menampilkan jumlah transaksi yang telah dicatat.
7. **Reset Riwayat Transaksi**: Menghapus semua riwayat transaksi yang telah dicatat.

## Instalasi

Untuk menjalankan program ini, pastikan Anda memiliki **gcc** (GNU Compiler Collection) terinstal di sistem Anda. Anda bisa mengkompilasi dan menjalankan program ini menggunakan Makefile yang telah disediakan.

### Langkah-langkah instalasi:

1. Clone atau download repositori ini ke komputer Anda:

   ```bash
   git clone https://github.com/username/nama-repo.git
   cd nama-repo
   ```
   
2. Buka terminal dan arahkan ke direktori tempat Anda mengunduh program ini.
3. Jalankan perintah berikut untuk mengkompilasi program:

   ```bash
   make
   ```

4. Setelah kompilasi selesai, jalankan program dengan perintah:

   ```bash
   make run
   ```

5. Program akan berjalan di terminal, dan Anda dapat memilih fitur yang diinginkan berdasarkan menu yang ditampilkan.

## Struktur Program

- **main.c**: Program utama yang mengelola interaksi dengan pengguna dan menampilkan menu.
- **fungsi.c**: Menyimpan fungsi-fungsi terkait dengan transaksi, riwayat transaksi, dan lainnya.
- **Makefile**: Menyediakan aturan untuk mengkompilasi dan menjalankan program.

## Cara Penggunaan

Setelah menjalankan program, pengguna akan diberikan menu pilihan fitur, di antaranya:
1. Menambah transaksi keuangan.
2. Melihat riwayat transaksi yang dicatat.
3. Menghitung rata-rata transaksi.
4. Mengatur batasan nilai transaksi.
5. Menampilkan total sementara transaksi.
6. Menampilkan jumlah transaksi yang dicatat.
7. Mereset riwayat transaksi.

Program ini juga menggunakan format mata uang Rupiah (Rp) untuk menampilkan hasil transaksi.

## Pengaturan Batas Transaksi

Batas transaksi default adalah antara **1 dan 10.000**. Pengguna dapat mengubah batasan ini sesuai dengan kebutuhan.

## Kontribusi

Jika Anda ingin berkontribusi pada proyek ini, Anda dapat:
1. Fork repositori ini.
2. Buat perubahan atau penambahan fitur baru.
3. Kirimkan pull request dengan deskripsi perubahan yang telah dilakukan.

## Penulis

- Program ini dibuat oleh [Suryahipersomniaa].
