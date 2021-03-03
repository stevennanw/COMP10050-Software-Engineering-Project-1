//
// Created by Nan Wu on 23/02/2020.
//

#include <stdio.h>
#include <strings.h>
#include <ctype.h>

#define STR_NUM 14
#define MAX_LEN 100
#define CHAR_NUM 26

void sample_array(char inputStrings[STR_NUM][MAX_LEN],char sample[STR_NUM][MAX_LEN]);
void delete_ps(char inputStrings[STR_NUM][MAX_LEN]);
void find_missing_anagrams(char inputStrings[STR_NUM][MAX_LEN],char sample[STR_NUM][MAX_LEN],const char *output_file_path) ;

void lettercount(char inputStrings[STR_NUM][MAX_LEN],int letter_count[STR_NUM]);
void tmp_array(char inputStrings[STR_NUM][MAX_LEN],char tmp[STR_NUM][MAX_LEN]);

void characters_count(char inputStrings [STR_NUM][MAX_LEN], int charCount[STR_NUM][CHAR_NUM]);
void ToLower(char inputString[], char lowerString[]);

void compare(int charCount[STR_NUM][CHAR_NUM], int i,char sample[STR_NUM][MAX_LEN],int letter_count[STR_NUM],const char *output_file_path);

//'main' function in this .c file
void missing_anagrams(char inputStrings[STR_NUM][MAX_LEN],const char *output_file_path)
{
    char sample[STR_NUM][MAX_LEN]={0};
    sample_array(inputStrings, sample); //make a copy of inputStrings (including punctuation marks and spaces)

    delete_ps(inputStrings); //delete punctuation marks and space

    printf("The missing anagrams are:\n");

    find_missing_anagrams(inputStrings,sample,output_file_path);
}

//make a copy of original inputStrings (including punctuation marks and spaces)
void sample_array(char inputStrings[STR_NUM][MAX_LEN],char sample[STR_NUM][MAX_LEN]) {
    for(int i=0;i<STR_NUM;i++)
    {
        for(int j=0; j<MAX_LEN;j++)
        {
            sample[i][j]=inputStrings[i][j];
        }
    }
}

//deletes all punctuations marks and spaces of the original strings
void delete_ps(char inputStrings[STR_NUM][MAX_LEN]) {
    for(int i=0;i<STR_NUM;i++)
    {
        for(int j=0;j<MAX_LEN;j++)
        {
            if(inputStrings[i][j]==' '|| inputStrings[i][j]==',' || inputStrings[i][j]=='!')
            {
                for(int p=j; p<MAX_LEN;p++)
                {
                    inputStrings[i][p]=inputStrings[i][p+1];
                }
                j--;
            }

        }
    }
}

void find_missing_anagrams(char inputStrings[STR_NUM][MAX_LEN],char sample[STR_NUM][MAX_LEN],const char *output_file_path) {
    int letter_count[STR_NUM]={0};
    char tmp[STR_NUM][MAX_LEN];

    lettercount(inputStrings, letter_count);

    tmp_array(inputStrings, tmp); //make a copy of inputStrings (no punctuation marks and spaces)

    FILE *op = fopen(output_file_path,"a+");
    printf("\nQuestion4\n\n");
    fputs("\nQuestion4\n\n",op);
    fclose (op);

    for(int num=0;num<STR_NUM;num++)
    {
        for (int p = 0; p < STR_NUM; p++) {
            inputStrings[p][letter_count[num]] = '\0'; //unify the number of elements in all strings
        }

        int charCount[STR_NUM][CHAR_NUM]={0};

        characters_count(inputStrings, charCount); //This function counts the characters in the sentences stored in InputStrings and stores them in the 2D array charCount

        compare(charCount, num, sample, letter_count,output_file_path); //determine if every two strings are anagrams after the number of their elements become the same

        for(int i=0;i<STR_NUM;i++)
        {
            for(int j=0; j<MAX_LEN;j++)
            {
                inputStrings[i][j]=tmp[i][j];
            }
        }
    }
}

//count the total number of letters in each string
void lettercount(char inputStrings[STR_NUM][MAX_LEN],int letter_count[STR_NUM])
{
    for (int i = 0; i < STR_NUM; i++) {
        for (int j = 0; j < MAX_LEN; j++) {
            if ((inputStrings[i][j] >= 'A' && inputStrings[i][j] <= 'Z') ||
                (inputStrings[i][j] >= 'a' && inputStrings[i][j] <= 'z')) {
                letter_count[i]++;
            }

            if (inputStrings[i][j] == '\0') {
                break;
            }
        }
    }
}

//make a copy of inputStrings (no punctuation marks and spaces)
void tmp_array(char inputStrings[STR_NUM][MAX_LEN],char tmp[STR_NUM][MAX_LEN])
{
    for(int i=0;i<STR_NUM;i++)
    {
        for(int j=0; j<MAX_LEN;j++)
        {
            tmp[i][j]=inputStrings[i][j];
        }
    }
}

//This function counts the characters in the sentences stored in InputStrings and stores them in the 2D array charCount
void characters_count(char inputStrings [STR_NUM][MAX_LEN], int charCount[STR_NUM][CHAR_NUM]) {
    char lowerString[MAX_LEN];

    //initialize charCount
    for(int i =0; i < STR_NUM; i++)
        for(int j =0;  j< CHAR_NUM; j++)
            charCount[i][j] = 0;

    for(int i =0; i< STR_NUM; i++){
        //converts a string into lower case letters
        ToLower(inputStrings[i], lowerString);
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

//change the letter to lowercase
void ToLower(char inputString[], char lowerString[]){
    for(int i = 0; i< strlen(inputString); i++){
        // function to lower converts a character in its lower case version
        lowerString[i] = tolower(inputString[i]);
    }
}

//determine if every two strings are anagrams after the number of their elements become the same
void compare(int charCount[STR_NUM][CHAR_NUM], int i,char sample[STR_NUM][MAX_LEN],int letter_count[STR_NUM],const char *output_file_path)
{
    FILE *op = fopen(output_file_path,"a+");
    for(int j=0; j<STR_NUM;j++)
    {
        int counter=0;
        for(int p=0;p<CHAR_NUM;p++)
        {
            if (charCount[i][p] != charCount[j][p])
            {
                counter=1;
                break;
            }
        }
        if(counter==0)
        {
            if(letter_count[i]-letter_count[j]!=0)
            {
                printf("\"%s\" is an anagram of \"%s\" if %d characters removed\n",sample[j],sample[i],letter_count[j]-letter_count[i]);
                fprintf(op,"\"%s\" is an anagram of \"%s\" if %d characters removed\n",sample[j],sample[i],letter_count[j]-letter_count[i]);
            }
        }
    }
    fclose (op);
}