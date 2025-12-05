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
    char name[20];
    char email[20];
    char phone[15];
    int saved;
} contact_t;

void listContacts(int numOfContacts, contact_t contacts[]);
void addContact(int *numOfContacts, contact_t contacts[]);
void saveContacts(int numOfContacts, contact_t contacts[]);
void loadContacts(contact_t contacts[]);
int getNumOfContacts(contact_t contacts[]);
void search(contact_t contacts[]);
int findEmptyContactIndex(contact_t contacts[]);
void deleteContact(contact_t contacts[]);

int main(void)
{    
    contact_t contacts[50] = {};
    loadContacts(contacts);
    int numOfContacts = 0;
    numOfContacts = getNumOfContacts(contacts);


    
   
    int userInput = 0;

    while(userInput != 5)
    {
        puts("1. list contacts");
        puts("2. add contact");
        puts("3. search contacts");
        puts("4. delete contact");
        puts("5. save and quit");
        
        scanf("%d", &userInput);
        switch(userInput)
        {
            case 1:
                listContacts(numOfContacts, contacts);
                break;
            case 2: 
                addContact(&numOfContacts, contacts);
                break;
            case 3:
                search(contacts);
                break;
            case 4:
                deleteContact(contacts);
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
    scanf("%s", contacts[openSpot].name);
    puts("enter an email");
    scanf("%s", contacts[openSpot].email);
    puts("enter a phone number");
    scanf("%s", contacts[openSpot].phone);

    contacts[*numOfContacts].saved = 1;
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
        printf("Name: %s\n", contacts[i].name);
        printf("Email: %s\n", contacts[i].email);
        printf("Phone: %s\n", contacts[i].phone);
        printf("\n");
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

void loadContacts(contact_t contacts[])
{
    
    FILE *file = fopen("contacts.bin", "rb");
    if (file != NULL)
    {
        fread(contacts, sizeof(contact_t), 50, file);
        fclose(file); 
        
    }

}

int getNumOfContacts(contact_t contacts[])
{
   FILE *file = fopen("contacts.bin", "rb");
    if (file != NULL)
    {
        int count = fread(contacts, sizeof(contact_t), 50, file);
        fclose(file); 
        return count;
        
    }
}

void search(contact_t contacts[])
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
            break;
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

void deleteContact(contact_t contacts[])
{

    puts("Enter an index to delete");
    int index = 0;
    scanf("%d", &index);

    contact_t empty = {'\0'};
    contacts[index]= empty;
    
    
}