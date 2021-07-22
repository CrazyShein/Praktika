#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <limits>
#include <regex>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;
int CorrectInt()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coord, coord_2;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    coord = csbi.dwCursorPosition;
    int number;
    bool correct = true;
    while (true)
    {
        correct = true;
        cin >> number;
        if (cin.get() != '\n')
            correct = false;
        if (cin.fail() && !correct && number <= 0)
        {
            coord_2.X = csbi.dwCursorPosition.X + 10;
            coord_2.Y = csbi.dwCursorPosition.Y;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_2);

            cout << "Ошибка!";
            system("pause");

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            for (int i = 0; i < 74; i++)
                cout << " ";

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            std::cin.clear();
            if (cin.fail() || !correct)
                cin.ignore(32767, '\n');
        }
        else
            return number;
    }
}
struct kratko {
    string nachalniy_put;
    string promish_punkt;
    string konec;
    float vrema_otpravki = 0;
    float vrema_pribitia = 0;
    float rasstoyanie = 0;
    int svobodnie_mesta = 0;
    int cena = 0;
};
void init(vector <kratko>* Day)
{
    Day->push_back({ "Павлоград","Днепр","Киев",11.05,14.35,76.8,1,106 });
    Day->push_back({ "Павлоград","Нету","Днепр",14.15,15.55,54.3,5,65 });
    Day->push_back({ "Павлоград","Нету","Харьков",19.45,3.35,243.3,10,68 });
    Day->push_back({ "Павлоград","Покровск","Донецк",11.15,14.35,189.1,12,90 });
    Day->push_back({ "Павлоград","Нету","Полтава",11.05,14.35,224.1,6,70 });
    Day->push_back({ "Павлоград","Покровск"," Краматорск",19.35,22.45,172.5,5,96 });
    Day->push_back({ "Павлоград","Нету","Одесса",8.25,14.55,129.2,4,102 });
    Day->push_back({ "Павлоград","Полтава","Харьков",6.25,9.55,304.2,15,97 });
    Day->push_back({ "Павлоград","Нету","Киев",6.25,9.55,76.8,0,79 });
    Day->push_back({ "Павлоград","Нету","Николаев",11.25,19.35,204.2,3,86 });
}
void showmenu()
{
    cout << "Вас приветствует автовокзал Павлограда " << endl << endl;
    cout << "Пожайлуста выберите один из пунктов" << endl << endl;
    cout << "1.Ввод новой записи" << endl << endl;
    cout << "2.Краткая информация" << endl << endl;
    cout << "3.Редактирование новой записи" << endl << endl;
    cout << "4.Удаление записей" << endl << endl;
    cout << "5.Поиск по конечному пути" << endl << endl;
    cout << "6.Сортировка за временем отправки" << endl << endl;
    cout << "7.Обработка за условием" << endl << endl;
    cout << "8.Запись файла" << endl << endl;
    cout << "9.Чтение файла" << endl << endl;
    cout << "10.Выход" << endl << endl;
    cout << "Введите цифру: ";
}
void showmenu8()
{
    system("cls");
    cout << "Пожайлуста выберите один из пунктов" << endl << endl;
    cout << "1.Самый длинный маршрут" << endl << endl;
    cout << "2.Средняя стоимость билетов" << endl << endl;
    cout << "3.Автобусы с наибольшим числом свободных мест." << endl << endl;
    cout << "4.Наименьший маршрут." << endl << endl;
    cout << "5.Вернуться обратно." << endl << endl;
    cout << "Введите цифру: ";
}
void Output(vector <kratko>* Day)
{
    system("cls");
    int y = 1;
    cout.width(74);
    cout << "Автобусы на сегодняшний день" << endl << endl;
    cout << "______________________________________________________________________________________________________________________\n";
    cout << "|№ |Начальный путь|Промежные пункты|    Конец    |Время отправки|Время прибытия|Расстояние|Свободные места|Цена Билета|\n";
    cout << "|__|______________|________________|_____________|______________|______________|__________|_______________|___________|\n";
    for (int i = 0; i <= Day->size() - 1; i++)
    {
        const kratko Put = (*Day)[i];
        cout << "|";
        cout.width(2);
        cout << y++ << "|";
        cout.width(14);
        cout << Put.nachalniy_put << "|";
        cout.width(16);
        cout << Put.promish_punkt << "|";
        cout.width(13);
        cout << Put.konec << "|";
        cout.width(14);
        cout << Put.vrema_otpravki << "|";
        cout.width(14);
        cout << Put.vrema_pribitia << "|";
        cout.width(8);
        cout << Put.rasstoyanie << "км|";
        cout.width(15);
        cout << Put.svobodnie_mesta << "|";
        cout.width(8);
        cout << Put.cena << " $ |\n";
    }
    cout << "|__|______________|________________|_____________|______________|______________|__________|_______________|___________|\n";
}
kratko Input(vector <kratko>* Day)
{
    bool correct = true;
    system("cls");
    kratko temp;
    temp.nachalniy_put = "Павлоград";
    while (1)
    {
        bool isCorrect = true;
        cout << "Промежные пункты - ";
        cin >> temp.promish_punkt;
        for (int i = 0; i < temp.promish_punkt.length(); i++)
            if (temp.promish_punkt[i]<char(192) || temp.promish_punkt[i]>char(255))
                isCorrect = false;
        if (isCorrect)
            break;
        else
            temp.promish_punkt.clear();
    }
    while(1)
    {
        bool isCorrect = true;
        cout << "Конец пути - ";
        cin >> temp.konec;
        for (int i = 0; i < temp.konec.length(); i++)
            if (temp.konec[i]<char(192) || temp.konec[i]>char(255))
                isCorrect = false;
        if (isCorrect)
            break;
        else
            temp.konec.clear();
    }
    while (true)
    {
        cout << "Время отправки - ";
        temp.vrema_otpravki = CorrectInt();
        if (temp.vrema_otpravki >= 0 && temp.vrema_otpravki <= 23.59)
            break;
    }
    while (1)
    {
        cout << "Время прибытия - ";
        temp.vrema_pribitia = CorrectInt();
        if (temp.vrema_pribitia >= 0 && temp.vrema_pribitia <= 23.59)
            break;
    }
    while (1)
    {
        cout << "Расстояние - ";
        temp.rasstoyanie=CorrectInt();
        if (temp.rasstoyanie >= 0 && INT32_MAX)
            break;
    }
    while (1)
    {
        cout << "Свободные места - ";
        temp.svobodnie_mesta= CorrectInt();
        if (temp.svobodnie_mesta >= 0 && temp.svobodnie_mesta <= 36)
            break;
    }
    while (1)
    {
        cout << "Цена Билета - ";
        temp.cena= CorrectInt();
        if (temp.cena >= 0 && temp.cena <= 1000)
            break;
    }
    Day->push_back(temp);
    system("cls");
    return temp;
}
void Swap(vector <kratko>& Day, int f)
{
    system("cls");
    int i=0;
    while (1)
    {

        cout << "\nКуда вы хотите подставить новую запись - ";
        i= CorrectInt();
        if (i > Day.size())
        {
            cout << "Данного пункта не существует." << endl;
            system("pause");
            system("cls");
        }
        if (i <= 0)
        {
            system("cls");
            cout << "Ничего не найдено" << endl;
            system("pause");
            system("cls");
            return;
         
        }
        else
        {
            swap(Day[f - 1], Day[i - 1]);
            break;
        }
    }
    system("cls");
}
void Edit(vector<kratko>* Day)
{
    int D = 0;
    while (1)
    {
        Output(Day);
        cout << "\nКакую из записей вы хотите изменить(за номером)? - ";
        D = CorrectInt();
        if (D > Day->size())
        {
            cout << "Данного пункта не существует." << endl;
            system("pause");
            system("cls");
        }
        else
        {
            kratko temp = (*Day)[D-1];
            system("cls");
            temp.nachalniy_put = "Павлоград";
            while (1)
            {
                bool isCorrect = true;
                cout << "Промежные пункты - ";
                cin >> temp.promish_punkt;
                for (int i = 0; i < temp.promish_punkt.length(); i++)
                    if (temp.promish_punkt[i]<char(192) || temp.promish_punkt[i]>char(255))
                        isCorrect = false;
                if (isCorrect)
                    break;
                else
                    temp.promish_punkt.clear();
            }
            while (1)
            {
                bool isCorrect = true;
                cout << "Конец пути - ";
                cin >> temp.konec;
                for (int i = 0; i < temp.konec.length(); i++)
                    if (temp.konec[i]<char(192) || temp.konec[i]>char(255))
                        isCorrect = false;
                if (isCorrect)
                    break;
                else
                    temp.konec.clear();
            }
            while (true)
            {
                cout << "Время отправки - ";
                temp.vrema_otpravki = CorrectInt();
                if (temp.vrema_otpravki >= 0 && temp.vrema_otpravki <= 23.59)
                    break;
            }
            while (1)
            {
                cout << "Время прибытия - ";
                temp.vrema_pribitia = CorrectInt();
                if (temp.vrema_pribitia >= 0 && temp.vrema_pribitia <= 23.59)
                    break;
            }
            while (1)
            {
                cout << "Расстояние - ";
                temp.rasstoyanie = CorrectInt();
                if (temp.rasstoyanie >= 0 && INT32_MAX)
                    break;
            }
            while (1)
            {
                cout << "Свободные места - ";
                temp.svobodnie_mesta = CorrectInt();
                if (temp.svobodnie_mesta >= 0 && temp.svobodnie_mesta <= 36)
                    break;
            }
            while (1)
            {
                cout << "Цена Билета - ";
                temp.cena = CorrectInt();
                if (temp.cena >= 0 && temp.cena <= 1000)
                    break;
            }
            (*Day)[D - 1] = temp;
            break;
        }
    }
}
void Delete(vector <kratko> &Day)
{
    int z=0;
    string line;
    while (1)
    {
        if (Day.size() == 1)
        {
            system("cls");
            cout << "Нельзя удалить последнюю запись" << endl;
            system("pause");
            system("cls");
            return;
        }
        Output(&Day);
        cout << "\nКакую из записей вы хотите удалить(за номером)? - ";
        z = CorrectInt();
        if (z == 0)
        {
            cout << "Данного пункта не существует." << endl;
            system("pause");
            system("cls");
        }
        if (z>Day.size())
        {
            cout << "Данного пункта не существует." << endl;
            system("pause");
            system("cls");
        }
        else
        {
            Day.erase(Day.begin() + (z - 1));
            break;
        }
    }
    system("cls");
}
void Search(vector <kratko> *Day)
{
    system("cls");
    int y = 0;
    int u = 0;
    string key;
    while (1)
    {
        bool isCorrect = true;
        cout << "Введите конечный путь,что вы хотите найти - ";
        cin >> key;
        for (int i = 0; i < key.length(); i++)
            if (key[i]<char(192) || key[i]>char(255))
                isCorrect = false;
        if (isCorrect)
            break;
        else
            key.clear();
        system("cls");
    }
    for (int i = 0; i <= Day->size() - 1; i++)
    {
        y++;
        const kratko Put = (*Day)[i];
        if (key==Put.konec)
        {
            u++;
            cout << "_____________________________________________________________________________________________________________________\n";
            cout << "|№|Начальный путь|Промежные пункты|    Конец    |Время отправки|Время прибытия|Расстояние|Свободные места|Цена Билета|\n";
            cout << "|_|______________|________________|_____________|______________|______________|__________|_______________|___________|\n";
            const kratko Put = (*Day)[i];
            cout << "|";
            cout.width(0);
            cout << y << "|";
            cout.width(14);
            cout << Put.nachalniy_put << "|";
            cout.width(16);
            cout << Put.promish_punkt << "|";
            cout.width(13);
            cout << Put.konec << "|";
            cout.width(14);
            cout << Put.vrema_otpravki << "|";
            cout.width(14);
            cout << Put.vrema_pribitia << "|";
            cout.width(8);
            cout << Put.rasstoyanie << "км|";
            cout.width(15);
            cout << Put.svobodnie_mesta << "|";
            cout.width(8);
            cout << Put.cena << " $ |\n";
            cout << "|_|______________|________________|_____________|______________|______________|__________|_______________|___________|\n";
        }
    }
    if (u == 0)
    {
        cout << "Ничего не найдено" << endl;
    }
    system("pause");
    system("cls");
}
void Price(vector <kratko>* Day)
{
    system("cls");
    double suma=0;
    double srednee;
    for (int i = 0; i < Day->size(); i++)
    {
        const kratko Cena = (*Day)[i];
        suma += Cena.cena;
    }
    srednee = suma/Day->size() ;
    cout << "Средняя стоимость билетов - " << srednee << endl;
    system ("pause");
    system("cls");
}
void Seat(vector <kratko>* Day)
{
    system("cls");
    int bus=0;
    for (int i = 0; i < Day->size(); i++)
    {
        const kratko seats = (*Day)[i];
        if (seats.svobodnie_mesta>=10)
        {
            bus++;
        }
    }
    cout << "Количество автобусов с наибольшим числом свободных мест(10 и более) - " << bus << endl;
    system("pause");
    system("cls");
}
void Longest(vector <kratko>* Day)
{
    system("cls");
    const kratko Put = (*Day)[0];
    double max = Put.rasstoyanie;
    for (int i = 1; i < Day->size(); i++)
    {
        const kratko Put2 = (*Day)[i];
        if (Put2.rasstoyanie>max)
        {
            max = Put2.rasstoyanie;
        }
    }
    cout << "Самый длинный маршрут - " << max <<endl;
    system("pause");
    system("cls");
}
void Smallest(vector <kratko>* Day)
{
    system("cls");
    const kratko Put = (*Day)[0];
    double min = Put.rasstoyanie;
    for (int i = 1; i < Day->size(); i++)
    {
        const kratko Put2 = (*Day)[i];
        if (Put2.rasstoyanie < min)
        {
            min = Put2.rasstoyanie;
        }
    }
    cout << "Самый меньший маршрут - " << min << endl;
    system("pause");
    system("cls");
}
void Write(vector <kratko> &Day)
{
    system("cls");
    const char* PATH1 = "List.txt";
    ofstream fout(PATH1, ios::binary);
    int q = Day.size();
    fout.write((char*)&q, sizeof(q));
    for (unsigned i = 0; i < q; i++)
    {
        fout.write((char*)&Day[i].nachalniy_put, sizeof(Day[i].nachalniy_put));
        fout.write((char*)&Day[i].promish_punkt, sizeof(Day[i].promish_punkt));
        fout.write((char*)&Day[i].konec, sizeof(Day[i].konec));
        fout.write((char*)&Day[i].vrema_otpravki, sizeof(Day[i].vrema_otpravki));
        fout.write((char*)&Day[i].vrema_pribitia, sizeof(Day[i].vrema_pribitia));
        fout.write((char*)&Day[i].rasstoyanie, sizeof(Day[i].rasstoyanie));
        fout.write((char*)&Day[i].svobodnie_mesta, sizeof(Day[i].svobodnie_mesta));
        fout.write((char*)&Day[i].cena, sizeof(Day[i].cena));
    }
    fout.close();
    cout << "Файл успешно записан" << endl;
    system("pause");
    system("cls");
}
void Reading(vector <kratko> &Day)
{
    system("cls");
    const char* PATH1 = "List.txt";
    ifstream fin(PATH1, ios::binary);
    unsigned m = 0;
    fin.read((char*)&m, sizeof(m));
    Day.resize(m);
    for (unsigned i = 0; i < m; i++)
    {
        fin.read((char*)&Day[i].nachalniy_put, sizeof(Day[i].nachalniy_put));
        fin.read((char*)&Day[i].promish_punkt, sizeof(Day[i].promish_punkt));
        fin.read((char*)&Day[i].konec, sizeof(Day[i].konec));
        fin.read((char*)&Day[i].vrema_otpravki, sizeof(Day[i].vrema_otpravki));
        fin.read((char*)&Day[i].vrema_pribitia, sizeof(Day[i].vrema_pribitia));
        fin.read((char*)&Day[i].rasstoyanie, sizeof(Day[i].rasstoyanie));
        fin.read((char*)&Day[i].svobodnie_mesta, sizeof(Day[i].svobodnie_mesta));
        fin.read((char*)&Day[i].cena, sizeof(Day[i].cena));
    }
    fin.close();
    cout << "Файл успешно прочитан" << endl;
    system("pause");
    system("cls");
}
void MenuSort()
{
    system("cls");
    cout << "Пожайлуста выберите один из пунктов" << endl << endl;
    cout << "1.Сортировка за возрастанием" << endl << endl;
    cout << "2.Сортировка за убыванием" << endl << endl;
    cout << "3.Выход" << endl << endl;
    cout << "Введите цифру: ";
}
void SortMin(vector <kratko>& Day)
{
    system("cls");
    for (int i = 0; i < Day.size() - 1; i++) 
    {
        for (int j = i + 1; j < Day.size(); j++)
        {
            if (Day[i].vrema_otpravki < Day[j].vrema_otpravki)
            {
                swap(Day[i].vrema_otpravki, Day[j].vrema_otpravki);
            }
        }
    }
    cout.width(74);
    Output(&Day);
    system("pause");
    system("cls");
}
void SortMax(vector <kratko>& Day)
{
    system("cls");
    for (int i = 0; i < Day.size() - 1; i++)
    {
        for (int j = i + 1; j < Day.size(); j++)
        {
            if (Day[i].vrema_otpravki > Day[j].vrema_otpravki)
            {
                swap(Day[i].vrema_otpravki, Day[j].vrema_otpravki);
            }
        }
        
    }
    Output(&Day);
    system("pause");
    system("cls");
}
int main()
{
    int u = 0;
    int f = 10;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    vector<kratko>Day;
    init(&Day);
    while (cin)
    {
        showmenu();
        int n;
        n=CorrectInt();
        switch (n)
        {
        case 1:
        {
            Input(&Day);
            f++;
            system("cls");
            cout << "Хотите ли вы подставить новую запись в другое место?" << endl << "(1-Да 2-Нет)" << endl;
            cin >> u;
            if (u == 1)
            {
                Swap(Day, f);
                system("cls");
                break;
            }
            else
            {
                system("cls");
                break;
            }
        }
        case 2:
        {
            Output(&Day);
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            Edit(&Day);
            break;
        }
        case 4:
        {
            Delete(Day);
            f--;
            break;
        }
        case 5:
        {
            Search(&Day);
            break;
        }
        case 6:
        {
            int d;
            MenuSort();
            d = CorrectInt();
            switch (d)
            {
            case 1:
            {
                SortMax(Day);
                break;
            }
            case 2:
            {
                SortMin(Day);
                break;
            }
            case 3:
            {
                system("cls");
                break;
            }
            default:
            {
                cout << endl << "Error" << endl;
                system("pause");
                system("cls");
            }
            }
        }
        break;
        case 7:
        {
            int c;
            showmenu8();
            c = CorrectInt();
            switch (c)
            {
            case 1:
            {
                Longest(&Day);
                break;
            }
            case 2:
            {
                Price(&Day);
                break;
            }
            case 3:
            {
                Seat(&Day);
                break;
            }
            case 4:
            {
                Smallest(&Day);
                break;
            }
            case 5:
            {
                system("cls");
                break;
            }
            default:
            {
                cout << endl << "Error" << endl;
                system("pause");
                system("cls");
            }
            }
        }
        break;
        case 8:
        {
            Write(Day);
            break;
        }
        case 9:
        {
            Reading(Day);
            break;
        }
        case 10:
        {
            system("cls");
            return 0;
        }
        default:
        {
            cout << endl <<  "Error" << endl;
            system("pause");
            system("cls");
        }
        }
    }
    
}
