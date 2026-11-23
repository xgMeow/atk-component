#pragma once
#include <string>
#include <vector>
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CObjectBase;
class CObjManage;
class ICrdnSystem;
class CVGTSystem;


///
/// VGT系统集合
///
class IATKOBJECT_API ICrdnSystemGroup
{
public:
    ICrdnSystemGroup(const ICrdnSystemGroup&) = delete;
    ICrdnSystemGroup& operator=(const ICrdnSystemGroup&) = delete;

	ICrdnSystemGroup(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage);
	virtual ~ICrdnSystemGroup();
	
	//********************************************************************
	/// 获得支持的VGT元素类型
	/// @author	Gan Shu Long
	/// @date	2026-06-02
	/// @return	支持的VGT元素类型
	//********************************************************************
	std::vector<std::string> GetSupportedVGTTypes();

	//********************************************************************
	/// 获得 是否支持类型
	/// @author	Gan Shu Long
	/// @date	2026-06-02
	/// @param[in]	eCrdnSystemType  类型
	/// @return	是否支持类型	
	//********************************************************************
	bool IsTypeSupported(ECrdnSystemType eCrdnSystemType);

	//********************************************************************
	/// 创建VGT角
	/// @author	Gan Shu Long
	/// @date	2026-06-02
	/// @param[in]	strName 名称
	/// @param[in]	strDescription 描述
	/// @param[in]	eCrdnSystemType 角类型
	/// @return	VGT角
	//********************************************************************
	ICrdnSystem* Create(std::string strName, std::string strDescription, ECrdnSystemType eCrdnSystemType);

	//********************************************************************
	/// 删除VGT元素
	/// @author	Gan Shu Long
	/// @date	2026-06-02
	/// @param[in]	strName 名称
	/// @note 返回值：是否成功
	//********************************************************************
	void Remove(std::string strName);

	//********************************************************************
	/// 获取VGT元素
	/// @author	Gan Shu Long
	/// @date	2026-06-02
	/// @param[in]	strName VGT元素名称
	/// @return	VGT元素基类指针
	//********************************************************************
	ICrdnSystem* Item(std::string strName);

	//********************************************************************
	/// 获取VGT是否已存在
	/// @author	Gan Shu Long
	/// @date	2026-06-02
	/// @param[in]	strName VGT元素名称
	/// @return	VGT是否已存在
	//********************************************************************
	bool Contains(std::string strName);

private:
	ICrdnSystem* NewICrdnSystem(CVGTSystem* pCVGTSystem, ECrdnSystemType eCrdnSystemType);

private:
	CObjManage*                           m_IAsGObjManage;
	CObjectBase*                          m_pCObjectBase;

	std::vector<ICrdnSystem*>              m_VectorICrdnSystem;
};
