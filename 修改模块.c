
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
			printf("请输入年龄：\n");
			scanf("%d", &s[i].age);
			printf("请输入语文成绩：\n");
			scanf("%f", &s[i].chinese);
			printf("请输入数学成绩：\n");
			scanf("%f", &s[i].math);
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
