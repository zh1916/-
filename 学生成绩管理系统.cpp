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
// 菜单
void main_menu()
{
	printf("=================================\n");
	printf("=       学生成绩管理系统        =\n");
	printf("=          1.教师               =\n");
	printf("=          2.学生               =\n");
	printf("=          0.退出系统           =\n");
	printf("=================================\n");
}
void teacher_do_menu()
{
	printf("=================================\n");
	printf("=             教师              =\n");
	printf("=          1.学生管理           =\n");
	printf("=          2.成绩管理           =\n");
	printf("=          0.退出系统           =\n");
	printf("=================================\n");
}
void teacher_menu()
{
	printf("=================================\n");
	printf("=            学生模块           =\n");
	printf("=        1.增加学生信息         =\n");
	printf("=        2.删除学生信息         =\n");
	printf("=        3.修改学生信息         =\n");
	printf("=        4.显示学生信息         =\n");
	printf("=        5.统计学生信息         =\n");
	printf("=        6.学生文件读取         =\n");
	printf("=        7.学生文件存档         =\n");
	printf("=        8.查询学生信息         =\n");
	printf("=        9.学生成绩排序         =\n");
	printf("=        0.退出系统             =\n");
	printf("=================================\n");
}
void score_menu()
{
	printf("=================================\n");
	printf("=           成绩模块            =\n");
	printf("=        1.增加成绩信息         =\n");
	printf("=        2.删除成绩信息         =\n");
	printf("=        3.修改成绩信息         =\n");
	printf("=        4.显示成绩信息         =\n");
	printf("=        5.统计成绩信息         =\n");
	printf("=        6.成绩文件读取         =\n");
	printf("=        7.成绩文件存档         =\n");
	printf("=        8.查询成绩信息         =\n");
	printf("=        9.学生成绩排序         =\n");
	printf("=        0.退出系统             =\n");
	printf("=================================\n");
}
void student_menu()
{
	printf("=================================\n");
	printf("=            学生               =\n");
	printf("=        1.查询自身信息         =\n");
	printf("=        2.查询自身成绩         =\n");
	printf("=        3.修改密码             =\n");
	printf("=        0.退出系统             =\n");
	printf("=================================\n");
}
