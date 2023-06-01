#include "Board.h"

Board::Board(uint8_t height, uint8_t width)
{
	mHeight = height + 2;
	mWidth = width + 2;
	mCursorCol = 1;
	mCursorRow = 1;
	mShowCursor = true;
	mBoard = new bool*[mWidth];
	for (size_t i = 0; i < mWidth; i++) mBoard[i] = new bool[mHeight];

	for (uint8_t i = 0; i < mHeight; i++)
	{
		for (uint8_t j = 0; j < mWidth; j++)
		{
			if (i == 0 or j == 0 or i == (mHeight - 1) or j == (mHeight - 1))
			{
				mBoard[i][j] = false;
			}
			else
			{
				setPiece(false, i, j);
			}
		}
	}
}

Board::~Board()
{
	for (size_t i = 0; i < mWidth; i++) delete[] mBoard[i];
	delete[] mBoard;
}

void Board::moveCursor(Direction direction)
{
	switch(direction)
	{
	case Left:
		if (mCursorCol > 1)
		{
			mCursorCol--;
		}
		else
		{
			mCursorCol = mWidth - 2;
		}
		break;
	case Right:
		if (mCursorCol < mWidth - 2)
		{
			mCursorCol++;
		}
		else
		{
			mCursorCol = 1;
		}
		break;
	case Down:
		if (mCursorRow < mHeight - 2)
		{
			mCursorRow++;
		}
		else
		{
			mCursorRow = 1;
		}
		break;
	case Up:
		if (mCursorRow > 1)
		{
			mCursorRow--;
		}
		else
		{
			mCursorRow = mHeight - 2;
		}
		break;
	}
}



void Board::setPiece(bool piece, uint8_t row, uint8_t col)
{
	if (row < 1 or row > (mHeight - 1) or col < 1 or col > (mWidth - 1))
		throw std::invalid_argument("invalid row/column, must be within the board");

	mBoard[row][col] = piece;
}


bool Board::getPiece(uint8_t row, uint8_t col)
{
	return mBoard[row][col];
}

void Board::swapTile(void)
{
	if (!mBoard[mCursorRow][mCursorCol])
	{
		setPiece(true, mCursorRow, mCursorCol);
	}
	else
	{
		setPiece(false, mCursorRow, mCursorCol);
	}
}

void Board::drawBoard()
{
	system("cls");
	std::cout << std::endl << std::endl << std::endl;
	for (uint8_t i = 1; i < mHeight - 1; i++)
	{
		std::cout << "        ";
		for (uint8_t j = 1; j < mWidth - 1; j++)
		{
			if (i == mCursorRow and j == mCursorCol and mShowCursor)
			{
				std::cout << ' ' << (unsigned char) 219 << ' ';
			}
			else
			{
				char displaySymbol = (mBoard[i][j]) ? 'o' : '.';
				std::cout << ' ' << displaySymbol << ' ';
			}			
		}

		std::cout << std::endl;
	}

	mShowCursor = !mShowCursor;
}
