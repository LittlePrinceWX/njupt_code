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
void menu()    /*顶层菜单函数*/ 
{
	printf("**************1.基础信息**************\n");
    printf("  ************2.信息查询************\n");
	printf("    **********3.业务管理**********\n");
	printf("      ********4.统计分析********\n");
	printf("        ******0.  退出  ******\n");
}
void menuBase()/*基本信息函数*/ 
{
  printf("******1.旅行社信息******\n");
  printf("******2.线路信息******\n");
  printf("******3.员工信息******\n");
  printf("******0.返回上层菜单*****\n");
}
void menucustomer()/*业务管理函数*/ 
{
	printf("******1.游客信息录入******\n");
    printf("******2.游客信息插入******\n");
    printf("******3.游客信息删除******\n");
    printf("******0.返回上层菜单*****\n");
    }  
int insertcus(Customer cus[],int n)
{
		n=readFile(cus,n);
	
	printf("请输入一个游客的信息\n");
	scanf("%s%s%s%d",&cus[n].name,&cus[n].sex,&cus[n].route,&cus[n].price);
	saveFile(cus,n);
    return n;
}
int readcus(Customer cus[])/*初始时录入批量的游客信息*/
 { 
int i,k,j;
	printf("需要录入的游客人数：\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		k=i+1;
		printf("请输入第%d个游客信息\n",k);
		
		scanf("%s%s%s%d",cus[i].name,cus[i].sex,cus[i].route,&cus[i].price);
		
		
	}
	return n;
	saveFile(cus,n);
}
int deletecus (Customer cus[],int n)    //删除游客
{
	n=readFile(cus,n);
	system("cls");
	int i,num=n;
	char str_a[20];
	printf("已知现有的游客名单\n") ;
	printf("姓名      性别      路线      价格\n");
	for(i=0;i<n;i++)
	{ 
	printf("我爱你"); 
	printf("%s%6s%6s%6d",cus[i].name,cus[i].sex,cus[i].route,&cus[i].price);
	} 
	for(i=0;i<n;i++)
	printf ("输入需要删除游客的名字:\n");
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
		printf("请输入你要选择的选项：\n");
        scanf ("%d",&a);
		switch (a)
		{
		   case 1:
           fp=fopen ("D:\\a\\旅行社信息.txt","r");
		   if (!fp)
		   {
			printf("无法打开文件");
		   }
		   while((ch = fgetc(fp))!=EOF)
		   {
		   	putchar(ch);
		   }
		   fclose(fp);break;
		

		   case 2:
	        fp=fopen ("D:\\a\\线路信息.txt","r");
		   if (!fp)
		   {
			printf("无法打开文件");
	       }
	       while((ch = fgetc(fp))!=EOF)
		   {
		   	putchar(ch);
		   }
		   fclose(fp);break;
		   case 3:
	       fp=fopen ("D:\\a\\员工信息.txt","r");
		   if (!fp)
		   {
			printf("无法打开文件"); 
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

printf("请输入你要进入的选项编号:\n");
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
 fp=fopen("D:\\新建文件夹\\custom.txt","r");
		   if (fp==0)
		   {
			printf("无法打开文件");
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
 
    printf("请输入要查询的姓名:\n");
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
 	if((fp=fopen("d:\\新建文件夹\\customer.txt","w ")) ==NULL)
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
 	if((fp=fopen("d:\\新建文件夹\\customer.txt","r")) ==NULL)
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
     printf("                                              #欢迎进入旅游管理系统#                  \n");
    printf ("                                              #       welcome      #                       \n");
    printf("                                                             \n");
	   	for(i=1;i>0;i++) 
		{
			printf("请输入正确数字密码:\n");
	        scanf("%d",&key); 
		    if(key==34207)
		       break;
			else
			printf("口令错误 请重新输入\a") ;
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
