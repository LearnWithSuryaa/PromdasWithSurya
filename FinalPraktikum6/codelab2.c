#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET "\033[0m"
#define MERAH "\033[31m"
#define HIJAU "\033[32m"
#define TEBAL "\033[1m"

#define MAX_NAMA 10
#define MAX_NIM 15
#define MAX_PRODI 15

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void truncateString(char *str, int maxLength)
{
    if (strlen(str) > maxLength)
    {
        str[maxLength] = '\0';
    }
}

void tulisDataMahasiswa()
{
    FILE *file = fopen("data_mahasiswa.txt", "a");
    if (file == NULL)
    {
        printf("%s%sGagal membuka file untuk menulis data.%s\n", MERAH, TEBAL, RESET);
        return;
    }

    char nama[100], nim[50], prodi[100];

    printf("Masukkan nama (maksimal %d karakter): ", MAX_NAMA);
    clearInputBuffer();
    fgets(nama, sizeof(nama), stdin);
    nama[strcspn(nama, "\n")] = '\0'; 
    truncateString(nama, MAX_NAMA);

    printf("Masukkan NIM (maksimal %d karakter): ", MAX_NIM);
    fgets(nim, sizeof(nim), stdin);
    nim[strcspn(nim, "\n")] = '\0'; 
    truncateString(nim, MAX_NIM);

    printf("Masukkan Program Studi (maksimal %d karakter): ", MAX_PRODI);
    fgets(prodi, sizeof(prodi), stdin);
    prodi[strcspn(prodi, "\n")] = '\0';
    truncateString(prodi, MAX_PRODI);

    // Header ditambahkan hanya jika file kosong
    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0)
    {
        fprintf(file, "+------------+-----------------+---------------+\n");
        fprintf(file, "|    Nama    |       NIM       | Program Studi |\n");
        fprintf(file, "+------------+-----------------+---------------+\n");
    }

    fprintf(file, "| %-10s | %-13s | %-13s |\n", nama, nim, prodi);
    fprintf(file, "+------------+-----------------+---------------+\n");

    fclose(file);
    printf("%s%sData mahasiswa berhasil ditulis ke file.%s\n", HIJAU, TEBAL, RESET);
}

void bacaDataMahasiswa()
{
    FILE *file = fopen("data_mahasiswa.txt", "r");
    if (file == NULL)
    {
        printf("%s%sGagal membuka file untuk membaca data atau file belum dibuat.%s\n", MERAH, TEBAL, RESET);
        return;
    }

    char buffer[256];
    printf("\n%s%sData Mahasiswa:%s\n", HIJAU, TEBAL, RESET);

    while (fgets(buffer, sizeof(buffer), file))
    {
        printf("%s", buffer);
    }

    fclose(file);
}

int main()
{
    int pilihan;

    while (1)
    {
        printf("\n========= Menu Utama =========\n");
        printf("1. Tulis data mahasiswa\n");
        printf("2. Baca data mahasiswa\n");
        printf("3. Keluar\n");
        printf("Pilih menu: ");

        if (scanf("%d", &pilihan) != 1)
        {
            printf("%s%sInput tidak valid. Masukkan angka!%s\n", MERAH, TEBAL, RESET);
            clearInputBuffer();
            continue;
        }

        switch (pilihan)
        {
        case 1:
            tulisDataMahasiswa();
            break;

        case 2:
            bacaDataMahasiswa();
            break;

        case 3:
            printf("%s%sKeluar dari program.%s\n", HIJAU, TEBAL, RESET);
            exit(0);

        default:
            printf("%s%sPilihan tidak valid. Silakan coba lagi.%s\n", MERAH, TEBAL, RESET);
            break;
        }
    }
}
