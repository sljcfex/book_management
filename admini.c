#include "interface.h"
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



void keydown3()
{
	Book tempBook; 
	Book newbook;
	int id;
	int i;
	struct Node* result = NULL;
	int userkey = 0;
	scanf("%d",&userkey);
	switch (userkey)
	{
	case 0:
		printf("[exit]\n");
		flag=0;
		break;
	case 1:
		
        printf("enter book information to add book\n");
        printf("please enter the book id:\n");
        scanf("%d",&newbook.id);
        printf("please enter the book title:\n");
        scanf("%s",newbook.title);
        printf("please enter the book author:\n");
        scanf("%s",newbook.authors);
        printf("please enter the book year:\n");
        scanf("%d",&newbook.year);
        printf("please enter the book copies:\n");
        scanf("%d",&newbook.copies);
		i=add_book(newbook,list1);
        if(i)
            printf("add failed");
		break;
	case 2:
		printf("enter the ID of the book you want to delete ");
        
        scanf("%d",&id);
        remove_book(find_book_by_id (id,list1),list1);
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
