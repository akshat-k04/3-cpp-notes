class Test
{
    int a;
    int b;

public:
    // Test(int i, int j) : b(j), a(i+b) here compiler will give garbage value of a because the order in line 3 and 4 is a comes 1st then b comes
    // so that is why a will initialize 1st then b 
    Test(int i, int j) : a(i), b(j)
    {
        cout << "Constructor executed"<<endl;
        cout << "Value of a is "<<a<<endl;
        cout << "Value of b is "<<b<<endl;
    }
};

int main()
{
    Test t(4, 6);

    return 0;
}
