#if !defined(_C_GAME_H_)
#define _C_GAME_H_

#include "s3e.h"
#include "Iw2D.h"
#include "IwGxFont.h"

#include "Sprite.h"

#include "Player.h"

enum eSpriteType
{
	ST_None, 
	ST_Screen, 
	ST_Button,
	ST_Card
};

enum scene
{
	Scene_Title,
	Scene_Game,
	Scene_Options,
	Scene_GameOver
};

//
//
// CGame - General game class 
//
// CGame is responsible for updating input, screen and sprites
// 
//

class CGame
{
	/// Properties
protected:
	CSpriteManager*				SpriteManager;					// The sprite manager handles a collection of game sprites
public:
	int							scene;
	Player					    players;

	int							Score;							// Game score
	CSpriteManager*				getSpriteManager()				{ return SpriteManager; }
	void						addSprite(CSprite* sprite)		{ SpriteManager->addSprite(sprite); }
	void						removeSprite(CSprite* sprite)	{ SpriteManager->removeSprite(sprite); }

	//void						updateScore(int amount);
	/// Properties End
protected:

	// Shared images
	CIw2DImage*					background_image;

	CIw2DImage*					button_image;
	CIw2DImage*					screen_image;

	// Font
	CIw2DFont*					Font;

	void	DrawValues();		// Draw the score on screen

public:
	CGame() : SpriteManager(NULL)	{}

	void	Init();				// Initialise the game
	void	Release();			// Release the game
	void	Update();			// Update the game
	void	Draw();				// Draw the game

	void setupGame(int numPlayers, int numPiles);
};

extern CGame g_Game;




#endif // _C_GAME_H_
