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


void Analyseitems(family sum[],int n)//������������͵Ľ��ռ�ܽ��İٷֱȲ�����֧����
{
	float total=0,a=0,income;
	int i=0,j=0,month;
	FILE*fp;
	printf("��ѡ���·ݣ�");
	scanf("%d",&month);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("�����ܽ��Ϊ%f",total);

		fp=fopen("D:\\Management_System\\һ��֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t��Ŀ  %-8sռ�ܱ�  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("�����ܽ��Ϊ%f",total);
		fclose(fp);
		printf("�����뱾������:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t������֧��Ϊ%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("�����ܽ��Ϊ%f",total);


		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t��Ŀ  %-8sռ�ܱ�  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("�����ܽ��Ϊ%f",total);
		fclose(fp);
		printf("�����뱾������:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t������֧��Ϊ%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("�����ܽ��Ϊ%f",total);


		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t��Ŀ  %-8sռ�ܱ�  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("�����ܽ��Ϊ%f",total);
		fclose(fp);
		printf("�����뱾������:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t������֧��Ϊ%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("�����ܽ��Ϊ%f",total);

		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t��Ŀ  %-8sռ�ܱ�  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("�����ܽ��Ϊ%f",total);
		fclose(fp);
		printf("�����뱾������:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t������֧��Ϊ%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("�����ܽ��Ϊ%f",total);

		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t��Ŀ  %-8sռ�ܱ�  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("�����ܽ��Ϊ%f",total);
		fclose(fp);
		printf("�����뱾������:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t������֧��Ϊ%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("�����ܽ��Ϊ%f",total);

		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t��Ŀ  %-8sռ�ܱ�  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("�����ܽ��Ϊ%f",total);
		fclose(fp);
		printf("�����뱾������:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t������֧��Ϊ%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("�����ܽ��Ϊ%f",total);

		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t��Ŀ  %-8sռ�ܱ�  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("�����ܽ��Ϊ%f",total);
		fclose(fp);
		printf("�����뱾������:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t������֧��Ϊ%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("�����ܽ��Ϊ%f",total);

		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t��Ŀ  %-8sռ�ܱ�  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("�����ܽ��Ϊ%f",total);
		fclose(fp);
		printf("�����뱾������:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t������֧��Ϊ%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("�����ܽ��Ϊ%f",total);

		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t��Ŀ  %-8sռ�ܱ�  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("�����ܽ��Ϊ%f",total);
		fclose(fp);
		printf("�����뱾������:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t������֧��Ϊ%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("�����ܽ��Ϊ%f",total);

		fp=fopen("D:\\Management_System\\ʮ��֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t��Ŀ  %-8sռ�ܱ�  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("�����ܽ��Ϊ%f",total);
		fclose(fp);
		printf("�����뱾������:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t������֧��Ϊ%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("�����ܽ��Ϊ%f",total);

		fp=fopen("D:\\Management_System\\ʮһ��֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t��Ŀ  %-8sռ�ܱ�  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("�����ܽ��Ϊ%f",total);
		fclose(fp);
		printf("�����뱾������:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t������֧��Ϊ%-10f\n",total/income);
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
			total+=sum[i].money;
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
		}
		fclose(fp);
		printf("�����ܽ��Ϊ%f",total);

		fp=fopen("D:\\Management_System\\ʮ����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",sum[i].type,&sum[i].money,sum[i].place,&sum[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t��Ŀ  %-8sռ�ܱ�  %-10f%\n",sum[i].type,sum[i].money/total);
		}
		printf("�����ܽ��Ϊ%f",total);
		fclose(fp);
		printf("�����뱾������:");
		scanf("\t\t\t%f",&income);
		printf("\t\t\t������֧��Ϊ%-10f\n",total/income);
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
