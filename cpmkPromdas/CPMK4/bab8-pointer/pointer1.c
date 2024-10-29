// soal nomor 1
#include <stdio.h>

int main()
{
    char huruf[11] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char *ptr = huruf;
    int length = sizeof(huruf) / sizeof(huruf[0]);

    printf("\nmenampilkan array menggunakan pointer: ");
    for (int i = 0; i < length; i++)
    {
        printf("%c ", *(ptr + i));
    }
    printf("\n\n");
    return 0;
}