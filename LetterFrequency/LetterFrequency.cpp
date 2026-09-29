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

    return 0;
}
