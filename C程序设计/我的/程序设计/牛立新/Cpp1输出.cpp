#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct       //定义结构体 
{
	char type[20];   //消费类型
	float money;    //消费金额
	char place[20];  //消费地点
	int time;        //消费时间
}family;
family fam[80];

void showitems(family sum[],int n)//输出某月份的消费信息
{
	int i=0,month;
	FILE *fp;
	printf("请选择月份: ");
	scanf("%d",&month);
	getchar();
	printf("\t\t\t----------------\n");
	printf("\t\t\t种类     支出     地点       时间\n");

	printf("\t\t\t---------------\n");

    switch(month)
    {
		case 1:
		fp=fopen("D:\\Management_System\\一月支出信息.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\二月支出信息.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\三月支出信息.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\四月支出信息.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\五月支出信息.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\六月支出信息.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\七月支出信息.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\八月支出信息.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\九月支出信息.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\十月支出信息.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\十一月支出信息.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\十二月支出信息.txt","r");                                   
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
	   
	   