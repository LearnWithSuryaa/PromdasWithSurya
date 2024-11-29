#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define RESET "\033[0m"
#define MERAH "\033[31m"
#define HIJAU "\033[32m"
#define CYAN "\033[36m"
#define BIRU "\033[34m"
#define TEBAL "\033[1m"
#define MAX_NAMA 50

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void cetakGaris(const char *warna, const char *karakter, int panjang)
{
    printf("%s", warna);
    for (int i = 0; i < panjang; i++)
    {
        printf("%s", karakter);
    }
    printf("%s\n", RESET);
}

void cetakHeader(const char *judul)
{
    cetakGaris(BIRU, "=", 76);
    printf("%s%s%-40s%s\n", CYAN, TEBAL, judul, RESET);
    cetakGaris(BIRU, "=", 76);
}

int validasiNama(const char *nama)
{
    for (int i = 0; nama[i] != '\0'; i++)
    {
        if (!isalpha(nama[i]) && nama[i] != ' ')
        {
            return 0;
        }
    }
    return 1;
}

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

float hitungRataRataKeseluruhan(int jumlahMahasiswa, float rataMatematika, float rataFisika, float rataKimia)
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
                // Tukar nama
                strcpy(tempNama, namaMahasiswa[i]);
                strcpy(namaMahasiswa[i], namaMahasiswa[j]);
                strcpy(namaMahasiswa[j], tempNama);

                // Tukar nilai
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
        int valid = 0;
        do
        {
            valid = inputNamaMahasiswa(nama[i]);
        } while (!valid);

        printf("Nilai untuk %s:\n", nama[i]);
        nilai[i][0] = validasiInput("Matematika", nama[i]);
        nilai[i][1] = validasiInput("Fisika", nama[i]);
        nilai[i][2] = validasiInput("Kimia", nama[i]);
        printf("\n");
        clearInputBuffer();
    }

    urutAbjad(nama, nilai, jumlahMahasiswa);

    cetakGaris(BIRU, "=", 76);
    printf("| %-20s | %-10s | %-10s | %-10s | %-10s |\n",
           "Nama Mahasiswa", "Matematika", "Fisika", "Kimia", "Rata-rata");
    cetakGaris(BIRU, "-", 76);

    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        float rataRata = (nilai[i][0] + nilai[i][1] + nilai[i][2]) / 3.0;
        printf("| %-20s | %-10.2f | %-10.2f | %-10.2f | %-10.2f |\n",
               nama[i], nilai[i][0], nilai[i][1], nilai[i][2], rataRata);
    }

    cetakGaris(BIRU, "=", 76);

    float rataMatematika, rataFisika, rataKimia;
    hitungRataRataPerMataPelajaran(jumlahMahasiswa, nilai, &rataMatematika, &rataFisika, &rataKimia);
    float rataRataKeseluruhan = hitungRataRataKeseluruhan(jumlahMahasiswa, rataMatematika, rataFisika, rataKimia);

    printf("%sRata-rata per mata pelajaran:%s\n", HIJAU, RESET);
    printf("  - Matematika: %.2f\n", rataMatematika);
    printf("  - Fisika    : %.2f\n", rataFisika);
    printf("  - Kimia     : %.2f\n", rataKimia);
    printf("\n%sRata-rata keseluruhan nilai mahasiswa: %.2f%s\n", HIJAU, rataRataKeseluruhan, RESET);

    return 0;
}