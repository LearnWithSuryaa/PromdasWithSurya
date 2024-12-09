#include <stdio.h>
#include <string.h>
#include "fungsi.h"
#include "utils.h"

void inputNamaBuah(char namaBuah[][MAKSIMAL_NAMA_BUAH], int jumlahBuah)
{
    for (int i = 0; i < jumlahBuah; i++)
    {
        while (1)
        {
            printf("  - Nama buah ke-%d: ", i + 1);
            scanf(" %s", namaBuah[i]);

            if (strlen(namaBuah[i]) == 0)
            {
                printf("%s%sERROR: Nama buah tidak boleh kosong!\n%s", MERAH, TEBAL, RESET);
            }
            else if (strlen(namaBuah[i]) > MAKSIMAL_NAMA_BUAH - 1)
            {
                printf("%s%sERROR: Nama buah terlalu panjang (maksimal %d karakter)!\n%s", MERAH, TEBAL, MAKSIMAL_NAMA_BUAH - 1, RESET);
            }
            else if (!validasiNamaBuah(namaBuah[i]))
            {
                printf("%s%sERROR: Nama buah hanya boleh berisi huruf dan spasi!\n%s", MERAH, TEBAL, RESET);
            }
            else
            {
                break;
            }
        }
    }
}

void tampilkanBuah(const char namaBuah[][MAKSIMAL_NAMA_BUAH], int jumlahBuah)
{
    for (int i = 0; i < jumlahBuah; i++)
    {
        printf("  %d. %s\n", i + 1, namaBuah[i]);
    }
}

void urutkanBuah(char namaBuah[][MAKSIMAL_NAMA_BUAH], int jumlahBuah)
{
    for (int i = 0; i < jumlahBuah - 1; i++)
    {
        for (int j = 0; j < jumlahBuah - i - 1; j++)
        {
            if (strcmp(namaBuah[j], namaBuah[j + 1]) > 0)
            {
                swapStrings(namaBuah[j], namaBuah[j + 1]);
            }
        }
    }
}
