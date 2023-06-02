// GameOfLife.cpp : Defines the entry point for the application.
//

#include "GameOfLife.h"

uint8_t main()
{
	system("TITLE Game of Life");
	Game game;

	while (true)
	{		
		game.Run();
		game.Render();
		game.ChangeState();
	}	
}
