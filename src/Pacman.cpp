#include "Pacman.h"
#include "Entity.h"

#include "raylib.h"

Pacman::Pacman(PosDouble startPos, Direction startDir): 
	Entity(startPos, startDir), 
	_nextdirection(startDir) 
{}

void Pacman::listenForClicks() {
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
		this->_nextdirection.x = Dir::Stop;
		this->_nextdirection.y = Dir::Back;
	} else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
		this->_nextdirection.x = Dir::Stop;
		this->_nextdirection.y = Dir::Forward;
	} else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
		this->_nextdirection.x = Dir::Forward;
		this->_nextdirection.y = Dir::Stop;
	} else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
		this->_nextdirection.x = Dir::Back;
		this->_nextdirection.y = Dir::Stop;
	}
}

void Pacman::updateDirection() {
	this->_direction = this->_nextdirection;
}

PosInt Pacman::calcNextPos(bool useCurrDir) {
	Direction dirToUse = useCurrDir ? this->_direction : this->_nextdirection;
	return {
    	int(this->_pos.y) + dirToUse.y,
    	int(this->_pos.x) + dirToUse.x
  	};
}

bool Pacman::isNextDirTurningBack() {
	return (
		this->_direction.x == -this->_nextdirection.x &&
		this->_direction.y == -this->_nextdirection.y
	);
}

bool Pacman::isStopped() {
	return (
		this->_direction.x == Dir::Stop && 
		this->_direction.y == Dir::Stop
	);
}
