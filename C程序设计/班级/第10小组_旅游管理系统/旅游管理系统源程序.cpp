#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<conio.h>

void menu()
{   printf("                 ****************************************\n");  
	printf("                 **             1.������Ϣ             **\n");
    printf("                 *****          2.ҵ�����          *****\n");
	printf("                 *******        3.��Ϣ��ѯ        *******\n");
	printf("                 *****          4.ͳ�Ʒ���          *****\n");
	printf("                 **             5.  �˳�               **\n");
	printf("                 ****************************************\n");
}
void menuBase()
{
    printf("                        ******1.��������Ϣ  ******\n");
    printf("                        ******2. ��·��Ϣ   ******\n");
    printf("                        ******3. Ա����Ϣ   ******\n");
    printf("                        ******0.�����ϲ�˵�******\n");
}

void menuManage()
{
    printf("                       ******1. ҵ��Ǽ�   ******\n");
    printf("                       ******2. ȷ�ϳ���   ******\n");
    printf("                       ******3. ҵ�����   ******\n");
    printf("                       ******0.�����ϲ�˵�******\n");
}
void menuSearch()
{
	printf("                      ******1.��·��Ϣ��ѯ******\n");
	printf("                      ******2.��Ա��Ϣ��ѯ******\n");
	printf("                      ******3.ҵ��Ǽǲ�ѯ******\n");
	printf("                      ******4.ȷ�ϳ��β�ѯ******\n");
	printf("                      ******5.ҵ������ѯ******\n");
	printf("                      ******0.�����ϲ�˵�******\n");
}
void menuCount()
{
	printf("                      ******1.�Ǽ�ҵ����ܱ�******\n");
	printf("                      ******2.ȷ�ϳ��λ��ܱ�******\n");
	printf("                      ******3.ҵ�������ܱ�******\n");
	printf("                      ******4. �ڼ����ͳ�� ******\n");
	printf("                      ******0. �����ϲ�˵� ******\n");
}



void yes()
{
		FILE *fp;
	char ch;
	fp=fopen("F:\\�½��ļ���\\��������Ϣ.txt","r");
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
	fp=fopen("F:\\�½��ļ���\\��·��Ϣ.txt","r");
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
	fp=fopen("F:\\�½��ļ���\\Ա����Ϣ.txt","r");
    if(fp==0)
{
	printf("�ļ�����\n");
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
	printf("         ------------------------������Ϣ-----------------------\n");
	menuBase();
	printf("ѡ���������:\n");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1:printf("         ------------------------��������Ϣ-----------------------\n");
		       yes();
		       break;
		case 2:printf("         ------------------------��·��Ϣ-----------------------\n");
		       no();
		       break;
		case 3:printf("         ------------------------Ա����Ϣ-----------------------\n");
		       hi();
		       break;
		case 0:break;
		 	}
		 	}while(choice>=1&&choice<=3) ;


}


 struct MessageRoad /*��·��Ϣ*/
{
	char name[10];
	char time[10];
	char way[20];
	int money;
};
typedef struct MessageRoad MessageRoad;
MessageRoad s[3]={{"�Ϻ�","����","��ʿ",1000},{"����","����","��ʿ",200},{"��","����","��ʿ",500}}; 



void SearchRoad(MessageRoad)/*��·��Ϣ��ѯ*/
{
	int choice;

	
	
		do{	
			printf("                  1.�Ϻ� 2.���� 3.�� 0.�����ϼ��˵�\n");
			printf ("��ѡ�����:\n");
			scanf ("%d",&choice);
			if(choice<=3)
			switch(choice)
		{
		case 1: printf("     ----------------------------------------------------------------------\n");
			    printf("                   *�ص�    :    %s*\n                   *����ʱ��: %s*\n                   *������ʽ: %s*\n                   *����    :    %d*\n",s[0].name,s[0].time,s[0].way,s[0].money);
			    printf("     ----------------------------------------------------------------------\n");
				break;
        case 2: printf("     ----------------------------------------------------------------------\n");
			    printf("                   *�ص�    :    %s*\n                   *����ʱ��: %s*\n                   *������ʽ: %s*\n                   *����    :    %d*\n",s[1].name,s[1].time,s[1].way,s[1].money);
			    printf("     ----------------------------------------------------------------------\n");
				break; 
		case 3: printf("     ----------------------------------------------------------------------\n");
			    printf("                   *�ص�    :    %s*\n                   *����ʱ��: %s*\n                   *������ʽ: %s*\n                   *����    :    %d*\n",s[2].name,s[2].time,s[2].way,s[2].money);
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

struct ManMessage /*��Ա��Ϣ��ѯ*/
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
	printf("�����������ѯ�����֤�ţ�\n");
	scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		if (f[i].IDcard==n)
		{
			printf("������%s\n�Ա�%s\n��ͥסַ��%s\n�绰���룺%d\n���֤�ţ�%d\n",f[i].name,f[i].sex,f[i].adress,f[i].phonenumber,f[i].IDcard);
		}
	}
	
}


struct thing/*ҵ����Ϣ*/
{
	char name[10];
	char road[20];
	int money;
	int number;
	int ID;
};
typedef struct thing thing;
thing z[10]={0} ;

int readFile(thing z[])  /*ҵ���ѯ*/
{
    FILE *fp;
	int i=0,n;
	fp=fopen("F:\\�½��ļ���\\ҵ��.txt","ab+");
	if(fp==0)
	{
		printf("�޷��򿪣�\n");
		return 0;
	}
    fread(&z[i],sizeof(z),1,fp);
	while(!feof(fp))
	{
		i++;
		fread(&z[i],sizeof(z),1,fp);
	}
	 printf("�����������ѯ�����֤�ţ�\n");
	scanf("%d",&n);
	for(i=0;i<100;i++)
	{
		
		if (z[i].ID==n)
		{   
		    printf("���    ����    ·��    ����    ����    ���֤��\n");
		    printf("%d\t%s\t%s\t%d\t%d\t%d\t\n",i,z[i].name,z[i].road,z[i].number,z[i].money,z[i].ID); 
			break; 
		}
		 if(i=100)
	    {
		printf("��Ϣ������\n");
     	}
	}

	fclose(fp);
    return 0;
}

struct MoneyOver      /*ҵ�����*/
{
	char name[20];
	int ShouldMoney;
	int TureMoney;
	int ID;
};
typedef MoneyOver MoneyOver;
MoneyOver busin[10];


void MessageMoney (MoneyOver busin[])/*ҵ������ѯ*/
{
	int i=0,n;
	FILE *fp;
	fp=fopen("F:\\�½��ļ���\\����.txt","ab+");
	if(fp==0)
	{
		printf("�޷��򿪣�\n");
		exit(1);
	}
    fread(&busin[i],sizeof(busin),1,fp);
	while(!feof(fp))
	{
		i++;
		fread(&busin[i],sizeof(busin),1,fp);
	}
	printf("�����������ѯ�����֤�ţ�\n");
	scanf("%d",&n);
	for(i=0;i<100;i++)
	{
		if (busin[i].ID==n)
		{   
		    printf("���� Ӧ������ ʵ�ɷ��� ���֤��\n");
		   
			printf("%s\t%d\t%d\t%d\t\n",busin[i].name,busin[i].ShouldMoney,busin[i].TureMoney,busin[i].ID);
			break;
		}
        if(i=100)
    	{
		printf("���벻����\n");
	    }

	}
	fclose(fp) ;
}


void messageSearch()        /*��Ϣ��ѯ*/
{
	int choice;
     

	do{
		 printf("         -----------------------��Ϣ��ѯ-----------------------\n");
		menuSearch();
			printf("ѡ���������:\n");
	scanf("%d",&choice); 
	switch (choice)
	{
	case 1:printf("        --------------------��·��Ϣ��ѯ-----------------------\n");
	        SearchRoad(s[3]);
			   break;
	case 2:printf("       ---------------------��Ա��Ϣ��ѯ-----------------------\n");
	        ManFound(f[2]);
			   break;
	case 3:printf("       ---------------------ҵ��Ǽǲ�ѯ-----------------------\n");
	       readFile(z);
		   break;
	case 4:printf("       ---------------------ȷ�ϳ��β�ѯ-----------------------\n");
			break;
	case 5:printf("       ---------------------ҵ������ѯ-----------------------\n");
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
    fp=fopen("F:\\�½��ļ���\\ҵ��.txt","ab+");
	if(fp==0)
	{
		printf("�޷��򿪣�\n");
		exit(0);
	}
	
	
    printf("����������Ǽǵ�����\n");
	scanf("%d",&a);
	
	
	for (i=b;i<b+a;i++)
	{
		printf("�����룺  ���� ·�� ���� ���� ���֤\n");
		scanf("%s%s%d%d%d",z[i].name,z[i].road,&z[i].money,&z[i].number,&z[i].ID);
		fwrite(z,sizeof(z),1,fp);
	   }
	 
	
	b=a+b;
	fclose(fp);
	return b;

}


int createFile(thing z[])     /*ҵ��Ǽ�*/
{
	
	int n,choice,b;
	printf("��ѡ��   1.������Ϣ       2.�˳�\n");
	scanf("%d",&choice);
	switch(choice) 
	{
	case 1:
	       Read(z);
	       n=b;
	       printf("�Ǽǳɹ���\n");
	       break;
	case 2:break; 
    }
	return n;
}


int Money(MoneyOver busin[])   /*ҵ�����Ǽ�*/
{
    int c=0;
	int i,n;
	FILE *fp;
	fp=fopen("F:\\�½��ļ���\\����.txt","ab+");
	if(fp==0)
	{
		printf("�޷��򿪣�\n");
		exit(0);
	}
	
	
	printf("����������Ǽǵ�����\n");
	scanf("%d",&n);
	
	for (i=c;i<n+c;i++)
	{
		printf("������:���� Ӧ�ɷ��� ʵ�ɷ��� ���֤��\n");
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

	printf("��ѡ��   1.������Ϣ       2.�˳�\n");
	scanf("%d",&choice);
	switch(choice) 
	{
	case 1:
	       Money(busin);
	       n=c;
	       printf("�Ǽǳɹ���\n");
	       break;
	case 2:break; 
    }
	
	
	
	return n;
}





void thingmanage()           /*ҵ�����*/
{
	
    int choice;
	 do{
    	printf("         -----------------------ҵ�����-------------------------\n");
		menuManage();
			printf("ѡ���������:\n");
	scanf("%d",&choice);
	switch (choice)
	{
	case 1:printf("          -----------------------ҵ��Ǽ�-------------------------\n");
	       createFile(z);
		   
			   break;
	case 2:printf("          -----------------------ȷ�ϳ���-------------------------\n");
			   break;
	case 3:	printf("         -----------------------ҵ�����-------------------------\n");
	        BusinessMoney (busin);
		    
            break;
	case 0:
			break;
}  
	}while(choice>=1&&choice<=5);
	} 

void OverAll(MoneyOver busin[])    //ҵ��������
{
	FILE *fp;
    int i=0;
	fp=fopen("F:\\�½��ļ���\\����.txt","ab+");
	if(fp==0)
	{
		printf("�޷��򿪣�\n");
		exit(1);
	}
    fread(&busin[i],sizeof(busin),1,fp);
	
	while(!feof(fp))
	{
		i++;
		fread(&busin[i],sizeof(busin),1,fp);
	}
    printf("���� Ӧ�ɷ��� ʵ�ɷ��� ���֤��\n");
	for(i=0;i<10;i++)
    {

	 	printf("%s\t%d\t%d\t%d\t\n",busin[i].name,busin[i].ShouldMoney,busin[i].TureMoney,busin[i].ID);
    }
    fclose(fp); 
}

void ThingAll(thing z[])//�Ǽ�ҵ�����
{
	FILE *fp;
    int i=0;
	fp=fopen("F:\\�½��ļ���\\ҵ��.txt","ab+");
	if(fp==0)
	{
		printf("�޷��򿪣�\n");
		exit(1);
	}
    fread(&z[i],sizeof(z),1,fp);
	
	while(!feof(fp))
	{
		i++;
		fread(&z[i],sizeof(z),1,fp);
	}
    printf("���    ����    ·��    ����    ����    ���֤��\n");
	for(i=0;i<10;i++)
    {

	 printf("%d\t%s\t%s\t%d\t%d\t%d\t\n",i,z[i].name,z[i].road,z[i].number,z[i].money,z[i].ID); 
    }
    fclose(fp); 
}

void Summarize()          /*ͳ�Ʒ���*/
{
	 int choice;
	 do{
    	printf("         -----------------------ͳ�Ʒ���-------------------------\n");
		menuCount();
			printf("ѡ���������:\n");
	scanf("%d",&choice);
	switch (choice)
	{
	case 1:printf("          -----------------------ҵ��Ǽǻ��ܱ�-------------------------\n");
	       ThingAll(z);
		   
			   break;
	case 2:printf("          -----------------------ȷ�ϳ��λ��ܱ�-------------------------\n");
			   break;
	case 3:	printf("         -----------------------ҵ�������ܱ�-------------------------\n");
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
	     printf("                        #��ӭ�������ι���ϵͳ#\n");
	   	for(i=1;i>0;i++) 
		{
			
					if(i==1)
	      	         
					  {
					    printf("#�������½����:\n");
	              	 
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
		  printf("��¼�ɹ���\n"); 
		   do {
		   menu();
	       printf("��ѡ���������:\n");
	       scanf("%d",&choice);
	           if(choice>=0&&choice<=5)
		           {
					      n=runmain(n,choice);
					  }
					   else
		          
				    printf("�������,������ѡ��!\n");
              
           }while(choice);
          
		    }
		     else
           {
           	printf("\a#������������������½����:\n");
	      	        
		   }

        }


	return 0;
}
