#pragma once
#include"D3DUtil.h"

namespace DPhoenix
{

	enum MapBlockTypes
	{
		FLOOR_MAPBLOCK,
		WALL_MAPBLOCK,
		COVER_MAPBLOCK,
		BEACON_MAPBLOCK,
		NULLSPACE_MAPBLOCK
	};

	class MapBlock
	{
	public:
		MapBlockTypes mMapBlockType;
		int mArrayXPos;
		int mArrayYpos;
		XMFLOAT3 mPosition;

		PrimitiveInstance* mMeshInstance;

		//methods
		MapBlock(MapBlockTypes _blockType, TextureMgr* _texMgr, ID3D11Device* _md3dDevice, DPhoenix::GeometryGenerator::MeshData* _Box,
			std::vector<std::string>& _floorColorMaps, std::vector<std::string>& _floorNormalMaps, std::vector<std::string>& _wallColorMaps,
			std::vector<std::string>& _wallNormalMaps, std::vector<std::string>& _coverColorMaps, std::vector<std::string>& _coverNormalMaps,
			int _arrayXPos, int _arrayYPos, float _tileSize);
		~MapBlock();
	};
}