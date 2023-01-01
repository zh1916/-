#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<mmsystem.h>
#define MAX 100
typedef struct Student
{
	char id[20];//学号
	char name[20];//姓名
	char sex[20];//性别
	char pwd[20];//密码
}Student;

typedef struct Score
{
	char id[20];//学号
	float chinese;//语文成绩
	float math;//数学成绩
}Score;

//存放学生信息的顺序表
Student s[MAX];
int temp_number = 0;
Score score[MAX];
int number = 0;



//管理员登录
int teacher_login()
{
	char s_id[20];
	char s_password[20];
	int temp = 0;
	printf("请输入教师账号：\n");
	scanf("%s", s_id);
	printf("请输入教师密码：\n");
	scanf("%s", s_password);


	if (!strcmp(s_id, "admin") && !strcmp(s_password, "123"))
	{
		temp++;
		printf("登录成功！\n");
		return 1;

	}

	if (temp == 0)
	{
		printf("账号或者密码错误，登录失败！\n");
		return 0;
	}

}
//学生
int stu_login()
{
	char s_id[20];
	char s_password[20];
	int temp = 0;
	printf("请输入学号：\n");
	scanf("%s", s_id);
	printf("请输入密码：\n");
	scanf("%s", s_password);

	for (int i = 0; i < temp_number; i++)
	{
		if (!strcmp(s_id, s[i].id)&& !strcmp(s_password, s[i].pwd))
		{
			temp++;
			printf("登陆成功！\n");
			return i;
		}
	}


	if (temp == 0)
	{
		printf("账号或者密码错误，登录失败！\n");
		return -1;
	}

}
