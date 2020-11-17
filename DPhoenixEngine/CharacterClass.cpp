#include "CharacterClass.h"

DPhoenix::CharacterClass::CharacterClass(CharacterClasses _class, TextureMgr * _texMgr,
	ID3D11Device * _md3dDevice, AudioMgr * _audioMgr)
{
	mClass = _class;
	mTexMgr = _texMgr;
	md3dDevice = _md3dDevice;
	mAudioMgr = _audioMgr;

	switch (mClass)
	{
	case TOY_SOLDIER_CLASS:
		//load in initial model / rig with first animation
		mAnimModel = new DPhoenix::SkinnedModel(md3dDevice, *mTexMgr,
			"Models\\SoldierAnimations\\SoldierIdle.dae", "Models\\SoldierAnimations\\");

		//load all animations before calling construct animations
		mAnimModel->Animator->LoadNewAnimations("Models\\SoldierAnimations\\SoldierDancing.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\SoldierAnimations\\SoldierMeleeKick.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\SoldierAnimations\\SoldierRunning.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\SoldierAnimations\\SoldierMagic.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\SoldierAnimations\\SoldierWeaponShoot.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\SoldierAnimations\\SoldierHurt.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\SoldierAnimations\\SoldierDying.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\SoldierAnimations\\SoldierDeadTwitch.dae");
		//this calculates all the frames of animation for the loaded animations
		mAnimModel->Animator->ConstructAnimations();

		//THESE STEPS ONLY FOR TOYLAND MODELS - THIS IS BECUASE THE TEXTURES AREN'T IN THE DAE / COLLADA FILE
		//HENCE WE'RE APPLYING IT TO ALL MODEL SUBSETS - FOR OTHER IMPORTED MODELS (E.G. MIXAMO)
		//THIS ISN'T NECESSARY
		for (int i = 0; i < mAnimModel->SubsetCount; i++)
		{
			mAnimModel->Subsets[i].materialIndex = 0;
		}

		mAnimModel->DiffuseMapSRV[0] =
			mTexMgr->CreateTexture("Models\\SoldierAnimations\\Textures\\2K\\SoldierTPoseWithBones_1001_BaseColor.png");
		mAnimModel->NormalMapSRV[0] =
			mTexMgr->CreateTexture("Models\\SoldierAnimations\\Textures\\2K\\SoldierTPoseWithBones_1001_Normal.png");
		//END TOYALNAD TEXTURE APPLICATION ----------------------------------------------------------------
		break;
	case DARK_ANGEL_CLASS:
		//load in initial model / rig with first animation
		mAnimModel = new DPhoenix::SkinnedModel(md3dDevice, *mTexMgr,
			"Models\\DarkangelAnimation\\AngelIdle.dae", "Models\\DarkangelAnimation\\");

		//load all animations before calling construct animations
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelDancing.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelMelee.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelSneakWalk.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelMelee.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelMelee.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelHurt.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelDying.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelDead.dae");
		//this calculates all the frames of animation for the loaded animations
		mAnimModel->Animator->ConstructAnimations();

		//THESE STEPS ONLY FOR TOYLAND MODELS - THIS IS BECUASE THE TEXTURES AREN'T IN THE DAE / COLLADA FILE
		//HENCE WE'RE APPLYING IT TO ALL MODEL SUBSETS - FOR OTHER IMPORTED MODELS (E.G. MIXAMO)
		//THIS ISN'T NECESSARY
		for (int i = 0; i < mAnimModel->SubsetCount; i++)
		{
			mAnimModel->Subsets[i].materialIndex = 0;
		}

		mAnimModel->DiffuseMapSRV[0] =
			mTexMgr->CreateTexture("Models\\DarkangelAnimation\\Texture\\darkAngelTexture.png");
		mAnimModel->NormalMapSRV[0] =
			mTexMgr->CreateTexture("Models\\DarkangelAnimation\\Texture\\darkAngelTexture_nm.png");
		//END TOYALNAD TEXTURE APPLICATION ----------------------------------------------------------------
		break;
	case DRAGON_CLASS:
		//load in initial model / rig with first animation
		mAnimModel = new DPhoenix::SkinnedModel(md3dDevice, *mTexMgr,
			"Models\\DarkangelAnimation\\AngelIdle.dae", "Models\\DarkangelAnimation\\");

		//load all animations before calling construct animations
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelDancing.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelMelee.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelSneakWalk.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelMelee.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelMelee.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelHurt.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelDying.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\DarkangelAnimation\\AngelDead.dae");
		//this calculates all the frames of animation for the loaded animations
		mAnimModel->Animator->ConstructAnimations();

		//THESE STEPS ONLY FOR TOYLAND MODELS - THIS IS BECUASE THE TEXTURES AREN'T IN THE DAE / COLLADA FILE
		//HENCE WE'RE APPLYING IT TO ALL MODEL SUBSETS - FOR OTHER IMPORTED MODELS (E.G. MIXAMO)
		//THIS ISN'T NECESSARY
		for (int i = 0; i < mAnimModel->SubsetCount; i++)
		{
			mAnimModel->Subsets[i].materialIndex = 0;
		}

		mAnimModel->DiffuseMapSRV[0] =
			mTexMgr->CreateTexture("Models\\DragonAnimation\\DragonTextures\\DragonSkin_D.png");
		mAnimModel->NormalMapSRV[0] =
			mTexMgr->CreateTexture("Models\\DragonAnimation\\DragonTextures\\DragonSkin_D_nm.png");
		//END TOYALNAD TEXTURE APPLICATION ----------------------------------------------------------------
		break;
	case BIG_CAT_CLASS:
		//load in initial model / rig with first animation
		mAnimModel = new DPhoenix::SkinnedModel(md3dDevice, *mTexMgr,
			"Models\\CatAnimations\\CatIdle.dae", "Models\\CatAnimations\\");

		//load all animations before calling construct animations
		mAnimModel->Animator->LoadNewAnimations("Models\\CatAnimations\\CatDance.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\CatAnimations\\CatMeleeSwipe.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\CatAnimations\\CatWalk.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\CatAnimations\\CatMagicSpit.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\CatAnimations\\CatMeleePounce.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\CatAnimations\\CatHitRecoil.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\CatAnimations\\CatDying.dae");
		mAnimModel->Animator->LoadNewAnimations("Models\\CatAnimations\\CatDead.dae");
		//this calculates all the frames of animation for the loaded animations
		mAnimModel->Animator->ConstructAnimations();

		//THESE STEPS ONLY FOR TOYLAND MODELS - THIS IS BECUASE THE TEXTURES AREN'T IN THE DAE / COLLADA FILE
		//HENCE WE'RE APPLYING IT TO ALL MODEL SUBSETS - FOR OTHER IMPORTED MODELS (E.G. MIXAMO)
		//THIS ISN'T NECESSARY
		for (int i = 0; i < mAnimModel->SubsetCount; i++)
		{
			mAnimModel->Subsets[i].materialIndex = 0;
		}

		mAnimModel->DiffuseMapSRV[0] =
			mTexMgr->CreateTexture("Models\\DragonAnimation\\DragonTextures\\DragonSkin_D.png");
		mAnimModel->NormalMapSRV[0] =
			mTexMgr->CreateTexture("Models\\DragonAnimation\\DragonTextures\\DragonSkin_D_nm.png");
		//END TOYALNAD TEXTURE APPLICATION ----------------------------------------------------------------
		break;
	}

	mModelInstance = new DPhoenix::SkinnedModelInstance("", mAnimModel);
	mModelInstance->Model = mAnimModel;

	SetBaseStats();
	CalculateStats(1);
}

DPhoenix::CharacterClass::CharacterClass(const CharacterClass & character)
{
	//stats --------------------------------------------------
	mLevel = character.mLevel;
	mBaseExp = character.mBaseExp; mExp = character.mExp;
	mBaseTP = character.mBaseTP; mTP = character.mTP;
	mBaseHP = character.mBaseHP; mHP = character.mHP; mMaxHP = character.mMaxHP;
	mBaseMP = character.mBaseMP; mMP = character.mMP; mMaxMP = character.mMaxMP;
	mBasePower = character.mBasePower; mPower = character.mPower;
	mBaseFirepower = character.mBaseFirepower; mFirepower = character.mFirepower;
	mBaseDefense = character.mBaseDefense; mDefense = character.mDefense;
	mBaseAccuracy = character.mBaseAccuracy; mAccuracy = character.mAccuracy;
	mBaseEvasion = character.mBaseEvasion; mEvasion = character.mEvasion;
	mBaseMagic = character.mBaseMagic; mMagic = character.mMagic;
	mBaseCharm = character.mBaseCharm; mCharm = character.mCharm;

	//character traits ---------------------------------------
	mClass = character.mClass;
	//actions should go here when determined
	//models should go here when determined

	//TEMP MODELS TO BEGIN WITH --------------------------------------
	mModelInstance = character.mModelInstance;

	mLifeState = character.mLifeState;
	mTurnState = character.mTurnState;
	mMoveState = character.mMoveState;
	mAnimation = character.mAnimation;

	//pointers to main singletons / devices
	mTexMgr = character.mTexMgr;
	md3dDevice = character.md3dDevice;
	mAudioMgr = character.mAudioMgr;
}

DPhoenix::CharacterClass::~CharacterClass()
{
}

void DPhoenix::CharacterClass::SetBaseStats()
{
	//as defined in the spreadsheet and GDD
	switch (mClass)
	{
	case TOY_SOLDIER_CLASS:
		mBaseExp = 100;
		mBaseTP = 10;
		mBaseHP = 30;
		mBaseMP = 15;
		mBasePower = 20;
		mBaseFirepower = 25;
		mBaseDefense = 20;
		mBaseAccuracy = 30;
		mBaseEvasion = 5;
		mBaseMagic = 2;
		mBaseCharm = 5;
		break;
	case DARK_ANGEL_CLASS:
		mBaseExp = 100;
		mBaseTP = 6;
		mBaseHP = 15;
		mBaseMP = 50;
		mBasePower = 5;
		mBaseFirepower = 5;
		mBaseDefense = 15;
		mBaseAccuracy = 10;
		mBaseEvasion = 20;
		mBaseMagic = 40;
		mBaseCharm = 25;
		break;
	case DRAGON_CLASS:
		mBaseExp = 100;
		mBaseTP = 6;
		mBaseHP = 40;
		mBaseMP = 50;
		mBasePower = 30;
		mBaseFirepower = 10;
		mBaseDefense = 50;
		mBaseAccuracy = 40;
		mBaseEvasion = 2;
		mBaseMagic = 30;
		mBaseCharm = 30;
		break;
	case BIG_CAT_CLASS:
		mBaseExp = 100;
		mBaseTP = 15;
		mBaseHP = 15;
		mBaseMP = 10;
		mBasePower = 15;
		mBaseFirepower = 10;
		mBaseDefense = 15;
		mBaseAccuracy = 35;
		mBaseEvasion = 15;
		mBaseMagic = 5;
		mBaseCharm = 10;
		break;
	}

}

void DPhoenix::CharacterClass::CalculateStats(int _level)
{

	mLevel = _level;
	//as defined in the spreadsheet and GDD
	switch (mClass)
	{
	case TOY_SOLDIER_CLASS:
		mExp = mBaseExp * (mLevel ^ 2);
		mTP = floor(mBaseTP + (pow(mLevel, 2) * 0.05));
		mHP = floor(mBaseHP * (pow(mLevel, 1.9)));
		mMaxHP = mHP;
		mMP = floor(mBaseMP + (pow(mLevel, 2) * 0.5));
		mMaxMP = mMP;
		mPower = min(floor(log2(mLevel) * 55 + mBasePower), 255);
		mFirepower = floor(log2(mLevel) * 45 + mBaseFirepower);
		mDefense = floor(log2(mLevel) * 40 + mBaseDefense);
		mAccuracy = floor(log2(mLevel) * 15 + mBaseAccuracy);
		mEvasion = floor(mBaseEvasion + (pow(mLevel, 2) * 0.125));
		mMagic = floor(mBaseMagic + pow(mLevel, 2) * 0.25);
		mCharm = floor(mBaseCharm + pow(mLevel, 2) * 0.4);
		break;
	case DARK_ANGEL_CLASS:
		mExp = mBaseExp * (mLevel ^ 2);
		mTP = floor(mBaseTP + (pow(mLevel, 2) * 0.05));
		mHP = floor(mBaseHP * (pow(mLevel, 1.9)));
		mMaxHP = mHP;
		mMP = floor(log2(mLevel) * 60 + mBaseMP);
		mMaxMP = mMP;
		mPower = floor(mBasePower * (pow(mLevel, 1.1)));
		mFirepower = floor(mBaseFirepower * (pow(mLevel, 1.05)));
		mDefense = floor(mBaseDefense * (pow(mLevel, 0.8)));
		mAccuracy = floor(mBaseAccuracy * (pow(mLevel, 0.5)));
		mEvasion = floor(mBaseEvasion + (pow(mLevel, 2) * 0.125));
		mMagic = min(floor(log2(mLevel) * 50 + mBaseMagic), 255);
		mCharm = min(floor(log2(mLevel) * 40 + mBaseCharm), 255);
		break;
	case DRAGON_CLASS:
		mExp = mBaseExp * (mLevel ^ 2);
		mTP = floor(mBaseTP + (pow(mLevel, 2) * 0.0125));
		mHP = floor(mBaseHP * (pow(mLevel, 1.95)));
		mMaxHP = mHP;
		mMP = floor(log2(mLevel) * 40 + mBaseMP);
		mMaxMP = mMP;
		mPower = floor(mBasePower * (pow(mLevel, 0.7)));
		mFirepower = floor(mBaseFirepower * (pow(mLevel, 0.96)));
		mDefense = floor(mBaseDefense * (pow(mLevel, 0.5)));
		mAccuracy = floor(mBaseAccuracy * (pow(mLevel, 0.3)));
		mEvasion = floor(mBaseEvasion + (pow(mLevel, 2) * 0.025));
		mMagic = min(floor(log2(mLevel) * 35 + mBaseMagic), 255);
		mCharm = min(floor(log2(mLevel) * 40 + mBaseCharm), 255);
		break;
	case BIG_CAT_CLASS:
		mExp = mBaseExp * (mLevel ^ 2);
		mTP = floor(mBaseTP + (pow(mLevel, 2) * 0.05));
		mHP = floor(mBaseHP * (pow(mLevel, 1.8)));
		mMaxHP = mHP;
		mMP = floor(mBaseMP + (pow(mLevel, 2) * 0.3));
		mMaxMP = mMP;
		mPower = min(floor(log2(mLevel) * 35 + mBasePower), 255);
		mFirepower = floor(log2(mLevel) * 30 + mBaseFirepower);
		mDefense = floor(log2(mLevel) * 40 + mBaseDefense);
		mAccuracy = floor(log2(mLevel) * 15 + mBaseAccuracy);
		mEvasion = floor(log2(mLevel) * 15 + mBaseEvasion);
		mMagic = floor(mBaseMagic + pow(mLevel, 2) * 0.25);
		mCharm = floor(mBaseCharm + pow(mLevel, 2) * 0.4);
		break;
	}

}

int DPhoenix::CharacterClass::MeleeAttack(CharacterClass* _target)
{
	std::srand(time(0));

	int rng = rand() % 100 + 1;

	int dmg = mPower * (rng * 0.1) - (_target->mDefense / rng);

	return dmg;
}

int DPhoenix::CharacterClass::MagicAttack(CharacterClass* _target, int _modifier, int _coverDmg)
{
	std::srand(time(0));

	int rng = rand() % 100 + 1;
	int rng2 = rand() % 100 + 1;

	int hit = mAccuracy * (rng * 0.01) - _target->mEvasion * (rng * 0.005);

	if (hit < 0)
		return -1; //to indicate miss

	int magic = mMagic * _modifier;

	int dmg = magic * (rng * 0.05) - (_target->mCharm * 0.75 / (rng * 0.1));

	return dmg;
}

int DPhoenix::CharacterClass::WeaponAttack(CharacterClass*_target, int _modifier, int _coverDmg)
{
	std::srand(time(0));

	int rng = rand() % 100 + 1;
	int rng2 = rand() % 100 + 1;

	int hit = mAccuracy * (rng * 0.005) - _target->mEvasion * (rng * 0.01);

	if (hit < 0)
		return -1; //to indicate miss

	int firepower = mFirepower * _modifier;

	int dmg = firepower * (rng * 0.1) - (_target->mDefense * 0.65 / (rng * 0.1));

	return dmg;
}

void DPhoenix::CharacterClass::Update(float dt)
{
	//lots of logic to go here!
}

