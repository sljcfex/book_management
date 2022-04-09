#include "user.h"
#include "interface.h"
#include "userop.h"
#include "admini.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>


struct Nd* list2 = NULL;
struct Nd* create( users user)
{
	struct Nd* newNode = (struct Nd*)malloc(sizeof(struct Nd));
	newNode->user = user;
	newNode->next = NULL;
	return newNode;
}

struct Nd* createHead1()
{
    struct Nd* headNode = (struct Nd*)malloc(sizeof(struct Nd));
    headNode->next = NULL;
    return headNode;
}
void add_user(users user,struct Nd* headNode)
{
  struct Nd* newNode = create(user);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
void userreg() 
   {  
     char id[20];
     printf("please enter your id:\n");
       scanf("%s",id);
     struct Nd* posNode = list2->next;

     while(posNode != NULL)
     {  
       if (strcmp(id, posNode->user.id)==0||strcmp(id,"librarian")) 
       {
         printf("This username already exists! Please re-register!\n");   
         return;   
       }

         posNode = posNode->next; 
     }
	users a;
    char psw[20];
     printf("please enter password \n");
       scanf("%s",psw);
     printf("Please confirm password\n");
     char psw1[20];
       scanf("%s",psw1);
  do{
     if(strcmp(psw,psw1)==0){
      
      strcpy(a.id, id);
      strcpy(a.psw, psw);
       add_user(a,list2);
      printf("Account registered successfully, please log in!\n"); 
   return;
  }else{
   printf("Passwords don't match ! Please re-enter:\n");
      scanf("%s",psw);
      printf("Please confirm password\n");
      scanf("%s",psw1);
    }
  }while(strcmp(psw,psw1)==0);
}

void userlog()
{

  printf("Welcome to the login screen!\n");
  printf("Please enter your id:\n");
  char id[20];
  char psw[20];
  scanf("%s",id);

  if(strcmp(id,"librarian")==0)
  {
    printf("please enter password \n");
      scanf("%s",psw);

    do{
        if(strcmp(psw,"librarian")==0)
        {
            adimi();
            return;
        }
        else
        {
            printf("Incorrect password! Please re-enter your password\n");
            scanf("%s",psw);

        }
  }while(strcmp(psw,"librarian")==0);
    }

      struct Nd* posNode = list2->next;
       while (posNode != NULL)
      {  
        if (strcmp(id, posNode->user.id)==0) 
       {

         printf("please enter password \n");
           scanf("%s",psw);

     do{ 
        if (strcmp(posNode->user.psw, psw)==0) 
        { 
          printf("Login successful, welcome to use!\n");

            useroperate(posNode->user);
          return;
        }


        else
        {  printf("Incorrect password! Please re-enter your password\n");
            scanf("%s",psw);

       }
        }while(strcmp(psw, posNode->user.psw)==0); 
       }
         posNode = posNode->next; 
    }printf("This user name does not exist, please re-enter!\n");

}
