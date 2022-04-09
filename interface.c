#include "interface.h"
#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
extern struct Node* list1;
extern struct Nd* list2;
int flag1=1;
void makeMenu1()
{
	printf("------------------------------------\n");
	printf("	Books Management System\n");
	printf("\t0.exit\n");
	printf("\t1.log in\n");
	printf("\t2.register\n");
	printf("\t3.display books\n");
	printf("\t4.search books\n");
	printf("------------------------------------\n");
	printf("please enter(0~4):");
}


void makeMenu2()
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
void searchbook()
{
		makeMenu2();
		Book tempBook; 
		char *title;
		char *author;
		int year; 
		struct Node* result = NULL;
		int userkey;
		scanf("%d",&userkey);
		switch (userkey)
		{
            case 0:
                printf("exit\n");
                break;
		    case 1:
			
			    printf("please enter the title:\n");
			    scanf("%s",title);
			    find_book_by_title (title,list1);
			    break;
		    case 2:
			
                printf("please enter the author:\n");
                scanf("%s",author);
                find_book_by_author (author,list1);
                break;
            case 3:

                printf("please enter the year:\n");
                scanf("%d",&year);
                find_book_by_year(year,list1);
                break;
            default:
                break;
		}
}
void keydown1()
{
	struct Node* result = NULL;
	int userkey = 0;
	scanf("%d",&userkey);
	switch (userkey)
	{
	case 0:
		printf("[ exit ]\n");
		printf("exit successfully\n");
		flag1=0;
		break;
	case 1:
		userlog();
		break;
	case 2:
		userreg();
		break;
	case 3:
		printList(list1);
		break;
	case 4:
		searchbook();
		break;
	default:
		break;
	}
}

void run_interface() {

    list1=createHead();
    list2=createHead1();
    int a=load_books(list1,"book.txt");
    while (1)
	{
		makeMenu1();
		keydown1();
        if(!flag1)break;
		system("pause");
	}
    int b=store_books(list1,"book.txt");
	return;
}
