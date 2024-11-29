#include <string.h>
#include "utility.h"

void hitungRataRataPerMataPelajaran(int jumlahMahasiswa, float nilai[][3], float *rataMatematika, float *rataFisika, float *rataKimia)
{
    *rataMatematika = 0;
    *rataFisika = 0;
    *rataKimia = 0;

    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        *rataMatematika += nilai[i][0];
        *rataFisika += nilai[i][1];
        *rataKimia += nilai[i][2];
    }

    *rataMatematika /= jumlahMahasiswa;
    *rataFisika /= jumlahMahasiswa;
    *rataKimia /= jumlahMahasiswa;
}

float hitungRataRataKeseluruhan(float rataMatematika, float rataFisika, float rataKimia)
{
    return (rataMatematika + rataFisika + rataKimia) / 3.0;
}

void urutAbjad(char namaMahasiswa[][MAX_NAMA], float nilai[][3], int jumlahMahasiswa)
{
    char tempNama[MAX_NAMA];
    float tempNilai[3];

    for (int i = 0; i < jumlahMahasiswa - 1; i++)
    {
        for (int j = i + 1; j < jumlahMahasiswa; j++)
        {
            if (strcmp(namaMahasiswa[i], namaMahasiswa[j]) > 0)
            {
                strcpy(tempNama, namaMahasiswa[i]);
                strcpy(namaMahasiswa[i], namaMahasiswa[j]);
                strcpy(namaMahasiswa[j], tempNama);

                for (int k = 0; k < 3; k++)
                {
                    tempNilai[k] = nilai[i][k];
                    nilai[i][k] = nilai[j][k];
                    nilai[j][k] = tempNilai[k];
                }
            }
        }
    }
}
