#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>

//����ԭ��
int getChoice();
void showMenu();
void doExercise(int);
int test(int);

/*
	���ܣ��û�ѡ����
	���أ��û��Ĺ���ѡ��
	1���ӷ�		2������		3���˷�		4������		0���˳�
*/
int getChoice()
{
	int choice;
	scanf("%d",&choice);
	return choice;
}

/*
	���ܣ���ʾ���ܵĲ˵�
*/

void showMenu()
{
	printf("===================================\n");
	printf("\n��ӭʹ��Сѧ������������ϰ���\n");
	printf("����������꼶��1-6����\n");
	printf("\n===================================\n");
}

/*
	���ܣ��Ʒ���
*/
void doExercise(int n)
{
	int score=0;		//��ϰ�÷֣���ʼ��Ϊ0
	int i=0;//��ϰ�����ļ�����
	int x=0;     //���������			
	
	for(i=1;i<=10;i++)
	{
		score=score+test(n);	
	}
	printf("������ϰ",x,"���⣬��������%d��\n",score);
}

/*
	���ܣ�����һ����Ĳ��Թ���
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
		printf("�����ˣ�\n");
		return 10;
	}
	else 
	{
		printf("�����ˣ�\n");
		return 0;
	}
}


//������
int main(void)
{
	int choice=0;		//�����û���ѡ��
	
	
	
	
	do
	{
		showMenu();				//��ʾ�˵�
		choice=getChoice();		

		//����choice�ķ�Χ
		if(choice<0 || choice>5)
		{
			choice=1;			//ǿ�����ӷ�
		}
		if(choice==0)
		{
			break;					//�û�ѡ��0���˳�ѭ�����˳�ϵͳ��
		}

		doExercise(choice);		//��ʲô��ϰ������������
	}while(choice!=0);

	printf("��ӭʹ�ñ�������ټ���\n");
	return 0;
}

