#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void fileNewBug(int bug_id)
{
    printf("\n");
    printf("************* Filing a new Bug *************");
    printf("\n");

    time_t ct; // Data type used to store current time;
    time(&ct); // Used to save time in form of hours, minutes, seconds

    char name[20],bugtype[50],bugdescription[1000],bugpriority[30];
    int bugstatus;

    FILE *ptr;
    printf("Enter your name: ");
    scanf(" %[^\n]s",&name);
    char name2[20];
    strcpy(name2,name);

    char cname[] = ".docx1";
    strcat(name,cname);

    printf("Filename: %s\n",name);
    char path[] = "D:\\PRIYANSHU\\Project\\Database for bug tracking system\\";
    char full[1000];
    snprintf(full, sizeof(full),"%s%s",path, name); //is used to redirect the output of printf function onto a buffer
    ptr = fopen(full,"w");

    if(ptr == NULL)
    {
        printf("File is not created!!!");
    }
    fprintf(ptr,"Date and Time: %s",ctime(&ct));

    fprintf(ptr,"Bug ID: %d\n",bug_id);
    printf("Bug ID: %d\n",bug_id);

    fprintf(ptr,"Bug filled by: %s\n\n",name2);

    printf("Enter bug type: ");
    scanf(" %[^\n]s",&bugtype);
    fprintf(ptr,"Bug Type is: %s\n",bugtype);

    printf("Enter Bug Priority: ");
    scanf(" %[^\n]s",&bugpriority);
    fprintf(ptr,"Bug Priority is: %s",bugpriority);
    fprintf(ptr,"\n");

    printf("Enter Bug description:\n");
    scanf(" %[^\n]s",&bugdescription);
    fprintf(ptr,"Bug description: %s\n",bugdescription);
    fprintf(ptr,"\n");

    printf("\nEnter the status of bug: \n");
    printf("1. Not Yet Assigned\n");
    printf("2. In Process\n");
    printf("3. Fixed\n");
    printf("4. Delivered\n");
    printf("\nEnter Your Choice: ");
    scanf("%d",&bugstatus);

    fprintf(ptr,"Date and Time: %s",ctime(&ct));//ctime()--> is used to return the time in hours:minutes:seconds
    fprintf(ptr,"Bug Status: ");

    switch(bugstatus)
    {
        case 1:
             fprintf(ptr,"Not Yet Assigned\n");
             break;
        case 2:
             fprintf(ptr,"In Process\n");
             break;
        case 3:
             fprintf(ptr,"Fixed\n");
             break;
        case 4:
             fprintf(ptr,"Delivered\n");
             break;
        default:
             printf("Invalid Choice\n");
             break;
          
    }
    printf("\nDetails Entered Successfully\n");
    fclose(ptr);
}
void changeBugStatus()
{
     printf("\n");
    printf("************* Changing Status Of Bug *************");
    printf("\n");
    time_t ct;
    time(&ct);

    FILE *ptr;
    char name[20];

    printf("Enter your name: ");
    scanf("%s",name);
    char cname[]=".txt";
    strcat(name,cname);

    char path[]= "D:\\PRIYANSHU\\Project\\Database for bug tracking system\\";
    char full[1000];
    snprintf(full,sizeof(full),"%s%s",path,name);
    ptr = fopen(full,"a");

    printf("\nEnter the change status of the bug: \n");
    printf("1. Not Yet Assigned\n");
    printf("2. In Process\n");
    printf("3. Fixed\n");
    printf("4. Delivered\n");
    printf("\nEnter Your Choice: ");

    int k;
    scanf("%d",&k);

    fprintf(ptr,"\n"); 
    fprintf(ptr,"Date and Time: %s",ctime(&ct));
    fprintf(ptr,"Bug Status: ");

    switch (k)
    {
    case 1:
         fprintf(ptr,"Not Yet Assigned\n");
         break;
    case 2:
          fprintf(ptr,"In Process\n");
          break;
     case 3:
          fprintf(ptr,"Fixed\n");
          break;
     case 4:
          fprintf(ptr,"Delivered\n");
          break;

    default:
        printf("Invalid Choice!!!\n");
         break;
    }

    printf("\nStatus Changed Successfully\n");
    fclose(ptr);
}
void report()
{
     printf("\n");
    printf("************* Report *************");
    printf("\n");

    FILE *ptr;
    char name[20];

    printf("Enter Your Name: ");
    scanf(" %[^\n]s",&name);
    char ex[] = ".txt";
    strcat(name,ex);

    char path[] = "D:\\PRIYANSHU\\Project\\Database for bug tracking system\\";
    char full[1000];
    snprintf(full,sizeof(full),"%s%s",path,name);
    ptr = fopen(full,"r");
    char ch;
    ch = getc(ptr);

    while(ch!=EOF)
    {
         printf("%c",ch);
         ch = getc(ptr);

    }
    fclose(ptr);
    getch();

}
int main()
{
    printf("\n");
    printf("*******************");
    printf("BUG TRACKING SYSTEM");
    printf("*******************\n");

    int choice;
    int bug_id = 0;
    
    while(1)
    {
        printf("\n1. To enter a new Bug.");
        printf("\n2. To change the status of the bug.");
        printf("\n3. To get bug report.");
        printf("\n4. To exit.");
        printf("\n\n Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
           bug_id++;
           fileNewBug(bug_id);
            break;
        case 2:
             changeBugStatus();             
             break;
        case 3:
            report();
             break;
        case 4:
             exit(0);
             break;        
        default:
            printf("\nInvalid choice!!!");
            break;
        }

    }

}