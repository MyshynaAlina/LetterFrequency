#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;
const int LETTER_COUNT = 33;

void printDiagram(string letters, int count[], int threshold)
{
    int maxCount = 0;
    bool found = false;
    for (int i = 0; i < LETTER_COUNT; i++)
    {
        if (count[i] >= threshold && count[i] > maxCount)
        {
            maxCount = count[i];
        }
    }
    for (int i = 0; i < LETTER_COUNT; i++)
    {
        if (count[i] >= threshold)
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
        cout << "Íåìàº ë³òåð ³ç çàäàíîþ ÷àñòîòîþ." << endl;
    }
    
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string text;
    string letters = "àáâã´äåºæçè³¿éêëìíîïðñòóôõö÷øùüþÿ";
    string bigLetters = "ÀÁÂÃ¥ÄÅªÆÇÈ²¯ÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÜÞß";

    int count[LETTER_COUNT] = { 0 };
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
        for (int j = 0; j < LETTER_COUNT; j++)
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

    string input;
    int threshold = 0;
    bool valid = true;

    cout << "Ââåä³òü ïîðîãîâå çíà÷åííÿ: ";
    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            valid = false;
            break;
        }
    }

    if (valid)
    {
        try
        {
            threshold = stoi(input);
        }
        catch (...)
        {
            valid = false;
        }
    }

    if (!valid || threshold < 1)
    {
        cout << "Ïîìèëêà: ââåä³òü äîäàòíå ö³ëå ÷èñëî." << endl;
        return 0;
    }

    cout << endl;
    printDiagram(letters, count, threshold);

    return 0;
}
