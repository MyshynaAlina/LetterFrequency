#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string text;
    string letters = "àáâã´äåºæçè³¿éêëìíîïğñòóôõö÷øùüşÿ";
    string bigLetters = "ÀÁÂÃ¥ÄÅªÆÇÈ²¯ÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÜŞß";

    int count[33] = { 0 };

    cout << "Ââåä³òü òåêñò äëÿ àíàë³çó: ";
    getline(cin, text);

    for (int i = 0; i < text.length(); i++) 
    {
        for (int j = 0; j < 33; j++)
        {
            if (text[i] == letters[j] || text[i] == bigLetters[j])
            {
                count[j]++;
                break;
            }
        }
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
