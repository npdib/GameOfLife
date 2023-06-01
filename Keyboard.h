#pragma once

#include <Windows.h>
#include <iostream>

typedef struct key_t
{
	bool pressed = false;
	bool held = false;
} Key;

extern Key left, right, up, down, enter;

bool keyPressed(Key& key);
void GetKeyPresses(void);