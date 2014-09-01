#include "Ai.h"

Ai::Ai( Ogre::SceneManager *sceneMan, int id){
	
	height = 100 * .025;
	lenght = 100 * .025;
	width = 100 * .025;
	direction = -1; //This allows the player token to travel in the correct direction as it's value is multiplied by the input value
	
	squareNumber = 1;

	mEntity = sceneMan->createEntity("Ai" + Ogre::StringConverter::toString(id), Ogre::SceneManager::PT_SPHERE);
	
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

void Ai::moveForward(float addVal){
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

void Ai::moveBackward(float addVal){
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

bool Ai::chooseRollTwo(){
	for (int i = 6; i < 8; i++){
		if ((squareNumber + i == Movers::SNAKE_ONE[0]) || 
			(squareNumber + i == Movers::SNAKE_TWO[0]) || 
			(squareNumber + i == Movers::SNAKE_THREE[0]) || 
			(squareNumber + i == Movers::SNAKE_FOUR[0]) || 
			(squareNumber + i == Movers::SNAKE_FIVE[0])){
			return false;
		}
	}
	for (int i = 1; i < 7; i++){
		if ((squareNumber + i == Movers::LADDER_ONE[0]) || 
			(squareNumber + i == Movers::LADDER_TWO[0]) || 
			(squareNumber + i == Movers::LADDER_THREE[0]) || 
			(squareNumber + i == Movers::LADDER_FOUR[0])){
			return false;
		}
	}
	return true;
}


Ogre::Vector3 Ai::getPosition(){
	return position;
}