// soal nomor 5
#include <stdio.h>

int main()
{
    int num[51];
    int i;
    for (i = 0; i <= 50; i++)
    {
        num[i] = i;
        if (num[i] % 2 != 0)
        {
            printf("%d adalah angka ganjil\n", num[i]);
        }
    }
    return 0;
}