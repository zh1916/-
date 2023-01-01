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
//增加信息
void add()
{
	printf("==========增加信息=========\n");

	printf("请输入学号：\n");
	scanf("%s", s[temp_number].id);
	for(int i = 0; i < temp_number; i++)
	{
		if (!strcmp(s[temp_number].id, s[i].id))
		{
			printf("存在该学号，添加失败！\n");
			return;
		}
	}
	printf("请输入姓名：\n");
	scanf("%s", s[temp_number].name);
	printf("请输入性别：\n");
	scanf("%s", s[temp_number].sex);
	printf("请输入密码：\n");
	scanf("%s", s[temp_number].pwd);
	temp_number++;
	printf("=======添加信息成功======\n");
}
//增加成绩
void add_score()
{

	int temp = 0;
	printf("请输入学号：\n");
	scanf("%s", score[number].id);
	for(int i = 0; i < temp_number; i++)
	{
		if (!strcmp(score[number].id, s[i].id))
		{
			temp++;
		}
	}

	if (temp == 0)
	{
		printf("不存在该信息，添加失败\n");
		return;
	}

	for(int i = 0; i < number; i++)
	{
		if (!strcmp(score[number].id, score[i].id))
		{
			printf("已经添加该学生成绩信息，添加失败！\n");
			return;
		}
	}

	printf("请输入语文成绩：\n");
	scanf("%f", &score[number].chinese);
	printf("请输入数学成绩：\n");
	scanf("%f", &score[number].math);
	number++;
	printf("=======添加信息成功======\n");
}
//显示信息
void showAll()
{
	printf("==========显示信息=========\n");
	for (int i = 0; i < temp_number; i++)
	{
		printf("学号：%s\t", s[i].id);
		printf("姓名：%s\t", s[i].name);
		printf("性别：%s\t", s[i].sex);
		printf("密码：%s\t", s[i].pwd);
	}
	printf("=======显示信息结束======\n");
}
//主函数
int main()
{

	int chioce;

	while (1)
	{
		one:
		main_menu();
		int ch;
		printf("请输入你的选择：\n");
		scanf("%d", &ch);
		if (ch == 1)
		{
			teacher_do_menu();
			printf("请输入你的选择：\n");
			scanf("%d", &ch);
			if (ch == 1)
			{
				int flag = teacher_login();
				if (flag == 1)
				{
					while (1)
					{
						teacher_menu();
						printf("请输入你的选择（0-9）:\n");
						scanf("%d", &chioce);
						if (chioce < 0 || chioce>9)
						{
							printf("输入有误，请重新输入！\n");
						}
						else
						{
							switch (chioce)
							{
							case 1:
								add();
								break;
							case 2:
								del();
								break;
							case 3:
								modify();
								break;
							case 4:
								showAll();
								break;
							case 5:
								countList();
								break;
							case 6:
								readList();
								break;
							case 7:
								saveList();
								break;
							case 8:
								search();
								break;
							case 9:
								sort();
								break;
							case 0:
								goto one;
								break;
							}
						}

					}
				}
			}
			else if(ch==2)
			{
				int flag = teacher_login();
				if (flag == 1)
				{
					while (1)
					{
						score_menu();
						printf("请输入你的选择（0-9）:\n");
						scanf("%d", &chioce);
						if (chioce < 0 || chioce>9)
						{
							printf("输入有误，请重新输入！\n");
						}
						else
						{
							switch (chioce)
							{
							case 1:
								add_score();
								break;
							case 2:
								del_score();
								break;
							case 3:
								modify_score();
								break;
							case 4:
								show_score();
								break;
							case 5:
								countList();
								break;
							case 6:
								read_score();
								break;
							case 7:
								save_score();
								break;
							case 8:
								search_score();
								break;
							case 9:
								sort();
								break;
							case 0:
								goto one;
								break;
							}
						}

					}
				}
			}
			else if (ch == 0)
			{
				goto one;
			}
			else
			{
				printf("输入有误！\n");
			}



		}
		else if (ch == 2)
		{
			int index = stu_login();
			if (index != -1)
			{
				while (1)
				{
					student_menu();
					printf("请输入你的选择（0-4）:\n");
					scanf("%d", &chioce);
					if (chioce < 0 || chioce>4)
					{
						printf("输入有误，请重新输入！\n");
					}
					else
					{
						switch (chioce)
						{
						case 1:
							show_self(index);
							break;
						case 2:
							show_self_score(index);
							break;
						case 3:
							update_self(index);
							break;
						case 0:
							printf("欢迎下次使用！\n");
							goto one;
							break;
						}
					}

				}
			}


		}
		else if (ch == 0)
		{
			printf("欢迎下次使用！\n");
			exit(0);
		}
		else
		{
			printf("输入有误！\n");
		}
	}


	return 0;
}
