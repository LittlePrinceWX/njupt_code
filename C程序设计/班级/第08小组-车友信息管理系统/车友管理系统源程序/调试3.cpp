#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
//����ṹ�峵��
struct cheyou
{
	char name[20];
	//��Ա��
	char nickname[20];
	//��Ա�ǳ�
	char job[20];
	//��Աְҵ
	char brand[20];
	//����Ʒ��
	char type[20];
	//����
	char colour[20];
	//��ɫ
	char price[20];
	//����
	char modle[20];
	//�������ͺ�
	int sex;
	//�Ա�
	int age;
	//����
	int driveage;
	//����
};

//�����������������ѵ�λ��
void change(int a,int b,struct cheyou *f)
//a,b��ʾ��Ҫ�����������������е�λ��
{
	int p;
	char q[20];
	strcpy(q,f[a].name);
	//����strcpy��������
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
//�������С�����������
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
		//����change�������������е�������Ա
	}
	cout<<"��Ա��"<<"\t"<<"�ǳ�"<<"\t"<<"�Ա�"<<"\t"<<"ְҵ"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"Ʒ��"<<"\t"<<"����"<<"\t"<<"��ɫ"<<"\t"<<"\t"<<"�ͺ�"<<"\t"<<"����"<<"\t"<<endl;
	for(x=0;x<l;x++)
	{
		cout<<p[x].name<<"\t";
		cout<<p[x].nickname<<"\t";
		if (p[x].sex==0)
			cout<<"��"<<"\t";
		else
			cout<<"Ů"<<"\t";
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
//��ѯŮ�Գ�����Ϣ
void FindFemale(struct cheyou *cy,int l)
{
	int x=0;
	cout<<"Ů�Ի�Ա��Ϣ"<<endl;
	cout<<"��Ա��"<<"\t"<<"�ǳ�"<<"\t"<<"ְҵ"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"Ʒ��"<<"\t"<<"����"<<"\t"<<"��ɫ"<<"\t"<<"�ͺ�"<<"\t"<<"����"<<"\t"<<endl;
	while (x<l)
	{
		if (cy[x].sex==1)
			//ѭ�������Ů��
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
//��ѯ���Գ�����Ϣ
void FindMale(struct cheyou *cy,int l)
{
	int y=0;
	cout<<"���Ի�Ա��Ϣ"<<endl;
	cout<<"��Ա��"<<"\t"<<"�ǳ�"<<"\t"<<"ְҵ"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"Ʒ��"<<"\t"<<"����"<<"\t"<<"��ɫ"<<"\t"<<"\t"<<"�ͺ�"<<"\t"<<"����"<<"\t"<<endl;
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


//���ճ��Ͳ���
void FindByType(struct cheyou *p,int l)
{
	char t[20];
	int x=0,a=0;
	cout<<"��������Ҫ��ѯ�ĳ��ͣ�"<<endl;
	cin>>t;
	for(x=0;x<l;x++)
		if (strcmp(p[x].type,t)==0)
				a++;
	if (a!=0)
	{
		cout<<"���������ĳ����У�"<<endl;
		cout<<"��Ա��"<<"\t"<<"�ǳ�"<<"\t"<<"�Ա�"<<"\t"<<"ְҵ"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"Ʒ��"<<"\t"<<"����"<<"\t"<<"��ɫ"<<"\t"<<"\t"<<"�ͺ�"<<"\t"<<"����"<<"\t"<<endl;
		for(x=0;x<l-1;x++)
		{
			if (strcmp(p[x].type,t)==0)
			{
				cout<<p[x].name<<"\t";
				cout<<p[x].nickname<<"\t";
				if (p[x].sex==0)
					cout<<"��"<<"\t";
				else
					cout<<"Ů"<<"\t";
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
		cout<<"û�з��������ĳ���"<<endl;
}
//���շ������ͺŲ���
void FindByModle(struct cheyou *p,int l)
{
	char t[20];
	int x=0,a=0;
	cout<<"��������Ҫ��ѯ���ͺţ�"<<endl;
	cin>>t;
	for(x=0;x<l;x++)
		if (strcmp(p[x].modle,t)==0)
				a++;
	if (a!=0)
	{
		cout<<"���������ĳ����У�"<<endl;
		cout<<"��Ա��"<<"\t"<<"�ǳ�"<<"\t"<<"�Ա�"<<"\t"<<"ְҵ"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"Ʒ��"<<"\t"<<"����"<<"\t"<<"��ɫ"<<"\t"<<"�ͺ�"<<"\t"<<"����"<<"\t"<<endl;
		for(x=0;x<l-1;x++)
		{
			if (strcmp(p[x].modle,t)==0)
			{
				cout<<p[x].name<<"\t";
				cout<<p[x].nickname<<"\t";
				if (p[x].sex==0)
					cout<<"��"<<"\t";
				else
					cout<<"Ů"<<"\t";
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
		cout<<"û�з��������ĳ���"<<endl;
}
//���ճ��۲���
void FindByPrice(struct cheyou *p,int l)
{
	char t[20];
	int x=0,a=0;
	cout<<"��������Ҫ��ѯ�ĳ��ۣ�"<<endl;
	cin>>t;
	for(x=0;x<l;x++)
		if (strcmp(p[x].price,t)==0)
				a++;
	if (a!=0)
	{
		cout<<"���������ĳ����У�"<<endl;
		cout<<"��Ա��"<<"\t"<<"�ǳ�"<<"\t"<<"�Ա�"<<"\t"<<"ְҵ"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"Ʒ��"<<"\t"<<"����"<<"\t"<<"��ɫ"<<"\t"<<"�ͺ�"<<"\t"<<"����"<<"\t"<<endl;
		for(x=0;x<l-1;x++)
		{
			if (strcmp(p[x].price,t)==0)
			{
				cout<<p[x].name<<"\t";
				cout<<p[x].nickname<<"\t";
				if (p[x].sex==0)
					cout<<"��"<<"\t";
				else
					cout<<"Ů"<<"\t";
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
		cout<<"û�з��������ĳ���"<<endl;
}
//��Ʒ�Ƽ��㳵����
void CountByBrand(struct cheyou *p,int l)
{
	int x=0,m=0;
	//m��ʾ���������ĳ�����
	char t[20];
	cout<<"��������Ҫ��ѯ��Ʒ��"<<endl;
	cin>>t;
	while (x<l)
	{
		if (strcmp(p[x].brand,t)==0)
		{	m++;
		cout<<p[x].name<<"\t";
				cout<<p[x].nickname<<"\t";
					if (p[x].sex==0)
					cout<<"��"<<"\t";
				else
					cout<<"Ů"<<"\t";
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
	cout<<"���������ĳ�����"<<m<<"��"<<endl;
}
//�����ͼ��㳵����
void CountByType(struct cheyou *p,int l)
{
	int x=0,m=0;
	//m��ʾ���������ĳ�����
	char t[20];
	cout<<"��������Ҫ��ѯ�ĳ���"<<endl;
	cin>>t;
	while (x<l)
	{
		if (strcmp(p[x].type,t)==0)
		{
			m++;
		cout<<p[x].name<<"\t";
				cout<<p[x].nickname<<"\t";
					if (p[x].sex==0)
					cout<<"��"<<"\t";
				else
					cout<<"Ů"<<"\t";
					cout<<p[x].job<<"\t";
					cout<<p[x].age<<"\t";
					cout<<p[x].driveage<<"\t";
					cout<<p[x].brand<<"\t";
					cout<<p[x].type<<"\t";
					cout<<p[x].name<<"\t"<<endl;}
		x++;
	}
	cout<<"���������ĳ�����"<<m<<"��"<<endl;
}
//ɾ��������Ϣ
void Delete(struct cheyou *p,int &l)
{
	char t[20];
	int x=0,i,a=0;
	FILE *fp2;
	cout<<"��������Ҫ�˻�Ļ�Ա����"<<endl;
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
					//��Ҫɾ���ĳ�Ա��������β
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
				cout<<"�ļ���ʧ��"<<endl;
				exit(1);
			}
			else
			for(i=0;i<l-1;i++)
				//�������ȥ���һλ����д���ļ�
				fprintf(fp2,"%s %s %d %s %d %d %s %s %s %s %s\n",p[i].name,p[i].nickname,p[i].sex,p[i].job,p[i].age,p[i].driveage,p[i].brand,p[i].type,p[i].colour,p[i].price,p[i].modle);
			fclose(fp2);
			cout<<"��Ա��ɾ��"<<endl;
	}
	else
		cout<<"�����ڸû�Ա"<<endl;
}
//����³�����Ϣ
void Add(struct cheyou *a,int &l)
{
	FILE *fp;
	fp=fopen("cheyou.dat","ab+");
	if (!fp)
	{
		cout<<"�ļ���ʧ��"<<endl;
		exit(1);
	}
	cout<<"����������ӳ��ѵ���Ϣ"<<endl;
	cout<<"�������Ա��"<<endl;
	cin>>a[l].name;
	cout<<"�������Ա�ǳ�"<<endl;
	cin>>a[l].nickname;
	cout<<"�������Ա�Ա�0Ϊ�� 1ΪŮ��"<<endl;
	cin>>a[l].sex;
	while ((a[l].sex!=1)&&(a[l].sex!=0))
	{
		cout<<"�����Ա𲻺Ϸ������������룺"<<endl;
		cin>>a[l].sex;
	}
	cout<<"�������Աְҵ"<<endl;
	cin>>a[l].job;
	cout<<"�������Ա����"<<endl;
	cin>>a[l].age;
	while (a[l].age<=18)
	{
		cout<<"���䲻�Ϸ�,��������������"<<endl;
		cin>>a[l].age;
	}
	cout<<"�������Ա����"<<endl;
	cin>>a[l].driveage;
	while ((a[l].age-a[l].driveage)<18)
	{
		cout<<"���䲻�Ϸ����������������"<<endl;
		cin>>a[l].driveage;
	}
	cout<<"�����복��Ʒ��"<<endl;
	cin>>a[l].brand;
	cout<<"�����복��"<<endl;
	cin>>a[l].type;
	cout<<"�����복����ɫ"<<endl;
	cin>>a[l].colour;
	cout<<"�����뷢�����ͺ�"<<endl;
	cin>>a[l].modle;
	cout<<"�����복��"<<endl;
	cin>>a[l].price;
	fprintf(fp,"%s %s %d %s %d %d %s %s %s %s %s %s\n",a[l].name,a[l].nickname,a[l].sex,a[l].job,a[l].age,a[l].driveage,a[l].brand,a[l].type,a[l].colour,a[l].modle,a[l].price);//����ӵ��³�����Ϣд���ļ�β
	fclose(fp);
	cout<<"�³�����Ϣ������"<<endl;	
}
void main()
{
	system("color F0");
	//�ı䱳��ɫΪ����ɫ��ǰ��ɫΪ��ɫ
	int l,x;
	struct cheyou cy[100];
	char s[2],password[5];
	cout<<"��������"<<endl;
	//������֤
	cin>>password;
	while (strcmp(password,"123")!=0)
	{
		cout<<"��������������������룺"<<endl;
		cin>>password;
	}
	system("cls");
	//������Ļ
	do
	{
		l=0;
		FILE *fp1;
		fp1=fopen("D:\\cheyou.txt","rb");
		if (!fp1)
		{
			cout<<"�ļ���ʧ��"<<endl;
			exit(1);
		}
		else
		{	
			fscanf(fp1,"%s%s%d%s%d%d%s%s%s%s%s",&cy[l].name,&cy[l].nickname,&cy[l].sex,&cy[l].job,&cy[l].age,&cy[l].driveage,&cy[l].brand,&cy[l].type,&cy[l].colour,&cy[l].modle,&cy[l].price);//���ļ������ݶ���ṹ��������
			while(!feof(fp1))
			{
				l++;
				//�ۼ����Ա��
				fscanf(fp1,"%s%s%d%s%d%d%s%s%s%s%s",&cy[l].name,&cy[l].nickname,&cy[l].sex,&cy[l].job,&cy[l].age,&cy[l].driveage,&cy[l].brand,&cy[l].type,&cy[l].colour,&cy[l].modle,&cy[l].price);
			}
			l++;
		}
		fclose(fp1);
		cout<<"==��ӭ���복�ѹ���ϵͳ=="<<endl;
		cout<<"��ѡ��"<<endl<<"1.������г�����Ϣ"<<endl<<"2.���ӳ�����Ϣ"<<endl<<"3.ɾ��������Ϣ"<<endl;
		cout<<"4.���ճ����ѯ����"<<endl<<"5.��ѯ��Ա����"<<endl<<"6.��ѯĳһƷ�Ƴ�����"<<endl<<"7.����Ů�Գ�����Ϣ"<<endl<<"8.�������Գ�����Ϣ"<<endl<<"9.��ѯĳһ���۳���"<<endl<<"10.��ѯĳһ�������ͺų���"<<endl;
		cin>>x;
		switch(x)//��switch-case����������Ӻ������в���
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
			cout<<"���л�Ա"<<l-1<<"��"<<endl;
			//�Ѿ��ڶ����ļ�������ʱ�������Ա�����ʲ�����дһ������ͳ�ƻ�Ա��
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
		cout<<"�Ƿ�������в�������Y/��N"<<endl;
		cin>>s;
		system("cls");
	}
	while (strcmp(s,"Y")==0);
	cout<<"��лʹ�ñ�ϵͳ�������˳���"<<endl;
	//���˳����������ʾ
}
