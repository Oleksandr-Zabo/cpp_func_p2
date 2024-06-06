#include <iostream>
using namespace std;
//
int sum_range(int a, int b, int sum = 0) {
	if (a <= b) {
		sum += a;
		sum_range(++a, b, sum);
	}
	else {
		return sum;
	}

}
int main()
{
	//range include f_num and s_num
	int f_num, s_num;
	cout << "Enter number 1: ";
	cin >> f_num;
	cout << "Enter number 2: ";
	cin >> s_num;
	if (f_num > s_num) {
		int temp = f_num;
		f_num = s_num;
		s_num = temp;
	}

	cout << "Sum of range: " << sum_range(f_num, s_num) << endl;
	cout << "The end" << endl;
	system("pause");
	return 0;
}