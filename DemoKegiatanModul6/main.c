#include <stdio.h>
#include "produk.h"

void menu() {
    int pilihan;
    do {
        printf("\n=== Menu Manajemen Produk ===\n");
        printf("1. Tambah Produk Baru\n");
        printf("2. Tampilkan Daftar Produk\n");
        printf("3. Update Produk\n");
        printf("4. Hapus Produk\n");
        printf("5. Keluar\n");
        printf("Pilih opsi: ");
        if (scanf("%d", &pilihan)!=1)
        {
            printf("%s%sInputan tidak valid. Mohon masukkan angka!\n%s", MERAH, TEBAL, RESET);
            clearInputBuffer();
            continue;
        }

        switch (pilihan) {
        case 1:
            tambahProduk();
            break;
        case 2:
        printf("\n");
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

int main() {
    menu();
    return 0;
}
