#include <stdio.h>
#include <Windows.h>

int RSA( int baseNum,  int key,  int msg)		//自定义的RSA函数
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
	printf("请输入p、q: ");
	scanf("%d%d", &p, &q);					//随机输入两个不相想等的数p和q
	baseNum = p*q;							//计算p和q乘积
	Euler = (p - 1)*(q - 1);				//求出此值，用来计算keyD
	printf("请输入公钥(与%d互质): ", Euler);
	scanf("%d", &keyE);						//输入公钥keyE
	while (keyE<1 || keyE>Euler)			//keyE有大小范围的限制
	{
		printf("输入错误！\n请重新输入: ");
		scanf("%d", &keyE);
	}
	keyD = 1;
	while (((keyE*keyD) % Euler) != 1)		//求私钥keyD
		keyD++;
	printf("私钥:%d\n", keyD);
	printf("1.加密\n");						//打印菜单
	printf("2.解密\n");
	printf("3.退出\n");
	while (1)
	{
		printf("请选择要执行的操作：");
		scanf("%d", &r);						//输入选项1 or 2 or 3来执行不同操作
		switch (r)
		{
		case 1:									//输入1进行加密
			printf("请输入要加密的数据: ");
			scanf("%c", &m_msg);
			mm_msg=m_msg;
			c_msg = RSA(baseNum, keyE, 97);	//调用RSA函数
			printf("加密后的数据为：%d\n", c_msg);
			break;
		case 2:									//输入2进行解密
			printf("请输入要解密的数据: (只限三位数)");
			scanf("%d", &c_msg);
			m_msg = RSA(baseNum, keyD, c_msg);	//调用RSA函数
			printf("解密后的数据为：%c\n", m_msg);
			break;
		case 3:									//输入3退出程序
			exit(0);
			break;
		default:
			printf("选择有误\n");
			break;
		}
	}
	return 0;
}
