#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <assert.h>


/**
 * @brief Determining the length of a string
 * @details The function calculates the number of elements up to '\0'
 * @param str String value
 * @return A variable with a length value
 */
int myStrlen(char* str) {
    assert(str != NULL);

    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    return len;
}


/**
 * @brief Copying a string
 * @details Copies characters from one string to another, subject to length
 * @param source The string from which the data is copied
 * @param target The string to which the data is copied
 * @param source_bit_len The bit length of the string from which the data is copied
 * @param target_bit_len The bit length of the string to which the data is copied
 * @return The copied string or NULL
 */
char* myStrcpy(char* source, char* target, size_t source_bit_len, size_t target_bit_len) {
    assert(source != NULL);
    assert(target != NULL);

    if ((int)(target_bit_len - source_bit_len) < 0) {
        return NULL;
    } else {
        for (int i = 0; i <= myStrlen(source); i++) {
            target[i] = source[i];
        }
        return target;
    }
}


/**
 * @brief Searching for a character in a string
 * @details Search for the first matching character in a string
 * @param source The string in which the character is being searched
 * @param symbol Symbol to search for
 * @return The line after this character or NULL
 */
char* myStrchr(char* source, int symbol) {
    assert(source != NULL);

    while (*source != (char) symbol) {
        if (*source == '\0') {
            return NULL;
        }
        source++;
    }

    return (char*) source;
}


/**
 * @brief Duplicating a string
 * @details Copying a string using malloc. This function allocates memory, it needs to be cleaned up
 * @param source String to duplicate
 * @see myStrcpy
 * @return Duplicated string
 */
char* myStrdup(char* source) {
    assert(source != NULL);

    char* target = (char*) malloc(myStrlen(source) + 1);
    target = myStrcpy(source, target, sizeof(source), myStrlen(source)+1);

    return target;
}


/**
 * @brief Searching for a substring in a string
 * @param source Search string
 * @param value Search value
 * @return A string starting from the found substring or NULL
 */
char* myStrstr(char* source, char* value) {
    assert(source != NULL);
    assert(value != NULL);

    if (myStrlen(value) == 0) {
        return (char *) source;
    }

    while (*source) {
        if (*source == *value) {
            while (*source == *value) {
                source++;
            }
            return (--source);
        }
        source++;
    }
    return NULL;
}

/**
 * @brief Searching for the position of a symbol in the range
 * @details Finds a character in a restricted area of the string
 * @param source Search string
 * @param symbol Symbol to search for
 * @param len Search range
 * @return The position of the first matching character or NULL
 */
void* myMemchr(void* source, int symbol, size_t len) {
    char* buf_source = source;
    assert(buf_source != NULL);

    for (int pos = 0; pos <= len; pos++) {
        if (buf_source[pos] == (char) symbol) {
            return (void*)(pos + 1);
        }
    }

    return NULL;
}


/**
 * @brief Copying elements in the range
 * @details Copying elements of a certain number of elements
 * @param source String to copy
 * @param target The term of the received value
 * @param num Number of characters
 * @return The copied string or NULL
 */
void* myMemcpy (void* source, void* target, size_t num) {
    char* buf_source = source;
    char* buf_target = target;

    assert(buf_source != NULL);
    assert(buf_target != NULL);

    if (num > myStrlen(source)) {
        return NULL;
    }

    for (size_t i = 0; i < num; i++) {
        buf_target[i] = buf_source[i];
    }

    return buf_target;
}


/**
 * @brief Replacing elements
 * @details Replacing a limited number of elements with a new symbol
 * @param mem_target Copy and Replace string
 * @param value Symbol to replace
 * @param num Number of items to replace
 * @return A string with replaced elements or NULL
 */
void* myMemset(void* mem_target, int value, size_t num) {
    char* buf_target = mem_target;
    assert(buf_target != NULL);

    if (num > myStrlen(mem_target)) {
        return NULL;
    }

    for (size_t i = 0; i < num; i++) {
        buf_target[i] = value;
    }

    return buf_target;
}


/**
 * @brief Output function
 * @details Output the result of all library functions
 * @param str1 First string
 * @param str2 Second string
 * @param str3 Third string
 * @param str4 Fourth string
 * @param str1_len Bit length of the first string
 * @param str3_len Bit length of the third string
 * @param searching_symbol The symbol to search in myStrchr() and myMemchr()
 * @see
 * myStrlen()
 * myStrcpy()
 * myStrchr()
 * myStrdup()
 * myStrstr()
 * myMemchr()
 * myMemcpy()
 * myMemset()
 */
void output(char* str1, char* str2, char* str3, char* str4, size_t str1_len, size_t str3_len, char searching_symbol) {
    printf("Main string: %s \n", str1);
    printf("Length of the main string: %d \n", myStrlen(str1));

        // Output myStrcpy()
    if (myStrcpy(str1, str3, str1_len, str3_len) == NULL) {
        printf("Sorry, but copying is not possible. \n");
    } else {
        printf("Copied string: %s \n", myStrcpy(str1, str3, str1_len, str3_len));
    }

        // Output myStrchr()
    if (myStrchr(str1, searching_symbol) == NULL) {
        printf("Symbol '%c' not found. \n", searching_symbol);
    } else {
        printf("Symbol '%c' position by strchr: %d \n", searching_symbol, (myStrchr(str1, searching_symbol) - str1 + 1));
    }

    printf("Duplicated string: %s \n", myStrdup(str1));

        // Output myStrstr()
    if (myStrstr(str1, str2) == NULL) {
        printf("Substring not found. \n");
    } else {
        printf("Substring search: %s \n", myStrstr(str1, str2));
    }

        // Output myMemchr()
    if (myMemchr(str1, searching_symbol, myStrlen(str1)) == NULL) {
        printf("Symbol '%c' not found. \n", searching_symbol);
    } else {
        printf("Symbol '%c' position by memchr: %d \n", searching_symbol, myMemchr(str1, searching_symbol, myStrlen(str1)));
    }

        // Output myMemcpy()
    if (myMemcpy(str1, str4, 5) == NULL) {
        printf("The number of characters exceeds the length of the string. \n");
    } else {
        printf("Copied string area: %s \n", myMemcpy(str1, str4, 5));
    }

        // Output myMemset()
    if (myMemset(str1, '/', 5) == NULL) {
        printf("The number of characters exceeds the length of the string. \n");
    } else {
        printf("Replaced string: %s \n", myMemset(str1, '/', 5));
    }
}



