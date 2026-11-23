#pragma once
#include "IAtkObj.h"
#include "ICEnum.h"
#include "IClassInfo.h"
#include "IAtkObjectCollection.h"
#include <string>
#include <unordered_map>
class CObjManage;
struct CObjData;
class CCoord3;
class IAtkObjectRoot;
class IAtkAccess;
class IAccessConstraintCollection;
class ICrdnProvider;
#define CCoord	CCoord3

///
/// 对象
///
class IATKOBJECT_API IAtkObject : public IClassInfo
{
public:
    IAtkObject(const IAtkObject&) = delete;
    IAtkObject& operator=(const IAtkObject&) = delete;

	IAtkObject(CObjData* pObjData, CObjManage* IAsGObjManage, IAtkObjectRoot* Root);
	virtual ~IAtkObject();

	//********************************************************************
	/// 删除对象
	/// @author	Dong Min
	/// @date	2023-11-3
	//********************************************************************
	void Unload();

	//********************************************************************
	/// 获得约束
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	约束集合指针
	//********************************************************************
	IAccessConstraintCollection* GetAccessConstraints();

	//********************************************************************
	/// 获得子对象
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	子对象集合
	//********************************************************************
	IAtkObjectCollection* GetChildren();

	//********************************************************************
	/// 获得历史数据
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	vecEpsec  仿真消耗时间
	/// @param[in]	vecPos    仿真位置
	/// @return	true-数据可获取
	//********************************************************************
	bool GetOrbitData(std::vector<double>& vecEpsec, std::vector<CCoord>& vecPos);

	//********************************************************************
	/// 获得可见性计算对象
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strObjectPath  计算对象路径，例"Satellite/Satellite1"
	/// @return	可见性计算对象
	//********************************************************************
	IAtkAccess* GetAccess(std::string strObjectPath);

	//********************************************************************
	/// 获得可见性计算对象
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	pIAtkObject  计算对象指针
	/// @return	可见性计算对象
	//********************************************************************
	IAtkAccess* GetAccessByObject(IAtkObject* pIAtkObject);

	//********************************************************************
	/// 获得对象是否支持可见性计算
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	是否支持可见性计算
	//********************************************************************
	bool IsAccessSupported();

	//********************************************************************
	/// 设置 对象名称
	/// @author	Gan Shu Long
	/// @date	2024-06-05
	/// @param[in]	strInstanceName  对象名称
	//********************************************************************
	void SetInstanceName(std::string  strInstanceName);

	//********************************************************************
	/// 矢量几何工具
	/// @author	Gan Shu Long
	/// @date	2026-06-02
	/// @return	矢量几何工具
	//********************************************************************
	ICrdnProvider* GetVGT();
	
	//********************************************************************
	/// 获取 对象类型
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @return	对象类型
	//********************************************************************
	EATKObjectType GetClassType();
	
	//********************************************************************
	/// 获取 对象类名
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @return	对象类名
	//********************************************************************
	std::string GetObjClassName();
	
	//********************************************************************
	/// 获取 对象是否包含子对象
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @return	对象是否包含子对象
	//********************************************************************
	bool GetHasChildren();
	
	//********************************************************************
	/// 获取 对象名称
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @return	对象名称
	//********************************************************************
	std::string GetInstanceName();
	
	//********************************************************************
	/// 获取 对象的父对象信息
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @return	对象的父对象信息
	//********************************************************************
	IAtkObject* GetParent();
	
	//********************************************************************
	/// 获取 对象路径
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @return	对象路径
	//********************************************************************
	std::string GetPath();
	
	//********************************************************************
	/// 获取 根对象信息
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @return	根对象信息
	//********************************************************************
	IAtkObjectRoot* GetRoot();
	
	//********************************************************************
	/// 获取 中心天体名称
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @return	中心天体名称
	//********************************************************************
	std::string	GetCentralBodyName();

protected:
	CObjData*                         m_pObjData;
	CObjManage*                       m_IAsGObjManage;

	IAccessConstraintCollection*      m_AccessConstraints;   ///<对象约束
	IAtkObjectCollection*             m_Children;            ///<子对象信息
	IAtkObjectRoot*                   m_Root;                ///<根对象信息
	std::unordered_map<IAtkObject*, IAtkAccess*>            m_MapObjAccess;           //<可见性对象列表
	ICrdnProvider*                    m_VGT;                 ///<矢量几何工具

	void GetIParent(IAtkObject* pIObj, std::string strParentPath, bool& bFind, IAtkObject* &pParent);
	void UnloadSubObject(std::vector<IAtkObject*>& vecIAtkObj);
	void DeleteParentObjectVector(bool bUi);

	void AddDepObject(IAtkObjectCollection* pParentObj);

	static void HandleUnload(IAtkObject* self, const struct AsTEvent& event_);
};



