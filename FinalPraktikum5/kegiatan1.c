#include <stdio.h>
#include <string.h>

#define MAKSIMAL_BUAH 10
#define MAKSIMAL_NAMA_BUAH 20

#define RESET "\033[0m"
#define MERAH "\033[31m"
#define HIJAU "\033[32m"
#define KUNING "\033[33m"
#define CYAN "\033[36m"
#define BIRU "\033[34m"

int main() {
    int jumlahBuah = 0;
    char input[10];

    printf(HIJAU "===============================================================\n" RESET);
    printf(HIJAU "            Selamat datang di Program Input Buah!\n" RESET);
    printf(HIJAU "===============================================================\n" RESET);

    while (1) {
        int valid = 1;

        printf(KUNING "Berapa banyak buah yang ingin Anda masukkan? (maksimal %d): " RESET, MAKSIMAL_BUAH);
        scanf("%s", input);

        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] < '0' || input[i] > '9') {
                valid = 0;
                break;
            }
        }

        if (valid) {
            jumlahBuah = 0;
            for (int i = 0; input[i] != '\0'; i++) {
                jumlahBuah = jumlahBuah * 10 + (input[i] - '0'); 
            }

            if (jumlahBuah > MAKSIMAL_BUAH) {
                printf(MERAH "===============================================================\n" RESET);
                printf(MERAH "PERINGATAN: Anda hanya dapat memasukkan maksimal %d buah.\n" RESET, MAKSIMAL_BUAH);
                jumlahBuah = MAKSIMAL_BUAH;
                break;
            } else if (jumlahBuah <= 0) {
                printf(MERAH "===============================================================\n" RESET);
                printf(MERAH "PERINGATAN: Jumlah buah harus lebih dari 0.\n" RESET);
            } else {
                break;
            }
        } else {
            printf(MERAH "===============================================================\n" RESET);
            printf(MERAH "ERROR: Masukkan angka yang valid!\n\a" RESET);
            printf(MERAH "===============================================================\n" RESET);
        }
    }

    char namaBuah[MAKSIMAL_BUAH][MAKSIMAL_NAMA_BUAH];
    printf(CYAN "===============================================================\n" RESET);
    printf(CYAN "Silakan masukkan nama buah:\n" RESET);
    for (int i = 0; i < jumlahBuah; i++) {
        while (1) {
            printf(BIRU "  - Nama buah ke-%d: " RESET, i + 1);
            scanf(" %s", namaBuah[i]);

            int valid = 1;

            for (int j = 0; namaBuah[i][j] != '\0'; j++) {
                if (!((namaBuah[i][j] >= 'A' && namaBuah[i][j] <= 'Z') ||
                      (namaBuah[i][j] >= 'a' && namaBuah[i][j] <= 'z') ||
                      namaBuah[i][j] == ' ')) {
                    valid = 0;
                    break;
                }
            }

            if (strlen(namaBuah[i]) == 0) {
                printf(MERAH "  ERROR: Nama buah tidak boleh kosong!\n" RESET);
            } else if (strlen(namaBuah[i]) > MAKSIMAL_NAMA_BUAH - 1) {
                printf(MERAH "  ERROR: Nama buah terlalu panjang (maksimal %d karakter)!\n" RESET, MAKSIMAL_NAMA_BUAH - 1);
            } else if (!valid) {
                printf(MERAH "  ERROR: Nama buah hanya boleh berisi huruf dan spasi!\n" RESET);
            } else {
                break;
            }
        }
    }

    printf(HIJAU "===============================================================\n" RESET);
    printf(HIJAU "Berikut daftar buah yang Anda masukkan:\n" RESET);
    for (int i = 0; i < jumlahBuah; i++) {
        printf(KUNING "  %d. %s\n" RESET, i + 1, namaBuah[i]);
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

    printf(CYAN "===============================================================\n" RESET);
    printf(CYAN "Nama buah dalam urutan abjad:\n" RESET);
    for (int i = 0; i < jumlahBuah; i++) {
        printf(KUNING "  %d. %s\n" RESET, i + 1, namaBuah[i]);
    }

    printf(HIJAU "===============================================================\n" RESET);
    printf(HIJAU "         Terima kasih telah menggunakan program ini!\n" RESET);
    printf(HIJAU "===============================================================\n" RESET);

    return 0;
}
