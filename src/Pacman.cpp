#include "Pacman.h"
#include "Entity.h"

#include "raylib.h"

Pacman::Pacman(PosDouble startPos, Direction startDir): Entity(startPos, startDir) {
	this->_nextSpeedDir = startDir;
}

void Pacman::listenForClicks() {
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
		this->_nextSpeedDir.x = Dir::Stop;
		this->_nextSpeedDir.y = Dir::Back;
	} else if (IsKeyPressed(KEY_S || IsKeyPressed(KEY_DOWN))) {
		this->_nextSpeedDir.x = Dir::Stop;
		this->_nextSpeedDir.y = Dir::Forward;
	} else if (IsKeyPressed(KEY_D || IsKeyPressed(KEY_RIGHT))) {
		this->_nextSpeedDir.x = Dir::Forward;
		this->_nextSpeedDir.y = Dir::Stop;
	} else if (IsKeyPressed(KEY_A || IsKeyPressed(KEY_LEFT))) {
		this->_nextSpeedDir.x = Dir::Back;
		this->_nextSpeedDir.y = Dir::Stop;
	}
}

void Pacman::updateSpeedDir() {
	this->_speedDir = this->_nextSpeedDir;
}

PosInt Pacman::calcNextPos(bool useCurrDir) {
	Direction dirToUse = useCurrDir ? this->_speedDir : this->_nextSpeedDir;
	return {
    	int(this->_pos.y) + dirToUse.y,
    	int(this->_pos.x) + dirToUse.x
  	};
}

bool Pacman::isNextDirTurningBack() {
	return (
		this->_speedDir.x == -this->_nextSpeedDir.x &&
		this->_speedDir.y == -this->_nextSpeedDir.y
	);
}

bool Pacman::isStopped() {
	return (
		this->_speedDir.x == Dir::Stop && 
		this->_speedDir.y == Dir::Stop
	);
}
