#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"


void listContacts(AddressBook *addressBook) 
{ 
    //int sortcriteria(int )
    printf("Name: %s\tPhoneNo: %s\tEmail: %s\n");
    
    for(int i=0;i<addressBook -> contactCount;i++){
         printf("%s\t%s\t%s\t",addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
    }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	//* Define the logic to create a Contacts */
    int validname(char name[]){
        int flag=1;
        for(int i=0;name[i]!=0;i++){
            if((!isalpha(name[i] ))&& name[i]!=' '){
                flag=0;
                break;
            }
        }
        if(flag==0){
            return 0;
        }
        else{
            return 1;
        }
    }
    addressBook->contactCount=0;
    int valid;
    do{
        
        printf("Enter name");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
        valid=validname(addressBook->contacts[addressBook->contactCount].name);
        if(valid==0){
             printf("Invalid name,enter again");
        }

    }while(valid==0);
    int validphoneno(char phone[]){
        int len=strlen(phone);
        if(phone[0]>5 && len==10){
            return 1;
        }
        else{
            return 0;
        }
    }
    int valid1;
    do{
        printf("Enter phoneno");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);
        valid1=validphoneno(addressBook->contacts[addressBook->contactCount].phone);
        if(valid1==0){
             printf("Invalid phoneno,enter again");
        }

    }while(valid1==0);
    int validemail(char email[]){
        int len=strlen(email);
        int flag=1;
        for(int i=0;email[i]!=0;i++){
            if(!islower(email[i])){
                flag=0;
                break;
            }
        }
        if(flag==1){
        
         if(!strchr(email,' ')){
            if(strchr(email,'@') && email[0]!='@'){
                if(strcmp(email+len-4,".com")==0){
                    char* at=strchr(email,'@');
                    char* com=strstr(email,".com");
                    if((com-at)!=1){
                        return 1;
                    }
                }
            }
        }
    }
        return 0;
    }
    int valid2;
    do{
       
        printf("Enter email");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
        valid2=validemail(addressBook->contacts[addressBook->contactCount].email);
        if(valid2==0){
            printf("Invalid email,enter again");
        }
    }while(valid2==0);


    }


    


void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */

}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   
}
