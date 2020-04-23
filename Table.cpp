#include "Table.h"
Table::Table(char* objFile, bool hasTexture, map<string, texture>* textures):Model_OBJ(objFile, hasTexture, textures){ //tao ban
	this->right = 0.46;
	this->top = -0.19;
	this->bottom = 0.2;
	this->heigh = 0.2574;
	holes[0] = new Hole(glm::vec3(-0.46388,heigh,0.22166), 0.04);
	holes[1] = new Hole(glm::vec3(-0.46388, heigh, -0.20933), 0.04);
	holes[2] = new Hole(glm::vec3(0.00469, heigh, -0.22465), 0.05);		
	holes[3] = new Hole(glm::vec3(0.00479, heigh, 0.23079), 0.05);			
	holes[4] = new Hole(glm::vec3(0.47007, heigh, -0.20933), 0.04);		
	holes[5] = new Hole(glm::vec3(0.47007, heigh, 0.22153), 0.04);
}

/*Kiem tra va cham cac canh ban*/
bool Table::isBallHitLeftBorder(Ball *ball){ //canh trai
	if ( ball->pos.x < (this->left + ball->radius) ) 
		return true;
	else 
		return false;
}


bool Table::isBallHitRightBorder(Ball *ball){ //canh phai
	if ( ball->pos.x > (this->right - ball->radius) )
		return true;
	else
		return false;
}

bool Table::isBallHitTopBorder(Ball *ball){ //canh tren
	if ( ball->pos.z < (this->top + ball->radius) )
		return true;
	else 
		return false;
}

bool Table::isBallHitBottomBorder(Ball *ball){ // canh duoi
	if ( ball->pos.z > (this->bottom - ball->radius) )
		return true;
	else 
		return false;	
}
/*Kiem tra va cham cac goc ban*/

void Table::resToBallHitTable(Ball *ball){ // xu ly va cham ban
	if ( isBallHitLeftBorder(ball) ){
		ball->vel.x = -ball->vel.x;	
		ball->pos.x = left + ball->radius;
	} else 
	if ( isBallHitRightBorder(ball) ){
		ball->vel.x = -ball->vel.x;	
		ball->pos.x = right - ball->radius;
	}		
				
	if ( isBallHitTopBorder(ball)){
		ball->vel.z = -ball->vel.z;								
		ball->pos.z = top + ball->radius;		
	} else 
	if ( isBallHitBottomBorder(ball)){
		ball->vel.z = -ball->vel.z;								
		ball->pos.z = bottom - ball->radius;				
	}
		
}

