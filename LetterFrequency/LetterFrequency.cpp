#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void printDiagram(string letters, int count[], int threshold)
{
    int maxCount = 0;
    bool found = false;
    for (int i = 0; i < 33; i++)
    {
        if (count[i] >= threshold && count[i] > maxCount)
        {
            maxCount = count[i];
        }
    }
    for (int i = 0; i < 33; i++)
    {
        if (count[i] > 0 && count[i] >= threshold)
        {
            found = true;
            cout << letters[i] << " ";
            int barLenght = count[i] * 50 / maxCount;
            if (barLenght == 0)
            {
                barLenght = 1;
            }
            for (int j = 0; j < barLenght; j++)
            {
                cout << "#";
            }
            cout << " " << count[i] << endl;
        }
    }
    if (found == false)
    {
        cout << "Немає літер із заданою частотою." << endl;
    }
    
}

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
    int threshold;

    cout << "Введіть порогове значення: ";

    if (!(cin >> threshold) || threshold < 1)
    {
        cout << "Порогове значення повинно бути додатним цілим числом." << endl;
        return 0;
    }

    cout << endl;
    printDiagram(letters, count, threshold);

    return 0;
}
