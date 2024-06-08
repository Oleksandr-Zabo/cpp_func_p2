#include <iostream>
#include <ctime>
using namespace std;

const int FULL_SIZE = 20;

// for 1-d array
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
    cout << "Maxin 1-D array: " << max_val << endl;
}

//for 2-d array
void max_in_array(int arr[][FULL_SIZE], int size)
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
    cout << "Maxin 2-D array: " << max_val << endl;
}


//for 3-d array
void max_in_array(int arr[][FULL_SIZE][FULL_SIZE], int size)
{
    int max_val = arr[0][0][0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if (arr[i][j][k] > max_val)
                {
                    max_val = arr[i][j][k];
                }
            }
            
        }
    }
    cout << "Max in 3-D array: " << max_val << endl;
}


int max_num(int num_1, int num_2) {
    if (num_1 > num_2) {
        return num_1;
    }
    else {
        return num_2;
    }
}

int max_num(int num_1, int num_2, int num_3) {
    if (num_1 > num_2 && num_1 > num_3) {
        return num_1;
    }
    else if (num_3 > num_2 && num_3 >= num_1) {
        return num_3;
    }
    else {
        return num_2;
    }
}

int main()
{
    srand(time(0));
    //size of arrays
    int size;
    do
    {
        cout << "Enter the size of the array: ";
        cin >> size;
    } while (size > FULL_SIZE || size <= 0);

    //1-d array
    int arr_1[FULL_SIZE];
    for (int i = 0; i < size; i++)
    {
        arr_1[i] = rand() % 30 - 15;
    }

    cout << "Array 1: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr_1[i] << " ";
    }
    cout << endl;
    max_in_array(arr_1, size);
    cout << endl << endl;


    //2-d array
    int arr_2[FULL_SIZE][FULL_SIZE];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr_2[i][j] = rand() % 30 - 15;
        }
    }

    cout << "Array 2: " << endl;
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

    cout << endl << endl;

    //3-d array
    int arr_3[FULL_SIZE][FULL_SIZE][FULL_SIZE];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                arr_3[i][j][k] = rand() % 30 - 15;
            } 
        }
    }

    cout << "Array 3: " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                cout << arr_3[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;

    max_in_array(arr_3, size);
    cout << endl << endl;


    //numbers
    int firsrt_n, second_n, third_n;
    cout << "Enter the first number: ";
    cin >> firsrt_n;

    cout << "Enter the second number: ";
    cin >> second_n;

    cout << "Max num: " << max_num(firsrt_n, second_n) << endl;

    cout << "Enter the first number: ";
    cin >> firsrt_n;

    cout << "Enter the second number: ";
    cin >> second_n;

    cout << "Enter the third number: ";
    cin >> third_n;

    cout << "Max num: " << max_num(firsrt_n, second_n, third_n) << endl;
    

    cout << "The end" << endl;
    system("pause");
    return 0;
}
