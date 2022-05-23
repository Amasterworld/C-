#define OLC_PGE_APPLICATION




#include <PathFinding_BFS.h>




// Override base class with your custom functionality


int main()
{

	//INPUT ip;
	//std::thread t(f, ip);


	PathFinding_BFS demo;

	if (demo.Construct(512 + demo.nExpand, 480 + demo.nExpand / 2, 2, 2))
	{
		demo.Start();
	}

	//t.join();





	return 0;
}
