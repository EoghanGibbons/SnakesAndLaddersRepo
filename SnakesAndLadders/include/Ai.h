#ifndef AI_h
#define AI_h

#include <Ogre.h>
#include <string>
#include "Player.h"
#include "Movers.h"

class Ai : public Player{
public:
	Ai(Ogre::SceneManager *, int);//Constructor
	void moveForward(float);
	void moveBackward(float);
	virtual bool chooseRollTwo();
	//bool chooseRoll();
	Ogre::Vector3 getPosition();
private:
	//Ogre::Vector3 position;
	//Ogre::Entity* mEntity;
	//Ogre::SceneNode* mSceneNode;
};
#endif