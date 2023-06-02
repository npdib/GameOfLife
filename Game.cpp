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

uint8_t Game::GetAliveNeighbours(uint8_t row, uint8_t col)
{
	uint8_t neighbours = 0;

	for (uint8_t i = row - 1; i <= row + 1; i++)
	{
		for (uint8_t j = col - 1; j <= col + 1; j++)
		{
			if (!(i == row and j == col))
			{
				if (mBoard->getPiece(i, j))
				{
					neighbours++;
				}
			}
		}
	}
	return neighbours;
}

bool Game::cellAlive(uint8_t neighbours, bool alive)
{
	if (alive)
	{
		if (neighbours == 2 or neighbours == 3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (neighbours == 3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Game::runSimulationStep()
{
	Board tempBoard(kHeight, kWidth);

	for (uint8_t i=1; i < kHeight - 1; i++)
	{
		for (uint8_t j=1; j < kWidth - 1; j++)
		{
			tempBoard.setPiece(cellAlive(GetAliveNeighbours(i, j), mBoard->getPiece(i, j)), i, j);
		}
	}

	bool BoardSame = true;

	for (uint8_t i = 1; i < kHeight - 1; i++)
	{
		for (uint8_t j = 1; j < kWidth - 1; j++)
		{
			if (tempBoard.getPiece(i,j) != mBoard->getPiece(i, j))
			{
				BoardSame = false;
				break;
			}
		}

		if (!BoardSame)
		{
			break;
		}
	}

	if (BoardSame)
	{
		mState.NewState = Finished;
		mState.changeState = true;
		mDrawBoardOnce = true;
	}

	for (uint8_t i = 1; i < kHeight - 1; i++)
	{
		for (uint8_t j = 1; j < kWidth - 1; j++)
		{
			mBoard->setPiece(tempBoard.getPiece(i, j), i, j);
		}
	}
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

	if (mSimulationSteps != 0 and mUpdate == 0)
	{
		runSimulationStep();
	}

	GetKeyPresses();
	if (keyPressed(escape))
	{
		mState.NewState = Pause;
		mState.changeState = true;
		mDrawBoardOnce = true;
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

void Game::finished()
{
	mBoard->showCursor(false);

	GetKeyPresses();
	if (keyPressed(enter))
	{
		mState.NewState = Setup;
		mState.changeState = true;
		mBoard->resetBoardAndCursor();
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
	case Finished:
		finished();
		break;
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
			mUpdate = 19;
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

		if (mDrawBoardOnce)
		{
			mBoard->drawBoard();

			std::cout << "                   Current simulation steps:  " << mSimulationSteps << std::endl;

			std::cout << "                        Simulation Paused ..." << std::endl;

			std::cout << "                    Press escape to continue" << std::endl;

			mDrawBoardOnce = false;
		}


		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		break;

	case Finished:
		if (mDrawBoardOnce)
		{
			mBoard->drawBoard();

			std::cout << "                  Simulation Finished in " << mSimulationSteps - 2 << " steps." << std::endl;
			std::cout << "                  Press enter to restart ... " << std::endl;

			mDrawBoardOnce = false;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		break;
	}
}

void Game::ChangeState()
{
	if (mState.changeState)
	{
		mState.CurrentState = mState.NewState;
		mState.changeState = false;
		mState.NewState = None;
		mUpdate = 0;
	}
}
