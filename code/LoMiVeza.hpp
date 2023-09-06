#ifndef dLoMiVeza_Hpp
#define dLoMiVeza_Hpp
//headers
#include <cstdlib>
#include <functional>
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
using tTokenTable = std::unordered_map<std::string, tTokenValue>;
using tTokenArray = std::vector<tTokenValue>;
/* type of tokenizer
 */
class tTokenMaker
{
public://typedef

public://codetor

	tTokenMaker();

public://getters

public://setters

public://actions

private://datadef

	tTokenTable vTokenTable;
	tTokenArray vTokenArray;

};//tTokenMaker
/* type of source code unit
 */
class tSourceObject
{
public://typedef

	using tInfo = std::string_view;
	using tData = std::string;

public://codetor

	tSourceObject(tInfo vInfo): vData{vInfo}
	{
	}

public://getters

public://setters

public://actions

private://datadef

	tData vData;

};//tSourceObject
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
