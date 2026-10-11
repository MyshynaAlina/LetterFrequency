#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void printDiagram(string letters, int count[])
{
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
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string text;
    string letters = "àáâã´äåºæçè³¿éêëìíîïðñòóôõö÷øùüþÿ";
    string bigLetters = "ÀÁÂÃ¥ÄÅªÆÇÈ²¯ÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÜÞß";

    int count[33] = { 0 };
    bool hasLetters = false;

    cout << "Ââåä³òü òåêñò äëÿ àíàë³çó: ";
    getline(cin, text);

    if (text.empty())
    {
        cout << "Ïîìèëêà: íåìàº òåêñòó." << endl;
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
        cout << "Ïîìèëêà: íåìàº óêðà¿íñüêèõ ë³òåð." << endl;
        return 0;
    }

    cout << endl;
    printDiagram(letters, count);

    return 0;
}
