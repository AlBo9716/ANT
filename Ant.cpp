//Программа для определения координат клеток, достпуных муравью, и их количества
//P.S. Мои размышления относительно решения задания описаны в файле README.md
#include <iostream>
#include <vector>
#include <string> 

using namespace std;

void main(); //Функция выполнения программы
int sum_digits(int n); //Функция разбивает числа на разряды и суммирует их
int sum2_digits(int k, int l);//Функция суммирует вес 2-х чисел
vector<string> coordXY(int x, int y); //Функция поиска координат клеток, по которым можно ходить


void main()
{
    setlocale(LC_ALL, "");
    int x0 = 1000, y0 = 1000;
    cout << "Координаты доступных клеток:" << endl << endl;
    for (string coord : coordXY(x0,y0))
        cout << coord << endl;
    cout << endl << "Количество доступных клеток: " << coordXY(x0, y0).size() << endl << endl;
    system("pause");
}

int sum_digits(int n) {
    int result = 0;
    while (n != 0)
    {
        result += n % 10;
        n /= 10;
    }
    return result;
 }

int sum2_digits(int k, int l)
{
    int result = 0;
    result = sum_digits(k) + sum_digits(l);
    return result;
}

vector<string> coordXY(int x, int y) {
    int x1 = x;
    vector<string> result;
    //Сначала после каждого шага цикла будем увеличивать значение X на 1, а Y оставим прежним,
    // пока не найдем координаты всех клеток при Y=1000
    while (!(sum2_digits(x, y) > 19)) {
        result.push_back("(" + to_string(x) + "," + to_string(y) + ")");
        x++;
        //Теперь увеличим значение Y на 1, и дальше снова по циклу. 
        // Итак до тех пор, пока не найдем координаты всех клеток, подходящих условию
        if (sum2_digits(x, y) > 19)
            x = x1, y++;
    }
    return result;
}