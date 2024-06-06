#include <iostream>
#include <ctime>
using namespace std;

int min_ten(int arr[], const int size = 100, int i = 0, int min_sum = INT_MAX, int min_pos = 0, int j = 0, int sum = 0) {
    if (i <= 90) {
        if (j < 10) {
            sum += arr[i + j];
            min_ten(arr, size, i, min_sum, min_pos, ++j, sum);
        }
        else {
            if (min_sum > sum) {
                min_sum = sum;
                min_pos = i;
            }
            sum = 0;
            j = 0;
        }
        min_ten(arr, size, ++i, min_sum, min_pos, j, sum);
    }
    else {
        return min_pos;
    }
}


//with cycle for
//int min_ten(int arr[], const int size = 100, int i = 0, int min_sum = INT_MAX, int min_pos = 0, int sum = 0) {
//    if (i <= 90) {
//        for (int j = 0; j < 10; j++)
//        {
//            sum += arr[i + j];
//        }
//        if (min_sum > sum) {
//            min_sum = sum;
//            min_pos = i;
//        }
//        sum = 0;
//
//        min_ten(arr, size, ++i, min_sum, min_pos, sum);
//    }
//    else {
//        return min_pos;
//    }
//}

int main() {
    srand(time(0));

    const int full_size = 100;
    int arr[full_size];

    for (size_t i = 0; i < full_size; i++) {
        arr[i] = rand() % 20; // Randomly fill the array
    }

    cout << "Array: ";
    for (size_t i = 0; i < full_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int  position = 0;
    position = min_ten(arr);
    cout << "Min range of ten starts from index: " << position << endl;

    cout << "The end" << endl;
    system("pause");
    return 0;
}