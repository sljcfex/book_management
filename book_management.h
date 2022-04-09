
#ifndef BOOK_MANAGEMENT_GUARD__H 
#define BOOK_MANAGEMENT_GUARD__H

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
/*You can extend the structs (Book and BookList) defined in this head file;
  However, you may not change the function prototypes. 
  You are also free to add additional head files and data structures as needed. 
*/


typedef struct _Book {
	    unsigned int id; //Book ID
		char *title; //book title
		char *authors; //comma separated list of authors
		unsigned int year; // year of publication
		unsigned int copies; //number of copies the library has
		struct _Book *next; //pointer to the next book element
}Book;

typedef struct _BookList {
	 Book* list; // pointer to a list of struct Book.
	 unsigned int length; // number of elements in the (Book*) List 
}BookList;
struct Node
{
	Book book;
	struct Node* next;
};
struct Node* createHead();


//saves the database of books in the specified file
//returns 0 if books were stored correctly, or an error code otherwise
int store_books(struct Node* headNode,FILE * file);

//loads the database of books from the specified file
//the file must have been generated by a previous call to store_books()
//returns 0 if books were loaded correctly, or an error code otherwise
int load_books(FILE *file,struct Node* headNode);
void printList(struct Node* headNode);
//adds a book to the ones available to the library
//returns 0 if the book could be added, or an error code otherwise
int add_book(Book book,struct Node* headNode);

//removes a book from the library
//returns 0 if the book could be successfully removed, or an error code otherwise.
int remove_book(Book book,struct Node* headNode);

//finds books with a given title.
//returns a BookList structure, where the field "list" is a list of books, or null if no book with the 
//provided title can be found. The length of the list is also recorded in the returned structure, with 0 in case
//list is the NULL pointer.
BookList find_book_by_title (const char *title,struct Node* headNode);
Book find_book_by_id (const int id,struct Node* headNode);
int find_book_by_id_bool (const int id,struct Node* headNode);
//finds books with the given authors.
//returns a Booklist structure, where the field "list" is a newly allocated list of books, or null if no book with the 
//provided title can be found. The length of the list is also recorded in the returned structure, with 0 in case
//list is the NULL pointer.
BookList find_book_by_author (const char *author,struct Node* headNode);

//finds books published in the given year.
//returns a Booklist structure, where the field "list" is a list of books, or null if no book with the 
//provided title can be found. The length of the list is also recorded in the returned structure, with 0 in case
//list is the NULL pointer.
BookList find_book_by_year (unsigned int year,struct Node* headNode);

#endif
