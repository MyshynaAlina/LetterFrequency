#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string text;

    cout << "¬вед≥ть текст дл€ анал≥зу: ";
    getline(cin, text);

    return 0;
}
