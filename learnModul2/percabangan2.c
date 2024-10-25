#include <stdio.h>
/*
int main(){
    float tinggiAir;
    printf("masukkan tinggi air: ");
    scanf("%d", &tinggiAir);

    if(tinggiAir <= 500.0){
        printf("Status: AMAN\n");
    }else if(tinggiAir >= 500.1 && tinggiAir <= 600.0){
        printf("Status: WASPADA");
    }else if(tinggiAir >= 600.1 && tinggiAir <= 650.0){
        printf("Status: SIAGA 2");
    }else if(tinggiAir > 650){
        printf("Status: SIAGA 1");
    }

    return 0;
}*/

#include <stdio.h>

int main() {
    char huruf;
    char pilihan;

    do {
        printf("Masukkan huruf: ");
        scanf(" %c", &huruf);  // Mengabaikan karakter newline

        if (huruf == 'q' || huruf == 'Q') {
            printf("Program dihentikan.\n");
            break;  // Keluar dari loop
        }

        // Memeriksa apakah karakter adalah huruf (a-z, A-Z)
        if ((huruf >= 'a' && huruf <= 'z') || (huruf >= 'A' && huruf <= 'Z')) {
            // Memeriksa apakah huruf adalah vokal
            if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o' ||
                huruf == 'A' || huruf == 'I' || huruf == 'U' || huruf == 'E' || huruf == 'O') {
                printf("\n%c adalah huruf vokal.\n\n", huruf);
            } else {
                printf("\n%c adalah huruf konsonan.\n\n", huruf);
            }
        } else {
            printf("\nKarakter yang dimasukkan bukan huruf. Silakan coba lagi.\n");
        }

        printf("Apakah Anda ingin melanjutkan? (y/n): ");
        scanf(" %c", &pilihan);  // Mengabaikan karakter newline
    } while (pilihan == 'y' || pilihan == 'Y');

    return 0;
}
