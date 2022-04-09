#ifndef USER__H
#define USER__H
#include "book_management.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct The_users
{
  char id[11];  
  char psw[20]; 
  int borrowid[15];
  int borrow;
  struct The_users * next;
}users;
struct Nd
{
	users user;
	struct Nd* next;
};
struct Nd* create(users user);
struct Nd* createHead1();
void add_user(users user,struct Nd* headNode);

void userreg();

void userlog();
#endif
