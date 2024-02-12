#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct Library
{
    int NO;
    char name[100];
    char Wname[100];
    char page[100];
    float Price;
    struct Library *next;


}* head;

void insert(int NO, char* name, char* Wname, char* page, float Price)
{

   struct Library * Library = (struct Library *) malloc(sizeof(struct Library));
	Library->NO = NO;
	strcpy(Library->name, name);
    strcpy(Library->Wname, Wname);
	strcpy(Library->page, page);
	Library->Price = Price;
	Library->next = NULL;

	if(head==NULL){

		head = Library;
	}
	else{

		Library->next = head;
		head = Library;
	}

}

void search(int NO)
{
    struct Library * temp = head;
	while(temp!=NULL){
		if(temp->NO==NO){
			printf("\nBook Serial Number : %d\n", temp->NO);
			printf("Book Name : %s\n", temp->name);
            printf("Author Name : %s\n", temp->Wname);
			printf("Page Number : %s\n", temp->page);
			printf("Book Price : %0.2f\n", temp->Price);
			return;
		}
		temp = temp->next;
	}
	printf("Book Serial with Serial number %d is not found !!!\n", NO);
}

void update(int NO)
{
    struct Library * temp = head;
	while(temp!=NULL){

		if(temp->NO==NO){
			printf("Record with Book Serial Number %d Found !!!\n", NO);
			printf("Enter new book name: ");
			scanf("%s", temp->name);
			printf("Enter new author name  : ");
			scanf("%s", temp->Wname);
			printf("Enter new page number: ");
			scanf("%s", temp->page);
			printf("Enter new Price: ");
			scanf("%f",&temp->Price);
			printf("Updation Successful!!!\n");
			return;
		}
		temp = temp->next;
	}
	printf("Book with Serial number %d is not found !!!\n", NO);
}

void Delete(int NO)
{
    struct Library * temp1 = head;
	struct Library * temp2 = head;
	while(temp1!=NULL){
		if(temp1->NO==NO){
			printf("Record with serial number %d found !!!\n", NO);
			if(temp1==temp2){
				head = head->next;
				free(temp1);
			}
			else{
				temp2->next = temp1->next;
				free(temp1);
			}
			printf("Record Successfully Deleted !!!\n");
			return;
		}
		temp2 = temp1;
		temp1 = temp1->next;
	}
	printf("Book with Serial number %d is not found !!!\n", NO);

}
void display()
{
    struct Library * temp = head;
	while(temp!=NULL){

		printf("Book Serial number : %d\n", temp->NO);
		printf("Book Name : %s\n", temp->name);
		printf("Author Name : %s\n", temp->Wname);
		printf("Page Number : %s\n", temp->page);
		printf("Book Price : %0.2f\n\n", temp->Price);
		temp = temp->next;

	}
}

int main()
{
    head = NULL;
    int choice;
    char name[30];
    char Wname[30];
    char page[30];
    int NO;
    float Price;
    printf("1 to insert book details\n2 to search for book details\n3 to delete book details\n4 to update book details\n5 to display all book details");
    do
    {
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\nEnter Book Serial Number : ");
                scanf("%d", &NO);
                printf("Enter Book Name: ");
                scanf("%s", name);
                printf("Enter Author : ");
                scanf("%s", Wname);
                printf("Enter Page Number: ");
                scanf("%s", page);
                printf("Enter Book Price: ");
                scanf("%f", &Price);
                insert(NO, name, Wname, page, Price);
                break;
            case 2:
                printf("\nEnter Book Serial number to search : ");
                scanf("%d", &NO);
                search(NO);
                break;
            case 3:
                printf("\nEnter Book Serial number to delete : ");
                scanf("%d", &NO);
                Delete(NO);
                break;
            case 4:
                printf("\nEnter Book Serial number to update : ");
                scanf("%d", &NO);
                update(NO);
                break;
            case 5:
                display();
                break;

        }

    } while (choice != 0);
}

