#include "MapBlock.h"

DPhoenix::MapBlock::MapBlock(MapBlockTypes _blockType, TextureMgr* _texMgr,
	ID3D11Device* _md3dDevice, DPhoenix::GeometryGenerator::MeshData* _Box,
	std::vector<std::string>& _floorColorMaps, std::vector<std::string>& _floorNormalMaps, std::vector<std::string>& _wallColorMaps,
	std::vector<std::string>& _wallNormalMaps, std::vector<std::string>& _coverColorMaps, std::vector<std::string>& _coverNormalMaps,
	int _arrayXPos, int _arrayYPos, float _tileSize)

{
	mMapBlockType = _blockType;
	mArrayXPos = _arrayXPos;
	mArrayXPos = _arrayXPos;

	mPosition.x = mArrayXPos * _tileSize;
	mPosition.z = mArrayXPos * _tileSize;

	//differnt mat types for effects

	Material* materialStandard = new Material();
	Material* materialShiny = new Material();

	materialStandard->Ambient = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	materialStandard->Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	materialStandard->Specular = XMFLOAT4(1.0f, 1.0f, 1.0f, 32.0f);
	materialStandard->Reflect = XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f);

	materialShiny->Ambient = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	materialShiny->Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	materialShiny->Specular = XMFLOAT4(0.8f, 0.8f, 0.8f, 16.0f);
	materialShiny->Reflect = XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);

	int index = 0;

	switch (mMapBlockType)
	{
	case DPhoenix::FLOOR_MAPBLOCK:

		index = rand() % (_floorColorMaps.size() - 1);

		mMeshInstance = new PrimitiveInstance();
		mMeshInstance->LoadLitTexInstance(_md3dDevice, _floorColorMaps[index], _Box, _texMgr);
		mMeshInstance->mMaterial = materialStandard;
		mMeshInstance->mNormalMap = _texMgr->CreateTexture(_floorNormalMaps[index]);

		mPosition.y = 0.0f;

		mMeshInstance->mPosition = mPosition;

		//entity settigns for collision


		break;
	case DPhoenix::WALL_MAPBLOCK:

		index = rand() % (_wallColorMaps.size() - 1);

		mMeshInstance = new PrimitiveInstance();
		mMeshInstance->LoadLitTexInstance(_md3dDevice, _wallColorMaps[index], _Box, _texMgr);
		mMeshInstance->mMaterial = materialShiny;
		mMeshInstance->mNormalMap = _texMgr->CreateTexture(_wallNormalMaps[index]);

		mPosition.y = _tileSize;

		mMeshInstance->mPosition = mPosition;

		//entity settigns for collision


		break;
	case DPhoenix::COVER_MAPBLOCK:

		index = rand() % (_coverColorMaps.size() - 1);

		mMeshInstance = new PrimitiveInstance();
		mMeshInstance->LoadLitTexInstance(_md3dDevice, _coverColorMaps[index], _Box, _texMgr);
		mMeshInstance->mMaterial = materialShiny;
		mMeshInstance->mNormalMap = _texMgr->CreateTexture(_coverNormalMaps[index]);

		mPosition.y = _tileSize / 2;

		mMeshInstance->mPosition = mPosition;

		//entity settigns for collision

		break;
	case DPhoenix::BEACON_MAPBLOCK:

		index = rand() % (_floorColorMaps.size() - 1);

		mMeshInstance = new PrimitiveInstance();
		mMeshInstance->LoadLitTexInstance(_md3dDevice, _floorColorMaps[index], _Box, _texMgr);
		mMeshInstance->mMaterial = materialStandard;
		mMeshInstance->mNormalMap = _texMgr->CreateTexture(_floorNormalMaps[index]);

		mPosition.y = 0.0f;

		mMeshInstance->mPosition = mPosition;

		//entity settigns for collision

		break;
	case DPhoenix::NULLSPACE_MAPBLOCK:

		mMeshInstance = NULL;

		break;
	default:
		break;
	}
}