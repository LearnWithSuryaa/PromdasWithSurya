#ifndef FUNGSI_H
#define FUNGSI_H

#include "utils.h" 

#define MAKSIMAL_BUAH 10
#define MAKSIMAL_NAMA_BUAH 20

void inputNamaBuah(char namaBuah[][MAKSIMAL_NAMA_BUAH], int jumlahBuah);

void tampilkanBuah(const char namaBuah[][MAKSIMAL_NAMA_BUAH], int jumlahBuah);

void urutkanBuah(char namaBuah[][MAKSIMAL_NAMA_BUAH], int jumlahBuah);

#endif
