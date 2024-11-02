# Deskripsi Program

Program ini adalah aplikasi **bioskop** berbasis teks yang memungkinkan pengguna memilih film, jenis tiket, hari (weekday atau weekend), dan memanfaatkan diskon jika pengguna adalah member atau membeli tiket pada hari weekday. Program ini dirancang untuk menghitung total harga tiket berdasarkan pilihan film dan jenis tiket, serta menerapkan diskon sesuai dengan kondisi yang berlaku. Pengguna kemudian dapat memasukkan jumlah pembayaran, dan program akan menghitung serta menampilkan kembalian (jika ada) dalam format rupiah yang benar.

## Fitur Utama

1. **Pemilihan Film**:
   Pengguna dapat memilih dari daftar film yang tersedia beserta harga tiket untuk setiap film. Harga tiket bervariasi antara film yang satu dengan yang lainnya.

2. **Pemilihan Jenis Tiket**:
   Pengguna dapat memilih jenis tiket yang diinginkan: *Reguler*, *VIP*, atau *VVIP*, yang memiliki harga berbeda-beda.

3. **Pemilihan Hari**:
   Pengguna memasukkan tanggal pemesanan dalam format DD-MM-YYYY, yang kemudian digunakan untuk menentukan apakah pembelian dilakukan pada weekday atau weekend. Diskon weekday sebesar 15% akan diterapkan secara otomatis jika pemesanan dilakukan pada weekday.

4. **Diskon Member**:
   Jika pengguna adalah member, program akan memberikan diskon tambahan sebesar 10%. Diskon ini berlaku hanya jika pengguna membeli tiket pada weekday.

5. **Pembayaran dan Kembalian**:
   Pengguna akan diminta untuk memasukkan jumlah uang yang dibayarkan. Program kemudian akan menghitung kembalian jika pembayaran melebihi total harga tiket.

6. **Format Rupiah**:
   Harga total dan kembalian akan ditampilkan dalam format rupiah dengan pemisah titik ribuan dan desimal dua digit. Sebagai contoh, angka Rp. 150.000,50 akan ditampilkan dengan format yang benar, yakni `Rp. 150.000,50`.

---

# Penambahan Fitur

1. **Validasi Tanggal**:
   - Program ini memvalidasi apakah tanggal yang dimasukkan pengguna sesuai dengan format DD-MM-YYYY dan apakah merupakan tanggal yang valid (termasuk pengecekan untuk tahun kabisat di bulan Februari).
   
2. **Penentuan Weekday atau Weekend**:
   - Berdasarkan tanggal pemesanan yang dimasukkan, program menghitung hari dalam minggu untuk menentukan apakah diskon weekday (15%) dapat diterapkan.
   
3. **Diskon Member**:
   - Diskon tambahan sebesar 10% diberikan kepada pengguna yang adalah member, tetapi hanya berlaku jika mereka membeli tiket pada weekday. Diskon ini tidak berlaku pada weekend.

4. **Logic Diskon**:
   1. Diskon weekday (15%) akan diterapkan jika pemesanan dilakukan pada hari kerja(senin hingga jumat).
   2. Diskon member (10%) hanya akan diterapkan jika pengguna merupakan member.
   3. Program memeriksa apakah hari termasuk weekend dan mengabaikan diskon member jika pemesanan dilakukan pada Sabtu atau Minggu.

5. **Alamat Memori Total Harga**
   - Di bawah tampilan total harga, program menambahkan informasi mengenai alamat memori dari variabel yang menyimpan nilai total harga:
   ```c
   printf("Alamat memori variabel total: %p\n", (void*)&totalHarga);
   ```
6. Fungsi `hitungHariDariTanggal`
   - Fungsi ini digunakan untuk menghitung hari dalam seminggu dari tanggal yang diberikan. Hari dalam seminggu diwakili oleh angka berikut:
   - 0: Sabtu
   - 1: Minggu
   - 2: Senin
   - 3: Selasa
   - 4: Rabu
   - 5: Kamis
   - 6: Jumat

   ### Parameter:
   - `int hari`: Hari dari tanggal yang ingin dihitung.
   - `int bulan`: Bulan dari tanggal yang ingin dihitung.
   - `int tahun`: Tahun dari tanggal yang ingin dihitung.

   ### Logika:
   1. Jika bulan kurang dari 3, tambahkan 12 ke bulan dan kurangi 2 dari bulan.
   2. Hitung nilai `k` yang merupakan sisa bagi tahun dengan 100.
   3. Hitung nilai `j` yang merupakan hasil bagi tahun dengan 100.
   4. Gunakan rumus untuk menghitung hari dalam seminggu dan kembalikan hasilnya.

   ### Contoh Penggunaan:
   ```c
   int hari = 15;
   int bulan = 10;
   int tahun = 2023;
   int hariDihitung = hitungHariDariTanggal(hari, bulan, tahun);
   ```
7. fungsi `isWeekday` 
   - Fungsi ini digunakan untuk menentukan apakah hari yang dihitung merupakan hari kerja (Senin hingga Jumat).

   ### Parameter:
   - `int h`: Nilai hari yang dihitung oleh fungsi `hitungHariDariTanggal`.

   ### Mengembalikan:
   - `true`: Jika hari merupakan hari kerja (Senin hingga Jumat).
   - `false`: Jika bukan.
   ### Contoh Penggunaan:
   ```c
   if (isWeekday(hariDihitung)) {
      printf("Hari kerja");
    } else {
      printf("Akhir pekan");
   }  
   ```
---

## Penjelasan Format Rupiah

Salah satu fitur penting dari program ini adalah tampilan harga dalam format rupiah yang benar. Untuk memastikan angka ditampilkan dengan pemisah ribuan dan desimal yang sesuai dengan format rupiah, fungsi `formatRupiah()` dirancang untuk:
- **Pemisah Ribuan**: Memasukkan titik (.) sebagai pemisah setiap tiga digit dari belakang untuk mempermudah pembacaan angka besar.
- **Desimal**: Menambahkan dua digit desimal setelah koma untuk menampilkan bagian sen (jika ada).

### Contoh Format:
- **Rp. 150000,5** → **Rp. 150.000,50**
- **Rp. 5000** → **Rp. 5.000,00**

Dengan fungsi ini, angka-angka finansial dapat ditampilkan sesuai standar Indonesia dalam format yang lebih mudah dipahami.

### Code Snippet: Fungsi Format Rupiah

Berikut adalah kode untuk fungsi `formatRupiah()` yang memastikan format rupiah tampil dengan benar:

```c
void formatRupiah(float harga)
{
    int bagianUtama = (int)harga;                           // Ambil bagian utama (sebelum desimal)
    int bagianDesimal = (int)((harga - bagianUtama) * 100); // Ambil bagian desimal
    char buffer[50], formatted[50] = "";                    // Buffer dan string akhir
    int len, count = 0;

    // Ubah bagian utama ke string
    sprintf(buffer, "%d", bagianUtama);
    len = strlen(buffer);

    // Tambahkan pemisah titik setiap tiga digit
    for (int i = len - 1; i >= 0; i--)
    {
        formatted[count++] = buffer[i];
        if ((len - i) % 3 == 0 && i != 0)
            formatted[count++] = '.';
    }
    formatted[count] = '\0';

    // Balik string agar benar
    for (int i = 0; i < count / 2; i++)
    {
        char temp = formatted[i];
        formatted[i] = formatted[count - i - 1];
        formatted[count - i - 1] = temp;
    }

    // Tambahkan desimal di akhir
    printf(GREEN "Rp%s,%02d" RESET, formatted, bagianDesimal);
}
