#ifndef PLAYER_h
#define PLAYER_h

#include <Ogre.h>
#include <string>


class Player{
public:
	Player(Ogre::SceneManager *, int);//constructor
	Player();//Default constructor for Ai
	virtual bool chooseRollTwo();
	int getSquareNumber();
	void moveForward(float);
	void moveBackward(float);
	Ogre::Vector3 position;
	Ogre::Entity* mEntity;
	Ogre::SceneNode* mSceneNode;
	int width, lenght, height;
	int direction;
	int squareNumber;
private:
	/*Ogre::Vector3 position;
	Ogre::Entity* mEntity;
	Ogre::SceneNode* mSceneNode;
	int width, lenght, height;
	int direction;
	int squareNumber;*/
};

#endif