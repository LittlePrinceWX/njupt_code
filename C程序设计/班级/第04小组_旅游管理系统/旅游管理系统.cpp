#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <memory.h>
#include <string.h>
#include <malloc.h> 
#include <windows.h>
#define sizes sizeof (Customer)
#define M 5
struct Customer
{
	char name[20];
	char sex[20];
	char route[20];
	int price;
};
int readFile(Customer cus[],int n);
 void saveFile(Customer cus[],int n);
int n;
typedef struct Customer Customer;
void menu()    /*����˵�����*/ 
{
	printf("**************1.������Ϣ**************\n");
    printf("  ************2.��Ϣ��ѯ************\n");
	printf("    **********3.ҵ�����**********\n");
	printf("      ********4.ͳ�Ʒ���********\n");
	printf("        ******0.  �˳�  ******\n");
}
void menuBase()/*������Ϣ����*/ 
{
  printf("******1.��������Ϣ******\n");
  printf("******2.��·��Ϣ******\n");
  printf("******3.Ա����Ϣ******\n");
  printf("******0.�����ϲ�˵�*****\n");
}
void menucustomer()/*ҵ�������*/ 
{
	printf("******1.�ο���Ϣ¼��******\n");
    printf("******2.�ο���Ϣ����******\n");
    printf("******3.�ο���Ϣɾ��******\n");
    printf("******0.�����ϲ�˵�*****\n");
    }  
int insertcus(Customer cus[],int n)
{
		n=readFile(cus,n);
	
	printf("������һ���ο͵���Ϣ\n");
	scanf("%s%s%s%d",&cus[n].name,&cus[n].sex,&cus[n].route,&cus[n].price);
	saveFile(cus,n);
    return n;
}
int readcus(Customer cus[])/*��ʼʱ¼���������ο���Ϣ*/
 { 
int i,k,j;
	printf("��Ҫ¼����ο�������\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		k=i+1;
		printf("�������%d���ο���Ϣ\n",k);
		
		scanf("%s%s%s%d",cus[i].name,cus[i].sex,cus[i].route,&cus[i].price);
		
		
	}
	return n;
	saveFile(cus,n);
}
int deletecus (Customer cus[],int n)    //ɾ���ο�
{
	n=readFile(cus,n);
	system("cls");
	int i,num=n;
	char str_a[20];
	printf("��֪���е��ο�����\n") ;
	printf("����      �Ա�      ·��      �۸�\n");
	for(i=0;i<n;i++)
	{ 
	printf("�Ұ���"); 
	printf("%s%6s%6s%6d",cus[i].name,cus[i].sex,cus[i].route,&cus[i].price);
	} 
	for(i=0;i<n;i++)
	printf ("������Ҫɾ���ο͵�����:\n");
	scanf ("%s",str_a);
	for (i=0;i<num;i++)
	{
		if (strcmp(cus[i].name,str_a)==0)
		for (i;i<num;i++)
		{
			strcpy(cus[i].name,cus[i+1].name);
			strcpy(cus[i].sex,cus[i+1].sex);
			strcpy(cus[i].route,cus[i+1].route);
			cus[i].price=cus[i+1].price;
			
			
			 
		}
	}
		saveFile(cus,n);
	return n;
}
     
	 
void Message()
{
	menuBase();
	FILE *fp;
	    char ch; 
		int a;
		printf("��������Ҫѡ���ѡ�\n");
        scanf ("%d",&a);
		switch (a)
		{
		   case 1:
           fp=fopen ("D:\\a\\��������Ϣ.txt","r");
		   if (!fp)
		   {
			printf("�޷����ļ�");
		   }
		   while((ch = fgetc(fp))!=EOF)
		   {
		   	putchar(ch);
		   }
		   fclose(fp);break;
		

		   case 2:
	        fp=fopen ("D:\\a\\��·��Ϣ.txt","r");
		   if (!fp)
		   {
			printf("�޷����ļ�");
	       }
	       while((ch = fgetc(fp))!=EOF)
		   {
		   	putchar(ch);
		   }
		   fclose(fp);break;
		   case 3:
	       fp=fopen ("D:\\a\\Ա����Ϣ.txt","r");
		   if (!fp)
		   {
			printf("�޷����ļ�"); 
		}
			while((ch = fgetc(fp))!=EOF)
		   {
		   	putchar(ch);
		   }
		   fclose(fp);break;
		   case 0:break;
	   } 
} 
int yewu(Customer cus[],int n)
{
	int choice;
do
{
menucustomer();

printf("��������Ҫ�����ѡ����:\n");
scanf("%d",&choice);
switch(choice)
{      case 2:  insertcus(cus,n);break;
		case 1: readcus(cus)  ;break;
		case 3:deletecus (cus,n) ;break;
case 0:break;
}
}while(choice);
return n;
}

void tongji()
 {
 FILE *fp;
 char ch;
 fp=fopen("D:\\�½��ļ���\\custom.txt","r");
		   if (fp==0)
		   {
			printf("�޷����ļ�");
	       }
	       while((ch = fgetc(fp))!=EOF)
		   {
		   	putchar(ch);
		   }
		   fclose(fp);
		  
	}

void chaxun(struct Customer cus[M])
{
    char *q;
    int i;
 
    printf("������Ҫ��ѯ������:\n");
    scanf("%s",q);
     
    for(i=0;i<M;i++)
    { 
        if(strcmp(cus[i].name,q)==0)
        { 
            printf("result:%s %s %s %d\n",cus[i].name,cus[i].sex,cus[i].route,cus[i].price);
            break;
        }
    }
}


 void saveFile(Customer cus[],int n)
 {
 	int i;
 	FILE *fp;
 	if((fp=fopen("d:\\�½��ļ���\\customer.txt","w ")) ==NULL)
 	{
 		printf("can not open file !\n");
 	
	 }
	 for(i=0;i<n;i++)
	 {
	 fwrite(&cus[i],sizeof(struct Customer),n,fp);
}
	 fclose(fp);
 }

int readFile(Customer cus[],int n)
 {
 	FILE *fp;
 	int i=0;
 	if((fp=fopen("d:\\�½��ļ���\\customer.txt","r")) ==NULL)
 	{
 		printf("file does not exist,create it first:\n");
 		return 0;
	 }
	 for(i=0;i<n;i++)
	 {
	 fread(&cus[i],sizeof(struct Customer),n,fp);
}
	 while(!feof(fp))
	 {
	 	i++;
	 	fread(cus,sizeof(cus),1,fp);
	 }
	 fclose(fp);
	 return i;
 }
int main()
{
	Customer cus[30];
	int choice,i,n,key;
	n=readFile(cus,n);
     printf("                                              #��ӭ�������ι���ϵͳ#                  \n");
    printf ("                                              #       welcome      #                       \n");
    printf("                                                             \n");
	   	for(i=1;i>0;i++) 
		{
			printf("��������ȷ��������:\n");
	        scanf("%d",&key); 
		    if(key==34207)
		       break;
			else
			printf("������� ����������\a") ;
		} 
		do
		{
		menu();
		printf("please input your choice:");
		scanf("%d",&choice);
	    switch (choice)
	{
		case 1:Message( );
		       break;
	    case 2:chaxun(cus);
		      break;
		case 3:yewu(cus,n);
		       break;
		case 4:tongji( );
		       break;
		       case 0:break;
	 }
	}while(choice);
	saveFile(cus,n);
	return n;
	} 
