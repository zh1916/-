#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
//增加信息
void add()
{
	printf("==========增加信息=========\n");

	printf("请输入学号：\n");
	scanf("%s", s[temp_number].id);
	for (int i = 0; i < temp_number; i++)
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
	for (int i = 0; i < temp_number; i++)
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

	for (int i = 0; i < number; i++)
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
//显示成绩
void show_score()
{
	printf("==========显示成绩=========\n");
	for (int i = 0; i < number; i++)
	{
		printf("学号：%s\t", score[i].id);
		printf("语文成绩：%0.2f\t", score[i].chinese);
		printf("数学成绩：%0.2f\n", score[i].math);
	}
	printf("=======显示信息结束======\n");
}
//查找信息
void search()
{

	printf("==========查找信息=========\n");
	printf("1.按照学号查询\n");
	printf("2.按照姓名查询\n");
	printf("请输入你的选择：\n");
	int ch;
	scanf("%d",&ch);
	if (ch == 1)
	{
		printf("请输入你要查找的学号：\n");
		char id[20];
		int a = 1;
		scanf("%s", id);
		for (int i = 0; i < temp_number; i++)
		{
			if (!strcmp(id, s[i].id))
			{

				printf("学号：%s\t", s[i].id);
				printf("姓名：%s\t", s[i].name);
				printf("性别：%s\t", s[i].sex);
				printf("密码：%s\t", s[i].pwd);
				a = 0;
				break;
			}
		}
		if (a == 1)
		{
			printf("没有该信息！\n");
		}
		printf("=======查找结束======\n");
	}
	else if (ch == 2)
	{
		printf("请输入你要查找的姓名：\n");
		char name[20];
		int a = 1;
		scanf("%s", name);
		for (int i = 0; i < temp_number; i++)
		{
			if (!strcmp(name, s[i].name))
			{

				printf("学号：%s\t", s[i].id);
				printf("姓名：%s\t", s[i].name);
				printf("性别：%s\t", s[i].sex);
				printf("密码：%s\t", s[i].pwd);
				a = 0;
				break;
			}
		}
		if (a == 1)
		{
			printf("没有该信息！\n");
		}
		printf("=======查找结束======\n");
	}
	else
	{
		printf("输入有误！\n");
		return;
	}
	

	

}
//查找成绩
void search_score()
{

	printf("请输入你要查找的学号：\n");
	char id[20];
	int a = 1;
	scanf("%s", id);
	for (int i = 0; i < number; i++)
	{
		if (!strcmp(id, score[i].id))
		{

			printf("学号：%s\t", score[i].id);
			printf("语文成绩：%0.2f\t", score[i].chinese);
			printf("数学成绩：%0.2f\n", score[i].math);
			a = 0;
			break;
		}
	}
	if (a == 1)
	{
		printf("没有该信息！\n");
	}
	printf("=======查找结束======\n");



}
//统计信息
void countList()
{
	printf("==========统计信息=========\n");
	printf("学生数量为：%d\n", temp_number);

	for (int i = 0; i < number; i++)
	{
		printf("学号：%s\t", score[i].id);
		printf("总成绩：%0.2f\n", score[i].chinese+ score[i].math);
	}
	printf("=======统计结束======\n");

}
//修改信息
void modify()
{
	printf("==========修改信息=========\n");
	printf("请输入你要修改的学号：\n");
	char id[20];
	int a = 1;
	scanf("%s", id);
	for (int i = 0; i < temp_number; i++)
	{
		if (!strcmp(id, s[i].id))
		{
			printf("请输入姓名：\n");
			scanf("%s", s[i].name);
			printf("请输入性别：\n");
			scanf("%s", s[i].sex);
			printf("请输入密码：\n");
			scanf("%s", s[i].pwd);

			a = 0;
			break;
		}
	}
	if (a == 1)
	{
		printf("没有该信息，修改失败！\n");
	}

	printf("=======修改信息完毕======\n");
}
//修改成绩
void modify_score()
{
	printf("==========修改信息=========\n");
	printf("请输入你要修改的学号：\n");
	char id[20];
	int a = 1;
	scanf("%s", id);
	for (int i = 0; i < number; i++)
	{
		if (!strcmp(id, s[i].id))
		{

			printf("请输入语文成绩：\n");
			scanf("%f", &score[i].chinese);
			printf("请输入数学成绩：\n");
			scanf("%f", &score[i].math);
			a = 0;
			break;
		}
	}
	if (a == 1)
	{
		printf("没有该信息，修改失败！\n");
	}

	printf("=======修改信息完毕======\n");
}
//删除信息
void del()
{
	printf("==========删除信息=========\n");
	printf("请输入你要删除的学号：\n");
	char id[20];
	int a = 1;
	scanf("%s", id);
	for (int i = 0; i < temp_number; i++)
	{
		if (!strcmp(id, s[i].id))
		{
			a = 0;
			for (int j = i; j < temp_number - 1; j++)
			{
				s[j] = s[j + 1];
			}
			temp_number--;
			printf("删除成功！\n");
			break;
		}
	}

	if (a == 1)
	{
		printf("没有该信息！\n");
	}
	printf("=======删除结束======\n");
}
//删除成绩
void del_score()
{
	printf("==========删除信息=========\n");
	printf("请输入你要删除的学号：\n");
	char id[20];
	int a = 1;
	scanf("%s", id);
	for (int i = 0; i < number; i++)
	{
		if (!strcmp(id, score[i].id))
		{
			a = 0;
			for (int j = i; j < number - 1; j++)
			{
				score[j] = score[j + 1];
			}
			number--;
			printf("删除成功！\n");
			break;
		}
	}

	if (a == 1)
	{
		printf("没有该信息！\n");
	}
	printf("=======删除结束======\n");
}
//信息保存文件
void saveList()
{
	FILE* file;
	if ((file = fopen("student.txt", "w")) == NULL)
	{
		printf("文件打开失败！");
		exit(0);
	}

	for (int i = 0; i < temp_number; i++)
	{
		fprintf(file, "%s  ", s[i].id);
		fprintf(file, "%s  ", s[i].name);
		fprintf(file, "%s  ", s[i].sex);
		fprintf(file, "%s\n", s[i].pwd);
	}
	fclose(file);
	printf("文件保存成功！\n");


}
//成绩保存文件
void save_score()
{
	FILE* file;
	if ((file = fopen("score.txt", "w")) == NULL)
	{
		printf("文件打开失败！");
		exit(0);
	}

	for (int i = 0; i < number; i++)
	{
		fprintf(file, "%s  ", score[i].id);
		fprintf(file, "%f  ", score[i].chinese);
		fprintf(file, "%f\n", score[i].math);
	}
	fclose(file);
	printf("文件保存成功！\n");


}
//读取文件信息
void readList()
{
	FILE* fp;
	fp = fopen("student.txt ", "r");
	if (fp == NULL)
	{
		printf("打开文件失败！\n");
	}

	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %s\n",
			s[temp_number].id,
			s[temp_number].name,
			s[temp_number].sex,
			s[temp_number].pwd);
		temp_number++;
	}
	fclose(fp);
	printf("读取文件信息成功！\n");
}
//读取成绩信息
void read_score()
{
	FILE* fp;
	fp = fopen("score.txt ", "r");
	if (fp == NULL)
	{
		printf("打开文件失败！\n");
	}

	while (!feof(fp))
	{
		fscanf(fp, "%s %f %f\n",
			score[number].id,
			&score[number].chinese,
			&score[number].math);
		number++;
	}
	fclose(fp);
	printf("读取文件信息成功！\n");
}
//按成绩排序
void sort()
{
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number - 1 - i; j++)
		{
			if (score[j].chinese + score[j].math > score[j + 1].chinese + score[j + 1].math)
			{
				Student p;
				p = s[j];
				s[j] = s[j + 1];
				s[j + 1] = p;
			}
		}
	}
	printf("排序成功\n");
	for (int i = 0; i < number; i++)
	{
		printf("学号：%s\t", score[i].id);
		printf("语文成绩：%0.2f\t", score[i].chinese);
		printf("数学成绩：%0.2f\n", score[i].math);
	}
}



//查询自身信息
void show_self(int index)
{

	printf("学号：%s\t", s[index].id);
	printf("姓名：%s\t", s[index].name);
	printf("性别：%s\t", s[index].sex);
	printf("密码：%s\n", s[index].pwd);

}
//查询自身成绩
void show_self_score(int index)
{

	for (int i = 0; i < number; i++)
	{
		if (!strcmp(s[index].id, score[i].id))
		{
			printf("学号：%s\t", score[i].id);
			printf("语文成绩：%0.2f\t", score[i].chinese);
			printf("数学成绩：%0.2f\n", score[i].math);
		}
	}


}
//修改密码
void update_self(int index)
{
	printf("请输入新的密码：\n");
	scanf("%s", s[index].pwd);
	printf("修改成功！\n");


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

