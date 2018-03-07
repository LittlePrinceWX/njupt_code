#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define PR printf
#define SC scanf

typedef struct customer{	   //�ͻ���Ϣ
	char name[20];			   //�ͻ�����
	int num;				      //��Ʊ��
	int level;				  //��λ�ȼ�
	customer *next;
}customer,*Lcustomer;

typedef struct airline{		//������Ϣ
	char end_addr[20];		//�����յ�
	char line_num[5];		   //�����
	char plant_num[8];		//�ɻ���
	int day;				       //��������
	int total;				    //��Ա
	int left;				    //ʣ��Ʊ��
	customer *booked;		    //�Ѷ��ͻ���Ϣ
	customer *wait;			//�ŶӵȺ�Ʊ��Ϣ
	airline *next;
}airline,*Lairline;

airline *L;					 //��������Ϣ����Ϊȫ�ֱ��������ٲ�������
Lairline search_line()		//������Ų��Һ���
{
	char a[5];
	airline *p ;
	p=L->next;
	PR("�����뺽���");
	SC("%s",a);
	for(;p;p=p->next)
		if(!strcmp(a,p->line_num)) break;
	return p;
}

Lairline search_plant()		//���ɻ��Ų��Һ���
{
	char a[8];
	airline *p;
	p=L->next;
	PR("������ɻ���");
	SC("%s",a);
	for(;p;p=p->next)
		if(!strcmp(a,p->plant_num)) break;
	return p;
}

Lairline search_day()		//���������ڲ��Һ���
{
	int a;
	airline *p;
	p=L->next;
	PR("�������������");
	SC("%d",&a);
	for(;p;p=p->next)
		if(a==p->day) break;
	return p;
}

Lairline search_addr()		//�������յ���Һ���
{
	char a[20];
	airline *p;
	p=L->next;
	PR("�����뺽���յ�");
	SC("%s",a);
	for(;p;p=p->next)
		if(!strcmp(a,p->end_addr)) break;
	return p;
}

void guide()			//���˵�����
{
	PR("**********************��ӭ���뺽����Ʊϵͳ**********************\n");
	PR("\t\t��ʾ���к���==>  1\n");
	PR("\t\t��ѯ������Ϣ==>  2\n");
	PR("\t\t��Ʊҵ��    ==>  3\n");
	PR("\t\t��Ʊҵ��    ==>  4\n");
	PR("\t\t����ϵͳ    ==>  5\n");
	PR("\t\t�˳�ϵͳ    ==>  0\n");
	PR("**************************************************************\n");
	PR("\t\t�����Ļ��Ϣ==>  9\n\n");
	PR("�밴����ָ������:\t");
}

void insert_line()		//�����º���
{
	airline *p,*q;
	int flag=1;
	for(;flag;)
	{
		q=(Lairline)malloc(sizeof(airline)); //Ϊ���������������һ���ڴ� 
		PR("�����뺽��ţ�");
		SC("%s",q->line_num);
		for(p=L;p->next;p=p->next)
			if(strcmp(p->next->line_num,q->line_num)>=0)
				break;
		if(p->next&&strcmp(p->next->line_num,q->line_num)==0)
		{
			PR("�����Ѵ��ڣ�����������\n");
			continue;
		}
		PR("������������ڣ�");
		SC("%d",&q->day);
		PR("������ɻ��ţ�");
		SC("%s",q->plant_num);
		PR("�������յ�վ��");
		SC("%s",q->end_addr);
		q->total=120;
		q->left=120;
		q->booked=NULL;
		q->wait=NULL;
		q->next=p->next;
		p->next=q;
		PR("���Ӻ���ɹ����Ƿ��������\n������1��\n���أ�0��");
		SC("%d",&flag);

	}
}

void print_customer(airline *p)		//��ʾ����ͻ���Ϣ
{
	customer *c;
	if(p->booked)
	{
		c=p->booked;
		PR("�Ѷ�Ʊ�ͻ���Ϣ\nƱ��\t/\t�ͻ�����\n");
		for(;c;c=c->next)
			PR("%5d\t/\t%s\n",c->num,c->name);
		PR("\n\n");
	}
	else
		PR("��ʱû�пͻ���Ʊ\n\n");
	if(p->wait)
	{
		c=p->wait;
		PR("�ŶӶ�Ʊ�ͻ���Ϣ\nƱ��\t/\t�ͻ�����\n");
		for(;c;c=c->next)
			PR("%5d\t/\t%s\n",c->num,c->name);
		PR("\n\n");
	}
	else
		PR("��ʱû�пͻ��ŶӶ�Ʊ\n\n");
}

void admin()				//�������Ա����ϵͳ
{
	int i,flag,tag;
	char a[20];
	airline *p;
	PR("���������Ա���룺");
	for(i=0;i<3;i++)
	{
		SC("%s",a);
		if(strcmp(a,"1129"))
		{
			PR("\t\t======�������======\n\n");
			i++;
		}
		else break;
	}
	if(i==3)
	{	guide(); return ;	}
	for(tag=1;tag;)
	{
		PR("��ѡ�����\n��ѯ���ඩƱ�����1��\n�����º��ࣨ2��\n");
		SC("%d",&flag);
		if(flag==1)
		{
			p=search_line();
			if(p)
				print_customer(p);
			else
				PR("û���ҵ��ú���\n");
		}
		else if(flag==2)
			insert_line();
		else
			PR("���������밴��ʾ����\n");
		PR("��ѡ�����\n������1��\n�˻����˵���0��\n");
		SC("%d",&tag);
	}
	guide();
}
void book()				//��Ʊϵͳ
{
	int i;
	int flag=0;
	airline *p;
	customer *cst,*c;
	PR("�������ѯ����ķ�ʽ��\n");	
	PR("�����--->1\n");
	PR("�յ�վ--->2\n");
	PR("��������->3\n");
	for(;!flag;)
	{
		SC("%d",&i);
		switch(i)
		{
		case 1: p=search_line();flag=1;break;
		case 2: p=search_addr();flag=1;break;
		case 3: p=search_day();flag=1;break;
		default:PR("��������,����������\n");break;
		}
	}
	if(p)
	{

		PR("�յ�վ                  �����    ����    ��������   ��Ʊ��\n");
		PR("%-20s%10s%10s%8d%8d\n",p->end_addr,p->line_num,p->plant_num,p->day,p->left);
		cst=(customer *)malloc(sizeof(customer));
		PR("�����붩Ʊ������");
		SC("%d",&cst->num);
		PR("�������λ�ȼ���1/2/3��");
		SC("%d",&cst->level);
		PR("��������������");
		SC("%s",cst->name);
		if(cst->num<=p->left)
		{
			cst->next=p->booked;
			p->booked=cst;
			p->left=p->left-cst->num;
			PR("��Ʊ�ɹ�����λ��Ϊ%d~%d\n",p->total-p->left-cst->num+1,p->total-p->left);
		}
		else
		{
			PR("��Ʊ���㣬�Ƿ��ŶӵȺ�\n�ǣ�1��\n��0��\n");
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
		PR("û�иú���\n");
	guide();
}

void waited(airline *p)			//�ŶӶ�Ʊϵͳ
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
			PR("%s���������ŶӶ�%d��Ʊ������Ʊ���Ƿ�\n�ǣ�1��\n��0��\n",q->next->name,q->next->num);
			SC("%d",&flag);
			if(flag)
			{
				q0=q->next;
				q->next=q->next->next;
				q0->next=p->booked;
				p->booked=q0;
				p->left=p->left-q0->num;
				PR("�ŶӶ�Ʊ�ɹ�\n\n");
			}
			else
				q=q->next;
		}
		else
			q=q->next;
	}
	p->wait=h->next;
}
void refund()			//��Ʊϵͳ
{
	int flag;
	char a[20];
	airline *p;
	customer *c,*c1;
	p=search_line();
	c=p->booked;
	if(!p)
	{	
		PR("û�иú���\n\n");
		guide();
		return;
	}
	PR("��������������");
	SC("%s",a);
	if(!p->booked->name)
	{
		PR("�Բ���û���ҵ�������Ϣ\n\n");
		guide();
		return ;
	}
	if(!strcmp(a,p->booked->name))
	{
		PR("��Ʊ��Ϣ\n����/�յ�վ/Ʊ��\n%s/%s/%d\n",p->booked->name,p->end_addr,p->booked->num);
		PR("ȷ��Ҫ��Ʊ������\n�ǣ�1��\n��0)\n");
		scanf("%d",&flag);
		if(flag)
		{
			p->booked=p->booked->next;
			p->left=p->left+c->num;
			free(c);
			PR("��Ʊ�ɹ�\n\n");
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
			PR("�Բ���û���ҵ�������Ϣ\n\n");
			guide();
			return ;
		}
		else
		{
			PR("��Ʊ��Ϣ\n����/�յ�վ/Ʊ��\n%s/%s/%d\n",c->next->name,p->end_addr,c->next->num);
			PR("ȷ��Ҫ��Ʊ������\n�ǣ�1��\n��0)\n");
			scanf("%d",&flag);
			if(flag)
			{
				c1=c->next;
				c->next=c->next->next;
				p->left=p->left+c1->num;
				free(c1);
				PR("��Ʊ�ɹ�\n\n");
				waited(p);
				guide();
			}
		}
	}

}

void search()			//�����ѯϵͳ
{
	int i;
	int flag=0;
	airline *p;
	PR("�������ѯ����ķ�ʽ��\n");
	PR("�����---->1\n");
	PR("�ɻ���---->2\n");
	PR("��������-->3\n");
	PR("�����յ�-->4\n");
	SC("%d",&i);
	for(;!flag;)
		switch(i)
		{
		case 1: p=search_line();flag=1;break;
		case 2: p=search_plant();flag=1;break;
		case 3: p=search_day();flag=1;break;
		case 4: p=search_addr();flag-=1;break;
		default:PR("��������,����������\n");break;
		}
	if(p)
	{
		PR("�յ�վ                 �����   �ɻ���   ��������   ��Ʊ��\n");
		PR("%-20s%10s%10s%8d%8d\n",p->end_addr,p->line_num,p->plant_num,p->day,p->left);
		PR("�Ƿ�Ʊ��ȷ���밴1��");
		SC("%d",&i);
		if(i==1)
				book();
	}
	else 
		PR("û�иú���\n");
}

void InitLine()				//��ʼ��������Ϣ
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
	strcpy(p->end_addr,"���");
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
	strcpy(p->end_addr,"����");
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
	strcpy(p->end_addr,"�Ϻ�");
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
	strcpy(p->end_addr,"����");
	strcpy(p->line_num,"CA12");
	strcpy(p->plant_num," 2586934");
	p->day=1;
	p->left=120;
	p->total=120;
	p->next=q->next;
	q->next=p;
} 

void printline()			//��ʾ���к�����Ϣ
{
	int flag;
	airline *p;
	p=L->next;
	PR("�յ�վ                  �����   ����    ��������   ��Ʊ��\n");
	for(;p;p=p->next)
	{
		PR("%-20s%10s%10s%8d%8d\n",p->end_addr,p->line_num,p->plant_num,p->day,p->left);

	}
	PR("��1���붩Ʊϵͳ����0�������˵�\n");
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
		PR("���ļ�ʧ��");
		exit(0); 
	}
	fwrite(L,sizeof(airline),120,fp);
	fclose(fp);
}

int main()				//������
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
