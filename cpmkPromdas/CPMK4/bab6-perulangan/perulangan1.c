#include <stdio.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

// program menampilkan "Teknik Informatika YESS" 100x
int main()
{
    int i;
    for (i = 0; i < 100; i++)
    {
        printf(RED "Teknik Informatika YESS" RESET);
    }
    return 0;
}
