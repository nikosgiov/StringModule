/*	Nikolaos Giovanopoulos - CSD4613
	ASSIGNMENT 2	
	mystring_ars.c
*/

#include "mystring.h"

/* Return the length of string `pcStr`.

It is a checked runtime error for `pcStr` to be NULL. */

size_t ms_length(const char pcStr[]) {

	size_t uiLength = 0U;
        assert(pcStr != NULL);
        while (pcStr[uiLength] != '\0')
        	uiLength++;
        return uiLength;
}

/*Copies the string "str2" to string "str1" and returns a pointer to "str1".
It is a checked runtime error for "str2" to be NULL.*/

char *ms_copy(char str1[],const char str2[]){

        size_t i;
        assert(str2 != NULL);
	for (i=0; i<ms_length(str2); i++)
		str1[i] = str2[i];
	str1[i] = '\0';
	return str1; 
}

/*Copies up to n characters from the string "str2" to string "str1" and returns a pointer to the "str1".
If the length of "str2" is less than the number n , the rest of the "str1" will be padded with null bytes.
It is a checked runtime error for "str2" to be NULL.*/

char *ms_ncopy(char str1[],const char str2[],size_t n){

	size_t i;
	assert(str2 != NULL);
	for (i=0; i<n; i++)
		str1[i] = str2[i];
	str1[i] = '\0';
	return str1;
}

/*Appends the string "str2" to the string "str1",removing its old null terminator
and adding a new one at the end of the new string("str1").
Returns a pointer to the "str1".
It is a checked runtime error for "str2" to be NULL.*/

char *ms_concat(char str1[],const char str2[]){

	size_t i,j;
	assert(str2 != NULL);
	i = ms_length(str1);		
	for (j=0; j<ms_length(str2); j++,i++)
		str1[i] = str2[j];
	str1[i] = '\0';
        return str1;
}

/*Appends up to n characters of the string "str2"to the string "str1",removing 
its old null terminator and adding a new one at the end of the new string("str1").
Returns a pointer to the "str1".
It is a checked runtime error for "str2" to be NULL.*/

char *ms_nconcat(char str1[],const char str2[],size_t n){

	size_t i,j;
	assert(str2 != NULL);
	i = ms_length(str1);
	for (j=0; j<n; j++,i++)
		str1[i] = str2[j];
	str1[i] = '\0';
        return str1;
}

/*Returns a negative, positive or equal to zero integer if the string
"str1" is less than the string "str2",greater or equal respectively.
It is a checked runtime error for "str1" and "str2" to be NULL.*/

int ms_compare(const char str1[],const char str2[]){

	size_t i;
	assert(str1 != NULL && str2 != NULL);
	for (i=0; str1[i]==str2[i]; i++){
		if (i == ms_length(str1) || i == ms_length(str2))
			return 0;
	}
	if (str1[i] < str2[i])
		return -1;
	else
		return 1;
}

/*Returns a negative, positive or equal to zero integer if the first
n characters of the string "str1" are less than these of the string
"str2", greater or equal respectively.
It is a checked runtime error for "str1" and "str2" to be NULL.*/

int ms_ncompare (const char str1[],const char str2[],size_t n){

	size_t i;
	assert(str1 != NULL && str2 != NULL);
	if (n == 0) return 0;
	for (i=0; str1[i] == str2[i] && i<n; i++){
		if(i == ms_length(str1) || i==n-1)
			return 0;
	}
	if (str1[i] < str2[i])
		return -1;
	else
		return 1;
}

/*Returns a pointer to the beginning of the substring "str2" at the
first occurrence in the string "str1", or NULL if the substring
is not found. Null terminators are not compared.
It is a checked runtime error for "str1" and "str2" to be NULL.*/

char *ms_search(const char str1[],const char str2[]){

	size_t i,j,p;
	assert(str1 != NULL && str2 != NULL);
	for (i=0; i<ms_length(str1); i++){
		if (str1[i] == str2[0]){
			p=i;
			for (j=0; j<ms_length(str2); j++,p++){
			if (str1[p] != str2[j])
				break;
			}
			if (j == ms_length(str2))
				return (char *)&(str1[i]);
		}
	}
	return NULL;
}