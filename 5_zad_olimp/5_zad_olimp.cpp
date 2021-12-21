#include <vector>
#include <iostream>
using namespace std;
int main()
{
    short x,y,amb_x ,amb_y,size,koef;
    cin >> y;cin >> x;cin >> amb_x;
    cin >> amb_y;cin >> size;cin >> koef;
    amb_x--;
    amb_y--;
    vector <vector <int>> field_cost;
    field_cost.resize(x);
    for (int i=0; i < x; i++) { //установление размерности матрицы
        field_cost[i].resize(y);
    }
    vector <vector<int>> field_mass = field_cost;
    for (int k = 0; k < y; k++) { // заполнение вектора обьема клеток
        for (int i = 0; i < x; i++) {
            short num;
            cin >> num;
            field_mass[i][k] = num;
        }
    }
    for (int k = 0; k < y; k++) { // заполнение вектора цены за тону на клетке
        for (int i = 0; i < x; i++) {
            short num;
            cin >> num;
            unsigned short dostavka = koef * (abs(amb_x - i) + abs(amb_y - k)); // цена доставки до амбара
            field_cost[i][k] = dostavka + num;
        }
    }
     short cost = 0 ,mass=0;
    short min= SHRT_MAX, min_x, min_y;
    for (; true;) { //поиск минимальных значений 
        for (int k = 0; k < y; k++) {
            for (int i = 0; i < x; i++) {
                if (field_cost[i][k] < min ) {
                        min = field_cost[i][k];
                        min_x = i;
                        min_y = k;
                }
            }
        }
        mass += field_mass[min_x][min_y];
        field_cost[min_x][min_y] = SHRT_MAX;
        if (mass > size) {
            cost += (size-mass+field_mass[min_x][min_y]) * min;
            cout << cost;
            return 1;
        }
        cost += min* field_mass[min_x][min_y];
        min = SHRT_MAX;
        
    }
}
