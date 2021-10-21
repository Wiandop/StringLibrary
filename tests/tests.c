#include "tests.h"
#include <stdio.h>
#include <assert.h>
#include "../string.h"

int run_all_tests() {
    assert(OK == test_myStrlen());
    assert(OK == test_myStrcpy());
    assert(OK == test_myStrchr());
    assert(OK == test_myStrdup());
    assert(OK == test_myStrstr());
    assert(OK == test_myMemchr());
    assert(OK == test_myMemcpy());
    assert(OK == test_myMemset());
}


errors string_comparison(char* str1, char* str2) {
    if (myStrlen(str1) != myStrlen(str2)) {
        return ligma;
    } else {
        for (int i = 0; i < myStrlen(str1); i++) {
            if (str1[i] != str2[i]) {
                printf("%c %c", str1[i], str2[i]);
                return ligma;
            }
        }
    }

    return OK;
}

// Test myStrlen

errors test_myStrlen() {
    printf("Testing myStrlen(). \n");

    char test_string[] = "Hello";

    if (myStrlen(test_string) != 5) {
        return ligma;
    }

    printf("Testing myStrlen() completed! \n \n");
    return OK;
}


// Test myStrcpy

errors test_myStrcpy() {
    printf("Testing myStrcpy(). \n");

    char test_string1[] = "Hello world";
    char target_string1[16];

    if (string_comparison(test_string1, myStrcpy(test_string1, target_string1, sizeof(test_string1), sizeof(target_string1))) != OK && myStrcpy(test_string1, target_string1, sizeof(test_string1), sizeof(target_string1)) != NULL) {
        return ligma;
    }

    char test_string2[] = "Hello world";
    char target_string2[2];

    if (myStrcpy(test_string2, target_string2, sizeof(test_string2), sizeof(target_string2)) != NULL) {
        return ligma;
    }

    printf("Testing myStrcpy() completed! \n \n");
    return OK;
}


// Test myStrchr

errors test_myStrchr() {
    printf("Testing myStrchr(). \n");

    char test_string[] = "Star* wars";

    if ((myStrchr(test_string, '*') - test_string + 1) != 5) {
        return ligma;
    }

    if (myStrchr(test_string, ')') != NULL) {
        return ligma;
    }

    printf("Testing myStrchr() completed! \n \n");
    return OK;
}


// Test myStrdup

errors test_myStrdup() {
    printf("Testing myStrdup(). \n");

    char test_string[] = "Linux Ubuntu";

    if (string_comparison(test_string, myStrdup(test_string)) != OK) {
        return ligma;
    }

    printf("Testing myStrdup() completed! \n \n");
    return OK;
}


// Test myStrstr

errors test_myStrstr() {
    printf("Testing myStrstr(). \n");

    char test_string[] = "abacabacaba";
    char target_string1[] = "";
    char result_string1[] = "abacabacaba";

    if (string_comparison(result_string1, myStrstr(test_string, target_string1)) != OK) {
        return ligma;
    }

    char target_string2[] = "caba";
    char result_string2[] = "cabacaba";

    if (string_comparison(result_string2, myStrstr(test_string, target_string2)) != OK) {
        return ligma;
    }

    char target_string3[] = "ui";

    if (myStrstr(test_string, target_string3) != NULL) {
        return ligma;
    }

    printf("Testing myStrstr() completed! \n \n");
    return OK;
}


// Test myMemchr

errors test_myMemchr() {
    printf("Testing myMemchr(). \n");

    char test_string[] = "abacaba";

    if (myMemchr(test_string, 'c', myStrlen(test_string)) != 4) {
        return ligma;
    }

    if (myMemchr(test_string, ')', myStrlen(test_string)) != NULL) {
        return ligma;
    }

    printf("Testing myMemchr() completed! \n \n");
    return OK;
}


// Test myMemcpy

errors test_myMemcpy() {
    printf("Testing myMemcpy(). \n");

    char test_string[] = "Linux Ubuntu";
    char target_string[15];
    char result_string[] = "Linux";

    if (string_comparison(result_string, myMemcpy(test_string, target_string, 5)) != OK) {
        return ligma;
    }

    if (myMemcpy(test_string, target_string, 58) != NULL) {
        return ligma;
    }

    printf("Testing myMemcpy() completed! \n \n");
    return OK;
}


// Test myMemset

errors test_myMemset() {
    printf("Testing myMemset(). \n");

    char test_string[] = "String library";
    char res_string[] = "****ng library";

    if (string_comparison(myMemset(test_string, '*', 4), res_string) != OK) {
        return ligma;
    }

    if (myMemset(test_string, '*', 19) != NULL) {
        return ligma;
    }

    printf("Testing myMemset() completed! \n \n");
    return OK;
}