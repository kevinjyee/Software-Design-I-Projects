
#include <stdio.h>
#include "String.h"
#include "Customer.h"
#include "CustomerDB.h"
#include <iostream>

void readString(String&);
void readNum(int&);

CustomerDB database;

int num_bottles = 0;
int num_rattles = 0;
int num_diapers = 0;
int num_custom1 = 0;
int num_custom2 = 0;

#define Occupied 1
#define Free  0

String Custom1;
String Custom2;
int Custom1Flag = Free;
int Custom2Flag = Free;


/* clear the inventory and reset the customer database to empty */
void reset(void) {
	database.clear();
	num_bottles = 0;
	num_rattles = 0;
	num_diapers = 0;
	num_custom1 =0;
	num_custom2=0;
	Custom1Flag= 0;
	Custom2Flag =0;
}

/* Beta students: please rewrite this function so that it works with Custom
 * SKUs.
 * You might want to change the way the inventory is stored in global
 * variables -- an array might be nice (just thinking out loud here).
 * You're not required to, but your solution to the project is much shorter
 * if you use this function.
 *
 * selectInventItem is a convenience function that allows you
 * to obtain a pointer to the inventory record using the item type name
 * word must be "Bottles", "Diapers" or "Rattles"
 * for example the expression *selectInventItem("Bottles") returns the 
 * current global variable for the number of bottls in the inventory
 */
int* selectInventItem(String word) {
	if (word == "Bottles") {
		return &num_bottles;
	} else if (word == "Diapers") {
		return &num_diapers;
	} else if (word == "Rattles") {
		return &num_rattles;
	}
	else if(word == Custom1){
		return &num_custom1;
	}
	else if(word == Custom2){
		return &num_custom2;
	}
	
	/* NOT REACHED */
	return 0;
}

/*
 * Beta students: please rewrite this function so that it works with Custom
 * SKUs. You're not required to, but your solution to the project is much shorter
 * if you use this function.
 *
 * this overload of selectInventItem is similar to selectInventItem above, however
 * this overload takes a Customer as a second argument and selects the data member
 * of that Customer that matches "word". The function returns a pointer to one of the three data
 * members from the specified customer.
 */
int* selectInventItem(String word, Customer& cust) {
	if (word == "Bottles") {
		return &cust.bottles;
	} else if (word == "Diapers") {
		return &cust.diapers;
	} else if (word == "Rattles") {
		return &cust.rattles;
	}
	else if(word == Custom1){
		return &cust.custom1;
	}
	else if(word == Custom2){
		return &cust.custom2;
	}
	
	/* NOT REACHED */
	return 0;
}


/*
 * findMax searches through the CustomerDB "database" and returns the Customer
 * who has purchased the most items of the specified type.
 * type must be one of "Bottles", "Rattles" or "Diapers".
 * 
 * Note: if two or more Customers are tied for having purchased the most of that item type
 * then findMax returns the first Customer in the CustomerDB who has purchased that maximal
 * quantity.
 *
 * Note: in the special case (invalid case) where there are zero Customers in the 
 * CustomerDB, fundMax returns a null pointer (0)
 */
Customer* findMax(String type) {
	Customer* result = 0;
	int max = 0;
	for (int k = 0; k < database.size(); k += 1) {
		Customer& cust = database[k];
		int *p = selectInventItem(type, cust); 
		if (*p > max) {
			max = *p;
			result = &cust;
		}
	}
	
	return result;
}




void processPurchase() {
		String customer;
		String item;
		int item_amount;

		readString(customer);
		readString(item);
		readNum(item_amount);

		int* selectedInventory = selectInventItem(item);

		if(item_amount <= 0 || selectedInventory ==0){return;}

		if(item_amount < *selectedInventory){
			printf("Sorry");
			//std::cout << "Sorry " << customer << ", we only have " << *selectedInventory << " " << item << std::endl;
		}
		else{
			*selectedInventory -= item_amount;
			*selectInventItem(item,database[customer]) += item_amount;
		}
		/*
			 * Is it available? (item amount > NumBottles)
			 * If it is not available, then return an error message by calling "printerrormessage()"
			 */



}

void processSummarize() {
}

void processInventory() {
	String word;
	int num;

	readString(word);
	readNum(num);

	int* item = selectInventItem(word);

	if(item){ //check to see if not null
	*item += num;
	}
}

void processSKU() {

	String item;
	readString(item);

	int* selectedinventory = selectInventItem(item);
	if(selectedinventory){return;} //see if it exists

	if(Custom1Flag == Occupied && Custom2Flag == Occupied){
		return;
	}

	if(Custom1Flag == Free){
		Custom1 = item;
		Custom1Flag = Occupied;

	}
	else if(Custom2Flag == Free){
		Custom2 = item;
		Custom2Flag = Occupied;
	}

}
