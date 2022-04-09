#include "user.h"
#include "userop.h"
#include "admini.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>


extern struct Node* list1;

struct Nd* create( users user)
{
	struct Nd* newNode = (struct Nd*)malloc(sizeof(struct Nd));
	newNode->user = user;
	newNode->next = NULL;
	return newNode;
}
struct Nd* list2 = NULL;
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
void userreg() 
   {  
     char id[20];
     printf("please enter your id:\n");
     getchar();
     gets(id);
     struct Nd* posNode = list2->next;
     while(posNode != NULL)
     {  
       if (strcmp(id, posNode->user.id)==0||strcmp(id,"librarian")==0)
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
      a.borrow=0;
      int x;
      for(x=0;x<=15;x++)
          a.borrowid[x]=0;
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
void load_users(FILE * file,struct Nd * headNode)
{
    if (file == NULL)
    {
        printf("File opened failed, exit.");
        exit(0);
    }
    users a;
    char temp[55];
    memset(temp,'\0',50);
    char buf[55];
    int tempborrow,tempid;
    while ( (fgets(buf, 50, file)) != NULL) {
        char* id = (char*) malloc(sizeof(char)*50);
        char* psw = (char*) malloc(sizeof(char)*50);
        sscanf(buf, "%s %s %d",  id, psw, &tempborrow);//split string
        strcpy(a.id,id);
        strcpy(a.psw,psw);
        a.borrow=tempborrow;
        int i;
        for(i=1;i<=a.borrow;i++)
        {
            sscanf(buf,"%d",&tempid);
            a.borrowid[i]=tempid;
        }

        add_user(a,headNode);
    }
}
void store_users(struct Nd* headNode,const char* filename)
{
    FILE* fp = fopen(filename, "w");
    struct Nd* pMove = headNode->next;
    while (pMove != NULL)
    {
        int i;
        fprintf(fp, "%s\t%s\t%d\t", pMove->user.id, pMove->user.psw, pMove->user.borrow);
        for(i=1;i<=pMove->user.borrow;i++)
            fprintf(fp,"%d\t",pMove->user.borrowid[i]);
        fprintf(fp,"\n");

        pMove = pMove->next;
    }
    fclose(fp);

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
