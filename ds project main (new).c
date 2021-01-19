#include<stdio.h> //file 
#include<conio.h> //int etc
#include<string.h> //%s stry copy stricpm
#include<stdlib.h> //used for pf sf
#include<dos.h> //used for goto
#include<malloc.h> //malloc 
struct contact 
{
	char ph[12],work[12];
	char name[20],add[100],email[30];
	char company[20],dob[9];
} list;
struct node
{
	char ph[12],work[12];
	char name[20],add[100],email[30];
	char company[20],dob[9];
	struct node *next;
};
struct node *top,*temp;
char name[20];
FILE *fp, *ft;
int i,n,ch,l,found;
struct node *insert(struct node *);
void display();
void search();
void dis(struct node *);
void del();
struct node *arrange(struct node *,struct node *);
int main()
{
do 
{
main:
    system("cls");    /* ************Main menu ***********************  */
    printf("\n\t"); 
	printf("**** Contact Management System ****");
    printf("\n\n\n\t\t\tMAIN MENU\n================================================================================");
	printf("\n\t\t 1>> Add a new Contact");
	printf("\n\t\t 2>> List all Contacts");
	printf("\n\t\t 3>> Search for contact");
	printf("\n\t\t 4>> Delete a Contact");
	printf("\n\t\t 5>> Recent Contacts");
	printf("\n\t\t 6>> Exit");
	printf("\n================================================================================\n\t\t");
    printf("Enter the choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    	case 1:
    		ins:
    		system("cls");
    		temp=insert(top);
    		top=arrange(temp,top);
    		printf("contact Inserted sucessfully \n");
    		printf("enter 1 to ADD another contact \nelse enter 0:");
    		scanf("   %d",&ch);
    		if(ch==1)
    		goto ins;
    		else
    		break;
    	case 2:
    		system("cls");
    		display();
    		break;
    	case 3:
    		search();
    		break;
    	case 4:
    		del();
    		break;
    	case 5:    	
    		system("cls");
    		dis(top);
    		break;
    	case 6:	
    		break;
    	default:
    		break;
    	
	}
}while(ch!=6);
}


struct node *insert(struct node *top)
{	int n;
	struct node *ptr;
 	ptr=(struct node *)malloc(sizeof(struct node));
	     	fp=fopen("contact0.dll","a");
 			printf("enter name: ");
 		    fflush(stdin);
            scanf("%[^\n]",&ptr->name);
            fflush(stdin);
            printf("Personal Phone No: ");
            scanf("%[^\n]",&ptr->ph);
            fflush(stdin);
            printf("address: ");
            scanf("%[^\n]",&ptr->add);
            printf("do you want to add Work info then enter '1' else enter '0' \n");
            scanf("%d",&n);
            if(n==1)
            {
            fflush(stdin);
            printf("DOB ");
            scanf("%[^\n]",&ptr->dob);
            fflush(stdin);
            printf("email address: ");
            scanf("%[^\n]",&ptr->email);
            fflush(stdin);
            printf("company working: ");
            scanf("%[^\n]",&ptr->company);
            fflush(stdin);
            printf("Profesional (work) Phone No: ");
            scanf("%[^\n]",&ptr->work);
            strcpy(list.dob,ptr->dob);
            strcpy(list.email,ptr->email);
            strcpy(list.company,ptr->company);
            strcpy(list.work,ptr->work);
        	}
        	printf("\n");
            strcpy(list.name,ptr->name);
            strcpy(list.add,ptr->add);
            strcpy(list.ph,ptr->ph);
            if(n==0)
            {
            strcpy(list.dob,"NO DATA");
            strcpy(list.email,"NO DATA");
            strcpy(list.company,"NO DATA");
            strcpy(list.work,"NO DATA");
			}
			fwrite(&list,sizeof(list),1,fp);
            fclose(fp);
    return ptr;
}
void display()
{
	int i,n;
	printf("do you want a detailed phonebook then enter '1' else 0 \n" );
    scanf("%d",&n);
 system("cls");
        printf("\n\t\t========================================\n\t\t|\t<<<<LIST OF CONTACTS>>>>       |\n\t\t========================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");
	    for(i=97; i<=122; i=i+1)
        {
           FILE *fp=fopen("contact0.dll","r");
            fflush(stdin);
            int found=0;
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                if(list.name[0]==i || list.name[0]==i-32)
                {	if(n==0)
                   {
					 printf("\nName\t: %s\nPhone\t: %s\nAddress\t: %s\nEmail\t: %s\n",list.name,list.ph,list.add,list.email);
                     found++;
            		}
            		else
            		{
            		printf("\nName: %s\nPhone: %s\nAddress: %s\n",list.name,list.ph,list.add);
            		printf("work no.: %s\nEmail Add: %s\nCompany Working: %s\nDOB: %s\n",list.work,list.email,list.company,list.dob);
                    found++;	
					}
                }
            }
            if(found!=0)
            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);
                getch();
            }
            fclose(fp);
        }
}

void dis(struct node *top)
{
struct node *ptr;
int found=0;
ptr=top;
if(top==NULL)
printf("\n NO RECENT CONTACT AVAILABEL");
else
{
	 printf("\n\t\t================================\n\t\t\tLIST OF RECENT CONTACTS\n\t\t================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");
	while(ptr!=NULL)
{
	printf("\nName\t\t: %s\nPhone\t\t: %s\nAddress\t\t: %s \n",list.name,list.ph,list.add);
    printf("work no.\t: %s \nEmail Add\t: %s \nCompany Working\t: %s \nDOB\t\t: %s\n",list.work,list.email,list.company,list.dob);
ptr=ptr->next;
found++;
}
printf("=========================================================== (%d)\n\n",found);
}
getch();
}

struct node *arrange(struct node *temp,struct node *top)
{
	if(top==NULL)
	{
		temp->next=NULL;
		top=temp;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
return top;
}

void search()
{   char name1[20];
    int n;
    printf("do you want a detailed phonebook then enter '1' else 0 \n" );
    scanf("%d",&n);
	system("cls");
            found=0;
            printf("\n\n\tCONTACT SEARCH\n================================================================================\n\tName of contact to search: ");
            fflush(stdin);
            scanf("%[^\n]",&name1);
            int i,found,l=strlen(name1);
            FILE *fp=fopen("contact0.dll","r");
            system("cls");
            printf("\n================================================================================\n>>>>>Search result for <<<<<'%s'>>>> \n===================================================\n",name1);
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                for(i=0; i<=l; i++)
                    name[i]=list.name[i];
                name[l]='\0';
                if(stricmp(name,name1)==0)
                {
                	if(n==0)
                    {
					printf("\nName\t: %s\nPhone\t: %s\nAddress\t: %s\nEmail\t: %s\n",list.name,list.ph,list.add,list.email);
            		}
            		else
            		{
            		printf("\nName: %s\nPhone: %s\nAddress: %s\n",list.name,list.ph,list.add);
            		printf("work no.: %s\nEmail Add: %s\nCompany Working: %s\nDOB: %s\n",list.work,list.email,list.company,list.dob);
            		}
                }
            }printf("=========================================================================");
            fclose(fp);
            getch();
}
	
void del()
{
    fp=fopen("contact0.dll","r");
	ft=fopen("temp.dat","w");
	system("cls");
    fflush(stdin);
	printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");
    scanf("%[^\n]",&name);
        
    while(fread(&list,sizeof(list),1,fp)!=0)
            if (stricmp(name,list.name)!=0)
             fwrite(&list,sizeof(list),1,ft);
      fclose(fp);
      fclose(ft);
     remove("contact0.dll");
     rename("temp.dat","contact0.dll");

}
