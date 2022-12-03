#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long int test;
	cin>>test;
	while(test--)
	{
	    long long int xx,zz,yy,x,y,max1=-1;
	    cin>>xx>>zz;
	    for(long long int i=xx;i<2*xx;i++)
	    {
	        yy=(zz/i)*i;
	        if(yy-i>max1)
	        {
	            max1=yy-i;
	            x=i;
	            y=yy;
	        }
	    }
	    cout<<x<<" "<<y<<endl;
	}
	return 0;
}
