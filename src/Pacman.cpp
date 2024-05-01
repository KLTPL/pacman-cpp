#include "Pacman.h"
#include "Entity.h"
#include "Direction.h"

Pacman::Pacman(PosDouble startPos, Direction startDir): 
	Entity(startPos, startDir), 
	_nextdirection(startDir) 
{}

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

void Pacman::setNextDirection(Direction newNextDirection) {
	this->_nextdirection = newNextDirection;
}