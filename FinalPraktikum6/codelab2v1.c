#include <stdio.h>
#include <string.h>

#define MAX_NAMA 10
#define MAX_NIM 15
#define MAX_PRODI 15

void clearInputBuffer()
{
    while (getchar() != '\n'); 
}

void potongString(char *str, int maxLength)
{
    if (strlen(str) > maxLength)
    {
        str[maxLength] = '\0'; 
    }
}

int hitungDataMahasiswa()
{
    FILE *file = fopen("data_mahasiswa.txt", "r");
    if (file == NULL)
    {
        return 0;
    }

    int count = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file))
    {
        if (strstr(buffer, "Data mahasiswa ke-") != NULL)
        {
            count++;
        }
    }

    fclose(file);
    return count;
}

void tulisDataMahasiswa()
{
    FILE *file = fopen("data_mahasiswa.txt", "a");
    if (file == NULL)
    {
        printf("Gagal membuka file untuk menulis data.\n");
        return;
    }

    char nama[100], nim[50], prodi[100];
    int count = hitungDataMahasiswa();

    printf("Masukkan nama (maksimal %d karakter): ", MAX_NAMA);
    clearInputBuffer(); 
    fgets(nama, sizeof(nama), stdin);
    nama[strcspn(nama, "\n")] = '\0'; 
    potongString(nama, MAX_NAMA);

    printf("Masukkan NIM (maksimal %d karakter): ", MAX_NIM);
    fgets(nim, sizeof(nim), stdin);
    nim[strcspn(nim, "\n")] = '\0';
    potongString(nim, MAX_NIM);

    printf("Masukkan Program Studi (maksimal %d karakter): ", MAX_PRODI);
    fgets(prodi, sizeof(prodi), stdin);
    prodi[strcspn(prodi, "\n")] = '\0';
    potongString(prodi, MAX_PRODI);

    fprintf(file, "Data mahasiswa ke-%d\n", count + 1);
    fprintf(file, "Nama        : %s\n", nama);
    fprintf(file, "NIM         : %s\n", nim);
    fprintf(file, "Program Studi: %s\n\n", prodi);

    fclose(file);
    printf("Data mahasiswa berhasil ditulis ke file.\n");
}

void bacaDataMahasiswa()
{
    FILE *file = fopen("data_mahasiswa.txt", "r");
    if (file == NULL)
    {
        printf("File belum dibuat atau gagal dibuka.\n");
        return;
    }

    char buffer[256];

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
            printf("Input tidak valid. Masukkan angka!\n");
            clearInputBuffer();
            continue;
        }

        if (pilihan == 1)
        {
            tulisDataMahasiswa();
        }
        else if (pilihan == 2)
        {
            bacaDataMahasiswa();
        }
        else if (pilihan == 3)
        {
            printf("Keluar dari program.\n");
            break;
        }
        else
        {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    return 0;
}