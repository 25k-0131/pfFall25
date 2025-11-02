#include <stdio.h>
#include <string.h>


void encodeMessage(char message[]);
void decodeMessage(char message[]);
void reverse(char message[]);


int main (void)
{
	int choice;
	char message[200];
	do{
	
		printf("\nMENU\n");
		printf("1. Encode message\n2. Decode message\n3.Exit\n");
		printf("Select you choice: ");
		scanf("%d", &choice);
    
    
	    switch(choice)
	    {
	    	case 1:
	    		printf("Enter message to encode: ");
	    		scanf(" %[^\n]", message); 
	            encodeMessage(message);
	            printf("Encoded message: %s\n", message);
	            break;
	            
	    	case 2:
	    		printf("Enter message to decode: ");
	    		scanf(" %[^\n]", message); 
	            decodeMessage(message);
	            printf("Decoded message: %s\n", message);
				break;
			case 3:
				printf("Exiting...\n");
				break;
			default:
				printf("Enter correct number again\n");
		}
		
	} while(choice!=3);
	
	return 0;
}



void reverse(char message[])
{
	int i;
	int len = strlen(message); 
	for (i=0; i<len/2; i++)
	{
	int temp = message[i];
	message[i]= message[len-i-1];
	message[len-i-1] = temp;
   }
}
   
void encodeMessage(char message[]) 
{
	int len = strlen(message); 

	int i;
	reverse(message);
	
	for (i=0; i<len; i++)
   {
   		message[i]^=((1<<1) | (1<<4));      	
   }
	return;
	
  }  
   
	

void decodeMessage(char message[])
{
	int len = strlen(message); 

	int j;
	
	for (j=0; j<len; j++)
   {
   		message[j]^=((1<<1) | (1<<4));      	
   }
   reverse(message);
	return;
}
