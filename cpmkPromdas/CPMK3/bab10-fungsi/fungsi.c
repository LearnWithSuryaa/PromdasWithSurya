#include <stdio.h>
#include <stdbool.h>

// fungsi menghitung luas lingkaran
float luasLingkaran(float radius)
{
    const float PI = 3.14159;
    return PI * radius * radius;
}

// fungsi membalik array
void tulisMundur(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

// fungsi mencari nilai terbesar
int findMax(int num1, int num2, int num3)
{
    int max = num1;
    if (num2 > max)
    {
        max = num2;
    }

    if (num3 > max)
    {
        max = num3;
    }

    return max;
}

// fungsi menampilkan jam dengan format J:M:D
void tulisJam(int jam, int menit, int detik)
{
    printf("jam %02d:%02d:%02d ", jam, menit, detik);
}

// fungsi bilangan genap = 1
int isEvent(int bilangan)
{
    if (bilangan % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// fungsi bilangan positif
int isPositif(int bilangan)
{
    if (bilangan > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// fungsi mencari karakter pada string
int findPos(char str[], char karakter)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == karakter)
        {
            return i;
        }
        i++;
    }
    return -1;
}

//fungsi menampilkan nilai absolut
int absolut(float nilai)
{
    if (nilai < 0)
    {
        nilai = -nilai;
    }

    printf("Nilai absolut: %.2f", nilai);
}

