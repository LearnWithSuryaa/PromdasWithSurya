#include <stdio.h>
#include <string.h>

int main()
{
    char students[5][2][10] = {
        {"Alice", "85"},
        {"Bob", "90"},
        {"Charlie", "78"},
        {"David", "92"},
        {"Eva", "88"},
    };

    printf("\nDaftar Nama dan Nilai Sebelum Diubah:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s: %s\n", students[i][0], students[i][1]);
    }

    strcpy(students[3][1], "95");

    printf("\nDaftar Nama dan Nilai Setelah Diubah:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s: %s\n", students[i][0], students[i][1]);
    }

    return 0;
}
