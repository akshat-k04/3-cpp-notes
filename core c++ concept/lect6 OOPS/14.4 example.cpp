#include <iostream>
using namespace std;
class Base
{
public:
	int f(int i)
	{
		cout << "f(int): ";
		return i+3;
	}
};
class Derived : public Base
{
public:
	double f(double d)
	{
		cout << "f(double): ";
		return d+3.3;
	}
};
int main()
{
	Derived* dp = new Derived;
	cout << dp->f(3) << '\n';
	cout << dp->f(3.3) << '\n';
	delete dp;
	return 0;
}

// output:-
// f(double): 6.3
// f(double): 6.6 