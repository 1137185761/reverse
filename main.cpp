#include<iostream>
#include<string.h>

using namespace std;

void reverser(unsigned char* s1,unsigned char *s2)
{
	int len = strlen((char*)s1);
	unsigned char tmp[1024];
	unsigned char *p1 = s1;
	unsigned char* p2 = tmp + len;
	*p2-- = 0;

	while (*p1)
	{
		if (*p1 < 0x80)//ox80(十六进制)=128(十进制)
		{
			*p2-- = *p1++;
		}
		else
		{
			*(p2 - 1) = *p1++;
			*p2 = *p1++;
			p2 -= 2;
		}
	}
	for (int i = 0; i < len; i++)
	{
		s2[i] = tmp[i];
	}

}
int main()
{
	unsigned char ori_str[] = "我a是v小b萌q新";
	unsigned char derc_str[1024];
	int len = strlen((char*)ori_str);
	cout << "strlen=" << len << endl;
	reverser(ori_str, derc_str);
	for (int i = 0; i < len; i++)
	{
		cout << derc_str[i];
	}
	cout << endl;
	for (int i = 0; i < len; i++)
	{
		cout << ori_str[i];
	}
	return 0;
}