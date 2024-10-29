#include <stdio.h>
int main()
{
    int num[5];
    int *ptr = num;

    printf("\nMasukkan 5 angka: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("Angka ke-%d: ", i + 1);
        scanf("%d", ptr + i);
    }

    printf("\nAngka yang dimasukkan\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(ptr + i));
    }
    printf("\n\n");
    return 0;
}