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
	None,
	Setup,
	Simulation,
	Pause
} RunningState;

typedef struct full_state_t
{
	RunningState CurrentState;
	bool changeState;
	RunningState NewState;
} FullState;

class Game
{
private:
	uint8_t mUpdate;
	FullState mState;
	Board* mBoard;
	int mSimulationSteps;
	bool mDrawBoardOnPause;

	void setup(void);
	void simulation(void);
	void pause(void);

public:
	Game(void);
	~Game(void);
	void Run(void);
	void Render(void);
};