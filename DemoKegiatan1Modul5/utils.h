#ifndef UTILS_H
#define UTILS_H

#define MAKSIMAL_NAMA_BUAH 20

#define RESET "\033[0m"
#define MERAH "\033[31m"
#define BIRU "\033[34m"
#define CYAN "\033[36m"
#define TEBAL "\033[1m"

void clearInputBuffer();

void cetakGaris(const char *warna, const char *karakter, int panjang);

void cetakHeader(const char *judul);

int validasiNamaBuah(const char *nama);

void swapStrings(char *str1, char *str2);

#endif
