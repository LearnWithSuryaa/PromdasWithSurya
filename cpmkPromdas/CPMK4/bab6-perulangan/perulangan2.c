#include <stdio.h>
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"


// program menampilkan bilangan kelipatan 5 dari 0-100
int main()
{
    int i;
    for (i = 0; i < 100; i++)
    {
        if (i % 5 == 0)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
