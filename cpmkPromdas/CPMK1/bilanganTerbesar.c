#include <stdio.h>

int main()
{
    int a, b;

    printf("Masukkan nilai a: ");
    scanf("%d", &a);
    printf("Masukkan nilai b: ");
    scanf("%d", &b);

    if (a > b)
    {
        printf("\n%d lebih besar dari %d.\n\n", a, b);
    }
    else if (a < b)
    {
        printf("\n%d lebih kecil dari %d\n\n.", a, b);
    }
    else
    {
        printf("\nKedua nilai yang diinputkan sama\n\n");
    }
    return 0;
}