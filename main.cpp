#include <iostream>
#include <ctime>
using namespace std;

const int FULL_SIZE = 20;

template <typename type>
void init_matrix(type arr[FULL_SIZE][FULL_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (typeid(type) == typeid(int)) {
                arr[i][j] = rand() % 21 - 10;
            }
            else if (typeid(type) == typeid(double)) {
                arr[i][j] = rand() % 21 - 10 + 0.5;
            }
            else if (typeid(type) == typeid(char)) {
                arr[i][j] = rand() % 255;
            }
            else {
                arr[i][j] = 0;
            }
        }
    }
}

template <typename type>
void print_matrix(type arr[FULL_SIZE][FULL_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl<<endl;
}

template <typename type>
void max_min_matrix(type arr[FULL_SIZE][FULL_SIZE], int size) {
    type min = arr[0][0];
    type max = arr[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                if (arr[i][j] < min) {
                    min = arr[i][j];
                }
                if (arr[i][j] > max) {
                    max = arr[i][j];
                }
            }
        }
    }
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << endl << endl;
}

template <typename type>
void Sort_matrix(type arr[], int size) {
    for (int i = 1; i < size; ++i) {
        type key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    srand(time(0));
    int size;
    do {
        cout << "Enter size: ";
        cin >> size;
    } while (size < 0 || size > FULL_SIZE);

    //int
    int arr_main[FULL_SIZE][FULL_SIZE];
    init_matrix<int>(arr_main, size);

    cout << "Your matrix: " << endl;
    print_matrix<int>(arr_main, size);
    max_min_matrix<int>(arr_main, size);

    for (int i = 0; i < size; ++i) {
        Sort_matrix<int>(arr_main[i], size);
    }

    cout << "Your sorted matrix: " << endl;
    print_matrix<int>(arr_main, size);


    //double
    double arr_main_2[FULL_SIZE][FULL_SIZE];
    init_matrix<double>(arr_main_2, size);

    cout << "Your matrix: " << endl;
    print_matrix<double>(arr_main_2, size);

    max_min_matrix<double>(arr_main_2, size);

    for (int i = 0; i < size; ++i) {
        Sort_matrix<double>(arr_main_2[i], size);
    }

    cout << "Your sorted matrix: " << endl;
    print_matrix<double>(arr_main_2, size);

    //char
    char arr_main_3[FULL_SIZE][FULL_SIZE];
    init_matrix<char>(arr_main_3, size);

    cout << "Your matrix: " << endl;
    print_matrix<char>(arr_main_3, size);
    max_min_matrix<char>(arr_main_3, size);

    for (int i = 0; i < size; ++i) {
        Sort_matrix<char>(arr_main_3[i], size);
    }

    cout << "Your sorted matrix: " << endl;
    print_matrix<char>(arr_main_3, size);


    cout << "The end" << endl;
    return 0;
}
