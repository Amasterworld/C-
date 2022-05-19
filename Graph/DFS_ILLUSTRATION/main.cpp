

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




#include <PathFinding_DPS.h>




// Override base class with your custom functionality


int main()
{

	//INPUT ip;
	//std::thread t(f, ip);
	

	PathFinding_DPS demo;
	
	if (demo.Construct(512 + demo.nExpand, 480 + demo.nExpand / 2, 2, 2))
	{
		demo.Start();
	}

	//t.join();





	return 0;
}

