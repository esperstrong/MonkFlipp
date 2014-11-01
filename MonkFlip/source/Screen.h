#if !defined(_SCREEN_H_)
#define _SCREEN_H_

#include "s3e.h"
#include "Iw2D.h"

#include "Sprite.h"

//
//
// Bucket - The main buucket object that the player can move around to collect water drops
//
// Bucket is derived from sprite so we can make use of sprites inherent sprite rendering capabilities
//
// 
class Screen : public CSprite
{
	/// Properties
protected:
public:
	char* equation;
	float value;
	// Font
	CIw2DFont*					Font;
	/// Properties End

protected:
	//void	DoCollision();

public:
	Screen() : CSprite() { }
	virtual ~Screen() {}

	void	Init();				// Initialise the bucket game object
	bool	Update();			// Update the bucket game object
	void	DrawValues();
};



#endif // _BUCKET_H_
