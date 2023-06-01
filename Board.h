#pragma once

#include <iostream>

typedef enum direction_t
{
	Left,
	Right,
	Up,
	Down
} Direction;

class Board
{
private:
	uint8_t mCursorRow;
	uint8_t mCursorCol;
	bool mShowCursor;
	uint8_t mHeight;
	uint8_t mWidth;
	bool** mBoard;

public:
	Board(uint8_t height, uint8_t width);
	~Board();
	void moveCursor(Direction direction);
	void setPiece(bool piece, uint8_t row, uint8_t col);
	bool getPiece(uint8_t row, uint8_t col);
	void swapTile(void);
	void drawBoard(void);
};