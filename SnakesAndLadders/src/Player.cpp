#include "Player.h"

Player::Player( Ogre::SceneManager *sceneMan, int id){
	height = 100 * .025;
	lenght = 100 * .025;
	width = 100 * .025;
	direction = -1; //This allows the player token to travel in the correct direction as it's value is multiplied by the input value
	
	squareNumber = 1;

	mEntity = sceneMan->createEntity("player" + Ogre::StringConverter::toString(id), Ogre::SceneManager::PT_CUBE);

	
	if (id == 0){
		position = Ogre::Vector3(72.5 - width ,	2,	-61.75);
		mEntity->setMaterialName("SnakesAndLadders/Red");
	}
	else if (id == 1){
		position = Ogre::Vector3(65.25 - width ,	2,	-61.75);
		mEntity->setMaterialName("SnakesAndLadders/Blue");
	}
	else if (id == 2){
		position = Ogre::Vector3(72.5 - width ,	2,	-72.5 + width);
		mEntity->setMaterialName("SnakesAndLadders/Green");
	}
	else {
		position = Ogre::Vector3(65.25 - width ,	2,	-72.5 + width);
		mEntity->setMaterialName("SnakesAndLadders/Yellow");
	}

	mSceneNode = sceneMan->getRootSceneNode()->createChildSceneNode();

	mSceneNode->scale(.025,.025,.025);//(0.03125,0.03125,0.03125);
	mSceneNode->attachObject(mEntity);
	mSceneNode->setPosition(position);
}

bool Player::chooseRollTwo(){
	return true;
}

Player::Player(){
}

void Player::moveForward(float addVal){
	if (squareNumber < 100){
		if (squareNumber%10 == 0){
			position.z = position.z + addVal;
			direction = direction *-1;
		}
		else {//(squareNumber%10 != 0){
			position.x = position.x + (addVal* direction);
		}

		mSceneNode->setPosition(position);
		squareNumber++;
	}
}

void Player::moveBackward(float addVal){
	if (squareNumber < 100){
		if ((squareNumber-1)%10 == 0){
			position.z = position.z - addVal;
			direction = direction *-1;
		}
		else {//(squareNumber%10 != 0){
			position.x = position.x - (addVal* direction);
		}

		mSceneNode->setPosition(position);
		squareNumber--;
	}
}


int Player::getSquareNumber(){
	return squareNumber;
}