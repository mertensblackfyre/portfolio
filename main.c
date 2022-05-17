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
  str[strlen(str) - 0];
}

void addMember(FILE *fp) 
{
  char choice;
  struct member member;
  printf("\t\tAdd the client's name: ");
  takeInput(member.name);
  printf("\t\tAdd the client's id: ");
  takeInput(member.id);
  printf("\t\tData issued: ");
  takeInput(member.date);
  printf("\t\tAdd the client's phone number: ");
  takeInput(member.phoneNumber);
  fp = fopen("Members.dat","ab");
  fwrite(&member,sizeof(struct member),1,fp);

if(fwrite != 0 ) 
 printf("\t\tSuccess!,%shas been registerd\n",member.name);

else
{
  printf("Something went wrong, Try again later.");
  fclose(fp);
}

 printf("\t\tDo you want go back to main menu?(Y/N): ");
 scanf("%c",&choice);

     
  if (choice == 'y' || choice == 'Y')
  {
    main();
  }

  fclose(fp);

}

void deleteMember(FILE *fp)
{
  FILE *fp_tmp;
  struct member usr;
  int memberFound = 0;
  char id[50];
  char choice;

  printf("\t\tEnter an ID:\n\t\t");
  takeInput(id);
  fp = fopen("Members.dat","rb");
  fp_tmp=fopen("tmp.bin", "wb");

while (fread(&usr,sizeof(struct member),1,fp))
{

if (!strcmp(usr.id,id)) 
{
  memberFound = 1;
  printf("\t\t----------------------------------------- \n");
  printf("\t\tMember have been found\n\n");
  printf("\t\tClient's ID: %s\n",usr.id);
  printf("\t\tClient's name: %s\n",usr.name);
  printf("\t\tClient's contact number: %s\n",usr.phoneNumber);
  printf("\t\tMember since: %s\n\n\n",usr.date);
  printf("\t\tAre you sure you want to delete this record?(Y/N): ");
  scanf("%c",&choice);
} 
// if (choice == 'Y' && strcmp(usr.id,id)) fwrite(&usr, sizeof(struct member), 1, fp_tmp);  

else fwrite(&usr, sizeof(struct member), 1, fp_tmp);   
}

if (!memberFound) printf("\t\tMember not Found\n");

  fclose(fp);
  fclose(fp_tmp);
	remove("Members.dat");
	rename("tmp.bin", "Members.dat");   
}

void viewMembers(FILE *fp) 
{
  struct member client;
  char choice;
  fp = fopen("Members.dat","rb");

  while (fread(&client,sizeof(struct member),1,fp))
  {
  printf("\t\t----------------------------------------- \n");
  printf("\t\tClient's ID:\t%s\n",client.id);
  printf("\t\tClient's name:\t%s\n",client.name);
  printf("\t\tClient's phone number:\t%s\n",client.phoneNumber);
  printf("\t\tMember since:\t%s\n",client.date);
  }
   fclose(fp);
   
   printf("\t\tDo you want go back to main menu?(Y/N): ");
   scanf("%c",&choice);

     
  if (choice == 'y' || choice == 'Y')
  {
    main();
  }
}

void searchMember(FILE *fp)
{
  struct member usr;
  int memberFound = 0;
  char id[50];
  char choice;

  printf("\t\tEnter an ID:\n\t\t");
  takeInput(id);
  fp = fopen("Members.dat","rb");
while (fread(&usr,sizeof(struct member),1,fp))
{
if (!strcmp(usr.id,id))
{
  memberFound = 1;
  printf("\t\t----------------------------------------- \n");
  printf("\t\tMember Found\n\n");
  printf("\t\tClient's ID:%s\n",usr.id);
  printf("\t\tClient's name:\t%s\n",usr.name);
  printf("\t\tClient's phone number:\t%s\n",usr.phoneNumber);
  printf("\t\tMember since:\t%s\n",usr.date);
}
}
if(!memberFound) printf("\t\tMember not Found\n"); 

  fclose(fp);
  printf("\t\tDo you want go back to main menu?(Y/N): ");
  scanf("%c",&choice);

     
  if (choice == 'y' || choice == 'Y')
  {
    main();
  }

}

void updateMember(FILE *fp)
{
  FILE *fp_tmp;
  struct member usr;
  int memberFound = 0;
  char id[50];
  char choice;
  char choice2;

  printf("\t\tEnter an ID: ");
  takeInput(id);
  fp = fopen("Members.dat","rb");
  fp_tmp = fopen("tmp.bin", "wb");

while (fread(&usr,sizeof(struct member),1,fp))
{
if (!strcmp(usr.id,id)) memberFound = 1;

else
{
  fwrite(&usr, sizeof(struct member), 1, fp_tmp);
}
}
  fclose(fp_tmp);
if (memberFound)
{
  strcpy(usr.id,id);
  printf("\t\tMember found\n");
  printf("\t\tDo you want to update the member's record?(Y/N) ");
  scanf("%c",&choice2);
  fgetc(stdin);
}

if (choice2 == 'y' || choice2 == 'Y')
{
  printf("\t\t---------------- Old Record --------------- \n");
  printf("\t\tClient's id: %s\n",usr.id);
  printf("\t\tClient's name: %s\n",usr.name);
  printf("\t\tClient's contact number: %s\n",usr.phoneNumber);
  printf("\t\t------------------------------------------- \n");

  printf("\t\tNew client's name: ");
  takeInput(usr.name);
  printf("\n\t\tNew client's phone number: ");
  takeInput(usr.phoneNumber);
  fp_tmp = fopen("tmp.bin", "ab+");
  fwrite(&usr,sizeof(struct member),1, fp_tmp);
}

  printf("\t\t---------------- New Record --------------- \n\n");
  printf("\t\tClient's id: %s\n",usr.id);
  printf("\t\tClient's name: %s\n",usr.name);
  printf("\t\tClient's contact number: %s\n",usr.phoneNumber);
  printf("\t\tMember since: %s\n",usr.date);
  printf("\t\t------------------------------------------- \n");



if (!memberFound) 
  printf("\t\tMember not Found\n");

  fclose(fp);
  fclose(fp_tmp);
	remove("Members.dat");
	rename("tmp.bin", "Members.dat");

  printf("\n\t\tDo you want go back to main menu?(Y/N): ");
  scanf("%c",&choice);
  
  if (choice == 'y' || choice == 'Y')
  {
    main();
  }
  
}

int main() 
{
  system("cls");
  int choice;
  FILE *fp; 

  printf("\t\t\t\tMain Menu\n");
  printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
  printf("\t\t<1>\tAdd a Member\n\n");
  printf("\t\t<2>\tRemove a Member\n\n");
  printf("\t\t<3>\tView all Members\n\n");
  printf("\t\t<4>\tSearch Member by ID\n\n");
  printf("\t\t<5>\tUpdate a Member\n\n");
  printf("\t\t<6>\tClose Application\n\n");
  printf("\t\tEnter your choice:");

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
  
  case 4:
  system("cls");
  searchMember(fp);
  break;

  case 5:
  system("cls");
  updateMember(fp);
  break;

  case 6:
  exit(1);
  break;

  default:
  printf("\n\t\tNOT A VALID CHOICE.");
  break;
}
 return 0;
}