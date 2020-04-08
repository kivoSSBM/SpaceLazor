#include "GameHandler.h"
using namespace std;
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(static_cast<unsigned int>(time(0)));
	GameHandler Game;

	Game.update();


	return 0;
}