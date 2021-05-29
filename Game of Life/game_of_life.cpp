#include "game_of_life.h"
#include<iostream>
#include<ctime>

bool game_of_life::slucajna_vrijednost()
{
	return rand() % 4 == 0;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	int Alive = 0;

	int el_up = j - 1;

	for (int r = 0; r < 3; r++)
	{
		if (_generacija[i - 1][el_up] == 1)
		{
			Alive++;
		}
		el_up++;
	}

	int el_middle = j - 1;

	for (int r = 0; r <= 1; r++)
	{
		if (_generacija[i][el_middle] == 1)
		{
			Alive++;
		}
		el_middle += 2;
	}

	int el_down = j - 1;

	for (int r = 0; r < 3; r++)
	{
		if (_generacija[i + 1][el_down] == 1)
		{
			Alive++;
		}
		el_down++;
	}

	if (_generacija[i][j] == 1 && Alive == 2)
	{
		return 1;
	}
	else if (_generacija[i][j] == 1 && Alive == 3)
	{
		return 1;
	}
	else if (_generacija[i][j] == 1 && Alive < 2)
	{
		return 0;
	}
	else if (_generacija[i][j] == 1 && Alive >= 3)
	{
		return 0;
	}
	else if (_generacija[i][j] == 0 && Alive == 3)
	{
		return 1;
	}
	return false;
}

game_of_life::game_of_life()
{
	srand(time(nullptr));
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = celija_zauzeta(i, j);
		}
	}
}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j] == 0)
			{
				cout << '.';
			}
			else
			{
				cout << '#';
			}
		}
		cout << endl;
	}
}
