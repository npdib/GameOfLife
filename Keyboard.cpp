#include "Keyboard.h"

Key left, right, up, down, space, enter, escape;

bool keyPressed(Key& key)
{
	if (key.pressed and !key.held)
	{
		//std::cout << "pressed, held, ready: " << key.pressed << ", " << key.held << ", " << key.ready << std::endl;
		key.pressed = false;
		return true;
	}
	else
	{
		return false;
	}
}

void GetKeyPresses(void)
{
	if ((GetKeyState(VK_LEFT) & 0x8000) or (GetKeyState('A') & 0x8000))
	{
		if (!left.held)
		{
			left.pressed = true;
			left.held = true;
		}
	}
	else
	{
		left.held = false;
	}
	if ((GetKeyState(VK_RIGHT) & 0x8000) or (GetKeyState('D') & 0x8000))
	{
		if (!right.held)
		{
			right.pressed = true;
			right.held = true;
		}
	}
	else
	{
		right.held = false;
	}

	if ((GetKeyState(VK_DOWN) & 0x8000) or (GetKeyState('S') & 0x8000))
	{
		if (!down.held)
		{
			down.pressed = true;
			down.held = true;
		}
	}
	else
	{
		down.held = false;
	}
	if ((GetKeyState(VK_UP) & 0x8000) or (GetKeyState('W') & 0x8000))
	{
		if (!up.held)
		{
			up.pressed = true;
			up.held = true;
		}
	}
	else
	{
		up.held = false;
	}

	if ((GetKeyState(VK_SPACE) & 0x8000))
	{
		if (!space.held)
		{
			space.pressed = true;
			space.held = true;
		}
	}
	else
	{
		space.held = false;
	}

	if ((GetKeyState(VK_RETURN) & 0x8000))
	{
		if (!enter.held)
		{
			enter.pressed = true;
			enter.held = true;
		}
	}
	else
	{
		enter.held = false;
	}

	if ((GetKeyState(VK_ESCAPE) & 0x8000))
	{
		if (!escape.held)
		{
			escape.pressed = true;
			escape.held = true;
		}
	}
	else
	{
		escape.held = false;
	}
}