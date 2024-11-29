#include <stdio.h>
#include <string.h>
#include "utility.h"
#include "input.h"

float validasiInput(char *namaMataPelajaran, const char *namaMahasiswa)
{
    float nilai;
    int valid = 0;

    do
    {
        printf("Masukkan nilai %s%s%s%s untuk %s%s%s%s (0-100): ",
               CYAN, TEBAL, namaMataPelajaran, RESET,
               BIRU, TEBAL, namaMahasiswa, RESET);
        if (scanf("%f", &nilai) != 1)
        {
            printf("%sInput tidak valid. Harap masukkan angka! %s\n", MERAH, RESET);
            clearInputBuffer();
        }
        else if (nilai < 0 || nilai > 100)
        {
            printf("%s%sNilai harus di antara 0 dan 100!%s\n", MERAH, TEBAL, RESET);
        }
        else
        {
            valid = 1;
        }
    } while (!valid);

    return nilai;
}

int inputNamaMahasiswa(char *nama)
{
    printf("Masukkan nama mahasiswa: ");
    fgets(nama, MAX_NAMA, stdin);
    nama[strcspn(nama, "\n")] = '\0';

    if (!validasiNama(nama))
    {
        printf("%s%sNama hanya boleh berisi huruf dan spasi!%s\n", MERAH, TEBAL, RESET);
        return 0;
    }
    return 1;
}
