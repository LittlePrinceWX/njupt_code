#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include"password.h"

char a[6]={0},b[6]={0},c[6]={0},d[6]={0},e[6]={0},f[6]={0};

int Passwoord_Menu ()
{
	int p;
	printf("\t\t***************************************************\n");
	printf("\t\t***************************************************\n");
	printf("\t\t**\t\t1.密码修改                       **\n");
	printf("\t\t**\t\t2.登录                           **\n");
	printf("\t\t***************************************************\n");
	printf("\t\t***************************************************\n");
	printf("请输入您所需要的选项（1,2）：");
	scanf("%d",&p); 
	return p;
}


void Input_Password ()
{
	printf("\t\t\t请输入六位数原密码：");
	for (int i=0;i<6;i++)
	{
		b[i]=getchar();
		if(b[i]>='0'||b[i]<='9'||b[i]>='a'||b[i]<='z'||b[i]>='A'||b[i]<='Z')
			putchar('*');
    }
    getchar();
}


void Set_New_Password()
{
	printf("\t\t\t请设置您的新密码：");
	for (int i=0;i<6;i++)
	{
		c[i]=getchar();
		if(c[i]>='0'||c[i]<='9'||c[i]>='a'||c[i]<='z'||c[i]>='A'||c[i]<='Z')
			putchar('*');
    }
	getchar();		
    printf("\t\t\t请确认您的新密码：");
	for (int i=0;i<6;i++)
	{
		d[i]=getchar();		
		if(d[i]>='0'||d[i]<='9'||d[i]>='a'||d[i]<='z'||d[i]>='A'||d[i]<='Z')
			putchar('*');
    }	
    getchar();
}

void Password_Change ()
{
	int k;
	FILE *fp1,*fp2;
	fp1=fopen("D:\\Management_System\\密码.txt","r"); 
	if(!fp1)
	{
		printf("file cannot be opened");
		exit(1);		
	}
	for(int i=0;!feof(fp1);i++)
	{
		a[i]=fgetc(fp1);
	}
	fclose(fp1);
	
	Input_Password();
	
	if(a[0]==b[0]&&a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3]&&a[4]==b[4]&&a[5]==b[5])
	{
		for(int n=0;;)
		{
			Set_New_Password();
			if(d[0]==c[0]&&d[1]==c[1]&&d[2]==c[2]&&d[3]==c[3]&&d[4]==c[4]&&d[5]==c[5])
			{
				break;
			}
			else
				n++;
			if(n>=3)
			{
				printf("系统即将关闭\n");
				system("pause");
				//exit(1);
			}
		}
		fp2=fopen("D:\\密码.txt","w");
		if(!fp2)
		{
			printf("the file cannot be opened!");
			exit(1);
		}
		for(int j=0;j<6;j++)
		{
			fputc(c[j],fp2);
		}
		fclose(fp2);
		printf("\t\t\t密码修改成功!\n");	
	}
	else
	{
		printf("\t\t\t密码错误\n");
		k++;
		if(k>=3)
		{
			printf("系统即将关闭\n");
			system("pause");
			//exit(1);
		}		
	}
}



void Passwoord_Verify ()
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
			f[j]=getchar();
			if(f[j]>='0'||f[j]<='9'||f[j]>='a'||f[j]<='z'||f[j]>='A'||f[j]<='Z')
				putchar('*');
		}
		getchar();
		if(e[0]==f[0]&&e[1]==f[1]&&e[2]==f[2]&&e[3]==f[3]&&e[4]==f[4]&&e[5]==f[5])
		{
			printf("\t\t\t\t密码正确！请进行验证！\n");
			break;
		}
		if(e[0]!=f[0]||e[1]!=f[1]||e[2]!=f[2]||e[3]!=f[3]||e[4]!=f[4]||e[5]!=f[5])//当密码错误时如下
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


void Password ()
{
	int p;
	printf("\t\t***************************************************\n");
	printf("\t\t***************************************************\n");
	printf("\t\t**\t\t1.密码修改                       **\n");
	printf("\t\t**\t\t2.登录                           **\n");
	printf("\t\t***************************************************\n");
	printf("\t\t***************************************************\n");
	printf("请输入您所需要的选项（1,2）：");
	scanf("%d",&p); 
	getchar();
	
	switch(p)
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

void Verification_code()//验证码部分
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
		//system("pause");
		if(k>3)
		{
			printf("系统即将关闭\n");
			system("pause");
			exit(0);
		}
		k++;
	}

}

int Menu_Select()//显示该系统所具备的功能
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







