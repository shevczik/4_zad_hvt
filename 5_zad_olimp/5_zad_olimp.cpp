
#include <vector>
#include <string>
#include <iostream>
using namespace std;


int main()
{
    short x,y,amb_x ,amb_y,size,koef;
    //1 строка
    cin >> y;
    cin >> x;
    cin >> amb_x;
    cin >> amb_y;
    cin >> size;
    cin >> koef;
    amb_x--;
    amb_y--;

    vector <vector <int>> field_cost;
    field_cost.resize(x);
    for (int i=0; i < x; i++) { //установление размерности матрицы
        field_cost[i].resize(y);
    }
    vector <vector<int>> field_mass = field_cost;
    vector <vector <int>> field_price = field_cost;
    for (int i = 0; i < y; i++) { // заполнение вектора обьема клеток
        for (int k = 0; k < x; k++) {
            short num;
            cin >> num;
            field_mass[k][i] = num;
        }
    }

    for (int i = 0; i < y; i++) { // заполнение вектора цены за тону на клетке
        for (int k = 0; k < x; k++) {
            short num;
            cin >> num;
            field_cost[k][i] = num;
        }
    }
    
    for (int i = 0; i < x; i++) { // заполнение вектора стоимости пукупки + доставки на клетке
        for (int k = 0; k < y; k++) {
            field_price [i][k] = field_cost[i][k]*field_mass[i][k];//цена покупки всего урожая
            unsigned short dostavka=koef*(abs(amb_x-k)+abs(amb_y-i)); // цена доставки до амбара
            field_price[i][k] += dostavka;
        }
    }
     short cost = 0 ,mass=0;


    short min=10000, min_x, min_y;
    for (; true;) {//поиск минимальных значений 
        for (int i = 0; i < x; i++) {
            for (int k = 0; k < y; k++) {
                if (field_price[i][k] < min && field_price[i][k] != 0) {
                        min = field_price[i][k];
                        min_x = i;
                        min_y = k;
                }
            }
        }
        mass += field_mass[min_x][min_y];
        field_price[min_x][min_y] = 10000;
        if (mass > size) {
            cout << cost;
            return 1;
        }
        cost += min;
        min = 100000;
        
    }
    


}
