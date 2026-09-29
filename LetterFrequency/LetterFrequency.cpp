#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string text;
    string letters = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";

    int count[33] = { 0 };

    cout << "Введіть текст для аналізу: ";
    getline(cin, text);

    for (int i = 0; i < text.length(); i++) 
    {
        for (int j = 0; j < 33; j++)
        {
            if (text[i] == letters[j])
            {
                count[j]++;
                break;
            }
        }
    }

    return 0;
}
