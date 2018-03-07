
#include<stdio.h>
#include<stdlib.h>
#include"open.h"

struct flight
{
	char ID[20];
	char sta_add[20];
	char arr_add[20];
	char stop_add[20];
	char sta_date[10];
	char sta_time[10];
	float fly_time;
};
typedef struct flight fli;

int bookticket();
int returnticket();
int change_seat09(int l, int r);
int change_seat13(int l, int r);
int change_seat31(int l, int r);
int return_seat09(int l, int r);
int return_seat13(int l, int r);
int return_seat31(int l, int r);

int check(char *ps)     //����ĺ��� �����룩 
{
	char passwd[]="6666"; //�趨�����Ƕ��١�
	int i=0;
	int flag=1;
	for(;*ps!='\0'&& flag;ps++)
	{
		if(*ps>='a' && *ps<='z')
		    *ps=*ps-32+2;
		if(*ps!=passwd[i])
		    flag=0;
		else
		    i++;
	 } 
	return flag;
}


int input_flight(fli *inf)
{
	FILE *fp;
	fp = fopen("C:\\vc\\project_flight\\flight_file\\input_flight.txt","w");
	if(fp == 0)
	{
		printf("��ʧ��!\n");
		return 1;
		exit(1);
	}
	fwrite(inf,sizeof(*inf),1,fp);
	fclose(fp);
	return 0;
}

void read_inform()                                              //������п�Ԥ��������Ϣ
{
	FILE *fp;
	char ch;
	fp = fopen("C:\\vc\\project_flight\\flight_file\\flight_file_total.txt","r");
	if(fp == 0)
	{
		printf("error file\n");
		exit(1);
	}
	while((ch = fgetc(fp)) != EOF)
	{
		putchar(ch);
	}
	putchar('\n');
	fclose(fp);
    open_input();	
}

void buy_back_ticket()                                       //��Ʊ����Ʊѡ����
{
    int choice;
	int judge1 = 0;
	int judge2 = 1;
	int jud;
	printf("************************************************\n");
	printf("**************��ӭ���붩Ʊ����Ʊϵͳ************\n");
	printf("---------------->��������������<----------------\n");
	printf("---------------->1. Ԥ����Ʊ\n");
	printf("---------------->2. �˶���Ʊ\n");
	while(1)
	{
	    scanf("%d",&choice);
		if(1 == choice)
		{
			judge1 = bookticket();
			if(judge1 == 1)
			{
				printf("����ʧ��!\n");
				continue;
			}
			break;
		}
		if(2 == choice)
		{
			printf("��Ʊ��Ϣ����Ʊ���ᷣ��ԭ�ۻ�Ʊ��30%%���Ƿ�ȷ��������Ʊ?\n");
			printf("ȷ��������1������������2:\n");
			scanf("%d",&jud);
			if(1 == jud)
			{
			    judge2 = returnticket();
			    if(judge2 == 0)
				{
				    printf("����ʧ��!\n");
				    continue;
				}
			    break;
			}
			if(2 == jud)
			{
				break;
			}
			else
			{
			        printf("�������!\n");
                    printf("��������������:\n");
	                printf("1. Ԥ����Ʊ\n");
        	        printf("2. �˶���Ʊ\n"); 
			        continue;
			}
		}
	}
}

int change_seat09(int l, int r)
{
    FILE *fp;
	int lo;
	int i = 0;
	char ch;
	int judge = 0;
	if(l == 1)
	{
        lo = r;
	}
	if(l == 2)
	{
		lo = r+7;
	}
	if(l == 3)
	{
		lo = r+14;
	}
	if(l == 4)
	{
		lo = r+21;
	}
	if(l == 5)
	{
		lo = r+28;
	}
	fp = fopen("C:\\vc\\project_flight\\flight_file\\seat_09.txt","r+");
	if(fp == 0)
	{
		printf("��ʧ��!\n");
		exit(1);
	}
	while(i != lo)
	{
        i++;
		ch = fgetc(fp);
	}
	if(ch == '1')
	{
		judge = 1;
	}
	else{
		ch = '1';
		fseek(fp, -1L, 1);
		fputc(ch, fp);
		fflush(fp);
	}
	fclose(fp);
	return judge;
}

int change_seat13(int l, int r)
{
    FILE *fp;
	int lo;
	int i = 0;
	char ch;
	int judge = 0;
	if(l == 1)
	{
        lo = r;
	}
	if(l == 2)
	{
		lo = r+7;
	}
	if(l == 3)
	{
		lo = r+14;
	}
	if(l == 4)
	{
		lo = r+21;
	}
	if(l == 5)
	{
		lo = r+28;
	}
	fp = fopen("C:\\vc\\project_flight\\flight_file\\seat_13.txt","r+");
	if(fp == 0)
	{
		printf("��ʧ��!\n");
		exit(1);
	}
	while(i != lo)
	{
        i++;
		ch = fgetc(fp);
	}
	if(ch == '1')
	{
		judge = 1;
	}
	else{
		ch = '1';
		fseek(fp, -1L, 1);
		fputc(ch, fp);
		fflush(fp);
	}
	fclose(fp);
	return judge;
}

int change_seat31(int l, int r)
{
    FILE *fp;
	int lo;
	int i = 0;
	char ch;
	int judge = 0;
	if(l == 1)
	{
        lo = r;
	}
	if(l == 2)
	{
		lo = r+7;
	}
	if(l == 3)
	{
		lo = r+14;
	}
	if(l == 4)
	{
		lo = r+21;
	}
	if(l == 5)
	{
		lo = r+28;
	}
	fp = fopen("C:\\vc\\project_flight\\flight_file\\seat_31.txt","r+");
	if(fp == 0)
	{
		printf("��ʧ��!\n");
		exit(1);
	}
	while(i != lo)
	{
        i++;
		ch = fgetc(fp);
	}
	if(ch == '1')
	{
		judge = 1;
	}
	else{
		ch = '1';
		fseek(fp, -1L, 1);
		fputc(ch, fp);
		fflush(fp);
	}
	fclose(fp);
	return judge;
}

int return_seat09(int l,int r)
{
    FILE *fp;
	int lo;
	int i = 0;
	char ch;
	int judge = 0;
	if(l == 1)
	{
        lo = r;
	}
	if(l == 2)
	{
		lo = r+7;
	}
	if(l == 3)
	{
		lo = r+14;
	}
	if(l == 4)
	{
		lo = r+21;
	}
	if(l == 5)
	{
		lo = r+28;
	}
	fp = fopen("C:\\vc\\project_flight\\flight_file\\seat_09.txt","r+");
	if(fp == 0)
	{
		printf("��ʧ��!\n");
		exit(1);
	}
	while(i != lo)
	{
        i++;
		ch = fgetc(fp);
	}
	if(ch == '0')
	{
		judge = 1;
	}
	else{
		ch = '0';
		fseek(fp, -1L, 1);
		fputc(ch, fp);
		fflush(fp);
	}
	fclose(fp);
	return judge;
}

int return_seat13(int l,int r)
{
    FILE *fp;
	int lo;
	int i = 0;
	char ch;
	int judge = 0;
	if(l == 1)
	{
        lo = r;
	}
	if(l == 2)
	{
		lo = r+7;
	}
	if(l == 3)
	{
		lo = r+14;
	}
	if(l == 4)
	{
		lo = r+21;
	}
	if(l == 5)
	{
		lo = r+28;
	}
	fp = fopen("C:\\vc\\project_flight\\flight_file\\seat_13.txt","r+");
	if(fp == 0)
	{
		printf("��ʧ��!\n");
		exit(1);
	}
	while(i != lo)
	{
        i++;
		ch = fgetc(fp);
	}
	if(ch == '0')
	{
		judge = 1;
	}
	else{
		ch = '0';
		fseek(fp, -1L, 1);
		fputc(ch, fp);
		fflush(fp);
	}
	fclose(fp);
	return judge;
}

int return_seat31(int l, int r)
{
	FILE *fp;
	int lo;
	int i = 0;
	char ch;
	int judge = 0;
	if(l == 1)
	{
        lo = r;
	}
	if(l == 2)
	{
		lo = r+7;
	}
	if(l == 3)
	{
		lo = r+14;
	}
	if(l == 4)
	{
		lo = r+21;
	}
	if(l == 5)
	{
		lo = r+28;
	}
	fp = fopen("C:\\vc\\project_flight\\flight_file\\seat_31.txt","r+");
	if(fp == 0)
	{
		printf("��ʧ��!\n");
		exit(1);
	}
	while(i != lo)
	{
        i++;
		ch = fgetc(fp);
	}
	if(ch == '0')
	{
		judge = 1;
	}
	else{
		ch = '0';
		fseek(fp, -1L, 1);
		fputc(ch, fp);
		fflush(fp);
	}
	fclose(fp);
	return judge;
}

int bookticket()                                             //��Ʊ����
{
    int ch;
	int line;
	int j;
	int row;
	printf("******---flight B16010809 ���Ϻ��������---******\n");
	printf("******---flight B16010813 ��������������---******\n");
	printf("******---flight B16010831 �ӱ�������Ī˹��-******\n");
	printf("����������Ҫ���������β��2λ:\n");
	scanf("%d",&ch);
	while(1)
	{
		if(9 == ch)
		{
			printf("���Ǹú������λ���:\n");
			printf("(0�����λ��1���������˶���):\n");
			open_seat_09();
			printf("�밴�ź��е�˳������������ѡ�����λ,�м��ö��Ÿ���:\n");
			scanf("%d,%d",&line,&row);
			if((line>5)||(line<1))
			{
				printf("������������������:\n");
				continue;
			}
			else if((row>6)||(row<1))
			{
				printf("������������������:\n");
				continue;
			}
            j = change_seat09(line,row);
			if(j == 0)
			{
                printf("-------->��Ʊ�ɹ�!\n");
				break;
			}
			else{
				printf("-------->��Ʊʧ�ܣ���λ�������˶���!\n");
				printf("-------->��������������ѡ���λ��:\n");
				continue;
			}
		}
		if(13 == ch)
		{
            printf("���Ǹú������λ���:\n");
			printf("(0�����λ��1���������˶���):\n");
			open_seat_13();
			printf("����������Ҫ��������λ��:\n");
			scanf("%d,%d",&line,&row);
			if((line>5)||(line<1))
			{
				printf("������������������:\n");
				continue;
			}
			else if((row>6)||(row<1))
			{
				printf("������������������:\n");
				continue;
			}
		    j = change_seat13(line,row);
			if(j == 0)
			{
                printf("-------->��Ʊ�ɹ�!\n");
				break;
			}
			else{
				printf("-------->��Ʊʧ�ܣ���λ�������˶���!\n");
				printf("-------->��������������ѡ���λ��:\n");
				continue;
			}
		}
		if(31 == ch)
		{
			printf("���Ǹú������λ���:\n");
			printf("(0�����λ��1���������˶���):\n");
			open_seat_31();
			printf("����������Ҫ��������λ��:\n");
			scanf("%d,%d",&line,&row);
			if((line>5)||(line<1))
			{
				printf("������������������:\n");
				continue;
			}
			else if((row>6)||(row<1))
			{
				printf("������������������:\n");
				continue;
			}
            j = change_seat31(line,row);
			if(j == 0)
			{
                printf("-------->��Ʊ�ɹ�!\n");
				break;
			}
			else{
				printf("-------->��Ʊʧ�ܣ���λ�������˶���!\n");
				printf("-------->��������������ѡ���λ��:\n");
				continue;
			}
		}
	}
	return j;
}

int returnticket()                                       //��Ʊ����
{
    int flight;
    int re_li;
	int re_ro;
	int re_j;
	printf("******---flight B16010809 ���Ϻ��������---******\n");
	printf("******---flight B16010813 ��������������---******\n");
	printf("******---flight B16010831 �ӱ�������Ī˹��-******\n");
	printf("����������Ҫ�˶������β��2λ:\n");
	scanf("%d",&flight);
	while(1)
	{
		if(9 == flight)
		{
			printf("�����Ǹú������λ���:\n");
			printf("(0�����λ��1���������˶���):\n");
			open_seat_09();
			printf("���������Ѷ�����λ����λ��,�м��ö��Ÿ���:\n");
			scanf("%d,%d",&re_li,&re_ro);
			if((re_li>5)||(re_li<1))
			{
				printf("������������������:\n");
				continue;
			}
			else if((re_ro>6)||(re_ro<1))
			{
				printf("������������������:\n");
				continue;
			}
			re_j = return_seat09(re_li, re_ro);
			if(re_j == 1)
			{
				printf("��Ʊʧ��,����λ��δ���˶���\n");
				printf("�������������ĺ���β��2λ:\n");
				continue;
			}
			else{
				printf("�˶��ɹ����˿�ڿ۳��������24Сʱ֮���˻�!\n");
				break;
			}
		}
		if(13 == flight)
		{
			printf("�����Ǹú������λ���:\n");
			printf("(0�����λ��1���������˶���):\n");
			open_seat_13();
			printf("���������Ѷ�����λ����λ��:\n");
			scanf("%d,%d",&re_li,&re_ro);
			if((re_li>5)||(re_li<1))
			{
				printf("������������������:\n");
				continue;
			}
			else if((re_ro>6)||(re_ro<1))
			{
				printf("������������������:\n");
				continue;
			}
			re_j = return_seat13(re_li, re_ro);
			if(re_j == 1)
			{
				printf("��Ʊʧ��,����λ��δ���˶���\n");
				printf("�������������ĺ���β��2λ:\n");
				continue;
			}
			else{
				printf("�˶��ɹ����˿�ڿ۳��������24Сʱ֮���˻�!\n");
				break;
			}
		}
		if(31 == flight)
		{
			printf("�����Ǹú������λ���:\n");
			printf("(0�����λ��1���������˶���):\n");
			open_seat_31();
			printf("���������Ѷ�����λ����λ��:\n");
			scanf("%d,%d",&re_li,&re_ro);
			if((re_li>5)||(re_li<1))
			{
				printf("������������������:\n");
				continue;
			}
			else if((re_ro>6)||(re_ro<1))
			{
				printf("������������������:\n");
				continue;
			}
			re_j = return_seat31(re_li, re_ro);
			if(re_j == 1)
			{
				printf("��Ʊʧ��,����λ��δ���˶���\n");
				printf("�������������ĺ���β��2λ:\n");
				continue;
			}
			else{
				printf("�˶��ɹ����˿�ڿ۳��������24Сʱ֮���˻�!\n");
				break;
			}
		}
	}
    return 1;
}

void find_inform()                                     //�����ѯ����
{
	int choice;
	int fli_id;
	int time_c;
	int start_c;
	printf("***************************************\n");
    printf("******---��ӭ���뺽���ѯϵͳ!---******\n");
	printf("******-------��������ѡ��:-------******\n");
	printf("******------1.������Ų�ѯ;------******\n");
	printf("******-----2.�����ʱ���ѯ;-----******\n");
    printf("******------3.�������ز�ѯ;------******\n");
	printf("***************************************\n");
	while(1)
	{
		printf("----->������������Ҫ��ѯ����Ŀ:\n");
		scanf("%d",&choice);
		if(choice>3||choice<1)
		{
			printf("�����������������:\n");
			continue;
		}
		if(1 == choice)
		{
			printf("�����º���ţ�������һ�������ĩβ��λ:\n");
			printf("---------->B16010809\n");
			printf("---------->B16010813\n");
			printf("---------->B16010831\n");
			scanf("%d",&fli_id);
			if(9 == fli_id)
			{
			    printf("������������ѯ�ĺ�����Ϣ:\n");
				printf("����� ������ Ŀ�ĵ� �������� ���ʱ�� ��ͣ���У�0Ϊ�ޣ� Ԥ�Ʒ���ʱ��\n");
				open_flight_09();
				break;
			}
			if(13 == fli_id)
			{
				printf("������������ѯ�ĺ�����Ϣ:\n");
				printf("����� ������ Ŀ�ĵ� �������� ���ʱ�� ��ͣ���У�0Ϊ�ޣ� Ԥ�Ʒ���ʱ��\n");
				open_flight_13();
				break;
			}
			if(31 == fli_id)
			{
				printf("������������ѯ�ĺ�����Ϣ:\n");
				printf("����� ������ Ŀ�ĵ� �������� ���ʱ�� ��ͣ���У�0Ϊ�ޣ� Ԥ�Ʒ���ʱ��\n");
				open_flight_31();
				break;
			}
			else{
				printf("������������������:\n");
				continue;
			}
		}
		if(2 == choice)
		{
			printf("�����Ǹû����ɲ�ѯ��������ʱ��:\n");
			printf("---1---------->2017.9.31   01:15\n");
            printf("---2---------->2017.9.11   15:21\n");
            printf("---3---------->2017.9.22   02:42\n");
			printf("����������Ҫ��ѯ�����ʱ������:\n");
			scanf("%d",&time_c);
			if("time_c == 1")
			{
			    printf("������������ѯ�ĺ�����Ϣ:\n");
				printf("����� ������ Ŀ�ĵ� �������� ���ʱ�� ��ͣ���У�0Ϊ�ޣ� Ԥ�Ʒ���ʱ��\n");
				open_flight_09();
				break;
			}
			if("time_c == 2")
			{
			    printf("������������ѯ�ĺ�����Ϣ:\n");
				printf("����� ������ Ŀ�ĵ� �������� ���ʱ�� ��ͣ���У�0Ϊ�ޣ� Ԥ�Ʒ���ʱ��\n");
				open_flight_13();
				break;
			}
			if("time_c == 3")
			{
			    printf("������������ѯ�ĺ�����Ϣ:\n");
				printf("����� ������ Ŀ�ĵ� �������� ���ʱ�� ��ͣ���У�0Ϊ�ޣ� Ԥ�Ʒ���ʱ��\n");
				open_flight_31();
				break;
			}
		}
		if(3 == choice)
		{
			printf("------>��ϵͳ�ɲ�ѯ�ĳ�������:\n");
			printf("------>1.�Ϻ�\n");
			printf("------>2.����\n");
			printf("------>3.����\n");
			printf("------>�������������ѯ�ĳ��������:\n");
			scanf("%d",&start_c);
			if(1 == start_c)
			{
				printf("�����Ǹú������Ϣ:\n");
				printf("����� ������ Ŀ�ĵ� �������� ���ʱ�� ��ͣ���У�0Ϊ�ޣ� Ԥ�Ʒ���ʱ��\n");
				open_flight_09();
				break;
			}
			if(2 == start_c)
			{
				printf("�����Ǹú������Ϣ:\n");
				printf("����� ������ Ŀ�ĵ� �������� ���ʱ�� ��ͣ���У�0Ϊ�ޣ� Ԥ�Ʒ���ʱ��\n");
				open_flight_13();
				break;
			}
			if(3 == start_c)
			{
				printf("�����Ǹú������Ϣ:\n");
				printf("����� ������ Ŀ�ĵ� �������� ���ʱ�� ��ͣ���У�0Ϊ�ޣ� Ԥ�Ʒ���ʱ��\n");
				open_flight_31();
				break;
			}
			else{
				printf("������������������:\n");
				continue;
			}
		}
		else{
			printf("�������!\n");
			continue;
		}
	}
}

void arrange_ID()
{
	fli s1;
	fli s2;
	fli s3;
	FILE *fp9;
	FILE *fp13;
	FILE *fp31;
    int i , j;
	char temp;
	char total[3]; 
	fp9 = fopen("C:\\vc\\project_flight\\flight_file\\flight_file_9.txt","r+");
	if(fp9 == 0)
	{
		printf("error file!\n");
		exit(1);
	}
    fp13 = fopen("C:\\vc\\project_flight\\flight_file\\flight_file_13.txt","r+");
	if(fp13 == 0)
	{
		printf("error file!\n");
		exit(1);
	}
	fp31 = fopen("C:\\vc\\project_flight\\flight_file\\flight_file_31.txt","r+");
    if(fp31 == 0)
	{
		printf("error file!\n");
		exit(1);
	}
    fscanf(fp9 , "%s%s%s%s%s%s%f",&s1.ID,&s1.sta_add,&s1.arr_add,&s1.sta_date,&s1.sta_time,&s1.stop_add,&s1.fly_time);
    fscanf(fp13 , "%s%s%s%s%s%s%f",&s2.ID,&s2.sta_add,&s2.arr_add,&s2.sta_date,&s2.sta_time,&s2.stop_add,&s2.fly_time);
	fscanf(fp31 , "%s%s%s%s%s%s%f",&s3.ID,&s3.sta_add,&s3.arr_add,&s3.sta_date,&s3.sta_time,&s3.stop_add,&s3.fly_time);
    total[0] = s1.ID;
	total[1] = s2.ID;
	total[2] = s3.ID;
	for(i=0;i<2;i++)
	{
		for(j=2;j>i;j--)
		{
            if(total[j]<total[j-1])
			{
				temp = total[j-1];
				total[j-1] = total[j];
				total[j] = temp;
			}
		}
	}
	total[0] = s1.ID;
	total[1] = s2.ID;
	total[2] = s3.ID;
	printf("����Ϊ������:\n");
    printf("%s %s %s %s %s %s %f\n",s1.ID,s1.sta_add,s1.arr_add,s1.sta_date,s1.sta_time,s1.stop_add,s1.fly_time);
	printf("%s %s %s %s %s %s %f\n",s2.ID,s2.sta_add,s2.arr_add,s2.sta_date,s2.sta_time,s2.stop_add,s2.fly_time);
    printf("%s %s %s %s %s %s %f\n",s3.ID,s3.sta_add,s3.arr_add,s3.sta_date,s3.sta_time,s3.stop_add,s3.fly_time);
	fclose(fp9);
    fclose(fp13);
	fclose(fp31);
}


void arrange_inform()
{
	printf("*******************************************\n");
	arrange_ID();
}

void input_inform()                                      //����¼�뺯��
{
    int ju = 0;
	fli s1,*p;
	p = &s1;
	printf("�밴˳�����뺽����Ϣ:\n");
	printf("����� ������ Ŀ�ĵ� �������� ���ʱ�� ��ͣ���У�0Ϊ�ޣ� Ԥ�Ʒ���ʱ��\n");
	scanf("%s,%s,%s,%s,%s,%s,%f",&p->ID,&p->sta_add,&p->arr_add,&p->sta_date,&p->sta_time,&p->stop_add,&p->fly_time);
	ju = input_flight(p);
	if(ju == 0)
	{
	    printf("������Ϣ�ѳɹ�¼�뵽��ϵͳ��!\n");
	}
	else{
		printf("��ʧ��!\n");
	}
}

int main(void)
{
    int judge = 0;                                        //�����ж���������                                    //���봢���ڸ�����                                             
	int choice = 0;                                       //�û�ѡ��                
	int i = 0;                                            
	int a;
	char str[200]; 
	
	    printf("******************************\n");
		printf("\n"); 
		printf("++++++++++����������++++++++++\n");
		printf("\n");
		printf("******************************\n");
	   do{ 
	    while( ( str[i]=getchar() ) != '#' )  //���������������ַ�
		{
			i++;
		} 
		str[i]='\0';
		if(check(str))
		{
			printf("������ȷ!\n");
			a=1;
		}
	
		else
		{
			printf("�������!\n");
			a=0;
		}
		system("cls");
		
       }while(a!=1);

	while(1)
	{
		printf("==========================================================================\n");
		printf("                       **************************\n");
	    printf("                       ***********----***********\n");
	    printf("                       *********--------*********\n");
	    printf("                       *******------------*******\n");
        printf("                       ****---�ɻ���Ʊϵͳ---****\n");                //��ʼ����
	    printf("                       ****--��ӭ�����ϵͳ--****\n");
	    printf("                       ****---��������ѡ��---****\n");
	    printf("                       ****1.������к�����Ϣ****\n");
	    printf("                       ****--2.¼�뺽����Ϣ--****\n");
        printf("                       ****3.��ѯ���к�����Ϣ****\n");
	    printf("                       ****--4.������Ϣ����--****\n");
	    printf("                       ****---5.��Ʊ����Ʊ---****\n");
	    printf("                       *****----------------*****\n");
	    printf("                       *******------------*******\n");
	    printf("                       ***********----***********\n");
	    printf("                       **************************\n");
		printf("==========================================================================\n");
	    printf("������������Ҫ�������Ŀ:\n");
		scanf("%d",&choice);
		if(1==choice)
		{
			printf("�����ǿ��Զ����ĺ������Ϣ:\n");
			printf("����� ������ Ŀ�ĵ� �������� ���ʱ�� ��ͣ���У�0Ϊ�ޣ� Ԥ�Ʒ���ʱ��\n");
			read_inform();
			continue;
		}
		if(2==choice)
		{
			input_inform();
			continue;
		}
		if(3==choice)
		{
			find_inform();
			continue;
		}
		if(4==choice)
		{
			arrange_inform();
			continue;
		}
		if(5==choice)
		{
			buy_back_ticket();
			continue;
		}
		else{
			printf("����������������������������Ҫ����ĳ���:\n");
			continue;
		}
	}
	return 0;
}
