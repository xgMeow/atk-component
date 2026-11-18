#pragma once
#include "../IAtkObj.h"
#include <string>
#include <vector>
class CObjManage;
class ICvAssetListElement;
class AsAcObjParam;

///
/// 覆盖性对象集合
///
class IATKOBJECT_API ICvAssetListCollection
{
public:
	ICvAssetListCollection(const ICvAssetListCollection&) = delete;
	ICvAssetListCollection& operator=(const ICvAssetListCollection&) = delete;

	ICvAssetListCollection(CObjManage* IAsGObjManage, bool bAccess);
	~ICvAssetListCollection();

	//********************************************************************
	/// 获取可添加对象列表
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @return 可添加对象列表
	//********************************************************************
	std::vector<std::string> GetAvailableAssets();

	//********************************************************************
	/// 获取对象能否分配到覆盖性对象集合
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @param[in]	strObjectPath  对象路径名称 例：Satellite/Satellite1
	/// @return	对象能否分配到覆盖性对象集合
	//********************************************************************
	bool CanAssignAsset(std::string strObjectPath);

	//********************************************************************
	/// 添加对象
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @param[in]	strObjectPath  对象路径名称 例：Satellite/Satellite1
	/// @return	覆盖性对象元素
	//********************************************************************
	ICvAssetListElement* Add(std::string strObjectPath);

	//********************************************************************
	/// 获取覆盖性对象元素
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @param[in]	strObjectPath  对象路径名称 例：Satellite/Satellite1
	/// @return	覆盖性对象元素
	//********************************************************************
	ICvAssetListElement* GetAssetFromPath(std::string strObjectPath);

	//********************************************************************
	/// 获取对象是否已添加到覆盖性对象集合
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @param[in]	strObjectPath  对象路径名称 例：Satellite/Satellite1
	/// @return	对象是否已添加到覆盖性对象集合
	//********************************************************************
	bool IsAssetAssigned(std::string strObjectPath);

	//********************************************************************
	/// 移除对象通过对象路径名称
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @param[in]	strObjectPath  对象路径名称 例：Satellite/Satellite1
	//********************************************************************
	void Remove(std::string strObjectPath);

	//********************************************************************
	/// 移除所有对象
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	//********************************************************************
	void RemoveAll();

	//********************************************************************
	/// 移除对象通过索引
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @param[in]	nIndex  索引
	//********************************************************************
	void RemoveAt(int nIndex);

	//********************************************************************
	/// 获取覆盖性对象集合数量
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @return	覆盖性对象集合数量
	//********************************************************************
	int GetCount();

	//********************************************************************
	///  获取覆盖性对象元素通过索引
	/// @author	Gan Shu Long
	/// @date	2026-10-01
	/// @param[in]	nIndex  索引
	/// @return	覆盖性对象元素
	//********************************************************************
	ICvAssetListElement* Item(int nIndex);

private:
	bool SetAssetListToCoverageOperation();						//设置覆盖性对象集合到底层
	std::vector<std::string> GetAsAcObjParamSubObjPath(AsAcObjParam* pAsAcObjParam);		//获取可选目标对象子对象路径

private:
	CObjManage*							m_IAsGObjManage;

	bool								m_bAccess;					//是否为访问对象集合，否则就是目标对象集合
	std::vector<ICvAssetListElement*>	m_vecICvAssetListElement;   //覆盖性计算对象属性集合
};
