#pragma once

#include "ECS.h"

class positionComponent : public Component
{

private:

	int xpos_, ypos_;

public:

	positionComponent(int x, int y) {

		xpos_ = x;
		ypos_ = y;

	}

	positionComponent() {

		xpos_ = 0;
		ypos_ = 0;

	}

	int x() const { return xpos_; }
	int y() const { return ypos_; }

	virtual void init() override {

		xpos_ = 0;
		ypos_ = 0;

	}

	virtual void setPos(int x, int y) {

		xpos_ = x;
		ypos_ = y;
	}

	virtual void update() override {
		xpos_++;
		ypos_++;
	}

};