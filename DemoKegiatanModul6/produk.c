#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produk.h"

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

double validasiHarga()
{
    double harga;
    while (1)
    {
        printf("Masukkan Harga Produk: ");
        if (scanf("%lf", &harga) == 1 && harga >= 0)
        {
            return harga;
        }
        printf("%s%sInput tidak valid. Masukkan angka positif.\n%s", MERAH, TEBAL, RESET);
        clearInputBuffer();
    }
}

int validasiStok()
{
    int stok;
    while (1)
    {
        printf("Masukkan Stok Produk: ");
        if (scanf("%d", &stok) == 1 && stok >= 0)
        {
            return stok;
        }
        printf("%s%sInput tidak valid. Masukkan angka positif.\n%s", MERAH, TEBAL, RESET);
        clearInputBuffer();
    }
}

void tambahProduk()
{
    Produk p;
    printf("Masukkan ID Produk: ");
    scanf("%s", p.id);
    printf("Masukkan Nama Produk: ");
    scanf(" %[^\n]", p.nama);
    printf("Masukkan Kategori Produk: ");
    scanf(" %[^\n]", p.kategori);
    p.harga = validasiHarga();
    p.stok = validasiStok();

    FILE *file = fopen("produk_toko.txt", "a");
    if (file)
    {
        fprintf(file, "%s,%s,%s,%.2lf,%d\n", p.id, p.nama, p.kategori, p.harga, p.stok);
        fclose(file);
        printf("%sProduk berhasil ditambahkan.\n%s", HIJAU, RESET);
    }
    else
    {
        printf("%s%sGagal membuka file.\n%s", MERAH, TEBAL, RESET);
    }
}

void tampilkanProduk()
{
    FILE *file = fopen("produk_toko.txt", "r");
    if (file == NULL)
    {
        printf("%s%sBelum ada produk yang tersimpan.\n%s", MERAH, TEBAL, RESET);
        return;
    }

    printf("+-------------+----------------------+-----------------------+------------+--------+\n");
    printf("| %-11s | %-20s | %-21s | %-10s | %-6s |\n", "ID Produk", "Nama Produk", "Kategori", "Harga", "Stok");
    printf("+-------------+----------------------+-----------------------+------------+--------+\n");

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        Produk p;
        sscanf(line, "%[^,],%[^,],%[^,],%lf,%d", p.id, p.nama, p.kategori, &p.harga, &p.stok);

        printf("| %-11s | %-20s | %-21s | %10.2lf | %6d |\n", p.id, p.nama, p.kategori, p.harga, p.stok);
        printf("+-------------+----------------------+-----------------------+------------+--------+\n");
    }
   
    fclose(file);
}

void updateProduk()
{
    char cariId[10];
    printf("Masukkan ID Produk yang ingin diupdate: ");
    scanf("%s", cariId);

    FILE *file = fopen("produk_toko.txt", "r");
    if (file == NULL)
    {
        printf("%sBelum ada produk yang tersimpan.\n%s", MERAH, RESET);
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        printf("%sGagal membuka file sementara.\n%s", MERAH, RESET);
        fclose(file);
        return;
    }

    char line[256];
    int ditemukan = 0;

    while (fgets(line, sizeof(line), file))
    {
        Produk p;
        sscanf(line, "%[^,],%[^,],%[^,],%lf,%d", p.id, p.nama, p.kategori, &p.harga, &p.stok);

        if (strcmp(p.id, cariId) == 0)
        {
            ditemukan = 1;

            printf("%sProduk ditemukan: \n%s", HIJAU, RESET);
            printf("ID: %s, Nama: %s, Kategori: %s, Harga: %.2lf, Stok: %d\n",
                   p.id, p.nama, p.kategori, p.harga, p.stok);

            printf("\nPilih atribut yang ingin diubah:\n");
            printf("1. Nama\n");
            printf("2. Kategori\n");
            printf("3. Harga\n");
            printf("4. Stok\n");
            printf("5. Semua\n");
            printf("6. Batal\n");
            printf("Pilih opsi (1-6): ");

            int pilihan;
            scanf("%d", &pilihan);

            switch (pilihan)
            {
            case 1:
                printf("Masukkan Nama baru: ");
                scanf(" %[^\n]", p.nama);
                break;
            case 2:
                printf("Masukkan Kategori baru: ");
                scanf(" %[^\n]", p.kategori);
                break;
            case 3:
                p.harga = validasiHarga();
                break;
            case 4:
                p.stok = validasiStok();
                break;
            case 5:
                printf("Masukkan Nama baru: ");
                scanf(" %[^\n]", p.nama);
                printf("Masukkan Kategori baru: ");
                scanf(" %[^\n]", p.kategori);
                p.harga = validasiHarga();
                p.stok = validasiStok();
                break;
            case 6:
                printf("%sPembatalan update produk.\n%s", HIJAU, RESET);
                fclose(file);
                fclose(temp);
                return;
            default:
                printf("%s%sPilihan tidak valid, update batal.\n%s", MERAH, TEBAL, RESET);
                fclose(file);
                fclose(temp);
                return;
            }
        }

        fprintf(temp, "%s,%s,%s,%.2lf,%d\n", p.id, p.nama, p.kategori, p.harga, p.stok);
    }

    fclose(file);
    fclose(temp);

    remove("produk_toko.txt");
    rename("temp.txt", "produk_toko.txt");

    if (ditemukan)
    {
        printf("%sProduk berhasil diupdate!\n%s", HIJAU, RESET);
    }
    else
    {
        printf("%s%sProduk dengan ID '%s' tidak ditemukan.\n%s", MERAH, TEBAL, cariId, RESET);
    }
}

void hapusProduk()
{
    char cariId[10];
    printf("Masukkan ID Produk yang ingin dihapus: ");
    scanf("%s", cariId);

    FILE *file = fopen("produk_toko.txt", "r");
    if (file == NULL)
    {
        printf("%sBelum ada produk yang tersimpan.\n%s", MERAH, RESET);
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        printf("%sGagal membuka file sementara.\n%s", MERAH, RESET);
        fclose(file);
        return;
    }

    char line[256];
    int ditemukan = 0;

    while (fgets(line, sizeof(line), file))
    {
        Produk p;
        sscanf(line, "%[^,],%[^,],%[^,],%lf,%d", p.id, p.nama, p.kategori, &p.harga, &p.stok);

        if (strcmp(p.id, cariId) == 0)
        {
            ditemukan = 1;
        }
        else
        {
            fprintf(temp, "%s,%s,%s,%.2lf,%d\n", p.id, p.nama, p.kategori, p.harga, p.stok);
        }
    }

    fclose(file);
    fclose(temp);

    remove("produk_toko.txt");
    rename("temp.txt", "produk_toko.txt");

    if (ditemukan)
    {
        printf("%sProduk berhasil dihapus!\n%s", HIJAU, RESET);
    }
    else
    {
        printf("%s%sProduk dengan ID '%s' tidak ditemukan.\n%s", MERAH, TEBAL, cariId, RESET);
    }
}
