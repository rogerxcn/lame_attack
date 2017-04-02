#ifndef OBJECTS_H
#define OBJECTS_H

#define ALIEN_HEIGHT 8
#define ALIEN_WIDTH 11
#define _ 0x000000 //BLK
#define X 0xFFFFFF //WH
#define WHITE 0xFFFFFF

class PlayerShip{

public:
	PlayerShip();
	
	int getX() { return this.xpos;}
	int getY() { return this.ypos;}
	void draw(uLCD_4DGL&);

private:
	int xpos;
	int ypos;
};


class ScreenAliens{

public:
	ScreenAliens();
	ScreenAliens(int, int);
	
	virtual void draw(uLCD_4DGL&);
	virtual void update();

	int getX() { return this.xpos; }
	int getY() { return this.ypos; }
	bool isAlive() { return this.alive; }
	void destroy() { this.alive = false; }

private:
	int xpos;
	int ypos;
	bool alive;
				
};   


class AlienBob : public ScreenAliens{

public:
	AlienBob();
	AlienBob(int, int);

	void draw(uLCD_4DGL&);
	void update();	

private:

	int alienBobDown_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
		_,_,X,_,_,_,_,_,X,_,_,
		_,_,_,X,_,_,_,X,_,_,_,
		_,_,X,X,X,X,X,X,X,_,_,
		_,X,X,_,X,X,X,_,X,X,_,
		X,X,X,X,X,X,X,X,X,X,X,
		X,_,X,X,X,X,X,X,X,_,X,
		X,_,X,_,_,_,_,_,X,_,X,
		_,_,_,X,X,_,X,X,_,_,_,

	};

	int alienBobUp_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
 		_,_,X,_,_,_,_,_,X,_,_,
  		X,_,_,X,_,_,_,X,_,_,X,
	 	X,_,X,X,X,X,X,X,X,_,X,
	  	X,X,X,_,X,X,X,_,X,X,X,
		X,X,X,X,X,X,X,X,X,X,X,
		_,_,X,X,X,X,X,X,X,_,_,
		_,_,X,_,_,_,_,_,X,_,_,
		_,X,_,_,_,_,_,_,_,X,_,
	};


};


class AlienAlice : public ScreenAliens{

public:
	AlienAlice();
	AlienAlice(int, int);

	void draw(uLCD_4DGL&);
	void update();

private:

	int alienAlice_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
 		_,_,_,_,X,X,X,_,_,_,_,
  	_,X,X,X,X,X,X,X,X,X,_,
	 	X,X,X,X,X,X,X,X,X,X,X,
	  X,X,X,_,_,X,_,_,X,X,X,
		X,X,X,X,X,X,X,X,X,X,X,
		_,_,_,X,X,_,X,X,_,_,_,
		_,_,X,X,_,_,_,X,X,_,_,
		X,X,_,_,_,X,_,_,_,X,X,
	};

};

#endif 
