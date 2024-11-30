#include <stdio.h>

#define RESET "\033[0m"
#define MERAH "\033[31m"
#define HIJAU "\033[32m"
#define TEBAL "\033[1m"

int faktorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * faktorial(n - 1);
}

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int main()
{
    int n1, n2;

    while (1)
    {
        printf("\nMasukkan angka untuk menghitung faktorial: ");
        if (scanf("%d", &n1) != 1)
        {
            printf("%s%sInput tidak valid. Mohon masukkan angka!\n%s", MERAH, TEBAL, RESET);
            clearInputBuffer();
            continue;
        }

        if (n1 <= 0)
        {
            printf("%s%sInput tidak valid. Mohon masukkan angka positif atau lebih dari 0!\n%s", MERAH, TEBAL, RESET);
            continue;
        }

        printf("%sFaktorial dari %d adalah: %d\n%s", HIJAU, n1, faktorial(n1), RESET);
        break;
    }

    while (1)
    {
        printf("Masukkan angka untuk menghasilkan deret Fibonacci: ");
        if (scanf("%d", &n2) != 1)
        {
            printf("%s%sInput tidak valid. Mohon masukkan angka!\n%s", MERAH, TEBAL, RESET);
            clearInputBuffer();
            continue;
        }

        if (n2 <= 0)
        {
            printf("%s%sInput tidak valid. Mohon masukkan angka positif atau lebih dari 0!\n%s", MERAH, TEBAL, RESET);
            continue;
        }

        printf("%sDeret Fibonacci hingga suku ke-%d adalah: %s", HIJAU, n2, RESET);
        for (int i = 0; i < n2; i++)
        {
            printf("%s%d %s", HIJAU, fibonacci(i), RESET);
        }
        printf("\n");
        break;
    }
    return 0;
}
