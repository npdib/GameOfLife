// GameOfLife.cpp : Defines the entry point for the application.
//

#include "GameOfLife.h"

uint8_t main()
{	
	Board board(kHeight, kWidth);
	uint8_t update = 0;
	while (true)
	{
		GetKeyPresses();
		if (keyPressed(left))
		{
			board.moveCursor(Left);
		}
		if (keyPressed(right))
		{
			board.moveCursor(Right);
		}
		if (keyPressed(up))
		{
			board.moveCursor(Up);
		}
		if (keyPressed(down))
		{
			board.moveCursor(Down);
		}
		if (keyPressed(enter))
		{
			board.swapTile();
		}

		if (update == 0)
		{
			update = 4;
			board.drawBoard();
		}
		else
		{
			update--;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}	
}
