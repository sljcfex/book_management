#include "book_management.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
/*You can extend the structs (Book and BookList) defined in this head file;
  However, you may not change the function prototypes. 
  You are also free to add additional head files and data structures as needed. 
*/
struct Node* createHead()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}
struct Node* createNode(Book book)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->book = book;
	newNode->next = NULL;   
	return newNode;
}

struct Node* list1 = NULL;
//saves the database of books in the specified file
//returns 0 if books were stored correctly, or an error code otherwise
int store_books(struct Node* headNode,const char* filename)
{
	FILE* fp = fopen(filename, "w");
	struct Node* pMove = headNode->next;
	while (pMove != NULL)
	{
		fprintf(fp, "%d\t%s\t%s\t%d\t%d\n", pMove->book.id, pMove->book.title, pMove->book.authors,pMove->book.year,pMove->book.copies);
		pMove = pMove->next;
	}
	fclose(fp);
	return 0;
}

//loads the database of books from the specified file
//the file must have been generated by a previous call to store_books()
//returns 0 if books were loaded correctly, or an error code otherwise
int load_books(struct Node* headNode,const char* filename)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fp = fopen(filename, "w+");
	}
	Book booka;
	while (fscanf(fp, "%d\t%s\t%s\t%d\t%d\n", booka.id, booka.title, booka.authors,booka.year,booka.copies) != EOF)
	{
		add_book(booka,list1 );
	}
	fclose(fp);
	return 0;
}

//adds a book to the ones available to the library
//returns 0 if the book could be added, or an error code otherwise
int add_book(Book book,struct Node* headNode)
{
	struct Node* newNode = createNode(book);
	newNode->next = headNode->next;
	headNode->next = newNode;
	return 0;
}

void printList(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
	printf("ID\ttitle\tauthor\tyear\tcopies\n");
	while(pMove != NULL)
	{
		printf("%d\t%s\t%s\t%d\t%d\n", pMove->book.id, pMove->book.title, pMove->book.authors,pMove->book.year,pMove->book.copies);
		pMove = pMove->next;
	}
}
Book find_book_by_id (const int id,struct Node* headNode)
{
    struct Node* posNode = headNode->next;
    while(posNode!=NULL)
    {
        if(posNode->book.id==id)
        {
            return posNode->book;
        }
        posNode=posNode->next;
    }
}


//removes a book from the library
//returns 0 if the book could be successfully removed, or an error code otherwise.
int remove_book(Book book,struct Node* headNode)
{
	int id=book.id;
	struct Node* posLeftNode = headNode;
	struct Node* posNode = headNode->next;
	while (posNode != NULL && posNode->book.id==id)
	{
		posLeftNode = posNode;
		posNode = posLeftNode->next;
	}
	if (posNode == NULL)
	{
		return 0;
	}
	else
	{
		printf("\n");
		posLeftNode->next = posNode->next;
		free(posNode);
		posNode = NULL;
	}
	return 0;
}

//finds books with a given title.
//returns a BookList structure, where the field "list" is a list of books, or null if no book with the 
//provided title can be found. The length of the list is also recorded in the returned structure, with 0 in case
//list is the NULL pointer.
BookList find_book_by_title (const char *title,struct Node* headNode)
{
	BookList booklist; 
	booklist.length=0;
	struct Node* posNode = headNode->next;
	struct Node* posNode1 = headNode->next;
	while (posNode != NULL )
	{
		if( strcmp(posNode->book.title,title))
		{
			booklist.length++;
		}
		posNode = posNode->next;
	}
	if(!booklist.length)
	{
		printf("no book found!\n");
		return ;
	}
	printf("ID\ttitle\tauthor\tyear\tcopies\n");
	while (posNode1 != NULL )
	{
		if( strcmp(posNode->book.title, title)==0)
		{
			printf("%d\t%s\t%s\t%d\t%d\n", posNode1->book.id, posNode1->book.title, posNode1->book.authors,posNode1->book.year,posNode1->book.copies);
		}
		posNode1 = posNode1->next;
	}
	return booklist;
}

//finds books with the given authors.
//returns a Booklist structure, where the field "list" is a newly allocated list of books, or null if no book with the 
//provided title can be found. The length of the list is also recorded in the returned structure, with 0 in case
//list is the NULL pointer.
BookList find_book_by_author (const char *author,struct Node* headNode)
{
	BookList booklist; 
	booklist.length=0;
	struct Node* posNode = headNode->next;
	struct Node* posNode1 = headNode->next;
	while (posNode != NULL)
	{
		if( strcmp(posNode->book.authors,author))
		{
			booklist.length++;
		}
		posNode = posNode->next;
	}
	if(!booklist.length)
	{
		printf("no book found!\n");
		return ;
	}
	printf("ID\ttitle\tauthor\tyear\tcopies\n");
	while (posNode1 != NULL )
	{
		if(strcmp(posNode->book.authors, author)==0)
		{
			printf("%d\t%s\t%s\t%d\t%d\n", posNode1->book.id, posNode1->book.title, posNode1->book.authors,posNode1->book.year,posNode1->book.copies);
		}
		posNode1 = posNode1->next;
	}
	return booklist;
}


//finds books published in the given year.
//returns a Booklist structure, where the field "list" is a list of books, or null if no book with the 
//provided title can be found. The length of the list is also recorded in the returned structure, with 0 in case
//list is the NULL pointer.
BookList find_book_by_year (unsigned int year,struct Node* headNode)
{
	BookList booklist;
	booklist.length=0;
	struct Node* posNode = headNode->next;
	struct Node* posNode1 = headNode->next;
	while (posNode != NULL )
	{
		if( posNode->book.year==year)
		{
			booklist.length++;
		}
		posNode = posNode->next;
	}
	if(!booklist.length)
	{
		printf("no book found!\n");
		return ;
	}
	printf("ID\ttitle\tauthor\tyear\tcopies\n");
	while (posNode1 != NULL )
	{
		if( posNode1->book.year==year)
		{
			printf("%d\t%s\t%s\t%d\t%d\n", posNode1->book.id, posNode1->book.title, posNode1->book.authors,posNode1->book.year,posNode1->book.copies);
		}
		posNode1 = posNode1->next;
	}
	return booklist;
}

