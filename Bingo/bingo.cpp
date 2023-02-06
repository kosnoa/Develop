#include <iostream>
#include <time.h>
#include <math.h>
#include <windows.h>
using namespace std;

const int Marking = 'x';
int Bingo[25] = {};
int BingoCount = 0;
int maxBingo = 0;

void Init()
{
    for (int i = 0; i < 25; i++)
    {
        Bingo[i] = i + 1;
    }
}

void Shuffle(int count)
{
    srand(time(nullptr));

    for (int i = 0; i < count; i++)
    {
        int numRand1 = rand() % 25;
        int numRand2 = rand() % 25;

        int temp = Bingo[numRand1];
        Bingo[numRand1] = Bingo[numRand2];
        Bingo[numRand2] = temp;
    }
}

void ShowNumbers()
{
    system("cls");
    cout << "Created by kosnoa\n";
    cout << "The Input is not marking the number, it marks the location.\n";
    cout << "Please enter the Number between 1 ~ 25.\n";
    for (int i = 0; i < 25; i++)
    {
        if (i % 5 == 0)
            cout << '\n';

        if (Bingo[i] == Marking)
            cout << (char)Bingo[i] << '\t';
        else
            cout << (int)Bingo[i] << '\t';
    }

    cout << '\n';
    cout << "Number of Bingo: " << BingoCount << '\n';
}

int GetInput()
{

    int num = 0;
    while (1)
    {
        ShowNumbers();
        num = 0;
        string s;
        bool check = true;
        cout << "Enter the Number: ";
        cin >> s;
        int strlen = s.size() - 1;

        for (int i = 0; i < s.size(); i++)
        {
            if (!isdigit(s[i]))
            {
                cout << "Not an Integer.\n";
                check = false;
                Sleep(2000);
                break;
            }
            else
            {
                num += (s[i] - '0') * pow(10, strlen);
                strlen--;
            }
        }
        if (check)
        {
            if (num > 25)
            {
                cout << "The Number is Greater than 25.\n";
                Sleep(2000);
            }
            else if (num < 1)
            {
                cout << "The Number is Less than 25.\n";
                Sleep(2000);
            }
            else
            {
                break;
            }
        }
    }

    return num - 1;
}

void SetMarking(int num)
{
    for (int i = 0; i < 25; i++)
    {
        if (num == i)
        {
            Bingo[i] = Marking;
            break;
        }
    }
}

void CountBingo()
{
    BingoCount = 0;
    for (int i = 0; i < 25; i++)
    {
        if (Bingo[i * 5] == Marking && Bingo[i * 5 + 1] == Marking && Bingo[i * 5 + 2] == Marking && Bingo[i * 5 + 3] == Marking && Bingo[i * 5 + 4] == Marking)
            BingoCount++;

        if (Bingo[i] == Marking && Bingo[i + 5 * 1] == Marking && Bingo[i + 5 * 2] == Marking && Bingo[i + 5 * 3] == Marking && Bingo[i + 5 * 4] == Marking)
            BingoCount++;

        if (Bingo[0] == Marking && Bingo[6] == Marking && Bingo[12] == Marking && Bingo[18] == Marking && Bingo[24] == Marking)
            BingoCount++;

        if (Bingo[4] == Marking && Bingo[8] == Marking && Bingo[12] == Marking && Bingo[16] == Marking && Bingo[20] == Marking)
            BingoCount++;
    }
}

int main()
{
    while (1)
    {
        cout << "Bingo Lines: ";
        cin >> maxBingo;
        Init();
        Shuffle(100);

        while (1)
        {
            ShowNumbers();
            SetMarking(GetInput());
            CountBingo();

            if (BingoCount >= maxBingo)
                break;
        }
        ShowNumbers();

        int check = 0;
        cout << "Exit (0) | Replay(1)\n";
        while(1)
        {
            cin >> check;
            if (check == 1 || check == 0)
            {
                break;
            }
        }

        if (!check)
        {
            break;
        }
        else 
        {
            system("cls");
        }
    }
    cout << "Thanks for Playing!\n";
}