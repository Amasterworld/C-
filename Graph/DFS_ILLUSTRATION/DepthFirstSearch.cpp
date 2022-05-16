

/*
	OneLoneCoder.com - Path Finding #2 - Wave Propagation & Potential Fields
	"...never get lost again, so long as you know where you are" - @Javidx9
	Background
	~~~~~~~~~~
	A nice follow up alternative to the A* Algorithm. Wave propagation is less
	applicable to multiple objects with multiple destinations, but fantatsic
	for multiple objects all reaching the same destination.
	WARNING! This code is NOT OPTIMAL!! It is however very robust. There
	are many ways to optimise this further.
	License (OLC-3)
	~~~~~~~~~~~~~~~
	Copyright 2018 OneLoneCoder.com
	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions
	are met:
	1. Redistributions or derivations of source code must retain the above
	copyright notice, this list of conditions and the following disclaimer.
	2. Redistributions or derivative works in binary form must reproduce
	the above copyright notice. This list of conditions and the following
	disclaimer must be reproduced in the documentation and/or other
	materials provided with the distribution.
	3. Neither the name of the copyright holder nor the names of its
	contributors may be used to endorse or promote products derived
	from this software without specific prior written permission.
	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
	HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
	LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
	DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
	THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	Links
	~~~~~
	YouTube:	https://www.youtube.com/javidx9
	Discord:	https://discord.gg/WhwHUMV
	Twitter:	https://www.twitter.com/javidx9
	Twitch:		https://www.twitch.tv/javidx9
	GitHub:		https://www.github.com/onelonecoder
	Patreon:	https://www.patreon/javidx9
	Homepage:	https://www.onelonecoder.com
	Relevant Videos
	~~~~~~~~~~~~~~~
	Part #1 https://youtu.be/icZj67PTFhc
	Part #2 https://youtu.be/0ihciMKlcP8
	Author
	~~~~~~
	David Barr, aka javidx9, ©OneLoneCoder 2018
*/
#define OLC_PGE_APPLICATION

#include "olcPixelGameEngine.h"

#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>




// Override base class with your custom functionality
class PathFinding_DPS : public olc::PixelGameEngine
{
public:

	int nExpand = 400;
	//constructor
	PathFinding_DPS()
	{
		sAppName = "PathFinding -Depth First Search";
	}

private:
	
	int nMapWidth;
	int nMapHeight;
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
	
	//std::vector<std::vector<bool>> bVisited(nMapWidth, std::vector<bool>(nMapHeight, false));
	

	float fTimeCount = 0.0f;


	float fUpdateRate = 1.0f / 2.0f;
	float fTick = 1.0f;

	int nLocX = nStartX;
	int nLocY = nStartY;
	

	//int x = nStartX, y = nStartY;
	int nDistBetLines = 22; // distance between lines

public:



	void draw(const auto& p) // C++20 can be used as  void draw(const auto& p )
	{
		// Draw Map
		Clear(olc::BLACK);
		DrawString(540, 200 - nDistBetLines * 4, "CYAN is the border", olc::CYAN, 1);
		DrawString(540, 200 - nDistBetLines * 3, "Right click on the cell to create an obstacle", olc::GREY, 1);
		DrawString(540, 200 - nDistBetLines * 2, "Press Ctl + Right click to move START point", olc::GREEN, 1);
		DrawString(540, 200 - nDistBetLines, "Press Shift + Right click to move END point", olc::RED, 1);
		DrawString(540, 200, "Depth First Search", olc::WHITE, 1);
		DrawString(540, 200 + nDistBetLines, "Cannot GUARRANTE to get the shortest path", olc::WHITE, 1);
		DrawString(540, 200 + nDistBetLines * 2, "But TC: O(V*V) with afjacency matrix", olc::WHITE, 1);
		DrawString(540, 200 + nDistBetLines * 3, "SC: O(V) ", olc::WHITE, 1);

		for (int x = 0; x < nMapWidth; x++)
		{
			for (int y = 0; y < nMapHeight; y++)
			{
				
				olc::Pixel colour = olc::BLUE;

				if (bObstacleMap[p(x, y)])
					colour = olc::GREY;

				if (x == nStartX && y == nStartY)
				{
					colour = olc::GREEN;

				}
				if (x == nEndX && y == nEndY)
					colour = olc::RED;
				
				if (x == 0 || y == 0 || x == nMapWidth - 1 || y == nMapHeight - 1)
					colour = olc::CYAN;

				// Draw Base
				FillRect(x * nCellSize, y * nCellSize, nCellSize - nBorderWidth, nCellSize - nBorderWidth, colour);
			}
		}
	}

	
	bool OnUserCreate() override
	{
		nBorderWidth = 4;
		nCellSize = 32;
		nMapWidth = (ScreenWidth() - nExpand )/ nCellSize;
		nMapHeight = ScreenHeight() / nCellSize;
		bObstacleMap = new bool[nMapWidth * nMapHeight]{ false };
		nFlowFieldZ = new int[nMapWidth * nMapHeight]{ 0 };
		fFlowFieldX = new float[nMapWidth * nMapHeight]{ 0 };
		fFlowFieldY = new float[nMapWidth * nMapHeight]{ 0 };
		
		
		nStartX = 3;
		nStartY = 7;
		nEndX = 12;
		nEndY = 7;


		

		
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		
		
		std::vector<std::vector<bool>> bVisited(nMapWidth, std::vector<bool>(nMapHeight, false));
		std::vector<std::vector<bool>> bVisited_algo(nMapWidth, std::vector<bool>(nMapHeight, false));
		
		// Little convenience lambda 2D -> 1D
		auto p = [&](int x, int y) { return y * nMapWidth + x; };

		//std::cout << " Welcome " << std::endl;
		// User Input
		int nSelectedCellX = GetMouseX() / nCellSize;
		int nSelectedCellY = GetMouseY() / nCellSize;

		if (GetMouse(0).bReleased)
		{
			// Toggle Obstacle if mouse left clicked
			bObstacleMap[p(nSelectedCellX, nSelectedCellY)] =
				!bObstacleMap[p(nSelectedCellX, nSelectedCellY)];
		}
		// Replace Start button with right click `SHIFT
		if (GetMouse(1).bReleased && GetKey(olc::Key::SHIFT).bHeld && nStartX != nSelectedCellX && nStartY != nSelectedCellY)
		{
			nStartX = nSelectedCellX;
			nStartY = nSelectedCellY;
			//nFlowFieldZ[p(nEndX, nEndY)] = 0;
			
		}
		// Replace the location of End button with right click + Controla
		if (GetKey(olc::Key::CTRL).bHeld && GetMouse(1).bReleased && nEndX != nSelectedCellX && nEndY != nSelectedCellY)
		{

			nEndX = nSelectedCellX;
			nEndY = nSelectedCellY;
			//nFlowFieldZ[p(nEndX, nEndY)] = 0;
			
		}

		// add grid and its boundary and add obstacles
		
		for (int x = 0; x < nMapWidth; x++)
		{
			for (int y = 0; y < nMapHeight; y++)
			{
				// Set border or obstacles
				if (x == 0 || y == 0 || x == (nMapWidth - 1) || y == (nMapHeight - 1) || bObstacleMap[p(x, y)])
				{
					nFlowFieldZ[p(x, y)] = -1;
				}
				else
				{
					nFlowFieldZ[p(x, y)] = 0;
				}
			}
		}
			
		
		std::list<std::tuple<int, int, int>> nodes; // using list for fun, we can use struct np

		nodes.emplace_back(nEndX, nEndY, 1); // oh list uses tuples, so we can use emplace_back like vector
		bVisited[nEndX][nEndY] = true;
		while(!nodes.empty())
		{


			
			
			int nCurrentX = std::get<0>(nodes.front());
			int nCurrentY = std::get<1>(nodes.front());
			int depth     = std::get<2>(nodes.front());
			
			nodes.pop_front();


			nFlowFieldZ[p(nCurrentX, nCurrentY)] = 	depth;

			
			// Check East
			if ((nCurrentX + 1) < nMapWidth && nFlowFieldZ[p(nCurrentX + 1, nCurrentY)] == 0 && !bVisited[nCurrentX + 1][nCurrentY])
			{
				nodes.emplace_back(nCurrentX + 1, nCurrentY, depth + 1 );
				bVisited[nCurrentX + 1][nCurrentY] = true;
			}

			// Check West
			if ((nCurrentX - 1) >= 0 && nFlowFieldZ[p(nCurrentX - 1, nCurrentY)] == 0 && !bVisited[nCurrentX - 1][nCurrentY])
			{
				nodes.emplace_back(nCurrentX - 1, nCurrentY, depth + 1);
				bVisited[nCurrentX - 1][nCurrentY] = true;
			}

			// Check South
			if ((nCurrentY + 1) >= 0 && nFlowFieldZ[p(nCurrentX, nCurrentY +1)] == 0 && !bVisited[nCurrentX][nCurrentY +1])
			{
				nodes.emplace_back(nCurrentX, nCurrentY +1, depth + 1);
				bVisited[nCurrentX][nCurrentY +1] = true;
			}

			// Check North
			if ((nCurrentY - 1) >= 0 && nFlowFieldZ[p(nCurrentX, nCurrentY - 1)] == 0 && !bVisited[nCurrentX][nCurrentY - 1])
			{
				nodes.emplace_back(nCurrentX, nCurrentY - 1, depth + 1);
				bVisited[nCurrentX][nCurrentY - 1] = true;
			}
			
		}

			
		
		
		
		
		

		
		std::stack <std::pair<int, int> > path;

		std::list<std::pair<int, int>> lReachPath;
		path.emplace(nStartX, nStartY);
		lReachPath.emplace_back(nStartX, nStartY);
		bool bReach = false;
		//int nCurrX = nStartX;
		//int nCurrY = nStartY;
		
		// Depth First Search
		
	
		
		
		// cannot use int visited[m][n] as we had done, because m and n cannot be known in compile time --> list or vector


		std::vector<std::vector<int>> lXpath(nMapWidth, std::vector<int>(nMapHeight, 0));
		std::vector<std::vector<int>> lYpath(nMapWidth, std::vector<int>(nMapHeight, 0));
		

		
		while (!path.empty() && !bReach)
		{
			//std::list<std::tuple<int, int, int>> listNeighbours;
			// 4-Way Connectivity
			
			
			std::pair <int, int> temp_q = path.top();

			path.pop();

			int nCurrX = temp_q.first;
			int nCurrY = temp_q.second;

			//std::cout << nCurrX << "  " << nCurrY << std::endl;
			
			if (nCurrX == nEndX && nCurrY == nEndY)
			{
				//std::cout << "reach  " << std::endl;
				bReach = true;
				//lReachPath.emplace_back(nCurrX, nCurrY);
				break;
			}
			
			//std::cout << nFlowFieldZ[p(nCurrX, nCurrY - 1)] <<"  "<< nCurrY <<std::endl; //  3 - 7 forever need to check

			if ((nCurrY - 1) >= 0 && nFlowFieldZ[p(nCurrX, nCurrY - 1)] > 0 && !bVisited_algo[nCurrX][nCurrY - 1])
			{
				//std::cout << " draw 1" << std::endl;
				path.emplace(temp_q.first, nCurrY - 1);
				//lReachPath.emplace_back(nCurrX, nCurrY - 1);
			 	bVisited_algo[nCurrX][nCurrY - 1] = true;
				lXpath[nCurrX][nCurrY - 1] = temp_q.first;
				lYpath[nCurrX][nCurrY - 1] = temp_q.second;
			}

			if (nCurrY + 1 < nMapHeight && nFlowFieldZ[p(nCurrX, nCurrY + 1)] > 0 && !bVisited_algo[nCurrX][nCurrY + 1])
			{
				//std::cout << " draw 2" << std::endl;
				path.emplace(nCurrX, nCurrY + 1);
				//lReachPath.emplace_back(nCurrX, nCurrY + 1);
			    bVisited_algo[nCurrX][nCurrY + 1] = true;
				lXpath[nCurrX][nCurrY + 1] = temp_q.first;
				lYpath[nCurrX][nCurrY + 1] = temp_q.second;
			}
			
			if (nCurrX - 1 >= 0 && nFlowFieldZ[p(nCurrX - 1, nCurrY)] > 0 && !bVisited_algo[nCurrX - 1][nCurrY])
			{
				//std::cout << " draw 3" << std::endl;
				path.emplace(nCurrX - 1, nCurrY);
				//lReachPath.emplace_back(nCurrX - 1, nCurrY);
			    bVisited_algo[nCurrX- 1][nCurrY] = true;
				
				lXpath[nCurrX - 1][nCurrY] = temp_q.first;
				lYpath[nCurrX - 1][nCurrY] = temp_q.second;
			}

			 	
			if (nCurrX + 1 < nMapWidth && nFlowFieldZ[p(nCurrX + 1, nCurrY)] > 0 && !bVisited_algo[nCurrX + 1][nCurrY])
			{
			//	std::cout << " draw 4" << std::endl;
				path.emplace(nCurrX + 1, nCurrY);
				//lReachPath.emplace_back(nCurrX + 1, nCurrY);
			 	bVisited_algo[nCurrX+1][nCurrY] = true;
				
				lXpath[nCurrX + 1][nCurrY] = temp_q.first;
				lYpath[nCurrX + 1][nCurrY] = temp_q.second;
			}
						
			
				
		}
		
		draw(p);
		//auto cmp = [](std::tuple<int, int, int >& a, std::tuple<int, int, int >& b) {return std::get<2>(a) < std::get<2>(b); };
		std::priority_queue< int > pqTrajec;
		std::vector<std::pair <int, int>> vPath;
		if (bReach) {
			
			int nCurrX = nEndX; int nCurrY = nEndY;
			int nDist = 0;
			
			pqTrajec.emplace(nDist);
			vPath.emplace_back(nEndX, nEndY);
			while (nCurrX != nStartX || nCurrY != nStartY)
			{
				nDist++;
				//FillCircle(nEndX * nCellSize + ((nCellSize - nBorderWidth) / 2), nEndY * nCellSize + ((nCellSize - nBorderWidth) / 2), 10, olc::YELLOW);
				int nEndX_Update = nCurrX, nEndY_Update = nCurrY;
				pqTrajec.emplace(nDist);
				vPath.emplace_back(lXpath[nCurrX][nCurrY], lYpath[nCurrX][nCurrY]);
				nCurrX = lXpath[nEndX_Update][nEndY_Update]; nCurrY = lYpath[nEndX_Update][nEndY_Update];
			}
		}
		
		
		int ox, oy;
		int nDistStart2EndPoint = 0;
		bool bFirstPoint = true;
		
		// reverse the trajec  to create the path from Start to End point.
		
		for(auto p: vPath)
		{ 
			

			if (bFirstPoint && !pqTrajec.empty())
			{
				
				ox = p.first; oy = p.second;
				nDistStart2EndPoint = pqTrajec.top();
				//pqTrajec.pop();
				bFirstPoint = false;

			}
			//else
			if (!bFirstPoint && !pqTrajec.empty())
			{


				
				DrawString(ox* nCellSize, oy* nCellSize, std::to_string(nDistStart2EndPoint), olc::WHITE);
				FillCircle(ox * nCellSize + ((nCellSize - nBorderWidth) / 2), oy * nCellSize + ((nCellSize - nBorderWidth) / 2), 10, olc::YELLOW);
				ox = p.first; oy = p.second;
				nDistStart2EndPoint = pqTrajec.top();
				pqTrajec.pop();
			}


		}

		

	return true;
	}
	

};

int main()
{

	//INPUT ip;
	//std::thread t(f, ip);
	
	PathFinding_DPS demo;
	if (demo.Construct(512 + demo.nExpand, 480 + demo.nExpand/2, 2, 2))
	{

		demo.Start();



	}

	//t.join();





	return 0;
}

