//
// Created by Nan Wu on 14/02/2020.
//

#include <stdio.h>
#include <string.h>

void input_file(const char *input_file_path, char inputArr[14][100],const char *output_file_path)
{
    //read this array from input file
    FILE *fp = fopen(input_file_path,"r+");
    int lineNum=0;

    if (fp == NULL)
    {
        perror ("Error opening input file");
        lineNum = -1; /* use this as a file not found code */
    }
    else
    {
        while (fgets(inputArr[lineNum], sizeof(inputArr[lineNum]),fp) != NULL)
        {
            char *pos;
            if ((pos=strchr(inputArr[lineNum], '\n')) != NULL)
                *pos = '\0';
            lineNum++;
        }
        fclose (fp);
    }

    //write this array to output file
    FILE *op = fopen(output_file_path,"w+");

    printf("Question 1\n\n");
    fputs("Question 1\n\n",op);

    //print this array
    for(int i =0; i < lineNum; i ++)
    {
        printf("%s\n",inputArr[i]);
        fputs(inputArr[i],op);
        fputs("\n",op);
    }
    fclose (op);
}
