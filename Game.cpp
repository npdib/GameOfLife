#include "Game.h"

Game::Game()
{
	mBoard = new Board(kHeight, kWidth);
	mUpdate = 0;
	mState = Setup;
}

Game::~Game()
{
	delete mBoard;
}

void Game::setup()
{
	GetKeyPresses();
	if (keyPressed(left))
	{
		mBoard->moveCursor(Left);
	}
	if (keyPressed(right))
	{
		mBoard->moveCursor(Right);
	}
	if (keyPressed(up))
	{
		mBoard->moveCursor(Up);
	}
	if (keyPressed(down))
	{
		mBoard->moveCursor(Down);
	}
	if (keyPressed(enter))
	{
		mBoard->swapTile();
	}
}


void Game::Run()
{
	switch (mState)
	{
	case Setup:
		setup();
		break;
	}
}


void Game::Render()
{
	// mUpdate and draw the board
	if (mUpdate == 0)
	{
		mUpdate = 4;
		mBoard->drawBoard();
	}
	else
	{
		mUpdate--;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

