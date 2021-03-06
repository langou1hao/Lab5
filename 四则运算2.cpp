#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>

//函数原型
int getChoice();
void showMenu();
void doExercise(int);
int test(int);

/*
	功能：用户选择功能
	返回：用户的功能选择
	1、加法		2、减法		3、乘法		4、除法		0、退出
*/
int getChoice()
{
	int choice;
	scanf("%d",&choice);
	return choice;
}

/*
	功能：显示功能的菜单
*/

void showMenu()
{
	printf("===================================\n");
	printf("\n欢迎使用小学生四则运算练习软件\n");
	printf("请输入你的年级（1-6）：\n");
	printf("\n===================================\n");
}

/*
	功能：计分器
*/
void doExercise(int n)
{
	int score=0;		//练习得分，初始化为0
	int i=0;//练习题数的计数器
	int x=0;     //做题的数量			
	
	for(i=1;i<=10;i++)
	{
		score=score+test(n);	
	}
	printf("本次练习",x,"道题，你做对了%d道\n",score);
}

/*
	功能：进行一道题的测试过程
*/
int test(int n)
{
	char ranswer=0;			
	char uanswer=0;			
	char t=0;				
	char operation;			
	int num1=0;				
	int num2=0;				
	double num3=0;
	double num4=0;
	double num5=0;
	double num6=0;

	srand(time(NULL));		
	num1=rand()%100;			
	num2=rand()%100;
	num5=rand()%10000;
	num6=rand()%10000;
	num3=num5/100.0;
	num4=num6/100.0;

	
	if(n==1 or n==2)
	{
		n=rand()%2+1;
	}
	
	if(n==3 or n==4)
	{
		n=rand()%4+1;
	}
	
	if(n==5 or n==6)
	{
		n=rand()%4+1;
	}

	switch(n)
	{
		case 1:
			operation='+';
			break;

		case 2:
			operation='-';
			break;

		case 3:
			operation='*';
			break;

		case 4:
			operation='/';
			break;
	}


	if((operation=='-') && (num1<num2))
	{
		t=num1;
		num1=num2;
		num2=t;
	}
	
		if((operation=='-') && (num3<num4))
	{
		t=num3;
		num3=num4;
		num4=t;
	}


	if(operation=='/')
	{
		if(num2==0)
		{
			num2=1;
		}
		num1=num1*num2;			
	}
	
		if(operation=='/')
	{
		if(num4==0)
		{
			num4=1;
		}
		num3=num3*num4;			
	}


    if(n==1 or n==2 or n==3 or n==4)
    {
    	printf("%d%c%d= ",num1,operation,num2);
    	scanf("%d",&uanswer);
    	
    	switch(operation)
	{
		case '+':
		ranswer=num1+num2;
		break;

		case '-':
		ranswer=num1-num2;
		break;

		case '*':
		ranswer=num1*num2;
		break;

		case '/':
		ranswer=num1/num2;
		break;
	}
	}
	
	if(n==5 or n==6)
	{
		printf("%d%c%d= ",num3,operation,num4);
		scanf("%d",&uanswer);
		
		switch(operation)
	{
		case '+':
		ranswer=num3+num4;
		break;

		case '-':
		ranswer=num3-num4;
		break;

		case '*':
		ranswer=num3*num4;
		break;

		case '/':
		ranswer=num3/num4;
		break;
	}
	}
	
	
	

	if(uanswer==ranswer)
	{
		printf("做对了！\n");
		return 10;
	}
	else 
	{
		printf("做错了！\n");
		return 0;
	}
}


//主函数
int main(void)
{
	int choice=0;		//接收用户的选择
	
	
	
	
	do
	{
		showMenu();				//显示菜单
		choice=getChoice();		

		//控制choice的范围
		if(choice<0 || choice>5)
		{
			choice=1;			//强制做加法
		}
		if(choice==0)
		{
			break;					//用户选择0，退出循环（退出系统）
		}

		doExercise(choice);		//做什么练习，并启动评分
	}while(choice!=0);

	printf("欢迎使用本软件，再见！\n");
	return 0;
}

