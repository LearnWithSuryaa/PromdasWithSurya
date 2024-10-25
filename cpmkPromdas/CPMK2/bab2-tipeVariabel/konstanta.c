#include <stdio.h>

int main()
{
    const int MAXSIZE = 225;
    const float PI = 3.14, MIN_KELVIN = 80.8, R = 8.314472;
    const char ROOTDIR = 'C';

    printf("\n%d\n", MAXSIZE);
    printf("%.2f\n", PI);
    printf("%.1f\n", MIN_KELVIN);
    printf("%f\n", R);
    printf("%c\n\n", ROOTDIR);

    return 0;
}
