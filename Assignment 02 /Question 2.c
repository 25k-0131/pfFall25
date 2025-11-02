#include <stdio.h>
#include <string.h>

	int productCode[] = {1,2,3,4};
	int Quantity[] = {50, 10, 20 , 8};
	float price[]= {100, 200, 300, 150};
	int products = 4;
	
	char name[50];
	char cnic[50];
	
	int cartProductCode[50];
	int cartQuantity[50];
	int cartcount = 0;
	
	float totalBill=0, finalBill=0;
	int n, discount=0;
	
	
void CustomerInformation();
void DisplayInventory();
void AddItem();
void TotalBill();
void ApplyPromo();
void ShowInvoice();	





int main (void)
{
	

	
	do
	{
		printf("\nWelcome to Supermarket\n1. Customer Information\n2. Display inventory\n3. Add item to cart\n4. Display total bill\n5. Show invoice\n6. Exit\n");
		printf(" Select any one Option to contnue: ");
		scanf("%d", &n);
		
		switch(n)
		{
			case 1:
				 CustomerInformation();
				 break;
			case 2:
				DisplayInventory();
				break;
			case 3:
				AddItem ();
				break;
			case 4:
				TotalBill ();
				break;
			case 5:
				ShowInvoice ();
				break;
			case 6:
                printf("Thank you for visiting! Goodbye.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                				
		}
		
		
		

	}while(n!=6);
	
	


	return 0;
	
}


void CustomerInformation()
{

	
	printf("Enter name: ");
	scanf(" %[^\n]" ,name);
	
	printf("Enter CNIC: ");
	scanf(" %[^\n]", cnic);
   printf("Customer details saved successfully!\n");
	
	return;
}

 

void DisplayInventory ()
{
	printf("\nCode\tQuantity\tPrice\n");
	int i;
	for (i=0; i<products; i++)
	{
		printf("Code: %03d\tQuantity: %d\tPrice: %.2f\n", productCode[i], Quantity[i],  price[i] );
	}
	return;
}

void AddItem ()
{
	int i,pcode, q, found=0;
	
	printf("Enter product code: ");
	scanf("%d", &pcode);
	
	for (i=0; i<products; i++)
	{
		if (pcode == productCode[i])
		{
			found = 1;
			printf("Enter Quantity: ");
			scanf("%d", &q);
			
			if (q<=Quantity[i])
			{
				cartProductCode[cartcount] = pcode;
				cartQuantity[cartcount] = q;
				cartcount++;
				Quantity[i] -= q;
				printf("Item added successfully\n");
				 
			}
			else
			{
				printf("Out of Stock\n");
			}
			break;
		}
		
	}
	if (!found)
	{
		printf("Item not found\n");
		
	}
	return;
		
}

void TotalBill ()
{
	int i, j;
	totalBill=0;
    printf("\nCode\tQty\tPrice\tSubtotal\n");
	
	
	for (i=0; i<cartcount; i++)
	{
		for (j = 0; j<products; j++)
		{
			if (cartProductCode[i] == productCode[j])
			{
                float subtotal = price[j] * cartQuantity[i];

				totalBill += subtotal;
				printf("Code: %03d\tQuantity: %d\tPrice: %.2f\t Total: %.2f\n", cartProductCode[i], cartQuantity[i], price[j], subtotal);			
			}
			
		}
		
	}
	
	printf("Total Bill: %.2f\n", totalBill);
	return;
}

void ApplyPromo() {
	discount = 0;
    char code[20];
    
    printf("\nEnter promo code or 'no' if none: ");
    scanf("%s", code);

    if (strcmp(code, "Eid2025") == 0) {
    	discount = 1;
        printf("Promo code applied! You got 25%% off.\n");
        finalBill = totalBill * 0.75;
		
    }
    else {
        printf("No promo applied.\n");
        finalBill = totalBill;
    }
    return;
}
void ShowInvoice ()
{
	if (discount == 0)
	{
		ApplyPromo();
	}
	
	printf("\n===== CUSTOMER INVOICE =====\n");

	printf("Customer name: %s\n", name);
	printf("Customer CNIC: %s\n", cnic);
	
	printf("Total Bill Before Discount: %.2f\n", totalBill);
	
	if (discount) {
        printf("Discount Applied: 25%%\n");
    } else {
        printf("No Discount Applied\n");
    }

    printf("Final Payable Amount: %.2f\n", finalBill);
    
    return;


}
