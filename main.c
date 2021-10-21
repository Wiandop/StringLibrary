#include <stdio.h>
#include "string.h"
#include "tests/tests.h"

/**
 * OUTPUT_LANGUAGE = English
 * PROJECT_NAME = String library
 * PROJECT_NUMBER = 1.0.0
 * PROJECT_BRIEF = A program with the basic functions of the <string.h> library
 * OUTPUT_DIRECTORY = /doc
 */

/**
 * @brief Entry point
 * @detailed Execution of the program
 * starts here.
 * @return Program exit status
 */

int main() {
    char string1[] = "Linux Ubuntu";
    char string2[] = "ux";
    char string3[18];
    char string4[15];
    char searching_symbol = 'U';
    size_t str1_len = sizeof(string1);
    size_t str3_len = sizeof(string3);

    output(string1, string2, string3, string4, str1_len, str3_len, searching_symbol);

    run_all_tests();
    printf("All tests passed!\n");
    return 0;
}
