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
		cin >> name;//��������
	}
	void setd()
	{
		cin >> day;//��������
	}
	void setk()
	{
		cin >> n;//�����ʱ
	}
	void setm()
	{
		cin >> lesson_name;//����γ�����
	}
	void setl()
	{
		cin >> lx;//����ȱ������
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
	file.open("D:\ѧ������.txt", ios::in | ios::out);//�ļ�����
	cout << "=������Ҫ¼�뼸��ͬѧ��Ϣ:";
	cin >> j;
	cout << "\t\t\t������" << j << "��ͬѧ��Ϣ:" << endl;
	for (i = 0; i<j; i++)
	{
		cout << "����:";
		p[i].setn();
		cout << "����:";
		p[i].setd();
		cout << "��ʱ:";
		p[i].setk();
		cout << "����:";
		p[i].setm();
		cout << "����:";
		p[i].setl();

		file.write((char*)&p[i], sizeof(p[i]));//д�ļ�
	}
	cout << "�ɹ�����ͬѧ��Ϣ���뷵��!" << endl;
	file.close();//�ر��ļ�
}
//��ѯ��Ϣ
void chaxun()//��ѯ�����ĵ���
{
	student x;
	char name[20], z;
	fstream m;
al:int a = 0, flag = 0;//goto���
	m.open("D:\ѧ������.txt", ios::in);
	cout << "��������Ҫ��ѯ��ͬѧ����:" << endl;
	cin >> name;
	m.read((char*)&x, sizeof(x));
	while (!m.eof())//ԭ�ļ���ͷ����
	{
		if (!strcmp(name, x.getn()))
		{
			cout << "����:" << x.getn() << endl;
			cout << "����:" << x.getd() << endl;
			cout << "��ʱ:" << x.getk() << endl;
			cout << "�γ�����:" << x.getm() << endl;
			cout << "ȱ������:" << x.getl() << endl;
			flag = 1;
			break;
		}
		m.read((char*)&x, sizeof(x));
	}
	m.close();
	if (flag == 0)
	{
		cout << "�Բ�������ѯ��ͬѧ��ȱ�������뷵��" << endl;
	}

	cout << "�������ѯ������Y,�������������" << endl;
	cin >> z;
	if (z == 'Y' || z == 'y')
		goto al;
}
//�޸ĺ����ĵ���
void xiugai()                  /*�޸ĳ�Ա����*/
{
	student l;
	char xname[20], w;
	fstream xfile;
	xfile.open("D:\ѧ������.txt", ios::in | ios::out);
	xfile.read((char*)&l, sizeof(l));//���ļ���L��
	cout << "��������Ҫ�޸ĵ�ͬѧ����:" << endl;
	cin >> xname;
	while (!xfile.eof())//����EOF�жϺ���
	{
		if (!strcmp(xname, l.getn()))
		{
			cout << "����:" << l.getn() << endl;
			cout << "����:" << l.getd() << endl;
			cout << "��ʱ:" << l.getk() << endl;
			cout << "�γ�����:" << l.getm() << endl;
			cout << "ȱ������:" << l.getl() << endl;
			cout << "ȷ���޸��밴Y,���������" << endl;
			cin >> w;
			if (w == 'Y' || w == 'y')
			{
				cout << "����:";
				l.setn();
				cout << "����:";
				l.setd();
				cout << "��ʱ:";
				l.setk();
				cout << "�γ�����:";
				l.setm();
				cout << "ȱ��		����:";
				l.setl();
				xfile.open("D:\ѧ������.txt", ios::in);
				xfile.write((char*)&l, sizeof(l));
			}
			else
			{
				break;
			}

		}
		xfile.read((char*)&l, sizeof(l));//���ļ���L��
	}
	xfile.close();
}
void renci()
{
	int i = 0, j = 1, x = 0, y = 0;
	student s;
	fstream d;
	d.open("D:\\ѧ������.txt", ios::in);
	d.read((char*)&s, sizeof(s));
	i = 1;
	cout << "��������Ϊ:" << x << endl;
	cout << "�������Ϊ:" << y << endl;
	cout << "��������Ϊ:" << i << endl;
	cout << "�ٵ�����Ϊ:" << j << endl;
	cout << "��" << s.getd() << "��:" << endl;
	{
		cout << "�γ�����:" << s.getm() << endl;
	}
	d.read((char*)&s, sizeof(s));//���ļ���s��
	d.close();
}
void cishu()
{
	int i = 0, j = 1, x = 0, y = 0;
	student m;
	fstream b;
	b.open("D:\\ѧ������.txt", ios::in);
	b.read((char*)&m, sizeof(m));
	i = 1;
	cout << "���˴���Ϊ:" << x << endl;
	cout << "��ٴ���Ϊ:" << y << endl;
	cout << "���δ���Ϊ:" << i << endl;
	cout << "�ٵ�����Ϊ:" << j << endl;
	cout << "��" << m.getd() << "��:" << endl;
	{
		cout << "����:" << m.getn() << endl;
	}

	b.read((char*)&m, sizeof(m));//�����ļ�L��
	b.close();
}
main()
{
	int i;
	while (i)
	{
		cout << "\t\t�������������������������" << endl;
		cout << "\t\t\t��ӭ����ѧ������ϵͳ���" << endl;
		cout << "\t\t��������������������������" << endl;
		cout << "\t\t��                                              ��" << endl;
		cout << "\t\t��                                              ��" << endl;
		cout << "\t\t��      1.¼��ѧ����ȱ�μ�¼                    ��" << endl;
		cout << "\t\t��                                              ��" << endl;
		cout << "\t\t��                                              ��" << endl;
		cout << "\t\t��      2.�޸�ĳ��ѧ����ȱ�μ�¼                ��" << endl;
		cout << "\t\t��                                              ��" << endl;
		cout << "\t\t��                                              ��" << endl;
		cout << "\t\t��      3.��ѯĳ��ѧ����ȱ�����                ��" << endl;
		cout << "\t\t��                                              ��" << endl;
		cout << "\t\t��                                              ��" << endl;
		cout << "\t\t��      4.����ѧ�����������δ���                ��" << endl;
		cout << "\t\t��                                              ��" << endl;
		cout << "\t\t��                                              ��" << endl;
		cout << "\t\t��      5.��ѧ�������˴�                        ��" << endl;
		cout << "\t\t��                                              ��" << endl;
		cout << "\t\t��                                              ��" << endl;
		cout << "\t\t��      6.�˳�                                  ��" << endl;
		cout << "\t\t��                                              ��" << endl;
		cout << "\t\t��������������������������" << endl << endl;
		cout << "\t��******��ѡ��������Ҫ����Ϣ******��" << endl;
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
			cout << endl << endl << endl << "\t\t\t�˳�����ϵͳ,��ӭ�´�ʹ��" << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}