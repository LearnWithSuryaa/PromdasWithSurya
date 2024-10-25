# Program Pembelian Tiket Bioskop

Program ini adalah aplikasi konsol sederhana yang memungkinkan pengguna untuk memilih film, jenis tiket, dan hari tayang, serta menghitung total harga tiket bioskop dengan menerapkan diskon untuk member dan hari tertentu.

## Fitur Utama

1. **Pemilihan Film**: Pengguna dapat memilih dari beberapa film yang tersedia dengan harga yang berbeda.
2. **Pemilihan Jenis Tiket**: Terdapat tiga jenis tiket yang dapat dipilih, yaitu Reguler, VIP, dan VVIP, masing-masing dengan harga yang berbeda.
3. **Diskon**: 
   - Diskon 15% untuk pembelian tiket pada hari weekday.
   - Diskon 10% untuk member.
4. **Penghitungan Total Harga**: Total harga dihitung berdasarkan pilihan film dan jenis tiket, serta diskon yang berlaku.
5. **Pembayaran**: Pengguna diminta untuk memasukkan jumlah uang yang dibayarkan, dan program akan menghitung kembalian jika ada.

## Struktur Program

### Enum

- `enum film`: Menyimpan daftar film yang tersedia.
- `enum jenisTiket`: Menyimpan jenis tiket yang dapat dipilih.

### Fungsi

- `header()`: Menampilkan judul aplikasi.
- `line()`: Menampilkan garis pemisah untuk format tampilan.
- `clearInputBuffer()`: Membersihkan input buffer untuk menghindari kesalahan input.

### Alur Program

1. Menampilkan daftar film dan meminta pengguna untuk memilih salah satu.
2. Menampilkan daftar jenis tiket dan meminta pengguna untuk memilih.
3. Menanyakan hari tayang (weekday atau weekend).
4. Menanyakan apakah pengguna adalah member.
5. Menghitung total harga berdasarkan pilihan dan diskon yang berlaku.
6. Meminta pengguna untuk memasukkan jumlah uang yang dibayarkan dan menghitung kembalian jika diperlukan.

## Contoh Penggunaan

```
----------------------------------- Bioskop -----------------------------------
Pilih film:
1. Spiderman - Rp.50000
2. Batman - Rp.55000
3. Superman - Rp.60000
4. Avengers - Rp.70000
5. Joker - Rp.45000
Masukkan pilihan Anda (1-5): 
```

Pengguna akan mengikuti langkah-langkah di atas untuk menyelesaikan pembelian tiket bioskop.

## Penutup

Program ini adalah contoh penggunaan struktur kontrol, fungsi, dan enum dalam bahasa pemrograman C untuk membuat aplikasi interaktif yang sederhana. Anda dapat mengembangkan lebih lanjut dengan menambahkan fitur tambahan sesuai kebutuhan.
