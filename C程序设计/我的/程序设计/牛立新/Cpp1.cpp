typedef struct//����ṹ��
{
	char type[20];//��������
	float Getusm;//���ѽ��
	char place[20];//���ѵص�
	int time;//����ʱ��
}family;
family fam[80];

int menu_select()//��ʾ��ϵͳ���߱��Ĺ���
{
	int c;
	do{
		system("cls");//����
		printf("\t\t��ӭ������֧ͥ������ϵͳ\n");
		printf("\t\t1.����������Ϣ|\n");
		printf("\t\t2.��ʾ�������|\n");
		printf("\t\t3.�����������|\n");
		printf("\t\t4.�˳�ϵͳ|\n");
		printf("\t\t"*****************************************\n");
		printf("\t\t"*****************************************\n");
		printf("\t\t\t���Ӧѡ��ѡ�1-4����");
		scanf("%d",&c);
	}while(c<1||c>8);
	return c;
}

void password()   //�����¼
{
	char d(6);
	char m(6);
	m[0]='1',m[1]='2',m[2]='3',m[3]='4',m[4]='5',m[5]='6';   //����Ƚ�printf��"��������λ�����룺"����//��������
	for (int n=0;;)
	{
		printf("���������룺\n");
		for (int i=0,i<6,i++)
		{
			d[i]=getch();
			if(d[i]>='0'||d[i]<='9'||d[i]<='z'||d[i]>='A'||d[i]<='z')
				putchar('*');
		}
		if(d[0]==m[0]&&d[1]==m[1]&&d[2]==m[2]&&d[3]==m[3]&&d[4]==m[4]&&d[5]==m[5])
		{
			printf("\n\t\t\t������ȷ���������֤��\n");break;
		}
		if(d[0]!=m[0]||d[1]!=m[1]||d[2]!=m[2]||d[3]!=m[3]||d[4]!=m[4]||d[5]!=m[5])//���������ʱ����
			printf("\n����������������룺");
		if(n>3)
		{
			printf("ϵͳ�����ر�\n");
			system("pause");
			exist(0);
		}
		n++
	}
}
void verification_code()//��֤�벿��
{
	int p[1]={0};
	int q[1]={0};
	for(int k=0;;)
	{
		srand(time(NULL));
		printf("��֤��Ϊ��\n");
		p[0]=rand()%1000;//����0-1000�������
		printf("%d",p[0]);
		printf("��������֤�룺");
		scanf("%d",&q[0]);
		if(q=[0]!=p[0])
			printf("\n��ӭʹ�ã�\n");
		system("pause");
		break;
	}
	if(k>3)
	{
		printf("ϵͳ�����ر�\n");
		system("pause");
		exit(0);
	}
	k++
}
}
