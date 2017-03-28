/*
@file objects.cpp
Implementation of objects.h
*/

#include "objects.h"

ScreenAliens::ScreenAliens(){
	this.xpos = 0;
	this.ypos = 0;
	this.alive = true;
}


ScreenAliens::ScreenAliens(int x, int y){
	this.xpos = x;
	this.ypos = y;
	this.alive = true;
}

AlienBob::AlienBob() : ScreenAliens() {};

AlienBob::AlienBob(int x, int y) : ScreenAliens(x, y) {};

AlienAlice::AlienAlice() : ScreenAliens() {};

AlienAlice::AlienAlice(int x, int y) : ScreenAliens(x, y) {};


