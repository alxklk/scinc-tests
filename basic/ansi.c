#include <stdio.h>
#include <Windows.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 4
#endif

int main(int argc, char** argv)
{
	HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned long oldmode;
	GetConsoleMode(console, &oldmode);
	SetConsoleMode(console, oldmode|ENABLE_VIRTUAL_TERMINAL_PROCESSING);
//	printf("\x1b[6;30;42m ANSI ENABLE_VIRTUAL_TERMINAL_PROCESSING=%i Success! \x1b[0m", ENABLE_VIRTUAL_TERMINAL_PROCESSING);
	return 0;
}