typedef struct//定义结构体
{
	char type[20];//消费类型
	float Getusm;//消费金额
	char place[20];//消费地点
	int time;//消费时间
}family;
family fam[80];

int menu_select()//显示该系统所具备的功能
{
	int c;
	do{
		system("cls");//清屏
		printf("\t\t欢迎来到家庭支出管理系统\n");
		printf("\t\t1.输入消费信息|\n");
		printf("\t\t2.显示消费情况|\n");
		printf("\t\t3.消费情况分析|\n");
		printf("\t\t4.退出系统|\n");
		printf("\t\t"*****************************************\n");
		printf("\t\t"*****************************************\n");
		printf("\t\t\t请对应选择选项（1-4）：");
		scanf("%d",&c);
	}while(c<1||c>8);
	return c;
}

void password()   //密码登录
{
	char d(6);
	char m(6);
	m[0]='1',m[1]='2',m[2]='3',m[3]='4',m[4]='5',m[5]='6';   //数组比较printf（"请输入六位数密码："）；//输入密码
	for (int n=0;;)
	{
		printf("请输入密码：\n");
		for (int i=0,i<6,i++)
		{
			d[i]=getch();
			if(d[i]>='0'||d[i]<='9'||d[i]<='z'||d[i]>='A'||d[i]<='z')
				putchar('*');
		}
		if(d[0]==m[0]&&d[1]==m[1]&&d[2]==m[2]&&d[3]==m[3]&&d[4]==m[4]&&d[5]==m[5])
		{
			printf("\n\t\t\t密码正确！请进行验证！\n");break;
		}
		if(d[0]!=m[0]||d[1]!=m[1]||d[2]!=m[2]||d[3]!=m[3]||d[4]!=m[4]||d[5]!=m[5])//当密码错误时如下
			printf("\n密码错误！请重新输入：");
		if(n>3)
		{
			printf("系统即将关闭\n");
			system("pause");
			exist(0);
		}
		n++
	}
}
void verification_code()//验证码部分
{
	int p[1]={0};
	int q[1]={0};
	for(int k=0;;)
	{
		srand(time(NULL));
		printf("验证码为：\n");
		p[0]=rand()%1000;//产生0-1000的随机数
		printf("%d",p[0]);
		printf("请输入验证码：");
		scanf("%d",&q[0]);
		if(q=[0]!=p[0])
			printf("\n欢迎使用！\n");
		system("pause");
		break;
	}
	if(k>3)
	{
		printf("系统即将关闭\n");
		system("pause");
		exit(0);
	}
	k++
}
}
