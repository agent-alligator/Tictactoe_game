#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char token = 'x';
bool tie = false;
string n1, n2;

void functionOne()
{
    cout << "    |    |    \n";
    cout << "  " << space[0][0] << " | " << space[0][1] << "  | " << space[0][2] << " \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << "  " << space[1][0] << " | " << space[1][1] << "  | " << space[1][2] << " \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << "  " << space[2][0] << " | " << space[2][1] << "  | " << space[2][2] << " \n";
    cout << "    |    |    \n";
}

void functionTwo()
{
    int digit;

    if (token == 'x')
    {
        cout << n1 << " PLEASE ENTER: ";
        cin >> digit;
    }
    else if (token == '0')
    {
        cout << n2 << " PLEASE ENTER: ";
        cin >> digit;
    }

    if (digit == 1)
    {
        row = 0;
        column = 0;
    }
    else if (digit == 2)
    {
        row = 0;
        column = 1;
    }
    else if (digit == 3)
    {
        row = 0;
        column = 2;
    }
    else if (digit == 4)
    {
        row = 1;
        column = 0;
    }
    else if (digit == 5)
    {
        row = 1;
        column = 1;
    }
    else if (digit == 6)
    {
        row = 1;
        column = 2;
    }
    else if (digit == 7)
    {
        row = 2;
        column = 0;
    }
    else if (digit == 8)
    {
        row = 2;
        column = 1;
    }
    else if (digit == 9)
    {
        row = 2;
        column = 2;
    }
    else
    {
        cout << "Invalid input!!!" << endl;
        functionTwo();
        return;
    }

    if (space[row][column] != 'x' && space[row][column] != '0')
    {
        if (token == 'x')
        {
            space[row][column] = 'x';
            token = '0';
        }
        else
        {
            space[row][column] = '0';
            token = 'x';
        }
        functionOne(); // Print the board after a valid move
    }
    else
    {
        cout << "Space already occupied. Choose a different position." << endl;
        functionTwo();
    }
}

bool functionThree()
{
    for (int i = 0; i < 3; i++)
    {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) || (space[0][i] == space[1][i] && space[0][i] == space[2][i]))
        {
            return true;
        }
    }

    if ((space[0][0] == space[1][1] && space[0][0] == space[2][2]) || (space[0][2] == space[1][1] && space[1][1] == space[2][0]))
    {
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'x' && space[i][j] != '0')
            {
                return false;
            }
        }
    }

    tie = true;
    return true;
}

int main()
{
    cout << "ENTER THE NAME OF PLAYER 1: ";
    getline(cin, n1);
    cout << "ENTER THE NAME OF PLAYER 2: ";
    getline(cin, n2);
    cout << n1 << " > PLAYER 1" << endl;
    cout << n2 << " > PLAYER 2" << endl;

    functionOne(); // Print the initial board

    while (!functionThree())
    {
        functionTwo();
        functionThree();
    }

    if (token == 'x' && !tie)
    {
        cout << n2 << " won the game!" << endl;
    }
    else if (token == '0' && !tie)
    {
        cout << n1 << " won the game!" << endl;
    }
    else
    {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
