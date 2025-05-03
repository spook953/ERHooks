#include "app/app.hpp"

int main()
{
	if (!App::Run()) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}