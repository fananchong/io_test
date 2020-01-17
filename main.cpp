
#include <functional>
#include <vector>
#include <stdlib.h>

void test1(int);
void test2(int);
void test3(int);
void test4(int);
void test5(int);
void test6(int);

int main(int argc, const char * argv[])
{
	if (argc <= 1)
	{
		printf("参数不足！\n");
		return 1;
	}
	typedef std::function<void(int)> functype;
	std::vector<functype> f = { nullptr, test1, test2, test3, test4, test5, test6 };
	int param = 0;
	if (argc <= 3)
	{
		param = std::atoi(argv[2]);
	}
	f[std::atoi(argv[1])](param);
	return 0;
}
