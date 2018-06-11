#include <iostream>
#include <vector>

using namespace std;

const int Carrier_SIZE = 5;
const int Battleship_SIZE = 4;
const int Cruiser_SIZE = 3;
const int Submarine_SIZE = 3;
const int Destroyer_SIZE = 2;
const int FLEET_SIZE = 5;

struct Point
{
	int	row;
	int	col;
};

struct Ship
{
	string			name;
	int				size;
	int				hitCount;
	vector<Point>	points;
};

struct PlayerBoard
{
	char	board[10][10];
	Ship	ships[FLEET_SIZE];
};


void initBoard(char [][10]);
void displayBoards(char [][10], char [][10]);


int main()
{
	PlayerBoard P1;
	PlayerBoard P2;

	initBoard(P1.board);
	initBoard(P2.board);

	displayBoards(P1.board, P2.board);
	return (0);
}

/*
*	Init boards to spaces;
*/
void initBoard(char a[][10])
{
	for (size_t r = 0; r < 10; r++)
		for (size_t c = 0; c < 10; c++)
			a[r][c] = 'x';
}

/*
*	The two boards should appear side by side.
*/
void displayBoards(char a[][10], char b[][10])
{
	int		c;
	int		r;
	char	A;
	string	l1;
	string	l2;


	A = 'A';
	c = 0;
	r = 0;
	l1 = "  -----------------------------------------";
	l2 = "            -----------------------------------------\n";


	cout << "                  Your Board          "
		 << "                                Enemy Board\n"
		 << "    1   2   3   4   5   6   7   8   9  10"
		 << "                1   2   3   4   5   6   7   8   9  10\n";




	while (A <= 'J')
	{
		c = 0;
		cout << l1 << l2 << A << ' ';
		for (size_t i = 0; i < 11; i++)
		{
			cout << '|';
			if (c < 10)
				for (size_t i = 0; i < 3; i++)
				{
					// if (i == 1)
					// 	cout << a[r][c++];
					// else
						cout << ' ';
				}
		}

		c = 0;
		cout << "       " << A++ << " ";
		for (size_t i = 0; i < 11; i++)
		{
			cout << '|';
			if (c < 10)
				for (size_t i = 0; i < 3; i++)
				{
					// if (i == 1)
					// 	cout << b[r++][c++];
					// else
						cout << ' ';
				}
		}
		cout << endl;

	}

	cout << l1 << l2;
}
