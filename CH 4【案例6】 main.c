#include <stdio.h>
#include <Windows.h>

int RSA( int baseNum,  int key,  int msg)		//�Զ����RSA����
{
	int RSAmsg = 1;
	key = key + 1;
	while (key != 1)
	{
		RSAmsg = RSAmsg*msg;
		RSAmsg = RSAmsg%baseNum;
		key--;
	}
	return RSAmsg;
}
int main()
{
	int p, q, baseNum, Euler, r;
	int keyE, keyD,mm_msg,cc_msg;
	char m_msg, c_msg;
	printf("������p��q: ");
	scanf("%d%d", &p, &q);					//�����������������ȵ���p��q
	baseNum = p*q;							//����p��q�˻�
	Euler = (p - 1)*(q - 1);				//�����ֵ����������keyD
	printf("�����빫Կ(��%d����): ", Euler);
	scanf("%d", &keyE);						//���빫ԿkeyE
	while (keyE<1 || keyE>Euler)			//keyE�д�С��Χ������
	{
		printf("�������\n����������: ");
		scanf("%d", &keyE);
	}
	keyD = 1;
	while (((keyE*keyD) % Euler) != 1)		//��˽ԿkeyD
		keyD++;
	printf("˽Կ:%d\n", keyD);
	printf("1.����\n");						//��ӡ�˵�
	printf("2.����\n");
	printf("3.�˳�\n");
	while (1)
	{
		printf("��ѡ��Ҫִ�еĲ�����");
		scanf("%d", &r);						//����ѡ��1 or 2 or 3��ִ�в�ͬ����
		switch (r)
		{
		case 1:									//����1���м���
			printf("������Ҫ���ܵ�����: ");
			scanf("%c", &m_msg);
			mm_msg=m_msg;
			c_msg = RSA(baseNum, keyE, 97);	//����RSA����
			printf("���ܺ������Ϊ��%d\n", c_msg);
			break;
		case 2:									//����2���н���
			printf("������Ҫ���ܵ�����: (ֻ����λ��)");
			scanf("%d", &c_msg);
			m_msg = RSA(baseNum, keyD, c_msg);	//����RSA����
			printf("���ܺ������Ϊ��%c\n", m_msg);
			break;
		case 3:									//����3�˳�����
			exit(0);
			break;
		default:
			printf("ѡ������\n");
			break;
		}
	}
	return 0;
}
