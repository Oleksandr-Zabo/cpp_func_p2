#include <iostream>
#include <ctime>
using namespace std;

const int main_size = 4;


template <typename type>
void user_number(type user_arr[]) {
    type user_num;
    do {
        cout << "Enter your number (4 digits): ";
        cin >> user_num;

        if (cin.fail()) {//cin.fail()- check input data with problems
            cout << "Error: Incorrect input! Please enter a valid integer." << endl;
            cin.clear();//continue work after problem
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//clear bufer to input new data
        }
    } while (user_num < 1000 || user_num > 9999);

    for (int i = 0; i < main_size; i++) {
        user_arr[main_size - i - 1] = user_num % 10;
        user_num /= 10;
    }
}

bool is_bulls(int arr_comp[], int user_arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr_comp[i] == user_arr[j]) {
                return 1;
            }
        }
    }
    return 0;
}


int find_bulls(int arr_comp[], int user_arr[], int num_bulls = 0, int k = 0, int size = main_size) {
    if (is_bulls(arr_comp, user_arr, size)) {
        for (int j = 0; j < size; j++) {
            if (arr_comp[j] == user_arr[k]) {
                num_bulls++;

                for (int i = k; i < size; i++) // Видаляємо число, яке має бика у user_arr
                {
                    user_arr[i] = user_arr[i + 1];
                }
                for (int i = j; i < size; i++) // Видаляємо число, яке має бика у arr_comp
                {
                    arr_comp[i] = arr_comp[i + 1];
                }
                size--;


                break;
            }
        }
        find_bulls(arr_comp, user_arr, num_bulls, k + 1, size);
    }
    else {
        return num_bulls;
    }
}


int find_cows(int comp_arr[], int arr_user[], int c = 0, int num_cows = 0) {
    if (c < main_size) {
        if (comp_arr[c] == arr_user[c]) {
            num_cows++;
        }
        return find_cows(comp_arr, arr_user, ++c, num_cows);
    }
    else {
        return num_cows;
    }
}


int game_func(int comp_arr[], int i = 1) {
    int arr_user[main_size];
    user_number(arr_user);
    bool win = true;
    for (size_t j = 0; j < main_size; j++) {
        if (comp_arr[j] != arr_user[j]) {
            win = false;
            break;
        }
    }
    if (!win) {
        int num_bulls = 0, num_cow = 0;

        int temp_1[main_size], temp_2[main_size]; //temp arrs- fix bags with num cows
        for (int i = 0; i < main_size; i++) {
            temp_1[i] = comp_arr[i];
            temp_2[i] = arr_user[i];
        }
        num_bulls = find_bulls(temp_1, temp_2);
        num_cow = find_cows(comp_arr, arr_user);
        num_bulls -= num_cow;//num bull from func include num cow, so num_bulls real: num_bulls = num_bulls - num_cow;
        cout << "You have bull(s): " << num_bulls << endl;
        cout << "You have cow(s): " << num_cow << endl;
        game_func(comp_arr, ++i);
    }
    else {
        return i;
    }
    
}

int main() {
    srand(time(0));
    // Create random number
    int arr_comp[main_size];
    do {
        arr_comp[0] = rand() % 10;
    } while (arr_comp[0] == 0);

    for (int i = 1; i < main_size; i++) {
        arr_comp[i] = rand() % 10;
    }

    cout << "\tGame bulls and cows" << endl << endl;

    int attempts = game_func(arr_comp);

    cout << "You win!" << endl;
    cout << "Number of attempts: " << attempts << endl;

    cout << "The end" << endl;
    system("pause");
    return 0;
}
