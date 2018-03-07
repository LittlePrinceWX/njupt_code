/***************************************************************
**项目名称：家庭支出管理系统 
**编译环境：Dev-C++  
**项目编写：王潇    B16010810
**          牛立新  B16010811 
**          刘一帆  B16010814
**完成时间：2017/9/8 
**说    明：文件目录：D\Management_System\
**          该目录下有  密码.txt 
**                      一月支出信息.txt 到 十二月支出信息.txt
**                      共13个txt文件 
****************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<conio.h>

typedef struct       //定义结构体
{
	char type[20];   //消费类型
	float money;    //消费金额
	char place[20];  //消费地点
	int time;        //消费时间
}expense;
expense exp[80];

void Mode_1 ();    //功能一 *输入消费信息*
void Mode_2 ();    //功能二 *显示消费情况*
void Mode_3 ();    //功能三 *消费情况分析*
void Mode_4 ();    //功能四 *退出系统*
int Passwoord_Menu ();               //密码菜单
void Input_Password ();              //输入密码函数
void Set_New_Password();             //设置新密码函数
void Password_Change ();             //修改密码函数
void Passwoord_Verify ();            //密码登录函数
void Password ();                    //密码函数
void Verification_code();            //验证码部分
int Menu_Select();                   //系统菜单，显示该系统所具备的功能
int Inputitmes(expense fm[],int n);      //输入消费信息
void Save (expense fm[],int n);          //保存消费信息
void showitems(expense fm[],int n);      //输出某月份的消费信息
void Analyseitems(expense fm[],int n);   //求各种消费类型的金额占总金额的百分比并求收支比例

char a[6]={0},b[6]={0},c[6]={0},d[6]={0},e[6]={0},f[6]={0};   //定义数组存放密码

int main ()
{
	Password();                 //密码函数
	Verification_code();        //验证码函数
	for(;;)
	{
		switch(Menu_Select())   //调用菜单选择函数，分类处理
		{
			case 1:
				Mode_1();       //模式一
				break;
			case 2:
				Mode_2();       //模式二
				getchar();
				break;
			case 3:
				Mode_3();       //模式三
				getchar();
				break;
			case 4:
				Mode_4();    //模式四
		
		}	
	}

}



void Mode_1 ()    //功能一 *输入消费信息*
{
	int n=0;
	char c;
	printf("\t\t\t请输入相应消费情况：\n");
	n=Inputitmes(exp,n);
	printf("\t\t\t需要保存数据吗？y\\n！ :");
	getchar();
	scanf("%c",&c);
	if(c=='y'||c=='Y')
		Save(exp,n);
	printf("\t\t\t");
	system("pause");
}

void Mode_2 ()   //功能二*显示消费情况*
{
	int n=0;
	showitems(exp,n);
}

void Mode_3 ()    //功能三*消费情况分析*
{
	int n=0;
	Analyseitems(exp,n);
}

void Mode_4 ()    //功能四*退出系统*
{
	char c;
	printf("\t\t\t你确定要退出了吗？y\\n : ");
	getchar();
	scanf("%c",&c);
	if(c=='y'||c=='Y')
	{
		printf("\t\t\t谢谢使用！\n");
		getchar();
		system("pause");
		exit(0);
	}
	if(c=='n'||c=='N')
	{
		system("pause");
	}
}

//*********************************************************************************//
//**************************密码函数部分*******************************************//

int Passwoord_Menu ()   //密码菜单
{
	int p;
	printf("\t\t***************************************************\n");
	printf("\t\t***************************************************\n");
	printf("\t\t**\t\t1.密码修改                       **\n");
	printf("\t\t**\t\t2.登录                           **\n");
	printf("\t\t***************************************************\n");
	printf("\t\t***************************************************\n");
	printf("\t\t请输入您所需要的选项（1,2）：");
	scanf("%d",&p); 
	getchar();
	return p;
}

void Input_Password ()     //输入密码函数
{
	printf("\t\t\t请输入六位数原密码：");
	for (int i=0;i<6;i++)
	{
		b[i]=getch();
		if(b[i]>='0'||b[i]<='9'||b[i]>='a'||b[i]<='z'||b[i]>='A'||b[i]<='Z')
			putchar('*');
    }
    getchar();
}

void Set_New_Password()    //设置新密码函数
{
	printf("\t\t\t请设置您的新密码：");
	for (int i=0;i<6;i++)
	{
		c[i]=getch();
		if(c[i]>='0'||c[i]<='9'||c[i]>='a'||c[i]<='z'||c[i]>='A'||c[i]<='Z')
			putchar('*');
    }
	getchar();		
    printf("\t\t\t请确认您的新密码：");
	for (int i=0;i<6;i++)
	{
		d[i]=getch();		
		if(d[i]>='0'||d[i]<='9'||d[i]>='a'||d[i]<='z'||d[i]>='A'||d[i]<='Z')
			putchar('*');
    }	
    getchar();
}

void Password_Change ()            //修改密码函数
{
	FILE *fp1,*fp2;
	fp1=fopen("D:\\Management_System\\密码.txt","r");   //打开密码文件
	if(!fp1)
	{
		printf("file cannot be opened");
		exit(1);		
	}
	for(int i=0;!feof(fp1);i++)
	{
		a[i]=fgetc(fp1);              //读出文件里存放的原始密码
	}
	fclose(fp1);
	
	for (int k=0;;)
	{
		Input_Password();              //调用输入密码函数
		
		if(a[0]==b[0]&&a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3]&&a[4]==b[4]&&a[5]==b[5])  //对比输入密码与原始密码
		{
			for(int n=0;;)
			{
				Set_New_Password();    //调用修改密码函数
				if(d[0]==c[0]&&d[1]==c[1]&&d[2]==c[2]&&d[3]==c[3]&&d[4]==c[4]&&d[5]==c[5])
				{
					break;              //修改成功退出for循环，进入下一步
				}
				else
					n++;
				if(n>=3)         //修改错误三次退出系统
				{
					printf("系统即将关闭\n");
					system("pause");
					exit(1);
				}
			}
			fp2=fopen("D:\\Management_System\\密码.txt","w+");   //以写方式打开密码文件
			if(!fp2)
			{
				printf("the file cannot be opened!");
				exit(1);
			}
			for(int j=0;j<6;j++)
			{
				fputc(c[j],fp2);             //写入修改的新密码
			}
			fclose(fp2);
			printf("\t\t\t密码修改成功!\n");
			break;	
		}
		else
		{
			printf("\t\t\t密码错误\n");
			k++;			
		}		
		if(k>=3)                         //密码输入错误三次退出系统
		{
			printf("系统即将关闭\n");
			system("pause");
			exit(1);
		}		
	}
	
}

void Passwoord_Verify ()     //密码登录函数
{
	FILE *fp3;
	fp3=fopen("D:\\Management_System\\密码.txt","r");
	
	if(!fp3)
	{
		printf("the file cannot be opened!");
		exit(1);
	}
	for(int i=0;!feof(fp3);i++)
	{
		e[i]=fgetc(fp3);
	}
	fclose(fp3);
	
	for (int n=0;;)
	{
		printf("\t\t\t请输入六位数密码: ");
		for (int j=0;j<6;j++)
		{
			f[j]=getch();
			if(f[j]>='0'||f[j]<='9'||f[j]>='a'||f[j]<='z'||f[j]>='A'||f[j]<='Z')
				putchar('*');
		}
		getchar();
		if(e[0]==f[0]&&e[1]==f[1]&&e[2]==f[2]&&e[3]==f[3]&&e[4]==f[4]&&e[5]==f[5])
		{
			printf("\t\t\t\t密码正确！请进行验证！\n");
			break;
		}
		if(e[0]!=f[0]||e[1]!=f[1]||e[2]!=f[2]||e[3]!=f[3]||e[4]!=f[4]||e[5]!=f[5])//密码错误
		{
			
			printf("\n密码错误！请重新输入：\n");
			n++;
		}
		if(n>2)
		{
			printf("系统即将关闭\n");
			system("pause");
			exit(0);
		}
	}
}

void Password ()        //密码函数
{
	int p;
	switch(Passwoord_Menu())
	{
		case 1:
		{
			Password_Change();
		}
		case 2:
		{
			Passwoord_Verify();
		}
	}
	
}

//************************************************************************//
//************************************************************************//

void Verification_code()      //验证码部分
{
	int p[1]={0};
	int q[1]={0};
	for(int k=0;;)
	{
		srand((unsigned)time(NULL));
		printf("验证码为：");
		p[0]=rand() % 1000;        //产生0-1000的随机数
		printf("%d\n",p[0]);
		printf("请输入验证码：");
		scanf("%d",&q[0]);
		getchar();
		if(q[0]==p[0])
		{
			printf("\n欢迎使用！\n");
			break;
		}
		if(k>3)
		{
			printf("系统即将关闭\n");
			system("pause");
			exit(0);
		}
		k++;
	}

}

int Menu_Select()     //系统菜单，显示该系统所具备的功能
{
	int c;
	do{
		system("cls");
		printf("\t\t******************************************\n");
		printf("\t\t******************************************\n");
		printf("\t\t**\t欢迎来到家庭支出管理系统\t**\n");
		printf("\t\t**\t1.输入消费信息|          \t**\n");
		printf("\t\t**\t2.显示消费情况|          \t**\n");
		printf("\t\t**\t3.消费情况分析|          \t**\n");
		printf("\t\t**\t4.退出系统|              \t**\n");
		printf("\t\t******************************************\n");
		printf("\t\t******************************************\n");
		printf("\t\t\t请对应选择选项（1-4）：");
		scanf("%d",&c);
	}while(c<1||c>8);
	return c;
}

//***********************************************************************//
//**************************Mode_1()*************************************//

int Inputitmes(expense fm[],int n)   //输入消费信息
{
	int i=0;
	char sign='y',x[10];
	while(sign!='n'&&sign!='N')
	{
		printf("\t\t\t种类:");
		scanf("\t\t\t%s",fm[n+i].type);
		printf("\t\t\t支出（大于零）:");
		scanf("\t\t\t%f",&fm[n+i].money);
		printf("\t\t\t地点:");
		scanf("\t\t\t%s",fm[n+i].place);
		printf("\t\t\t时间(0-31):");
		scanf("\t\t\t%d",&fm[n+i].time);
		if(fm[n+i].time<1||fm[n+i].time>31)
			return false;
		gets(x);
		printf("\t\t\t需要再次输入吗？(y\\n)");
		scanf("\t\t\t%c",&sign);
		i++;
	}
	return(n+i);
}


void Save (expense fm[],int n)    //保存消费信息
{
	int month,i;
	FILE *fp;
	printf("\t\t请输入当前信息所属月份；");
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
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
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
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
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
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
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
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
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
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
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
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
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
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
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
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
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
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
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
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
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
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
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
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fclose(fp);
			printf("\t\t\t保存成功!\n");			
			break;		
	}
}

//******************************************************************************//
//****************************Mode_2()******************************************//

void showitems(expense fm[],int n)   //输出某月份的消费信息
{
	int i=0,month;
	FILE *fp;
	printf("\t\t\t请选择月份: ");
	scanf("%d",&month);
	getchar();
	printf("\t\t\t---------------------------------\n");
	printf("\t\t\t种类     支出     地点       时间\n");
	printf("\t\t\t---------------------------------\n");

    switch(month)
    {
		case 1:
		fp=fopen("D:\\Management_System\\一月支出信息.txt","r");                                   
	    if(fp==0)
	    {
	    	printf("file error\n");
		    exit(1);
	    }
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
		    printf("\t\t\t%-8s%9.3f  %-8s   %-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
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
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
		    printf("\t\t\t%-8s%9.3f  %-8s   %-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
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
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
		    printf("\t\t\t%-8s%9.3f  %-8s   %-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
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
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
		    printf("\t\t\t%-8s%9.3f  %-8s   %-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
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
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
		    printf("\t\t\t%-8s%9.3f  %-8s   %-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
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
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
		    printf("\t\t\t%-8s%9.3f  %-8s   %-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
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
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
		    printf("\t\t\t%-8s%9.3f  %-8s   %-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
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
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
		    printf("\t\t\t%-8s%9.3f  %-8s   %-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
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
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
		    printf("\t\t\t%-8s%9.3f  %-8s   %-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
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
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
		    printf("\t\t\t%-8s%9.3f  %-8s   %-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
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
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
		    printf("\t\t\t%-8s%9.3f  %-8s   %-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
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
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
		    printf("\t\t\t%-8s%9.3f  %-8s   %-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		}
		fclose(fp);
		break;
	}
}	

//************************************************************************************//
//*******************************Mode_3()*********************************************//

void Analyseitems(expense fm[],int n)   //求各种消费类型的金额占总金额的百分比并求收支比例
{
	float total=0,a=0,income;
	int i=0,j=0,month;
	FILE*fp;
	printf("\t\t\t请选择月份：");
	scanf("%d",&month);
	printf("\n");
	switch(month)
	{
		case 1:
		fp=fopen("D:\\Management_System\\一月支出信息.txt","r");
		if(fp==0)
		{
			printf("file error\n");
			exit(1);
		}
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
			printf("\t\t\t%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			total+=fm[i].money;
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t消费总金额为%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\一月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t项目 %-8s   占总比 %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t请输入本月收入:");
		scanf("%f",&income);
		printf("\t\t本月收支比为   %-10f\n",total/income);
		break;
		
		case 2:
		fp=fopen("D:\\Management_System\\二月支出信息.txt","r");
		if(fp==0)
		{
			printf("file error\n");
			exit(1);
		}
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
			printf("\t\t\t%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			total+=fm[i].money;
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t消费总金额为%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\二月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t项目  %-8s占总比  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t请输入本月收入:");
		scanf("%f",&income);
		printf("\t\t本月收支比为   %-10f\n",total/income);
		break;	

		case 3:
		fp=fopen("D:\\Management_System\\三月支出信息.txt","r");
		if(fp==0)
		{
			printf("file error\n");
			exit(1);
		}
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
			printf("\t\t\t%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			total+=fm[i].money;
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t消费总金额为%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\三月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t项目 %-8s   占总比 %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t请输入本月收入:");
		scanf("%f",&income);
		printf("\t\t本月收支比为   %-10f\n",total/income);
		break;		

		case 4:
		fp=fopen("D:\\Management_System\\四月支出信息.txt","r");
		if(fp==0)
		{
			printf("file error\n");
			exit(1);
		}
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
			printf("\t\t\t%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			total+=fm[i].money;
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t消费总金额为%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\四月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t项目  %-8s   占总比  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t请输入本月收入:");
		scanf("%f",&income);
		printf("\t\t本月收支比为   %-10f\n",total/income);
		break;		

		case 5:
		fp=fopen("D:\\Management_System\\五月支出信息.txt","r");
		if(fp==0)
		{
			printf("file error\n");
			exit(1);
		}
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
			printf("\t\t\t%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			total+=fm[i].money;
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t消费总金额为%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\五月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t项目 %-8s   占总比 %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t请输入本月收入:");
		scanf("%f",&income);
		printf("\t\t本月收支比为   %-10f\n",total/income);
		break;
		
		case 6:
		fp=fopen("D:\\Management_System\\六月支出信息.txt","r");
		if(fp==0)
		{
			printf("file error\n");
			exit(1);
		}
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
			printf("\t\t\t%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			total+=fm[i].money;
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t消费总金额为%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\六月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t项目 %-8s   占总比 %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t请输入本月收入:");
		scanf("%f",&income);
		printf("\t\t本月收支比为   %-10f\n",total/income);
		break;
		
		case 7:
		fp=fopen("D:\\Management_System\\七月支出信息.txt","r");
		if(fp==0)
		{
			printf("file error\n");
			exit(1);
		}
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
			printf("\t\t\t%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			total+=fm[i].money;
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t消费总金额为%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\七月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t项目  %-8s   占总比  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t请输入本月收入:");
		scanf("%f",&income);
		printf("\t\t本月收支比为   %-10f\n",total/income);
		break;
		
		case 8:
		fp=fopen("D:\\Management_System\\八月支出信息.txt","r");
		if(fp==0)
		{
			printf("file error\n");
			exit(1);
		}
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
			printf("\t\t\t%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			total+=fm[i].money;
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t消费总金额为%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\八月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t项目  %-8s   占总比  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t请输入本月收入:");
		scanf("%f",&income);
		printf("\t\t本月收支比为    %-10f\n",total/income);
		break;
		
		case 9:
		fp=fopen("D:\\Management_System\\九月支出信息.txt","r");
		if(fp==0)
		{
			printf("file error\n");
			exit(1);
		}
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
			printf("\t\t\t%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			total+=fm[i].money;
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t消费总金额为%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\九月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t项目  %-8s占总比  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t请输入本月收入:");
		scanf("%f",&income);
		printf("\t\t本月收支比为   %-10f\n",total/income);
		break;
		
		case 10:
		fp=fopen("D:\\Management_System\\十月支出信息.txt","r");
		if(fp==0)
		{
			printf("file error\n");
			exit(1);
		}
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
			printf("\t\t\t%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			total+=fm[i].money;
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t消费总金额为%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\十月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t项目  %-8s   占总比  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t请输入本月收入:");
		scanf("%f",&income);
		printf("\t\t本月收支比为   %-10f\n",total/income);
		break;
		
		case 11:
		fp=fopen("D:\\Management_System\\十一月支出信息.txt","r");
		if(fp==0)
		{
			printf("file error\n");
			exit(1);
		}
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
			printf("\t\t\t%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			total+=fm[i].money;
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t消费总金额为%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\十一月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t项目  %-8s   占总比  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t请输入本月收入:");
		scanf("%f",&income);
		printf("\t\t本月收支比为   %-10f\n",total/income);
		break;
		
		case 12:
		fp=fopen("D:\\Management_System\\十二月支出信息.txt","r");
		if(fp==0)
		{
			printf("file error\n");
			exit(1);
		}
		fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		while(!feof(fp))
		{
			printf("\t\t\t%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			total+=fm[i].money;
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t消费总金额为%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\十二月支出信息.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t项目  %-8s   占总比  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t请输入本月收入:");
		scanf("%f",&income);
		printf("\t\t本月收支比为   %-10f\n",total/income);
		break;			
	}
	getchar();
}



