#include<iostream>
#include<functional>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	bool operator ==(const Person &p)
	{
		if (this->m_age == p.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_name;
	int m_age;
};
class greater20
{
public:
	bool operator()(Person &p)
	{
		return p.m_age > 20;
	}

};
class greaterfive
{
public:
	bool operator()(int v)
	{
		return v > 5;
	}
};
void test()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand()%2);
	}
	int ret = count_if(v.begin(), v.end(),greaterfive());
	cout << "大于5的个数有："<< ret << endl;

}
void test2()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 20);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	int ret = count_if(v.begin(), v.end(), greater20());
	cout << "大于20岁的人有 "<<ret<<" 个" << endl;
}
int main()
{
	test();
	test2();
	system("pause");
	return 0;
}
