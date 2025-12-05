#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
allows user add new contact, display list of contacts or save and quit.  

next things to add
-edit contacts
-delete contacts
-contact search by name or phone number
-adding some more notes
*/

typedef struct contact {
    char name[30];
    char email[30];
    char phone[15];
} contact_t;

void listContacts(int numOfContacts, contact_t contacts[]);
void addContact(int *numOfContacts, contact_t contacts[]);
void saveContacts(int numOfContacts, contact_t contacts[]);
int loadContacts(contact_t contacts[]);

int search(contact_t contacts[]);
int findEmptyContactIndex(contact_t contacts[]);
void deleteContact(contact_t contacts[], int i);
void edit(contact_t contacts[], int i);

int main(void)
{    
    contact_t contacts[50] = {};
    
    int numOfContacts = 0;
    numOfContacts = loadContacts(contacts);
    
    int userInput = 0;

    while(userInput != 5)
    {
        puts("1. list contacts");
        puts("2. add contact");
        puts("3. search contacts");
        puts("4. delete contact");
        puts("5. save and quit");
        
        scanf("%d", &userInput);

        int listMenu = 0;
        int searchResult = 0;
        switch(userInput)
        {
            case 1:
                listContacts(numOfContacts, contacts);
               
                searchResult = search(contacts);
                puts("1. menu");
                puts("2. edit contact");

                scanf("%d", &listMenu);

                if (listMenu == 1)
                {
                    break;
                }
                else
                {
                    edit(contacts, searchResult);
                }
                
                break;
            case 2: 
                addContact(&numOfContacts, contacts);
                break;
            case 3:
                search(contacts);
                break;
            case 4:
                deleteContact(contacts, 0);
                break;
            default:
            break;
        }
    }
 
    saveContacts(numOfContacts, contacts); 

}

void addContact(int *numOfContacts, contact_t contacts[])
{
    int openSpot = findEmptyContactIndex(contacts);
    puts("enter a name");
    scanf("%30s", contacts[openSpot].name);
    puts("enter an email");
    scanf("%30s", contacts[openSpot].email);
    puts("enter a phone number");
    scanf("%15s", contacts[openSpot].phone);

    *numOfContacts = *numOfContacts +1;
}

void listContacts(int numOfContacts, contact_t contacts[])
{
   // FILE *file = fopen("contacts.bin", "rb");
   // fread(contacts, sizeof(contact_t), numOfContacts, file);
   // fclose(file); 
   
    for(int i = 0; i < numOfContacts; i++)
    {
        if(contacts[i].name[0] != '\0')
        {
        printf("%s\n", contacts[i].name);
        
        }
    }

}

void saveContacts(int numOfContacts, contact_t contacts[])
{
    FILE *file = fopen("contacts.bin", "wb");
    if (file != NULL)
    {
        fwrite(contacts, sizeof(contact_t), numOfContacts, file);
        fclose(file); 
    }
    
}

int loadContacts(contact_t contacts[])
{
    int count = 0;
    FILE *file = fopen("contacts.bin", "rb");
    if (file != NULL)
    {
        count = fread(contacts, sizeof(contact_t), 50, file);
        fclose(file); 
        
    }
    return count;

}

int search(contact_t contacts[])
{
    puts("enter contact name");
    char buffer[20] = {'\0'};
    
    scanf(" %s", buffer);

    
    int searchLength = strlen(buffer);
    
    for(int i = 0; i < 50; i++)
    {

        if (strncmp(buffer, contacts[i].name, searchLength) == 0)
        {
            printf("Name: %s\n", contacts[i].name);  
            printf("Email: %s\n", contacts[i].email);
            printf("Phone: %s\n", contacts[i].phone);
            printf("\n");
            return i;
        }

    }
}

int findEmptyContactIndex(contact_t contacts[])
{
    for(int i = 0; i < 50; i++)
    {
        if (contacts[i].name[0] == '\0')
        return i;
    }
}

void deleteContact(contact_t contacts[], int i)
{
    contact_t empty = {'\0'};
    contacts[i]= empty;
    puts("contact deleted");
}

void edit(contact_t contacts[], int i)
{
  
    int userInput = 0;

   
    while (userInput != 5)
    {
        puts("1. edit name");
        puts("2. edit email");
        puts("3. edit phone number");
        puts("4. delete contact");
        puts("5. menu");
        scanf("%d", &userInput);
        switch (userInput)
        {
        case 1:
            puts("enter new name");
            scanf(" %s", contacts[i].name);
            break;
        case 2:
            puts("enter new email");
            scanf(" %s", contacts[i].email);
            break;
        case 3:
            puts("enter new phone number");
            scanf(" %s", contacts[i].phone);
            break;
        case 4:
            deleteContact(contacts, i);
        
        default:
            break;
        }
    }
}






