#pragma once
#include <string>
#include <vector>
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CObjectBase;
class CObjManage;
class ICrdnPlane; 
class CVGTPlane;


///
/// VGT面集合
///
class IATKOBJECT_API ICrdnPlaneGroup
{
public:
    ICrdnPlaneGroup(const ICrdnPlaneGroup&) = delete;
    ICrdnPlaneGroup& operator=(const ICrdnPlaneGroup&) = delete;

	ICrdnPlaneGroup(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage);
	virtual ~ICrdnPlaneGroup();
	
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
	/// @param[in]	eCrdnPlaneType  类型
	/// @return	是否支持类型	
	//********************************************************************
	bool IsTypeSupported(ECrdnPlaneType eCrdnPlaneType);

	//********************************************************************
	/// 创建VGT角
	/// @author	Gan Shu Long
	/// @date	2026-06-02
	/// @param[in]	strName 名称
	/// @param[in]	strDescription 描述
	/// @param[in]	eCrdnPlaneType 角类型
	/// @return	VGT角
	//********************************************************************
	ICrdnPlane* Create(std::string strName, std::string strDescription, ECrdnPlaneType eCrdnPlaneType);

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
	ICrdnPlane* Item(std::string strName);

	//********************************************************************
	/// 获取VGT是否已存在
	/// @author	Gan Shu Long
	/// @date	2026-06-02
	/// @param[in]	strName VGT元素名称
	/// @return	VGT是否已存在
	//********************************************************************
	bool Contains(std::string strName);

private:
	ICrdnPlane* NewICrdnPlane(CVGTPlane* pCVGTPlane, ECrdnPlaneType eCrdnPlaneType);

private:
	CObjManage*                           m_IAsGObjManage;
	CObjectBase*                          m_pCObjectBase;

	std::vector<ICrdnPlane*>              m_VectorICrdnPlane;
};
