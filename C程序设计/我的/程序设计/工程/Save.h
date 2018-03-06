#ifndef SAVE_H_
#define SAVE_H_

typedef struct       //定义结构体
{
	char type[20];   //消费类型
	float Getsum;    //消费金额
	char place[20];  //消费地点
	int time;        //消费时间
}family;


extern int Inputitmes (family sum[],int n);
extern void Save (family sum[],int n);
extern void Mode_1 ();

#endif
