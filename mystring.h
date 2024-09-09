/*	Nikolaos Giovanopoulos - CSD4613
	ASSIGNMENT 2	
	mystring.h
*/

#include <stdio.h>
#include <stddef.h>
#include <assert.h>

/* Return the length of string `pcStr`.

It is a checked runtime error for `pcStr` to be NULL. */

size_t ms_length(const char *str1);

/*Copies the string "str2" to string "str1" and returns a pointer to "str1".
It is a checked runtime error for "str2" to be NULL.*/

char *ms_copy(char *str1,const char *str2);

/*Copies up to n characters from the string "str2" to string "str1" and returns a pointer to the "str1".
If the length of "str2" is less than the number n , the rest of the "str1" will be padded with null bytes.
It is a checked runtime error for "str2" to be NULL.*/

char *ms_ncopy(char *str1, const char *str2,size_t n);

/*Appends the string "str2" to the string "str1",removing its old null terminator
and adding a new one at the end of the new string("str1").
Returns a pointer to the "str1".
It is a checked runtime error for "str2" to be NULL.*/

char *ms_concat(char *str1,const char *str2 );

/*Appends up to n characters of the string "str2"to the string "str1",removing 
its old null terminator and adding a new one at the end of the new string("str1").
Returns a pointer to the "str1".
It is a checked runtime error for "str2" to be NULL.*/

char *ms_nconcat(char *str1,const char *str2,size_t n);

/*Returns a negative, positive or equal to zero integer if the string
"str1" is less than the string "str2",greater or equal respectively.
It is a checked runtime error for "str1" and "str2" to be NULL.*/

int ms_compare(const char *str1,const char *str2);

/*Returns a negative, positive or equal to zero integer if the first
n characters of the string "str1" are less than these of the string
"str2", greater or equal respectively.
It is a checked runtime error for "str1" and "str2" to be NULL.*/

int ms_ncompare(const char *str1,const char *str2,size_t n);

/*Returns a pointer to the beginning of the substring "str2" at the
first occurrence in the string "str1", or NULL if the substring
is not found. Null terminators are not compared.
It is a checked runtime error for "str1" and "str2" to be NULL.*/

char *ms_search(const char *str1,const char *str2);

/* 
 * Return a pointer to the first occurrence of character c in string `pcStr`, 
 * or NULL if the character is not found.
 *
 * It is a checked runtime error for `pcStr` to be NULL.
 */
char *ms_strchr(const char *pcStr, int c);