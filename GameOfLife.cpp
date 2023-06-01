// GameOfLife.cpp : Defines the entry point for the application.
//

#include "GameOfLife.h"

RunningState main_state;

void setup(Board& board)
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
}

uint8_t main()
{
	Board board(kHeight, kWidth);
	uint8_t update = 0;
	main_state = Setup;

	while (true)
	{
		switch (main_state)
		{
		case Setup:
			setup(board);
			break;
		}


		// update and draw the board
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
