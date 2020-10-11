# include <conio.h>
# include <stdio.h>
# include <alloc.h>
# include <string.h>

struct node
{
    int num;
    char name[15];
    struct node *next;
};


struct node *list; //global start pointer
FILE *fp; // Global file pointer

struct node *getrecord()
{
    struct node *temp,e;
    temp=(struct node*)malloc(sizeof(struct node));

    printf("Reached till here...");
    getch();

    fflush(stdin);
// fscanf(fp,"%d %s",&temp->num,temp->name);
    fread(&temp,sizeof(temp),1,fp);
    printf("%d %s",temp->num,temp->name);

// temp->num=e.num;
// strcpy(temp->name,e.name);
    getch();
    temp->next = NULL;
    return temp;
}

struct node *getnode()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the person's phone number--->");
    scanf("%d",&temp->num);

    printf("Enter the person's Name--->");
    scanf("%s",&temp->name);

    temp->next = NULL;
    return temp;
}

struct node *search(int id,int *flag)
{
    struct node *cur,*prev;
    *flag=0;

    if
    (list==NULL)
        return NULL;

    for(prev=NULL,cur=list; (cur); prev=cur,cur=cur->next)
        if(cur->num == id)
        {
            *flag = 1;
            break;
        }


    return prev;
}

int insert(struct node *new1)
{
    struct node *prev;
    int flag;

    prev = search(new1->num,&flag);

    if(list==NULL)
    {
        list = new1; //first node in list
        return;
    }

    if(flag==1)
        return -1;
    else
    {
        new1->next = prev->next;
        prev->next = new1; // insert in the middle or end
    }

    return 0;
}

void display()
{
    struct node *cur;
    auto int n=0;

    if(list==NULL)
    {
        printf("List empty !");
        return;
    }

    printf("The phone records are--->");
    cur=list;
    for(cur=list; (cur); cur=cur->next)
    {
        printf("Record no. %d--->",n+1);
        printf("Record phone no.:%d",cur->num);
        printf("person Name:%s",cur->name);
        n++;
    }

}

int delnode(int id)
{
    struct node *prev,*temp;
    int flag=0;

    if(list==NULL)
        return -1;

    prev=search(id,&flag);

    if(flag==0)
        return -1;

    if(prev==NULL)
    {
        temp=list;
        list=list->next;
        free(temp);
    }

    else
    {
        temp=prev->next;
        prev->next=temp->next;
        free(temp);
    }
    return 0;
}

struct node *query(int id,char *flag,int toggle)
{
    struct node *cur,*prev;
    int x=0;

    if(list==NULL)
        return NULL;

    if(toggle)
    {
        for(prev=NULL,cur=list; (cur); prev=cur,cur=cur->next)
            if(cur->num == id)
            {
                x=1;
                break;
            }
    }
    else
    {
        for(prev=NULL,cur=list; (cur); prev=cur,cur=cur->next)
            if(!strcmp(cur->name,flag))
            {
                x=1;
                break;
            }
    }

    if(x==0)
    {
        printf("The number doesnt exist !");
        return NULL;
    }

    return cur;
}

void CopyToFile()
{
    FILE *fp;
    struct node *cur;
    fp=fopen("phone.txt","w");

    cur=list;
    if(cur==NULL)
    {
        printf("The list is empty, nothing to write back...");
        return;
    }
    for(cur=list; (cur); cur=cur->next)
        fprintf(fp,"%d %s",cur->num,cur->name); //writing back to file
    fclose(fp);
}

void main()
{
    int ch=0,ans=0;
    int val=0;
    char str[15];
    struct node *new1,*new2;


    clrscr();

    /* initialization of list with the existing records */

    fp=fopen("phone.txt","r");

    if(fp==NULL)
    {
        printf("File cant be opened !");
        getch();
        exit(1);
    }

    while(!feof(fp))
    {
        new1=getrecord();

        if(insert(new1)==-1)
            printf("Cant insert record ! Error...");
        else
            printf("Record entered...");
    }
    getch();
    fclose(fp);

    do
    {
        clrscr();
        printf("Menu");
        printf("1. Add a New phone record.");
        printf("2. Delete an existing Record.");
        printf("3. show all Records.");
        printf("4. Modify a particular Record.");
        printf("5. Exit.");
        printf("Enter your choice--->");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:

            new1 = getnode();
            val = insert(new1);
            if(val==-1)
                printf("Employee id already exists ! try again...");
            else
                printf("Employee details successfully stored");
            break;

        case 2:
            printf("Enter the phone no.you wish to delete--->");
            scanf("%d",&val);
            ans=delnode(val);

            if(ans==-1)
                printf("Record doesnt exist ! Try again...");
            if(ans==0)
                printf("Record deleted !");
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Search by phone no. or Name ? (1/2)--->");
            scanf("%d",&ch);
            if(ch==1)
            {
                printf("Enter the phone no. you wish to search for--->");
                scanf("%d",&val);
                new2=query(val,&str,1);
            }
            else
            {
                printf("Enter the name of the person you wish to search for--->");
                scanf("%s",&str);
                new2=query(val,&str,0);
            }
            if(new2)
            {
                printf("Enter the New name of the person--->");
                scanf("%s",&new2->name);
                printf("Enter new phone no. of the person--->");
                scanf("%d",&new2->num);
                printf("Record modified successfully !");
            }
            break;
        case 5:
            printf("Leaving Database,writing back to file...");
            CopyToFile();
            getch();
            free(list);
            exit(1);
            break;
        }
        getch();
    }
    while(1);

}
