#include "PathFinding_BFS.h"


// define the  constructor

PathFinding_BFS::PathFinding_BFS()
{
	sAppName = "PathFinding - Breath First Search";
}

void PathFinding_BFS::DrawMap(const auto& p)
{
	// Draw Map
	Clear(olc::BLACK);
	DrawString(540, 200 - nDistBetLines * 4, "CYAN is the border", olc::CYAN, 1);
	DrawString(540, 200 - nDistBetLines * 3, "Right click on the cell to create an obstacle", olc::GREY, 1);
	DrawString(540, 200 - nDistBetLines * 2, "Press Ctl + Right click to move START point", olc::GREEN, 1);
	DrawString(540, 200 - nDistBetLines * 1, "Press Shift + Right click to move END point", olc::RED, 1);
	DrawString(540, 200 + nDistBetLines * 0, "Breath First Search: ", olc::WHITE, 1);
	DrawString(540, 200 + nDistBetLines * 1, "CAN GUARRANTE to get the shortest path", olc::WHITE, 1);
	DrawString(540, 200 + nDistBetLines * 2, "But TC: O(V+E) with afjacency matrix", olc::WHITE, 1);
	DrawString(540, 200 + nDistBetLines * 3, "SC: O(V), need space more than DFS ", olc::WHITE, 1);

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


			// draw the grid corresponds on the colour variable

			FillRect(x * nCellSize, y * nCellSize, nCellSize - nBorderWidth, nCellSize - nBorderWidth, colour);

			if (bVisited_algo[y * nMapWidth + x])
			{

				FillCircle(x * nCellSize + ((nCellSize - nBorderWidth) / 2), y * nCellSize + ((nCellSize - nBorderWidth) / 2), 10, olc::BLACK);

			}
		}
	}
}

void PathFinding_BFS::SetUp(bool Start, std::string sIni, std::string sLoadingDefaultMaze_1, std::string sLoadingDefaultMaze_2, auto p)
{
	// when StartButton (YES OR NOT button is NOT pressed)
	if (!bStartButton)
	{
		sIni = "Welcome to the DPS";
		sLoadingDefaultMaze_1 = "   Do you want to load ";
		sLoadingDefaultMaze_2 = "     default maze?";
		DrawString(600, 200 + nDistBetLines * 8, sIni, olc::GREEN, 2);
		DrawString(520, 200 + nDistBetLines * 10, sLoadingDefaultMaze_1, olc::GREEN, 2);
		DrawString(520, 200 + nDistBetLines * 12, sLoadingDefaultMaze_2, olc::GREEN, 2);
		DrawString(600, 200 + nDistBetLines * 14, "YES", olc::DARK_YELLOW, 2);
		DrawString(800, 200 + nDistBetLines * 14, sNo, olc::RED, 2);

		
		//click to YES buttom
		if (600 <= (GetMouseX()) && (GetMouseX()) <= 640 && 200 + nDistBetLines * 14 <= (GetMouseY()) && (GetMouseY()) <= 200 + nDistBetLines * 14 + 15 && GetMouse(0).bReleased && !bStartButton)
		{
			DrawString(600, 200 + nDistBetLines * 14, "YES", olc::GREEN, 2);
			// reset all obstacles
			memset(bObstacleMap, false, nMapWidth * nMapHeight * sizeof(bool));
			memset(bVisited_algo, false, nMapWidth * nMapHeight * sizeof(int));
			path.emplace(nStartX, nStartY);
			bVisited_algo[nStartY * nMapWidth + nStartX] = true;
			//put default obstacles, it is better to get the maze from txt file.
			bObstacleMap[p(9, 7)] = true; bObstacleMap[p(9, 8)] = true;  bObstacleMap[p(9, 6)] = true; bObstacleMap[p(9, 5)] = true;
			bObstacleMap[p(10, 7)] = true; bObstacleMap[p(9, 11)] = true;  bObstacleMap[p(11, 6)] = true; bObstacleMap[p(10, 5)] = true;


			for (int i = 0; i < nMapWidth * nMapHeight; ++i)
			{
				if (bObstacleMap[i])
					nNumObstacles++;
			}
			bStartButton = true;
		}
		// NO button
		else if (800 <= (GetMouseX()) && (GetMouseX()) <= 840 && 200 + nDistBetLines * 14 <= (GetMouseY()) && (GetMouseY()) <= 200 + nDistBetLines * 14 + 15)
		{
			bFalgNoButton = true;
			DrawString(570, 200 + nDistBetLines * 16, "YOU CAN CREATE YOUROWN MAZE ", olc::MAGENTA, 1);
			DrawString(600, 200 + nDistBetLines * 17, "BY LEFT CLICK IN THE GRID", olc::MAGENTA, 1);
			// change NO to OK
			sNo = "OK";

			if (GetMouse(0).bReleased && !bStartButton)
			{
				memset(bVisited_algo, false, nMapWidth * nMapHeight * sizeof(int));
				path.emplace(nStartX, nStartY);
				bVisited_algo[nStartY * nMapWidth + nStartX] = true;
				for (int i = 0; i < nMapWidth * nMapHeight; ++i)
				{
					if (bObstacleMap[i])
						nNumObstacles++;
				}
				bStartButton = true;
			}

		}
		// if the user move mouse to the  grid, then appears this message 
		if (GetMouseX() < 512 && bFalgNoButton == true)
		{
			DrawString(800, 200 + nDistBetLines * 14, sNo, olc::RED, 2);
			DrawString(570, 200 + nDistBetLines * 16, "WHEN YOU FINISH, CLICK OK TO START ", olc::MAGENTA, 1);
		}

	}
}

void PathFinding_BFS::DrawBorder(const auto p)
{
	for (int x = 0; x < nMapWidth; x++)
	{
		for (int y = 0; y < nMapHeight; y++)
		{
			// Set border and obstacles
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

}

void PathFinding_BFS::BFS(bool& bReach, bool& bStartButton, auto p)
{
	int count = 0; 
	// The HEART of the Algorithm
	if (!bReach && bStartButton)
	{
		//while (count < path.size())
		//{
			//std::list<std::tuple<int, int, int>> listNeighbours;
			std::pair <int, int> temp_q;
			// to avoid problem when the path to END point is not found, then path is empty, --> path.top() --> error.
			if (path.empty() == false)
				temp_q = path.front();



			int nCurrX = temp_q.first;
			int nCurrY = temp_q.second;

			//std::cout << nCurrX << "  " << nCurrY << std::endl;
			//std::cout << "nCurrX " << nCurrX << " nCurrY " << nCurrY << std::endl;

			if (nCurrX == nEndX && nCurrY == nEndY)
			{
				//std::cout << "nCurrX  " << nCurrX<<"nCurrY "<< nCurrY << std::endl;
				bReach = true;
				//lReachPath.emplace_back(nCurrX, nCurrY);

			}

			// 4-Way Connectivity
			//std::cout << nFlowFieldZ[p(nCurrX, nCurrY - 1)] <<"  "<< nCurrY <<std::endl; //  3 - 7 forever need to check

			if ((nCurrY - 1) >= 0 && nFlowFieldZ[p(nCurrX, nCurrY - 1)] != -1 && bVisited_algo[p(nCurrX, nCurrY - 1)] == false)
			{

				path.emplace(std::make_pair(nCurrX, nCurrY - 1));
				bVisited_algo[p(nCurrX, nCurrY - 1)] = true;
				FillCircle((nCurrX)*nCellSize + ((nCellSize - nBorderWidth) / 2), (nCurrY - 1) * nCellSize + ((nCellSize - nBorderWidth) / 2), 10, olc::YELLOW);
				lXpath[nCurrX][nCurrY - 1] = temp_q.first;
				lYpath[nCurrX][nCurrY - 1] = temp_q.second;
			}

			if (nCurrY + 1 < nMapHeight && nFlowFieldZ[p(nCurrX, nCurrY + 1)] != -1 && bVisited_algo[p(nCurrX, nCurrY + 1)] == false)
			{


				path.emplace(std::make_pair(nCurrX, nCurrY + 1));
				bVisited_algo[p(nCurrX, nCurrY + 1)] = true;
				FillCircle((nCurrX) * nCellSize + ((nCellSize - nBorderWidth) / 2), (nCurrY + 1) * nCellSize + ((nCellSize - nBorderWidth) / 2), 10, olc::YELLOW);
				lXpath[nCurrX][nCurrY + 1] = temp_q.first;
				lYpath[nCurrX][nCurrY + 1] = temp_q.second;
			}

			if (nCurrX - 1 >= 0 && nFlowFieldZ[p(nCurrX - 1, nCurrY)] != -1 && bVisited_algo[p(nCurrX - 1, nCurrY)] == false)
			{

				path.emplace(std::make_pair(nCurrX - 1, nCurrY));
				bVisited_algo[p(nCurrX - 1, nCurrY)] = true;
				FillCircle((nCurrX - 1) * nCellSize + ((nCellSize - nBorderWidth) / 2), nCurrY * nCellSize + ((nCellSize - nBorderWidth) / 2), 10, olc::YELLOW);
				lXpath[nCurrX - 1][nCurrY] = temp_q.first;
				lYpath[nCurrX - 1][nCurrY] = temp_q.second;
			}


			if (nCurrX + 1 < nMapWidth && nFlowFieldZ[p(nCurrX + 1, nCurrY)] != -1 && bVisited_algo[p(nCurrX + 1, nCurrY)] == false)
			{

				path.emplace(std::make_pair(nCurrX + 1, nCurrY));
				bVisited_algo[p(nCurrX + 1, nCurrY)] = true;

				FillCircle((nCurrX + 1) * nCellSize + ((nCellSize - nBorderWidth) / 2), nCurrY * nCellSize + ((nCellSize - nBorderWidth) / 2), 10, olc::YELLOW);
				lXpath[nCurrX + 1][nCurrY] = temp_q.first;
				lYpath[nCurrX + 1][nCurrY] = temp_q.second;
			}




			// to avoid the problem the when the END point cannot be reach, then bReach == false, then path is empty and path.pop() make the program crash
			if (path.empty() == false)
				path.pop();




			//if (path.empty() == false)
		//	{
			//	for (int x = 0; x < nMapWidth; x++)
			//		for (int y = 0; y < nMapHeight; y++)
					{

						//std::cout << nNumObstacles << std::endl;
						//FillCircle(path.front().first * nCellSize + ((nCellSize - nBorderWidth) / 2), path.front().second * nCellSize + ((nCellSize - nBorderWidth) / 2), 10, olc::YELLOW);
				//	}
			}
		//	count++;
		//}
	}
}

void PathFinding_BFS::DrawPathAndlength(bool bReach, std::string sIni)
{
	if (bReach)
	{
		sIni = " ";

		DrawString(600, 200 + nDistBetLines * 8, "PATH IS FOUND", olc::GREEN, 2);

		std::priority_queue< int > pqTrajec; // max heap
		std::vector<std::pair <int, int>> vPath;

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




		int ox, oy;

		bool bFirstPoint = true;

		// reverse the traject to create the path from Start to End point.

		for (auto p : vPath)
		{

			if (bFirstPoint && !pqTrajec.empty())
			{

				ox = p.first; oy = p.second;
				nDistStart2EndPoint = pqTrajec.top();
				nMaxDistStart2EndPoint = pqTrajec.top();
				bFirstPoint = false;

			}
			//else
			if (!bFirstPoint && !pqTrajec.empty())
			{

				DrawString(ox * nCellSize, oy * nCellSize, std::to_string(nDistStart2EndPoint), olc::WHITE);
				FillCircle(ox * nCellSize + ((nCellSize - nBorderWidth) / 2), oy * nCellSize + ((nCellSize - nBorderWidth) / 2), 10, olc::YELLOW);
				ox = p.first; oy = p.second;
				nDistStart2EndPoint = pqTrajec.top();
				//std::cout << nDistStart2EndPoint<< std::endl;
				pqTrajec.pop();
			}


		}

		if (bReach && pqTrajec.empty())
		{
			//	std::cout << "nMaxDistStart2EndPoint" << std::endl;
			DrawString(520, 200 + nDistBetLines * 10, "The shortest path length is", olc::YELLOW, 2);
			DrawString(670, 200 + nDistBetLines * 12, std::to_string(nMaxDistStart2EndPoint), olc::YELLOW, 2);
			Reset();
			//std::cout << pqTrajec.size() << std::endl;
		}

	}

	// Path is not FOUND
	if (!bReach && path.empty() && bStartButton)
	{
		
		//std::cout << "Path empty" << std::endl;
		DrawString(600, 200 + nDistBetLines * 8, "PATH IS NOT FOUND", olc::RED, 2);
		DrawString(640, 200 + nDistBetLines * 10, "No path is created", olc::DARK_YELLOW, 1);
		Reset();

	}
}

void PathFinding_BFS::Reset()
{

	DrawString(670, 200 + nDistBetLines * 14, "RESET", olc::DARK_YELLOW, 3);
	if (670 <= (GetMouseX()) && (GetMouseX()) <= 790 && 200 + nDistBetLines * 14 <= (GetMouseY()) && (GetMouseY()) <= 200 + nDistBetLines * 14 + 20 && GetMouse(0).bReleased)
	{

		// reset path from Start to End point
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
		// reset bVisited_algo
		//bVisited_algo = new int[nMapWidth * nMapHeight];
		memset(bVisited_algo, false, nMapWidth * nMapHeight * sizeof(int));
		//bObstacleMap = new bool[nMapWidth * nMapHeight]{ false };
		//memset(bObstacleMap, false, nMapWidth * nMapHeight * sizeof(bool));

		while (!path.empty())
			path.pop();

		//path.emplace(nStartX, nStartY);
		//bVisited_algo[nStartY * nMapWidth + nStartX] = 1;


		bReach = false;
		bStartButton = false;
		bFalgNoButton = false;

	}
}

void PathFinding_BFS::InputMouse(const auto p)
{
	int nSelectedCellX = GetMouseX() / nCellSize;
	int nSelectedCellY = GetMouseY() / nCellSize;
	// the whole monitor is 512+nExpand, the nExpand contains the simple GUI, we do not want to create obstacles when click overthere
	if (GetMouseX() < 512)
	{
		if (GetMouse(0).bReleased)
		{
			// Toggle Obstacle if mouse left clicked
			bObstacleMap[p(nSelectedCellX, nSelectedCellY)] =
				!bObstacleMap[p(nSelectedCellX, nSelectedCellY)];
		}
	}
	// Replace Start button with right click `SHIFT
	if (GetMouse(1).bReleased && GetKey(olc::Key::SHIFT).bHeld && (nStartX != nSelectedCellX || nStartY != nSelectedCellY))
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

}