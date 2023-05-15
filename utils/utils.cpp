#include "utils.h"

void utilities::random_name()
{
	constexpr int length = 15;
	const auto characters = TEXT("abcdefghi9182345jklmnopqrstuv211935960473wxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
	TCHAR title[length + 1]{};

	for (int j = 0; j != length; j++)
	{
		title[j] += characters[rand() % 80];
	}

	SetConsoleTitle(title);
}