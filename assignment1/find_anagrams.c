//
// Created by Nan Wu on 23/02/2020.
//

#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

#define STR_NUM 14
#define MAX_LEN 100
#define CHAR_NUM 26

void count_characters(char inputStrings [STR_NUM][MAX_LEN], int charCount[STR_NUM][CHAR_NUM]);
void Find_anagrams(char array[STR_NUM][MAX_LEN], int charCount[STR_NUM][CHAR_NUM],const char *output_file_path);

void delete_repeat(char add_array[STR_NUM][STR_NUM]);
void valid_print(char array[STR_NUM][MAX_LEN],char add_array[STR_NUM][STR_NUM],const char *output_file_path);

//'main' function in this .c file
void find_anagrams(char inputStrings[STR_NUM][MAX_LEN],const char *output_file_path) {
    int charCount[STR_NUM][CHAR_NUM];
    count_characters(inputStrings, charCount);
    Find_anagrams(inputStrings, charCount,output_file_path);
}

//This function counts the characters in the sentences stored in InputStrings and stores them in the 2D array charCount
void count_characters(char inputStrings [STR_NUM][MAX_LEN], int charCount[STR_NUM][CHAR_NUM])
{
    char lowerString[MAX_LEN];

    //initialize charCount
    for(int i =0; i < STR_NUM; i++)
        for(int j =0;  j< CHAR_NUM; j++)
            charCount[i][j] = 0;

    for(int i =0; i< STR_NUM; i++){
        //converts a string into lower case letters
        toLower(inputStrings[i], lowerString);
        for (int j =0; j < strlen(inputStrings[i]); j++){
            //increments the cell in char count associated with the corresponding character
            switch(lowerString[j]){
                case 'a': charCount[i][0]++;
                    break;
                case 'b': charCount[i][1]++;
                    break;
                case 'c': charCount[i][2]++;
                    break;
                case 'd': charCount[i][3]++;
                    break;
                case 'e': charCount[i][4]++;
                    break;
                case 'f': charCount[i][5]++;
                    break;
                case 'g': charCount[i][6]++;
                    break;
                case 'h': charCount[i][7]++;
                    break;
                case 'i': charCount[i][8]++;
                    break;
                case 'j': charCount[i][9]++;
                    break;
                case 'k': charCount[i][10]++;
                    break;
                case 'l': charCount[i][11]++;
                    break;
                case 'm': charCount[i][12]++;
                    break;
                case 'n': charCount[i][13]++;
                    break;
                case 'o': charCount[i][14]++;
                    break;
                case 'p': charCount[i][15]++;
                    break;
                case 'q': charCount[i][16]++;
                    break;
                case 'r': charCount[i][17]++;
                    break;
                case 's': charCount[i][18]++;
                    break;
                case 't': charCount[i][19]++;
                    break;
                case 'u': charCount[i][20]++;
                    break;
                case 'v': charCount[i][21]++;
                    break;
                case 'w': charCount[i][22]++;
                    break;
                case 'x': charCount[i][23]++;
                    break;
                case 'y': charCount[i][24]++;
                    break;
                case 'z': charCount[i][25]++;
                    break;
                default: break;

            }
        }

    }
}

void Find_anagrams(char array[STR_NUM][MAX_LEN], int charCount[STR_NUM][CHAR_NUM],const char *output_file_path)
{
    char add_array[STR_NUM][STR_NUM] = {0};

    //create a new 2D array called 'add_array', column p of row i and the column p of row j of charCount are added up together, assigning this value to the position of row i and column j of add_array.
    //If this element is not 26, change it to 0.
    //if only this number appear in this row, change this number to 0
    for (int i = 0; i < STR_NUM; i++)
    {
        //if charCount[i][p]==charCount[j][p], add 1 to add_array[i][j]
        for (int j = 0; j < STR_NUM; j++)
        {
            for (int p = 0; p < CHAR_NUM; p++) {
                if (charCount[i][p] == charCount[j][p]) {
                    add_array[i][j]++;
                }
            }

            //If this element is not 26, change it to 0.
            if (add_array[i][j] != CHAR_NUM) {
                add_array[i][j] = 0;
            } else {
                add_array[i][j] = j + 1;
            }
        }

        //if only this number appear in this row, change this number to 0
        int counter = 0;
        for (int j = 0; j < STR_NUM; j++) {
            counter = counter + add_array[i][j];
        }
        if (counter == i + 1) {
            for (int j = 0; j < STR_NUM; j++) {
                add_array[i][j] = 0;
            }
        }
    }

    //delete repeat rows
    delete_repeat(add_array);

    //check same print and print them
    valid_print(array,add_array,output_file_path);
}

//delete repeat rows
void delete_repeat(char add_array[STR_NUM][STR_NUM]) {
    for (int i = 0; i < 13; i++) {
        for (int j = i + 1; j < STR_NUM; j++) {
            for (int p = 0; p < STR_NUM; p++) {
                if (add_array[i][p] == add_array[j][p]) {
                    add_array[j][p] = 0;
                }
            }
        }
    }
}

//check same print and print them
void valid_print(char array[STR_NUM][MAX_LEN],char add_array[STR_NUM][STR_NUM],const char *output_file_path)
{
    FILE *op = fopen(output_file_path,"a+");

    printf("\nQuestion3\n\n");
    fputs("\nQuestion3\n\n",op);

    for (int i = 0; i < STR_NUM; i++)
    {
        bool valid_print=false;
        for (int j = 0; j < STR_NUM; j++)
        {
            if (add_array[i][j] != 0)
            {
                printf("\"%s\" ", array[add_array[i][j] - 1]);
                fprintf(op,"\"%s\" ", array[add_array[i][j] - 1]);
                valid_print=true;
            }
        }
        if (valid_print==true)
        {
            printf("\n");
            fputs("\n",op);
        }
    }
    fclose (op);
}


