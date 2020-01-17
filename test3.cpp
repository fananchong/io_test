#include <chrono>
#include <cstdio>
#include <cstdlib>

void test3(int buffsize)
{
	printf("TEST CASE: 只调用 fwrite ；并设置 setbuf ，大小为 %d \n", buffsize);
	FILE* f = fopen("fcase1.txt", "wb");
	if (!f)
	{
		printf("can not open file\n");
		exit(1);
	}
	char* buff = new char[buffsize];
	setvbuf(f, buff, _IOFBF, buffsize);
	int iters = 1000000;
	using std::chrono::high_resolution_clock;
	auto start = high_resolution_clock::now();
	for (int i = 0; i < iters; i++)
	{
		char msg[1024];
		auto len = snprintf(msg, sizeof(msg), "Hello logger: msg number %d\n", i);
		fwrite(msg, len, 1, f);
	}
	auto delta = high_resolution_clock::now() - start;
	auto delta_d = std::chrono::duration_cast<std::chrono::duration<double>>(delta).count();
	printf("Elapsed: %0.2f secs %d/sec\n", delta_d, int(iters / delta_d));
	delete buff;
}
