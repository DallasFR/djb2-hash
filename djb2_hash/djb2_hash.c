#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

DWORD64 djb2(PBYTE str) {
	DWORD64 dwHash = 0x7734773477347734;
	INT c;

	while (c = *str++)
		dwHash = ((dwHash << 0x5) + dwHash) + c;

	return dwHash;
}

int main(int argc, char* argv[])
{
	DWORD64 FuncToHash;
	for (int i = 0; i < argc; i++)
	{
		printf("%s : ", argv[i]);
		FuncToHash = djb2((PBYTE)argv[i]);
		printf("0x%llx\n", FuncToHash);
	}

}