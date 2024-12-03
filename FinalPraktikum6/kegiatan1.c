#include <stdio.h>
#include <string.h>

void tambahProduk()
{
    FILE *file = fopen("produk_toko.txt", "a");
    if (file == NULL)
    {
        printf("Gagal membuka file.\n");
        return;
    }

    char id[10], nama[50], kategori[30];
    double harga;
    int stok;

    printf("Masukkan ID Produk: ");
    scanf("%s", id);
    printf("Masukkan Nama Produk: ");
    scanf(" %[^\n]", nama);
    printf("Masukkan Kategori Produk: ");
    scanf(" %[^\n]", kategori);
    printf("Masukkan Harga Produk: ");
    scanf("%lf", &harga);
    printf("Masukkan Stok Produk: ");
    scanf("%d", &stok);

    fprintf(file, "ID       : %s\n", id);
    fprintf(file, "Nama     : %s\n", nama);
    fprintf(file, "Kategori : %s\n", kategori);
    fprintf(file, "Harga    : %.2lf\n", harga);
    fprintf(file, "Stok     : %d\n\n", stok);
    fclose(file);

    printf("Produk berhasil ditambahkan!\n");
}

void tampilkanProduk()
{
    FILE *file = fopen("produk_toko.txt", "r");
    if (file == NULL)
    {
        printf("Belum ada produk yang tersimpan.\n");
        return;
    }

    char buffer[256];
    printf("\nDaftar Produk:\n");
    while (fgets(buffer, sizeof(buffer), file))
    {
        printf("%s", buffer);
    }
    fclose(file);
}

void updateProduk()
{
    char id[10], cariId[10];
    printf("Masukkan ID Produk yang ingin diupdate: ");
    scanf("%s", cariId);

    FILE *file = fopen("produk_toko.txt", "r");
    if (file == NULL)
    {
        printf("Belum ada produk yang tersimpan.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    char buffer[256], nama[50], kategori[30];
    double harga;
    int stok, ditemukan = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        if (sscanf(buffer, "ID       : %s", id) == 1 && strcmp(id, cariId) == 0)
        {
            ditemukan = 1;
            printf("Masukkan Nama baru: ");
            scanf(" %[^\n]", nama);
            printf("Masukkan Kategori baru: ");
            scanf(" %[^\n]", kategori);
            printf("Masukkan Harga baru: ");
            scanf("%lf", &harga);
            printf("Masukkan Stok baru: ");
            scanf("%d", &stok);

            fprintf(temp, "ID       : %s\n", id);
            fprintf(temp, "Nama     : %s\n", nama);
            fprintf(temp, "Kategori : %s\n", kategori);
            fprintf(temp, "Harga    : %.2lf\n", harga);
            fprintf(temp, "Stok     : %d\n\n", stok);

            // mengabaikan 4 baris setekah id
            fgets(buffer, sizeof(buffer), file);
            fgets(buffer, sizeof(buffer), file);
            fgets(buffer, sizeof(buffer), file);
            fgets(buffer, sizeof(buffer), file);
        }
        else
        {
            fputs(buffer, temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove("produk_toko.txt");
    rename("temp.txt", "produk_toko.txt");

    if (ditemukan)
        printf("Produk berhasil diupdate!\n");
    else
        printf("Produk dengan ID '%s' tidak ditemukan.\n", cariId);
}

void hapusProduk()
{
    char id[10], cariId[10];
    printf("Masukkan ID Produk yang ingin dihapus: ");
    scanf("%s", cariId);

    FILE *file = fopen("produk_toko.txt", "r");
    if (file == NULL)
    {
        printf("Belum ada produk yang tersimpan.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    char buffer[256];
    int ditemukan = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        if (sscanf(buffer, "ID       : %s", id) == 1 && strcmp(id, cariId) == 0)
        {
            ditemukan = 1;
            // mengabaikan 4 baris setekah id
            fgets(buffer, sizeof(buffer), file);
            fgets(buffer, sizeof(buffer), file);
            fgets(buffer, sizeof(buffer), file);
            fgets(buffer, sizeof(buffer), file);
        }
        else
        {
            fputs(buffer, temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove("produk_toko.txt");
    rename("temp.txt", "produk_toko.txt");

    if (ditemukan)
        printf("Produk berhasil dihapus!\n");
    else
        printf("Produk dengan ID '%s' tidak ditemukan.\n", cariId);
}

void menu()
{
    int pilihan;
    do
    {
        printf("\n=== Menu Manajemen Produk ===\n");
        printf("1. Tambah Produk Baru\n");
        printf("2. Tampilkan Daftar Produk\n");
        printf("3. Update Produk\n");
        printf("4. Hapus Produk\n");
        printf("5. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            tambahProduk();
            break;
        case 2:
            tampilkanProduk();
            break;
        case 3:
            updateProduk();
            break;
        case 4:
            hapusProduk();
            break;
        case 5:
            printf("Keluar dari program.\n");
            break;
        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 5);
}

int main()
{
    printf("===============================================================\n");
    printf("         Selamat datang di Program Manajemen Produk!\n");
    printf("===============================================================\n");
    menu();
    return 0;
}
