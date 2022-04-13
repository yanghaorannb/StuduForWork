#include <iostream>
using namespace std;

class Cube
{
public:
	void setL(int l)//设置长
	{
		m_L = l;
	}
	int getL()
	{
		return m_L;
	}
	void setW(int w)//设置宽
	{
		m_W = w;
	}
	int getW()
	{
		return m_W;
	}
	void setH(int h)//设置高
	{
		m_H = h;
	}
	int getH()
	{
		return m_H;
	}

	int calculateS()//面积
	{
		return 2 * m_L * m_H + 2 * m_W * m_H + 2 * m_L * m_W;
	}

	int calculateV()//体积
	{
		return m_L * m_H * m_W;
	}
	bool isSameByClass(Cube& c)
	{
		if (m_L == c.getL() && m_H == c.getH() && m_W == c.getW())
		{
			return true;
		}
		return false;
	}
private:
	int m_L;//长
	int m_W;//宽
	int m_H;//高
};

bool isSame(Cube& c1, Cube& c2)
{
	if (c1.getL() == c2.getL() && c1.getH() == c2.getH() && c1.getW() == c2.getW())
	{
		return true;
	}
	return false;
}

int main()
{
	Cube c1;
	c1.setL(10);
	c1.setH(10);
	c1.setW(10);

	cout << "C1的面积为：" << c1.calculateS() << endl;
	cout << "C1的体积为：" << c1.calculateV() << endl;

	Cube c2;
	c2.setL(10);
	c2.setH(10);
	c2.setW(20);

	bool ret = isSame(c1, c2);
	if (ret)
	{
		cout << "C1和C2相等" << endl;
	}
	else
	{
		cout << "C1和C2不相等" << endl;
	}

	bool ret1 = c1.isSameByClass(c2);
	if (ret1)
	{
		cout << "C1和C2相等" << endl;
	}
	else
	{
		cout << "C1和C2不相等" << endl;
	}

	system("pause");
	return 0;
}