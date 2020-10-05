#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define n 50    

int enr=1;
int num_books=10;
int arr[50]={0};             // Initially No book is issued (inidicated bt 0)

void add_book();
void set_books();    
void total_books();
void delete_mem();
void show_list();
void ret_book();
void issue_book();
void fine();
void add_mem();

struct lib {
  int serial_num;
  char book_title[50];
  char book_author[50];

}book[n];

struct member{
  char name[30];
  int enroll_num;
}mem[30];

void main()
{
    printf("\nManav Naharwal 05316401519\n\n");
    printf("\n\t----------------------------------------------------------------------\n");
	  printf("\t         L i b r a r y     M a n a g e m e n t     S y s t e m\n");
	  printf("\t----------------------------------------------------------------------\n\n\n");
    set_books();
    printf("\t----------------  Important Conditions ----------------- \n\tTotal books (Initially) are 10.\n\tRate of fine is for same for every book.\n\tOnly one book is allowed to issue to each member.\n\tMaximum time to return a book is 1 Month.\n\tMaximim number of memberships which can be alloted is 30 (1 to 30).\n\tStudent must not forget his/her issued book serial number as it would be asked at the time of returning book.\n"); 

    while(1)
    {
       int k;
       printf("\nWhat do you want to do :\n");
       printf("\n1.Add a book\n2.Total Books currently present in Library\n3.Issue a book\n4.Return a book with fine (if any)\n5.Add members\n6.Delete a membership\n7.Show the list of books and members.\n8.Exit\n\n");
       scanf("%d",&k);

       switch(k)
       {
         case 1:
         add_book();
         getch();
         break;
         
         case 2:
         total_books();
         getch();
         break;

         case 3:
         issue_book();
         getch();
         break;

         case 4:
         ret_book();
         getch();
         break;

         case 5:
         add_mem();
         getch();
         break;

         case 6:
         delete_mem();
         getch();
         break;

         case 7:
         show_list();
         getch();
         break;

         case 8:
         exit(0);

         default:
         printf("Wrong Input !");
         break;

       }
      
    } 
}

void set_books()    
{

  strcpy(book[1].book_title,"Introduction to Algorithms");
  strcpy(book[1].book_author,"Thomas H. Cormen, Charles E. Leiserson");
  book[1].serial_num=1;  

  strcpy(book[2].book_title,"The Clean Coder");
  strcpy(book[2].book_author,"Robert C. Martin");
  book[2].serial_num=2;

  strcpy(book[3].book_title,"Structure and Interpretation of Computer Programs");
  strcpy(book[3].book_author,"Harold Abelson, Gerald Jay Sussman");
  book[3].serial_num=3;

  strcpy(book[4].book_title,"Code Complete");
  strcpy(book[4].book_author,"Steve McConnell");
  book[4].serial_num=4;

  strcpy(book[5].book_title,"Design Patterns");
  strcpy(book[5].book_author,"Erich Gamma, Richard Helm, Ralph Johnson");
  book[5].serial_num=5;

  strcpy(book[6].book_title,"The Pragmatic Programmer");
  strcpy(book[6].book_author,"Andrew Hunt, David Thomas");
  book[6].serial_num=6;

  strcpy(book[7].book_title,"Head First Design Patterns");
  strcpy(book[7].book_author,"Eric Freeman, Bert Bates"); 
  book[7].serial_num=7;

  strcpy(book[8].book_title,"The Art of Computer Programming");
  strcpy(book[8].book_author,"Donald E. Knuth");
  book[8].serial_num=8;

  strcpy(book[9].book_title,"Refactoring");
  strcpy(book[9].book_author,"Martin Fowler"); 
  book[9].serial_num=9;
  
  strcpy(book[10].book_title,"Let us C");
  strcpy(book[10].book_author,"Yashavant Kanetkar");
  book[10].serial_num=10;

}

void total_books()
{
  int i,q=1;
  printf("\tCurrent No. of books : %d\n",num_books);
  printf("\n\t=========================================\n");
  
  for (i=1;i<=num_books;i++)
  {
    if (i==arr[q])
    { 
      q++;
      continue;
    }

    else
    { printf("\n%d. ",book[i].serial_num);
      printf("Title of book is : %s",book[i].book_title);
      printf("\nName of Author is : %s",book[i].book_author);
      printf("\n");
      q++;
    }

  }
  
}

void add_book()
{
   if (num_books <= 50)
   {
     char str[30];
     printf("\nPlease give the respective serial number.\n");
     printf("Current No. of books is : %d\n",num_books);
     printf("What's the title : ");
     scanf("%s",str);
     num_books++;
     printf("Who's the author : ");
     scanf("%*[\n] %[^\n]s",str);
     printf("\nWhat's the serial number : ");
       strcpy(book[num_books].book_title,str);
     scanf("%d",&book[num_books].serial_num);
     strcpy(book[num_books].book_author,str);
   }

   else 
   printf("No Space !");

}

void issue_book()
{
  int issue;
  char ask;
  total_books();
  printf("\n\nWhich book do you want to issue ? ");
  scanf("%d",&issue);
  printf("Are you sure ! (y/n) : ");
  scanf(" %c",&ask);

  if (ask == 'y')
  {
    arr[issue] = issue;
    num_books--;
    printf("\nIssued!\n");    
  }

  else
  main();
}

void ret_book()
{
  int h,flag=0,ser_no;
  printf("Enter your book serial number : ");
  scanf("%d",&ser_no);
  
  for (h=1;h<=50;h++)
  {
    if (ser_no==arr[h])
    {
      printf("\nFOUND.\n");
      printf("Was this your book name : %s",book[ser_no].book_title);
      printf("\n");
      flag=1;
      arr[h]=0; 
      num_books++;
      break;
    } 
    
  }

  if (flag==0)
  {
    printf("Not found.\n\n");
    ret_book();  
  }
 
  fine();
}

void fine()
{
  /* Fine is 2 for every book  */
    int d=30;
    int years;
    int months;
    int dates;
    int year;
    int month;
    int date;
    int arr[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    int f=0;
    int e;
    int c;
    printf("Enter the issue YEAR/MONTH/DATE\n");
    scanf("%d %d %d",&year,&month,&date);
    if ( year % 400==0 || year%4==0 && year%100!=0)
    {
        for(int i=0;i<month-1;i++)
          sum+=arr[i];
        
        sum=sum+date;
    }

    else
    {
        for(int i=0;i<month-1;i++)
          sum+=a[i];
        
        sum=sum+date;
    }
    printf("\nEnter the return YEAR/MONTH/DATE\n");
    scanf("%d %d %d",&years,&months,&dates);
    if( years%400==0 || years%4==0 && years%100 !=0)
    {
        for(int i=0;i<months-1;i++)
          f+=arr[i];
        
        f=f+dates;
    }

    else
    {
        for(int i=0;i<months-1;i++)
          f+=a[i];
        
        f=f+dates;
    }

    e=f-sum;

    if(e>d)
      c=(e-d)*2;
    
    else
      c=0;
    
    printf("\nFine is %d\n",c);
}

void add_mem()
{
  int enroll;
  printf("Enter your enrollment number: ");
  scanf("%d",&enroll);

  if (enroll <= 0 && enroll > 30 )
  {
     printf("This is not a valid enrollment number. It can only be in range of 1 to 30");
     add_mem();
  }

  mem[enr].enroll_num = enroll;
  printf("Enter your Name : ");
  scanf("%*[\n] %[^\n]s",mem[enroll].name);
  enr++;
  printf("\nYour membership has been filed.");
  printf("\n\nThank you! and Happy Reading.");

}

void delete_mem()
{
  char ask,en,temp,flag=0;
  printf("\nAre you sure you want to delete your membership (y/n): ");
  scanf(" %c",&ask);

  if (ask=='y' || ask=='n')
  {
    if (ask=='y')
    {
      printf("Please enter your enrollment number : ");
      scanf("%d",&en);

      for (temp=1;temp<=30;temp++)
      {
        if (en==mem[temp].enroll_num)
        {
          mem[temp].enroll_num=0;
          printf("\nYour membership is removed.");
          flag=1;
        }
      }

       if (flag==0)
      {
        printf("Not Found.\n\n");
        delete_mem();
      }

    }

    else
      main();
  }
  
  else 
  printf("WRONG INPUT!");
}

void show_list()
{
  int i,count=0;
  total_books();
  printf("\n\n");
  printf("\t---------------------List Of Members-------------------");
  for (i=1;i<=30;i++)
  {
    if (mem[i].enroll_num==0)
    {
      count++;
      continue;
    }

    else 
    {
      printf("\n\t%d. ",mem[i].enroll_num);
      printf("%s",mem[i].name);
    }
  }

  if (count==30)
   printf("\n\nNo Members are there..\n");
}

