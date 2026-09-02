#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"


void listContacts(AddressBook *addressBook) 
{  
    void sortcriteria(AddressBook *addressBook){
        int choice;
        printf("Sort contacts by\n");
        printf("1.Sort by name\n");
        printf("2.Sort by phoneno\n");
        printf("3.Sort by email\n");
        printf("Select your choice\n");
        scanf("%d",&choice);
        for(int i=0;i<addressBook->contactCount-1;i++){
            for(int j=i+1;j<addressBook->contactCount;j++){
                int result=0;
                if(choice==1){
                    result=strcmp(addressBook->contacts[i].name,addressBook->contacts[j].name);
                }
                else if(choice==2){
                    result=strcmp(addressBook->contacts[i].phone,addressBook->contacts[j].phone);
                }
                else if(choice==3){
                    result=strcmp(addressBook->contacts[i].email,addressBook->contacts[j].email);
                }
                else{
                    printf("Invalid choice \n");
                    printf("Enter again\n");
                    sortcriteria(addressBook);
                }
                if(result>0){
                    Contact temp=addressBook->contacts[i];
                    addressBook->contacts[i]=addressBook->contacts[j];
                    addressBook->contacts[j]=temp;
                }
        }

    }
}
    sortcriteria(addressBook);
    printf("%-20s %-20s %-30s\n", "Name", "PhoneNo", "Email");

for(int i = 0; i < addressBook->contactCount; i++)
{
    printf("%-20s %-20s %-30s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
}
    
}



void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}




// validname func
int validname(char name[]){
        int flag=1;
        for(int i=0;name[i]!=0;i++){
            if((!isalnum(name[i] ))&& name[i]!=' '){
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



    //valid phoneno func

int validphoneno(char phone[])
{
    int len = strlen(phone);

    if (len != 10)
    {
        return 0;
    }

    if (phone[0] < '6' || phone[0] > '9')
    {
        return 0;
    }
        for (int i = 1; i < 10; i++)
    {
        if (phone[i] < '0' || phone[i] > '9')
        {
            return 0;
        }
    }

    return 1;
}



//valid email func

int validemail(char email[])
{
    int len = strlen(email);
    
    
    if (strchr(email, ' ') || email[0]==' ')
    {
        return 0;
    }

   
    if ((strchr(email, '@') == NULL) || (email[0] == '@'))
    {
        return 0;
    }
    
   
    if (len < 4 || strcmp(email + len - 4, ".com") != 0)
    {
        return 0;
    }

   
    char *at = strchr(email, '@');
    char *com = strstr(email, ".com");

    if (com - at <= 1)
    {
        return 0;
    }

   
    for (int i = 0; i < len; i++)
    {
        if (!((email[i] >= 'a' && email[i] <= 'z') ||
              (email[i] >= '0' && email[i] <= '9') ||
              email[i] == '@' ||
              email[i] == '.'))
        {
            return 0;
        }
    }
    
   

    return 1;
}



void createContact(AddressBook *addressBook){
	//* Define the logic to create a Contacts */
    
    
    int valid;
    do{
        
        printf("Enter name : ");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
        valid=validname(addressBook->contacts[addressBook->contactCount].name);
       
        if(valid==0){
             printf("Invalid name,enter again\n");
        } 


    }while(valid==0 );
    
 
    

    int valid1,present;
    do{
        printf("Enter phoneno : ");
        scanf("%s",addressBook->contacts[addressBook->contactCount].phone);
       
        valid1=validphoneno(addressBook->contacts[addressBook->contactCount].phone);
        if(valid1==0){
             printf("Invalid phoneno,enter again\n");
        }
   present = 0;

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].phone,
                  addressBook->contacts[addressBook->contactCount].phone) == 0)
        {
            present = 1;
            break;
        }
    }

    if(present == 1)
    {
        printf("Phone no already present, create another phone no\n");
    }
    

    }while(valid1==0 || present==1);



    int valid2;
    do{
       
        printf("Enter email : ");
        scanf(" %s",addressBook->contacts[addressBook->contactCount].email);
        valid2=validemail(addressBook->contacts[addressBook->contactCount].email);
        if(valid2==0){
            printf("Invalid email");
        }
    present = 0;

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].email,addressBook->contacts[addressBook->contactCount].email) == 0)
        {
            present = 1;
            break;
        }
    }

    if(present == 1)
    {
        printf("Email already present, create another email\n");
    }
    }while(valid2==0|| present==1);


    addressBook->contactCount++;


    
}


    


void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    
    int choice;
    do{
    printf("Search contacts by\n");
    printf("1.Search by name\n");
    printf("2.Search by phoneno\n");
    printf("3.Search by email\n");
    printf("Select your choice\n");
    scanf("%d",&choice);
    }
    while(choice < 1 || choice > 3);
    
    
    printf("Enter the contact to search : ");
    char res[50];
    scanf(" %[^\n]",res);
    
    for(int i=0;i<addressBook->contactCount;i++){
        if(choice==1){
        if(strcasestr(res,addressBook->contacts[i].name)!=NULL){
             printf("%-20s %-20s %-30s\n", "Name", "PhoneNo", "Email");
            
              printf("%-20s %-20s %-30s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        }
        else if(choice==2){
             if(strcmp(res,addressBook->contacts[i].phone)==0){
              printf("%-20s %-20s %-30s\n", "Name", "PhoneNo", "Email");
            
              printf("%-20s %-20s %-30s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        }
        else if(choice==3){
            
             if(strcmp(res,addressBook->contacts[i].email)==0){
              printf("%-20s %-20s %-30s\n", "Name", "PhoneNo", "Email");
            
              printf("%-20s %-20s %-30s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        }
        else{
             printf("Contact not found");
        }
    }


}

void editContact(AddressBook *addressBook)
{
   

    int choice;

    do
    {
       printf("Search contact by\n");
       printf("1. Search by name\n");
       printf("2. Search by phone\n");
       printf("3. Search by email\n");
       printf("Select your choice: ");
        scanf("%d", &choice);

    } while(choice < 1 || choice > 3);


    char ans[100];
    char finalans[100];
    int valid;


    

    if(choice == 1)
    {
        int index[100];
        int count = 0;

        printf("Enter the contact name you want to search: ");
        scanf(" %[^\n]", ans);

        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcasecmp(addressBook->contacts[i].name, ans) == 0)
            {
                index[count] = i;
                count++;
            }
        }

        if(count == 0)
        {
            printf("Contact not found\n");
            return;
        }

        for(int i = 0; i < count; i++)
        {
            printf("%-5s %-20s %-20s %-30s\n", "SlNo", "Name", "PhoneNo", "Email");
            printf("%-5d %-20s %-20s %-30s\n",i + 1,addressBook->contacts[index[i]].name,addressBook->contacts[index[i]].phone,addressBook->contacts[index[i]].email);
        }

        int selected;

        do
        {
            printf("Enter which contact slno you want to edit: ");
            scanf("%d", &selected);

            if(selected < 1 || selected > count)
            {
                printf("Invalid choice, enter correct choice\n");
            }

        } while(selected < 1 || selected > count);


        int actualIndex = index[selected - 1];


     
        int editChoice;

        do
        {
            printf("\nWhich field do you want to edit?\n");
            printf("1. Name\n");
            printf("2. Phone\n");
            printf("3. Email\n");
            printf("Enter your choice: ");
            scanf("%d", &editChoice);

        } while(editChoice < 1 || editChoice > 3);


      
        if(editChoice == 1)
        {
            do
            {
                printf("Enter new name: ");
                scanf(" %[^\n]", finalans);

                valid = validname(finalans);

                if(valid == 0)
                {
                    printf("Invalid name, enter again\n");
                }

            } while(valid == 0);

            strcpy(addressBook->contacts[actualIndex].name, finalans);
        }


      
        else if(editChoice == 2)
        {
            do
            {
                printf("Enter new phone: ");
                scanf("%s", finalans);

                valid = validphoneno(finalans);

                if(valid == 0)
                {
                    printf("Invalid phone, enter again\n");
                }

            } while(valid == 0);

            strcpy(addressBook->contacts[actualIndex].phone, finalans);
        }


     
        else
        {
            do
            {
                printf("Enter new email: ");
                scanf("%s", finalans);

                valid = validemail(finalans);

                if(valid == 0)
                {
                    printf("Invalid email, enter again\n");
                }

            } while(valid == 0);

            strcpy(addressBook->contacts[actualIndex].email, finalans);
        }

        printf("Contact updated successfully\n");
    }



    else if(choice == 2)
    {
        int found = 0;

        printf("Enter the contact phone you want to search: ");
        scanf("%s", ans);

        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcmp(addressBook->contacts[i].phone, ans) == 0)
            {
                found = 1;

                printf("1. %s\t%s\t%s\n",
                       addressBook->contacts[i].name,
                       addressBook->contacts[i].phone,
                       addressBook->contacts[i].email);


                int editChoice;

                do
                {
                    printf("\nWhich field do you want to edit?\n");
                    printf("1. Name\n");
                    printf("2. Phone\n");
                    printf("3. Email\n");
                    printf("Enter your choice: ");
                    scanf("%d", &editChoice);

                } while(editChoice < 1 || editChoice > 3);


               
                if(editChoice == 1)
                {
                    do
                    {
                        printf("Enter new name: ");
                        scanf(" %[^\n]", finalans);

                        valid = validname(finalans);

                        if(valid == 0)
                        {
                            printf("Invalid name, enter again\n");
                        }

                    } while(valid == 0);

                    strcpy(addressBook->contacts[i].name, finalans);
                }


              
                else if(editChoice == 2)
                {
                    do
                    {
                        printf("Enter new phone: ");
                        scanf("%s", finalans);

                        valid = validphoneno(finalans);

                        if(valid == 0)
                        {
                            printf("Invalid phone, enter again\n");
                        }

                    } while(valid == 0);

                    strcpy(addressBook->contacts[i].phone, finalans);
                }


               
                else
                {
                    do
                    {
                        printf("Enter new email: ");
                        scanf("%s", finalans);

                        valid = validemail(finalans);

                        if(valid == 0)
                        {
                            printf("Invalid email, enter again\n");
                        }

                    } while(valid == 0);

                    strcpy(addressBook->contacts[i].email, finalans);
                }

                printf("Contact updated successfully\n");
                return;
            }
        }

        if(found == 0)
        {
            printf("Contact not found\n");
        }
    }


   

    else if(choice == 3)
    {
        printf("Enter the contact email you want to search: ");
        scanf("%s", ans);

        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcmp(addressBook->contacts[i].email, ans) == 0)
            {
                printf("1. %s\t%s\t%s\n",
                       addressBook->contacts[i].name,
                       addressBook->contacts[i].phone,
                       addressBook->contacts[i].email);


                int editChoice;

                do
                {
                    printf("\nWhich field do you want to edit?\n");
                    printf("1. Name\n");
                    printf("2. Phone\n");
                    printf("3. Email\n");
                    printf("Enter your choice: ");
                    scanf("%d", &editChoice);

                } while(editChoice < 1 || editChoice > 3);


              
                if(editChoice == 1)
                {
                    do
                    {
                        printf("Enter new name: ");
                        scanf(" %[^\n]", finalans);

                        valid = validname(finalans);

                        if(valid == 0)
                        {
                            printf("Invalid name, enter again\n");
                        }

                    } while(valid == 0);

                    strcpy(addressBook->contacts[i].name, finalans);
                }


            
                else if(editChoice == 2)
                {
                    do
                    {
                        printf("Enter new phone: ");
                        scanf("%s", finalans);

                        valid = validphoneno(finalans);

                        if(valid == 0)
                        {
                            printf("Invalid phone, enter again\n");
                        }

                    } while(valid == 0);

                    strcpy(addressBook->contacts[i].phone, finalans);
                }


                
                else
                {
                    do
                    {
                        printf("Enter new email: ");
                        scanf("%s", finalans);

                        valid = validemail(finalans);

                        if(valid == 0)
                        {
                            printf("Invalid email, enter again\n");
                        }

                    } while(valid == 0);

                    strcpy(addressBook->contacts[i].email, finalans);
                }

                printf("Contact updated successfully\n");
                return;
            }
        }

        printf("Contact not found\n");
    }
}



void deleteContact(AddressBook *addressBook)
{
    
    int choice;

    do
    {
        printf("Search contacts by\n");
        printf("1. Search by name\n");
        printf("2. Search by phoneno\n");
        printf("3. Search by email\n");
        printf("Select your choice: ");
        scanf("%d", &choice);

    } while(choice < 1 || choice > 3);


    char res[50];

    printf("Enter the contact you want to search: ");
    scanf(" %[^\n]", res);


   

    if(choice == 1)
    {
        int index[100];
        int count = 0;

        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcasecmp(addressBook->contacts[i].name, res) == 0)
            {
                index[count] = i;
                count++;
            }
        }

        if(count == 0)
        {
            printf("Contact not found\n");
            return;
        }

        printf("%-5s %-20s %-20s %-30s\n",
               "SlNo", "Name", "PhoneNo", "Email");

        for(int i = 0; i < count; i++)
        {
            printf("%-5d %-20s %-20s %-30s\n",
                   i + 1,
                   addressBook->contacts[index[i]].name,
                   addressBook->contacts[index[i]].phone,
                   addressBook->contacts[index[i]].email);
        }


        int selected;

        do
        {
            printf("Select the slno of the contact you want to delete: ");
            scanf("%d", &selected);

            if(selected < 1 || selected > count)
            {
                printf("Invalid choice, enter correct choice\n");
            }

        } while(selected < 1 || selected > count);


        int actualIndex = index[selected - 1];


        for(int j = actualIndex;
            j < addressBook->contactCount - 1;
            j++)
        {
            addressBook->contacts[j] =
                addressBook->contacts[j + 1];
        }

        addressBook->contactCount--;

        printf("Contact deleted successfully\n");
    }


   

    else if(choice == 2)
    {
        int found = 0;
        int actualIndex;

        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcmp(res, addressBook->contacts[i].phone) == 0)
            {
                found = 1;
                actualIndex = i;
                break;
            }
        }

        if(found == 0)
        {
            printf("Contact not found\n");
            return;
        }


        printf("%-5s %-20s %-20s %-30s\n",
               "SlNo", "Name", "PhoneNo", "Email");

        printf("%-5d %-20s %-20s %-30s\n",
               1,
               addressBook->contacts[actualIndex].name,
               addressBook->contacts[actualIndex].phone,
               addressBook->contacts[actualIndex].email);


        int selected;

        do
        {
            printf("Select the slno of the contact you want to delete: ");
            scanf("%d", &selected);

            if(selected != 1)
            {
                printf("Invalid choice, enter correct choice\n");
            }

        } while(selected != 1);


        for(int j = actualIndex;
            j < addressBook->contactCount - 1;
            j++)
        {
            addressBook->contacts[j] =
                addressBook->contacts[j + 1];
        }

        addressBook->contactCount--;

        printf("Contact deleted successfully\n");
    }


    

    else if(choice == 3)
    {
        int found = 0;
        int actualIndex;

        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcmp(res, addressBook->contacts[i].email) == 0)
            {
                found = 1;
                actualIndex = i;
                break;
            }
        }

        if(found == 0)
        {
            printf("Contact not found\n");
            return;
        }


        printf("%-5s %-20s %-20s %-30s\n",
               "SlNo", "Name", "PhoneNo", "Email");

        printf("%-5d %-20s %-20s %-30s\n",
               1,
               addressBook->contacts[actualIndex].name,
               addressBook->contacts[actualIndex].phone,
               addressBook->contacts[actualIndex].email);


        int selected;

        do
        {
            printf("Select the slno of the contact you want to delete: ");
            scanf("%d", &selected);

            if(selected != 1)
            {
                printf("Invalid choice, enter correct choice\n");
            }

        } while(selected != 1);


        for(int j = actualIndex;
            j < addressBook->contactCount - 1;
            j++)
        {
            addressBook->contacts[j] =
                addressBook->contacts[j + 1];
        }

        addressBook->contactCount--;

        printf("Contact deleted successfully\n");
    }
}