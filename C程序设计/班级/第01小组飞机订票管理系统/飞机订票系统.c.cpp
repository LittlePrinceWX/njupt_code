#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define PR printf
#define SC scanf

typedef struct customer{	   //客户信息
	char name[20];			   //客户姓名
	int num;				      //订票量
	int level;				  //舱位等级
	customer *next;
}customer,*Lcustomer;

typedef struct airline{		//航线信息
	char end_addr[20];		//航线终点
	char line_num[5];		   //航班号
	char plant_num[8];		//飞机号
	int day;				       //飞行日期
	int total;				    //定员
	int left;				    //剩余票数
	customer *booked;		    //已定客户信息
	customer *wait;			//排队等候订票信息
	airline *next;
}airline,*Lairline;

airline *L;					 //将航班信息定义为全局变量，减少参数传递
Lairline search_line()		//按航班号查找航班
{
	char a[5];
	airline *p ;
	p=L->next;
	PR("请输入航班号");
	SC("%s",a);
	for(;p;p=p->next)
		if(!strcmp(a,p->line_num)) break;
	return p;
}

Lairline search_plant()		//按飞机号查找航班
{
	char a[8];
	airline *p;
	p=L->next;
	PR("请输入飞机号");
	SC("%s",a);
	for(;p;p=p->next)
		if(!strcmp(a,p->plant_num)) break;
	return p;
}

Lairline search_day()		//按飞行日期查找航班
{
	int a;
	airline *p;
	p=L->next;
	PR("请输入飞行日期");
	SC("%d",&a);
	for(;p;p=p->next)
		if(a==p->day) break;
	return p;
}

Lairline search_addr()		//按航班终点查找航班
{
	char a[20];
	airline *p;
	p=L->next;
	PR("请输入航班终点");
	SC("%s",a);
	for(;p;p=p->next)
		if(!strcmp(a,p->end_addr)) break;
	return p;
}

void guide()			//主菜单界面
{
	PR("**********************欢迎进入航空售票系统**********************\n");
	PR("\t\t显示所有航线==>  1\n");
	PR("\t\t查询航线信息==>  2\n");
	PR("\t\t订票业务    ==>  3\n");
	PR("\t\t退票业务    ==>  4\n");
	PR("\t\t管理系统    ==>  5\n");
	PR("\t\t退出系统    ==>  0\n");
	PR("**************************************************************\n");
	PR("\t\t清除屏幕信息==>  9\n\n");
	PR("请按上面指引操作:\t");
}

void insert_line()		//插入新航班
{
	airline *p,*q;
	int flag=1;
	for(;flag;)
	{
		q=(Lairline)malloc(sizeof(airline)); //为待插入的数据申请一块内存 
		PR("请输入航班号：");
		SC("%s",q->line_num);
		for(p=L;p->next;p=p->next)
			if(strcmp(p->next->line_num,q->line_num)>=0)
				break;
		if(p->next&&strcmp(p->next->line_num,q->line_num)==0)
		{
			PR("航班已存在，请重新输入\n");
			continue;
		}
		PR("请输入飞行日期：");
		SC("%d",&q->day);
		PR("请输入飞机号：");
		SC("%s",q->plant_num);
		PR("请输入终点站：");
		SC("%s",q->end_addr);
		q->total=120;
		q->left=120;
		q->booked=NULL;
		q->wait=NULL;
		q->next=p->next;
		p->next=q;
		PR("增加航班成功，是否继续增加\n继续（1）\n返回（0）");
		SC("%d",&flag);

	}
}

void print_customer(airline *p)		//显示航班客户信息
{
	customer *c;
	if(p->booked)
	{
		c=p->booked;
		PR("已定票客户信息\n票数\t/\t客户姓名\n");
		for(;c;c=c->next)
			PR("%5d\t/\t%s\n",c->num,c->name);
		PR("\n\n");
	}
	else
		PR("暂时没有客户订票\n\n");
	if(p->wait)
	{
		c=p->wait;
		PR("排队订票客户信息\n票数\t/\t客户姓名\n");
		for(;c;c=c->next)
			PR("%5d\t/\t%s\n",c->num,c->name);
		PR("\n\n");
	}
	else
		PR("暂时没有客户排队订票\n\n");
}

void admin()				//进入管理员操作系统
{
	int i,flag,tag;
	char a[20];
	airline *p;
	PR("请输入管理员密码：");
	for(i=0;i<3;i++)
	{
		SC("%s",a);
		if(strcmp(a,"1129"))
		{
			PR("\t\t======密码错误======\n\n");
			i++;
		}
		else break;
	}
	if(i==3)
	{	guide(); return ;	}
	for(tag=1;tag;)
	{
		PR("请选择操作\n查询航班订票情况（1）\n增加新航班（2）\n");
		SC("%d",&flag);
		if(flag==1)
		{
			p=search_line();
			if(p)
				print_customer(p);
			else
				PR("没有找到该航班\n");
		}
		else if(flag==2)
			insert_line();
		else
			PR("操作错误，请按提示操作\n");
		PR("请选择操作\n继续（1）\n退回主菜单（0）\n");
		SC("%d",&tag);
	}
	guide();
}
void book()				//订票系统
{
	int i;
	int flag=0;
	airline *p;
	customer *cst,*c;
	PR("请输入查询航班的方式：\n");	
	PR("航班号--->1\n");
	PR("终点站--->2\n");
	PR("飞行日期->3\n");
	for(;!flag;)
	{
		SC("%d",&i);
		switch(i)
		{
		case 1: p=search_line();flag=1;break;
		case 2: p=search_addr();flag=1;break;
		case 3: p=search_day();flag=1;break;
		default:PR("操作错误,请重新输入\n");break;
		}
	}
	if(p)
	{

		PR("终点站                  航班号    机型    飞行日期   余票量\n");
		PR("%-20s%10s%10s%8d%8d\n",p->end_addr,p->line_num,p->plant_num,p->day,p->left);
		cst=(customer *)malloc(sizeof(customer));
		PR("请输入订票数量：");
		SC("%d",&cst->num);
		PR("请输入舱位等级（1/2/3）");
		SC("%d",&cst->level);
		PR("请输入您的名字");
		SC("%s",cst->name);
		if(cst->num<=p->left)
		{
			cst->next=p->booked;
			p->booked=cst;
			p->left=p->left-cst->num;
			PR("订票成功，座位号为%d~%d\n",p->total-p->left-cst->num+1,p->total-p->left);
		}
		else
		{
			PR("余票不足，是否排队等候？\n是（1）\n否（0）\n");
			SC("%d",&flag);
			if(flag)
			{
				if(!p->wait)
				{
					cst->next=p->wait;
					p->wait=cst;
				}
				else
				{
					c=p->wait;
					for(;c->next;c=c->next);
					cst->next=c->next;
					c->next=cst;
				}
			}
		}
	}
	else 
		PR("没有该航班\n");
	guide();
}

void waited(airline *p)			//排队订票系统
{
	int flag;
	customer *q,*q0,*h;
	if(!p->wait) return;
	q=(customer *)malloc(sizeof(customer));
	q->level=0;
	q->num=123;
	strcpy(q->name,"00000");
	q->next=p->wait;
	h=q;
	for(;p->left>0&&q->next;)
	{
		if(q->next->num<p->left)
		{
			PR("%s，您正在排队定%d张票，现有票，是否定\n是（1）\n否（0）\n",q->next->name,q->next->num);
			SC("%d",&flag);
			if(flag)
			{
				q0=q->next;
				q->next=q->next->next;
				q0->next=p->booked;
				p->booked=q0;
				p->left=p->left-q0->num;
				PR("排队订票成功\n\n");
			}
			else
				q=q->next;
		}
		else
			q=q->next;
	}
	p->wait=h->next;
}
void refund()			//退票系统
{
	int flag;
	char a[20];
	airline *p;
	customer *c,*c1;
	p=search_line();
	c=p->booked;
	if(!p)
	{	
		PR("没有该航班\n\n");
		guide();
		return;
	}
	PR("请输入您的姓名");
	SC("%s",a);
	if(!p->booked->name)
	{
		PR("对不起，没有找到您的信息\n\n");
		guide();
		return ;
	}
	if(!strcmp(a,p->booked->name))
	{
		PR("退票信息\n姓名/终点站/票数\n%s/%s/%d\n",p->booked->name,p->end_addr,p->booked->num);
		PR("确认要退票？（）\n是（1）\n否（0)\n");
		scanf("%d",&flag);
		if(flag)
		{
			p->booked=p->booked->next;
			p->left=p->left+c->num;
			free(c);
			PR("退票成功\n\n");
			waited(p);
			guide();
		}
	}
	else
	{
		for(;c->next;c=c->next)
			if(!strcmp(a,c->next->name))
				break;
		if(!c->next)
		{
			PR("对不起，没有找到您的信息\n\n");
			guide();
			return ;
		}
		else
		{
			PR("退票信息\n姓名/终点站/票数\n%s/%s/%d\n",c->next->name,p->end_addr,c->next->num);
			PR("确认要退票？（）\n是（1）\n否（0)\n");
			scanf("%d",&flag);
			if(flag)
			{
				c1=c->next;
				c->next=c->next->next;
				p->left=p->left+c1->num;
				free(c1);
				PR("退票成功\n\n");
				waited(p);
				guide();
			}
		}
	}

}

void search()			//航班查询系统
{
	int i;
	int flag=0;
	airline *p;
	PR("请输入查询航班的方式：\n");
	PR("航班号---->1\n");
	PR("飞机号---->2\n");
	PR("飞行日期-->3\n");
	PR("航班终点-->4\n");
	SC("%d",&i);
	for(;!flag;)
		switch(i)
		{
		case 1: p=search_line();flag=1;break;
		case 2: p=search_plant();flag=1;break;
		case 3: p=search_day();flag=1;break;
		case 4: p=search_addr();flag-=1;break;
		default:PR("操作错误,请重新输入\n");break;
		}
	if(p)
	{
		PR("终点站                 航班号   飞机号   飞行日期   余票量\n");
		PR("%-20s%10s%10s%8d%8d\n",p->end_addr,p->line_num,p->plant_num,p->day,p->left);
		PR("是否订票（确定请按1）");
		SC("%d",&i);
		if(i==1)
				book();
	}
	else 
		PR("没有该航班\n");
}

void InitLine()				//初始化航线信息
{
	airline *p,*q;
	L=(airline *)malloc(sizeof(airline));
	L->booked=NULL;
	L->wait=NULL;
	L->next=NULL;
	strcpy(L->end_addr,"00000000");
	strcpy(L->line_num,"000");
	strcpy(L->plant_num,"0000000");
	L->day=L->left=L->total=0;
	q=L;
    p=(airline *)malloc(sizeof(airline));
	p->booked=NULL;
	p->wait=NULL;
	strcpy(p->end_addr,"天津");
	strcpy(p->line_num,"MU21");
	strcpy(p->plant_num,"2351678");
	p->day=4;
	p->left=120;
	p->total=120;
	p->next=q->next;
	q->next=p;

	p=(airline *)malloc(sizeof(airline));
	p->booked=NULL;
	p->wait=NULL;
	strcpy(p->end_addr,"广州");
	strcpy(p->line_num,"ZH23");
	strcpy(p->plant_num,"4558934");
	p->day=3;
	p->left=120;
	p->total=120;
	p->next=q->next;
	q->next=p;

	p=(airline *)malloc(sizeof(airline));
	p->booked=NULL;
	p->wait=NULL;
	strcpy(p->end_addr,"上海");
	strcpy(p->line_num,"CA32");
	strcpy(p->plant_num,"2432422");
	p->day=2;
	p->left=120;
	p->total=120;
	p->next=q->next;
	q->next=p;

   p=(airline *)malloc(sizeof(airline));
	p->booked=NULL;
	p->wait=NULL;
	strcpy(p->end_addr,"北京");
	strcpy(p->line_num,"CA12");
	strcpy(p->plant_num," 2586934");
	p->day=1;
	p->left=120;
	p->total=120;
	p->next=q->next;
	q->next=p;
} 

void printline()			//显示所有航班信息
{
	int flag;
	airline *p;
	p=L->next;
	PR("终点站                  航班号   机型    飞行日期   余票量\n");
	for(;p;p=p->next)
	{
		PR("%-20s%10s%10s%8d%8d\n",p->end_addr,p->line_num,p->plant_num,p->day,p->left);

	}
	PR("按1进入订票系统，按0返回主菜单\n");
	SC("%d",&flag);
	if(flag)
		book();
	else guide();

}

void saveFile() 
{
	FILE *fp;
	if((fp=fopen("C:\\airline.dat","wb"))==NULL)
	{
		PR("打开文件失败");
		exit(0); 
	}
	fwrite(L,sizeof(airline),120,fp);
	fclose(fp);
}

int main()				//主函数
{
	int flag=1;
	guide();
	InitLine();	
	do
	{		
		switch(getchar())
		{
		case '1':printline();break;
		case '2':search();break;
		case '3':book();break;
		case '4':refund();break;
		case '5':admin();break;
		case '9':system("cls");guide();break;
		case '0':flag=0;saveFile();break;
		}
	}while(flag);
}
