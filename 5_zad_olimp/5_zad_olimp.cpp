
#include <vector>
#include <string>
#include <iostream>
using namespace std;


int main()
{
    short x,y,amb_x =-1,amb_y=-1,size,koef;
    //1 строка
    cin >> y;
    cin >> x;
    cin >> amb_x;
    cin >> amb_y;
    cin >> size;
    cin >> koef;

    vector <vector <int>> field_cost;
    field_cost.resize(x);
    for (int i=0; i < x; i++) { //установление размерности матрицы
        field_cost[i].resize(y);
    }
    vector <vector<int>> field_mass = field_cost;
    vector <vector <int>> field_price = field_cost;
    for (int i = 0; i < x; i++) { // заполнение вектора обьема клеток
        for (int k = 0; k < y; k++) {
            short num;
            cin >> num;
            field_mass[i][k] = num;
        }
    }

    for (int i = 0; i < x; i++) { // заполнение вектора цены за тону на клетке
        for (int k = 0; k < y; k++) {
            short num;
            cin >> num;
            field_cost[i][k] = num;
        }
    }
    
    for (int i = 0; i < x; i++) { // заполнение вектора стоимости пукупки + доставки на клетке
        for (int k = 0; k < y; k++) {
            field_price [i][k] = field_cost[k][i]*field_mass[k][i];//цена покупки всего урожая
            short dostavka=koef*(abs(amb_x-k)+abs(amb_y-i)); // цена доставки до амбара
            field_price[i][k] += dostavka;
        }
    }
    unsigned int cost = 0 ,mass=0;


    short min=10000, min_x, min_y;
    for (mass; mass < size;) {
        for (int i = 0; i < x; i++) {
            for (int k = 0; k < y; k++) {
                if (field_price[i][k] < min) {
                    if (i != amb_x && k != amb_y) {
                        min = field_price[i][k];
                        field_price[i][k] = 100000;
                    }
                }
            }
        }
        mass += min;
    }
    cout << mass - min;
    // сортировать ничего нельзя ,т.к. потеряется свзязь с массой ,которую нужно считать!!!

}
