#include "input.h"
#include "input.c"
#include "sort.h"
#include "sort.c"
#include "find_anagrams.h"
#include "find_anagrams.c"
#include "missing_anagrams.h"
#include "missing_anagrams.c"

const char *input_file_path = "../input.txt";
const char *output_file_path = "../output.txt";
char string[14][100];

int main() {
    input_file(input_file_path,string,output_file_path);

    sort(string,output_file_path);

    find_anagrams(string,output_file_path);

    missing_anagrams(string,output_file_path);

    return 0;
}
