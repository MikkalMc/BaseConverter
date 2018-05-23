#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


void printNewArray(char* inputArray[], int range) {
    int i;
    printf("\n");
    for (i = 0; i < range; i += 1)
    {
        printf("%s ", inputArray[i]);
    }
}

int convertDecimalToHex(int x)
{
    int hexadecimal_number, remainder, count = 0;
    for (count = 0; x > 0; count++)
    {
        remainder = x % 16;
        hexadecimal_number = hexadecimal_number + remainder * pow(10, count);
        x = x / 16;
    }
    return hexadecimal_number;
}

int convertDecimalToBinary(int n)
{
    int binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n != 0)
    {
        remainder = n % 2;
        n /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}

char** copyArrayOfRange(char* inputArray[], int start, int end)
{
    int i;
    char **result = (char **) malloc((end-start)*sizeof(char*));
    for (i = start; i < end; i +=1) 
    {
        result[i-start] = (char *) malloc(sizeof(char) * strlen(inputArray[i]));
        sprintf(result[i-start], "%s", inputArray[i]);
    }

    return result;
}

//Something to decimal
char** binaryToDecimal (char* inputArray[], int interval) 
{
    int i;
    int tempNum;
    char ** result = (char**) malloc((interval)*sizeof(char*));
    for (i = 0; i < interval; i+=1)
    {
        tempNum = (int) strtol(inputArray[i], NULL, 2);
        result[i] = (char*) malloc(sizeof(char) * (int) ((ceil(log10(tempNum)/(log10(2)))+1)));
        sprintf(result[i], "%d", (int)tempNum);
    }

    return result;
}

char **hexToDecimal(char *inputArray[], int interval)
{
    int i;
    int tempNum;
    char **result = (char **)malloc((interval) * sizeof(char *));
    for (i = 0; i < interval; i += 1)
    {
        tempNum = (int)strtol(inputArray[i], NULL, 16);
        result[i] = (char *)malloc(sizeof(char) * (int)((ceil(log10(tempNum) / (log10(2))) + 1)));
        sprintf(result[i], "%d", (int)tempNum);
    }

    return result;
}

//Decimal to other
char **decimalToBinary(char *inputArray[], int interval)
{
    int i;
    int charToInt;
    int tempNum;
    char **result = (char **)malloc((interval) * sizeof(char *));

    for (i = 0; i < interval; i += 1)
    {
        charToInt = atoi(inputArray[i]);
        tempNum = convertDecimalToBinary(charToInt);
        result[i] = (char *)malloc(sizeof(char) * (int)((ceil(log10(tempNum) / (log10(2))) + 1)));
        sprintf(result[i], "%d", (int)tempNum);
    }

    return result;
}

char **decimalToHex(char *inputArray[], int interval)
{
    int i;
    int charToInt;
    int tempNum;
    char **result = (char **)malloc((interval) * sizeof(char *));

    for (i = 0; i < interval; i += 1)
    {
        charToInt = atoi(inputArray[i]);
        tempNum = convertDecimalToHex(charToInt);
        result[i] = (char *)malloc(sizeof(char) * (int)((ceil(log10(tempNum) / (log10(2))) + 1)));
        sprintf(result[i], "%d", (int)tempNum);
    }

    return result;
}

int main(int argc, char *argv[])
{
    char **result;
    char **copy;
    int i;

    if (argc < 4)
    {
        printf("ERROR: You need an argument.\n");
        // We are out of here!
        return 1;
    }
    else 
    {
        char startingBase = argv[1][0];
        char endingBase = argv[2][0];
        int printRange = argc - 3;

        printf("Starting base %c \n",  startingBase);
        printf("Ending base %c \n", endingBase);
        printf("Size %i \n", argc);

        if(startingBase == 'd') {
            if(endingBase == 'd') {
                result = copyArrayOfRange(argv, 3, argc);
                printNewArray(result, printRange);
            }
            else if (endingBase == 'h') {
                result = decimalToHex(copyArrayOfRange(argv, 3, argc), printRange);
                printNewArray(result, printRange);
            }
            else if (endingBase == 'b')
            {
                result = decimalToBinary(copyArrayOfRange(argv, 3, argc), printRange);
                printNewArray(result, printRange);
            }
            else {
                printf("ERROR: Improper base input.\n");
                return 1;
            }
        }

        else if(startingBase == 'h') {
            if (endingBase == 'h')
            {
                result = copyArrayOfRange(argv, 3, argc);
                printNewArray(result, printRange);
            }
            else if (endingBase == 'd')
            {
                result = hexToDecimal(copyArrayOfRange(argv, 3, argc), printRange);
                printNewArray(result, printRange);
            }
            else if (endingBase == 'b')
            {
                result = decimalToBinary(hexToDecimal(copyArrayOfRange(argv, 3, argc), printRange), printRange);
                printNewArray(result, printRange);
            }
            else
            {
                printf("ERROR: Improper base input.\n");
                return 1;
            }
        }

        else if(startingBase == 'b') {
            if (endingBase == 'b')
            {
                result = copyArrayOfRange(argv, 3, argc);
                printNewArray(result, printRange);
            }
            else if (endingBase == 'd')
            {
                result = binaryToDecimal(copyArrayOfRange(argv, 3, argc), printRange);
                printNewArray(result, printRange);

            }
            else if (endingBase == 'h')
            {
                result = decimalToHex(binaryToDecimal(copyArrayOfRange(argv, 3, argc), printRange), printRange);
                printNewArray(result, printRange);
            }
            else
            {
                printf("ERROR: Improper base input.\n");
                return 1;
            }
        }
        else
        {
            printf("ERROR: Improper base input.\n");
            return 1;
        }
    }
}