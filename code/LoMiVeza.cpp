#ifndef dLoMiVeza_Cpp
#define dLoMiVeza_Cpp
//headers
#include "LoMiVeza.hpp"
//content
namespace nLoMiVeza
{
}
#if defined(dLoMiVeza_MakeTexe)
//typedef
#if defined(dLoMiVeza_MakeTest)
using tTestKey = std::string_view;
using tTestOut = int;
using tTestFun = std::function<tTestOut(void)>;
using tTestTab = std::unordered_map<tTestKey, tTestFun>;
using tTestRef = tTestTab::iterator;
#endif//ifd(dLoMiVeza_MakeTest)
//actions
int main(int vArgC, char **vArgV, char **vEnvi)
{
#if defined(dLoMiVeza_MakeTest)
	extern tTestTab vTestTab;
	if(vArgC == 3 && std::string_view(vArgV[1]) == "test")
	{
		tTestKey vTestKey = std::string_view(vArgV[2]);
		tTestRef vTestRef = vTestTab.find(vTestKey);
		if(vTestRef == vTestTab.end())
		{
			std::cerr << "invalid test key: " << vTestKey << std::endl;
			return EXIT_FAILURE;
		}
		else
		{
			std::cout << vTestKey << "=" << std::endl;
			tTestOut vTestOut = vTestRef->second();
			std::cout << "=" << vTestKey << std::endl;
			return vTestOut;
		}
	}
	else
#endif//ifd(dLoMiVeza_MakeTest)
	{
		auto vIter = std::ostream_iterator<char *>(std::cout, "\n");
		std::copy(vArgV, vArgV + vArgC, vIter);
	}
	return EXIT_SUCCESS;
}
#if defined(dLoMiVeza_MakeTest)
tTestTab vTestTab = {
	{"Hello",
	 []()
	 {
     std::cout << "HelloWorld";
		 return EXIT_SUCCESS;
	 }},
};
#endif//ifd(dLoMiVeza_MakeTest)
#endif//ifd(dLoMiVeza_MakeTexe)
#endif//dLoMiVeza_Cpp
