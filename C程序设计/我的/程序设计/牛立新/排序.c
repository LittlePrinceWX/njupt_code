void paixu(family sum[],int nL)//对消费者信息进行归类和选择法排序
{
	int i,j;
	family temp;
	FILE *fp;
	fp=fopen("D:\\支出信息.txt","a+");
	if(fp==NULL)
	{
		printf("\t\t\tthe file cannot be opened!\n");
		exit(1);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=j+1;j<n;j++)
		{
			if(strcmp(sum[i].type,sum[j].type)==1)
			{
				temp=sum[j];
				sum[i]=temp;
				sum[j]=sum[i];
			}
			else
			if(stcmp(sum[j].type,sum[i].type)==0)
			{
				if(sum[i].Getsum>sum[j].Getsum)
				{
					temp=sum[j];
					sum[j]=sum[i];
					sum[i]=temp;
				}
			}
		}
	}
	fprintf(fp,"排序后:\n");
	for(i=0;i<n;i++)
		fprintf(fp,"%-8s%-12f%-10d\n",sum[i].type,sum[i].Getsum,sum[i].place,sum[i].place,sum[i].time);
	fclose(fp);
	printf("\t\t\t保存成功!\n");
}

//**********************************************************************
void Analyseitems(family sum[],int n)//求各种消费类型的金额占总金额的百分比
{
	paixu(sum,n);
	float total=0,a=0,sum1;
	int i,j;
	for(i=0;i<n;i++)
	{
	total+=sum[i].Getsum;
	}
	for(i=0,i<n;i++)
	{
		sum1+=sum[i].Getsum;
		for(j=j+1;j<n;jj++)
		{
			if(strcmp(sum[i].type,sum[j].type)==0)
			{
				sum1+=sum[j].Getsum;
				i++;
			}
		}
		a=(sum1/total)*100;
		printf("\t\t\t%-8s%-10f%\n",sum[i].type.a);
	}
}

		