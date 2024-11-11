#include <stdio.h>
#include <string.h>

int main() {
    char gender[10];
    
    while (1) { // Loop untuk meminta input hingga valid
        printf("Enter gender (Male/Female): ");
        scanf("%s", gender);

        if (strcasecmp(gender, "Male") == 0) {
            printf("%s\n", gender);
            break; // Keluar dari loop jika input valid
        } else if (strcasecmp(gender, "Female") == 0) {
            printf("%s\n", gender);
            break; // Keluar dari loop jika input valid
        } else {
            printf("Invalid input, please enter 'Male' or 'Female'.\n");
        }
    }

    return 0;
}
