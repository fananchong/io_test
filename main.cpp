
#include <functional>
#include <vector>
#include <stdlib.h>

void test1();
void test2();
void test3();

int main(int argc, const char * argv[])
{
	if (argc <= 1)
	{
		printf("参数不足！\n");
		return 1;
	}
	typedef std::function<void()> functype;
	std::vector<functype> f = { nullptr, test1, test2, test3 };
	f[std::atoi(argv[1])]();
	return 0;
}
