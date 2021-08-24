/*Use struct Article and a pointer pointed to the struct and print out Article number, 
Quantity and Description (20 characters). Use function Print() to print those out*/
#include <stdio.h>

struct Article					//	Declare the structure Article 
{
	int Num, Qty;
	char Des[20];
};
void Print(struct Article* pt);	//	Declare the Print function to print out Num, Qty and Des.

int main()
{
	//	Initialize the struct Article art and assgin values to each
	struct Article art = { 4, 10, "A test description" }; // for art.Num, art.Qty, are.Des respectively
	struct Article* pt = &art;	//	set a pointer to art's address
	Print(pt);					// Call function Print() to print out those three items
	return 0;
}

/* Function Print() to print Number, Quantity, and Descrption with a pointer as input*/
void Print(Article* pt)
{
	printf("Article Number: %d\n", pt->Num);
	printf("Article Quantity: %d\n", pt->Qty);
	printf("Article Description: %s\n", pt->Des);
	return;
}