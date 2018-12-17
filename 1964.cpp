#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct database{
char ID[15],name[30],course[25],section[3], cgpa[5];
};
struct database b;

int choice,i;
int found=0,l;
char n_id[15],search[15];
char z[] = "0";
FILE *fp,*ft;


main()
{
main:
system("cls");
system("COLOR F0");
printf("\t\t\t\t:::Student Information System:::\n\n\t\t\t\t\t::Main Menu::\n\n\t\t\t\t[1] Add Record\n\t\t\t\t[2] Record List\n\t\t\t\t[3] Search Record\n\t\t\t\t[4] Edit Record\n\t\t\t\t[5] Delete Record\n\t\t\t\t[0] Exit\n");
printf("Enter Your Choice:");
scanf("%d",&choice);

switch(choice)
{

case 0:
    break;

case 1:
    system("cls");
    fp=fopen("file.txt","a");
    for(;;)
    {
        fflush(stdin);
        printf("Enter '0' or put a 'space' to exit");
        printf("\nEnter ID:");
        scanf("%[^\n]",&b.ID);
        if(strcmp(b.ID," ")==0 || strcmp(b.ID,z)==0)break;
        fflush(stdin);
        printf("Enter Name:");
        scanf("%[^\n]",&b.name);
        fflush(stdin);
        printf("Enter Course:");
        scanf("%[^\n]",&b.course);
        fflush(stdin);
        printf("Enter Section:");
        scanf("%s",&b.section);
        fflush(stdin);
        printf("Enter C.G.P.A:");
        scanf("%s",&b.cgpa);
        printf("\n");
        fwrite(&b,sizeof(b),1,fp);
        fflush(stdin);
    }
fclose(fp);
break;

case 2:
    system("cls");
    printf("\n\t\t\t\t\tRecord List\n\n");

    for(i=97;i<=122;i++)
    {
        fp=fopen("file.txt","r");

        fflush(stdin);
        while(fread(&b,sizeof(b),1,fp)==1)
        {
            if(b.name[0]==i || b.name[0]==i-32)
            {
                printf("\nID: %s\nName: %s\nCourse: %s\nSection: %s\nC.G.P.A: %s\n",b.ID,b.name,b.course,b.section,b.cgpa);
            }
        }
        fclose(fp);
    }
break;


case 3:
   system("cls");
    do{
        found=0;
        printf("\t\t\t\tSearch Record\n\n\tID number to search:");
        fflush(stdin);
        scanf("%[^\n]",&search);
        l=strlen(search);
        fp=fopen("file.txt","r");

        system("cls");

        while(fread(&b,sizeof(b),1,fp)==1){
            for(i=0;i<=l;i++){
               n_id[i]=b.ID[i];
                n_id[l]='\0';
            }

            if(strcmp(n_id,search)==0){
                printf("\nID: %s\nName: %s\nCourse: %s\nSection: %s\nC.G.P.A: %s\n",b.ID,b.name,b.course,b.section,b.cgpa);
                found++;
            }
        }

        if(found==0){printf("\nNo Match Found\n");}
        else{printf("\n%d match found\n",found);
        fclose(fp);
        }

        printf("\nTry again??\n\t\t\t[1] Yes\t\t[0] No\n");
        scanf("%d",&choice);
    }while(choice==1);
break;

case 4:
system("cls");
fp=fopen("file.txt","r");
ft=fopen("temp.txt","w");
fflush(stdin);
printf("..::Edit data\n===============================\n\n\t..::Enter the id to edit:");
scanf("%[^\n]",search);
while(fread(&b,sizeof(b),1,fp)==1)
{
if(stricmp(search,b.ID)!=0)
fwrite(&b,sizeof(b),1,ft);
}
fflush(stdin);
printf("\n\n..::Editing '%s'\n\n",search);
printf("..::Name(Use identical):");
scanf("%[^\n]",&b.name);
fflush(stdin);
printf("..::ID:");
scanf("%[^\n]",&b.ID);
fflush(stdin);
printf("..::Course:");
scanf("%[^\n]",&b.course);
fflush(stdin);
printf("..::Section:");
scanf("%c",&b.section);
printf("..::C.G.P.A:");
scanf("%s",&b.cgpa);
printf("\n");
fwrite(&b,sizeof(b),1,ft);
fclose(fp);
fclose(ft);
remove("file.txt");
rename("temp.txt","file.txt");
break;

case 5:
system("cls");
fflush(stdin);
printf("\n\n\t..::DELETE A DATA\n\t==========================\n\t..::Enter the ID of data to delete:");
scanf("%[^\n]",&search);
fp=fopen("file.txt","r");
ft=fopen("temp.txt","w");
while(fread(&b,sizeof(b),1,fp)!=0)
if (stricmp(search,b.ID)!=0)
fwrite(&b,sizeof(b),1,ft);
fclose(fp);
fclose(ft);
remove("file.txt");
rename("temp.txt","file.txt");
break;



    default:
        printf("Invalid choice:");
break;
    }



printf("\nSure to Exit??\n");
printf("\t\t[1] Main Menu\t\t[0] Exit\n");
scanf("%d",&choice);

switch(choice)
{

case 0:
    break;
case 1:
    goto main;
}

}
