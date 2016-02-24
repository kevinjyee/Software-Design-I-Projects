/*
 * Pointers.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: kevin
 */




#include <stdio.h>
#include <stdint.h>

int main(void){
	int32_t x =42;
	int* p = &x; // this is supose to point to a character. it's trying to point to an integer
	*(p+1) = 1;
	printf("the value is %d %d\n", *p, x);
}
