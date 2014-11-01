#include "IwResManager.h"
#include "Input.h"

#include "Game.h"
#include "Screen.h"
#include "Button.h"


//
// Global declaration of the CGame class. Allows global access to the game class
//
CGame g_Game;

//
//
// CGame implementation
//
//
void CGame::Init()
{

	// Allocate the sprite manager
	SpriteManager = new CSpriteManager();

	// Load the resource group that contains our graphics
	IwGetResManager()->LoadGroup("MonkFlip.group");

	// Create images that we can use to render our objects
	background_image	= Iw2DCreateImageResource("background");
	//bucket_image		= Iw2DCreateImageResource("bucket");
	//water_drop_image	= Iw2DCreateImageResource("water_drop");
	//cloud_image			= Iw2DCreateImageResource("cloud");
	button_image = Iw2DCreateImageResource("button");
	//equalsbutton_image = Iw2DCreateImageResource("equalsbutton");
	screen_image = Iw2DCreateImageResource("screen");

	// Create the font that is used to display the score
	Font = Iw2DCreateFontResource("trebuchet_12");

	// Get screen dimentions
	int screen_width = Iw2DGetSurfaceWidth();
	int screen_height = Iw2DGetSurfaceHeight();

	// Create background sprite
	CSprite* background_sprite = new CSprite();
	background_sprite->Init();
	background_sprite->setPosAngScale(screen_width / 2, screen_height / 2, 0, IW_GEOM_ONE);
	background_sprite->setImage(background_image);
	background_sprite->setDestSize(screen_width, screen_height);
	SpriteManager->addSprite(background_sprite);


}

void CGame::Release()
{
	// Clean-up sprite manager
	if (SpriteManager != NULL)
	{
		delete SpriteManager;
		SpriteManager = NULL;
	}

	// Clean-up font
	if (Font != NULL)
	{
		delete Font;
		Font = NULL;
	}

	// Clean-up shared images
	if (background_image != NULL)
	{
		delete background_image;
		background_image = NULL;
	}
	if (button_image != NULL)
	{
		delete button_image;
		button_image = NULL;
	}
	if (screen_image != NULL)
	{
		delete screen_image;
		screen_image = NULL;
	}
}

void CGame::Update()
{
	// Update the games sprite objects
	SpriteManager->Update();

	// Updaste water drop timer
	/*WaterDropTimer--;
	if (WaterDropTimer <= 0)
	{
		// Create water drop
		WaterDropTimer = 10;
		WaterDrop* drop_sprite = new WaterDrop();
		drop_sprite->Init();
		drop_sprite->setImage(water_drop_image);
		SpriteManager->addSprite(drop_sprite);
	}*/
}

void CGame::Draw()
{
	// Clear screen 
	Iw2DSurfaceClear(0xff000000);

	// Draw the games sprite objects
	SpriteManager->Draw();

	// Draw the score text
	DrawValues();

	// Show surface
	Iw2DSurfaceShow();
}

/*
void CGame::updateScore(int amount)
{
	// Adjust score
	Score += amount;
}

*/
void CGame::DrawValues()
{
	// Set the current font
	Iw2DSetFont(Font);

	// Reset the visual transform
	Iw2DSetTransformMatrix(CIwMat2D::g_Identity.ConvertToCIwFMat2D());

	// Set teh texts colour to black
	Iw2DSetColour(0xff000000);

	// Draw the score label
	Iw2DDrawString("Monkflippp", CIwFVec2(25, 40), CIwFVec2(300, 10), IW_2D_FONT_ALIGN_LEFT, IW_2D_FONT_ALIGN_TOP);

	// Convert the score number to text
	char str[32];
	snprintf(str, 32, "%d", Score);

	// Draw the score number
	//Iw2DDrawString(str, CIwFVec2(25, 70), CIwFVec2(300, 10), IW_2D_FONT_ALIGN_LEFT, IW_2D_FONT_ALIGN_TOP);
}