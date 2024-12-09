#include <stdio.h>
#include "fungsi.h"
#include "utils.h"

int main()
{
    cetakHeader("                    Selamat Datang di Program Input Buah");

    int jumlahBuah;
    char namaBuah[MAKSIMAL_BUAH][MAKSIMAL_NAMA_BUAH];

    do
    {
        printf("\nBerapa banyak buah yang ingin Anda masukkan? (maksimal %d): ", MAKSIMAL_BUAH);
        scanf("%d", &jumlahBuah);

        if (jumlahBuah <= 0)
        {
            printf("%s%sJumlah harus lebih dari 0.\n%s", MERAH, TEBAL, RESET);
        }

        if (jumlahBuah > MAKSIMAL_BUAH)
        {
            printf("%s%sPeringatan inputan tidak boleh lebih dari %d\n%s", MERAH, TEBAL, MAKSIMAL_BUAH, RESET);
        }

    } while (jumlahBuah <= 0 || jumlahBuah > MAKSIMAL_BUAH);

    inputNamaBuah(namaBuah, jumlahBuah);

    printf("\nDaftar Buah yang Anda masukkan:\n");
    tampilkanBuah(namaBuah, jumlahBuah);

    urutkanBuah(namaBuah, jumlahBuah);

    printf("\nDaftar Buah dalam urutan alfabet:\n");
    tampilkanBuah(namaBuah, jumlahBuah);

    return 0;
}
