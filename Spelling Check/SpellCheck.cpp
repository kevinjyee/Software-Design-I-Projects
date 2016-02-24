#include <stdio.h> // declarations of standard input/output functions
#include <stdint.h> // declarations of standard integer types (e.g., int32_t)
#include <stdlib.h> // declarations of general functions in the standard library (e.g., abort, exit)
#include <string>
#include <myHash.h> // my personal Hash Function

int UppertoLower = 'A' - 'a';


/******Function: toLower*********
 * Rewriting "toLower" of the standard library
 * Turns capital letters into lower case
 */
std::string toLower(std::string input){
	while(input){
		if(*input >= 'A' && *input <= 'Z'){
			*input -= UppertoLower;
			}
	input++;
	}
}



void spellCheck(std::string article, std::string dictionary){

article = toLower(article);
dictionary = toLower(dictionary);

}
