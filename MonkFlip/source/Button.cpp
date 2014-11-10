#include "Button.h"
#include "Game.h"

#include "Input.h"

#include <iostream>

using namespace std;


void Button::Init()
{
	Caption = "";
	Pressed = false;
	Type = ST_Button;
	Position.x = 20 + (rand() * (Iw2DGetSurfaceWidth() - 40)) / RAND_MAX;
	Position.y = -20;
}

bool Button::Update()
{
	//if (Destroyed)
	//	return false;	// Tell the sprite manager to remove this water drop

	// If user touches the screen then move the bucket to the touched position
	if (g_Input.getTouchCount() != 0)
	{
		//Position.x = g_Input.getTouch(0)->x;
		if (insideButton(g_Input.getTouch(0)->x, g_Input.getTouch(0)->y))
			Pressed = true;

	}else if (Pressed){
		/*if (Caption == 'c'){
			g_Game.Score = 0;
			g_Game.ValueBefore = 0;
			g_Game.calculation = "YusukeCalc";
			g_Game.error = false;
			g_Game.OperPicking = false;
		} */
		Pressed = false;
	}

	CSprite::Update();

	//Position.x += Velocity.x;
	//Position.y += Velocity.y;

	//if (Position.y >= Iw2DGetSurfaceHeight() + 20)
	//{
	//	return false;	// Tell the sprite manager to remove this water drop
	//}

	return true;

}

void Button::Draw(){
	CSprite::Draw();
	//string s = string(1,Caption);
	Iw2DDrawString(Caption, CIwFVec2(Position.x, Position.y), CIwFVec2(Width, Height), IW_2D_FONT_ALIGN_LEFT, IW_2D_FONT_ALIGN_TOP);
}

bool Button::insideButton(int x, int y){
	return Position.x - (Width / 2) <= x && Position.x + (Width / 2) >= x && Position.y - (Height / 2) <= y && Position.y + (Height/2) >= y;
}