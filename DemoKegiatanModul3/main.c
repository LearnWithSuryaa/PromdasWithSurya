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

    inputTanggal(&hari, &bulan, &tahun); 
    line();

    totalHarga = applyDiscounts(totalHarga, member, hari, bulan, tahun);

    printTotalHarga(totalHarga);

    float pembayaran = inputPembayaran(totalHarga);

    calculateKembalian(totalHarga, pembayaran);

    return 0;
}