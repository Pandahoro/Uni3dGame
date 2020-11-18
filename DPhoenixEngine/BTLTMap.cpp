#include "BTLTMap.h"

DPhoenix::BTLTMap::BTLTMap(std::string filename, TextureMgr* mTexMgr, ID3D11Device* md3dDevice,
	std::vector<XMFLOAT3>& enemySpawnVec,
	std::vector<XMFLOAT3>& playerSpawnVec,
	std::vector<XMFLOAT3>& beaconSpawnVec,
	DPhoenix::GeometryGenerator::MeshData* _Box,
	std::vector<std::string>& _floorColorMaps, std::vector<std::string>& _floorNormalMaps,
	std::vector<std::string>& _wallColorMaps, std::vector<std::string>& _wallNormalMaps,
	std::vector<std::string>& _coverColorMaps, std::vector<std::string>& _coverNormalMaps,
	int tilesWidth, int tilesLength,
	float tileSize)
{
	// get map from CSV file and populate 2d vector
	std::ifstream inMapFile(filename);

	// parsing helpers for CSV file
	std::string value;
	std::string ignore;
	//calculate width and height
	mWidth = tilesWidth;
	mLength = tilesLength;
	//size of tiles (assume square)

	//values in constructing map
	int row = mLength - 1; //count backwords as it stacks
	int col = 0;
	int count = 0;

	//set vectors values based on tile sizes
	mTiles.resize(mWidth);
	for (int i = 0; i < mTiles.size(); i++)
	{
		mTiles.resize(mLength);

	}
	XMFLOAT3 objectPos; // used for spawn points

	//size to 4 each
	playerSpawnVec.resize(4);
	enemySpawnVec.resize(4);
	beaconSpawnVec.resize(4);

	//map parsing, start top row and go by colomn

	//seed
	srand(time(0));

	//read in map file and continue while open
	while (inMapFile.good())
	{
		//getline until next comma - sore in vaue
		std::getline(inMapFile, value, '\n');

		//if we have a actual line
		if (value.length() > 1)
		{
			//lloop through the chars in the value given
			for (int i = 0; i < value.length(); i++)
			{
				//check betwwen two points of ascii table
				int indexStart = (int)'0';
				int indexEnd = (int)'z';
				//if char is within range
				if ((int)value[i])
				{
					//check what the value is for tile
					switch (value[i])
					{
					case '0':
						mTiles[col][row] = new MapBlock(DPhoenix::NULLSPACE_MAPBLOCK,
							mTexMgr, md3dDevice, _Box,
							_floorColorMaps, _floorNormalMaps,
							_wallColorMaps, _wallNormalMaps,
							_coverColorMaps, _wallNormalMaps,
							col, row, tileSize);
						break;
					case 'f':
						mTiles[col][row] = new MapBlock(DPhoenix::FLOOR_MAPBLOCK,
							mTexMgr, md3dDevice, _Box,
							_floorColorMaps, _floorNormalMaps,
							_wallColorMaps, _wallNormalMaps,
							_coverColorMaps, _wallNormalMaps,
							col, row, tileSize);
						break;
					case 'c':
						mTiles[col][row] = new MapBlock(DPhoenix::COVER_MAPBLOCK,
							mTexMgr, md3dDevice, _Box,
							_floorColorMaps, _floorNormalMaps,
							_wallColorMaps, _wallNormalMaps,
							_coverColorMaps, _wallNormalMaps,
							col, row, tileSize);
						break;
					case 'b':
						mTiles[col][row] = new MapBlock(DPhoenix::WALL_MAPBLOCK,
							mTexMgr, md3dDevice, _Box,
							_floorColorMaps, _floorNormalMaps,
							_wallColorMaps, _wallNormalMaps,
							_coverColorMaps, _wallNormalMaps,
							col, row, tileSize);

						beaconSpawnVec.push_back(XMFLOAT3(col * tileSize, tileSize / 2 + 5.0f, row * tileSize));
						break;
					case 'l':
						mTiles[col][row] = new MapBlock(DPhoenix::BEACON_MAPBLOCK,
							mTexMgr, md3dDevice, _Box,
							_floorColorMaps, _floorNormalMaps,
							_wallColorMaps, _wallNormalMaps,
							_coverColorMaps, _wallNormalMaps,
							col, row, tileSize);
						break;
					case '1':
						mTiles[col][row] = new MapBlock(DPhoenix::FLOOR_MAPBLOCK,
							mTexMgr, md3dDevice, _Box,
							_floorColorMaps, _floorNormalMaps,
							_wallColorMaps, _wallNormalMaps,
							_coverColorMaps, _wallNormalMaps,
							col, row, tileSize);

						playerSpawnVec[0] = XMFLOAT3(col * tileSize, tileSize / 2, row * tileSize);
						break;
					case '2':
						mTiles[col][row] = new MapBlock(DPhoenix::FLOOR_MAPBLOCK,
							mTexMgr, md3dDevice, _Box,
							_floorColorMaps, _floorNormalMaps,
							_wallColorMaps, _wallNormalMaps,
							_coverColorMaps, _wallNormalMaps,
							col, row, tileSize);

						playerSpawnVec[1] = XMFLOAT3(col * tileSize, tileSize / 2, row * tileSize);

						break;
					case '3':
						mTiles[col][row] = new MapBlock(DPhoenix::NULLSPACE_MAPBLOCK,
							mTexMgr, md3dDevice, _Box,
							_floorColorMaps, _floorNormalMaps,
							_wallColorMaps, _wallNormalMaps,
							_coverColorMaps, _wallNormalMaps,
							col, row, tileSize);

						playerSpawnVec[2] = XMFLOAT3(col * tileSize, tileSize / 2, row * tileSize);

						break;
					case '4':
						mTiles[col][row] = new MapBlock(DPhoenix::NULLSPACE_MAPBLOCK,
							mTexMgr, md3dDevice, _Box,
							_floorColorMaps, _floorNormalMaps,
							_wallColorMaps, _wallNormalMaps,
							_coverColorMaps, _wallNormalMaps,
							col, row, tileSize);

						playerSpawnVec[3] = XMFLOAT3(col * tileSize, tileSize / 2, row * tileSize);

						break;
					case '9':
						mTiles[col][row] = new MapBlock(DPhoenix::NULLSPACE_MAPBLOCK,
							mTexMgr, md3dDevice, _Box,
							_floorColorMaps, _floorNormalMaps,
							_wallColorMaps, _wallNormalMaps,
							_coverColorMaps, _wallNormalMaps,
							col, row, tileSize);
						enemySpawnVec[0] = XMFLOAT3(col * tileSize, tileSize / 2, row * tileSize);
						break;
					case '8':
						mTiles[col][row] = new MapBlock(DPhoenix::NULLSPACE_MAPBLOCK,
							mTexMgr, md3dDevice, _Box,
							_floorColorMaps, _floorNormalMaps,
							_wallColorMaps, _wallNormalMaps,
							_coverColorMaps, _wallNormalMaps,
							col, row, tileSize);

						enemySpawnVec[1] = XMFLOAT3(col * tileSize, tileSize / 2, row * tileSize);

						break;
					case '7':
						mTiles[col][row] = new MapBlock(DPhoenix::NULLSPACE_MAPBLOCK,
							mTexMgr, md3dDevice, _Box,
							_floorColorMaps, _floorNormalMaps,
							_wallColorMaps, _wallNormalMaps,
							_coverColorMaps, _wallNormalMaps,
							col, row, tileSize);

						enemySpawnVec[2] = XMFLOAT3(col * tileSize, tileSize / 2, row * tileSize);

						break;
					case '6':
						mTiles[col][row] = new MapBlock(DPhoenix::NULLSPACE_MAPBLOCK,
							mTexMgr, md3dDevice, _Box,
							_floorColorMaps, _floorNormalMaps,
							_wallColorMaps, _wallNormalMaps,
							_coverColorMaps, _wallNormalMaps,
							col, row, tileSize);

						enemySpawnVec[3] = XMFLOAT3(col * tileSize, tileSize / 2, row * tileSize);

						break;
					}
					col++;
				}
				row--; col;
			}
		}
	}
}