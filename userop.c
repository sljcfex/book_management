#include "book_management.h"
#include "userop.h"
#include "interface.h"
#include "user.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
extern struct Node* list1;
extern struct Nd* list2;
void makeMenu()
{
	printf("------------------------------------\n");
	printf("	user interface\n");
	printf("\t0.exit\n");
	printf("\t1.borrow books\n");
	printf("\t2.return books\n");
	printf("\t3.display books\n");
	printf("\t4.search books\n");
	printf("------------------------------------\n");
	printf("please enter(0~4):");
}

int keydown2(users user) {
    int userkey = 0;
    int id;
    int i, j;
    scanf("%d", &userkey);
    switch (userkey) {
        case 0:
            printf("[ exit ]\n");
            printf("exit successfully\n");
            return 1;
            break;
        case 1:
            printf("borrow books \n"); //书籍存在可以借阅，书籍的数量-1，不存在借阅失败
            printf("Please enter the id :\n");
            scanf("%d", &id);

            struct Node *posNode = list1->next;
            int flag = 1;
            while (posNode != NULL) {
                if (posNode->book.id == id) {

                    for (i = 1; i <= user.borrow; i++) {
                        if (id == user.borrowid[i]) {
                            printf("you have already borrowed one copy of this book!\n");
                            flag = 0;
                        }
                    }
                    if (posNode->book.copies > 0 && flag == 1) {
                        posNode->book.copies--;
                        user.borrow++;
                        user.borrowid[user.borrow] = posNode->book.id;
                        printf("Borrowing successful！\n");
                        flag = 0;
                    } else if (posNode->book.copies <= 0) {
                        printf("No books in stock, borrowing failed!\n");
                        flag = 0;
                    }
                }
                posNode = posNode->next;
            }
            if (flag == 1)
                printf("No related books, can not borrow!\n");
            break;
        case 2:
            printf("【 return books 】\n"); // 当前书籍的数量+1
            if (user.borrow) {
                printf("ID\ttitle\tauthor\tyear\tcopies\n");
                for (i = 1; i <= user.borrow; i++) {
                    struct Node *posNode = list1->next;
                    while (posNode != NULL) {
                        if (posNode->book.id == user.borrowid[i]) {
                            printf("%d\t%s\t%s\t%d\t%d\n", posNode->book.id, posNode->book.title, posNode->book.authors,
                                   posNode->book.year, posNode->book.copies);
                            break;
                        }
                        posNode = posNode->next;
                    }
                }
                printf("Please enter the id :\n");
                scanf("%d", &id);

                struct Node *posNode = list1->next;
                int flag = 1;
                while (posNode != NULL) {
                    if (posNode->book.id == id) {
                        for (i = 1; i <= user.borrow; i++) {
                            if (id == user.borrowid[i]) {
                                posNode->book.copies++;
                                user.borrowid[i] = -1;
                                int c = user.borrowid[i + 1];
                                for (j = i; j <= user.borrow; j++) {
                                    user.borrowid[j] = c;
                                    c = user.borrowid[j + 2];
                                }
                                user.borrow--;
                                printf("Book returned successfully!\n");
                                flag = 0;
                            }
                        }
                        break;
                    }
                    posNode = posNode->next;
                }
                if (flag)
                    printf("The source of this book is illegal!\n");
                break;
                case 3:
                    printList(list1);
                break;
                case 4:
                    searchbook();
                default:
                    break;
            }

    }return 0;
}



void useroperate(users user)
{
    while (1)
	{
		makeMenu();
		if(keydown2(user))
		{
			break;
		}
		system("pause");

	}
	return;
}
