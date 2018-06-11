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


void initB(char [][10]);
void displayBoards(char [][10], char [][10]);
void initFleet(PlayerBoard&);
void setShip(PlayerBoard&, int);
void getValidShipInfo(int&, int&, char&, PlayerBoard&, int);
void initBoard(PlayerBoard&, PlayerBoard&);
void turn(PlayerBoard &, PlayerBoard &, int);



int main()
{
	PlayerBoard P1;
	PlayerBoard P2;

	initB(P1.board);
	initB(P2.board);
	initFleet(P1);
	initFleet(P2);
	initBoard(P1, P2);

	cout << ".\n.\n.\n";

	int c = 0;
	int player_turn = 1;

	while (1)
	{


		if (c % 2 == 0)
		{
			turn(P2, P1, player_turn);
			player_turn = 2;
			c++;
		}
		else
		{
			turn(P1, P2, player_turn);
			player_turn = 1;
			c++;
		}
	}



	// displayBoards(P1.board, P2.board);
	// displayBoards(P2.board, P1.board);



	return (0);
}


bool game_won(char b[][10], int p_num)
{

	for (size_t r = 0; r < 10; r++)
		for (size_t c = 0; c < 10; c++)
			if (b[r][c] == 's')
				return (false);

	cout << "You sunk the fleet!!! You win!!!\n";


	return (true);
}


void turn(PlayerBoard &P1, PlayerBoard &P2, int p_num)
{
	char	c_row;
	int		row;
	int		col;

	c_row = 'x';
	row = -1;
	col = -1;

	displayBoards(P1.board, P2.board);
	cout << "\n\n\n\n\n";
	cin.clear();
	do{
		cout << "Player "<< p_num<<":\n"
			 << "Fire a shot: ";
		cin >> c_row >> col;
		cout << "\n";

		row = (char)toupper(c_row) - 'A';
		col -= 1;

		if (!(row >= 0 && row <= 9) || !(col >= 0 && col <= 9)
				|| (P2.board[row][col] != ' ' &&  P2.board[row][col] != 's'))
			cout << "Invalid\n";

	}
	while (!(row >= 0 && row <= 9) || !(col >= 0 && col <= 9)
			|| (P2.board[row][col] != ' ' &&  P2.board[row][col] != 's'));



	if (P2.board[row][col] == 's')
	{
		cout << "Hit!!!\n";
		P2.board[row][col] = 'H';
	}
	if (P2.board[row][col] == ' ')
	{
		cout << "You Missed.";
		P2.board[row][col] = 'M';
	}

	if (game_won(P2.board, p_num))
		cout << "won\n";//exit(1);



	//cout << row << " " << col << endl;

}

/*test
void setShip_test(PlayerBoard &p, int shipIndex, int x)
{
	size_t v;

	v = 0;

		p.ships[shipIndex].hitCount = 0;

		if (shipIndex == 0)
		{
			p.ships[shipIndex].name = "carrier";
			p.ships[shipIndex].size = Carrier_SIZE;
			for (v = 0; v < p.ships[v].size; v++)
			{
				p.ships[shipIndex].points.push_back(Point());
				p.ships[shipIndex].points[v].row = v;
				p.ships[shipIndex].points[v].col = 0 + x;

			}
		}
		else if (shipIndex == 1)
		{
			p.ships[shipIndex].name = "battleship";
			p.ships[shipIndex].size = Battleship_SIZE;


			for (v = 0; v < p.ships[v].size; v++)
			{
				p.ships[shipIndex].points.push_back(Point());
				p.ships[shipIndex].points[v].row = v;
				p.ships[shipIndex].points[v].col = 1 + x;

			}
		}
		else if (shipIndex == 2)
		{
			p.ships[shipIndex].name = "cruiser";
			p.ships[shipIndex].size = Cruiser_SIZE;

			for (v = 0; v < p.ships[v].size; v++)
			{
				p.ships[shipIndex].points.push_back(Point());
				p.ships[shipIndex].points[v].row = v;
				p.ships[shipIndex].points[v].col = 2 + x;

			}
		}
		else if (shipIndex == 3)
		{
			p.ships[shipIndex].name = "submarine";
			p.ships[shipIndex].size = Submarine_SIZE;

			for (v = 0; v < p.ships[v].size; v++)
			{
				p.ships[shipIndex].points.push_back(Point());
				p.ships[shipIndex].points[v].row = v;
				p.ships[shipIndex].points[v].col = 3 + x;

			}
		}
		else if (shipIndex == 4)
		{
			p.ships[shipIndex].name = "destroyer";
			p.ships[shipIndex].size = Destroyer_SIZE;

			for (v = 0; v < p.ships[v].size; v++)
			{
				p.ships[shipIndex].points.push_back(Point());
				p.ships[shipIndex].points[v].row = v;
				p.ships[shipIndex].points[v].col = 4 + x;

			}
		}

		p.board[p.ships[shipIndex].points[v].row][p.ships[shipIndex].points[v].col] = 's';


}
*/

/*
*	An initBoard function that takes in two PlayerBoard objects by reference,
*	and calls the setShip function for each ship in the fleet. After each ship
*	is placed on the board the boards should be displayed.
*/

void initBoard(PlayerBoard &P1, PlayerBoard &P2)
{

	cout << "Player 1 set your board.\n";
	displayBoards(P1.board, P2.board);
	for (size_t i = 0; i < FLEET_SIZE; i++)
	{
		setShip(P1, i);
		displayBoards(P1.board, P2.board);
	}

	cout << "\nPlayer 2 set your board.\n";
	displayBoards(P2.board, P1.board);
	for (size_t i = 0; i < FLEET_SIZE; i++)
	{
		setShip(P2, i);
		displayBoards(P2.board, P1.board);
	}

}

/*
*	A setShip function that takes in a PlayerBoard object by reference and an int variable
*	that stores the index of the ship that is currently being placed, and places the ship onto
*	the board. The setShip function calls the getValidShipInfo function to determine which
*	spots on the board the ship will occupy.
*/
void setShip(PlayerBoard &p, int shipIndex)
{
	int		row;
	int		col;
	char	orientation;

	row = -1;
	col = -1;
	orientation = 'x';

	getValidShipInfo(row, col, orientation, p, shipIndex);

	if (orientation == 'v')
	{
		if (p.ships[shipIndex].size + row > 10)
		{
			cout << "Error: Ship placement is outside the board.\n";
			return (setShip(p, shipIndex));
		}

		for (size_t i = row; i < p.ships[shipIndex].size + row; i++)
		{
			p.board[i][col] = 's';
		}
	}
	else if (orientation == 'h')
	{
		if (p.ships[shipIndex].size + col > 10)
		{
			cout << "Error: Ship placement is outside the board.\n";
			return (setShip(p, shipIndex));
		}

		for (size_t i = col; i < p.ships[shipIndex].size + col; i++)
		{
			p.board[row][i] = 's';
		}
	}

//	cout << row << " " << col << " " << orientation << " " << shipIndex<< endl;
}

/*
*	A spaceOccupied function that takes in the PlayerBoard object, an int for
*	the row and col placement of the ship, a character for the orientation,
*	and the ship size. This function returns true if the placement of the
*	ship would overlap an already existing ship placement or false if
*	the space is not occupied.
*/
bool spaceOccupied(PlayerBoard &p, int row, int col,
					char orientation, int s_size)
{

	if (orientation == 'v')
	{
		for (size_t i = row; i < s_size + row; i++)
		{
			if (p.board[i][col] != ' ')
			{
				cout << "Error: Space already occupied.\n";
				return (true);
			}
		}
	}
	else if (orientation == 'h')
	{
		for (size_t i = col; i < s_size + col; i++)
		{
			if (p.board[row][i] != ' ')
			{
				cout << "Error: Space already occupied.\n";
				return (true);
			}
		}
	}
	return (false);
}


/*
*	check for invalid coordinates.
*/
bool check(int row, int col, char orientation)
{
	if (!(row >= 0 && row <= 9))
	{
		cout << "Error: Coordinates are not valid.\n";
		return (false);
	}
	else if (!(col >= 0 && col <= 9))
	{
		cout << "Error: Coordinates are not valid.\n";
		return (false);
	}

	if (orientation != 'v' && orientation != 'h')
	{
		cout << "Error: Orientation of ship is invalid.\n";
		return (false);
	}

	return (true);
}


/*
*	A getValidShipInfo function that takes in four parameters by reference, two
*	ints holding the row and the column of the starting coordinates of the
*	ship, a char that will hold the orientation of the ship (horizontal or
*	vertical), and the PlayerBoard. The function will also take a fifth
*	argument by value which is the index of the ship being placed. The
*	function will prompt the user for the starting row and column coordinates
*	of the ship which the user will enter as: letter number. These will then
*	need to be converted to the proper row and column index of the array.
*	The function will also prompt the user for the horizontal or vertical
*	orientation of the ship. The function will be responsible for performing
*	the error checking so that a valid ship placement is received from the
*	user. The function will also call the function spaceOccupied to determine
*	if any of the spaces the ship would take up if placed on the board are
*	currently occupied.
*/

void getValidShipInfo(int &row, int &col, char &orientation,
						PlayerBoard &p, int shipIndex)
{
	char c_row;

	c_row = 'x';

	do{

	cout << "Enter the starting coordinates of your "
		 << p.ships[shipIndex].name << ": ";
	cin >> c_row >> col;
	cout << endl;

	cout << "Enter the orientation of your "
		 << p.ships[shipIndex].name << " (horizontal(h) or vertical(v)): ";
	cin >> orientation;
	cout << endl;

	row = (char)toupper(c_row) - 'A';
	col -= 1;
	orientation = (char)tolower(orientation);

	}
	while (!check(row, col, orientation));

	if (spaceOccupied(p, row, col,
		orientation, p.ships[shipIndex].size))
		getValidShipInfo(row, col, orientation, p, shipIndex);



//	cout << c_row << " " << col << " " << orientation << " " << shipIndex<< endl;
}


/*
*	An initFleet function that takes in a PlayerBoard object as a parameter and
*	initializes all the ships in the fleet with the appropriate information. For
*	example, the name and size of the ship should be initialized within
*	the function.
*
*/
void initFleet(PlayerBoard &p)
{
	for (size_t i = 0; i < FLEET_SIZE; i++)
	{
		if (i == 0)
		{
			p.ships[i].name = "carrier";
			p.ships[i].size = Carrier_SIZE;
		}
		else if (i == 1)
		{
			p.ships[i].name = "battleship";
			p.ships[i].size = Battleship_SIZE;
		}
		else if (i == 2)
		{
			p.ships[i].name = "cruiser";
			p.ships[i].size = Cruiser_SIZE;
		}
		else if (i == 3)
		{
			p.ships[i].name = "submarine";
			p.ships[i].size = Submarine_SIZE;
		}
		else if (i == 4)
		{
			p.ships[i].name = "destroyer";
			p.ships[i].size = Destroyer_SIZE;
		}

		p.ships[i].hitCount = 0;

		for (size_t v = 0; v < p.ships[v].size; v++)
		{
			p.ships[i].points.push_back(Point());
			p.ships[i].points[v].row = -1;
			p.ships[i].points[v].col = -1;

		}

	}
}


/*
*	Init boards to spaces;
*/
void initB(char a[][10])
{
	for (size_t r = 0; r < 10; r++)
		for (size_t c = 0; c < 10; c++)
			a[r][c] = ' ';
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
			if (i < 10)
				for (size_t s = 0; s < 3; s++)
				{
					if (s == 1)
						cout << a[r][c++];
					else
						cout << ' ';
				}
		}

		c = 0;
		cout << "          " << A++ << " ";
		for (size_t i = 0; i < 11; i++)
		{
			cout << '|';
			if (i < 10)
				for (size_t s = 0; s < 3; s++)
				{
					if (s == 1 && b[r][c] != 's')
						cout << b[r][c++];
					else
						cout << ' ';
				}
		}
		r++;
		cout << endl;

	}

	cout << l1 << l2;
}
