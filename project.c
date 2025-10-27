#include <stdio.h>
#include <math.h> // Required for pow() function
#include <stdlib.h> // For strtol

// Function to convert and print decimal to binary
void printBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    int binaryNum[32]; // Assuming 32-bit integer
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

int hexa() {
    char hexInput[20]; // To store the hexadecimal input as a string
    long int decimalNum;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hexInput);

    // Convert hexadecimal string to decimal using strtol
    decimalNum = strtol(hexInput, NULL, 16);

    printf("Decimal: %ld\n", decimalNum);
    printf("Octal: %lo\n", decimalNum); // %lo for long octal
    printf("Binary: ");
    printBinary(decimalNum);
    printf("\n");

    return 0;
}

// Function to convert octal to decimal
int octalToDecimal(int octalNum) {
    int decimalNum = 0, i = 0;
    while (octalNum != 0) {
        decimalNum += (octalNum % 10) * pow(8, i);
        octalNum /= 10;
        i++;
    }
    return decimalNum;
}

int decimal() {
    int decimalNumber;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Octal: %o\n", decimalNumber);
    printf("Hexadecimal: %x\n", decimalNumber);
    printf("Binary: ");
    printBinary(decimalNumber);
    printf("\n");

    return 0;
}
int octal() {
    int octalInput;

    printf("Enter an octal number: ");
    scanf("%o", &octalInput); // %o reads input as an octal number

    // Print in decimal
    printf("Decimal: %d\n", octalInput);

    // Print in binary (requires custom conversion)
    printf("Binary: ");
    printBinary(octalInput);
    printf("\n");

    // Print in hexadecimal
    printf("Hexadecimal: %x\n", octalInput); // %x prints in hexadecimal

    return 0;
}
int binary() {
    long long binary_num;
    int decimal_num = 0, i = 0, remainder;

    // Input the binary number
    printf("Enter a binary number: ");
    scanf("%lld", &binary_num);

    // Convert binary to decimal
    long long temp_binary = binary_num; // Use a temporary variable for conversion
    while (temp_binary != 0) {
        remainder = temp_binary % 10;
        if (remainder != 0 && remainder != 1) {
            printf("Invalid binary number entered.\n");
            return 1; // Exit with an error code
        }
        decimal_num += remainder * pow(2, i);
        temp_binary /= 10;
        i++;
    }

    // Print the results
    printf("Decimal: %d\n", decimal_num);
    printf("Octal: %o\n", decimal_num);      // %o for octal output
    printf("Hexadecimal: %x\n", decimal_num); // %x for hexadecimal output (lowercase)
    // printf("Hexadecimal (uppercase): %X\n", decimal_num); // %X for uppercase hex

    return 0;
}

void main() {
    int a,b;
    do {
        printf("Enter a Choice :\n");
        printf("1 for Decimal\n");
        printf("2 for Octal\n");
        printf("3 for Binary\n");
        printf("4 for Hexadecimal\n");
        scanf("%d",&a);
        switch(a) {
            case 1:
            decimal();
            break;
            case 2:
            octal();
            break;
            case 3:
            binary();
            break;
            case 4:
            hexa();
            break;
            default:
            printf("Invalid Choice\n");
            break;
        }
        printf("Continue? 1=Yes 2=No\n");
        scanf("%d",&b);
    } while(b!=2);
}