// GameOfLife.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include "Board.h"
#include "Keyboard.h"
#include <chrono>
#include <thread>
#include <iostream>

typedef enum running_state_t
{
	Setup,
	Simulation,
	Pause
} RunningState;

constexpr uint8_t kHeight = 20;
constexpr uint8_t kWidth = 20;

// TODO: Reference additional headers your program requires here.
