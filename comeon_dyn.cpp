#include <iostream>
#include <string>

using namespace std;

struct Tours
{
    /* Запись структуры о туре */
    string country;
    string beginnig_date;
    string finish_date;
    string food_type;
    string rest_type;
    string hotel_star;
    int cost_of_tour;
};

void Fill_information_about_tour(Tours* info) {
    /* Заполнение информации о туре */
    cout << "Выберите страну для отдыха: " << endl;
    cin >> info->country;
    cin >> info->beginnig_date;
    cin >> info->finish_date;
    cin >> info->hotel_star;
    cin >> info->food_type;
    cin >> info->rest_type;
    cin >> info->cost_of_tour;
}
void showData(Tours* arr, int size_init_array) {
    for (int i = 0; i < size_init_array; i++) {
        if (arr[i].country[0] != '-') {
            cout << arr[i].country << endl << arr[i].beginnig_date << endl << arr[i].finish_date << endl << arr[i].hotel_star << endl
                << arr[i].food_type << endl << arr[i].rest_type << endl << arr[i].cost_of_tour << endl;
        }
    }
}

void Sorting_array_by_countries(Tours* arr, int size_init_array) {
    for (int i = 0; i < size_init_array - 1; i++) {
        if (char(arr[i].country[0]) > char(arr[i + 1].country[0])) {
            swap(arr[i], arr[i + 1]);
            if (i > 0) {
                i--;
            }
        }
    }
}

void Deleting_finished_tours(Tours* arr, int size_init_array, string date) {
    for (int i = 0; i < size_init_array - 1; i++) {
        string chislo = to_string(arr[i].finish_date[0]) + to_string(arr[i].finish_date[1]), date_chislo = to_string(date[0]) + to_string(date[1]);
        string month = to_string(arr[i].finish_date[3]) + to_string(arr[i].finish_date[4]), date_month = to_string(date[3]) + to_string(date[4]);
        string year = to_string(arr[i].finish_date[6]) + to_string(arr[i].finish_date[7]), date_year = to_string(date[6]) + to_string(date[7]);
        if (stoi(year) < stoi(date_year)) {
            arr[i].country = '-';
            arr[i].beginnig_date = '-';
            arr[i].finish_date = '-';
            arr[i].hotel_star = '-';
            arr[i].food_type = '-';
            arr[i].rest_type = '-';
            arr[i].cost_of_tour = -1;
        }
        if (stoi(month) < stoi(date_month)) {
            arr[i].country = '-';
            arr[i].beginnig_date = '-';
            arr[i].finish_date = '-';
            arr[i].hotel_star = '-';
            arr[i].food_type = '-';
            arr[i].rest_type = '-';
            arr[i].cost_of_tour = -1;
        }
        if (stoi(chislo) < stoi(date_chislo)) {
            arr[i].country = '-';
            arr[i].beginnig_date = '-';
            arr[i].finish_date = '-';
            arr[i].hotel_star = '-';
            arr[i].food_type = '-';
            arr[i].rest_type = '-';
            arr[i].cost_of_tour = -1;
        }
    }
}

void Available_tours(Tours* arr, int size_init_array, int tour_price, Tours* available, int* len_vailable) {
    for (int i = 0; i < size_init_array; i++) {
        if (arr[i].cost_of_tour > tour_price)
            continue;
        available[(*len_vailable)++] = arr[i];
    }
}

int main()
{
    setlocale(0, "");
    int operation_num = -1, size_init_array = 0;
    string date;
    int SIZE_OF_TRIP;
    cout << "Введите размер элемента массива(т.е. тура) " << endl;
    cin >> SIZE_OF_TRIP;
    Tours *arr = new Tours[SIZE_OF_TRIP];
    while (operation_num != 0) {
        cout << "Введите номер операции: " << endl;
        cin >> operation_num;
        switch (operation_num) {
        case 1:
            if (size_init_array + 1 >= SIZE_OF_TRIP) {
                cout << "Достигнут максимальный предел записи туров! ";
                break;
            }
            cout << "Добавление записи о турe: " << endl;
            Fill_information_about_tour(&arr[size_init_array++]);
            break;
        case 2:
            cout << "Перестановка" << endl;
            Sorting_array_by_countries(arr, size_init_array);
            break;
        case 3:
            cout << "showing: " << endl;
            showData(arr, size_init_array);
            break;
        case 4:
            cout << "Введите дату завершения: " << endl;
            cin >> date;
            Deleting_finished_tours(arr, size_init_array, date);
            break;
        case 5:
            cout << "По какой цене желаете отправиться в тур? " << endl;
            int tour_price, available_tours_size = 0;
            cin >> tour_price;
            Tours *available_tours_arr = new Tours[SIZE_OF_TRIP];
            Available_tours(arr, size_init_array, tour_price, available_tours_arr, &available_tours_size);
            cout << "Доступные туры: " << endl;
            showData(available_tours_arr, available_tours_size);
            break;
        }
    }
}

/*Australia
12.03.22
17.03.22
5_stars
hotel_breakfast
active
80

дата завершения = 25.04.22

Brasilia
19.06.22
29.06.22
4_stars
all_include
excursion
120*/