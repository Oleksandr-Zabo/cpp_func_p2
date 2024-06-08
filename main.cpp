#include <iostream>
using namespace std;
//
int gcd(int num_1, int num_2) {
    if (num_2 == 0) {
        return num_1;
    }
    else {
        return gcd(num_2, num_1 % num_2);
    }
}

int main()
{
    int first_n, second_n;
    cout << "Enter the first number: ";
    cin >> first_n;
    cout << "Enter the second number: ";
    cin >> second_n;

    int result = gcd(first_n, second_n);
    cout << "GCD: " << result << endl;

	cout << "The end" << endl;
	system("pause");
	return 0;
}