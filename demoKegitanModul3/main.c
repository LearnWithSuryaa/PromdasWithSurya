#include <stdio.h>
#include "bioskop.h"

int main()
{
    header();                                        
    printf("Program simulasi pemesanan tiket bioskop dengan diskon member dan validasi tanggal.\n");                                       
    line(); 

    int film = pilihFilm();                           
    int tiket = pilihTiket();                        
    float totalHarga = hitungTotalHarga(film, tiket); 
    int member = pilihMember();                       
    int hari = 0, bulan = 0, tahun = 0;

    // Input tanggal
    inputTanggal(&hari, &bulan, &tahun); 
    line();

    // Menghitung diskon
    totalHarga = applyDiscounts(totalHarga, member, hari, bulan, tahun);

    // Menampilkan total harga
    printTotalHarga(totalHarga);

    // Input pembayaran
    float pembayaran = inputPembayaran(totalHarga);

    // Menghitung kembalian
    calculateKembalian(totalHarga, pembayaran);

    return 0;
}