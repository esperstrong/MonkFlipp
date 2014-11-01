#if !defined(_CARD_H_)
#define _CARD_H_

#include "s3e.h"
#include "Iw2D.h"

#include "Sprite.h"

#include <string>

enum cardType
{
	//empty for now, put in card types like hime, bozu, etc
};

class Card : public CSprite
{
	/// Properties
protected:
	int type;
public:
	/// Properties End
protected:
public:
	Card() : CSprite() {}
	virtual ~Card()	{}

	void Draw();
	void	Init(char cap);				// Initialise the card game object
	bool	Update();			// Update our card object
};



#endif // _CARD_H_
