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
	Pause,
	Finished
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
	bool mDrawBoardOnce;

	uint8_t GetAliveNeighbours(uint8_t row, uint8_t col);
	bool cellAlive(uint8_t neighbours, bool alive);

	void runSimulationStep(void);

	void setup(void);
	void simulation(void);
	void pause(void);
	void finished(void);

public:
	Game(void);
	~Game(void);
	void Run(void);
	void Render(void);
	void ChangeState(void);
};