#include <chrono>
#include <cstdio>
#include <cstdlib>

void test2(int _)
{
	printf("TEST CASE: 每次调用 fwrite fflush\n");
	FILE* f = fopen("test.txt", "wb");
	if (!f)
	{
		printf("can not open file\n");
		exit(1);
	}

	int iters = 1000000;
	using std::chrono::high_resolution_clock;
	auto start = high_resolution_clock::now();
	for (int i = 0; i < iters; i++)
	{
		char msg[1024];
		auto len = snprintf(msg, sizeof(msg), "Hello logger: msg number %d\n", i);
		fwrite(msg, len, 1, f);
		fflush(f);
	}
	auto delta = high_resolution_clock::now() - start;
	auto delta_d = std::chrono::duration_cast<std::chrono::duration<double>>(delta).count();
	printf("Elapsed: %0.2f secs %d/sec\n", delta_d, int(iters / delta_d));
}
