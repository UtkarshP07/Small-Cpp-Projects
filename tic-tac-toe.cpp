#include <iostream>
#include <vector>
using namespace std;

/*
    Tic-Tac-Toe Game
    -----------------
    This is a simple two-player game where players take turns to place their symbols ('X' or '0')
    on a 3x3 grid. The objective is to get three of your symbols in a row (horizontally, vertically, or diagonally).
    The game ends when one player wins or when all grid positions are filled without a winner.
*/

// Function to print the Tic-Tac-Toe board
void printVal(vector<vector<char>> values)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << values[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

// Function to take input for player names
string playerName(int i)
{
    string player;
    cout << "Enter Player Name:" << endl;
    cout << "Player " << i << " :";
    cin >> player;
    cout << endl;
    return player;
}

// Function to place the player's symbol on the grid
char placeValue(vector<vector<char>> &values, int i, int j, bool &flag)
{
    char put;
    if (values[i][j] != '_') // Check if the cell is already occupied
    {
        cout << "Invalid Index: already placed value." << endl;
        return ' '; // Indicate invalid move
    }
    else
    {
        put = flag ? 'X' : '0'; // Choose the symbol based on the flag
        values[i][j] = put;     // Update the grid
    }
    flag = !flag; // Toggle the turn
    return put;
}

// Function to check if there is a winner
string IsWinner(string player1, string player2, vector<vector<char>> &values, int i, int j, char currentChar)
{
    // Check the current row
    if (values[i][0] == currentChar && values[i][1] == currentChar && values[i][2] == currentChar)
    {
        return currentChar == 'X' ? player2 : player1;
    }

    // Check the current column
    if (values[0][j] == currentChar && values[1][j] == currentChar && values[2][j] == currentChar)
    {
        return currentChar == 'X' ? player2 : player1;
    }

    // Check the main diagonal
    if (i == j && values[0][0] == currentChar && values[1][1] == currentChar && values[2][2] == currentChar)
    {
        return currentChar == 'X' ? player2 : player1;
    }

    // Check the anti-diagonal
    if (i + j == 2 && values[0][2] == currentChar && values[1][1] == currentChar && values[2][0] == currentChar)
    {
        return currentChar == 'X' ? player2 : player1;
    }

    return "none"; // No winner yet
}

int main()
{
    // Initialize player names and the game board
    string player1, player2;
    vector<vector<char>> values = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};

    cout << "Welcome to the Tic-Tac-Toe Game" << endl;
    cout << "*******************************" << endl;
    cout << endl;

    player1 = playerName(1); // Get Player 1 name
    player2 = playerName(2); // Get Player 2 name

    cout << "Welcome " << player1 << " and " << player2 << " to this Tic-Tac-Toe Game." << endl;
    cout << "Type index i and j for the index you want to change:" << endl;
    cout << endl;

    bool flag = 0;          // 0 for Player 1's turn, 1 for Player 2's turn
    string winner = "none"; // Keeps track of the winner

    while (winner == "none") // Loop until there is a winner
    {
        cout << (flag == 0 ? player1 : player2) << "'s Turn\n"
             << endl;

        printVal(values); // Print the current board
        cout << endl;

        int a, b; // Input for the cell coordinates
        cin >> a >> b;

        char placedSymbol = placeValue(values, a, b, flag);
        if (placedSymbol == ' ') // Skip the turn if the move was invalid
            continue;

        winner = IsWinner(player1, player2, values, a, b, placedSymbol); // Check for a winner
        if (winner != "none")                                            // If a winner is found
        {
            cout << "Winner is: " << winner << "!" << endl;
            printVal(values); // Display the final board
            break;
        }
        cout << endl;
    }

    return 0;
}
