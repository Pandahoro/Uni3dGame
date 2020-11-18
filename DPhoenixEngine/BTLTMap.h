#pragma once
#include "MapBlock.h"

namespace DPhoenix
{
	class BTLTMap
	{
	public:
		//using vectors so can be resized without globals
		std::vector<std::vector<MapBlock*>> mTiles;

		//width and length
		int mWidth;
		int mLength;

		//constructor, takes in maptada and ammount of tiles perpanel and panels as well as xmfloat3 originpoints for spawn locations
		BTLTMap(std::string filename, TextureMgr* mTexMgr, ID3D11Device* md3dDevice,
			std::vector<XMFLOAT3>& enemySpawnVec,
			std::vector<XMFLOAT3>& playerSpawnVec,
			std::vector<XMFLOAT3>& beaconSpawnVec,
			DPhoenix::GeometryGenerator::MeshData* _Box,
			std::vector<std::string>& _floorColorMaps, std::vector<std::string>& _floorNormalMaps, std::vector<std::string>& _wallColorMaps,
			std::vector<std::string>& _wallNormalMaps, std::vector<std::string>& _coverColorMaps, std::vector<std::string>& _coverNormalMaps,
			int tiesWidth, int tilesLength, float _tileSize);
		~BTLTMap() { };
	};
}