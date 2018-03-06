void Getsum(family sum[],int n)//计算消费总金额
{
	float getsum=0;
	int i=0;
	for(i=0;i<n;i++)
	{
		getsum+=sum[i].getsum;
	}
	printf("\t\t\t%f\n',getsum);
}
void Showitems(family sum[],int n)//输出所输入的消费信息
{
	int i;
	printf("\t\t\t-----------\n");
	printf("\t\t\t种类    支出      地点    时间\n");
	printf("\t\t\t-----------\n");
	for(i=1;i<n+1;i++)
	{
		printf("\t\t\t%-8s%-12f%-8s%-10d\n",sum[i-1].type,sum[i-1].getsum,sum[i-1].place,sum[i-1].time);
		if(i>1&&i%10==0)
		{
			printf("\t\t\t------------\n");
			printf("\t\t\t");
			system("pause");
			printf("\t\t\t-----------\n");
		}
	}
	printf("\t\t\t");
	system("pause"); 
}                                                                                                                                           su||