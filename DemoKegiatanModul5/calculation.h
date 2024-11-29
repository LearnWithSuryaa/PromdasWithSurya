#ifndef CALCULATION_H
#define CALCULATION_H
#define MAX_NAMA 50

void hitungRataRataPerMataPelajaran(int jumlahMahasiswa, float nilai[][3], float *rataMatematika, float *rataFisika, float *rataKimia);
float hitungRataRataKeseluruhan(float rataMatematika, float rataFisika, float rataKimia);
void urutAbjad(char namaMahasiswa[][MAX_NAMA], float nilai[][3], int jumlahMahasiswa);

#endif
