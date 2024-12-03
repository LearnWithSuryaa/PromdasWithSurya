#include <stdio.h>
#include <string.h>

#define MAKSIMAL_BUAH 10
#define MAKSIMAL_NAMA_BUAH 20

int main() {
    int jumlahBuah = 0;
    char namaBuah[MAKSIMAL_BUAH][MAKSIMAL_NAMA_BUAH];

    printf("===============================================================\n");
    printf("            Selamat datang di Program Input Buah!\n");
    printf("===============================================================\n");

    while (1) {
        printf("Berapa banyak buah yang ingin Anda masukkan? (maksimal %d): ", MAKSIMAL_BUAH);
        scanf("%d", &jumlahBuah);

        if (jumlahBuah > 0 && jumlahBuah <= MAKSIMAL_BUAH) {
            break;
        } else if (jumlahBuah > MAKSIMAL_BUAH) {
            printf("PERINGATAN: Anda hanya dapat memasukkan maksimal %d buah.\n", MAKSIMAL_BUAH);
        } else {
            printf("ERROR: Jumlah buah harus lebih dari 0!\n");
        }
    }

    printf("\nSilakan masukkan nama buah:\n");
    for (int i = 0; i < jumlahBuah; i++) {
        while (1) {
            printf("  - Nama buah ke-%d: ", i + 1);
            scanf(" %s", namaBuah[i]); 

            int panjangNama = strlen(namaBuah[i]);
            int valid = 1;

            for (int j = 0; j < panjangNama; j++) {
                if (!((namaBuah[i][j] >= 'A' && namaBuah[i][j] <= 'Z') || 
                      (namaBuah[i][j] >= 'a' && namaBuah[i][j] <= 'z') || 
                      namaBuah[i][j] == ' ')) {
                    valid = 0;
                    break;
                }
            }

            if (panjangNama == 0) {
                printf("ERROR: Nama buah tidak boleh kosong!\n");
            } else if (panjangNama > MAKSIMAL_NAMA_BUAH - 1) {
                printf("ERROR: Nama buah terlalu panjang (maksimal %d karakter)!\n", MAKSIMAL_NAMA_BUAH - 1);
            } else if (!valid) {
                printf("ERROR: Nama buah hanya boleh berisi huruf dan spasi!\n");
            } else {
                break;
            }
        }
    }

    printf("Berikut daftar buah yang Anda masukkan:\n");
    for (int i = 0; i < jumlahBuah; i++) {
        printf("  %d. %s\n", i + 1, namaBuah[i]);
    }

    for (int i = 0; i < jumlahBuah - 1; i++) {
        for (int j = 0; j < jumlahBuah - i - 1; j++) {
            if (strcmp(namaBuah[j], namaBuah[j + 1]) > 0) {
                char temp[MAKSIMAL_NAMA_BUAH];
                strcpy(temp, namaBuah[j]);
                strcpy(namaBuah[j], namaBuah[j + 1]);
                strcpy(namaBuah[j + 1], temp);
            }
        }
    }

    printf("Nama buah dalam urutan abjad:\n");
    for (int i = 0; i < jumlahBuah; i++) {
        printf("  %d. %s\n", i + 1, namaBuah[i]);
    }

    return 0;
}
