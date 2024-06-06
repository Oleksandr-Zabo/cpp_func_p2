#include <iostream>
using namespace std;
//
void star_N(int a, int i = 0) {
	if (i < a) {
		cout << "*";
		star_N(a, ++i);
	}
	

}
int main()
{
	int num_user;
	
	do
	{
		cout << "Enter number: ";
		cin >> num_user;
	} while (num_user < 1);
	star_N(num_user);

	cout << "\nThe end" << endl;
	system("pause");
	return 0;
}