#include"fstream.h"
#include"iostream.h"
#include"string.h"
class student
{
private:
	char day[20];
	char name[20];
	int n;
	char lesson_name[20];
	char lx[20];

public:
	void setn()
	{
		cin >> name;//输入姓名
	}
	void setd()
	{
		cin >> day;//输入日期
	}
	void setk()
	{
		cin >> n;//输入课时
	}
	void setm()
	{
		cin >> lesson_name;//输入课程名称
	}
	void setl()
	{
		cin >> lx;//输入缺课类型
	}
	char*getn()
	{
		return name;
	}
	char*getd()
	{
		return day;
	}
	int getk()
	{
		return n;
	}
	char*getm()
	{
		return lesson_name;
	}
	char*getl()
	{
		return lx;
	}
};
void luru()
{
	int i, j;
	student p[200];
	fstream file;
	file.open("D:\学生考勤.txt", ios::in | ios::out);//文件存盘
	cout << "=请输入要录入几名同学信息:";
	cin >> j;
	cout << "\t\t\t请输入" << j << "名同学信息:" << endl;
	for (i = 0; i<j; i++)
	{
		cout << "姓名:";
		p[i].setn();
		cout << "日期:";
		p[i].setd();
		cout << "课时:";
		p[i].setk();
		cout << "名称:";
		p[i].setm();
		cout << "类型:";
		p[i].setl();

		file.write((char*)&p[i], sizeof(p[i]));//写文件
	}
	cout << "成功输入同学信息，请返回!" << endl;
	file.close();//关闭文件
}
//查询信息
void chaxun()//查询函数的调用
{
	student x;
	char name[20], z;
	fstream m;
al:int a = 0, flag = 0;//goto语句
	m.open("D:\学生考勤.txt", ios::in);
	cout << "请输入你要查询的同学姓名:" << endl;
	cin >> name;
	m.read((char*)&x, sizeof(x));
	while (!m.eof())//原文件到头结束
	{
		if (!strcmp(name, x.getn()))
		{
			cout << "姓名:" << x.getn() << endl;
			cout << "日期:" << x.getd() << endl;
			cout << "课时:" << x.getk() << endl;
			cout << "课程名称:" << x.getm() << endl;
			cout << "缺课类型:" << x.getl() << endl;
			flag = 1;
			break;
		}
		m.read((char*)&x, sizeof(x));
	}
	m.close();
	if (flag == 0)
	{
		cout << "对不起，您查询的同学无缺课现象，请返回" << endl;
	}

	cout << "如继续查询请输入Y,否则按任意键返回" << endl;
	cin >> z;
	if (z == 'Y' || z == 'y')
		goto al;
}
//修改函数的调用
void xiugai()                  /*修改成员函数*/
{
	student l;
	char xname[20], w;
	fstream xfile;
	xfile.open("D:\学生考勤.txt", ios::in | ios::out);
	xfile.read((char*)&l, sizeof(l));//读文件到L里
	cout << "请输入您要修改的同学姓名:" << endl;
	cin >> xname;
	while (!xfile.eof())//调用EOF判断函数
	{
		if (!strcmp(xname, l.getn()))
		{
			cout << "姓名:" << l.getn() << endl;
			cout << "日期:" << l.getd() << endl;
			cout << "课时:" << l.getk() << endl;
			cout << "课程名称:" << l.getm() << endl;
			cout << "缺课类型:" << l.getl() << endl;
			cout << "确认修改请按Y,否则按任意键" << endl;
			cin >> w;
			if (w == 'Y' || w == 'y')
			{
				cout << "姓名:";
				l.setn();
				cout << "日期:";
				l.setd();
				cout << "课时:";
				l.setk();
				cout << "课程名称:";
				l.setm();
				cout << "缺课		类型:";
				l.setl();
				xfile.open("D:\学生考勤.txt", ios::in);
				xfile.write((char*)&l, sizeof(l));
			}
			else
			{
				break;
			}

		}
		xfile.read((char*)&l, sizeof(l));//读文件到L里
	}
	xfile.close();
}
void renci()
{
	int i = 0, j = 1, x = 0, y = 0;
	student s;
	fstream d;
	d.open("D:\\学生考勤.txt", ios::in);
	d.read((char*)&s, sizeof(s));
	i = 1;
	cout << "早退人数为:" << x << endl;
	cout << "请假人数为:" << y << endl;
	cout << "旷课人数为:" << i << endl;
	cout << "迟到人数为:" << j << endl;
	cout << "在" << s.getd() << "有:" << endl;
	{
		cout << "课程名称:" << s.getm() << endl;
	}
	d.read((char*)&s, sizeof(s));//读文件到s里
	d.close();
}
void cishu()
{
	int i = 0, j = 1, x = 0, y = 0;
	student m;
	fstream b;
	b.open("D:\\学生考勤.txt", ios::in);
	b.read((char*)&m, sizeof(m));
	i = 1;
	cout << "早退次数为:" << x << endl;
	cout << "请假次数为:" << y << endl;
	cout << "旷课次数为:" << i << endl;
	cout << "迟到次数为:" << j << endl;
	cout << "在" << m.getd() << "有:" << endl;
	{
		cout << "姓名:" << m.getn() << endl;
	}

	b.read((char*)&m, sizeof(m));//读到文件L里
	b.close();
}
main()
{
	int i;
	while (i)
	{
		cout << "\t\t★★★★★★★★★★★★★★★★★★★★★★★★" << endl;
		cout << "\t\t\t☆☆欢迎进入学生考勤系统☆☆" << endl;
		cout << "\t\t★★★★★★★★★★★★★★★★★★★★★★★★★" << endl;
		cout << "\t\t★                                              ★" << endl;
		cout << "\t\t★                                              ★" << endl;
		cout << "\t\t★      1.录入学生的缺课记录                    ★" << endl;
		cout << "\t\t★                                              ★" << endl;
		cout << "\t\t★                                              ★" << endl;
		cout << "\t\t★      2.修改某个学生的缺课记录                ★" << endl;
		cout << "\t\t★                                              ★" << endl;
		cout << "\t\t★                                              ★" << endl;
		cout << "\t\t★      3.查询某个学生的缺课情况                ★" << endl;
		cout << "\t\t★                                              ★" << endl;
		cout << "\t\t★                                              ★" << endl;
		cout << "\t\t★      4.旷课学生姓名及旷课次数                ★" << endl;
		cout << "\t\t★                                              ★" << endl;
		cout << "\t\t★                                              ★" << endl;
		cout << "\t\t★      5.有学生旷课人次                        ★" << endl;
		cout << "\t\t★                                              ★" << endl;
		cout << "\t\t★                                              ★" << endl;
		cout << "\t\t★      6.退出                                  ★" << endl;
		cout << "\t\t★                                              ★" << endl;
		cout << "\t\t★★★★★★★★★★★★★★★★★★★★★★★★★" << endl << endl;
		cout << "\t※******请选择您所需要的信息******※" << endl;
		cin >> i;

		switch (i)
		{
		case 1:luru(); break;
		case 2:xiugai(); break;
		case 3:chaxun(); break;
		case 4:cishu(); break;
		case 5:renci(); break;
		case 6:break;
		}
		if (i == 6)
		{
			cout << endl << endl << endl << "\t\t\t退出考勤系统,欢迎下次使用" << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}