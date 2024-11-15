#include <stdio.h>
#include "fungsi.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"


int main()
{
    int pilihFitur;

    do
    {
        tampilkanMenu();

        if (scanf("%d", &pilihFitur) != 1)
        {
            printf(RED "\nInput tidak valid. Mohon masukkan angka.\n" RESET);
            clearInputBuffer();
            continue;
        }

        switch (pilihFitur)
        {
        case 1:
            tambahTransaksi();
            break;
        case 2:
            lihatRiwayatTransaksi();
            break;
        case 3:
            hitungRataRataTransaksi();
            break;
        case 4:
            aturBatasTransaksi();
            break;
        case 5:
            tampilkanTotalSementara();
            break;
        case 6:
            tampilkanJumlahTransaksi();
            break;
        case 7:
            resetRiwayatTransaksi();
            break;
        case 0:
            printf(GREEN "\nTerima kasih telah menggunakan program ini!\n" RESET);
            break;
        default:
            printf(RED "\nPilihan tidak valid. Mohon pilih fitur yang ada.\n" RESET);
            break;
        }
    } while (pilihFitur != 0);

    return 0;
}