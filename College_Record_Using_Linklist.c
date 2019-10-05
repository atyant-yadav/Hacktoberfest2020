#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student_record
{

    char clas[50];
    char name[50];
    char email[50];
    char contact[50];
    char prn[50];
    int rollno;
    struct student_record *next;

}student_record;
struct student_record *head;
void insert_data(int n)
{ int i;
    struct student_record *temp = (struct student_record *)malloc(sizeof(struct student_record));
    printf("Enter the Name Of Student \n");
    scanf("%s",&temp->name);
    printf("Enter the Class Of Student \n");
    scanf("%s",&temp->clas);
    printf("Enter the Contact No. Of Student \n");
    scanf("%s",&temp->contact);
    printf("Enter the Email-ID Of Student \n");
    scanf("%s",&temp->email);
    printf("Enter the PRN Of Student \n");
    scanf("%s",&temp->prn);
    printf("Enter the Roll No. Of Student \n");
    scanf("%d",&temp->rollno);



    temp->next=NULL;
    if(n==1)
    {
        temp->next=head;
        head=temp;
        return;
    }

    struct student_record *temp1= head;
    for(i=0;i<n-2;i++)
        temp1=temp1->next;
    temp->next=temp1->next;
    temp1->next=temp;
}

void disp()
{
    struct student_record *temp = head;
    while(temp!=NULL)
    {
        printf("Name: %s \n",temp->name);
        printf("Roll No is: %d \n",temp->rollno);
        printf("PRN: %s \n",temp->prn);
        printf("Email-ID: %s \n",temp->email);
        printf("Class: %s \n",temp->clas);
        printf("Contact: %s \n",temp->contact);
        temp = temp->next;
    }
    printf("\n");
}
void del(int x)
{
struct student_record *temp3 = head;
    if(x==1)
    {
        head = temp3->next;
        free(temp3);
    }

    int i;
    for(int i=0;i<x-2;i++)
        temp3 = temp3->next;
    struct student_record *temp4 = temp3->next;
    temp3->next = temp4->next;
    free(temp3);
}



void search(char ni[5])
{
 int flag=0;
 struct student_record *temp = head;
 while(temp!=NULL)
 {
  if(strcmp(temp->name,ni)==0)
  {
  flag=1;
  printf("\n\nName of Student :   %s ",temp->name);
  printf("\n\nPRN of Student :        %s ",temp->prn);
  printf("\n\nRoll No. of Student :  %d",temp->rollno);
  printf("\n\nContact No. of Student :    %s",temp->contact);
  printf("\n\n\n");
  }
  temp=temp->next;
 }
 if(flag==0)
  printf("\n\nNo Match Found.");
}
void modify(int rn)
{
 struct student_record *temp = head;
 int ch;
 while(temp->rollno!=rn && temp!=NULL)
  temp=temp->next;
 if(temp->rollno==rn)
 {
  printf("******* MODIFY *******\n1.Name\n2.PRN");
  printf("\n3.Contact No\nEnter choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
  case 1 :  printf("Enter the Name of Student : ");
          scanf("%s",&temp->name);break;
  case 2 :  printf("\nEnter the PRN of Student : ");
          scanf("%s",&temp->prn);break;
  case 3 :  printf("\nEnter the Contact No. of Student : ");
          scanf("%s",&temp->contact);break;

  }
 }
 else
  printf("\nRecord not Found.");
}

int main()
{
 int ch,p,a,rn;
 char ni[5];
 while(ch!=6)
 {
  printf("1.Add the Record.\n\n2.Delete Record.");
  printf("\n\n3.Display\n\n4.Search\n\n5.Modify\n\n6.Exit");
  printf("\n\nEnter the Choice: ");
  scanf("%d",&ch);
   switch(ch)
   {
    case 1:
        printf("enter the position");
        scanf("%d",&p);
        insert_data(p);
    break;

    case 2:
        printf("enter the pos from where you want to delete");
        scanf("%d",&a);
        del(a);
    break;

    case 3:
        disp();
    break;

    case 4:
        printf("Enter the Name : ");
        scanf("%s",&ni);
        search(ni);
        break;
     case 5:
    printf("Enter the Roll No : ");
    scanf("%d",&rn);
    modify(rn);
    break;


    default:
        printf("wrong choice");
        break;
   }
 }


      return 0;
}




