#ifndef dLoMiVeza_Cpp
#define dLoMiVeza_Cpp
//headers
#include "LoMiVeza.hpp"
//content
namespace nLoMiVeza
{
//typedef
//-//tTokenValue
//-//-//getters
auto tTokenValue::fGetKind(tInfo vInfo) -> eKind
{
	if(vInfo.size() < 1)
	{
		return eKindNone;
	}
	auto vDataKindFound = vDataKindTable.find(vInfo);
	if(vDataKindFound != vDataKindTable.end())
	{
		return vDataKindFound->second;
	}
	return eKindNameWord;
}//fGetKind
auto tTokenValue::fGetKindInfo(eKind vKind) -> tInfo
{
	return vKindInfoArray[vKind];
}//fGetKindInfo
//-//-//consdef
const tTokenValue::tKindInfoArray tTokenValue::vKindInfoArray = {
	[eKindNone]			= "None",
	[eKindMetaWord] = "MetaWord",
	[eKindNameSign] = "NameSign",
	[eKindNameWord] = "NameWord",
	[eKindOperator] = "Operator",
	[eKindStartKey] = "StartKey",
	[eKindFinalKey] = "FinalKey",
};//vKindInfoArray
const tTokenValue::tDataKindTable tTokenValue::vDataKindTable = {
	//MetaWord
	{"variable", eKindMetaWord},
	{"constant", eKindMetaWord},
	{"statical", eKindMetaWord},
 //NameSign
	{"@",				eKindNameSign},
	{"#",				eKindNameSign},
	{"$",				eKindNameSign},
 //Operator
	{"+",				eKindOperator},
	{"-",				eKindOperator},
	{"*",				eKindOperator},
	{"/",				eKindOperator},
	{"%",				eKindOperator},
	{"|",				eKindOperator},
	{"&",				eKindOperator},
	{"^",				eKindOperator},
	{".",				eKindOperator},
	{",",				eKindOperator},
 //StartKey
	{"?",				eKindStartKey},
	{"{",				eKindStartKey},
	{"[",				eKindStartKey},
	{"(",				eKindStartKey},
 //FinalKey
	{"!",				eKindFinalKey},
	{"}",				eKindFinalKey},
	{"]",				eKindFinalKey},
	{")",				eKindFinalKey},
};//vDataKindTable
const tTokenValue::tPairSignTable tTokenValue::vPairSignTable = {
	{"?", "!"},
	{"{", "}"},
	{"[", "]"},
	{"(", ")"},
};//vPairSignTable
}//namespace nLoMiVeza
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
			fmt::println(stderr, "invalid test key: {}", vTestKey);
			return EXIT_FAILURE;
		}
		else
		{
			fmt::println(stdout, "{}?", vTestKey);
			tTestOut vTestOut = vTestRef->second();
			fmt::println(stdout, "{}!", vTestKey);
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
		 fmt::println(stdout, "HelloWorld");
		 return EXIT_SUCCESS;
	 }},
	{"Token_Kind",
	 []()
	 {
		 auto vList = std::initializer_list<std::string_view>{
			 "MetaWord",
			 "constant",
			 "variable",
			 "statical",
			 "NameSign",
			 "@",
			 "#",
			 "$",
			 "Operator",
			 "+",
			 "-",
			 "*",
			 "/",
			 "%",
			 "StartKey",
			 "?",
       "{",
       "[",
       "(",
			 "FinalKey",
			 "!",
       "}",
       "]",
       ")",
		 };
		 for(auto vData: vList)
		 {
			 nLoMiVeza::tTokenValue vTokenObject(vData);
			 fmt::println(stdout, "{} -> {}", vData, vTokenObject.fGetKindInfo());
		 }
		 return EXIT_SUCCESS;
	 }},
};
#endif//ifd(dLoMiVeza_MakeTest)
#endif//ifd(dLoMiVeza_MakeTexe)
#endif//dLoMiVeza_Cpp
