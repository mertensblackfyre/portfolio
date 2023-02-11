#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Member.h"
#include "Utils.h"


void menu()
{
    int choice;
    FILE *fp;

    printf("\t\t\t\tMain Menu\n");
    printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
    setTime();
    printf("\t\t<1>\tAdd a Member\n\n");
    printf("\t\t<2>\tRemove a Member\n\n");
    printf("\t\t<3>\tView all Members\n\n");
    printf("\t\t<4>\tSearch Member by ID\n\n");
    printf("\t\t<5>\tUpdate a Member\n\n");
    printf("\t\t<6>\tClose Application\n\n");
    printf("\t\tEnter your choice:");

    scanf("%d", &choice);
    fgetc(stdin);

    switch (choice)
    {
    case 1:
        system("cls");
        member_add(fp);
        break;

    case 2:
        system("cls");
        member_delete(fp);
        break;

    case 3:
        system("cls");
        members_view_all(fp);
        break;

    case 4:
        system("cls");
        member_search(fp);
        break;

    case 5:
        system("cls");
        member_update(fp);
    break;

    case 6:
        exit(1);
    break;

    default:
        printf("\n\t\tNOT A VALID CHOICE.");
    break;
    }
}

void member_add(FILE *fp)
{
  char choice;
  int taken = 0;
  Member member;
  Member usr;
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  fp = fopen("Members.dat", "ab+");

  printf("\t\tAdd the client's new id: ");
  takeInput(member.id);

  printf("\t\tAdd the client's name: ");
  takeInput(member.name);
  printf("\t\tAdd the client's phone number: ");
  takeInput(member.phoneNumber);
  printf("\t\tData issued: %s", asctime(tm));
  strcpy(member.date, asctime(tm));
  fwrite(&member, sizeof(member), 1, fp);
  printf("\t\tSuccess %s has been registerd\n", member.name);

  fclose(fp);
}

void member_delete(FILE *fp)
{
  FILE *fp_tmp;
  Member usr;
  int memberFound = 0;
  char id[50];
  char choice;

  printf("\t\tEnter an ID:\n\t\t");
  takeInput(id);
  fp = fopen("Members.dat", "rb");
  fp_tmp = fopen("tmp.bin", "wb");

  while (fread(&usr, sizeof(Member), 1, fp))
  {

    if (!strcmp(usr.id, id))
    {
      memberFound = 1;
      printf("\t\t----------------------------------------- \n");
      printf("\t\tMember have been found\n\n");
      printf("\t\tClient's ID: %s\n", usr.id);
      printf("\t\tClient's name: %s\n", usr.name);
      printf("\t\tClient's contact number: %s\n", usr.phoneNumber);
      printf("\t\tMember since: %s\n\n\n", usr.date);
      printf("\t\tRecord have been deleted");
    }

    else
      fwrite(&usr, sizeof(Member), 1, fp_tmp);
  }

  if (!memberFound)
    printf("\t\tMember not Found\n");

  fclose(fp);
  fclose(fp_tmp);
  remove("Members.dat");
  rename("tmp.bin", "Members.dat");
}

void members_view_all(FILE *fp)
{
  Member client;
  char choice;
  int memberFound = 0;
  fp = fopen("Members.dat", "rb");

  while (fread(&client, sizeof(Member), 1, fp))
  {
    memberFound = 1;
    printf("\t\t----------------------------------------- \n");
    printf("\t\tClient's ID:\t%s\n", client.id);
    printf("\t\tClient's name:\t%s\n", client.name);
    printf("\t\tClient's phone number:\t%s\n", client.phoneNumber);
    printf("\t\tMember since:\t%s\n", client.date);
  }

  if (!memberFound)
  {
    printf("\t\tNo members are found. Please add a member.\n");
  }

  fclose(fp);
}


void member_search(FILE *fp)
{
  Member usr;
  int memberFound = 0;
  char id[50];
  char choice;

  printf("\t\tEnter an ID:\n\t\t");
  takeInput(id);
  fp = fopen("Members.dat", "rb");
  while (fread(&usr, sizeof(Member), 1, fp))
  {
    if (!strcmp(usr.id, id))
    {
      memberFound = 1;
      printf("\t\t----------------------------------------- \n");
      printf("\t\tMember Found\n\n");
      printf("\t\tClient's ID:%s\n", usr.id);
      printf("\t\tClient's name:\t%s\n", usr.name);
      printf("\t\tClient's phone number:\t%s\n", usr.phoneNumber);
      printf("\t\tMember since:\t%s\n", usr.date);
    }
  }
  if (!memberFound)
    printf("\t\tMember not Found\n");

  fclose(fp);
}


void member_update(FILE *fp)
{
  FILE *fp_tmp;
  Member usr;
  int memberFound = 0;
  char id[50];
  char choice;
  char choice2;

  printf("\t\tEnter an ID: ");
  takeInput(id);
  fp = fopen("Members.dat", "rb");
  fp_tmp = fopen("tmp.bin", "wb");

  while (fread(&usr, sizeof(Member), 1, fp))
  {
    if (!strcmp(usr.id, id))
      memberFound = 1;

    else
    {
      fwrite(&usr, sizeof(Member), 1, fp_tmp);
    }
  }
  fclose(fp_tmp);
  if (memberFound)
  {
    strcpy(usr.id, id);
    printf("\t\tMember found\n");
    printf("\t\tDo you want to update the member's record?(Y/N) ");
    scanf("%c", &choice2);
    fgetc(stdin);
  }

  if (choice2 == 'y' || choice2 == 'Y')
  {
    printf("\t\t---------------- Old Record --------------- \n");
    printf("\t\tClient's id: %s\n", usr.id);
    printf("\t\tClient's name: %s\n", usr.name);
    printf("\t\tClient's contact number: %s\n", usr.phoneNumber);
    printf("\t\t------------------------------------------- \n");

    printf("\t\tNew client's name: ");
    takeInput(usr.name);
    printf("\n\t\tNew client's phone number: ");
    takeInput(usr.phoneNumber);
    fp_tmp = fopen("tmp.bin", "ab+");
    fwrite(&usr, sizeof(Member), 1, fp_tmp);

    printf("\t\t---------------- New Record --------------- \n\n");
    printf("\t\tClient's id: %s\n", usr.id);
    printf("\t\tClient's name: %s\n", usr.name);
    printf("\t\tClient's contact number: %s\n", usr.phoneNumber);
    printf("\t\tMember since: %s\n", usr.date);
    printf("\t\t------------------------------------------- \n");
  }

  if (!memberFound)
    printf("\t\tMember not Found\n");

  fclose(fp);
  fclose(fp_tmp);
  remove("Members.dat");
  rename("tmp.bin", "Members.dat");

}

