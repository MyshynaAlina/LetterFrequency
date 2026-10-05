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
    string bigLetters = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";

    int count[33] = { 0 };
    bool hasLetters = false;

    cout << "Введіть текст для аналізу: ";
    getline(cin, text);

    if (text.empty())
    {
        cout << "Помилка: немає тексту." << endl;
        return 0;
    }

    for (int i = 0; i < text.length(); i++) 
    {
        for (int j = 0; j < 33; j++)
        {
            if (text[i] == letters[j] || text[i] == bigLetters[j])
            {
                count[j]++;
                hasLetters = true;
                break;
            }
        }
    }

    if (hasLetters == false)
    {
        cout << "Помилка: немає українських літер." << endl;
        return 0;
    }

    cout << endl;
    cout << "" << endl;

    for (int i = 0; i < 33; i++)
    {
        if (count[i] > 0)
        {
            cout << letters[i] << " ";

            for (int j = 0; j < count[i]; j++)
            {
                cout << "#";
            }

            cout << " " << count[i] << endl;
        }
    }

    return 0;
}
