#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Custom itoa replacement (portable across compilers)
void my_itoa(int value, char *str, int base) {
    char *rc, *ptr, *low;
    rc = ptr = str;

    if (value < 0 && base == 10) {
        *ptr++ = '-';
        value = -value;
    }

    low = ptr;

    do {
        *ptr++ = "0123456789ABCDEF"[value % base];
        value /= base;
    } while (value);

    *ptr-- = '\0';
    while (low < ptr) {
        char tmp = *low;
        *low++ = *ptr;
        *ptr-- = tmp;
    }
}

// Function to log conversion to a file
void log_conversion(const char *log) {
    FILE *file = fopen("conversion_history.txt", "a");
    if (file) {
        fprintf(file, "%s\n", log);
        fclose(file);
    }
}

// Validation functions
int is_valid_binary(const char *str) {
    for (int i = 0; str[i]; i++)
        if (str[i] != '0' && str[i] != '1') return 0;
    return 1;
}

int is_valid_octal(const char *str) {
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '7') return 0;
    return 1;
}

int is_valid_hex(const char *str) {
    for (int i = 0; str[i]; i++)
        if (!isxdigit(str[i])) return 0;
    return 1;
}

int binary_to_decimal(const char *binary) {
    int decimal = 0;
    while (*binary) {
        decimal = decimal * 2 + (*binary++ - '0');
    }
    return decimal;
}

int octal_to_decimal(const char *octal) {
    int decimal;
    sscanf(octal, "%o", &decimal);
    return decimal;
}

int hex_to_decimal(const char *hex) {
    int decimal;
    sscanf(hex, "%x", &decimal);
    return decimal;
}

void decimal_to_others(int decimal) {
    char binary[32], octal[32], hex[32];
    my_itoa(decimal, binary, 2);
    my_itoa(decimal, octal, 8);
    my_itoa(decimal, hex, 16);
    printf("Binary: %s\n", binary);
    printf("Octal: %s\n", octal);
    printf("Hexadecimal: %s\n", hex);

    char log[256];
    sprintf(log, "Decimal: %d → Binary: %s, Octal: %s, Hexadecimal: %s", decimal, binary, octal, hex);
    log_conversion(log);
}

void convert_from_binary(const char *binary) {
    if (!is_valid_binary(binary)) {
        printf("Invalid binary number!\n");
        return;
    }

    int decimal = binary_to_decimal(binary);
    printf("Decimal: %d\n", decimal);

    char octal[32], hex[32];
    my_itoa(decimal, octal, 8);
    my_itoa(decimal, hex, 16);
    printf("Octal: %s\n", octal);
    printf("Hexadecimal: %s\n", hex);

    char log[256];
    sprintf(log, "Binary: %s → Decimal: %d, Octal: %s, Hexadecimal: %s", binary, decimal, octal, hex);
    log_conversion(log);
}

void convert_from_octal(const char *octal) {
    if (!is_valid_octal(octal)) {
        printf("Invalid octal number!\n");
        return;
    }

    int decimal = octal_to_decimal(octal);
    printf("Decimal: %d\n", decimal);

    char binary[32], hex[32];
    my_itoa(decimal, binary, 2);
    my_itoa(decimal, hex, 16);
    printf("Binary: %s\n", binary);
    printf("Hexadecimal: %s\n", hex);

    char log[256];
    sprintf(log, "Octal: %s → Decimal: %d, Binary: %s, Hexadecimal: %s", octal, decimal, binary, hex);
    log_conversion(log);
}

void convert_from_hexadecimal(const char *hex) {
    if (!is_valid_hex(hex)) {
        printf("Invalid hexadecimal number!\n");
        return;
    }

    int decimal = hex_to_decimal(hex);
    printf("Decimal: %d\n", decimal);

    char binary[32], octal[32];
    my_itoa(decimal, binary, 2);
    my_itoa(decimal, octal, 8);
    printf("Binary: %s\n", binary);
    printf("Octal: %s\n", octal);

    char log[256];
    sprintf(log, "Hexadecimal: %s → Decimal: %d, Binary: %s, Octal: %s", hex, decimal, binary, octal);
    log_conversion(log);
}

void view_conversion_history() {
    FILE *file = fopen("conversion_history.txt", "r");
    if (!file) {
        printf("No conversion history found.\n");
        return;
    }
    printf("\n====== Conversion History ======\n");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

int main() {
    int choice;
    char input[100];

    do {
        printf("\n===== Number System Converter =====\n");
        printf("1. Decimal to Binary, Octal, Hexadecimal\n");
        printf("2. Binary to Decimal, Octal, Hexadecimal\n");
        printf("3. Octal to Decimal, Binary, Hexadecimal\n");
        printf("4. Hexadecimal to Decimal, Binary, Octal\n");
        printf("5. View Conversion History\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter Decimal number: ");
                scanf("%s", input);
                decimal_to_others(atoi(input));
                break;
            case 2:
                printf("Enter Binary number: ");
                scanf("%s", input);
                convert_from_binary(input);
                break;
            case 3:
                printf("Enter Octal number: ");
                scanf("%s", input);
                convert_from_octal(input);
                break;
            case 4:
                printf("Enter Hexadecimal number: ");
                scanf("%s", input);
                convert_from_hexadecimal(input);
                break;
            case 5:
                view_conversion_history();
                break;
            case 6:
                printf("Program exited successfully.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}



