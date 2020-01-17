
#include <functional>
#include <vector>
#include <stdlib.h>

void test1();

int main(int argc, const char * argv[])
{
	if (argc <= 1)
	{
		printf("参数不足！\n");
		return 1;
	}
	auto i = std::atoi(argv[1]);

	typedef std::function<void()> functype;
	std::vector<functype> f = { 0,test1 };
	f[i]();
	return 0;
}
