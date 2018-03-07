#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
//定义结构体车友
struct cheyou
{
	char name[20];
	//会员名
	char nickname[20];
	//会员昵称
	char job[20];
	//会员职业
	char brand[20];
	//车辆品牌
	char type[20];
	//车型
	char colour[20];
	//颜色
	char price[20];
	//车价
	char modle[20];
	//发动机型号
	int sex;
	//性别
	int age;
	//年龄
	int driveage;
	//驾龄
};

//交换数组中两个车友的位置
void change(int a,int b,struct cheyou *f)
//a,b表示需要交换的数据在数组中的位置
{
	int p;
	char q[20];
	strcpy(q,f[a].name);
	//利用strcpy函数复制
	strcpy(f[a].name,f[b].name);
	strcpy(f[b].name,q);

	strcpy(q,f[a].nickname);
	strcpy(f[a].nickname,f[b].nickname);
	strcpy(f[b].nickname,q);

	p=f[a].sex;
	f[a].sex=f[b].sex;
	f[b].sex=p;

	strcpy(q,f[a].job);
	strcpy(f[a].job,f[b].job);
	strcpy(f[b].job,q);

	p=f[a].age;
	f[a].age=f[b].age;
	f[b].age=p;

	p=f[a].driveage;
	f[a].driveage=f[b].driveage;
	f[b].driveage=p;

	strcpy(q,f[a].brand);
	strcpy(f[a].brand,f[b].brand);
	strcpy(f[b].brand,q);

	strcpy(q,f[a].type);
	strcpy(f[a].type,f[b].type);
	strcpy(f[b].type,q);

	strcpy(q,f[a].colour);
	strcpy(f[a].colour,f[b].colour);
	strcpy(f[b].colour,q);
}
//按年龄从小到大排序并输出
void PrintAll(struct cheyou *p,int l)
{
	int x,index,i;
	for(x=0;x<l-1;x++)
	{
		index=x;
		for(i=x+1;i<l;i++)
			if (p[i].age<p[index].age)
				index=i;
		if (index!=x)
			change(index,x,p);
		//调用change函数交换数组中的两个成员
	}
	cout<<"会员名"<<"\t"<<"昵称"<<"\t"<<"性别"<<"\t"<<"职业"<<"\t"<<"年龄"<<"\t"<<"驾龄"<<"\t"<<"品牌"<<"\t"<<"车型"<<"\t"<<"颜色"<<"\t"<<"\t"<<"型号"<<"\t"<<"车价"<<"\t"<<endl;
	for(x=0;x<l;x++)
	{
		cout<<p[x].name<<"\t";
		cout<<p[x].nickname<<"\t";
		if (p[x].sex==0)
			cout<<"男"<<"\t";
		else
			cout<<"女"<<"\t";
		cout<<p[x].job<<"\t";
		cout<<p[x].age<<"\t";
		cout<<p[x].driveage<<"\t";
		cout<<p[x].brand<<"\t";
		cout<<p[x].type<<"\t";
		cout<<p[x].colour<<"\t";
	    cout<<p[x].modle<<"\t";
		cout<<p[x].price<<"\t"<<endl;
	}
}
//查询女性车友信息
void FindFemale(struct cheyou *cy,int l)
{
	int x=0;
	cout<<"女性会员信息"<<endl;
	cout<<"会员名"<<"\t"<<"昵称"<<"\t"<<"职业"<<"\t"<<"年龄"<<"\t"<<"驾龄"<<"\t"<<"品牌"<<"\t"<<"车型"<<"\t"<<"颜色"<<"\t"<<"型号"<<"\t"<<"车价"<<"\t"<<endl;
	while (x<l)
	{
		if (cy[x].sex==1)
			//循环体查找女性
		{
			cout<<cy[x].name<<"\t";
			cout<<cy[x].nickname<<"\t";
			cout<<cy[x].job<<"\t";
			cout<<cy[x].age<<"\t";
			cout<<cy[x].driveage<<"\t";
			cout<<cy[x].brand<<"\t";
			cout<<cy[x].type<<"\t";
			cout<<cy[x].colour<<"\t";
			cout<<cy[x].modle<<"\t";
			cout<<cy[x].price<<"\t"<<endl;
		}
		x++;
	}
}
//查询男性车友信息
void FindMale(struct cheyou *cy,int l)
{
	int y=0;
	cout<<"男性会员信息"<<endl;
	cout<<"会员名"<<"\t"<<"昵称"<<"\t"<<"职业"<<"\t"<<"年龄"<<"\t"<<"驾龄"<<"\t"<<"品牌"<<"\t"<<"车型"<<"\t"<<"颜色"<<"\t"<<"\t"<<"型号"<<"\t"<<"车价"<<"\t"<<endl;
	while (y<l)
	{
		if (cy[y].sex==0)
		{
			cout<<cy[y].name<<"\t";
			cout<<cy[y].nickname<<"\t";
			cout<<cy[y].job<<"\t";
			cout<<cy[y].age<<"\t";
			cout<<cy[y].driveage<<"\t";
			cout<<cy[y].brand<<"\t";
			cout<<cy[y].type<<"\t";
			cout<<cy[y].colour<<"\t";
			cout<<cy[y].modle<<"\t";
			cout<<cy[y].price<<"\t"<<endl;
		}
		y++;
	}
}


//按照车型查找
void FindByType(struct cheyou *p,int l)
{
	char t[20];
	int x=0,a=0;
	cout<<"请输入所要查询的车型："<<endl;
	cin>>t;
	for(x=0;x<l;x++)
		if (strcmp(p[x].type,t)==0)
				a++;
	if (a!=0)
	{
		cout<<"符合条件的车友有："<<endl;
		cout<<"会员名"<<"\t"<<"昵称"<<"\t"<<"性别"<<"\t"<<"职业"<<"\t"<<"年龄"<<"\t"<<"驾龄"<<"\t"<<"品牌"<<"\t"<<"车型"<<"\t"<<"颜色"<<"\t"<<"\t"<<"型号"<<"\t"<<"车价"<<"\t"<<endl;
		for(x=0;x<l-1;x++)
		{
			if (strcmp(p[x].type,t)==0)
			{
				cout<<p[x].name<<"\t";
				cout<<p[x].nickname<<"\t";
				if (p[x].sex==0)
					cout<<"男"<<"\t";
				else
					cout<<"女"<<"\t";
					cout<<p[x].job<<"\t";
					cout<<p[x].age<<"\t";
					cout<<p[x].driveage<<"\t";
					cout<<p[x].brand<<"\t";
					cout<<p[x].type<<"\t";
					cout<<p[x].name<<"\t";
					cout<<p[x].modle<<"\t";
					cout<<p[x].price<<"\t"<<endl;
			}
		}
	}
	else
		cout<<"没有符合条件的车友"<<endl;
}
//按照发动机型号查找
void FindByModle(struct cheyou *p,int l)
{
	char t[20];
	int x=0,a=0;
	cout<<"请输入所要查询的型号："<<endl;
	cin>>t;
	for(x=0;x<l;x++)
		if (strcmp(p[x].modle,t)==0)
				a++;
	if (a!=0)
	{
		cout<<"符合条件的车友有："<<endl;
		cout<<"会员名"<<"\t"<<"昵称"<<"\t"<<"性别"<<"\t"<<"职业"<<"\t"<<"年龄"<<"\t"<<"驾龄"<<"\t"<<"品牌"<<"\t"<<"车型"<<"\t"<<"颜色"<<"\t"<<"型号"<<"\t"<<"车价"<<"\t"<<endl;
		for(x=0;x<l-1;x++)
		{
			if (strcmp(p[x].modle,t)==0)
			{
				cout<<p[x].name<<"\t";
				cout<<p[x].nickname<<"\t";
				if (p[x].sex==0)
					cout<<"男"<<"\t";
				else
					cout<<"女"<<"\t";
					cout<<p[x].job<<"\t";
					cout<<p[x].age<<"\t";
					cout<<p[x].driveage<<"\t";
					cout<<p[x].brand<<"\t";
					cout<<p[x].type<<"\t";
					cout<<p[x].name<<"\t";
                    cout<<p[x].modle<<"\t";
					cout<<p[x].price<<"\t"<<endl;

			}
		}
	}
	else
		cout<<"没有符合条件的车友"<<endl;
}
//按照车价查找
void FindByPrice(struct cheyou *p,int l)
{
	char t[20];
	int x=0,a=0;
	cout<<"请输入所要查询的车价："<<endl;
	cin>>t;
	for(x=0;x<l;x++)
		if (strcmp(p[x].price,t)==0)
				a++;
	if (a!=0)
	{
		cout<<"符合条件的车友有："<<endl;
		cout<<"会员名"<<"\t"<<"昵称"<<"\t"<<"性别"<<"\t"<<"职业"<<"\t"<<"年龄"<<"\t"<<"驾龄"<<"\t"<<"品牌"<<"\t"<<"车型"<<"\t"<<"颜色"<<"\t"<<"型号"<<"\t"<<"车价"<<"\t"<<endl;
		for(x=0;x<l-1;x++)
		{
			if (strcmp(p[x].price,t)==0)
			{
				cout<<p[x].name<<"\t";
				cout<<p[x].nickname<<"\t";
				if (p[x].sex==0)
					cout<<"男"<<"\t";
				else
					cout<<"女"<<"\t";
					cout<<p[x].job<<"\t";
					cout<<p[x].age<<"\t";
					cout<<p[x].driveage<<"\t";
					cout<<p[x].brand<<"\t";
					cout<<p[x].type<<"\t";
					cout<<p[x].name<<"\t";
                    cout<<p[x].modle<<"\t";
					cout<<p[x].price<<"\t"<<endl;

			}
		}
	}
	else
		cout<<"没有符合条件的车友"<<endl;
}
//按品牌计算车友数
void CountByBrand(struct cheyou *p,int l)
{
	int x=0,m=0;
	//m表示符合条件的车友数
	char t[20];
	cout<<"请输入需要查询的品牌"<<endl;
	cin>>t;
	while (x<l)
	{
		if (strcmp(p[x].brand,t)==0)
		{	m++;
		cout<<p[x].name<<"\t";
				cout<<p[x].nickname<<"\t";
					if (p[x].sex==0)
					cout<<"男"<<"\t";
				else
					cout<<"女"<<"\t";
					cout<<p[x].job<<"\t";
					cout<<p[x].age<<"\t";
					cout<<p[x].driveage<<"\t";
					cout<<p[x].brand<<"\t";
					cout<<p[x].type<<"\t";
					cout<<p[x].name<<"\t";
					cout<<p[x].modle<<"\t";
					cout<<p[x].price<<"\t"<<endl;
		}
		x++;
	}
	cout<<"符合条件的车友有"<<m<<"个"<<endl;
}
//按车型计算车友数
void CountByType(struct cheyou *p,int l)
{
	int x=0,m=0;
	//m表示符合条件的车友数
	char t[20];
	cout<<"请输入需要查询的车型"<<endl;
	cin>>t;
	while (x<l)
	{
		if (strcmp(p[x].type,t)==0)
		{
			m++;
		cout<<p[x].name<<"\t";
				cout<<p[x].nickname<<"\t";
					if (p[x].sex==0)
					cout<<"男"<<"\t";
				else
					cout<<"女"<<"\t";
					cout<<p[x].job<<"\t";
					cout<<p[x].age<<"\t";
					cout<<p[x].driveage<<"\t";
					cout<<p[x].brand<<"\t";
					cout<<p[x].type<<"\t";
					cout<<p[x].name<<"\t"<<endl;}
		x++;
	}
	cout<<"符合条件的车友有"<<m<<"个"<<endl;
}
//删除车友信息
void Delete(struct cheyou *p,int &l)
{
	char t[20];
	int x=0,i,a=0;
	FILE *fp2;
	cout<<"请输入需要退会的会员姓名"<<endl;
	cin>>t;
	while (x<l)
		if (strcmp(p[x].name,t)==0)
		{
			i=x;
			a=1;
			break;
		}
		else
			x++;
	if (a==1)
	{
			if (i!=l-1)
				while(i<l)
					//将要删除的成员移至数组尾
				{
					strcpy(p[i].name,p[i+1].name);
					strcpy(p[i].nickname,p[i+1].nickname);
					p[i].sex=p[i+1].sex;
					strcpy(p[i].job,p[i+1].job);
					p[i].age=p[i+1].age;
					p[i].driveage=p[i+1].driveage;
					strcpy(p[i].brand,p[i+1].brand);
					strcpy(p[i].type,p[i+1].type);
					strcpy(p[i].colour,p[i+1].colour);
					i++;
				};
			l--;
			fp2=fopen("cheyou.dat","wb");
			if (!fp2)
			{
				cout<<"文件打开失败"<<endl;
				exit(1);
			}
			else
			for(i=0;i<l-1;i++)
				//将数组除去最后一位重新写入文件
				fprintf(fp2,"%s %s %d %s %d %d %s %s %s %s %s\n",p[i].name,p[i].nickname,p[i].sex,p[i].job,p[i].age,p[i].driveage,p[i].brand,p[i].type,p[i].colour,p[i].price,p[i].modle);
			fclose(fp2);
			cout<<"会员已删除"<<endl;
	}
	else
		cout<<"不存在该会员"<<endl;
}
//添加新车友信息
void Add(struct cheyou *a,int &l)
{
	FILE *fp;
	fp=fopen("cheyou.dat","ab+");
	if (!fp)
	{
		cout<<"文件打开失败"<<endl;
		exit(1);
	}
	cout<<"请输入新添加车友的信息"<<endl;
	cout<<"请输入会员名"<<endl;
	cin>>a[l].name;
	cout<<"请输入会员昵称"<<endl;
	cin>>a[l].nickname;
	cout<<"请输入会员性别（0为男 1为女）"<<endl;
	cin>>a[l].sex;
	while ((a[l].sex!=1)&&(a[l].sex!=0))
	{
		cout<<"输入性别不合法，请重新输入："<<endl;
		cin>>a[l].sex;
	}
	cout<<"请输入会员职业"<<endl;
	cin>>a[l].job;
	cout<<"请输入会员年龄"<<endl;
	cin>>a[l].age;
	while (a[l].age<=18)
	{
		cout<<"年龄不合法,请重新输入年龄"<<endl;
		cin>>a[l].age;
	}
	cout<<"请输入会员驾龄"<<endl;
	cin>>a[l].driveage;
	while ((a[l].age-a[l].driveage)<18)
	{
		cout<<"驾龄不合法，请重新输入驾龄"<<endl;
		cin>>a[l].driveage;
	}
	cout<<"请输入车辆品牌"<<endl;
	cin>>a[l].brand;
	cout<<"请输入车型"<<endl;
	cin>>a[l].type;
	cout<<"请输入车辆颜色"<<endl;
	cin>>a[l].colour;
	cout<<"请输入发动机型号"<<endl;
	cin>>a[l].modle;
	cout<<"请输入车价"<<endl;
	cin>>a[l].price;
	fprintf(fp,"%s %s %d %s %d %d %s %s %s %s %s %s\n",a[l].name,a[l].nickname,a[l].sex,a[l].job,a[l].age,a[l].driveage,a[l].brand,a[l].type,a[l].colour,a[l].modle,a[l].price);//将添加的新车友信息写入文件尾
	fclose(fp);
	cout<<"新车友信息添加完毕"<<endl;	
}
void main()
{
	system("color F0");
	//改变背景色为亮白色，前景色为黑色
	int l,x;
	struct cheyou cy[100];
	char s[2],password[5];
	cout<<"请输入口令："<<endl;
	//口令验证
	cin>>password;
	while (strcmp(password,"123")!=0)
	{
		cout<<"密码错误，请重新输入密码："<<endl;
		cin>>password;
	}
	system("cls");
	//清理屏幕
	do
	{
		l=0;
		FILE *fp1;
		fp1=fopen("D:\\cheyou.txt","rb");
		if (!fp1)
		{
			cout<<"文件打开失败"<<endl;
			exit(1);
		}
		else
		{	
			fscanf(fp1,"%s%s%d%s%d%d%s%s%s%s%s",&cy[l].name,&cy[l].nickname,&cy[l].sex,&cy[l].job,&cy[l].age,&cy[l].driveage,&cy[l].brand,&cy[l].type,&cy[l].colour,&cy[l].modle,&cy[l].price);//将文件中数据读入结构体数组中
			while(!feof(fp1))
			{
				l++;
				//累加求会员数
				fscanf(fp1,"%s%s%d%s%d%d%s%s%s%s%s",&cy[l].name,&cy[l].nickname,&cy[l].sex,&cy[l].job,&cy[l].age,&cy[l].driveage,&cy[l].brand,&cy[l].type,&cy[l].colour,&cy[l].modle,&cy[l].price);
			}
			l++;
		}
		fclose(fp1);
		cout<<"==欢迎进入车友管理系统=="<<endl;
		cout<<"请选择："<<endl<<"1.输出所有车友信息"<<endl<<"2.增加车友信息"<<endl<<"3.删除车友信息"<<endl;
		cout<<"4.按照车款查询车友"<<endl<<"5.查询会员总数"<<endl<<"6.查询某一品牌车友数"<<endl<<"7.查找女性车友信息"<<endl<<"8.查找男性车友信息"<<endl<<"9.查询某一车价车友"<<endl<<"10.查询某一发动机型号车友"<<endl;
		cin>>x;
		switch(x)//用switch-case语句进入各个子函数进行操作
		{
		case 1:
			system("cls");
			PrintAll(cy,l-1);
			break;
		case 2:
			system("cls");
			Add(cy,l);
			break;
		case 3:
			system("cls");
			Delete(cy,l);
			break;
		case 4:
			system("cls");
			FindByType(cy,l);
			break;
		case 5:
			system("cls");
			cout<<"共有会员"<<l-1<<"个"<<endl;
			//已经在读出文件中数据时计算过会员数，故不必再写一个函数统计会员数
			break;
		case 6:
			system("cls");
			CountByBrand(cy,l);
			break;
		case 7:
			system("cls");
			FindFemale(cy,l);
			break;
		case 8:
			system("cls");
			FindMale(cy,l);
			break;
		case 9:
			system("cls");
			FindByPrice(cy,l);
			break;
		case 10:
			system("cls");
			FindByModle(cy,l);
			break;
		}
		cout<<"是否继续进行操作？是Y/否N"<<endl;
		cin>>s;
		system("cls");
	}
	while (strcmp(s,"Y")==0);
	cout<<"感谢使用本系统，您已退出！"<<endl;
	//当退出后给出退提示
}
