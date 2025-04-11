#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_BITS 32  // Assuming 32-bit integers

// Logs conversion results into a file with timestamps
void logConversion(const char *entry) {
    FILE *file = fopen("conversion_history.txt", "a");
    if (file != NULL) {
        time_t now = time(NULL);
        fprintf(file, "[%s] %s\n", strtok(ctime(&now), "\n"), entry);
        fclose(file);
    }
}

// Displays the contents of the conversion history file
void viewHistory() {
    FILE *file = fopen("conversion_history.txt", "r");
    if (file == NULL) {
        printf("No history found.\n");
        return;
    }
    printf("\n===== Conversion History =====\n");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    printf("===== End of History =====\n\n");
}

// Converts a decimal number (positive or negative) to binary
void decimalToBinary(int num) {
    unsigned int mask = 1 << (MAX_BITS - 1);
    printf("Binary (%d-bit Two's Complement): ");
    for (int i = 0; i < MAX_BITS; i++) {
        printf("%d", (num & mask) ? 1 : 0);
        mask >>= 1;
    }
    printf("\n");
}

// Decimal to Binary, Octal, Hexadecimal
void decimalToOthers() {
    int dec;
    printf("Enter Decimal number: ");
    scanf("%d", &dec);
    decimalToBinary(dec);
    printf("Octal: %o\n", dec);
    printf("Hexadecimal: %X\n", dec);

    char log[200];
    sprintf(log, "Decimal %d => Binary, Octal, Hexadecimal", dec);
    logConversion(log);
}

// Binary string to decimal
int binaryToDecimal(char *bin) {
    int dec = 0;
    for (int i = 0; bin[i] != '\0'; i++) {
        if (bin[i] != '0' && bin[i] != '1') {
            printf("Invalid binary input.\n");
            return -1;
        }
        dec = dec * 2 + (bin[i] - '0');
    }
    return dec;
}

// Binary to Decimal, Octal, Hexadecimal
void binaryToOthers() {
    char bin[100];
    printf("Enter Binary number: ");
    scanf("%s", bin);
    int dec = binaryToDecimal(bin);
    if (dec == -1) return;

    printf("Decimal: %d\n", dec);
    printf("Octal: %o\n", dec);
    printf("Hexadecimal: %X\n", dec);

    char log[200];
    sprintf(log, "Binary %s => Decimal %d => Octal, Hexadecimal", bin, dec);
    logConversion(log);
}

// Octal to Decimal, Binary, Hexadecimal
void octalToOthers() {
    char oct[100];
    printf("Enter Octal number: ");
    scanf("%s", oct);
    int dec;
    sscanf(oct, "%o", &dec);
    printf("Decimal: %d\n", dec);
    decimalToBinary(dec);
    printf("Hexadecimal: %X\n", dec);

    char log[200];
    sprintf(log, "Octal %s => Decimal %d => Binary, Hexadecimal", oct, dec);
    logConversion(log);
}

// Hexadecimal to Decimal, Binary, Octal
void hexToOthers() {
    char hex[100];
    printf("Enter Hexadecimal number: ");
    scanf("%s", hex);
    int dec;
    sscanf(hex, "%x", &dec);
    printf("Decimal: %d\n", dec);
    decimalToBinary(dec);
    printf("Octal: %o\n", dec);

    char log[200];
    sprintf(log, "Hexadecimal %s => Decimal %d => Binary, Octal", hex, dec);
    logConversion(log);
}

// Display menu
void menu() {
    printf("\n===== Number System Converter =====\n");
    printf("1. Decimal to Binary, Octal, Hexadecimal\n");
    printf("2. Binary to Decimal, Octal, Hexadecimal\n");
    printf("3. Octal to Decimal, Binary, Hexadecimal\n");
    printf("4. Hexadecimal to Decimal, Binary, Octal\n");
    printf("5. View Conversion History\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Main function
int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: decimalToOthers(); break;
            case 2: binaryToOthers(); break;
            case 3: octalToOthers(); break;
            case 4: hexToOthers(); break;
            case 5: viewHistory(); break;
            case 6: printf("\n(Program Exits)\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}


