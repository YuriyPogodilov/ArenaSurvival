#include "core/game.h"

int main() {
	Game game(1280, 720);

	game.Initialize();

	game.Start();

	return 0;
}
