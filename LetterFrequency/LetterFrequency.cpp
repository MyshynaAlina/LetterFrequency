#include <iostream>
#include <string>
#include <vector>
#include "askiplot.hpp"
#include <algorithm>
#include <cmath>

#define NOMINMAX
#include <Windows.h>

using namespace std;
const int LETTER_COUNT = 33;

vector<int> scaleColumns(const vector<int>& values, int maxLength)
{
    vector<int> result;

    if (values.empty())
        return result;

    int maxValue = *max_element(values.begin(), values.end());

    // Якщо всі значення дорівнюють нулю
    if (maxValue == 0)
    {
        result.resize(values.size(), 0);
        return result;
    }

    // Масштабування довжин стовпчиків
    for (int value : values)
    {
        int length = round(
            (double)value / maxValue * maxLength
        );

        result.push_back(length);
    }

    return result;
}


void printDiagram(string letters, int count[], int threshold)
{
    int maxCount = 0;
    int selectedCount = 0;
    
    for (int i = 0; i < LETTER_COUNT; i++)
    {
        if (count[i] >= threshold)
        {
            selectedCount++;

            if (count[i] > maxCount)
            {
                maxCount = count[i];
            }
        }
    }

    if (selectedCount == 0)
    {
        cout << "Немає літер із заданою частотою." << endl;
        return;
    }

    const int plotWidth = 80;
    const int plotHeight = 22;
    const int maxBarHeight = 16;
    vector<askiplot::Bar> bars;

    int barIndex = 0;

    for (int i = 0; i < LETTER_COUNT; i++)
    {
        if (count[i] >= threshold)
        {
            int column = barIndex * plotWidth / selectedCount;
            int nextColumn = (barIndex + 1) * plotWidth / selectedCount;
            int slotWidth = nextColumn - column;

            int barWidth = slotWidth / 4;
            if (barWidth < 1) {
                barWidth = 1;
            }

            column += (slotWidth - barWidth) / 2;

            int barHeight = count[i] * maxBarHeight / maxCount;
            
            if (barHeight < 1)
            {
                barHeight = 1;
            }

            askiplot::Bar bar;
            bar.SetName(to_string(barIndex + 1));
            bar.SetColumn(column);
            bar.SetWidth(barWidth);
            bar.SetHeight(barHeight);
            bar.SetBrush(askiplot::Brush('#'));
            bar.SetEmpty(false);
            bars.push_back(bar);

            barIndex++;
        }
    }
    askiplot::BarPlot diagram(plotWidth, plotHeight);
    diagram.PlotBars(bars);
    diagram.DrawBarLabels(askiplot::Offset(0, 1));

    cout << diagram.Serialize() << endl;

    cout << "Кількість входжень:" << endl;

    int printed = 0;
    for (int i = 0; i < LETTER_COUNT; i++) {
        if (count[i] >= threshold) {
            printed++;
            cout << printed << " - " << letters[i] << ": " << count[i] << "\t";

            if (printed % 6 == 0) {
                cout << endl;
            }
        }
    }
    if (printed % 6 != 0) {
        cout << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string text;
    string letters = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
    string bigLetters = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";

    int count[LETTER_COUNT] = { 0 };
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
        cout << "Помилка: немає українських літер." << endl;
        return 0;
    }

    string input;
    int threshold = 0;
    bool valid = true;

    cout << "Введіть порогове значення: ";
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
        cout << "Помилка: введіть додатне ціле число." << endl;
        return 0;
    }

    cout << endl;
    printDiagram(letters, count, threshold);

    return 0;
}
