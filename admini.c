#include "book_management.h"
#include"admini.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern struct Node* list1;
int flag=1;
void makeMenu3()
{
	printf("------------------------------------\n");
	printf("	librarian model\n");
	printf("\t0.exit\n");
	printf("\t1.add book\n");
	printf("\t2.delete book\n");
	printf("\t3.display books\n");
	printf("\t4.search books\n");
	printf("------------------------------------\n");
	printf("please enter(0~4):");
}


void makeMenu12()
{
    printf("------------------------------------\n");
    printf("	Books search\n");
    printf("\t0.exit\n");
    printf("\t1.search by title\n");
    printf("\t2.search by author\n");
    printf("\t3.search by year\n");
    printf("------------------------------------\n");
    printf("please enter(0~3):");

}
void searchbook1()
{
    makeMenu12();
    Book tempBook;
    char *title;
    char *author;
    int year;
    char temp[50];
    struct Node* result = NULL;
    int userkey;
    scanf("%d",&userkey);
        if(userkey==0)
            printf("exit\n");
        if(userkey==1){

            printf("please enter the title:\n");
            memset(temp,'\0',50);
            getchar();
            gets(temp);
            find_book_by_title (temp,list1);
        }
        if(userkey==2){
            printf("please enter the author:\n");
            memset(temp,'\0',50);
            getchar();
            gets(temp);
            find_book_by_author (temp,list1);}


         if(userkey==2)
         {
             printf("please enter the year:\n");
             scanf("%d",&year);
             find_book_by_year(year,list1);
         }

}
void keydown3()
{

	Book newbook;
	int id;
	int i;
	struct Node* result = NULL;
	int userkey = 0;

	scanf("%d",&userkey);

	if(userkey== 0){
        printf("[exit]\n");
        flag=0;

    }

	else if (userkey==1)
    {   char temp[50];
        printf("enter book information to add book\n");
        printf("please enter the book id:\n");
        scanf("%d",&newbook.id);
        printf("please enter the book title:\n");
        memset(temp,'\0',50);
        getchar();
        gets(temp);
        newbook.title=(char*) malloc(sizeof(strlen(temp)));
        strcpy(newbook.title,temp);
        printf("please enter the book author:\n");
        memset(temp,'\0',50);
        getchar();
        gets(temp);
        newbook.authors=(char*) malloc(sizeof(strlen(temp)));
        strcpy(newbook.authors,temp);
        printf("please enter the book year:\n");
        scanf("%d",&newbook.year);
        printf("please enter the book copies:\n");
        scanf("%d",&newbook.copies);
		i=add_book(newbook,list1);
        if(i)
            printf("add failed");
		}
    else if (userkey==2) {
        printf("enter the ID of the book you want to delete:\n ");
        scanf("%d", &id);
        if(find_book_by_id_bool(id, list1)){
            remove_book(find_book_by_id(id, list1), list1);
            printf("delete successfully\n");
        }
        else
            printf("can't find target book\n");
    }
    else if (userkey==3)
		printList(list1);

    else if (userkey==4)
		searchbook1();

	else
        return;

}


void adimi() {

	while (1)
	{
		makeMenu3();
		keydown3();
        if(!flag)break;
		system("pause");
	}
	return;
}
