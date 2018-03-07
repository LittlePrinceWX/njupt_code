
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

int check(char *ps)     //检验的函数 （密码） 
{
	char passwd[]="6666"; //设定密码是多少。
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
		printf("打开失败!\n");
		return 1;
		exit(1);
	}
	fwrite(inf,sizeof(*inf),1,fp);
	fclose(fp);
	return 0;
}

void read_inform()                                              //浏览所有可预订航班信息
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

void buy_back_ticket()                                       //订票与退票选择函数
{
    int choice;
	int judge1 = 0;
	int judge2 = 1;
	int jud;
	printf("************************************************\n");
	printf("**************欢迎进入订票和退票系统************\n");
	printf("---------------->请输入您的需求<----------------\n");
	printf("---------------->1. 预定机票\n");
	printf("---------------->2. 退订机票\n");
	while(1)
	{
	    scanf("%d",&choice);
		if(1 == choice)
		{
			judge1 = bookticket();
			if(judge1 == 1)
			{
				printf("操作失败!\n");
				continue;
			}
			break;
		}
		if(2 == choice)
		{
			printf("退票信息：退票将会罚款原价机票的30%%，是否确定继续退票?\n");
			printf("确认请输入1，返回请输入2:\n");
			scanf("%d",&jud);
			if(1 == jud)
			{
			    judge2 = returnticket();
			    if(judge2 == 0)
				{
				    printf("操作失败!\n");
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
			        printf("输入错误!\n");
                    printf("请输入您的需求:\n");
	                printf("1. 预定机票\n");
        	        printf("2. 退订机票\n"); 
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
		printf("打开失败!\n");
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
		printf("打开失败!\n");
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
		printf("打开失败!\n");
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
		printf("打开失败!\n");
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
		printf("打开失败!\n");
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
		printf("打开失败!\n");
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

int bookticket()                                             //订票函数
{
    int ch;
	int line;
	int j;
	int row;
	printf("******---flight B16010809 从上海飞往赤峰---******\n");
	printf("******---flight B16010813 从宁波飞往深圳---******\n");
	printf("******---flight B16010831 从北京飞往莫斯科-******\n");
	printf("请输入您所要订购航班的尾号2位:\n");
	scanf("%d",&ch);
	while(1)
	{
		if(9 == ch)
		{
			printf("这是该航班的座位情况:\n");
			printf("(0代表空位，1代表已有人订购):\n");
			open_seat_09();
			printf("请按排和列的顺序输入您所想选择的座位,中间用逗号隔开:\n");
			scanf("%d,%d",&line,&row);
			if((line>5)||(line<1))
			{
				printf("输入有误，请重新输入:\n");
				continue;
			}
			else if((row>6)||(row<1))
			{
				printf("输入有误，请重新输入:\n");
				continue;
			}
            j = change_seat09(line,row);
			if(j == 0)
			{
                printf("-------->订票成功!\n");
				break;
			}
			else{
				printf("-------->订票失败，该位置已有人订购!\n");
				printf("-------->请重新输入您想选择的位置:\n");
				continue;
			}
		}
		if(13 == ch)
		{
            printf("这是该航班的座位情况:\n");
			printf("(0代表空位，1代表已有人订购):\n");
			open_seat_13();
			printf("请输入您所要订购的座位号:\n");
			scanf("%d,%d",&line,&row);
			if((line>5)||(line<1))
			{
				printf("输入有误，请重新输入:\n");
				continue;
			}
			else if((row>6)||(row<1))
			{
				printf("输入有误，请重新输入:\n");
				continue;
			}
		    j = change_seat13(line,row);
			if(j == 0)
			{
                printf("-------->订票成功!\n");
				break;
			}
			else{
				printf("-------->订票失败，该位置已有人订购!\n");
				printf("-------->请重新输入您想选择的位置:\n");
				continue;
			}
		}
		if(31 == ch)
		{
			printf("这是该航班的座位情况:\n");
			printf("(0代表空位，1代表已有人订购):\n");
			open_seat_31();
			printf("请输入您所要订购的座位号:\n");
			scanf("%d,%d",&line,&row);
			if((line>5)||(line<1))
			{
				printf("输入有误，请重新输入:\n");
				continue;
			}
			else if((row>6)||(row<1))
			{
				printf("输入有误，请重新输入:\n");
				continue;
			}
            j = change_seat31(line,row);
			if(j == 0)
			{
                printf("-------->订票成功!\n");
				break;
			}
			else{
				printf("-------->订票失败，该位置已有人订购!\n");
				printf("-------->请重新输入您想选择的位置:\n");
				continue;
			}
		}
	}
	return j;
}

int returnticket()                                       //退票函数
{
    int flight;
    int re_li;
	int re_ro;
	int re_j;
	printf("******---flight B16010809 从上海飞往赤峰---******\n");
	printf("******---flight B16010813 从宁波飞往深圳---******\n");
	printf("******---flight B16010831 从北京飞往莫斯科-******\n");
	printf("请输入您所要退订航班的尾号2位:\n");
	scanf("%d",&flight);
	while(1)
	{
		if(9 == flight)
		{
			printf("以下是该航班的座位情况:\n");
			printf("(0代表空位，1代表已有人订购):\n");
			open_seat_09();
			printf("请输入您已订购座位的座位号,中间用逗号隔开:\n");
			scanf("%d,%d",&re_li,&re_ro);
			if((re_li>5)||(re_li<1))
			{
				printf("输入有误，请重新输入:\n");
				continue;
			}
			else if((re_ro>6)||(re_ro<1))
			{
				printf("输入有误，请重新输入:\n");
				continue;
			}
			re_j = return_seat09(re_li, re_ro);
			if(re_j == 1)
			{
				printf("退票失败,该座位尚未有人订购\n");
				printf("请重新输入您的航班尾号2位:\n");
				continue;
			}
			else{
				printf("退订成功，退款将在扣除罚款后于24小时之内退还!\n");
				break;
			}
		}
		if(13 == flight)
		{
			printf("以下是该航班的座位情况:\n");
			printf("(0代表空位，1代表已有人订购):\n");
			open_seat_13();
			printf("请输入您已订购座位的座位号:\n");
			scanf("%d,%d",&re_li,&re_ro);
			if((re_li>5)||(re_li<1))
			{
				printf("输入有误，请重新输入:\n");
				continue;
			}
			else if((re_ro>6)||(re_ro<1))
			{
				printf("输入有误，请重新输入:\n");
				continue;
			}
			re_j = return_seat13(re_li, re_ro);
			if(re_j == 1)
			{
				printf("退票失败,该座位尚未有人订购\n");
				printf("请重新输入您的航班尾号2位:\n");
				continue;
			}
			else{
				printf("退订成功，退款将在扣除罚款后于24小时之内退还!\n");
				break;
			}
		}
		if(31 == flight)
		{
			printf("以下是该航班的座位情况:\n");
			printf("(0代表空位，1代表已有人订购):\n");
			open_seat_31();
			printf("请输入您已订购座位的座位号:\n");
			scanf("%d,%d",&re_li,&re_ro);
			if((re_li>5)||(re_li<1))
			{
				printf("输入有误，请重新输入:\n");
				continue;
			}
			else if((re_ro>6)||(re_ro<1))
			{
				printf("输入有误，请重新输入:\n");
				continue;
			}
			re_j = return_seat31(re_li, re_ro);
			if(re_j == 1)
			{
				printf("退票失败,该座位尚未有人订购\n");
				printf("请重新输入您的航班尾号2位:\n");
				continue;
			}
			else{
				printf("退订成功，退款将在扣除罚款后于24小时之内退还!\n");
				break;
			}
		}
	}
    return 1;
}

void find_inform()                                     //航班查询函数
{
	int choice;
	int fli_id;
	int time_c;
	int start_c;
	printf("***************************************\n");
    printf("******---欢迎进入航班查询系统!---******\n");
	printf("******-------您有如下选择:-------******\n");
	printf("******------1.按航班号查询;------******\n");
	printf("******-----2.按起飞时间查询;-----******\n");
    printf("******------3.按出发地查询;------******\n");
	printf("***************************************\n");
	while(1)
	{
		printf("----->请输入您所需要查询的项目:\n");
		scanf("%d",&choice);
		if(choice>3||choice<1)
		{
			printf("输入错误，请重新输入:\n");
			continue;
		}
		if(1 == choice)
		{
			printf("有如下航班号，请输入一个航班的末尾两位:\n");
			printf("---------->B16010809\n");
			printf("---------->B16010813\n");
			printf("---------->B16010831\n");
			scanf("%d",&fli_id);
			if(9 == fli_id)
			{
			    printf("以下是您所查询的航班信息:\n");
				printf("航班号 出发地 目的地 出发日期 起飞时间 经停城市（0为无） 预计飞行时间\n");
				open_flight_09();
				break;
			}
			if(13 == fli_id)
			{
				printf("以下是您所查询的航班信息:\n");
				printf("航班号 出发地 目的地 出发日期 起飞时间 经停城市（0为无） 预计飞行时间\n");
				open_flight_13();
				break;
			}
			if(31 == fli_id)
			{
				printf("以下是您所查询的航班信息:\n");
				printf("航班号 出发地 目的地 出发日期 起飞时间 经停城市（0为无） 预计飞行时间\n");
				open_flight_31();
				break;
			}
			else{
				printf("输入有误，请重新输入:\n");
				continue;
			}
		}
		if(2 == choice)
		{
			printf("以下是该机场可查询航班的起飞时间:\n");
			printf("---1---------->2017.9.31   01:15\n");
            printf("---2---------->2017.9.11   15:21\n");
            printf("---3---------->2017.9.22   02:42\n");
			printf("请输入您所要查询的起飞时间的序号:\n");
			scanf("%d",&time_c);
			if("time_c == 1")
			{
			    printf("以下是您所查询的航班信息:\n");
				printf("航班号 出发地 目的地 出发日期 起飞时间 经停城市（0为无） 预计飞行时间\n");
				open_flight_09();
				break;
			}
			if("time_c == 2")
			{
			    printf("以下是您所查询的航班信息:\n");
				printf("航班号 出发地 目的地 出发日期 起飞时间 经停城市（0为无） 预计飞行时间\n");
				open_flight_13();
				break;
			}
			if("time_c == 3")
			{
			    printf("以下是您所查询的航班信息:\n");
				printf("航班号 出发地 目的地 出发日期 起飞时间 经停城市（0为无） 预计飞行时间\n");
				open_flight_31();
				break;
			}
		}
		if(3 == choice)
		{
			printf("------>该系统可查询的出发地有:\n");
			printf("------>1.上海\n");
			printf("------>2.宁波\n");
			printf("------>3.北京\n");
			printf("------>请输入您所想查询的出发地序号:\n");
			scanf("%d",&start_c);
			if(1 == start_c)
			{
				printf("以下是该航班的信息:\n");
				printf("航班号 出发地 目的地 出发日期 起飞时间 经停城市（0为无） 预计飞行时间\n");
				open_flight_09();
				break;
			}
			if(2 == start_c)
			{
				printf("以下是该航班的信息:\n");
				printf("航班号 出发地 目的地 出发日期 起飞时间 经停城市（0为无） 预计飞行时间\n");
				open_flight_13();
				break;
			}
			if(3 == start_c)
			{
				printf("以下是该航班的信息:\n");
				printf("航班号 出发地 目的地 出发日期 起飞时间 经停城市（0为无） 预计飞行时间\n");
				open_flight_31();
				break;
			}
			else{
				printf("输入有误，请重新输入:\n");
				continue;
			}
		}
		else{
			printf("输入错误!\n");
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
	printf("以下为排序结果:\n");
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

void input_inform()                                      //航班录入函数
{
    int ju = 0;
	fli s1,*p;
	p = &s1;
	printf("请按顺序输入航班信息:\n");
	printf("航班号 出发地 目的地 出发日期 起飞时间 经停城市（0为无） 预计飞行时间\n");
	scanf("%s,%s,%s,%s,%s,%s,%f",&p->ID,&p->sta_add,&p->arr_add,&p->sta_date,&p->sta_time,&p->stop_add,&p->fly_time);
	ju = input_flight(p);
	if(ju == 0)
	{
	    printf("航班信息已成功录入到该系统中!\n");
	}
	else{
		printf("打开失败!\n");
	}
}

int main(void)
{
    int judge = 0;                                        //用于判断密码正误                                    //密码储存在该数组                                             
	int choice = 0;                                       //用户选择                
	int i = 0;                                            
	int a;
	char str[200]; 
	
	    printf("******************************\n");
		printf("\n"); 
		printf("++++++++++请输入密码++++++++++\n");
		printf("\n");
		printf("******************************\n");
	   do{ 
	    while( ( str[i]=getchar() ) != '#' )  //密码结束所输入的字符
		{
			i++;
		} 
		str[i]='\0';
		if(check(str))
		{
			printf("密码正确!\n");
			a=1;
		}
	
		else
		{
			printf("密码错误!\n");
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
        printf("                       ****---飞机订票系统---****\n");                //初始界面
	    printf("                       ****--欢迎进入该系统--****\n");
	    printf("                       ****---您有如下选择---****\n");
	    printf("                       ****1.浏览已有航班信息****\n");
	    printf("                       ****--2.录入航班信息--****\n");
        printf("                       ****3.查询已有航班信息****\n");
	    printf("                       ****--4.航班信息排序--****\n");
	    printf("                       ****---5.订票与退票---****\n");
	    printf("                       *****----------------*****\n");
	    printf("                       *******------------*******\n");
	    printf("                       ***********----***********\n");
	    printf("                       **************************\n");
		printf("==========================================================================\n");
	    printf("请输入您所需要办理的项目:\n");
		scanf("%d",&choice);
		if(1==choice)
		{
			printf("以下是可以订购的航班的信息:\n");
			printf("航班号 出发地 目的地 出发日期 起飞时间 经停城市（0为无） 预计飞行时间\n");
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
			printf("您的输入有误，请重新输入您所需要办理的程序:\n");
			continue;
		}
	}
	return 0;
}
