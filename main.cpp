#include <iostream>
using namespace std;
//
int pow(int a, int b, int pow_num = 1, int i = 0) {
	if (i < b) {
		pow_num *= a; 
		pow(a, b, pow_num,++i);
	}
	else {
		return pow_num;
	}
	
}
int main()
{
	int f_num, s_num;
	cout << "Enter number: ";
	cin >> f_num;
	cout << "Enter pow: ";
	cin >> s_num;
	cout << f_num << " ^ " << s_num << " = " << pow(f_num, s_num) << endl;
	cout << "The end" << endl;
	system("pause");
	return 0;
}