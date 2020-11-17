#pragma once
#include "d3dutil.h"

namespace BTLTConst
{
#pragma region Settings

	//things like damage modifiers can go here

#pragma endregion Settings

#pragma region SelectMenuUI

	//for hover images
	const int selectHoverImageWidth = 300;
	const int selectHoverImageHeight = 350;

#pragma region HoverAndClickAreas

	//ALL RECT initialisations are in the order Left, Top, Right, Bottom

	//These are all based on the DirectX11 positions of the screen
	//where the origin 0,0 is in the centre

	const RECT selectToySoldier = { -800, 150, -800 + selectHoverImageWidth, 150 - selectHoverImageHeight };
	const RECT selectDarkAngel = { -500, 150, -500 + selectHoverImageWidth, 150 - selectHoverImageHeight };
	const RECT selectDragon = { -200, 150, -200 + selectHoverImageWidth, 150 - selectHoverImageHeight };
	const RECT selectBigCat = { 100, 150, 100 + selectHoverImageWidth, 150 - selectHoverImageHeight };
	const RECT selectUpArrow = { 700, 250, 700 + 50, 250 - 50 };
	const RECT selectDownArrow = { 700, 200, 700 + 50, 200 - 50 };
	const RECT selectRemoveLast = { 700, -100, 700 + 50, -100 -50 };

#pragma endregion HoverAndClickAreas

#pragma region TextPositions

	//these positions are based on an origin of 0,0 in the top left
	//as they are for font rendering positions
	const float selectedLevelLeft = 1350.0f;
	const float selectedLevelTop = 200.0f;

	const float selectedCharacterClassesLeft = 1250.0f;
	const float selectedCharacterClassesTop = 350.0f;
	const float selectedCharacterClassesRowSpacing = 50.0f;

	const float selectedEnemyClassesLeft = 1300.0f;
	const float selectedEnemyClassesTop = 710.0f;
	const float selectedEnemyClassesRowSpacing = 40.0f;

	const float selectedToySoldierStatsLeft = 200.0f;
	const float selectedToySoldierStatsTop = 650.0f;
	
	const float selectedDarkAngelStatsLeft = 500.0f;
	const float selectedDarkAngelStatsTop = 650.0f;

	const float selectedDragonStatsLeft = 800.0f;
	const float selectedDragonStatsTop = 650.0f;

	const float selectedBigCatStatsLeft = 1100.0f;
	const float selectedBigCatStatsTop = 650.0f;

#pragma endregion TextPositions

#pragma endregion SelectMenuUI

}

