#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <time.h>
#include <windows.h>
using namespace std;

const int n = 9;
const int m = 9;
void intialize(int M[n][m])
{
    for (int I = 0; I < n; I++)
    {
        for (int J = 0; J < m; J++)
        {
            M[I][J] = 0;
        }
    }
    for (int k = 0; k < 20; k++)
    {
        srand(time(0));
        int i = rand() % 9;
        int j = rand() % 9;
        int num = rand () % 9 + 1;

       bool exists = false;
        for (int x = 0; x < 9; x++) 
        {
            if (M[i][x] == num || M[x][j] == num)
            {
                exists = true;
                break;
            }
            if (x < 3) {
                for (int y = 0; y < 3; y++) {
                    if (M[i / 3 * 3 + x][j / 3 * 3 + y] == num) 
                    {
                        exists = true;
                        break;
                    }
                }
            }
        }
        if (exists == false) 
        {
            M[i][j] = num;
        } 
        else 
        {
            k--;
        }
    }
}
void printBoard(int M[9][9]) {
    std::cout << "    1 2 3   4 5 6   7 8 9\n";
    std::cout << "  ┌───────┬───────┬───────┐\n";
    for (int i = 0; i < 9; ++i) {
        std::cout << i+1 << " │ ";
        for (int j = 0; j < 9; ++j) {
            if (M[i][j] == 0) {
                std::cout << ". ";
            } else {
                std::cout << M[i][j] << ' ';
            }
            if ((j + 1) % 3 == 0 && j != 8) {
                std::cout << "│ ";
            }
        }
        std::cout << "│\n";
        if ((i + 1) % 3 == 0 && i != 8) {
            std::cout << "  ├───────┼───────┼───────┤\n";
        }
    }
    std::cout << "  └───────┴───────┴───────┘\n";
}
bool checkelements(int M[n][m], int row, int column, int num)
{
    bool check = true;
    int counter1 = 0, counter2 = 0;
    cout << "Please enter the number of the row you want to play it in : ";
    cin >> row;
    cout << "Please enter the number of the column you want to play it in : ";
    cin >> column;
    cout << "Please enter the number you want to play : ";
    cin >> num;
    for (int j = 0; j < 9; j++)
    {
        if (num != M[row-1][j])
        {
            counter1++;
        }
        else 
        {
            check = false;
            break;
        }
    }
    if (counter1 == 9)
    {
        for (int i = 0; i < 9; i++)
        {
            if (num != M[i][column-1])
            {
                counter2 ++;
            }
            else
            {
                check = false;
                break;
            }
        }
        if (counter2 == 9)
        {
            int startRow = row - row % 3, startCol = column - column % 3;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                if (M[i + startRow][j + startCol] == num)
                {
                    check = false;
                    break;
                }
            }

        if (check == true)
        {
            M[row-1][column-1] = num;
        }
        }
    }
    return check;
}
bool isComplete(int M[n][m])
{
    bool win = true;
    int sumRow = 0, sumColumn = 0;
    for (int k = 0; k < 9; k++)
    {
        for (int i = 0; i < 9; i++)
        {
            sumRow += M[k][i];
            sumColumn += M[i][k];
        }
        if (sumRow != sumColumn)
        {
            win = false;
            break;
        }
    }
    return win;
}
int main (void)
{
    SetConsoleOutputCP(CP_UTF8);
    int M[n][m], row, column, num;
    intialize(M);
    while (isComplete(M) == false)
    {
        printBoard(M);
        if (checkelements(M, row, column, num) == false)
        {
            cout << "invalid choice : ";
        }
        system ("cls");
    }
    cout << "Congratulations, you completed the puzzle! \n";
}