#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x,int y)
{
COORD RAKHI;
RAKHI.X=x;
RAKHI.Y=y;
SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),RAKHI);

}
struct info
{
    char name[1000];
    char section[11];
    char advisor[50];
    int id;
    int batch;
};
void printchar(char c, int n){
    while(n--)
    {
    putchar(c);
    }
}
void printhead()
{
    gotoxy(55,2);
printchar('=',40);
gotoxy(57,4);
printf("WELCOME TO ADVISING TEACHING SYSTEM");
gotoxy(55,6);
printchar('=',40);
}
void login()
{
    system("CLS");
    char user[10]="raton",pass[6]="201103",u[10],p[6],ch;
    int i,n;
    printf("\n Enter Username: \n\t\t");
    scanf("%s",&u);
    printf("\n Enter Your Password: \n\t\t");
    for(i=0; i<6; i++)
    {
        ch=getch();
        p[i]=ch;
        ch='*';
        printf("%c",ch);
    }
    if(strcmpi(u,user)==0)
    {
        if(strcmpi(p,pass)==0)
        {
            printf("\n\n");
            admin();
        }
        else
        {
            printf("\n\n\n\t\t\aPassword error!!!! \n");
        }
    }
    else
    {
        printf("\n\n\n\t\t\t\tUser Doesn't Exist\n");
    }
}
void main()
{
    system("cls");
    printhead();
    int y;
    gotoxy(60,7);
    printf("Choose One");
    gotoxy(60,8);
    printf("1.ADMIN");
    gotoxy(60,9);
    printf("2.TEACHER");
    gotoxy(60,10);
    printf("3.STUDENT");
    //printf("\t\tchoose one\n\t1.ADMIN\n\t2.teacher\n\t3.student\n");
    gotoxy(60,13);
    printf("Enter Your Choice\t:");
    scanf("%d",&y);
    system("CLS");
    switch(y)
    {
    case 1:
    {
        login();
        break;
    }
    case 2:
    {
        teacher();
        messege();
        break;
    }
    case 3:
    {
        student();
        view_messege();
        break;
    }
    getch();
    }
}
void admin()
{
    int n;
    printf("\nchoose one \n1.Add student & Advisor\n2.search\n3.students & Advisor list\n4.Update information\n5.Delete information\n");
    scanf("%d",&n);
    system("color D");
    system("CLS");
    switch(n)
    {
    case 1:
    {
        insert();
        break;

    }
    case 2:
    {
        search();
        break;
    }
    case 3:
    {
        disp();
        break;
    }
    case 4:
    {
        update();
        break;
    }
    case 5:
        {
            delete();
            break;
        }
    default :
    {
        printf("\n\n\n\t\t\tInvalid number\n\t\t");
    }
    }
}
void insert()
{
    char another;
    struct info ca;
    another='y';
    while(another== 'y')
    {
        FILE *fp;
        fp=fopen("jarvis.txt","a");
        printf("ENTER NAME: \n");
        scanf("%s",&ca.name);
        printf("ENTER SECTION : \n");
        scanf("%s",&ca.section);
        printf("ENTER THE ADVISOR NAME : \n");
        scanf("%s",&ca.advisor);
        printf("ENTER THE ID : \n");
        scanf("%d",&ca.id);
        printf("ENTER THE BATCH :\n");
        scanf("%d",&ca.batch);
        printf("The record is successfully added");
        fwrite(&ca,sizeof(ca),1,fp);
        printf("\nDo you want to insert more Student & Adviser? (y/n)  : \n\n");
        fflush(stdin);
        another=getch();
        fclose(fp);
    }
    back();
}
void search()
{
    system("color 5");
    struct info ca;
    char another;
    int id;
    another='y';
    while(another== 'y')
    {
        printf("Enter the id you want to search : \n");
        scanf("%d",&id);
        system("CLS");
        FILE *fp;
        fp=fopen("jarvis.txt","r");
        while(fread(&ca,sizeof(ca),1,fp))
            if(ca.id==id)
            {
                printf("\nname : %s\nsection : %s\nadvisor : %s\nid : %d\nbatch : %d\n",ca.name,ca.section,ca.advisor,ca.id,ca.batch);
            }
        printf("\nwnat to see any other id details?? (y/n)  : \n\n");
        fflush(stdin);
        another=getch();
        fclose(fp);
    }
    back();
}
void disp()
{
    system("color B");
    struct info ca;
    FILE *fp;
    fp=fopen("jarvis.txt","r");
    while(fread(&ca,sizeof(ca),1,fp))
    {
        printf("\nname : %s\nsection : %s\nadvisor : %s\nid : %d\nbatch : %d\n",ca.name,ca.section,ca.advisor,ca.id,ca.batch);
    }
    fclose(fp);
    back();
}
void update()
{
    system("color E");
    char another;
    struct info ca;
    int id;
    FILE *fp;
    fp = fopen("jarvis.txt","r+");
    another='y';
    while(another== 'y')
    {
        printf("enter the id you want to modify : ");
        scanf("%d",&id);
        system("CLS");
        rewind(fp);
        while(fread(&ca,sizeof(ca),1,fp))
        {
            if(ca.id==id)
            {

                printf("Enter name: \n");
                scanf("%s",&ca.name);
                printf("Enter SECTION : \n");
                scanf("%s",&ca.section);
                printf("Enter the ADVISOR NAME : \n");
                scanf("%s",&ca.advisor);
                printf("Enter the ID : \n");
                scanf("%d",&ca.id);
                printf("Enter THE BATCH :\n");
                scanf("%d",&ca.batch);
                printf("The record is successfully added");
                fseek(fp,-sizeof(ca),SEEK_CUR);
                fwrite(&ca,sizeof(ca),1,fp);
                break;
            }
        }
        printf("\nmodify another record(y/n)\n\n");
        fflush(stdin);
        another=getch();
    }
    fclose(fp);
    back();
}
void student()
{
    system("color D");
    printf("\n\n\t\tSee teacher & choose who's your Advisor\n\n");
    printf("\n\n\t\tHere The list of teacher and student list\n\n");
    printf("\n\n\t\t1.Shayla pervin(MSP)-----(Student NO:1 To Student No:5)\n\n");
    printf("\t\t2.Shohel Arman(MSA)-----(Student NO:5 To Student No:10)\n\n");
    printf("\t\t3.Nusrat Jahan(NJ)-----(Student NO:11 To Student No:15)\n\n");
    printf("\t\t4.Afsana Begom(AB)-----(Student NO:16 To Student No:20)\n\n");
    printf("\t\t5.Sarmin Akter(SA)-----(Student NO:21 To Student No:25)\n\n");
    printf("\t\t6.Atia Sanjida(AS)-----(Student NO:26 To Student No:30)\n\n");
    view_messege();
    back();
}
void teacher()
{
    system("color B");
    printf("\n\n\t\t1.Shayla pervin(MSP)-----(Student NO:1 To Student No:5)\n\n");
    printf("\t\t2.Shohel Arman(MSA)-----(Student NO:5 To Student No:10)\n\n");
    printf("\t\t3.Nusrat Jahan(NJ)-----(Student NO:11 To Student No:15)\n\n");
    printf("\t\t4.Afsana Begom(AB)-----(Student NO:16 To Student No:20)\n\n");
    printf("\t\t5.Sarmin Akter(SA)-----(Student NO:21 To Student No:25)\n\n");
    printf("\t\t6.Atia Sanjida(AS)-----(Student NO:26 To Student No:30)\n\n");
    printf("Choose number___:::\n1.Search Students & Comment\n2.Exit :\n");
    int q;
    scanf("%d",&q);
    system("CLS");
    switch(q)
    {
    case 1:
        srch();
        break;
    default :
    {
        printf("\n\n\n\t\t\tInvalid input\n\t\t");
    }
    }
    back();
}
void srch()
{
    system("color E");
    struct info ca;
    char another;
    int id;
    another='y';
    while(another== 'y')
    {
        printf("Enter the id you want to search : \n");
        scanf("%d",&id);
        system("CLS");
        FILE *fp;
        fp=fopen("jarvis.txt","r");
        while(fread(&ca,sizeof(ca),1,fp))
            if(ca.id==id)
            {
                printf("\nname : %s\nsection : %s\nadvisor : %s\nid : %d\nbatch : %d\n",ca.name,ca.section,ca.advisor,ca.id,ca.batch);
            }
            messege();
        printf("\n\nwant to see any other id details?? (y/n)  : \n\n");
        fflush(stdin);
        another=getch();
        fclose(fp);
    }
    back();
}


delete()
{
    system("color C");
    FILE *fp,*fp1;
    struct info ca;
    int found=0,count=0;
    int h;
    char another;
    another='y';
    while(another== 'y')
    {
          fp=fopen("jarvis.txt","r");
          fp1=fopen("tempr.txt","w");
          printf("\n Enter the number you want to delete : ");
          scanf("%d",&h);
          system("CLS");
          while(1)
          {
              fread(&ca,sizeof(ca),1,fp);
              if(feof(fp))
              {
                  break;
              }
              if(ca.id==h)
              {
                  found=1;
              }
              else
              {
                  fwrite(&ca,sizeof(ca),1,fp1);
              }
          }
        fclose(fp);
        fclose(fp1);
        if(found==0)
        {
            printf("sorry no record found");
        }
        else
        {
           fp=fopen("jarvis.txt","w");
           fp1=fopen("tempr.txt","r");
           while(1)
           {
               fread(&ca,sizeof(ca),1,fp1);
               if(feof(fp1))
               {
                   break;
               }
               fwrite(&ca,sizeof(ca),1,fp);
           }
        }
        printf("\Do you want to delete more? (y/n) : \n\n");
        fflush(stdin);
        another=getch();
        fclose(fp);
        fclose(fp1);
    }
    back();
}


void back()
{
    int i;
    printf("\nDo you want to Continue press (0) or Back (1)\n");
    printf("\n\nEnter your choise : ");
    scanf("%d",&i);
    system("CLS");
    if(i==0)
    {
        main();
    }
    else if(i==2)
    {
        printf("\n\n\t\t\tThank You\n\n\t\t\tLOADING");
        main();
    }
    else
    {
        printf("Invalid Choice\n");
        back();
    }
}

struct meg
{
    char name[100];
    char b[100];

};
messege()
{
    FILE *fp;
    fp=fopen("sunn.txt","a");
    struct meg rekha;
    printf("Enter your name: ");
    fflush(stdin);
    fgets(rekha.name,50,stdin);
    printf("Enter your message:");
    fflush(stdin);
    fgets(rekha.b,100,stdin);
    fwrite(&rekha,sizeof(rekha),1,fp);
    fclose(fp);
}
void view_messege()
{
    struct meg rekha;
    FILE *fp;
    fp=fopen("sunn.txt","r");
    //printf("Message__::Come to My Counseling hour.\n ");
    while(fread(&rekha,sizeof(rekha),1,fp))
    {
        printf("Name:%s",rekha.name);
        printf("Message :%s",rekha.b);
    }
    fclose(fp);
}

