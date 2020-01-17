#include <chrono>
#include <cstdio>
#include <cstdlib>

void test6(int buffsize)
{
	printf("TEST CASE: 只调用 fwrite ；并设置 setbuf ，大小为 %d ；并死循环写 \n", buffsize);
	FILE* f = fopen("test.txt", "wb");
	if (!f)
	{
		printf("can not open file\n");
		exit(1);
	}
	char* buff = new char[buffsize];
	setvbuf(f, buff, _IOFBF, buffsize);
	for (int i = 0; true; i++)
	{
		char msg[1024];
		auto len = snprintf(msg, sizeof(msg), "Hello logger: msg number %d\n", i);
		fwrite(msg, len, 1, f);
	}
	delete buff;
}
