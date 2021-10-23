#include "tests.h"
#include <stdio.h>
#include <assert.h>
#include "../string.h"
const char wrong_string = NULL;

int run_all_tests() {
    assert(OK == test_myStrcmp());
    assert(OK == test_myStrlen());
    assert(OK == test_myStrcpy());
    assert(OK == test_myStrchr());
    assert(OK == test_myStrdup());
    assert(OK == test_myStrstr());
    assert(OK == test_myMemchr());
    assert(OK == test_myMemcpy());
    assert(OK == test_myMemset());
}

// Test myStrcmp

errors test_myStrcmp() {
    printf("Testing myStrcmp(). \n");

    char test_string1[] = "Hello";
    char test_string2[] = "Hello";

    if (myStrcmp(test_string1, wrong_string) != NULL) {
        return failed;
    }

    if (myStrcmp(test_string1, test_string2) != 0) {
        return failed;
    }

    char test_string3[] = "Hi";

    if (myStrcmp(test_string1, test_string3) == 0) {
        return failed;
    }

    printf("Testing myStrcmp() completed! \n \n");
    return OK;
}

// Test myStrlen

errors test_myStrlen() {
    printf("Testing myStrlen(). \n");

    char test_string[] = "Hello";

    if (myStrlen(wrong_string) != NULL) {
        return failed;
    }

    if (myStrlen(test_string) != 5) {
        return failed;
    }

    printf("Testing myStrlen() completed! \n \n");
    return OK;
}


// Test myStrcpy

errors test_myStrcpy() {
    printf("Testing myStrcpy(). \n");

    char test_string1[] = "Hello world";
    char target_string1[16];

    if (myStrcpy(wrong_string, target_string1, sizeof(test_string1), sizeof(target_string1)) != NULL) {
        return failed;
    }

    if (myStrcmp(test_string1, myStrcpy(test_string1, target_string1, sizeof(test_string1), sizeof(target_string1))) != 0 && myStrcpy(test_string1, target_string1, sizeof(test_string1), sizeof(target_string1)) != NULL) {
        return failed;
    }

    char test_string2[] = "Hello world";
    char target_string2[2];

    if (myStrcpy(test_string2, target_string2, sizeof(test_string2), sizeof(target_string2)) != NULL) {
        return failed;
    }

    printf("Testing myStrcpy() completed! \n \n");
    return OK;
}


// Test myStrchr

errors test_myStrchr() {
    printf("Testing myStrchr(). \n");

    char test_string[] = "Star* wars";

    if (myStrchr(wrong_string, '*') != NULL) {
        return failed;
    }

    if ((myStrchr(test_string, '*') - test_string + 1) != 5) {
        return failed;
    }

    if (myStrchr(test_string, ')') != NULL) {
        return failed;
    }

    printf("Testing myStrchr() completed! \n \n");
    return OK;
}


// Test myStrdup

errors test_myStrdup() {
    printf("Testing myStrdup(). \n");

    char test_string[] = "Linux Ubuntu";

    if (myStrdup(wrong_string) != NULL) {
        return failed;
    }

    if (myStrcmp(test_string, myStrdup(test_string)) != 0) {
        return failed;
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

    if (myStrstr(wrong_string, target_string1) != NULL) {
        return failed;
    }

    if (myStrcmp(result_string1, myStrstr(test_string, target_string1)) != 0) {
        return failed;
    }

    char target_string2[] = "caba";
    char result_string2[] = "cabacaba";

    if (myStrcmp(result_string2, myStrstr(test_string, target_string2)) != 0) {
        return failed;
    }

    char target_string3[] = "ui";

    if (myStrstr(test_string, target_string3) != NULL) {
        return failed;
    }

    printf("Testing myStrstr() completed! \n \n");
    return OK;
}


// Test myMemchr

errors test_myMemchr() {
    printf("Testing myMemchr(). \n");

    char test_string[] = "abacaba";

    if (myMemchr(wrong_string, 'c', myStrlen(test_string)) != NULL) {
        return failed;
    }

    if (myMemchr(test_string, 'c', myStrlen(test_string)) != 4) {
        return failed;
    }

    if (myMemchr(test_string, ')', myStrlen(test_string)) != NULL) {
        return failed;
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

    if (myMemcpy(wrong_string, target_string, 5) != NULL) {
        return failed;
    }

    if (myStrcmp(result_string, myMemcpy(test_string, target_string, 5)) != 0) {
        return failed;
    }

    if (myMemcpy(test_string, target_string, 58) != NULL) {
        return failed;
    }

    printf("Testing myMemcpy() completed! \n \n");
    return OK;
}


// Test myMemset

errors test_myMemset() {
    printf("Testing myMemset(). \n");

    char test_string[] = "String library";
    char res_string[] = "****ng library";

    if (myMemset(wrong_string, '*', 4) != NULL) {
        return failed;
    }

    if (myStrcmp(myMemset(test_string, '*', 4), res_string) != 0) {
        return failed;
    }

    if (myMemset(test_string, '*', 19) != NULL) {
        return failed;
    }

    printf("Testing myMemset() completed! \n \n");
    return OK;
}