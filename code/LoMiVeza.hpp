#ifndef dLoMiVeza_Hpp
#define dLoMiVeza_Hpp
//headers
#include <cstdlib>
#include <functional>
//-//memory
#include <memory>
//-//strings
#include <string_view>
#include "fmt/format.h"
//-//template library
#include <array>
#include <vector>
#include <unordered_map>
//-//input output
#include <iostream>
#include <fstream>
#include <filesystem>
//content
namespace nLoMiVeza
{
namespace nFileSystem = std::filesystem;
using tSourceUnit = std::shared_ptr<std::string>;
/* type of token
 * meaning of every separate word or a special symbol in the text
 */
class tTokenValue
{
public://enumdef

	/* enumeration of token kinds
	 */
	typedef enum eKind
		: unsigned
	{
		eKindNone = 0,
		eKindMetaWord,
		eKindNameSign,
		eKindNameWord,
		eKindOperator,
		eKindStartKey,
		eKindFinalKey,
		eKindLast
	} eKind;

public://typedef

	using tThis = tTokenValue;

	using tInfo = std::string_view;//мне поебать, я назову это так
	using tData = std::string;//и это тоже, makes sense to me

	using tKindInfoArray = tInfo[eKindLast];//enum + array = so_dang_cool
	using tDataKindTable = std::unordered_map<std::string_view, eKind>;
	using tPairSignTable = std::unordered_map<std::string_view, std::string_view>;

public://codetor

	tTokenValue(tInfo vInfo): vData{vInfo}, vKind{tThis::fGetKind(vInfo)}
	{
	}

public://getters

	inline auto fGetData() const -> tInfo
	{
		return this->vData;
	}
	inline auto fGetKind() const -> eKind
	{
		return this->vKind;
	}
	inline auto fGetKindInfo() const -> tInfo
	{
		return fGetKindInfo(this->vKind);
	}

	static auto fGetKind(tInfo vInfo) -> eKind;

	static auto fGetKindInfo(eKind vKind) -> tInfo;

public://setters

public://actions

private://datadef

	tData vData;
	eKind vKind;

public://consdef

	static const tKindInfoArray vKindInfoArray;
	static const tDataKindTable vDataKindTable;
	static const tPairSignTable vPairSignTable;
};
using tTokenArray = std::vector<tTokenValue>;
/* type of tokenizer
 */
class tTokenMaker
{
public://codetor

	tTokenMaker(tSourceUnit vSourceUnit): vSourceUnit{vSourceUnit}
	{
	}

public://getters

public://setters

public://actions

private://datadef

	tSourceUnit vSourceUnit;
	tTokenArray vTokenArray;

};//tTokenMaker
/* type of Instance
 * the holder of scripting environment
 * all variables and operations are stored here
 */
class tInstance
{
public://typedef

public://codetor

	tInstance();

public://getters

public://setters

public://actions

private://datadef

	tTokenMaker vTokenMaker;

};//tInstance
}//namespace nLoMiVeza
#endif//dLoMiVeza_Hpp
