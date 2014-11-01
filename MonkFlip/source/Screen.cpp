#include "Screen.h"

#include "Input.h"
#include "Game.h"
#include "Button.h"

//
//
// Bucket is our main player object that the player can control by touching somewhere on the screen. When the user 
// touches the screen the bucket will be moved to the touched position. The bucket is also responsible for checking
// collisins with water droplets and updating the players score when the player collects them
//
//
//

//
//
// Bucket implementation
//
//

void Screen::Init()
{
	Type = ST_Screen;
	Font = Iw2DCreateFontResource("trebuchet_12");
}

bool Screen::Update()
{
	CSprite::Update();

	// If user touches the screen then move the bucket to the touched position
	//if (g_Input.getTouchCount() != 0)
	//{
	//	Position.x = g_Input.getTouch(0)->x;
	//}

	// Process collision with water drops
	DrawValues();

	return true;
}

void Screen::DrawValues()
{
	// Set the current font
	Iw2DSetFont(Font);

	// Reset the visual transform
	Iw2DSetTransformMatrix(CIwMat2D::g_Identity.ConvertToCIwFMat2D());

	// Set teh texts colour to black
	Iw2DSetColour(0xff000000);

	// Draw the score label
	Iw2DDrawString("Score:", CIwFVec2(10, 10), CIwFVec2(200, 30), IW_2D_FONT_ALIGN_LEFT, IW_2D_FONT_ALIGN_TOP);

	// Convert the score number to text
	char str[32];
	snprintf(str, 32, "%d", 23);

	// Draw the score number
	Iw2DDrawString(str, CIwFVec2(100, 288), CIwFVec2(200, 30), IW_2D_FONT_ALIGN_LEFT, IW_2D_FONT_ALIGN_TOP);
}
/*
void Screen::DoCollision()
{
	// Search the sprite list in the spritemanager for water drops
	for (CSpriteManager::Iterator it = Parent->begin(); it != Parent->end(); ++it)
	{
		if ((*it)->getType() == ST_WaterDrop)
		{
			WaterDrop* drop = (WaterDrop*)*it;
			// Check to see if the water drop sprite is within 16 pixels of the bucket either way
			int dx = drop->getPosition().x - Position.x;
			if (dx < 0) dx = -dx;
			if (dx < 16)
			{
				// Check to see if the water drop is within the height range of the bucket
				int drop_y = drop->getPosition().y;
				if (drop_y > (Position.y - Height / 2) && drop_y < (Position.y + Height / 2))
				{
					// Tell the water drop to detsory itself
					drop->Destroy();

					// Tell the game to update our score
					g_Game.updateScore(1);
				}
			}
		}
	}
}

*/