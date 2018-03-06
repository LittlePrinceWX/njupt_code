#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

typedef struct       //定义结构体
{
	char type[20];   //消费类型
	float Getsum;    //消费金额
	char place[20];  //消费地点
	int time;        //消费时间
}family;
family fam[80];

int Inputitmes(family sum[],int n)//输入消费信息
{
	int i=0;
	char sign='y',x[10];
	while(sign!='n'&&sign!='N')
	{
		printf("\t\t\t种类:");
		scanf("\t\t\t%s",sum[n+i].type);
		printf("\t\t\t支出（大于零）:");
		scanf("\t\t\t%f",&sum[n+i].Getsum);
		printf("\t\t\t地点:");
		scanf("\t\t\t%s",sum[n+i].place);
		printf("\t\t\t时间(0-31):");
		scanf("\t\t\t%d",&sum[n+i].time);
		if(sum[n+i].time<1||sum[n+i].time>31)
			return false;
		gets(x);
		printf("\t\t\t需要再次输入吗？(y\\n)");
		scanf("\t\t\t%c",&sign);
		i++;
	}
	return(n+i);
}


void Save (family sum[],int n)
{
	int month,i;
	FILE *fp;
	printf("请输入当前信息所属月份；");
	scanf("%d",&month);
	getchar();
	switch(month)
	{
		case 1:

			fp=fopen("D:\\Management_System\\一月支出信息.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t保存成功!\n");
			break;
		case 2:
			fp=fopen("D:\\Management_System\\二月支出信息.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t保存成功!\n");			
			break;
		case 3:
			fp=fopen("D:\\Management_System\\三月支出信息.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t保存成功!\n");			
			break;
		case 4:
			fp=fopen("D:\\Management_System\\四月支出信息.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t保存成功!\n");			
			break;
		case 5:
			fp=fopen("D:\\Management_System\\五月支出信息.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t保存成功!\n");			
			break;
		case 6:
			fp=fopen("D:\\Management_System\\六月支出信息.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t保存成功!\n");			
			break;
		case 7:
			fp=fopen("D:\\Management_System\\七月支出信息.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t保存成功!\n");			
			break;
		case 8:
			fp=fopen("D:\\Management_System\\八月支出信息.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t保存成功!\n");			
			break;
		case 9:
			fp=fopen("D:\\Management_System\\九月支出信息.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t保存成功!\n");			
			break;
		case 10:
			fp=fopen("D:\\Management_System\\十月支出信息.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t保存成功!\n");			
			break;
		case 11:
			fp=fopen("D:\\Management_System\\十一月支出信息.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t保存成功!\n");			
			break;
		case 12:
			fp=fopen("D:\\Management_System\\十二月支出信息.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
			fclose(fp);
			printf("\t\t\t保存成功!\n");			
			break;		
	}
}


void Mode_1 ()
{
	int n=0;
	char c;
	printf("\t\t\t请输入相应消费情况：\n");
	n=Inputitmes(fam,n);
	printf("\t\t\t需要保存数据吗？y\\n！ :");
	getchar();
	scanf("%c",&c);
	if(c=='y'||c=='Y')
		Save(fam,n);
	printf("\t\t\t");
	system("pause");
}

	
int main ()
{

	Mode_1();

}
