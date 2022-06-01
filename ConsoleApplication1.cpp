include <iostream> 
#include<string> 
#include<math.h> 
#include<stack> 
#include<list> 
#include<iterator> 
#include<vector> 
#include<fstream> 
#include <ctime>
#include<windows.h>
#include<time.h>

using namespace std;

void rand_generation(char mas[10][10], int size/*размер корабля*/, int num_ship/*колличество кораблей*/) {

    int x, y;
    int dir = 0;
    int count_ship = 0;
    int ch = 0;
    while (count_ship < num_ship) {

        ch++;
        if (ch >= 1000) {
            break;
        }
        x = rand() & 10;
        y = rand() % 10;
        int tmp_x = x;
        int tmp_y = y;
        dir = rand() % 4;
        bool set = 1;
        for (int i = 0; i < size; i++) {
            if (x < 0 || y < 0 || x >= 10 || y >= 10) {
                set = 0; break;
            }
            if (mas[x][y] == '#' ||
                mas[x][y + 1] == '#' ||
                mas[x][y - 1] == '#' ||
                mas[x + 1][y] == '#' ||
                mas[x + 1][y + 1] == '#' ||
                mas[x + 1][y - 1] == '#' ||
                mas[x - 1][y] == '#' ||
                mas[x - 1][y + 1] == '#' ||
                mas[x - 1][y - 1] == '#') {
                set = 0; break;
            }
            switch (dir) {
            case 0:
                x++;
                break;
            case 1:
                y++;
                break;
            case 2:
                x--;
                break;
            case 3:
                y--;
                break;
            }
        }
        if (set == 1) {
            x = tmp_x;
            y = tmp_y;
            for (int i = 0; i < size; i++) {
                mas[x][y] = '#';
                switch (dir) {
                case 0:
                    x++;
                    break;
                case 1:
                    y++;
                    break;
                case 2:
                    x--;
                    break;
                case 3:
                    y--;
                    break;
                }
            }
            count_ship++;
        }
    }

    count_ship = 0;

}
class SeaBattle {
public:
    int value;
    char map[10][10];
    string name;
    char map2[10][10];
    SeaBattle() {

    }
    SeaBattle(int a) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                map[i][k] = '0';
                map2[i][k] = '0';
            }
        }
        value = 0;
    }
    virtual void initialization(SeaBattle& A) {

    }
    void Show() {
        cout << "   A" << " B " << "C " << "D " << "E " << "F " << "G " << "H " << "I " << "J " << endl;
        int l = 0;
        int m = 1;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (l == 0 && m != 10) {
                    cout << m << "  " << map[i][j] << " ";
                    l++;
                    m++;
                }
                else if (m == 10 && l == 0) {
                    cout << m << " " << map[i][j] << " ";
                    l++;
                    m++;
                }
                else {
                    cout << map[i][j] << " ";
                }
            }
            cout << endl;
            l = 0;
        }
    }
    void ShowInformationOfVrag() {
        cout << "   A" << " B " << "C " << "D " << "E " << "F " << "G " << "H " << "I " << "J " << endl;
        int l = 0;
        int m = 1;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (l == 0 && m != 10) {
                    cout << m << "  " << map2[i][j] << " ";
                    l++;
                    m++;
                }
                else if (m == 10 && l == 0) {
                    cout << m << " " << map2[i][j] << " ";
                    l++;
                    m++;
                }
                else {
                    cout << map2[i][j] << " ";
                }
            }
            cout << endl;
            l = 0;
        }
    }
    SeaBattle& operator=(const SeaBattle& other) {
        value = 2;
        return *this;
    }
};
class One_gener :public SeaBattle {
public:
    friend SeaBattle;
    One_gener() {

    }
    void initialization(SeaBattle& A)override {
        rand_generation(A.map, 1, 4);
    }
};
class Two_gener :public SeaBattle {
public:
    Two_gener() {

    }
    void initialization(SeaBattle& A)override {
        rand_generation(A.map, 2, 3);
    }
};
class Three_gener :public SeaBattle {
public:
    Three_gener() {

    }
    void initialization(SeaBattle& A)override {
        rand_generation(A.map, 3, 2);
    }
};
class Four_gener :public SeaBattle {
public:
    Four_gener() {

    }
    void initialization(SeaBattle& A)override {
        rand_generation(A.map, 4, 1);
    }

};
int h(char a) {
    if (a == 'A') {
        return 0;
    }
    else if (a == 'B') {
        return 1;
    }
    else if (a == 'C') {
        return 2;
    }
    else if (a == 'D') {
        return 3;
    }
    else if (a == 'E') {
        return 4;
    }
    else if (a == 'F') {
        return 5;
    }
    else if (a == 'G') {
        return 6;
    }
    else if (a == 'H') {
        return 7;
    }
    else if (a == 'I') {
        return 8;
    }
    else if (a == 'J') {
        return 9;
    }
}
void f() {
    string j;
    ofstream b;
    b.open("W:\\file1.txt");


    b << "\t\t\t\t\t\tHello People";
    b.close();
    ifstream j1;
    j1.open("W:\\file1.txt");
    while (getline(j1, j)) {
        cout << j << endl;
    }
    j1.close();
    cout << "\t\t\t\t\t\tSeaBattle!!!" << endl;
    ifstream a;

    cout << "\t\t\t\t\t\tRules!!!" << endl;
    cout << "Принцип «Морского боя» очень прост — вы расставляете свои корабли на поле 10х10, оппонент расставляет свои. Далее вы по очереди делаете «выстрелы», называя те или иные координаты поля — и оппонент отвечает на каждый «выстрел» словами «попал», «промахнулся» или «потопил»." << endl;

    while (getline(a, j)) {
        cout << j << endl;
    }

}
void zv(int x, int y, SeaBattle& BOT, SeaBattle& Obj) {
    BOT.map[x][y] = '&';
    if (x + 1 < 10 && BOT.map[x + 1][y] != '&') {
        BOT.map[x + 1][y] = '*';
    }
    if (y + 1 < 10 && BOT.map[x][y + 1] != '&') {
        BOT.map[x][y + 1] = '*';
    }
    if (x - 1 >= 0 && BOT.map[x - 1][y] != '&') {
        BOT.map[x - 1][y] = '*';
    }
    if (y - 1 >= 0 && BOT.map[x][y - 1] != '&') {
        BOT.map[x][y - 1] = '*';
    }
    if (x + 1 < 10 && y - 1 >= 0 && BOT.map[x + 1][y - 1] != '&') {
        BOT.map[x + 1][y - 1] = '*';
    }
    if (x - 1 >= 0 && y + 1 < 10 && BOT.map[x - 1][y + 1] != '&') {
        BOT.map[x - 1][y + 1] = '*';
    }
    if (y + 1 < 10 && x + 1 < 10 && BOT.map[x + 1][y + 1] != '&') {
        BOT.map[x + 1][y + 1] = '*';
    }
    if (y - 1 >= 0 && x - 1 >= 0 && BOT.map[x - 1][y - 1] != '&') {
        BOT.map[x - 1][y - 1] = '*';
    }
    Obj.map2[x][y] = '&';
    if (x + 1 < 10 && Obj.map2[x + 1][y] != '&') {
        Obj.map2[x + 1][y] = '*';
    }
    if (y + 1 < 10 && Obj.map2[x][y + 1] != '&') {
        Obj.map2[x][y + 1] = '*';
    }
    if (x - 1 >= 0 && Obj.map2[x - 1][y] != '&') {
        Obj.map2[x - 1][y] = '*';
    }
    if (y - 1 >= 0 && Obj.map2[x][y - 1] != '&') {
        Obj.map2[x][y - 1] = '*';
    }
    if (y - 1 >= 0 && x + 1 < 10 && Obj.map2[x + 1][y - 1] != '&') {
        Obj.map2[x + 1][y - 1] = '*';
    }
    if (y + 1 < 10 && x - 1 >= 0 && Obj.map2[x - 1][y + 1] != '&') {
        Obj.map2[x - 1][y + 1] = '*';
    }
    if (y + 1 < 10 && x + 1 < 10 && Obj.map2[x + 1][y + 1] != '&') {
        Obj.map2[x + 1][y + 1] = '*';
    }
    if (y - 1 >= 0 && x - 1 >= 0 && Obj.map2[x - 1][y - 1] != '&') {
        Obj.map2[x - 1][y - 1] = '*';
    }
}
bool Nalichie_ship(SeaBattle& a) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (a.map[i][j] == '#') {
                return true;
            }
        }
    }
    return false;
}
bool check(int x, int y, SeaBattle& BOT, SeaBattle& Obj) {
    int a = 0;
    if (BOT.map[x][y - 1] != '#' && BOT.map[x][y - 1] != '!' && y - 1 >= 0 &&
        BOT.map[x - 1][y] != '#' && BOT.map[x - 1][y] != '!' && x - 1 >= 0 &&
        BOT.map[x][y + 1] != '#' && BOT.map[x][y + 1] != '!' && y + 1 < 10 &&
        BOT.map[x + 1][y] != '#' && BOT.map[x + 1][y] != '!' && x + 1 < 10) {
        zv(x, y, BOT, Obj);
        if (BOT.map[x - 1][y] == '!' && x - 1 >= 0) {
            BOT.map[x - 1][y] = '&';
            if (BOT.map[x - 2][y] == '!' && x - 2 >= 0) {
                BOT.map[x - 2][y] = '&';
                if (BOT.map[x - 3][y] == '!' && x - 3 >= 0) {
                    BOT.map[x - 3][y] = '&';
                }
            }
        }
        if (BOT.map[x + 1][y] == '!' && x + 1 < 10) {
            BOT.map[x + 1][y] = '&';
            if (BOT.map[x + 2][y] == '!' && x + 2 < 10) {
                BOT.map[x + 2][y] = '&';
                if (BOT.map[x + 3][y] == '!' && x + 3 < 10) {
                    BOT.map[x + 3][y] = '&';
                }
            }
        }
        if (BOT.map[x][y - 1] == '!' && y - 1 >= 0) {
            BOT.map[x][y - 1] = '&';
            if (BOT.map[x][y - 2] == '!' && y - 2 >= 0) {
                BOT.map[x][y - 2] = '&';
                if (BOT.map[x][y - 3] == '!' && y - 3 >= 0) {
                    BOT.map[x][y - 3] = '&';
                }
            }
        }
        if (BOT.map[x][y + 1] == '!' && y + 1 >= 0) {
            BOT.map[x][y + 1] = '&';
            if (BOT.map[x][y + 2] == '!' && y + 2 >= 0) {
                BOT.map[x][y + 2] = '&';
                if (BOT.map[x][y + 3] == '!' && y + 3 >= 0) {
                    BOT.map[x][y + 3] = '&';
                }
            }
        }
        return true;
    }
    else if (BOT.map[x + 1][y] == '#' && x + 1 < 10) {
        return false;
    }
    else if (BOT.map[x][y + 1] == '#' && y + 1 < 10) {
        return false;
    }
    else if (BOT.map[x - 1][y] == '#' && x - 1 >= 0) {
        return false;
    }
    else if (BOT.map[x][y - 1] == '#' && y - 1 >= 0) {
        return false;
    }
    else {
        if (BOT.map[x - 1][y] == '!' && x - 1 >= 0) {
            BOT.map[x - 1][y] = '&';
            if (BOT.map[x - 2][y] == '!' && x - 2 >= 0) {
                BOT.map[x - 2][y] = '&';
                if (BOT.map[x - 3][y] == '!' && x - 3 >= 0) {


                    BOT.map[x - 3][y] = '&';
                }
            }
        }
        if (BOT.map[x + 1][y] == '!' && x + 1 < 10) {
            BOT.map[x + 1][y] = '&';
            if (BOT.map[x + 2][y] == '!' && x + 2 < 10) {
                BOT.map[x + 2][y] = '&';
                if (BOT.map[x + 3][y] == '!' && x + 3 < 10) {
                    BOT.map[x + 3][y] = '&';
                }
            }
        }
        if (BOT.map[x][y - 1] == '!' && y - 1 >= 0) {
            BOT.map[x][y - 1] = '&';
            if (BOT.map[x][y - 2] == '!' && y - 2 >= 0) {
                BOT.map[x][y - 2] = '&';
                if (BOT.map[x][y - 3] == '!' && y - 3 >= 0) {
                    BOT.map[x][y - 3] = '&';
                }
            }
        }
        if (BOT.map[x][y + 1] == '!' && y + 1 >= 0) {
            BOT.map[x][y + 1] = '&';
            if (BOT.map[x][y + 2] == '!' && y + 2 >= 0) {
                BOT.map[x][y + 2] = '&';
                if (BOT.map[x][y + 3] == '!' && y + 3 >= 0) {
                    BOT.map[x][y + 3] = '&';
                }
            }
        }
        zv(x, y, BOT, Obj);
        return true;
    }
}
void zamena(SeaBattle& BOT, SeaBattle& Obj) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (BOT.map[i][j] == '&') {
                zv(i, j, BOT, Obj);
            }
        }
    }
}
int povtor(SeaBattle& Obj, SeaBattle& BOT) {
    system("cls");
    cout << "Вашe поле(" << Obj.name << ")" << endl;
    Obj.Show();
    cout << "Информация о поле вашего врага(" << Obj.name << ")" << endl;
    Obj.ShowInformationOfVrag();
    int x; char y;
    cout << "Введите координату(букву) : "; cin >> y; cout << endl;
    cout << "Введите координату(цифру) : "; cin >> x; cout << endl;
    if (BOT.map[x - 1][h(y)] == '#') {
        BOT.map[x - 1][h(y)] = '!';
        Obj.map2[x - 1][h(y)] = '!';
        if (check(x - 1, h(y), BOT, Obj)) {
            zamena(BOT, Obj);
            cout << "Корабль убит!" << endl;
        }
        else if (!check(x - 1, h(y), BOT, Obj)) {
            cout << "Корабль ранен" << endl;
        }
        if (!Nalichie_ship(BOT)) {
            cout << "Выйграл человек" << endl;
            return 0;
        }
        povtor(Obj, BOT);
    }
    else if (BOT.map[x - 1][h(y)] == '!' ||
        BOT.map[x - 1][h(y)] == '*') {
        povtor(Obj, BOT);
    }
    else if (BOT.map[x - 1][h(y)] == '0') {
        cout << "Вы промазали" << endl;
        BOT.map[x - 1][h(y)] = '*';
        Obj.map2[x - 1][h(y)] = '*';
    }
    return 0;
}
int povtor2(SeaBattle& Obj, SeaBattle& BOT) {
    system("cls");
    cout << "Вашe поле(" << Obj.name << ")" << endl;
    Obj.Show();
    cout << "Информация о поле вашего врага(" << Obj.name << ")" << endl;
    Obj.ShowInformationOfVrag();
    int x1; char y1;
    int c1;
    x1 = rand() % 10 + 1;
    c1 = 65 + rand() % 10;
    y1 = c1;
    cout << "Введите координату(букву) : "; cout << char(y1); cout << endl;
    cout << "Введите координату(цифру) : "; x1; cout << x1; cout << endl;
    if (BOT.map[x1 - 1][h(y1)] == '#') {
        BOT.map[x1 - 1][h(y1)] = '!';
        Obj.map2[x1 - 1][h(y1)] = '!';
        if (check(x1 - 1, h(y1), BOT, Obj)) {
            zamena(BOT, Obj);
            cout << "Корабль убит!" << endl;
        }
        else if (!check(x1 - 1, h(y1), BOT, Obj)) {
            cout << "Корабль ранен" << endl;
        }
        if (!Nalichie_ship(BOT)) {
            cout << "Выйграл человек" << endl;
            return 0;
        }
        povtor(Obj, BOT);
    }
    else if (BOT.map[x1 - 1][h(y1)] == '!' ||
        BOT.map[x1 - 1][h(y1)] == '*') {
        povtor(Obj, BOT);
    }
    else if (BOT.map[x1 - 1][h(y1)] == '0') {
        cout << "Вы промазали" << endl;
        BOT.map[x1 - 1][h(y1)] = '*';
        Obj.map2[x1 - 1][h(y1)] = '*';
    }
    return 0;
}
int tmain(SeaBattle& Obj, SeaBattle& Obj2) {
    int x; char y;
    while (true) {

        cout << "Ходит " << Obj.name << endl;
        cout << "Вашe поле" << endl;
        Obj.Show();
        cout << "Информация о поле вашего врага" << endl;
        Obj.ShowInformationOfVrag();
        cout << "Введите координату(букву) : "; cin >> y; cout << endl;
        cout << "Введите координату(цифру) : "; cin >> x; cout << endl;
        if (Obj2.map[x - 1][h(y)] == '#') {
            Obj2.map[x - 1][h(y)] = '!';
            Obj.map2[x - 1][h(y)] = '!';
            if (check(x - 1, h(y), Obj2, Obj)) {
                zamena(Obj2, Obj);
                cout << "Корабль убит!" << endl;
            }
            else if (!check(x - 1, h(y), Obj2, Obj)) {
                cout << "Корабль ранен" << endl;
            }
            if (!Nalichie_ship(Obj2)) {
                system("cls");

                cout << "\t\t\t\tВЫЙГРАЛ " << Obj.name << endl;
                return 0;
            }
            Sleep(3000);
            povtor(Obj, Obj2);
        }
        else if (Obj2.map[x - 1][h(y)] == '!' || Obj2.map[x - 1][h(y)] == '*') {
            povtor(Obj, Obj2);
        }
        else if (Obj2.map[x - 1][h(y)] == '0') {
            cout << "Вы промазали" << endl;
            Obj2.map[x - 1][h(y)] = '*';
            Obj.map2[x - 1][h(y)] = '*';
        }
        cout << Obj.name << ", отойди не подсматривай, сейчас будет ходить " << Obj2.name << endl;
        system("pause");
        system("cls");


        cout << "Ходит " << Obj2.name << endl;
        cout << "Ваша поле" << endl;
        Obj2.Show();
        cout << "Информация о поле вашего врага" << endl;
        Obj2.ShowInformationOfVrag();
        cout << "Введите координату(букву) : "; cin >> y; cout << endl;
        cout << "Введите координату(цифру) : "; cin >> x; cout << endl;
        if (Obj.map[x - 1][h(y)] == '#') {
            Obj.map[x - 1][h(y)] = '!';
            Obj2.map2[x - 1][h(y)] = '!';
            if (check(x - 1, h(y), Obj, Obj2)) {
                zamena(Obj2, Obj);
                cout << "Корабль убит!" << endl;
            }
            else if (!check(x - 1, h(y), Obj2, Obj)) {
                cout << "Корабль ранен" << endl;
            }
            if (!Nalichie_ship(Obj)) {
                system("cls");

                cout << "\t\t\t\tВЫЙГРАЛ " << Obj2.name << endl;

                return 0;
            }
            povtor(Obj2, Obj);
        }
        else if (Obj.map[x - 1][h(y)] == '!' || Obj.map[x - 1][h(y)] == '*') {
            povtor(Obj2, Obj);
        }
        else if (Obj.map[x - 1][h(y)] == '0') {
            cout << "Вы промазали" << endl;
            Obj.map[x - 1][h(y)] = '*';
            Obj2.map2[x - 1][h(y)] = '*';
        }
        cout << Obj2.name << ", отойди не подсматривай, сейчас будет ходить " << Obj.name << endl;
        system("pause");
        system("cls");

    }
}
int bmain(SeaBattle& Obj, SeaBattle& Obj2) {
    int x; char y;
    int x1; char y1;
    int c1;
    while (true) {
        srand(time(NULL));
        cout << "Ходит " << Obj.name << endl;
        cout << "Вашe поле" << endl;
        Obj.Show();
        cout << "Информация о поле вашего врага" << endl;
        Obj.ShowInformationOfVrag();
        cout << "Введите координату(букву) : "; cin >> y; cout << endl;
        cout << "Введите координату(цифру) : "; cin >> x; cout << endl;
        if (Obj2.map[x - 1][h(y)] == '#') {
            Obj2.map[x - 1][h(y)] = '!';
            Obj.map2[x - 1][h(y)] = '!';
            if (check(x - 1, h(y), Obj2, Obj)) {
                zamena(Obj2, Obj);
                cout << "Корабль убит!" << endl;
            }
            else if (!check(x - 1, h(y), Obj2, Obj)) {
                cout << "Корабль ранен" << endl;
            }
            if (!Nalichie_ship(Obj2)) {
                system("cls");

                cout << "\t\t\t\tВЫЙГРАЛ " << Obj.name << endl;
                return 0;
            }
            Sleep(3000);
            povtor(Obj, Obj2);
        }
        else if (Obj2.map[x - 1][h(y)] == '!' || Obj2.map[x - 1][h(y)] == '*') {
            povtor(Obj, Obj2);
        }
        else if (Obj2.map[x - 1][h(y)] == '0') {
            cout << "Вы промазали" << endl;
            Obj2.map[x - 1][h(y)] = '*';
            Obj.map2[x - 1][h(y)] = '*';
        }
        cout << Obj.name << ", отойди не подсматривай, сейчас будет ходить " << Obj2.name << endl;
        system("pause");
        system("cls");
        x1 = rand() % 10 + 1;
        c1 = 65 + rand() % 10;
        y1 = c1;


        cout << "Ходит Bot" << endl;
        cout << "Ваша поле" << endl;
        Obj2.Show();
        cout << "Информация о поле вашего врага" << endl;
        Obj2.ShowInformationOfVrag();
        cout << "Введите координату(букву) : "; cout << char(y1); cout << endl;
        cout << "Введите координату(цифру) : "; x1; cout << x1; cout << endl;
        if (Obj.map[x1 - 1][h(y1)] == '#') {
            Obj.map[x1 - 1][h(y1)] = '!';
            Obj2.map2[x1 - 1][h(y1)] = '!';
            if (check(x1 - 1, h(y1), Obj, Obj2)) {
                zamena(Obj2, Obj);
                cout << "Корабль убит!" << endl;
            }
            else if (!check(x1 - 1, h(y1), Obj2, Obj)) {
                cout << "Корабль ранен" << endl;
            }
            if (!Nalichie_ship(Obj)) {
                system("cls");

                cout << "\t\t\t\tВЫЙГРАЛ " << Obj2.name << endl;

                return 0;
            }
            povtor2(Obj2, Obj);
        }
        else if (Obj.map[x1 - 1][h(y1)] == '!' || Obj.map[x1 - 1][h(y1)] == '*') {
            povtor2(Obj2, Obj);
        }
        else if (Obj.map[x1 - 1][h(y1)] == '0') {
            cout << "Вы промазали" << endl;
            Obj.map[x1 - 1][h(y1)] = '*';
            Obj2.map2[x1 - 1][h(y1)] = '*';
        }
        cout << Obj2.name << ", отойди не подсматривай, сейчас будет ходить " << Obj.name << endl;
        system("pause");
        system("cls");

    }
}
void main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int k;
    int h;
    f();
    SeaBattle Obj(1);
    SeaBattle Obj2(1);
    One_gener a1;
    Two_gener a2;
    Three_gener a3;
    Four_gener a4;
    a1.initialization(Obj);
    a2.initialization(Obj);
    a3.initialization(Obj);
    a4.initialization(Obj);
    a1.initialization(Obj2);
    a2.initialization(Obj2);
    a3.initialization(Obj2);
    a4.initialization(Obj2);
    Obj2 = Obj;
    cout << "Хотите ли вы начать игру с другом?(1-Da,2- No)" << endl;
    cin >> k;

    if (k == 1) {
        cout << "В ИГРЕ УЧАВСТВУЕТ " << Obj2.value << " ИГРОКA" << endl;
        cout << "Напишите имя первого игрока : "; cin >> Obj.name; cout << endl;
        cout << "Напишите имя второго игрока : "; cin >> Obj2.name; cout << endl;
        cout << "Первый ";
        int RAND = rand() % 10;
        if (RAND < 10) {
            tmain(Obj, Obj2);
        }
        else {
            tmain(Obj2, Obj);
        }
    }
    else if (k == 2) {
        cout << "Ну ладно, приходите еще!" << endl;
        cout << "Может хотите вы начать игру с ботом?(1-Da,2- No)" << endl;
        cin >> h;
        if (h == 1) {
            cout << "В ИГРЕ УЧАВСТВУЕТ " << Obj2.value << " ИГРОКA" << endl;
            cout << "Напишите имя первого игрока : "; cin >> Obj.name; cout << endl;
            cout << "Напишите имя второго игрока :  Bot"; cout << endl;
            cout << "Первый ";
            int RAND = rand() % 10;
            if (RAND < 10) {
                bmain(Obj, Obj2);
            }
            else {
                bmain(Obj2, Obj);
            }
        }
        else if (h == 2) {
            cout << "Ну ладно, приходите еще!" << endl;
            exit(0);
        }
    }
    }
