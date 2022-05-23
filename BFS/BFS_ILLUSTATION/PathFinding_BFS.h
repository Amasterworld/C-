#pragma once
#include "olcPixelGameEngine.h"
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <windows.h>
class PathFinding_BFS : public olc::PixelGameEngine
{

public:
	//declare constructor

	PathFinding_BFS();
	int nExpand = 400;
	
private:
	
	int nMapWidth = 0;
	int nMapHeight = 0;
	int nCellSize;
	int nBorderWidth;

	bool* bObstacleMap;

	int* nFlowFieldZ;
	float* fFlowFieldY;
	float* fFlowFieldX;

	int nStartX = 3;
	int nStartY = 7;
	int nEndX;
	int nEndY;

	bool bReach = false;
	int nDistBetLines = 22; // distance between lines
	std::queue <std::pair<int, int> > path; // for BFS we should use queue instead of stack
	
	int* bVisited_algo; // to point the visited nodes

	// to store the shortest path to the End point
	std::vector<std::vector<int>> lXpath;
	std::vector<std::vector<int>> lYpath;
	
	bool bFalgNoButton;
	bool bStartButton;
	std::string sNo;
	int nDistStart2EndPoint = 0;
	int nMaxDistStart2EndPoint = 0;
	int nDiscoverCell;  // the number of cells that are discovered
	int nNumObstacles; // the number of obstacles placed in the map (does not use now)

	int nFrame = 0;
public:
	
	bool OnUserCreate() override
	{
		nBorderWidth = 4;
		nCellSize = 32;
		nMapWidth = (ScreenWidth() - nExpand) / nCellSize;
		nMapHeight = ScreenHeight() / nCellSize;
		bObstacleMap = new bool[nMapWidth * nMapHeight]{ false };

		bVisited_algo = new int[nMapWidth * nMapHeight];
		memset(bVisited_algo, false, nMapWidth * nMapHeight * sizeof(int));
		nFlowFieldZ = new int[nMapWidth * nMapHeight]{ 0 };
		//fFlowFieldX = new float[nMapWidth * nMapHeight]{ 0 };
		//fFlowFieldY = new float[nMapWidth * nMapHeight]{ 0 };


		nStartX = 3;
		nStartY = 7;
		nEndX = 12;
		nEndY = 12;

		nDiscoverCell = 1; //the Start cell is discovered

		//bVisited_algo[nStartY * nMapWidth + nStartX] = true;

		// make lXpath is 0 with nMapWidth x nMapHeight dimension
		for (int x = 0; x < nMapWidth; x++)
		{
			lXpath.emplace_back(std::vector<int>());
			for (int y = 0; y < nMapHeight; y++)
				lXpath[x].emplace_back(0);
		}

		for (int x = 0; x < nMapWidth; x++)
		{
			lYpath.emplace_back(std::vector<int>());
			for (int y = 0; y < nMapHeight; y++)
				lYpath[x].emplace_back(0);
		}

		bStartButton = false;
		bFalgNoButton = false;
		//after changiing to OK, reset it to NO
		sNo = "NO";
		//nDistStart2EndPoint = 0;
		return true;
	}
	void DrawMap(const auto& p); // C++20 can be used as  void draw(const auto& p )
	void SetUp(bool Start, std::string sIni, std::string sLoadingDefaultMaze_1, std::string sLoadingDefaultMaze_2, auto p);
	void DrawBorder(const auto p);
	void BFS(bool& bReach, bool& bStartButton, auto p);

	void DrawPathAndlength(bool bReach, std::string sIni);

	void Reset();
	void InputMouse(const auto p);

	bool OnUserUpdate(float fElapsedTime) override
	{

		if (bStartButton )
		{
			nFrame = 200;
			std::this_thread::sleep_for(std::chrono::milliseconds(nFrame));
		}
		//std::this_thread::sleep_for(std::chrono::milliseconds(10));



	// Little convenience lambda 2D -> 1D
		auto a2DTo1D = [&](int x, int y) { return y * nMapWidth + x; };

		// User Input

		InputMouse(a2DTo1D);
		//draw map
		DrawMap(a2DTo1D);

		// SetUp
		std::string sIni;
		std::string sLoadingDefaultMaze_1;
		std::string sLoadingDefaultMaze_2;
		SetUp(!bStartButton, sIni, sLoadingDefaultMaze_1, sLoadingDefaultMaze_2, a2DTo1D);

		// create a border, // add grid and its boundary and add obstacles
		DrawBorder(a2DTo1D);

		// Search Algorithm: Depth First Search
		BFS(bReach, bStartButton, a2DTo1D);

		// if Path is found: Draw Path and Path Length otherwise informs that NO path is found
		DrawPathAndlength(bReach, sIni);
		


		return true;
	}

	
};

