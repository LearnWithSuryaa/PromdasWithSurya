#include <stdio.h>
#include "utility.h"

void tampilkanData(char namaMahasiswa[][MAX_NAMA], float nilai[][3], int jumlahMahasiswa, float rataMatematika, float rataFisika, float rataKimia, float rataKeseluruhan)
{
    cetakGaris(BIRU, "=", 76);
    printf("| %-20s | %-10s | %-10s | %-10s | %-10s |\n",
           "Nama Mahasiswa", "Matematika", "Fisika", "Kimia", "Rata-rata");
    cetakGaris(BIRU, "-", 76);

    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        float rataRata = (nilai[i][0] + nilai[i][1] + nilai[i][2]) / 3.0;
        printf("| %-20s | %-10.2f | %-10.2f | %-10.2f | %-10.2f |\n",
               namaMahasiswa[i], nilai[i][0], nilai[i][1], nilai[i][2], rataRata);
    }

    cetakGaris(BIRU, "=", 76);

    printf("%sRata-rata per mata pelajaran:%s\n", HIJAU, RESET);
    printf("  - Matematika: %.2f\n", rataMatematika);
    printf("  - Fisika    : %.2f\n", rataFisika);
    printf("  - Kimia     : %.2f\n", rataKimia);
    printf("\n%sRata-rata keseluruhan nilai mahasiswa: %.2f%s\n", HIJAU, rataKeseluruhan, RESET);
}
