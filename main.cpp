#include <iostream>
#include <ctime>
using namespace std;

void max_in_array(int arr[], int size)
{
    int max_val = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }
    cout << "Max: " << max_val << endl;
}

void max_in_array(int arr[][100], int size)
{
    int max_val = arr[0][0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] > max_val)
            {
                max_val = arr[i][j];
            }
        }
    }
    cout << "Max: " << max_val << endl;
}

int main()
{
    srand(time(0));
    const int FULL_SIZE = 100;
    int arr_1[FULL_SIZE];
    int size;
    do
    {
        cout << "Enter the size of the array: ";
        cin >> size;
    } while (size > FULL_SIZE || size <= 0);

    for (int i = 0; i < size; i++)
    {
        arr_1[i] = rand() % 30 - 15;
    }

    cout << "Array 1: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr_1[i] << " ";
    }
    cout << endl;
    max_in_array(arr_1, size);
    cout << endl;

    int arr_2[FULL_SIZE][FULL_SIZE];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr_2[i][j] = rand() % 30 - 15;
        }
    }

    cout << "Array 2: ";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr_2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    max_in_array(arr_2, size);

    cout << "The end" << endl;
    system("pause");
    return 0;
}
