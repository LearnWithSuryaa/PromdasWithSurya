#ifndef PRODUK_H
#define PRODUK_H

#define RESET "\033[0m"
#define MERAH "\033[31m"
#define HIJAU "\033[32m"
#define TEBAL "\033[1m"

typedef struct {
    char id[10];
    char nama[50];
    char kategori[30];
    double harga;
    int stok;
} Produk;

void clearInputBuffer();
void tambahProduk();
void tampilkanProduk();
void updateProduk();
void hapusProduk();
double validasiHarga();
int validasiStok();

#endif
