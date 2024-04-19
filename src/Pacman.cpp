#include "Pacman.h"
#include "Entity.h"
#include "Direction.h"

#include "raylib.h"

Pacman::Pacman(PosDouble startPos, Direction startDir): 
	Entity(startPos, startDir), 
	_nextdirection(startDir) 
{}

void Pacman::listenForClicks() {
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
		this->_nextdirection.setX(Dir::Stop);
		this->_nextdirection.setY(Dir::Back);
	} else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
		this->_nextdirection.setX(Dir::Stop);
		this->_nextdirection.setY(Dir::Forward);
	} else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
		this->_nextdirection.setX(Dir::Forward);
		this->_nextdirection.setY(Dir::Stop);
	} else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
		this->_nextdirection.setX(Dir::Back);
		this->_nextdirection.setY(Dir::Stop);
	}
}

void Pacman::updateDirection() {
	this->setDirection(this->_nextdirection);
}

PosInt Pacman::calcNextPos(bool useCurrDir) {
	Direction dirToUse = useCurrDir ? this->getDirection() : this->_nextdirection;
	auto pos = this->getPos();
	return {
    	int(pos.y) + dirToUse.y(),
    	int(pos.x) + dirToUse.x()
  	};
}

bool Pacman::isNextDirTurningBack() {
	auto direction = this->getDirection();
	return (
		direction.x() == -this->_nextdirection.x() &&
		direction.y() == -this->_nextdirection.y()
	);
}

bool Pacman::isStopped() {
	auto direction = this->getDirection();
	return (
		direction.x() == Dir::Stop && 
		direction.y() == Dir::Stop
	);
}
