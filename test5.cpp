#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <thread>

void test5(int _)
{
	printf("TEST CASE: 每次调用 fwrite fflush；并死循环写 \n");
	FILE* f = fopen("test.txt", "wb");
	if (!f)
	{
		printf("can not open file\n");
		exit(1);
	}
	for (int i = 0; true; i++)
	{
		char msg[1024];
		auto len = snprintf(msg, sizeof(msg), "Hello logger: msg number %d\n", i);
		fwrite(msg, len, 1, f);
		fflush(f);
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}
