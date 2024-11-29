#ifndef UTILITY_H
#define UTILITY_H
#define MAX_NAMA 50

#define RESET "\033[0m"
#define MERAH "\033[31m"
#define HIJAU "\033[32m"
#define CYAN "\033[36m"
#define BIRU "\033[34m"
#define TEBAL "\033[1m"

void clearInputBuffer();
void cetakGaris(const char *warna, const char *karakter, int panjang);
void cetakHeader(const char *judul);
int validasiNama(const char *nama);

#endif
