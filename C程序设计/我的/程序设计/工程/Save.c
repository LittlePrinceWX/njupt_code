#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include "Save.h"

family fam[80];


int Inputitmes(family sum[],int n)//����������Ϣ
{
	int i=0;
	char sign='y',x[10];
	while(sign!='n'&&sign!='N')
	{
		printf("\t\t\t����:");
		scanf("\t\t\t%s",sum[n+i].type);
		printf("\t\t\t֧���������㣩:");
		scanf("\t\t\t%f",&sum[n+i].Getsum);
		printf("\t\t\t�ص�:");
		scanf("\t\t\t%s",sum[n+i].place);
		printf("\t\t\tʱ��(0-31):");
		scanf("\t\t\t%d",&sum[n+i].time);
		if(sum[n+i].time<1||sum[n+i].time>31)
			return false;
		gets(x);
		printf("\t\t\t��Ҫ�ٴ�������(y\\n)");
		scanf("\t\t\t%c",&sign);
		i++;
	}
	return(n+i);
}



void Save (family sum[],int n)
{
	int month,i;
	FILE *fp;
	printf("�����뵱ǰ��Ϣ�����·ݣ�");
	scanf("%d",&month);
	getchar();
	switch(month)
	{
		case 1:

			fp=fopen("D:\\Management_System\\һ��֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");
			break;
		case 2:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 3:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 4:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 5:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 6:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 7:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 8:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 9:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 10:
			fp=fopen("D:\\Management_System\\ʮ��֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 11:
			fp=fopen("D:\\Management_System\\ʮһ��֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 12:
			fp=fopen("D:\\Management_System\\ʮ����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;		
	}
}


void Mode_1 ()
{
	int n=0;
	char c;
	printf("\t\t\t��������Ӧ���������\n");
	n=Inputitmes(fam,n);
	printf("\t\t\t��Ҫ����������y\\n�� :");
	getchar();
	scanf("%c",&c);
	if(c=='y'||c=='Y')
		Save(fam,n);
	printf("\t\t\t");
	system("pause");
}



