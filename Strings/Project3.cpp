/*
 *Kevin Yee
 *kjy252
 *Fall 2015
 */

#include <assert.h>
#include <string.h>
#include "MemHeap.h"
#include "String.h"
#include <stdio.h>
#include <math.h>
/* use these two macros and the function functions if you want -- not required */
#define SIGNATURE (~0xdeadbeef)
#define STRING(s) (((String*)s)-1)
#define utstrcpy2



/* allocate a utstring on the heap, initialize the string correctly by copying
 * the characters from 'src' and return a pointer to the first character of actual string data */
/*
 * Function: Sumwords
 * --------------------------------------
 * Sumwords is used to turn the value of the char string into integer values
 * This is returned in to the cache data
 */

int Sumwords(int* dummydata){

	int i =0;
	int sum =0;
	int multipliers[28] = {10000000,100000,1000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

while(dummydata[i]!=0){
	sum+= ((dummydata[i]-64)*multipliers[i]);
	i++;
}
return sum;
}

/*
 * Function: utstrdup
 * -----------------------------------
 * utstrdup is used to replicate a string from src
 * then the first 4 memory spaces are allocated for "check, capcity, size, and cache"
 */

char* utstrdup(const char* src) {
	int i =0;
	int k=0;
//find the length of the src 
int sizeofsrc = strlen(src);
//make the malloc depending on the size of the src + 1 
String* Heapstorage = (String*) malloc(sizeof(String)+sizeofsrc*sizeof(char)+1);

//Pass necessary information of string 
Heapstorage -> check = ~0xdeadbeef;
Heapstorage -> capacity = sizeofsrc;
Heapstorage -> length = sizeofsrc;

int decimal =0;
int dummydata[28] = {0};
uint32_t* ptr = (uint32_t*) &Heapstorage->check;

//Copies the src data into the actual data
for (i=0; i<sizeofsrc; i++){
	Heapstorage -> data[i] =  src[i];

}

for(k=0; k<27; k++){
	dummydata[k] = src[k];
}

Heapstorage-> data[i] = '\0';
dummydata[k]=0;

//Call function that returns the cumulative sum of the number.
decimal = Sumwords(dummydata);

//Cache value has value of characters as integers
Heapstorage ->cache = 0;
Heapstorage -> cache = decimal;

//returns the address of the data
return Heapstorage->data;

}

/* the parameter 'utstr' must be a utstring. Find the length of this string by accessing the meta-data
 * and return that length */

/*
 * Function: utstrlen
 * -----------------------------------
 * Returns the address of the metadata containing the length of a character
 */

uint32_t utstrlen(const char* utstr) {
	

	int length;
	
	String* TempString = (String*) (utstr-12);
	uint32_t* ptr = &TempString->check;
	assert(*ptr == SIGNATURE);

		length = TempString->length;
			return length;
	
	}

/* s must be a utstring. suffix can be an ordinary string (or a utstring)
 * append the characters from suffix to the string s. Do not allocate any additional storage, and
 * only append as many characters as will actually fit in s. Update the length meta-data for utstring s
 * and then return s */


/*
 * Function: utstrcat
 * ----------------------------
 * Concatanates suffix to s
 * no additional memory is allocated for s
 * only append as many characters as will actually fit in s.
 * updates the length of the meta data for utstring
 */
char* utstrcat(char* s, const char* suffix) {
	int dummydata[28] = {0};
	int k =0;
    uint32_t i = 0; //initialize counter
    String* Cat = (String*) (s-16);
    uint32_t *ptr = (uint32_t*) &Cat->check;
	assert(*ptr == SIGNATURE);
	uint32_t capacity = Cat->capacity;
	uint32_t length = Cat->length;
	uint32_t* currentlength = (uint32_t*) &Cat->length;

    while (suffix[i] != 0) { //check if end of suffix

        if ((capacity - *currentlength) != 0) {
            s[length] = suffix[i]; // put in suffix into the last location of length
            *currentlength += 1; // update length as we loop
            length += 1;
			i = i + 1;
        } else{
			s[length] = '\0';
			return s;
		}
    } s[length] = '\0';

for(k=0; k<27; k++){
	dummydata[k] = s[k];

}
dummydata[k] =0;
Cat->cache = Sumwords(dummydata);

	return s;
}





/* 'dst' must be a utstring. 'src' can be an ordinary string (or a utstring)
 * overwrite the characters in dst with the characters from src. Do not overflow the capacity of dst
 * For example, if src has five characters and dst has capacity for 10, then copy all five characters
 * However, if src has ten characters and dst only has capacity for 8, then copy only the first 8
 * characters. Do not allocate any additional storage, do not change capacity. Update the length
 * meta-data for dst and then return dst */

/*
 * Function: utstrcpy
 * ------------------------------------------
 * dstString contains new destination
 * src contains data
 * Copies src into dst
 * update length
 */

char* utstrcpy(char* dst, const char* src) {

	String* dstString = (String*) (dst - 16);
	uint32_t* ptr = (uint32_t*) &dstString->check;
	int dummydata[28] = {0};
	int k =0;
	
	uint32_t capacitydst = 0;
	uint32_t strlensrc = 0;
	uint32_t i =0;
	uint32_t j =0;
	
	*(ptr+2) = 0; // sets length to 0 as we do not know the new length just yet
	*(ptr+2) = 0;
	
	assert(*ptr == SIGNATURE);
	
	capacitydst = dstString->capacity;
	strlensrc = strlen(src);
	
	if(strlensrc < capacitydst){
	/*if there's space src < dst put entire string in there */

		for(i=0; i < strlensrc; i++){
		dst[i] = src[i];
		*(ptr+2) +=1;		 	//update length
	}
	
	dst[i] = 0;
	}
	else{
		/*if there's no space or not enough, just reach the end of the capacity*/
		for(j=0; j<capacitydst; j++){
			dst[j] = src[j];
			*(ptr+2) +=1; //update length
	}
	dst[j] = 0;
	}
	for(k=0; k<27;k++){
		dummydata[k] = dst[k];
	}
	dummydata[k] =0;
	dstString->cache = Sumwords(dummydata);
	
	return dst;
	
	
	
}




/* self must be a utstring. deallocate the storage for this string
 * (i.e., locate the start of the chunk and call free to dispose of the chunk, note that the start of
 * the chunk will be 12 bytes before *self) */


/*
 * void utstrfree(char* p); -- This function is used by our clients when they are finished
working with one of our strings. The function should deallocate the chunk on the heap
that holds this String struct (by calling free). Just be sure to compute the correct address
before calling free. Our clients are required to never call this function unless the
argument p is a utstring. They’re also required to always call this function (eventually)
for every utstring that they create.
 */

/*
 * Function: utstrfree
 * ------------------------------------------
 * Get a pointer to metadata
 * Free it
 */
void utstrfree(char* self) {
	

	int* ptr = (int*) self - 3; // pointer for metadata

		assert(*ptr == SIGNATURE);

		void* p = ptr-1;
			free(p);

}

/* s must be a utstring.
 * ensure that s has capacity at least as large as 'new_capacity'
 * if s already has capacity equal to or larger than new_capacity, then return s
 * if s has less capacity than new_capacity, then allocate new storage with sufficient space to store
 * new_capacity characters (plus a terminating zero), copy the current characters from s into this
 * new storage. Update the meta-data to correctly describe new new utstring you've created, deallocate s
 * and then return a pointer to the first character in the newly allocated storage */

/*
 * Function: utstrrealloc
 * ---------------------------------------
 * create a new string if the size requested is larger
 * s contains string
 * new_capacity is size requested
 */
char* utstrrealloc(char* s, uint32_t new_capacity) {

	int* ptr = (int*) s-3;
	uint32_t oldcapacity;
	int i=0;
	int k=0;
	int dummydata[28] = {0}; //used to store cache if they determine to make the size again
	assert(*ptr == SIGNATURE);

	oldcapacity = *(ptr+1); //find the current capacity

	if(oldcapacity >= new_capacity){
		return s; // do nothing if the request something smaller
	}

	else{
		String* reallocate = (String*) malloc(sizeof(String)+new_capacity+1); //else create larger malloc
		reallocate -> check = ~0xdeadbeef;
		reallocate -> capacity = new_capacity;

		while(s[i] != 0){
			reallocate->data[i] = s[i];

			i++;

		}
		for(k=0; k<27;k++){
			dummydata[k] = s[k];
		}
		dummydata[k]=  0;
		reallocate-> data[i] = 0;
		dummydata[i] = 0;

		reallocate->length = i;
		reallocate->cache = Sumwords(dummydata);
		utstrfree(s);
		return reallocate->data;
	}


}









int32_t utstrcmp(const char* s1, const char* s2) {



	int* ptr1 = (int*) s1-4;
	int* ptr2 = (int*) s2-4;


assert(*(ptr1+1) == SIGNATURE);

int difference = *ptr1 - *ptr2;
char TempChar_1;
char TempChar_2;

if(difference == 0){
	/*compare latter char
	 *
	 */
	do
	      {
	           TempChar_1 = *(s1++);
	           TempChar_2 = *(s2++);
	      } while(TempChar_1 && TempChar_1 == TempChar_2);

	      return TempChar_1 - TempChar_2;

}

	return difference;


//if(difference > 0){
//	return 1;
//}
//if(difference < 0){
//	return -1;
//}
//else{
//	return 0;
//}


}


