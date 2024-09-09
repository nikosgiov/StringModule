/*	Nikolaos Giovanopoulos - CSD4613
	ASSIGNMENT 2	
	mystring_ptrs.c
*/

#include "mystring.h"

/* Return the length of string `pcStr`.

It is a checked runtime error for `pcStr` to be NULL. */

size_t ms_length(const char *pcStr) {

    size_t uiLength = 0U;
    assert(pcStr != NULL);
    while (*(pcStr + uiLength) != '\0')
        uiLength++;
    return uiLength;
}

/*Copies the string "str2" to string "str1" and returns a pointer to "str1".
It is a checked runtime error for "str2" to be NULL.*/

char *ms_copy(char *str1,const char *str2){
    char *p = str1;
    assert(str2 != NULL);
    while((*p++ = *str2++) != '\0');
    return str1;
}

/*Copies up to n characters from the string "str2" to string "str1" and returns a pointer to the "str1".
If the length of "str2" is less than the number n , the rest of the "str1" will be padded with null bytes.
It is a checked runtime error for "str2" to be NULL.*/

char *ms_ncopy(char *str1,const char *str2,size_t n){
    char *p = str1;
    assert(str2 != NULL);
    while (n-- && (*p++ = *str2++));
    return str1;
}

/*Appends the string "str2" to the string "str1",removing its old null terminator
and adding a new one at the end of the new string("str1").
Returns a pointer to the "str1".
It is a checked runtime error for "str2" to be NULL.*/

char *ms_concat(char *str1,const char *str2){

    assert(str2 != NULL);
    ms_copy(str1+ms_length(str1),str2);
    return str1;
}

/*Appends up to n characters of the string "str2"to the string "str1",removing 
its old null terminator and adding a new one at the end of the new string("str1").
Returns a pointer to the "str1".
It is a checked runtime error for "str2" to be NULL.*/

char *ms_nconcat(char *str1,const char *str2,size_t n){

    char* ptr = str1 + ms_length(str1);
    assert(str2 != NULL);
    while (*str2 != '\0' && n--)
        *ptr++ = *str2++;
    *ptr = '\0';
    return str1;
}

/*Returns a negative, positive or equal to zero integer if the string
"str1" is less than the string "str2",greater or equal respectively.
It is a checked runtime error for "str1" and "str2" to be NULL.*/

int ms_compare(const char *str1,const char *str2){

    assert(str1 != NULL && str2 != NULL);
    while (*str1){
        if (*str1!=*str2) break;
        str1++;
        str2++;
    }
    if ( *(const unsigned char*)str1 < *(const unsigned char*)str2 )
        return -1;
    else if ( *(const unsigned char*)str1 > *(const unsigned char*)str2 )
        return 1;
    else
        return 0;
}

/*Returns a negative, positive or equal to zero integer if the first
n characters of the string "str1" are less than these of the string
"str2", greater or equal respectively.
It is a checked runtime error for "str1" and "str2" to be NULL.*/

int ms_ncompare(const char *str1,const char *str2,size_t n){

    assert(str1 != NULL && str2 != NULL);
    if (n == 0) return 0;
    while (*str1 == *str2 && n-- > 0){
        if (*str1 == '\0' || n == 0) return 0;
        str1++;
        str2++;
    }
    if ( *(const unsigned char*)str1 < *(const unsigned char*)str2 )
        return -1;
    else if ( *(const unsigned char*)str1 > *(const unsigned char*)str2 )
        return 1;
    else
        return 0;
}

/*Returns a pointer to the beginning of the substring "str2" at the
first occurrence in the string "str1", or NULL if the substring
is not found. Null terminators are not compared.
It is a checked runtime error for "str1" and "str2" to be NULL.*/

char *ms_search(const char *str1, const char *str2){
    const char*p,*cmp;
    assert(str1 != NULL && str2 != NULL);
    while (*str1){
        if (*str1 == *str2){
            p = str1;
            cmp = str2;
            while (*cmp){
                if (*p != *cmp) break;
                p++;
                cmp++;
            }
            if (*cmp == '\0') return (char *)str1;
        }
        str1++;
    }
    return NULL;
}



/* 
 * Return a pointer to the first occurrence of character c in string pcStr, 
 * or NULL if the character is not found.
 *
 * It is a checked runtime error for `pcStr` to be NULL.
 */
char *ms_strchr(const char *pcStr, int c) {

    assert(pcStr != NULL);  // Ensure the string is not NULL

    // Loop through the string until the null terminator
    while (*pcStr != '\0') {
        if (*pcStr == (char)c) {
            return (char *)pcStr;  // Return a pointer to the first occurrence of `c`
        }
        pcStr++;  // Move to the next character (pointer arithmetic)
    }

    // Check for the null terminator character
    if (c == '\0') {
        return (char *)pcStr;  // Return pointer to the null terminator
    }

    return NULL;  // Return NULL if character `c` is not found
}