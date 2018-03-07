

#include<stdio.h>
#include<stdlib.h>

void open_input()
{
    FILE *fp;
	char ch;
	fp = fopen("C:\\vc\\project_flight\\flight_file\\input_flight.txt","r");
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
}


void open_flight_09()
{
    FILE *fp;
	char ch;
	fp = fopen("C:\\vc\\project_flight\\flight_file\\flight_file_9.txt","r");
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
}

void open_flight_13()
{
    FILE *fp;
	char ch;
	fp = fopen("C:\\vc\\project_flight\\flight_file\\flight_file_13.txt","r");
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
}

void open_flight_31()
{
	FILE *fp;
	char ch;
	fp = fopen("C:\\vc\\project_flight\\flight_file\\flight_file_31.txt","r");
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
}

void open_seat_09()
{
	FILE *fp;
	char ch;
	fp = fopen("C:\\vc\\project_flight\\flight_file\\seat_09.txt","r");
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
}

void open_seat_13()
{
	FILE *fp;
	char ch;
	fp = fopen("C:\\vc\\project_flight\\flight_file\\seat_13.txt","r");
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
}

void open_seat_31()
{
	FILE *fp;
	char ch;
	fp = fopen("C:\\vc\\project_flight\\flight_file\\seat_31.txt","r");
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
}