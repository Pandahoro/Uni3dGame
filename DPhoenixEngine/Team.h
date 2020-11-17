#pragma once
#include "D3DUtil.h"
#include "CharacterClass.h"

namespace DPhoenix
{
	enum TeamStates
	{
		TM_OK_TEAMSTATE,
		TM_DYING_TEAMSTATE,
		TM_DEAD_TEAMSTATE
	};


	class Team
	{
		//look at me breaking encapsulation again
		//if you want to fix this, points make prizes
	public:

		//member vars -------------------------------------
		std::vector<CharacterClass*> mTeamMembers;
		int mTPPool;
		TeamStates mTeamState;
		int mSaves;
		int mTeamNumber;

		//there might be more for this class yet
		//right now it's a useful place for other mechanics

		//member methods -----------------------------------
		//constructor / destructor
		Team();
		~Team();

		//standard methods for game loop
		//we might not use these
		void Update(float dt);
		//void Draw();
	};
}

