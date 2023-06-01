#pragma once

#include "Board.h"
#include "Keyboard.h"
#include <chrono>
#include <thread>
#include <iostream>

constexpr uint8_t kHeight = 20;
constexpr uint8_t kWidth = 20;

typedef enum running_state_t
{
	Setup,
	Simulation,
	Pause
} RunningState;

class Game
{
private:
	uint8_t mUpdate;
	RunningState mState;
	Board* mBoard;

	void setup(void);

public:
	Game(void);
	~Game(void);
	void Run(void);
	void Render(void);
};