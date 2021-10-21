#ifndef PROJECT_TESTS_H
#define PROJECT_TESTS_H

typedef enum {
    OK,
    ligma
} errors;

int run_all_tests();
errors string_comparison(char* str1, char* str2);
errors test_myStrlen();
errors test_myStrcpy();
errors test_myStrchr();
errors test_myStrdup();
errors test_myStrstr();
errors test_myMemchr();
errors test_myMemcpy();
errors test_myMemset();

#endif
