#ifndef _Invent_h
#define _Invent_h 1

#include "MyString.h"

/* honors students may modify this struct */
typedef struct Customer {
	String name; // accessing name.ptr or name.len directly is poor style and may be penalized
	int bottles =0;
	int diapers = 0;
	int rattles = 0;
	int sku1 = 0;
	int sku2 = 0;
} Customer;


/* read a string from the input file.  Creates a new string (you must call destroyString) */
void readString(String*);

/* read one number form the input file */
void readNum(int*);

/* For each of the following three functions, we have read one word
 * from the input file, either "Inventory" "Purchase" or "Summarize"
 * In each case, the function should read the remaining input from
 * the input file (using readString and readNum) and
 * process the command 
 */
void processInventory(void);
void processPurchase(void);
void processSummarize(void);
void processSKU(void); // used in the honors requirement

/* reset the database (inventory, customer info, etc). */
void reset(void); 

#endif /* _Invent_h */
