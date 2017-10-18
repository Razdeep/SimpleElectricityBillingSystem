#include<unistd.h>
#include<stdio.h>
#ifndef RAJDEEP_H
#define RAJDEEP_H
void printLineSp(int n,char c);
void printLine(unsigned int);
void printCredits();
void delay();

void printLine(unsigned int n)
{
	unsigned short int i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("-");
	}
	printf("\n");
}

void printLineSp(int n,char c)
{
	unsigned short int i;
	printf("\n");
	for(i=0;i<n;i++)
		printf("%c",c);
	printf("\n");
}

void delay()
{
	//unsigned
	int i,j;
	for(j=0;j<5000;j++)
	{
	for(i=0;i<32767;i++)
	{}}
}

void printCredits()
{
	//unsigned short
	int i=0;
	char str[]="Created by Rajdeep Roy Chowdhury";
	while(str[i]!='\0')
	{
		//delay();
		//sleep(1);
		printf("-%c",str[i]);
		//putchar((int)str[i]);
		i++;

	}
}
#endif
