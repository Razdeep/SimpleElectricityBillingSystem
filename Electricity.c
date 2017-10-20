/*Backup Plan Project*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"rajdeep.h"
float first,second,third;
void reviewDatabase()
{
	//Bugs to be fixed in this function
	char temp[100];
	int id;
	char name[30];
	float first,second,third,units,amount;
	FILE *fp=fopen("data.txt","r");
	printLine(30);
	printf("\nID\tName\t@1st 100 units\t@Next 100 Units\t@Remaining Units\tUnits Consumed\tAmount");
	while(fscanf(fp,"%s",&temp)!=-1)
	{
		if(temp=='\n')
		printf("\n");
		printf("\t%s",temp);
	}
	/*while(fscanf(fp,"%d%s%.2f%.2f%.2f%.2f%.2f",&id,&name,&first,&second,&third,&units,&amount)!=-1)
	{
		printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",id,name,first,second,third,units,amount);
	}*/
}
void getch()
{
	int qwerty;
	printf("\n\nSince getch() is not included in standard libraries of C in Linux,\n Hit 0 and press Enter to continue ");
	scanf("%d",&qwerty);
}
void showParameters()
{
	printf("\n Electricity Bill is being calculate be the following parameters\n");
	printf("\n\tFirst 100 Units @\t Rs. %.2f/Unit",first);
	printf("\n\tThe next 100 Units @\t Rs. %.2f/Unit",second);
	printf("\n\tThe remaining units @\t Rs. %.2f/Unit",third);
	printLine(50);
}
void loadParameters()
{
	FILE *fp1=fopen("first.txt","r");
	FILE *fp2=fopen("second.txt","r");
	FILE *fp3=fopen("third.txt","r");
	fscanf(fp1,"%f",&first);
	fscanf(fp2,"%f",&second);
	fscanf(fp3,"%f",&third);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
void calculateBill()
{
	int id;
	char name[30],choice;
	loadParameters();
	showParameters();
	float units=0.0,amount=0.0;
	printf("Enter ID ");
	scanf("%d",&id);
	printf("Enter name ");
	scanf("%s",&name);
	level1:
	printf("Enter units of electricity consumed ");
	scanf("%f",&units);
	if(units<0)
	goto level1;
	if(units>200)
	{
		amount=(100*first)+(100*second)+((units-200)*third);
	}
	else if(units>100 && units<=200)
	{
		amount=(100*first)+((units-100)*second);
	}
	else if(units<=100)
	{
		amount=units*first;
	}
	printf("Calculated Electricity Bill is Rs %.2f/-",amount);
	printf("\n\nDo you want to save it? (Y|N) ");
	scanf(" %c",&choice);
	if(choice=='Y'||choice=='y')
	{
		FILE *fp=fopen("data.txt","a+");
		if(fprintf(fp,"%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",id,name,first,second,third,units,amount)>0)
		printf("Saved Successfully");
		else printf("Oops, faced some errors while saving. Call Rajdeep to fix this issue.");
		fclose(fp);
	}
	getch();
}
void setBillingParameters()
{
	loadParameters();
	showParameters();

	char choice;
	printf("Do you want to update calculation parameters?(Y|N) ");
	scanf(" %c",&choice);
	float temp1,temp2,temp3;
	if(choice=='y'||choice=='Y')
	{
		printf("Enter the rate of first 100 units of electricity ");
		scanf("%f",&temp1);
		printf("Enter the rate of the next 150 units of electricity ");
		scanf("%f",&temp2);
		printf("Enter the rate of the remaining units of electricity ");
		scanf("%f",&temp3);
		FILE *fp;
		fp=fopen("first.txt","w+");
		fprintf(fp,"%.2f",temp1);
		fclose(fp);
		fp=fopen("second.txt","w+");
		fprintf(fp,"%.2f",temp2);
		fclose(fp);
		fp=fopen("third.txt","w+");
		fprintf(fp,"%.2f",temp3);
		fclose(fp);
		printf("Successfully Updated Parameters.");
		getch();
	}
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
	for(i=0;i<10;i++)
	{
		printf("\n");
	}
	printTitle("\tElectricity Billing System");
	printf("1.\tCalculate Bill\n2.\tSet Billing Parameters\n3.\tCredits And Troubleshooting\n4.\tReview Database\n5.\tExit");

	printf("\n\nEnter Choice ");
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
		reviewDatabase();
		break;
		case 5:
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
