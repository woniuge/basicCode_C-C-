//������e��2.718281828����Ϊ�������壬Ȼ�������10λ��Чλ���ĸ�������
//���㷽ʽ��8λС��λ��ʾ�������Լ�ָ����ʽ��8λС��λ��ʾ������

#include <iostream.h>
#include <iomanip.h>

const double e = 2.718281828;

int main(void)
{
	cout << "1#10λ��Чλ���ĸ�����:" << setprecision(10) << e <<endl
		 << "2#���㷽ʽ��8λС��λ��ʾ����:" << setiosflags(ios::fixed)
		 << setprecision(8) << e <<endl
		 << "3#ָ����ʽ��8λС��λ��ʾ����:" << setiosflags(ios::scientific)
		 << setprecision(8) << e <<endl;
	
	cout << setprecision(6);		
}

