#include <stdio.h>
#include <string.h>

int main()
{
    int jumlahMahasiswa;

    printf("Masukkan jumlah mahasiswa: ");
    while (scanf("%d", &jumlahMahasiswa) != 1 || jumlahMahasiswa <= 0)
    {
        printf("Input tidak valid. Harap masukkan bilangan bulat positif!\n");
        while (getchar() != '\n')
            ;
        printf("Masukkan jumlah mahasiswa: ");
    }

    float nilai[jumlahMahasiswa][3];
    float totalMatematika = 0, totalFisika = 0, totalKimia = 0;

    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        printf("Masukkan nilai untuk mahasiswa ke-%d (Matematika, Fisika, Kimia): ", i + 1);
        while (scanf("%f %f %f", &nilai[i][0], &nilai[i][1], &nilai[i][2]) != 3 || 
               nilai[i][0] < 0 || nilai[i][0] > 100 || 
               nilai[i][1] < 0 || nilai[i][1] > 100 || 
               nilai[i][2] < 0 || nilai[i][2] > 100)
        {
            printf("Input tidak valid. Masukkan nilai antara 0 dan 100 (pisahkan dengan spasi)!\n");
            while (getchar() != '\n')
                ;
            printf("Masukkan nilai untuk mahasiswa ke-%d (Matematika, Fisika, Kimia): ", i + 1);
        }

        totalMatematika += nilai[i][0];
        totalFisika += nilai[i][1];
        totalKimia += nilai[i][2];
    }

    // Tampilkan nilai setiap mahasiswa
    printf("\nData Nilai Ujian:\n");
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        printf("Mhs %-2d       %.2f       %.2f       %.2f\n", i + 1, nilai[i][0], nilai[i][1], nilai[i][2]);
    }

    // Hitung rata-rata
    float rataMatematika = totalMatematika / jumlahMahasiswa;
    float rataFisika = totalFisika / jumlahMahasiswa;
    float rataKimia = totalKimia / jumlahMahasiswa;
    float rataKeseluruhan = (rataMatematika + rataFisika + rataKimia) / 3.0;

    // Tampilkan rata-rata
    printf("\nRata-rata Nilai:\n");
    printf("Matematika: %.2f\n", rataMatematika);
    printf("Fisika    : %.2f\n", rataFisika);
    printf("Kimia     : %.2f\n", rataKimia);
    printf("Rata-rata Keseluruhan: %.2f\n", rataKeseluruhan);

    return 0;
}
