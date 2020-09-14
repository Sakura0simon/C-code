#include<iostream>
using namespace std;

#define uint unsigned int

void Output(uint p, int bits, bool dot)
{
	for (int i = bits; i >= 0; i--)
	{
		putchar(((p >> i) & 0x01) + 0x30);

		if ((i == bits - 1) && dot)
		{
			putchar('.');
		}
	}
}

void OutputLine(int bits)
{
	for (int i = bits + 1; i >= 0; i--)
	{
		putchar('-');
	}

	putchar('\n');
}

int booth(int x, int y, int bits)
{
	uint result = 0;
	int z = 0;

	bits++;
	y <<= 1;//β���0
	putchar(' ');
	Output(0, bits, true);
	putchar('\n');

	for (int i = 0; i < bits; i++)
	{
		putchar('+');
		uint t = (((int)(y & 0x01)) - ((int)((y >> 1) & 0x01))) * x;
		Output(t, bits, true);
		putchar('\n');
		OutputLine(bits);
		z += (int)t;

		//������ģ��ָ��λ�ļ����еķ���λ������ʹ�����X86ָ��ļ��㷽ʽ
		if ((z & (1 << bits)) == 0)
		{
			z &= ((1 << (bits + 1)) - 1);
		}

		putchar(' ');
		Output(z, bits, true);
		putchar('\n');
		y >>= 1;
		result >>= 1;
		result |= ((((uint)z) & 0x01) << 31);

		if (i < (bits - 1))
		{
			z >>= 1;
			putchar('>');
			Output(z, bits, true);
			putchar('\n');
		}
	}

	if ((z & (1 << bits)) != 0)
	{
		z |= ~((1 << (bits + 1)) - 1);
	}

	result = ((((uint)z)) << (bits - 1)) | ((result >> (32 - bits)) & ((1 << bits) - 1));

	OutputLine(bits);
	Output(result, bits + bits - 1, true);
	putchar('\n');
	return result;
}

int main()
{
	booth(0x0A, -0x06, 4);
	system("pause");
	return 0;
}