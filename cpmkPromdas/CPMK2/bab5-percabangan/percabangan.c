#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// program membandingkan nilai terbesar
/*int main()
{
    int num1, num2;
    printf("\nMasukkan angka pertama: ");
    scanf("%d", &num1);
    printf("Masukkan angka kedua: ");
    scanf("%d", &num2);

    if (num1 > num2)
    {
        printf("Bilangan terbesar adalah: %d\n\n", num1);
    }
    else if (num2 > num1)
    {
        printf("Biangan terbesar adalah: %d\n\n", num2);
    }
    else
    {
        printf("Kedua bilangan sama: %d\n\n", num1);
    }

    return 0;
}*/

// program menentukan saklar ON/OFF
/*int main()
{
  int saklar;
  do
  {
    printf("\nMasukkan Status Saklar (1=ON, 0=OFF): ");
    scanf("%d", &saklar);
    if (saklar == 1)
    {
      printf("ON\n\n");
    }
    else if (saklar == 0)
    {
      printf("OFF\n\n");
    }
    else
    {
      printf("Error input tidak valid, masukkan nilai 1 atau 0\n");
    }
  } while (saklar != 0 && saklar != 1);

  return 0;
}*/

// program menentukan status tinggi air
/*int main(){
    float tinggiAir;
    printf("\nmasukkan tinggi air: ");
    scanf("%f", &tinggiAir);

    if(tinggiAir <= 500.0){
        printf("Status: AMAN\n");
    }else if(tinggiAir >= 500.1 && tinggiAir <= 600.0){
        printf("Status: WASPADA\n");
    }else if(tinggiAir >= 600.1 && tinggiAir <= 650.0){
        printf("Status: SIAGA 2\n");
    }else if(tinggiAir > 650){
        printf("Status: SIAGA 1\n");
    }

    return 0;
}*/

// program menentukan huruf vokal atau konsonan
/*int main() {
    char huruf;
    char pilihan;

    do {
        printf("\nMasukkan huruf: ");
        scanf(" %c", &huruf);

        if (huruf == 'q' || huruf == 'Q') {
            printf("Program dihentikan.\n");
            break;
        }

        if ((huruf >= 'a' && huruf <= 'z') || (huruf >= 'A' && huruf <= 'Z')) {

            if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o' ||
                huruf == 'A' || huruf == 'I' || huruf == 'U' || huruf == 'E' || huruf == 'O') {
                printf("\n%c adalah huruf vokal.\n\n", huruf);
            } else {
                printf("\n%c adalah huruf konsonan.\n\n", huruf);
            }
        } else {
            printf("\nKarakter yang dimasukkan bukan huruf. Silakan coba lagi.\n\n");
        }

        printf("Apakah Anda ingin melanjutkan? (y/n): ");
        scanf(" %c", &pilihan);
    } while (pilihan == 'y' || pilihan == 'Y');

    return 0;
}*/

int main()
{
    char code[5];
    while (1)
    {
        printf("Masukkan 4 karakter: ");
        scanf("%4s", code);

        if (strcasecmp(code, "abcd") == 0)
        {
            printf("Succsessfull process");
            break;
        }
        else
        {
            printf("Masukkan kode lagi!");
            continue;
        }
    }
    return 0;
}