// soal nomor 2
#include <stdio.h>
int main()
{
    int num[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr = num;
    int length = sizeof(num) / sizeof(num[0]);

    printf("\nMenampilkan array menggunakan pointer: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n\n");
    return 0;
}