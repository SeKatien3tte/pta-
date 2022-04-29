#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a , i , j , flag , k;
	i = 10;
	cin >> a;
	k = a;
	while ( i > 0)
	{
		flag = 0;
		for (j = (k - 1); j > 1; j--) {
			if (k % j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0 && k < a) {
			    cout.setf(ios :: right);
			    cout.width(6);
				cout  << k;
				i--;
		}
		k--;	
	}
}