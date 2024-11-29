#ifndef BIOSKOP_H
#define BIOSKOP_H

#include <stdbool.h>

enum Film
{
    SPIDERMAN,
    BATMAN,
    SUPERMAN,
    AVENGERS,
    JOKER
};

enum JenisTiket
{
    REGULER,
    VIP,
    VVIP
};

extern const int hargaFilm[];
extern const int hargaTiket[];

void header();
void line();
void clearInputBuffer();
bool validasiTanggal(int hari, int bulan, int tahun);
int hitungHariDariTanggal(int hari, int bulan, int tahun);
bool isWeekday(int h);
int pilihFilm();
int pilihTiket();
int pilihMember();
float hitungTotalHarga(int pilihanFilm, int pilihanTiket);
void formatRupiah(float harga);

bool inputTanggal(int *hari, int *bulan, int *tahun);
float applyDiscounts(float totalHarga, int member, int hari, int bulan, int tahun);
void printTotalHarga(float totalHarga);
float inputPembayaran(float totalHarga);
void calculateKembalian(float totalHarga, float pembayaran);

#endif 