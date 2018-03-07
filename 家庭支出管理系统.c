/***************************************************************
**��Ŀ���ƣ���֧ͥ������ϵͳ 
**���뻷����Dev-C++  
**��Ŀ��д������    B16010810
**          ţ����  B16010811 
**          ��һ��  B16010814
**���ʱ�䣺2017/9/8 
**˵    �����ļ�Ŀ¼��D\Management_System\
**          ��Ŀ¼����  ����.txt 
**                      һ��֧����Ϣ.txt �� ʮ����֧����Ϣ.txt
**                      ��13��txt�ļ� 
****************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<conio.h>

typedef struct       //����ṹ��
{
	char type[20];   //��������
	float money;    //���ѽ��
	char place[20];  //���ѵص�
	int time;        //����ʱ��
}expense;
expense exp[80];

void Mode_1 ();    //����һ *����������Ϣ*
void Mode_2 ();    //���ܶ� *��ʾ�������*
void Mode_3 ();    //������ *�����������*
void Mode_4 ();    //������ *�˳�ϵͳ*
int Passwoord_Menu ();               //����˵�
void Input_Password ();              //�������뺯��
void Set_New_Password();             //���������뺯��
void Password_Change ();             //�޸����뺯��
void Passwoord_Verify ();            //�����¼����
void Password ();                    //���뺯��
void Verification_code();            //��֤�벿��
int Menu_Select();                   //ϵͳ�˵�����ʾ��ϵͳ���߱��Ĺ���
int Inputitmes(expense fm[],int n);      //����������Ϣ
void Save (expense fm[],int n);          //����������Ϣ
void showitems(expense fm[],int n);      //���ĳ�·ݵ�������Ϣ
void Analyseitems(expense fm[],int n);   //������������͵Ľ��ռ�ܽ��İٷֱȲ�����֧����

char a[6]={0},b[6]={0},c[6]={0},d[6]={0},e[6]={0},f[6]={0};   //��������������

int main ()
{
	Password();                 //���뺯��
	Verification_code();        //��֤�뺯��
	for(;;)
	{
		switch(Menu_Select())   //���ò˵�ѡ���������ദ��
		{
			case 1:
				Mode_1();       //ģʽһ
				break;
			case 2:
				Mode_2();       //ģʽ��
				getchar();
				break;
			case 3:
				Mode_3();       //ģʽ��
				getchar();
				break;
			case 4:
				Mode_4();    //ģʽ��
		
		}	
	}

}



void Mode_1 ()    //����һ *����������Ϣ*
{
	int n=0;
	char c;
	printf("\t\t\t��������Ӧ���������\n");
	n=Inputitmes(exp,n);
	printf("\t\t\t��Ҫ����������y\\n�� :");
	getchar();
	scanf("%c",&c);
	if(c=='y'||c=='Y')
		Save(exp,n);
	printf("\t\t\t");
	system("pause");
}

void Mode_2 ()   //���ܶ�*��ʾ�������*
{
	int n=0;
	showitems(exp,n);
}

void Mode_3 ()    //������*�����������*
{
	int n=0;
	Analyseitems(exp,n);
}

void Mode_4 ()    //������*�˳�ϵͳ*
{
	char c;
	printf("\t\t\t��ȷ��Ҫ�˳�����y\\n : ");
	getchar();
	scanf("%c",&c);
	if(c=='y'||c=='Y')
	{
		printf("\t\t\tллʹ�ã�\n");
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
//**************************���뺯������*******************************************//

int Passwoord_Menu ()   //����˵�
{
	int p;
	printf("\t\t***************************************************\n");
	printf("\t\t***************************************************\n");
	printf("\t\t**\t\t1.�����޸�                       **\n");
	printf("\t\t**\t\t2.��¼                           **\n");
	printf("\t\t***************************************************\n");
	printf("\t\t***************************************************\n");
	printf("\t\t������������Ҫ��ѡ�1,2����");
	scanf("%d",&p); 
	getchar();
	return p;
}

void Input_Password ()     //�������뺯��
{
	printf("\t\t\t��������λ��ԭ���룺");
	for (int i=0;i<6;i++)
	{
		b[i]=getch();
		if(b[i]>='0'||b[i]<='9'||b[i]>='a'||b[i]<='z'||b[i]>='A'||b[i]<='Z')
			putchar('*');
    }
    getchar();
}

void Set_New_Password()    //���������뺯��
{
	printf("\t\t\t���������������룺");
	for (int i=0;i<6;i++)
	{
		c[i]=getch();
		if(c[i]>='0'||c[i]<='9'||c[i]>='a'||c[i]<='z'||c[i]>='A'||c[i]<='Z')
			putchar('*');
    }
	getchar();		
    printf("\t\t\t��ȷ�����������룺");
	for (int i=0;i<6;i++)
	{
		d[i]=getch();		
		if(d[i]>='0'||d[i]<='9'||d[i]>='a'||d[i]<='z'||d[i]>='A'||d[i]<='Z')
			putchar('*');
    }	
    getchar();
}

void Password_Change ()            //�޸����뺯��
{
	FILE *fp1,*fp2;
	fp1=fopen("D:\\Management_System\\����.txt","r");   //�������ļ�
	if(!fp1)
	{
		printf("file cannot be opened");
		exit(1);		
	}
	for(int i=0;!feof(fp1);i++)
	{
		a[i]=fgetc(fp1);              //�����ļ����ŵ�ԭʼ����
	}
	fclose(fp1);
	
	for (int k=0;;)
	{
		Input_Password();              //�����������뺯��
		
		if(a[0]==b[0]&&a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3]&&a[4]==b[4]&&a[5]==b[5])  //�Ա�����������ԭʼ����
		{
			for(int n=0;;)
			{
				Set_New_Password();    //�����޸����뺯��
				if(d[0]==c[0]&&d[1]==c[1]&&d[2]==c[2]&&d[3]==c[3]&&d[4]==c[4]&&d[5]==c[5])
				{
					break;              //�޸ĳɹ��˳�forѭ����������һ��
				}
				else
					n++;
				if(n>=3)         //�޸Ĵ��������˳�ϵͳ
				{
					printf("ϵͳ�����ر�\n");
					system("pause");
					exit(1);
				}
			}
			fp2=fopen("D:\\Management_System\\����.txt","w+");   //��д��ʽ�������ļ�
			if(!fp2)
			{
				printf("the file cannot be opened!");
				exit(1);
			}
			for(int j=0;j<6;j++)
			{
				fputc(c[j],fp2);             //д���޸ĵ�������
			}
			fclose(fp2);
			printf("\t\t\t�����޸ĳɹ�!\n");
			break;	
		}
		else
		{
			printf("\t\t\t�������\n");
			k++;			
		}		
		if(k>=3)                         //����������������˳�ϵͳ
		{
			printf("ϵͳ�����ر�\n");
			system("pause");
			exit(1);
		}		
	}
	
}

void Passwoord_Verify ()     //�����¼����
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
			f[j]=getch();
			if(f[j]>='0'||f[j]<='9'||f[j]>='a'||f[j]<='z'||f[j]>='A'||f[j]<='Z')
				putchar('*');
		}
		getchar();
		if(e[0]==f[0]&&e[1]==f[1]&&e[2]==f[2]&&e[3]==f[3]&&e[4]==f[4]&&e[5]==f[5])
		{
			printf("\t\t\t\t������ȷ���������֤��\n");
			break;
		}
		if(e[0]!=f[0]||e[1]!=f[1]||e[2]!=f[2]||e[3]!=f[3]||e[4]!=f[4]||e[5]!=f[5])//�������
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

void Password ()        //���뺯��
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

void Verification_code()      //��֤�벿��
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
		if(k>3)
		{
			printf("ϵͳ�����ر�\n");
			system("pause");
			exit(0);
		}
		k++;
	}

}

int Menu_Select()     //ϵͳ�˵�����ʾ��ϵͳ���߱��Ĺ���
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

//***********************************************************************//
//**************************Mode_1()*************************************//

int Inputitmes(expense fm[],int n)   //����������Ϣ
{
	int i=0;
	char sign='y',x[10];
	while(sign!='n'&&sign!='N')
	{
		printf("\t\t\t����:");
		scanf("\t\t\t%s",fm[n+i].type);
		printf("\t\t\t֧���������㣩:");
		scanf("\t\t\t%f",&fm[n+i].money);
		printf("\t\t\t�ص�:");
		scanf("\t\t\t%s",fm[n+i].place);
		printf("\t\t\tʱ��(0-31):");
		scanf("\t\t\t%d",&fm[n+i].time);
		if(fm[n+i].time<1||fm[n+i].time>31)
			return false;
		gets(x);
		printf("\t\t\t��Ҫ�ٴ�������(y\\n)");
		scanf("\t\t\t%c",&sign);
		i++;
	}
	return(n+i);
}


void Save (expense fm[],int n)    //����������Ϣ
{
	int month,i;
	FILE *fp;
	printf("\t\t�����뵱ǰ��Ϣ�����·ݣ�");
	scanf("%d",&month);
	getchar();
	switch(month)
	{
		case 1:

			fp=fopen("D:\\Management_System\\һ��֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");
			break;
		case 2:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 3:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 4:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 5:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 6:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 7:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 8:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 9:
			fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 10:
			fp=fopen("D:\\Management_System\\ʮ��֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 11:
			fp=fopen("D:\\Management_System\\ʮһ��֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;
		case 12:
			fp=fopen("D:\\Management_System\\ʮ����֧����Ϣ.txt","a+");
			if(fp==NULL)
			{
			    printf("\t\t\tthe file cannot be opened!\n");
				exit(1);
			}
			fseek(fp,-1,SEEK_END);
			for(i=0;i<n;i++)
				fprintf(fp,"%-8s%-12f%-8s%-10d\n",fm[i].type,fm[i].money,fm[i].place,fm[i].time);
			fclose(fp);
			printf("\t\t\t����ɹ�!\n");			
			break;		
	}
}

//******************************************************************************//
//****************************Mode_2()******************************************//

void showitems(expense fm[],int n)   //���ĳ�·ݵ�������Ϣ
{
	int i=0,month;
	FILE *fp;
	printf("\t\t\t��ѡ���·�: ");
	scanf("%d",&month);
	getchar();
	printf("\t\t\t---------------------------------\n");
	printf("\t\t\t����     ֧��     �ص�       ʱ��\n");
	printf("\t\t\t---------------------------------\n");

    switch(month)
    {
		case 1:
		fp=fopen("D:\\Management_System\\һ��֧����Ϣ.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\ʮ��֧����Ϣ.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\ʮһ��֧����Ϣ.txt","r");                                   
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
		fp=fopen("D:\\Management_System\\ʮ����֧����Ϣ.txt","r");                                   
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

void Analyseitems(expense fm[],int n)   //������������͵Ľ��ռ�ܽ��İٷֱȲ�����֧����
{
	float total=0,a=0,income;
	int i=0,j=0,month;
	FILE*fp;
	printf("\t\t\t��ѡ���·ݣ�");
	scanf("%d",&month);
	printf("\n");
	switch(month)
	{
		case 1:
		fp=fopen("D:\\Management_System\\һ��֧����Ϣ.txt","r");
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
		printf("\t\t�����ܽ��Ϊ%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\һ��֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t��Ŀ %-8s   ռ�ܱ� %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t�����뱾������:");
		scanf("%f",&income);
		printf("\t\t������֧��Ϊ   %-10f\n",total/income);
		break;
		
		case 2:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
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
		printf("\t\t�����ܽ��Ϊ%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t��Ŀ  %-8sռ�ܱ�  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t�����뱾������:");
		scanf("%f",&income);
		printf("\t\t������֧��Ϊ   %-10f\n",total/income);
		break;	

		case 3:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
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
		printf("\t\t�����ܽ��Ϊ%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t��Ŀ %-8s   ռ�ܱ� %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t�����뱾������:");
		scanf("%f",&income);
		printf("\t\t������֧��Ϊ   %-10f\n",total/income);
		break;		

		case 4:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
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
		printf("\t\t�����ܽ��Ϊ%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t��Ŀ  %-8s   ռ�ܱ�  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t�����뱾������:");
		scanf("%f",&income);
		printf("\t\t������֧��Ϊ   %-10f\n",total/income);
		break;		

		case 5:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
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
		printf("\t\t�����ܽ��Ϊ%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t��Ŀ %-8s   ռ�ܱ� %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t�����뱾������:");
		scanf("%f",&income);
		printf("\t\t������֧��Ϊ   %-10f\n",total/income);
		break;
		
		case 6:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
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
		printf("\t\t�����ܽ��Ϊ%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t��Ŀ %-8s   ռ�ܱ� %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t�����뱾������:");
		scanf("%f",&income);
		printf("\t\t������֧��Ϊ   %-10f\n",total/income);
		break;
		
		case 7:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
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
		printf("\t\t�����ܽ��Ϊ%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t��Ŀ  %-8s   ռ�ܱ�  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t�����뱾������:");
		scanf("%f",&income);
		printf("\t\t������֧��Ϊ   %-10f\n",total/income);
		break;
		
		case 8:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
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
		printf("\t\t�����ܽ��Ϊ%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t��Ŀ  %-8s   ռ�ܱ�  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t�����뱾������:");
		scanf("%f",&income);
		printf("\t\t������֧��Ϊ    %-10f\n",total/income);
		break;
		
		case 9:
		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
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
		printf("\t\t�����ܽ��Ϊ%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t��Ŀ  %-8sռ�ܱ�  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t�����뱾������:");
		scanf("%f",&income);
		printf("\t\t������֧��Ϊ   %-10f\n",total/income);
		break;
		
		case 10:
		fp=fopen("D:\\Management_System\\ʮ��֧����Ϣ.txt","r");
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
		printf("\t\t�����ܽ��Ϊ%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\ʮ��֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t��Ŀ  %-8s   ռ�ܱ�  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t�����뱾������:");
		scanf("%f",&income);
		printf("\t\t������֧��Ϊ   %-10f\n",total/income);
		break;
		
		case 11:
		fp=fopen("D:\\Management_System\\ʮһ��֧����Ϣ.txt","r");
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
		printf("\t\t�����ܽ��Ϊ%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\ʮһ��֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t��Ŀ  %-8s   ռ�ܱ�  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t�����뱾������:");
		scanf("%f",&income);
		printf("\t\t������֧��Ϊ   %-10f\n",total/income);
		break;
		
		case 12:
		fp=fopen("D:\\Management_System\\ʮ����֧����Ϣ.txt","r");
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
		printf("\t\t�����ܽ��Ϊ%f\n",total);
		printf("\n");

		fp=fopen("D:\\Management_System\\ʮ����֧����Ϣ.txt","r");
	
		while(!feof(fp))
		{
			fscanf(fp,"%s%f%s%d",fm[i].type,&fm[i].money,fm[i].place,&fm[i].time);
			i=i+1;
			n=i;
		}
	
		for(i=0;i<n-1;i++)
		{
			printf("\t\t��Ŀ  %-8s   ռ�ܱ�  %-10f%\n",fm[i].type,fm[i].money/total);
		}
		fclose(fp);
		printf("\n");
		printf("\t\t�����뱾������:");
		scanf("%f",&income);
		printf("\t\t������֧��Ϊ   %-10f\n",total/income);
		break;			
	}
	getchar();
}



