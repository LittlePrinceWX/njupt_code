#ifndef SAVE_H_
#define SAVE_H_

typedef struct       //����ṹ��
{
	char type[20];   //��������
	float Getsum;    //���ѽ��
	char place[20];  //���ѵص�
	int time;        //����ʱ��
}family;


extern int Inputitmes (family sum[],int n);
extern void Save (family sum[],int n);
extern void Mode_1 ();

#endif
