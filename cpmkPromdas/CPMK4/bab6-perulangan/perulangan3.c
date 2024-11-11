#include <stdio.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

int main()
{
    int nilai, loop, total = 0, countPositif = 0;
    char choice;
    do
    {
        do
        {
            printf("Masukkan jumlah angka yang ingin dimasukkan: ");
            scanf("%d", &loop);
            if (loop <= 1)
            {
                printf(RED "Masukkan minimal 2 angka!\n" RESET);
            }
        } while (loop <= 1);

        printf("\n");

        for (int i = 0; i < loop; i++)
        {
            do
            {
                printf("Masukkan nilai ke %d: ", i + 1);
                scanf("%d", &nilai);

                if (nilai > 0)
                {
                    total += nilai;
                    countPositif++;
                }
                else
                {
                    printf(RED "Masukkan nilai positif untuk menjumlahkan.\n" RESET);
                }
            } while (nilai <= 0);
        }

        printf(GREEN "\nTotal penjumlahan: %d\n" RESET, total);

        float rataRata = (float)total / countPositif;
        printf(GREEN "Rata-rata nilai positif: %.2f\n", rataRata);

        do
        {
            printf(BLUE "\nApakah ANda ingin Mengulang Program? (y/n): " RESET);

            while ((getchar()) != '\n')
                ;
            scanf("%c", &choice);

            if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
            {
                printf(RED "\nERROR MASUKKAN INPUT DENGAN BENAR!\n" RESET);
            }
        } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
        
        if (choice != 'y' || choice != 'Y')
        {
            printf("\n");
        }
    } while (choice == 'y' || choice == 'Y');
    printf(GREEN "Program selesai.\n\n" RESET);

    return 0;
}