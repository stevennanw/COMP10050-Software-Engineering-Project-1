//
// Created by Nan Wu on 23/02/2020.
//

#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#define STR_NUM 14
#define MAX_LEN 100

void insertionSort(char inputStrings [STR_NUM][MAX_LEN]);
void printStrings(char inputStrings[STR_NUM][MAX_LEN],const char *output_file_path);

//'main' function in this .c file
void sort(char inputStrings[STR_NUM][MAX_LEN],const char *output_file_path)
{
    insertionSort(inputStrings);
    printStrings(inputStrings,output_file_path);
}

//This function converts inputString in a string having all lowercase letters and copies the result in lowerString
void toLower(char inputString[], char lowerString[]){
    for(int i = 0; i< strlen(inputString); i++){
        // function to lower converts a character in its lower case version
        lowerString[i] = tolower(inputString[i]);
    }
}

// This function sorts an input array using the insertion sort algorithm
void insertionSort(char inputStrings [STR_NUM][MAX_LEN]) {

    char swap[MAX_LEN], lowerString1[MAX_LEN], lowerString2[MAX_LEN];
    for (int i = 1; i < STR_NUM; i++) {
        int j = i;
        // before comparing strings at positions j and j-1
        // it is necessary to convert them into lowercase strings
        toLower(inputStrings[j], lowerString1);
        toLower(inputStrings[j-1], lowerString2);

        while (j > 0 && strcmp(lowerString1, lowerString2) < 0) {
            // swapping of strings is performed using strcpy
            strcpy(swap, inputStrings[j]);
            strcpy(inputStrings[j], inputStrings[j - 1]);
            strcpy(inputStrings[j - 1], swap);
            j--;
            toLower(inputStrings[j], lowerString1);
            toLower(inputStrings[j-1], lowerString2);
        }
    }
}

//This function prints a set of strings provided as input
void printStrings(char inputStrings[STR_NUM][MAX_LEN],const char *output_file_path)
{
    FILE *op = fopen(output_file_path,"a+");

    printf("\nQuestion2\n\n");
    fputs("\nQuestion2\n\n",op);

    printf("The list of ordered strings is:\n");
    fputs("The list of ordered strings is:\n",op);

    for(int i =0; i<STR_NUM; i++)
    {
        printf("%s\n",inputStrings[i]);
        fputs(inputStrings[i],op);
        fputs("\n",op);
    }
    fclose (op);

}