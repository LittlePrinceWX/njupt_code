#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h>

void menu()
{   printf("                 ****************************************\n");  
	printf("                 **             1.基础信息             **\n");
    printf("                 *****          2.业务管理          *****\n");
	printf("                 *******        3.信息查询        *******\n");
	printf("                 *****          4.统计分析          *****\n");
	printf("                 **             5.  退出               **\n");
	printf("                 ****************************************\n");
}
void menuBase()
{
    printf("                        ******1.旅行社信息  ******\n");
    printf("                        ******2. 线路信息   ******\n");
    printf("                        ******3. 员工信息   ******\n");
    printf("                        ******0.返回上层菜单******\n");
}

void menuManage()
{
    printf("                       ******1. 业务登记   ******\n");
    printf("                       ******2. 确认出游   ******\n");
    printf("                       ******3. 业务结算   ******\n");
    printf("                       ******0.返回上层菜单******\n");
}
void menuSearch()
{
	printf("                      ******1.线路信息查询******\n");
	printf("                      ******2.人员信息查询******\n");
	printf("                      ******3.业务登记查询******\n");
	printf("                      ******4.确认出游查询******\n");
	printf("                      ******5.业务结算查询******\n");
	printf("                      ******0.返回上层菜单******\n");
}
void menuCount()
{
	printf("                      ******1.登记业务汇总表******\n");
	printf("                      ******2.确认出游汇总表******\n");
	printf("                      ******3.业务结算汇总表******\n");
	printf("                      ******4. 期间结算统计 ******\n");
	printf("                      ******0. 返回上层菜单 ******\n");
}



void yes()
{
		FILE *fp;
	char ch;
	fp=fopen("F:\\新建文件夹\\旅行社信息.txt","r");
    if(fp==0)
{
	printf("file error\n");
    exit(1);
}
while((ch=fgetc(fp))!=EOF)
{
	putchar(ch);
}
putchar('\n');
fclose(fp);
}


void no()
{
		FILE *fp;
	char ch;
	fp=fopen("F:\\新建文件夹\\线路信息.txt","r");
    if(fp==0)
{
	printf("file error\n");
    exit(1);
}
while((ch=fgetc(fp))!=EOF)
{
	putchar(ch);
}
putchar('\n');
fclose(fp);
}


void hi()
{
		FILE *fp;
	char ch;
	fp=fopen("F:\\新建文件夹\\员工信息.txt","r");
    if(fp==0)
{
	printf("文件错误\n");
    exit(1);
}
while((ch=fgetc(fp))!=EOF)
{
	putchar(ch);
}
putchar('\n');
fclose(fp);
}

void printHead()
{
	int choice;
	do{
	printf("         ------------------------基础信息-----------------------\n");
	menuBase();
	printf("选择您的入口:\n");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1:printf("         ------------------------旅行社信息-----------------------\n");
		       yes();
		       break;
		case 2:printf("         ------------------------线路信息-----------------------\n");
		       no();
		       break;
		case 3:printf("         ------------------------员工信息-----------------------\n");
		       hi();
		       break;
		case 0:break;
		 	}
		 	}while(choice>=1&&choice<=3) ;


}


 struct MessageRoad /*道路信息*/
{
	char name[10];
	char time[10];
	char way[20];
	int money;
};
typedef struct MessageRoad MessageRoad;
MessageRoad s[3]={{"上海","两天","巴士",1000},{"常州","两天","巴士",200},{"镇江","两天","巴士",500}}; 



void SearchRoad(MessageRoad)/*道路信息查询*/
{
	int choice;

	
	
		do{	
			printf("                  1.上海 2.常州 3.镇江 0.返回上级菜单\n");
			printf ("请选择入口:\n");
			scanf ("%d",&choice);
			if(choice<=3)
			switch(choice)
		{
		case 1: printf("     ----------------------------------------------------------------------\n");
			    printf("                   *地点    :    %s*\n                   *旅游时间: %s*\n                   *乘坐方式: %s*\n                   *费用    :    %d*\n",s[0].name,s[0].time,s[0].way,s[0].money);
			    printf("     ----------------------------------------------------------------------\n");
				break;
        case 2: printf("     ----------------------------------------------------------------------\n");
			    printf("                   *地点    :    %s*\n                   *旅游时间: %s*\n                   *乘坐方式: %s*\n                   *费用    :    %d*\n",s[1].name,s[1].time,s[1].way,s[1].money);
			    printf("     ----------------------------------------------------------------------\n");
				break; 
		case 3: printf("     ----------------------------------------------------------------------\n");
			    printf("                   *地点    :    %s*\n                   *旅游时间: %s*\n                   *乘坐方式: %s*\n                   *费用    :    %d*\n",s[2].name,s[2].time,s[2].way,s[2].money);
		        printf("     ----------------------------------------------------------------------\n");
				break;
		case 0:break;
		}
			else
	{
		printf("the number is wrong");
	}
	}while(choice>=1&&choice<=3);
	
	
}

struct ManMessage /*人员信息查询*/
{
	char name[10];
	char sex[10];
	char adress[20];
	int phonenumber;
	int IDcard;
};
typedef struct ManMessage ManMessage;
ManMessage f[2]={{"fei","b","kai",154,1998},{"shn","f","gui",145,1999}};

void ManFound(ManMessage)
{
	int i,n;
	printf("请输入你想查询的身份证号！\n");
	scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		if (f[i].IDcard==n)
		{
			printf("姓名：%s\n性别：%s\n家庭住址：%s\n电话号码：%d\n身份证号：%d\n",f[i].name,f[i].sex,f[i].adress,f[i].phonenumber,f[i].IDcard);
		}
	}
	
}


struct thing/*业务信息*/
{
	char name[10];
	char road[20];
	int money;
	int number;
	int ID;
};
typedef struct thing thing;
thing z[10]={0} ;

int readFile(thing z[])  /*业务查询*/
{
    FILE *fp;
	int i=0,n;
	fp=fopen("F:\\新建文件夹\\业务.txt","ab+");
	if(fp==0)
	{
		printf("无法打开！\n");
		return 0;
	}
    fread(&z[i],sizeof(z),1,fp);
	while(!feof(fp))
	{
		i++;
		fread(&z[i],sizeof(z),1,fp);
	}
	 printf("请输入你想查询的身份证号！\n");
	scanf("%d",&n);
	for(i=0;i<100;i++)
	{
		
		if (z[i].ID==n)
		{   
		    printf("编号    姓名    路线    号码    费用    身份证号\n");
		    printf("%d\t%s\t%s\t%d\t%d\t%d\t\n",i,z[i].name,z[i].road,z[i].number,z[i].money,z[i].ID); 
			break; 
		}
		 if(i=100)
	    {
		printf("信息不存在\n");
     	}
	}

	fclose(fp);
    return 0;
}

struct MoneyOver      /*业务结算*/
{
	char name[20];
	int ShouldMoney;
	int TureMoney;
	int ID;
};
typedef MoneyOver MoneyOver;
MoneyOver busin[10];


void MessageMoney (MoneyOver busin[])/*业务结算查询*/
{
	int i=0,n;
	FILE *fp;
	fp=fopen("F:\\新建文件夹\\结算.txt","ab+");
	if(fp==0)
	{
		printf("无法打开！\n");
		exit(1);
	}
    fread(&busin[i],sizeof(busin),1,fp);
	while(!feof(fp))
	{
		i++;
		fread(&busin[i],sizeof(busin),1,fp);
	}
	printf("请输入你想查询的身份证号！\n");
	scanf("%d",&n);
	for(i=0;i<100;i++)
	{
		if (busin[i].ID==n)
		{   
		    printf("姓名 应交费用 实缴费用 身份证号\n");
		   
			printf("%s\t%d\t%d\t%d\t\n",busin[i].name,busin[i].ShouldMoney,busin[i].TureMoney,busin[i].ID);
			break;
		}
        if(i=100)
    	{
		printf("号码不存在\n");
	    }

	}
	fclose(fp) ;
}


void messageSearch()        /*信息查询*/
{
	int choice;
     

	do{
		 printf("         -----------------------信息查询-----------------------\n");
		menuSearch();
			printf("选择您的入口:\n");
	scanf("%d",&choice); 
	switch (choice)
	{
	case 1:printf("        --------------------道路信息查询-----------------------\n");
	        SearchRoad(s[3]);
			   break;
	case 2:printf("       ---------------------人员信息查询-----------------------\n");
	        ManFound(f[2]);
			   break;
	case 3:printf("       ---------------------业务登记查询-----------------------\n");
	       readFile(z);
		   break;
	case 4:printf("       ---------------------确认出游查询-----------------------\n");
			break;
	case 5:printf("       ---------------------业务结算查询-----------------------\n");
	        MessageMoney(busin);
            break;
	case 0:break;
}  
	}while(choice>=1&&choice<=5);
}

int Read(thing *z)   
{
	FILE *fp;
	int i,b=0,a;
    fp=fopen("F:\\新建文件夹\\业务.txt","ab+");
	if(fp==0)
	{
		printf("无法打开！\n");
		exit(0);
	}
	
	
    printf("请输入所需登记的人数\n");
	scanf("%d",&a);
	
	
	for (i=b;i<b+a;i++)
	{
		printf("请输入：  姓名 路线 费用 号码 身份证\n");
		scanf("%s%s%d%d%d",z[i].name,z[i].road,&z[i].money,&z[i].number,&z[i].ID);
		fwrite(z,sizeof(z),1,fp);
	   }
	 
	
	b=a+b;
	fclose(fp);
	return b;

}


int createFile(thing z[])     /*业务登记*/
{
	
	int n,choice,b;
	printf("请选择：   1.输入信息       2.退出\n");
	scanf("%d",&choice);
	switch(choice) 
	{
	case 1:
	       Read(z);
	       n=b;
	       printf("登记成功！\n");
	       break;
	case 2:break; 
    }
	return n;
}


int Money(MoneyOver busin[])   /*业务结算登记*/
{
    int c=0;
	int i,n;
	FILE *fp;
	fp=fopen("F:\\新建文件夹\\结算.txt","ab+");
	if(fp==0)
	{
		printf("无法打开！\n");
		exit(0);
	}
	
	
	printf("请输入所需登记的人数\n");
	scanf("%d",&n);
	
	for (i=c;i<n+c;i++)
	{
		printf("请输入:姓名 应缴费用 实缴费用 身份证号\n");
		scanf("%s%d%d%d",busin[i].name,&busin[i].ShouldMoney,&busin[i].TureMoney,&busin[i].ID);
		fwrite(busin,sizeof(busin),1,fp);
	}
	c=n+c;
	fclose(fp);
	return c; 

}
int BusinessMoney(MoneyOver busin[])     
{
	
	int n,choice,c;

	printf("请选择：   1.输入信息       2.退出\n");
	scanf("%d",&choice);
	switch(choice) 
	{
	case 1:
	       Money(busin);
	       n=c;
	       printf("登记成功！\n");
	       break;
	case 2:break; 
    }
	
	
	
	return n;
}





void thingmanage()           /*业务管理*/
{
	
    int choice;
	 do{
    	printf("         -----------------------业务管理-------------------------\n");
		menuManage();
			printf("选择您的入口:\n");
	scanf("%d",&choice);
	switch (choice)
	{
	case 1:printf("          -----------------------业务登记-------------------------\n");
	       createFile(z);
		   
			   break;
	case 2:printf("          -----------------------确认出游-------------------------\n");
			   break;
	case 3:	printf("         -----------------------业务结算-------------------------\n");
	        BusinessMoney (busin);
		    
            break;
	case 0:
			break;
}  
	}while(choice>=1&&choice<=5);
	} 

void OverAll(MoneyOver busin[])    //业务结算汇总
{
	FILE *fp;
    int i=0;
	fp=fopen("F:\\新建文件夹\\结算.txt","ab+");
	if(fp==0)
	{
		printf("无法打开！\n");
		exit(1);
	}
    fread(&busin[i],sizeof(busin),1,fp);
	
	while(!feof(fp))
	{
		i++;
		fread(&busin[i],sizeof(busin),1,fp);
	}
    printf("姓名 应缴费用 实缴费用 身份证号\n");
	for(i=0;i<10;i++)
    {

	 	printf("%s\t%d\t%d\t%d\t\n",busin[i].name,busin[i].ShouldMoney,busin[i].TureMoney,busin[i].ID);
    }
    fclose(fp); 
}

void ThingAll(thing z[])//登记业务汇总
{
	FILE *fp;
    int i=0;
	fp=fopen("F:\\新建文件夹\\业务.txt","ab+");
	if(fp==0)
	{
		printf("无法打开！\n");
		exit(1);
	}
    fread(&z[i],sizeof(z),1,fp);
	
	while(!feof(fp))
	{
		i++;
		fread(&z[i],sizeof(z),1,fp);
	}
    printf("编号    姓名    路线    号码    费用    身份证号\n");
	for(i=0;i<10;i++)
    {

	 printf("%d\t%s\t%s\t%d\t%d\t%d\t\n",i,z[i].name,z[i].road,z[i].number,z[i].money,z[i].ID); 
    }
    fclose(fp); 
}

void Summarize()          /*统计分析*/
{
	 int choice;
	 do{
    	printf("         -----------------------统计分析-------------------------\n");
		menuCount();
			printf("选择您的入口:\n");
	scanf("%d",&choice);
	switch (choice)
	{
	case 1:printf("          -----------------------业务登记汇总表-------------------------\n");
	       ThingAll(z);
		   
			   break;
	case 2:printf("          -----------------------确认出游汇总表-------------------------\n");
			   break;
	case 3:	printf("         -----------------------业务结算汇总表-------------------------\n");
	        OverAll(busin);
			break;
	case 0: 
			break;
   }  
	}while(choice>=1&&choice<=3);
} 


int runmain(int n,int choice)
{
   	
	   switch(choice)
	{
	case 1:printHead();break;
	case 2:thingmanage();break;
	case 3:messageSearch();break;
	case 4:Summarize();break;
	case 5:break;
	}
	
return n;
}

int main()
{    
  int choice,n,i;
  char key[10];	                   
	     printf("                        #欢迎进入旅游管理系统#\n");
	   	for(i=1;i>0;i++) 
		{
			
					if(i==1)
	      	         
					  {
					    printf("#请输入登陆密码:\n");
	              	 
	              }
	             
	
	
	
	    for(i=0;i<10;i++)
		{
		key[i]=getch();
		if(key[i]=='\r')
		break;
		printf("*");
    	} 
	    key[i]='\0';
		printf("\n") ;
    	
				 
				 
		            
		  if(strcmp(key,"2071")==0)
	  
	      {
		  printf("登录成功！\n"); 
		   do {
		   menu();
	       printf("请选择您的入口:\n");
	       scanf("%d",&choice);
	           if(choice>=0&&choice<=5)
		           {
					      n=runmain(n,choice);
					  }
					   else
		          
				    printf("输入错误,请重新选择!\n");
              
           }while(choice);
          
		    }
		     else
           {
           	printf("\a#密码错误！请重新输入登陆密码:\n");
	      	        
		   }

        }


	return 0;
}
