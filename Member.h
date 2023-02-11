#if !defined(MEMBER_H)
#define MEMBER_H
#include <stdio.h>


typedef struct Member
{
  char name[50];
  char id[50];
  char phoneNumber[50];
  char date[50];
} Member;


void member_add(FILE *fp);
void member_delete(FILE *fp);
void members_view_all(FILE *fp);
void member_search(FILE *fp);
void member_update(FILE *fp);
void menu();

#endif