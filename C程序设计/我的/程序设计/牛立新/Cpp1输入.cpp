#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

typedef struct       //����ṹ��
{
	char type[20];   //��������
	float Getsum;    //���ѽ��
	char place[20];  //���ѵص�
	int time;        //����ʱ��
}family;
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
		printf("\t\t\t��Ҫ�ٴ�������(y\n)");
		scanf("\t\t\t%c",&sign);
		i++
	}
	return(n+i);
}

void Save(family sum[],int n)//������������Ϣ
{
	int i;
	FILE *fp;
	fp=fopen("D:\\֧����Ϣ.txt","a+");
	if(fp==NULL)
	{
		printf("\t\t\tthe file cannot be opened!\n");
		exit(1);
	}
	//fseek(fp,-1,SEEK_END);
	fputc('\n',fp);
	for(i=0;i<n;i++)
		fprintf(fp,"%-8s%-12f%-8s%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].time);
	fclose(fp);
	printf("\t\t\t ����ɹ�!\n);
}
	
