#include <stdio.h>
#include <string.h>


void AddNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int* bookcount);
void ProcessSale(int isbns[], char titles[][50], float prices[], int quantities[], int* bookcount);
void LowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int* bookcount);


int main(void)

{
	int n, count=0;
    int isbns[100];
	char titles[100][50];
	float prices[100];
	int quantities[100];
	
	do{
		printf("\nWelcome To Liberty Books.\n1. Add a new book\n2.Process a sale\n3.Generate Low Stock Report\n4.Exit \n");
		printf("Choose any One option: ");
		scanf("%d", &n);
		
		switch(n)
		{
			case 1:
				AddNewBook(isbns, titles, prices, quantities, &count);
				break;
			case 2:
				ProcessSale(isbns, titles, prices, quantities, &count);
				break;
			case 3:
				LowStockReport(isbns, titles, prices, quantities, &count);
				break;
			case 4:
				printf("Exiting...\n");
				return 0;
			default:
				printf("Enter valid number. Try again.\n");
			
	    }
   }while(n!=4); 
		
}
	

void AddNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int* bookcount)
{
	int newIsbn;
	char newTitle[50];
	float newPrice;
	int newQuantity;
	int i;
	
	
	printf("Enter ISBN: ");
	scanf("%d", &newIsbn);
	
	for (i=0; i<*bookcount; i++)
	{
		if (newIsbn == isbns[i])
		{
			printf("Book already exists\n");
			return;
		}
    }
	    
	    printf("Enter Title: ");
		scanf(" %[^\n]", newTitle);
	
		printf("Enter Price: ");
		scanf("%f", &newPrice);
	
		printf("Enter Quantity: ");
		scanf("%d", &newQuantity);
		
		isbns[*bookcount] = newIsbn;
		strcpy (titles[*bookcount], newTitle);
		prices[*bookcount] = newPrice;
		quantities[*bookcount] = newQuantity;
		
		(*bookcount)++;
		
		printf("Book added successfully!\n");

		return;	
	
}

void ProcessSale(int isbns[], char titles[][50], float prices[], int quantities[], int* bookcount)
{
	int newIsbn, newQuantity,i, flag=0;
	
	printf("Enter ISBN: ");
	scanf("%d", &newIsbn);
	

	
	for (i=0; i<*bookcount; i++)
	{
		if (newIsbn == isbns[i])
		{
			flag = 1;
			printf("Enter Quantity Sold: ");
			scanf("%d", &newQuantity);
			
			if (quantities[i] >= newQuantity)
			{
				quantities[i]-= newQuantity;
                printf("Sale processed successfully! Remaining stock: %d\n", quantities[i]);

			}
			else{
				
				printf("Out of Stock\n");
			}
			break;
		}

		}
		if (!flag)
		{
			printf("Book not found\n");
		}
    }
void LowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int* bookcount)
{
	printf("\n Low Stock Report (Quantity < 5)\n");

	int i,lowStockFound=0;
	for (i=0; i<*bookcount; i++)
	{
		if (quantities[i]<5)
		{
			printf("ISBN: %d\tTitle: %s\tPrice: %.2f\tQuantity: %d\n",isbns[i], titles[i], prices[i], quantities[i]);
            lowStockFound = 1;
		}
	}
	if (!lowStockFound) {
        printf("All books have sufficient stock.\n");
    }
}
