// 菜单
#include<stdio.h>
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
