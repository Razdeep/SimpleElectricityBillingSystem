/*Backup Plan Project*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"rajdeep.h"

void calculateBill()
{}
void setBillingParameters()
{
	float first,second,third;
	FILE *fp1=fopen("first.txt","r");
	FILE *fp2=fopen("second.txt","r");
	FILE *fp3=fopen("third.txt","r");
	fscanf(fp1,"%f",&first);
	fscanf(fp2,"%f",&second);
	fscanf(fp3,"%f",&third);

}
void creditsAndTroubleshooting()
{
	printCredits();
}
void choiceError()
{
	printf("Please enter a valid output");
}
void printTitle(char *arr)
{
	printLineSp(50,'*');
	printLine(50);
	puts(arr);
	printLine(50);
	printLineSp(50,'*');
}
void printMenu()
{
	int i,ch;
	printTitle("\tElectricity Billing System");
	printf("1.\tCalculate Bill\n2.\tSet Billing Parameters\n3.\tCredits And Troubleshooting\n4.\tExit");

	printf("\nEnter Choice ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		calculateBill();
		break;
		case 2:
		setBillingParameters();
		break;
		case 3:
		creditsAndTroubleshooting();
		break;
		case 4:
		exit(0);
		break;
		default:
		choiceError();
	}
}
int main()
{
	while(1)
	{
		printMenu();
	}
	return 0;
}
