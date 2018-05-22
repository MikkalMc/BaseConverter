#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


char** copyArrayOfRange(char* inputArray[], int start, int end)
{
    int i;
    char **result = (char **) malloc((end-start)*sizeof(char*));
    for (i = start; i < end; i) 
    {
        result[i-start] = (char *) malloc(sizeof(char) * strlen(inputArray[i]));
        sprintf(result[i-start], "%s", inputArray[i]);
    }
    return result;
}

char** binaryToDecimal (char* inputArray[], int interval) 
{
    int i;
    int tempNum;
    char ** result = (char**) malloc((interval)*sizeof(char*));
    // printf("testing this shit");
    for (i = 0; i < interval; i+=1)
    {
        tempNum = (int) strtol(inputArray[i], NULL, 2);
        result[i] = (char*) malloc(sizeof(char) * (int) ((ceil(log10(tempNum)/(log10(2)))+1)));
        sprintf(result[i], "%d", (int)tempNum);
    }
    free(inputArray);

    return result;
}

int main(int argc, char *argv[])
{
    char **result;
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

        printf("Starting base %c \n",  startingBase);
        printf("Ending base %c \n", endingBase);

        if(startingBase == 'd') {
            if(endingBase == 'd') {
                printf("return unmutated array");
            }
            else if (endingBase == 'h') {
                printf("dec to hex");
            }
            else if (endingBase == 'b')
            {
                printf("dec to bin");
            }
            else {
                printf("ERROR: Improper base input.\n");
                return 1;
            }
        }

        else if(startingBase == 'h') {
            if (endingBase == 'd')
            {
                printf("return unmutated array");
            }
            else if (endingBase == 'h')
            {
                printf("dec to hex");
            }
            else if (endingBase == 'b')
            {
                printf("dec to bin");
            }
            else
            {
                printf("ERROR: Improper base input.\n");
                return 1;
            }
        }

        else if(startingBase == 'b') {
            if (endingBase == 'd')
            {
                printf("return unmutated array");
            }
            else if (endingBase == 'h')
            {
                printf("dec to hex");
            }
            else if (endingBase == 'b')
            {
                printf("dec to bin");
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

        // result = binaryToDecimal(copyArrayOfRange(argv, 0, argc), argc);
        // for (i = 0; i < argc; i += 1)
        // {
        //     printf("%s ", result[i]);
        // }
        // printf("\n");
        // free(result);
        // return 0;
    }
    // for (i = 1; i < argc; i += 1)
    // {
    //     char *pos = argv[i];
    //     while (*pos != '\0')
    //     {
    //         printf("%c\n", *(pos++));
    //     }
    //     printf("\n");
    // }
}