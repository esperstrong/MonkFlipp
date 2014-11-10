#include "Card.h"
#include "Game.h"

#include "Input.h"

#include <iostream>

using namespace std;

void Card::Init(char cap)
{
	Type = ST_Card;
	Position.x = 0;
	Position.y = 0;
}

bool Card::Update()
{

	CSprite::Update();

	return true;

}

void Card::Draw(){
	CSprite::Draw();
	string s = "testring";//string(1, Caption);
	Iw2DDrawString(s.c_str(), CIwFVec2(Position.x, Position.y), CIwFVec2(Width, Height), IW_2D_FONT_ALIGN_LEFT, IW_2D_FONT_ALIGN_TOP);
}