#include <iostream>
#include <vector>

using namespace std;

void displayBoards();//char [][10], char [][10]);


int main()
{
	displayBoards();
	return (0);
}
void displayBoards()//char a[][10], char b[][10])
{
	char	A = 'A';
	string	l1 = "  -----------------------------------------";
	string	l2 = "            -----------------------------------------\n";

	cout << "                  Your Board          "
		 << "                                Enemy Board\n"
		 << "    1   2   3   4   5   6   7   8   9  10"
		 << "                1   2   3   4   5   6   7   8   9  10\n";

	for (size_t i = 0; i < 11; i++)
	{

		cout << l1 << l2 << A << ' ';
		for (size_t i = 0; i < 11; i++)
		{
			cout << '|';
			for (size_t i = 0; i < 3; i++)
			{
				cout << ' ';
			}
		}


		cout << "       " << A++ << " ";
		for (size_t i = 0; i < 11; i++)
		{
			cout << '|';
			for (size_t i = 0; i < 3; i++)
			{
				cout << ' ';
			}
		}
		cout << endl;

	}

	cout << l1 << l2;


}
