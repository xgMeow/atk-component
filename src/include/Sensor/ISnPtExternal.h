#pragma once
#include "../IAtkObj.h"
#include "ISnPointing.h"
struct CObjData;
class CSensor;

///
/// 指向：外部文件
///
class IATKOBJECT_API ISnPtExternal : public ISnPointing
{
public:
    ISnPtExternal(const ISnPtExternal&) = delete;
    ISnPtExternal& operator=(const ISnPtExternal&) = delete;

	ISnPtExternal(CObjData* pCObjData);
	~ISnPtExternal();

	//********************************************************************
	/// 设置 文件路径
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	strFilename 文件路径
	//********************************************************************
	void SetFilename(std::string  strFilename);

	//********************************************************************
	/// 获得 文件路径
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	文件路径
	//********************************************************************
	std::string  GetFilename();

private:
	CSensor*				m_pCSensor;
};

