#include "Game.h"

Game::Game()
{
	mBoard = new Board(kHeight, kWidth);
	mUpdate = 0;
	mState = {
		Setup,
		false,
		None
	};
}

Game::~Game()
{
	delete mBoard;
}

void Game::setup()
{
	mBoard->showCursor(true);
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
	if (keyPressed(space))
	{
		mBoard->swapTile();
	}
	if (keyPressed(enter))
	{
		mState.NewState = Simulation;
		mState.changeState = true;
		mSimulationSteps = 0;
	}
	
}

void Game::simulation()
{
	mBoard->showCursor(false);

	GetKeyPresses();
	if (keyPressed(escape))
	{
		mState.NewState = Pause;
		mState.changeState = true;
		mDrawBoardOnPause = true;
	}
}

void Game::pause()
{
	mBoard->showCursor(false);

	GetKeyPresses();
	if (keyPressed(escape))
	{
		mState.NewState = Simulation;
		mState.changeState = true;
	}
}




void Game::Run()
{
	switch (mState.CurrentState)
	{
	case Setup:
		setup();
		break;
	case Simulation:
		simulation();
		break;
	case Pause:
		pause();
		break;
	}

	if (mState.changeState)
	{
		mState.CurrentState = mState.NewState;
		mState.changeState = false;
		mState.NewState = None;
		mUpdate = 0;
	}
}


void Game::Render()
{

	switch (mState.CurrentState)
	{
	case Setup:
		// mUpdate and draw the board
		if (mUpdate == 0)
		{
			mUpdate = 24;
			mBoard->drawBoard();
			std::cout << std::endl << "         Press arrow keys to move cursor and space to toggle a cell" << std::endl \
				<< "         between alive and dead. Press enter to start the simulation.";
		}
		else
		{
			mUpdate--;
		}


		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		break;

	case Simulation:

		if (mUpdate == 0)
		{
			mUpdate = 49;
			mBoard->drawBoard();
			std::cout << "                   Current simulation steps:  " << mSimulationSteps << std::endl;
			mSimulationSteps++;
		}
		else
		{
			mUpdate--;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		break;

	case Pause:

		if (mDrawBoardOnPause)
		{
			mBoard->drawBoard();

			std::cout << "                   Current simulation steps:  " << mSimulationSteps << std::endl;

			std::cout << "                        Simulation Paused ..." << std::endl;

			std::cout << "                    Press escape to continue" << std::endl;

			mDrawBoardOnPause = false;
		}
		

		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		break;
	}
	
}