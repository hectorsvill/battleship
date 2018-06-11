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
void initFleet(PlayerBoard&);


int main()
{
	PlayerBoard P1;
	PlayerBoard P2;

	initBoard(P1.board);
	initBoard(P2.board);
	initFleet(P1);
	initFleet(P2);



	displayBoards(P1.board, P2.board);

	setShip(p, 0);

	return (0);
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

	getValidShipInfo(row, col, orientation, p, shipIndex)

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


	cout << "Enter the starting coordinates of your "
		 << p.ships[shipIndex].name << ": ";
	cin >> c_row;
	cout << endl;

	cout << "Enter the orientation of your "
		 << p.ships[shipIndex].name << " (horizontal(h) or vertical(v)):";
	cin >> col;


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
void initBoard(char a[][10])
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
					if (s == 1)
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
