#include <stdio.h>
#include <string.h>

#define MAX_NAMA 50

int main()
{
    printf("====================================================================\n");
    printf("                  PROGRAM DATA NILAI MAHASISWA\n");
    printf("====================================================================\n");

    int jumlahMahasiswa;

    printf("Masukkan jumlah mahasiswa: ");
    while (scanf("%d", &jumlahMahasiswa) != 1 || jumlahMahasiswa <= 0)
    {
        printf("Input tidak valid. Harap masukkan bilangan bulat positif!\n");
        while (getchar() != '\n')
            ;
        printf("Masukkan jumlah mahasiswa: ");
    }

    char nama[jumlahMahasiswa][MAX_NAMA];
    float nilai[jumlahMahasiswa][3];

    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        printf("Masukkan nama mahasiswa ke-%d: ", i + 1);
        scanf(" %s", nama[i]);

        printf("Masukkan nilai Matematika untuk %s (0-100): ", nama[i]);
        while (scanf("%f", &nilai[i][0]) != 1 || nilai[i][0] < 0 || nilai[i][0] > 100)
        {
            printf("Input tidak valid. Masukkan nilai antara 0 dan 100!\n");
            while (getchar() != '\n')
                ;
            printf("Masukkan nilai Matematika untuk %s (0-100): ", nama[i]);
        }

        printf("Masukkan nilai Fisika untuk %s (0-100): ", nama[i]);
        while (scanf("%f", &nilai[i][1]) != 1 || nilai[i][1] < 0 || nilai[i][1] > 100)
        {
            printf("Input tidak valid. Masukkan nilai antara 0 dan 100!\n");
            while (getchar() != '\n')
                ;
            printf("Masukkan nilai Fisika untuk %s (0-100): ", nama[i]);
        }

        printf("Masukkan nilai Kimia untuk %s (0-100): ", nama[i]);
        while (scanf("%f", &nilai[i][2]) != 1 || nilai[i][2] < 0 || nilai[i][2] > 100)
        {
            printf("Input tidak valid. Masukkan nilai antara 0 dan 100!\n");
            while (getchar() != '\n')
                ;
            printf("Masukkan nilai Kimia untuk %s (0-100): ", nama[i]);
        }
        printf("\n");
    }

    for (int i = 0; i < jumlahMahasiswa - 1; i++)
    {
        for (int j = i + 1; j < jumlahMahasiswa; j++)
        {
            if (strcmp(nama[i], nama[j]) > 0)
            {
                // Menukar nama
                char tempNama[MAX_NAMA];
                strcpy(tempNama, nama[i]);
                strcpy(nama[i], nama[j]);
                strcpy(nama[j], tempNama);

                // Menukar nilai
                float tempNilai[3];
                for (int k = 0; k < 3; k++)
                {
                    tempNilai[k] = nilai[i][k];
                    nilai[i][k] = nilai[j][k];
                    nilai[j][k] = tempNilai[k];
                }
            }
        }
    }

    printf("\nHasil Data Mahasiswa:\n");
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        float rataRata = (nilai[i][0] + nilai[i][1] + nilai[i][2]) / 3.0;
        printf("\nNama Mahasiswa: %s\n", nama[i]);
        printf("  - Matematika: %.2f\n", nilai[i][0]);
        printf("  - Fisika    : %.2f\n", nilai[i][1]);
        printf("  - Kimia     : %.2f\n", nilai[i][2]);
        printf("  - Rata-rata : %.2f\n", rataRata);
    }

    float totalMatematika = 0, totalFisika = 0, totalKimia = 0;
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        totalMatematika += nilai[i][0];
        totalFisika += nilai[i][1];
        totalKimia += nilai[i][2];
    }
    float rataMatematika = totalMatematika / jumlahMahasiswa;
    float rataFisika = totalFisika / jumlahMahasiswa;
    float rataKimia = totalKimia / jumlahMahasiswa;
    float rataKeseluruhan = (rataMatematika + rataFisika + rataKimia) / 3.0;

    printf("\nRata-rata per mata pelajaran:\n");
    printf("  - Matematika: %.2f\n", rataMatematika);
    printf("  - Fisika    : %.2f\n", rataFisika);
    printf("  - Kimia     : %.2f\n", rataKimia);
    printf("\nRata-rata keseluruhan nilai mahasiswa: %.2f\n", rataKeseluruhan);

    return 0;
}
