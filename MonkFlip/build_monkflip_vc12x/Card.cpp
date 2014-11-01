#include "Button.h"
#include "Game.h"

#include "Input.h"

#include <iostream>

using namespace std;

void Card::Init(char cap)
{
	Caption = cap;
	Pressed = false;
	Type = ST_Button;
	Position.x = 0;
	Position.y = 0;
}

bool Card::Update()
{

	// If user touches the screen then move the bucket to the touched position
	if (g_Input.getTouchCount() != 0)
	{
		if (insideButton(g_Input.getTouch(0)->x, g_Input.getTouch(0)->y))
			Pressed = true;

	}
	else if (Pressed){
		Pressed = false;
	}

	CSprite::Update();

	return true;

}

void Card::Draw(){
	CSprite::Draw();
	string s = string(1, Caption);
	Iw2DDrawString(s.c_str(), CIwFVec2(Position.x, Position.y), CIwFVec2(Width, Height), IW_2D_FONT_ALIGN_LEFT, IW_2D_FONT_ALIGN_TOP);
}

bool Card::insideButton(int x, int y){
	return Position.x - (Width / 2) <= x && Position.x + (Width / 2) >= x && Position.y - (Height / 2) <= y && Position.y + (Height / 2) >= y;
}