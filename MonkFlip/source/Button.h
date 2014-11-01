#if !defined(_BUTTON_H_)
#define _BUTTON_H_

#include "s3e.h"
#include "Iw2D.h"

#include "Sprite.h"

#include <string>

enum buttonType
{
	BTN_NUM,
	BTN_OPER,
	BTN_EQUALS
};

//
//
// WaterDrop - Water drop objects are spawned at the top of the screen fall downwards until they hit the ground or are collected by the player bucket
//
// 
class Button : public CSprite
{
	/// Properties
protected:
	//CIwSVec2	Velocity;		// Velocity of water drop

public:
	bool		Pressed;
	char		Caption;
	//void		setVelocity(int vx, int vy)	{ Velocity.x = vx; Velocity.y = vy; }
	//void		Destroy()					{ Destroyed = true; }
	/// Properties End
protected:
	bool	insideButton(int x, int y);
public:
	Button() : CSprite() {}
	virtual ~Button()	{}

	void SetCaption(std::string cap);
	void Draw();
	void	Init(char cap);				// Initialise the water drop game object
	bool	Update();			// Update our water drop object
};



#endif // _WATER_DROP_H_
