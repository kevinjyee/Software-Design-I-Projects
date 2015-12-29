/*
 * EE312 Simple CRM Project
 *
 * Kevin Yee
 * kjy252
 * Chris is my TA
 */

#include <stdio.h>
#include <assert.h>
#include "MyString.h"
#include "Invent.h"
#include <string.h>

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];

#define process

String Bottles;
String Rattles;
String Diapers;
String SKU1;
String SKU2;

int NumBottles=0;
int NumRattles=0;
int NumDiapers=0;
int NumSKU1=0;
int NumSKU2=0;
int NumCustomers = 0;

#define available 0
#define occupied 1

int SKU1flag = available;
int SKU2flag = available;

/*
* Function: printerrormessage
* Prints the error message of "Sorry Customer we only have x amount left"
* If there is more items requested than there is in inventory, this function is called
*/

void printerrormessage(String item, String customer){
	if(StringIsEqualTo(&item, &Bottles)){
			printf("Sorry ");
			StringPrint(&customer);
			printf(" ,we only have %d ",NumBottles);
			printf("Bottles\n");

			}

			if(StringIsEqualTo(&item, &Rattles)){
					printf("Sorry ");
					StringPrint(&customer);
					printf(", we only have %d ",NumRattles);
					printf("Rattles\n");

		}

			if(StringIsEqualTo(&item, &Diapers)){
							printf("Sorry ");
							StringPrint(&customer);
							printf(", we only have %d ",NumDiapers);
							printf("Diapers\n");

				}

			if(StringIsEqualTo(&item, &SKU1)){
							printf("Sorry ");
							StringPrint(&customer);
							printf(", we only have %d ",NumSKU1);
							StringPrint(&SKU1);
							printf("\n");

				}

			if(StringIsEqualTo(&item, &SKU2)){
								printf("Sorry ");
								StringPrint(&customer);
								printf(", we only have %d ",NumSKU2);
								StringPrint(&SKU2);
								printf("\n");

					}
}




/*
*Function: reset
* When the function is over, clear the entire database
* Sting Destroy all variables on the heap
*Clears the customer database
*/

void reset(void) {

if(NumCustomers == 0){
	 NumCustomers = 0;
		 NumBottles=0;
		 NumRattles=0;
		 NumDiapers=0;
		 NumSKU1=0;
		 NumSKU2=0;
	return;
}


		for (int i = 0; i < NumCustomers; i++) {

			StringDestroy(&(customers[i].name));

			customers[i].bottles = 0;
			customers[i].rattles = 0;
			customers[i].diapers = 0;
			customers[i].sku1 = 0;
			customers[i].sku2 = 0;


		}
		if (SKU1flag == occupied) {
			StringDestroy(&SKU1);
		}
		if (SKU2flag == occupied) {
			StringDestroy(&SKU2);
		}

		 NumCustomers = 0;
		 NumBottles=0;
		 NumRattles=0;
		 NumDiapers=0;
		 NumSKU1=0;
		 NumSKU2=0;

}


/*Fuction processSummarzie
*Prints out a summary
*Displays the number of Bottles, Rattles, and Diapers remaining in the inventory
*Displays how many customers have come to the store for purchases
*Displays the customer who purchased the most Diapers, Bottles, and Rattles
*If a certain item has not been puchased,the summary indicates it
*/
void processSummarize() {



	int i =0; //increments through all the customers to see who purchased the most
	int greatest_Bottles=0;
	String max_name_Bottles;

	int greatest_Rattles=0;
	String max_name_Rattles;

	int greatest_Diapers=0;
	String max_name_Diapers;

	int greatest_sku1=0;
	String max_name_sku1;

	int greatest_sku2=0;
	String max_name_sku2;

	/*
	 * Print out how many of each item are left
	 */

	if(SKU1flag == available && SKU2flag == available){
	printf("There are %d Bottles, %d Diapers, and %d Rattles in inventory\n",NumBottles, NumDiapers, NumRattles);

	}

	if(SKU1flag == occupied && SKU2flag == available){
		printf("There are %d Bottles, %d Diapers, %d Rattles, ", NumBottles, NumDiapers, NumRattles);
		printf("and %d ", NumSKU1);
		StringPrint(&SKU1);
		printf(" in inventory\n");

	}

	if(SKU1flag == occupied && SKU2flag == occupied){
		printf("There are %d Bottles, %d Diapers, %d Rattles, ", NumBottles, NumDiapers, NumRattles);
			printf("%d ", NumSKU1);
			StringPrint(&SKU1);
			printf(", and %d ", NumSKU2);
			StringPrint(&SKU2);
			printf(" in inventory\n");


	}

	/*
	 * Print out how many different cusomters we have
	 */
	printf("we have had a total of %d different customers\n", NumCustomers);




	/*
	 * Determine who purchased the most Bottles
	 *Determined by looking at each customer in the database
	 */



for(i=0; i <= NumCustomers; i++){
	if(customers[i].bottles > greatest_Bottles){
		greatest_Bottles = customers[i].bottles;
		max_name_Bottles = customers[i].name;
		}

	if(customers[i].rattles > greatest_Rattles){
			greatest_Rattles = customers[i].rattles;
			max_name_Rattles = customers[i].name;
			}

	if(customers[i].diapers > greatest_Diapers){
			greatest_Diapers = customers[i].diapers;
			max_name_Diapers = customers[i].name;
			}

	if(customers[i].sku1 > greatest_sku1){
				greatest_sku1 = customers[i].sku1;
				max_name_sku1 = customers[i].name;
				}

	if(customers[i].sku2 > greatest_sku2){
					greatest_sku2 = customers[i].sku2;
					max_name_sku2 = customers[i].name;
					}


	}

/*
* Prints out who has the most what
*/
if(greatest_Bottles != 0){
StringPrint(&max_name_Bottles); //Print who has the most Bottles
printf(" has purchased the most Bottles (%d)\n", greatest_Bottles);
}
else{
printf("no one has purchased any Bottles\n");
}

if(greatest_Diapers != 0){
StringPrint(&max_name_Diapers); //Print who has the most Rattles
printf(" has purchased the most Diapers (%d)\n", greatest_Diapers);
}

else{
	printf("no one has purchased any Diapers\n", greatest_Diapers);
}

if(greatest_Rattles != 0){
StringPrint(&max_name_Rattles); //Print who has the most Rattles
printf(" has purchased the most Rattles (%d)\n", greatest_Rattles);
}
else{
	printf("no one has purchased any Rattles\n");
}


if(SKU1flag == occupied){
if(greatest_sku1 != 0){
StringPrint(&max_name_sku1); //Print who has the most Rattles
printf(" has purchased the most ");
StringPrint(&SKU1);
printf("( %d)\n",greatest_sku1);
}
else{
	printf("no one has purchased any ");
	StringPrint(&SKU1);
	printf("\n");
}
}

if(SKU2flag == occupied){
if(greatest_sku2 != 0){
StringPrint(&max_name_sku2); //Print who has the most Rattles
printf(" has purchased the most ");
StringPrint(&SKU2);
printf(" (%d)\n",greatest_sku2);
}
else{
	printf("no one has purchased any ");
	StringPrint(&SKU2);
	printf("\n");
}

}


}




/*Function: processPurhcase
* Purchasing mechanism of the database
*/
#ifdef process
void processPurchase() {
	Bottles = StringCreate("Bottles");
	Rattles = StringCreate("Rattles");
	Diapers = StringCreate("Diapers");
	bool returning_customer = true;

	String customer;
	String item;
	int item_amount;

	readString(&customer);
	readString(&item);
	readNum(&item_amount);

	/*
	 * Is it a customer?
	 * If they purchase 0 items, then return, not real customer
	 */
	if(item_amount <= 0){
				StringDestroy(&customer);
				StringDestroy(&item);
				StringDestroy(&Bottles);
				StringDestroy(&Rattles);
				StringDestroy(&Diapers);
		return;
	}

	/*
	 * Is it available? (item amount > NumBottles)
	 * If it is not available, then return an error message by calling "printerrormessage()"
	 */

	if((StringIsEqualTo(&item, &Bottles) && item_amount > NumBottles)||
		(StringIsEqualTo(&item, &Rattles) && item_amount > NumRattles)||
		(StringIsEqualTo(&item, &Diapers) && item_amount > NumDiapers)||
		(StringIsEqualTo(&item, &SKU1) && item_amount > NumSKU1)||
		(StringIsEqualTo(&item, &SKU2) && item_amount > NumSKU2)
			){
		printerrormessage(item,customer);

		StringDestroy(&customer);
		StringDestroy(&item);
		StringDestroy(&Bottles);
		StringDestroy(&Rattles);
		StringDestroy(&Diapers);
		return;
	}


	/*
	 * If it is available
	 * Update the inventory located in the Global Variables
	 */
		if(StringIsEqualTo(&item, &Bottles)){
					NumBottles -= item_amount;
				}

		if(StringIsEqualTo(&item, &Rattles)){
				NumRattles -= item_amount;
			}

		if(StringIsEqualTo(&item, &Diapers)){
				NumDiapers -= item_amount;
			}

		if(StringIsEqualTo(&item, &SKU1)){
				NumSKU1 -= item_amount;
			}

		if(StringIsEqualTo(&item, &SKU2)){
			NumSKU2 -= item_amount;
		}



/*
 * Update existing user log
 * If users exist in the database, then returning cutomer = true
 * else, create user log
 */
		int customer_index =0;


			for (int i = 0; i < NumCustomers; i++) {


				if (StringIsEqualTo(&(customers[i].name), &customer)) {
					returning_customer = false;
					customer_index = i;
				}
			}



			if (returning_customer == true) {

					customers[NumCustomers].name = StringDup(&customer);
					customers[NumCustomers].bottles = 0;
					customers[NumCustomers].diapers = 0;
					customers[NumCustomers].rattles = 0;
					customers[NumCustomers].sku1 = 0;
					customers[NumCustomers].sku2 = 0;

					customer_index = NumCustomers;
					NumCustomers++;
				}

			if (StringIsEqualTo(&item, &Bottles)) {
					customers[customer_index].bottles += item_amount;

				} else if (StringIsEqualTo(&item, &Rattles)) {
					customers[customer_index].rattles += item_amount;

				} else if (StringIsEqualTo(&item, &Diapers)) {
					customers[customer_index].diapers +=item_amount;

				} else if (StringIsEqualTo(&item, &SKU1)) {
					customers[customer_index].sku1 += item_amount;

				} else if (StringIsEqualTo(&item, &SKU2)) {
					customers[customer_index].sku2 += item_amount;

				}

			StringDestroy(&customer);
			StringDestroy(&item);
			StringDestroy(&Bottles);
			StringDestroy(&Rattles);
			StringDestroy(&Diapers);



}
#endif




/* Function: processInventory
 * --------------------------------------
 * Records new shipment from the factory
 * Bottles/Diapers/Rattles/ect.
 */
void processInventory() {
	Bottles = StringCreate("Bottles");
	Rattles = StringCreate("Rattles");
	Diapers = StringCreate("Diapers");
	int FoundFlag =0;
	String item_name;
	int item_amount;
	readString(&item_name);
	readNum(&item_amount);

	if(StringIsEqualTo(&item_name, &Bottles)){
		NumBottles += item_amount;
		FoundFlag = 1;
	}

	else if(StringIsEqualTo(&item_name, &Rattles)){
			NumRattles += item_amount;
			FoundFlag = 1;
		}

	else if(StringIsEqualTo(&item_name, &Diapers)){
			NumDiapers += item_amount;
			FoundFlag = 1;
		}

	else if(StringIsEqualTo(&item_name, &SKU1)){
			NumSKU1 += item_amount;
			FoundFlag = 1;
		}

	else if(StringIsEqualTo(&item_name, &SKU2)){
		NumSKU2 += item_amount;
		FoundFlag= 1;
	}

	if(FoundFlag != 1){
		printf("The item does not exist. Please add it in the SKU to be registered\n");
	}


StringDestroy(&Bottles);
StringDestroy(&Rattles);
StringDestroy(&Diapers);
StringDestroy(&item_name);




}

/*
 * Function: processSKU
 * -------------------------------------
 * Adds new items into the SKU
 */

void processSKU(void) { // honors requirement


int Flag =0; //Flag to determine if the value to add into the SKU is a valid entry. 0 = yes 1 = No
String new_item;
readString(&new_item);
Bottles = StringCreate("Bottles");
Rattles = StringCreate("Rattles");
Diapers = StringCreate("Diapers");

/*
* Condtions:
* If both extra custom spaces are full, then prints error message
*/

if(SKU1flag == occupied && SKU2flag == occupied){
	printf("The SKU is out of space for storage\n");
	Flag = 1;

}

/*
* If someone calls upon "SKU Bottles" or something that already exists,
* then it will return the error message "This item already exists"
*/

if(StringIsEqualTo(&new_item, &Bottles)||
   StringIsEqualTo(&new_item, &Rattles)||
    StringIsEqualTo(&new_item,&Diapers)){
	printf("This item already exists!\n");
	Flag = 1;
}


/*
*Checks to see if SKU1 is open
*/

if(SKU1flag == available && Flag ==0){

	SKU1 = StringDup(&new_item);
	SKU1flag = occupied;

}

//Checks to see if SKU2 is open

else if(SKU2flag == available && Flag == 0){
	SKU2 = StringDup(&new_item);
	SKU2flag = occupied;

}
StringDestroy(&new_item);
StringDestroy(&Bottles);
StringDestroy(&Rattles);
StringDestroy(&Diapers);
}






