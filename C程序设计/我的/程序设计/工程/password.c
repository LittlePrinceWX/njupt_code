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
	printf("\t\t**\t\t1.�����޸�                       **\n");
	printf("\t\t**\t\t2.��¼                           **\n");
	printf("\t\t***************************************************\n");
	printf("\t\t***************************************************\n");
	printf("������������Ҫ��ѡ�1,2����");
	scanf("%d",&p); 
	return p;
}


void Input_Password ()
{
	printf("\t\t\t��������λ��ԭ���룺");
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
	printf("\t\t\t���������������룺");
	for (int i=0;i<6;i++)
	{
		c[i]=getchar();
		if(c[i]>='0'||c[i]<='9'||c[i]>='a'||c[i]<='z'||c[i]>='A'||c[i]<='Z')
			putchar('*');
    }
	getchar();		
    printf("\t\t\t��ȷ�����������룺");
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
	fp1=fopen("D:\\Management_System\\����.txt","r"); 
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
				printf("ϵͳ�����ر�\n");
				system("pause");
				//exit(1);
			}
		}
		fp2=fopen("D:\\����.txt","w");
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
		printf("\t\t\t�����޸ĳɹ�!\n");	
	}
	else
	{
		printf("\t\t\t�������\n");
		k++;
		if(k>=3)
		{
			printf("ϵͳ�����ر�\n");
			system("pause");
			//exit(1);
		}		
	}
}



void Passwoord_Verify ()
{
	FILE *fp3;
	fp3=fopen("D:\\Management_System\\����.txt","r");
	
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
		printf("\t\t\t��������λ������: ");
		for (int j=0;j<6;j++)
		{
			f[j]=getchar();
			if(f[j]>='0'||f[j]<='9'||f[j]>='a'||f[j]<='z'||f[j]>='A'||f[j]<='Z')
				putchar('*');
		}
		getchar();
		if(e[0]==f[0]&&e[1]==f[1]&&e[2]==f[2]&&e[3]==f[3]&&e[4]==f[4]&&e[5]==f[5])
		{
			printf("\t\t\t\t������ȷ���������֤��\n");
			break;
		}
		if(e[0]!=f[0]||e[1]!=f[1]||e[2]!=f[2]||e[3]!=f[3]||e[4]!=f[4]||e[5]!=f[5])//���������ʱ����
		{
			
			printf("\n����������������룺\n");
			n++;
		}
		if(n>2)
		{
			printf("ϵͳ�����ر�\n");
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
	printf("\t\t**\t\t1.�����޸�                       **\n");
	printf("\t\t**\t\t2.��¼                           **\n");
	printf("\t\t***************************************************\n");
	printf("\t\t***************************************************\n");
	printf("������������Ҫ��ѡ�1,2����");
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

void Verification_code()//��֤�벿��
{
	int p[1]={0};
	int q[1]={0};
	for(int k=0;;)
	{
		srand((unsigned)time(NULL));
		printf("��֤��Ϊ��");
		p[0]=rand() % 1000;        //����0-1000�������
		printf("%d\n",p[0]);
		printf("��������֤�룺");
		scanf("%d",&q[0]);
		getchar();
		if(q[0]==p[0])
		{
			printf("\n��ӭʹ�ã�\n");
			break;
		}
		//system("pause");
		if(k>3)
		{
			printf("ϵͳ�����ر�\n");
			system("pause");
			exit(0);
		}
		k++;
	}

}

int Menu_Select()//��ʾ��ϵͳ���߱��Ĺ���
{
	int c;
	do{
		system("cls");
		printf("\t\t******************************************\n");
		printf("\t\t******************************************\n");
		printf("\t\t**\t��ӭ������֧ͥ������ϵͳ\t**\n");
		printf("\t\t**\t1.����������Ϣ|          \t**\n");
		printf("\t\t**\t2.��ʾ�������|          \t**\n");
		printf("\t\t**\t3.�����������|          \t**\n");
		printf("\t\t**\t4.�˳�ϵͳ|              \t**\n");
		printf("\t\t******************************************\n");
		printf("\t\t******************************************\n");
		printf("\t\t\t���Ӧѡ��ѡ�1-4����");
		scanf("%d",&c);
	}while(c<1||c>8);
	return c;
}







