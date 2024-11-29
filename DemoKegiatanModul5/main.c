#include <stdio.h>
#include "utility.h"
#include "input.h"
#include "output.h"
#include "calculation.h"

int main()
{
    int jumlahMahasiswa;

    cetakHeader("                         PROGRAM DATA NILAI MAHASISWA");

    printf("Masukkan jumlah mahasiswa: ");
    while (scanf("%d", &jumlahMahasiswa) != 1 || jumlahMahasiswa <= 0)
    {
        printf("%s%sInput tidak valid. Harap masukkan bilangan bulat positif!%s\n", MERAH, TEBAL, RESET);
        clearInputBuffer();
        printf("Masukkan jumlah mahasiswa: ");
    }

    printf("\n");
    clearInputBuffer();

    char nama[jumlahMahasiswa][MAX_NAMA];
    float nilai[jumlahMahasiswa][3];

    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        do
        {
            if (inputNamaMahasiswa(nama[i]))
            {
                break;
            }
        } while (1);

        printf("Nilai untuk %s:\n", nama[i]);
        nilai[i][0] = validasiInput("Matematika", nama[i]);
        nilai[i][1] = validasiInput("Fisika", nama[i]);
        nilai[i][2] = validasiInput("Kimia", nama[i]);
        printf("\n");
        clearInputBuffer();
    }

    urutAbjad(nama, nilai, jumlahMahasiswa);

    float rataMatematika, rataFisika, rataKimia;
    hitungRataRataPerMataPelajaran(jumlahMahasiswa, nilai, &rataMatematika, &rataFisika, &rataKimia);
    float rataRataKeseluruhan = hitungRataRataKeseluruhan(rataMatematika, rataFisika, rataKimia);
    tampilkanData(nama, nilai, jumlahMahasiswa, rataMatematika, rataFisika, rataKimia, rataRataKeseluruhan);

    return 0;
}
