#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h> 


struct member
{
 char name[50];
 char id[50];
 char phoneNumber[50];
 char date[50];
};

void takeInput(char str[50])
{
  fgets(str,50,stdin);
  str[strlen(str)-0];
}

void addMember(FILE *fp) 
{
  struct member member;
  printf("\t\tAdd the client's name:\t");
  takeInput(member.name);
  printf("\t\tAdd the client's id:\t");
  takeInput(member.id);
  printf("\t\tData issued:\t");
  takeInput(member.date);
  printf("\t\tAdd the client's phone number:\t");
  takeInput(member.phoneNumber);
  fp = fopen("Members.dat","ab");
  fwrite(&member,sizeof(struct member),1,fp);
if(fwrite != 0 ) printf("\t\tSuccess!,%shas been registerd.",member.name);
else
{
  printf("Something went wrong, Try again letter.");
  fclose(fp);
 }
}

void deleteMember(FILE *fp)
{
  struct member usr;
  int memberFound = 0;
  char id[50];

  printf("\t\tEnter an ID:\n\t\t");
  takeInput(id);
  fp = fopen("Members.dat","rb");
while (fread(&usr,sizeof(struct member),1,fp))
{
if (!strcmp(usr.id,id))
{
  memberFound = 1;
}
}
if (memberFound)
{
  printf("\t\t----------------------------------------- \n");
  printf("\t\tMember Found\n\n");
  printf("\t\tClient's ID:%s\n",usr.id);
  printf("\t\tClient's name:\t%s\n",usr.name);
  printf("\t\tClient's phone number:\t%s\n",usr.phoneNumber);
  printf("\t\tMember since:\t%s\n",usr.date);
}
else
{
  printf("\t\tMember not Found\n"); 
}    
}

void viewMembers(FILE *fp) 
{
  struct member client;
  fp = fopen("Members.dat","rb");
  while (fread(&client,sizeof(struct member),1,fp))
  {
  printf("\t\t----------------------------------------- \n");
  printf("\t\tClient's ID:%s\n",client.id);
  printf("\t\tClient's name:\t%s\n",client.name);
  printf("\t\tClient's phone number:\t%s\n",client.phoneNumber);
  printf("\t\tMember since:\t%s\n",client.date);
  }
   fclose(fp);
}


int main() 
{
  int choice;
  FILE *fp;

  printf("\t\tMain Menu\n\n\n");
  printf("\t\t<1>\tAdd Members\n\n");
  printf("\t\t<2>\tRemove Members\n\n");
  printf("\t\t<3>\tSee Members\n\n");
  printf("\t\tEnter your choice: ");
  scanf("%d",&choice);
  fgetc(stdin);

switch (choice)
{
  case 1:
  system("cls");
  addMember(fp);
  break;

  case 2:
  system("cls");
  deleteMember(fp);
  break;

  case 3:
  system("cls");
  viewMembers(fp);
  break;
  default:
  break;
}
 return 0;
}