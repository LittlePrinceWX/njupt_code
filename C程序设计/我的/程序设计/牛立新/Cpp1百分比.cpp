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


void Analyseitems(family sum[],int n)//求各种消费类型的金额占总金额的百分比并求收支比例
{
	float total=0,a=0,income;
	int i=0,j=0,month;
	FILE*fp;
	printf("请选择月份：");
	scanf("%d",&month);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("消费总金额为%f",total);

		fp=fopen("D:\\Management_System\\一月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t项目  %-8s占总比  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("消费总金额为%f",total);
		fclose(fp);
		printf("请输入本月收入:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t本月收支比为%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("消费总金额为%f",total);


		fp=fopen("D:\\Management_System\\二月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t项目  %-8s占总比  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("消费总金额为%f",total);
		fclose(fp);
		printf("请输入本月收入:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t本月收支比为%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("消费总金额为%f",total);


		fp=fopen("D:\\Management_System\\三月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t项目  %-8s占总比  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("消费总金额为%f",total);
		fclose(fp);
		printf("请输入本月收入:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t本月收支比为%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("消费总金额为%f",total);

		fp=fopen("D:\\Management_System\\四月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t项目  %-8s占总比  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("消费总金额为%f",total);
		fclose(fp);
		printf("请输入本月收入:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t本月收支比为%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("消费总金额为%f",total);

		fp=fopen("D:\\Management_System\\五月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t项目  %-8s占总比  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("消费总金额为%f",total);
		fclose(fp);
		printf("请输入本月收入:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t本月收支比为%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("消费总金额为%f",total);

		fp=fopen("D:\\Management_System\\六月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t项目  %-8s占总比  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("消费总金额为%f",total);
		fclose(fp);
		printf("请输入本月收入:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t本月收支比为%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("消费总金额为%f",total);

		fp=fopen("D:\\Management_System\\七月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t项目  %-8s占总比  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("消费总金额为%f",total);
		fclose(fp);
		printf("请输入本月收入:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t本月收支比为%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("消费总金额为%f",total);

		fp=fopen("D:\\Management_System\\八月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t项目  %-8s占总比  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("消费总金额为%f",total);
		fclose(fp);
		printf("请输入本月收入:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t本月收支比为%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("消费总金额为%f",total);

		fp=fopen("D:\\Management_System\\九月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t项目  %-8s占总比  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("消费总金额为%f",total);
		fclose(fp);
		printf("请输入本月收入:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t本月收支比为%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("消费总金额为%f",total);

		fp=fopen("D:\\Management_System\\十月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t项目  %-8s占总比  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("消费总金额为%f",total);
		fclose(fp);
		printf("请输入本月收入:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t本月收支比为%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("消费总金额为%f",total);

		fp=fopen("D:\\Management_System\\十一月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t项目  %-8s占总比  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("消费总金额为%f",total);
		fclose(fp);
		printf("请输入本月收入:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t本月收支比为%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("消费总金额为%f",total);

		fp=fopen("D:\\Management_System\\十二月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t项目  %-8s占总比  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("消费总金额为%f",total);
		fclose(fp);
		printf("请输入本月收入:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t本月收支比为%-10f\n",total/income);
		break;
			
	}

}

void Mode_3 ()
{
	int n=0;
	Analyseitems(fam,n);
}

int main ()
{
	Mode_3();
}
