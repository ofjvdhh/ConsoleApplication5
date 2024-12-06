////////////////////////////////////////////////////////////////////////////////////////////////  

#include <iostream>
using namespace std;
bool vys(int year)
{
    bool res = false;
    if (year % 4 == 0)
        res = true;
    if (year % 100 == 0)
        res = false;
    if (year % 400 == 0)
        res = true;
    return res;
}
int date(int d, int m, int y)
{
    int k = d;
    if (vys(y) && (m > 2))
        k += y * 366;
    else k += y * 365;
    switch (m - 1)
    {
    case 12: k += 31;
    case 11: k += 30;
    case 10: k += 31;
    case  9: k += 30;
    case  8: k += 31;
    case  7: k += 31;
    case  6: k += 30;
    case  5: k += 31;
    case  4: k += 30;
    case  3: k += 31;
    case  2: k += 28;
    case  1: k += 31;
    }
    return k;
}
int difference(int day1, int day2, int mon1, int mon2, int year1, int year2)
{
    int k = date(day2, mon2, year2) - date(day1, mon1, year1) + 1;
    return k;
}
void main()
{
    int d1, d2, m1, m2, y1, y2;
    cout << "Input first day: ";
    cin >> d1;
    cout << "Input first month: ";
    cin >> m1;
    cout << "Input first year: ";
    cin >> y1;
    cout << "Input second day: ";
    cin >> d2;
    cout << "Input second month: ";
    cin >> m2;
    cout << "Input second year: ";
    cin >> y2;
    cout << "Between these two dates are " << difference(d1, d2, m1, m2, y1, y2) << " days\n";
}
   ///////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
const int SIZE = 10;
double averege(int array[][SIZE])
{
    double SUMMA = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            SUMMA += array[i][j];
    return SUMMA / (SIZE * SIZE);
}
void Print(int array[][SIZE])
{
    cout << " Array" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << array[i][j] << "\t";
        cout << endl;
    }
}
void Set(int array[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            array[i][j] = rand() % 100;
}

void main()
{
    int a[SIZE][SIZE];
    Set(a);
    Print(a);
    cout << "Average = " << averege(a) << endl;
    system("pause");
    return 0;

}


/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void header();

void init_array(int array[], size_t size_array);
void print_array(int array[], size_t size_array);
void pozitiv_number(int array[], size_t size_array);
void negativ_number(int array[], size_t size_array);
void zero_number(int array[], size_t size_array);
void words_ending_1(int num);
void words_ending_2(int num);
void words_ending_3(int num);


int main()

 {
    setlocale(LC_ALL, "Rus");
    cout << endl;
    header();
    cout << endl << endl << endl;
    srand(static_cast<size_t>(time(NULL)));
    const size_t size_array = 5;
    int array_a[size_array];

    init_array(array_a, size_array);
    print_array(array_a, size_array);

    pozitiv_number(array_a, size_array);
    negativ_number(array_a, size_array);
    zero_number(array_a, size_array);

    cout << endl << endl << endl;
    system("pause");
    system("cls");
    return(0);
}

void header()
{
    cout << endl;
    cout << "\n\tОсновы программирования на языке С++.\n";
    cout << "\tТема:  Функции. Передача массивов внутрь функции.\n\n";
    cout << "\tНаписать функцию, определяющую количество положительных, отрицательных и нулевых элементов передаваемого ей массива.\n";
    cout << endl;
}

void init_array(int array[], size_t size_array)
{
    for (int i = 0; i < size_array; i++)
    {
        array[i] = -10 + rand() % 20;
    }
}

void print_array(int array[], size_t size_array)
{
    for (int i = 0; i < size_array; i++)
    {
        cout << "\t" << array[i];
        if ((i + 1) % 10 == 0)
        {
            cout << "\n";
        }
    }
    cout << endl;
}

void pozitiv_number(int array[], size_t size_array)
{
    int temp = 0;
    int num = 0;
    for (int i = 0; i < size_array; i++)
    {
        num = i;
        if ((array[i]) > 0)
        {
            temp++;
        }
    }
    cout << "\tВ массиве находится " << temp;
    words_ending_2(temp);
    words_ending_1(temp);
    cout << ".\n";
}

void negativ_number(int array[], size_t size_array)
{
    int temp = 0;
    int num = 0;
    for (int i = 0; i < size_array; i++)
    {
        num = i;
        if ((array[i]) < 0)
        {
            temp++;
        }
    }
    cout << "\tВ массиве находится " << temp;
    words_ending_3(temp);
    words_ending_1(temp);
    cout << ".\n";
}

void zero_number(int array[], size_t size_array)
{
    int temp = 0;
    int num = 0;
    for (int i = 0; i < size_array; i++)
    {
        num = i;
        if ((array[i]) == 0)
        {
            temp++;
        }
    }
    cout << "\tВ массиве находится " << temp;
    words_ending_1(temp);
    cout << " с нулевым значением.\n";
}

void words_ending_1(int num)
{
    const std::string base = "чис";
    const std::string end1 = "ло";
    const std::string end2 = "ла";
    const std::string end3 = "ел";
    if (((num % 10) == 1) & ((num % 100) != 11)) // числа x1 & != (% 11)
    {
        std::cout << " " << base << end1;
    }
    else if ((((num % 10) > 1) & ((num % 10) < 5)) & !((((num % 100) > 11) & ((num % 100) < 15)))) // числа x2, x3, x4 & != (% 12, 13, 14)
    {
        std::cout << " " << base << end2;
    }
    else
    {
        std::cout << " " << base << end3; // все остальные
    }
}

void words_ending_2(int num)
{
    const std::string base_1 = "положительн";
    const std::string end1_1 = "ое";
    const std::string end2_1 = "ых";
    const std::string end3_1 = "ых";
    if (((num % 10) == 1) & ((num % 100) != 11)) // числа x1 & != (% 11)
    {
        std::cout << " " << base_1 << end1_1;
    }
    else if ((((num % 10) > 1) & ((num % 10) < 5)) & !((((num % 100) > 11) & ((num % 100) < 15)))) // числа x2, x3, x4 & != (% 12, 13, 14)
    {
        std::cout << " " << base_1 << end2_1;
    }
    else
    {
        std::cout << " " << base_1 << end3_1; // все остальные
    }
}

void words_ending_3(int num)
{
    const std::string base_2 = "отрицательн";
    const std::string end1_2 = "ое";
    const std::string end2_2 = "ых";
    const std::string end3_2 = "ых";
    if (((num % 10) == 1) & ((num % 100) != 11)) // числа x1 & != (% 11)
    {
        std::cout << " " << base_2 << end1_2;
    }
    else if ((((num % 10) > 1) & ((num % 10) < 5)) & !((((num % 100) > 11) & ((num % 100) < 15)))) // числа x2, x3, x4 & != (% 12, 13, 14)
    {
        std::cout << " " << base_2 << end2_2;
    }
    else
    {
        std::cout << " " << base_2 << end3_2; // все остальные
    }
}



