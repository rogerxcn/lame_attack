/* main cpp file */

#include "mbed.h"
#include "uLCD_4DGL.h" 
#include "Speaker.h" 
#include "Timer.h"

#include <ctime>
#include <cstdlib>
#include <cmath>

#define ALIEN_TYPES 2
#define ALIEN_BOB 0
#define ALIEN_ALICE 1


uLCD_4DGL uLCD(p28, p27, p29); // serial tx, serial rx, reset pin;
Speaker mySpeaker(p21);
Timer timer;

//Instantiate pins for pushbutton
DigitalIn pbLeft(p16);
DigitalIn pbMid(p17);
DigitalIn pbRight(p18);


short int bulletX = 0;
short int bulletY = 0;
bool bulletExist = false;

PlayerShip* player = new PlayerShip();
ScreenAliens* aliens[6];

/* Global Functions */

void draw_aliens(){
	for (int i = 0; i < 6; i++) {
		if (aliens[i] -> isAlive()) aliens[i]->draw(uLCD);
	}
}

void drawBullet(){
	uLCD.rectangle(bulletX-1, bulletY-1, bulletX+1, bulletY-1, 0xFFFFFF);
}

void updateBullet(){
	bulletY += 3;
	for (int i = 0; i < 6; i++) {
		bool nearX = abs(bulletX - alien[i]->getX) <= 2;
		bool nearY = abs(bulletY - alien[i]->getY) <= 2;
		if (nearX && nearY) {
			alien[i] -> destroy();
			bulletExist = false;
		}
	}
}

void generateBullet(int x, int y) {
	bulletX = player -> getX();
	bulletY = player -> getY();
	bulletExist = true;
}

/* main function */

int main(){
	pbLeft.mode(PullUp);
	pbRight.mode(PullUp);
	pbMid.mode(PullUp);

	uLCD.cls();


	for (int i = 0; i < 6; i++){
		
		short int type = rand() % ALIEN_TYPES;
		
		switch(type){
			case ALIEN_BOB:
				alien[i] = new AlienBob();
				break;
			case ALIEN_ALICE:
				alien[i] = new AlienAlice();
				break;
			default:
				break;
		}
	}

	timer.reset();
	timer.start();

	while(true){
		uLCD.cls();
		player.draw(uLCD);
		draw_aliens();
		if (bulletExist) {
			updateBullet();
			drawBullet();
		}

		if (!pbLeft) {
			player -> moveLeft();
		}

		if (!pbRight) {
			player -> moveRight();
		}

		if (!pbMid) {
			if (!bulletExist) generateBullet(player -> getX, player -> getY);
		}

		if (allDead) endGame(timer.read());
	}
}
