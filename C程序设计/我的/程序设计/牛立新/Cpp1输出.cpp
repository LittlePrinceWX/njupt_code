#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct       //����ṹ�� 
{
	char type[20];   //��������
	float money;    //���ѽ��
	char place[20];  //���ѵص�
	int time;        //����ʱ��
}family;
family fam[80];

void showitems(family sum[],int n)//���ĳ�·ݵ�������Ϣ
{
	int i=0,month;
	FILE *fp;
	printf("��ѡ���·�: ");
	scanf("%d",&month);
	getchar();
	printf("\t\t\t----------------\n");
	printf("\t\t\t����     ֧��     �ص�       ʱ��\n");

	printf("\t\t\t---------------\n");

    switch(month)
    {
		case 1:
		fp=fopen("D:\\Management_System\\һ��֧����Ϣ.txt","r");                                   
	    if(fp==0)
	    {
	    	printf("file error\n");
		    exit(1);
	    }
		fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		while(!feof(fp))
		{
		    printf("%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].money,sum[i].place,sum[i].time);
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		break;
		case 2:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
	    if(fp==0)
	    {
	    	printf("file error\n");
		    exit(1);
	    }
		fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		while(!feof(fp))
		{
		    printf("%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].money,sum[i].place,sum[i].time);
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		break;
		case 3:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
	    if(fp==0)
	    {
	    	printf("file error\n");
		    exit(1);
	    }
		fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		while(!feof(fp))
		{
		    printf("%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].money,sum[i].place,sum[i].time);
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		break;
		case 4:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
	    if(fp==0)
	    {
	    	printf("file error\n");
		    exit(1);
	    }
		fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		while(!feof(fp))
		{
		    printf("%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].money,sum[i].place,sum[i].time);
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		break;
		case 5:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
	    if(fp==0)
	    {
	    	printf("file error\n");
		    exit(1);
	    }
		fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		while(!feof(fp))
		{
		    printf("%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].money,sum[i].place,sum[i].time);
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		break;
		case 6:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
	    if(fp==0)
	    {
	    	printf("file error\n");
		    exit(1);
	    }
		fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		while(!feof(fp))
		{
		    printf("%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].money,sum[i].place,sum[i].time);
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		break;
		case 7:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
	    if(fp==0)
	    {
	    	printf("file error\n");
		    exit(1);
	    }
		fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		while(!feof(fp))
		{
		    printf("%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].money,sum[i].place,sum[i].time);
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		break;
		case 8:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
	    if(fp==0)
	    {
	    	printf("file error\n");
		    exit(1);
	    }
		fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		while(!feof(fp))
		{
		    printf("%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].money,sum[i].place,sum[i].time);
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		break;
		case 9:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
	    if(fp==0)
	    {
	    	printf("file error\n");
		    exit(1);
	    }
		fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		while(!feof(fp))
		{
		    printf("%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].money,sum[i].place,sum[i].time);
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		break;
		case 10:
		fp=fopen("D:\\Management_System\\ʮ��֧����Ϣ.txt","r");                                   
	    if(fp==0)
	    {
	    	printf("file error\n");
		    exit(1);
	    }
		fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		while(!feof(fp))
		{
		    printf("%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].money,sum[i].place,sum[i].time);
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		break;
		case 11:
		fp=fopen("D:\\Management_System\\ʮһ��֧����Ϣ.txt","r");                                   
	    if(fp==0)
	    {
	    	printf("file error\n");
		    exit(1);
	    }
		fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		while(!feof(fp))
		{
		    printf("%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].money,sum[i].place,sum[i].time);
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		break;
		case 12:
		fp=fopen("D:\\Management_System\\ʮ����֧����Ϣ.txt","r");                                   
	    if(fp==0)
	    {
	    	printf("file error\n");
		    exit(1);
	    }
		fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		while(!feof(fp))
		{
		    printf("%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].money,sum[i].place,sum[i].time);
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		break;
	}
}	

void Mode_2 ()
{
	int n=0;
	showitems(fam,n);
}

int main()
{
	Mode_2();
}
	   
	   