/*Backup Plan Project*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"rajdeep.h"

struct Record{
	int id;
	char name[30];
	float first;
	float second;
	float third;
	float units;
	float amount;
};
float first,second,third;
void getch();


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
	scanf("%s",name);
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
void editBill()
{
	loadParameters();
	showParameters();
	char ch;
	struct Record record[50];
	int i;
	FILE *fp=fopen("data.txt","r");
	//Reading from file
	for(i=0;;i++)
	{
		if(fscanf(fp,"%d%s%f%f%f%f%f",&record[i].id,record[i].name,&record[i].first,&record[i].second,&record[i].third,&record[i].units,&record[i].amount)==-1)
		break;
	}
	fclose(fp);
	int number=i,flag=0;
	//Display Records
	printf("\t\tDisplaying previously saved records... :)\n");
	printLine(100);
	printf("\nID\tName\t@1st 100 units\t@Next 100 Units\t@Remaining Units\tUnits Consumed\tAmount");
	printLine(100);

	//printing the records list
	for(i=0;i<number;i++)
	{
		printf("\n%d\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t%.2f",record[i].id,record[i].name,record[i].first,record[i].second,record[i].third,record[i].units,record[i].amount);
	}

	int id;
	printf("\nEnter ID of the bill which you want to edit ");
	scanf("%d",&id);

	for(i=0;i<number;i++)
	{
		if(record[i].id==id)
		{
			printf("\nEnter name ");
			scanf("%s",record[i].name);
			//level2:
			fflush(stdin);
			printf("\nEnter units of electricity consumed ");
			scanf("%f",&record[i].units);
			record[i].first=first;
			record[i].second=second;
			record[i].third=third;
			/*if(record[i].units<0)
			goto level2;*/
			if(record[i].units>200)
			{
				record[i].amount=(100*first)+(100*second)+((record[i].units-200)*third);
			}
			else if(record[i].units>100 && record[i].units<=200)
			{
				record[i].amount=(100*first)+((record[i].units-100)*second);
			}
			else if(record[i].units<=100)
			{
				record[i].amount=record[i].units*first;
			}
			printf("Calculated Electricity Bill is Rs %.2f/-",record[i].amount);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("\nNo match found in our database.");
	}
	//Save
	fflush(stdin);
	printf("\nDO YOU WANT TO MAKE CHANGES TO THE DATABASE? (Y|N) ");
	scanf(" %c",&ch);
	flag=0;
	if(ch=='Y'||ch=='y')
	{
		FILE *fp=fopen("data.txt","w");
		for(i=0;i<number;i++)
		{
			if(fprintf(fp,"%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",record[i].id,record[i].name,record[i].first,record[i].second,record[i].third,record[i].units,record[i].amount)<0)
			{
				flag=1;
				break;
			}
		}
		fclose(fp);
		if(flag==1)
		{
			printf("\nSorry for inconvenience. We are unable to modify our records. Please call Rajdeep.");
		}
		else{
			printf("\nOur records have been successfully updated. Have a nice day. :) ");
		}
	}
}
void reviewDatabase()
{
	struct Record record[50];
	struct Record tmp;
	int i;
	int ch;
	FILE *fp=fopen("data.txt","r");
	//Reading from file
	for(i=0;;i++)
	{
		if(fscanf(fp,"%d%s%f%f%f%f%f",&record[i].id,record[i].name,&record[i].first,&record[i].second,&record[i].third,&record[i].units,&record[i].amount)==-1)
		break;
	}
	fclose(fp);
	int number=i;
	printf("\n\t1. Sort by Name\n\t2. Sort by Amount or Units Consumed \n\t3. Sort by ID\n\t4. Sort by Input");
	fflush(stdin);
	printf("\nEnter Choice ");
	scanf("%d",&ch);
	printLine(30);
	printf("\t\tDisplaying previously saved records... :)\n");
	printLine(100);
	printf("\nID\tName\t@1st 100 units\t@Next 100 Units\t@Remaining Units\tUnits Consumed\tAmount");
	printLine(100);
	/*while(fscanf(fp,"%d%s%f%f%f%f%f",&record.id,record.name,&record.first,&record.second,&record.third,&record.units,&record.amount)!=-1)
	{
		printf("\n%d\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t%.2f",id,name,first,second,third,units,amount);
	}*/
	if(ch==1)
	{
		//Sorting by Name
		for(int j=0;j<number-1;j++)
		{
		for(i=0;i<number-1;i++)
		{
				if(strcmp(record[i].name,record[i+1].name)==1)
				{
					tmp=record[i];
					record[i]=record[i+1];
					record[i+1]=tmp;
				}
			}
		}
	}
	else if(ch==2)
	{
		//Sorting by Amount or Units Consumed
		for(int j=0;j<number-1;j++)
		{
		for(i=0;i<number-1;i++)
		{
			if(record[i].amount>record[i+1].amount)
			{
				tmp=record[i];
				record[i]=record[i+1];
				record[i+1]=tmp;
			}
		}
		}
	}
	else if(ch==3)
	{
		//sort by ID
		for(int j=0;j<number-1;j++)
		{
		for(i=0;i<number-1;i++)
		{
			if(record[i].id>record[i+1].id)
			{
				tmp=record[i];
				record[i]=record[i+1];
				record[i+1]=tmp;
			}
		}
		}
	}

	//printing the records list
	for(i=0;i<number;i++)
	{
		printf("\n%d\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t%.2f",record[i].id,record[i].name,record[i].first,record[i].second,record[i].third,record[i].units,record[i].amount);
	}

	getch();
}
void creditsAndTroubleshooting()
{
	printCredits();
	printf("\nFor support email me at rrajdeeproychowdhury@gmail.com");
	getch();
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
	printf("1.\tCalculate Bill\n2.\tSet Billing Parameters\n3.\tEdit Bill from the database\n4.\tReview Database\n5.\tCredits And Troubleshooting\n6.\tExit");

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
		editBill();
		break;
		case 4:
		reviewDatabase();
		break;
		case 5:
		creditsAndTroubleshooting();
		break;
		case 6:
		creditsAndTroubleshooting();
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
