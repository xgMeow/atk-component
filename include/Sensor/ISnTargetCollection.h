#pragma once
#include "../IAtkObj.h"
#include <string>
#include <vector>
class CSensor;
class CObjManage;
class IAtkObject;
class ISnTarget;

///
/// 目标定向已选对象列表
///
class IATKOBJECT_API ISnTargetCollection
{
public:
    ISnTargetCollection(const ISnTargetCollection&) = delete;
    ISnTargetCollection& operator=(const ISnTargetCollection&) = delete;

	ISnTargetCollection(CSensor* pCSensor, CObjManage* IAsGObjManage);
	~ISnTargetCollection();

	//********************************************************************
	/// 增加目标对象通过对象路径名称
	/// @author	Gan Shu Long
	/// @date	2026-03-24
	/// @param[in]	strObjPathName  对象路径名称
	//********************************************************************
	void Add(std::string strObjPathName);

	//********************************************************************
	/// 增加目标对象通过对象指针
	/// @author	Gan Shu Long
	/// @date	2026-03-24
	/// @param[in]	pIAtkObject  对象指针
	//********************************************************************
	void AddObject(IAtkObject* pIAtkObject);

	//********************************************************************
	/// 通过索引移除目标对象
	/// @author	Gan Shu Long
	/// @date	2026-03-24
	/// @param[in]	index  对象索引
	//********************************************************************
	void Remove(int index);

	//********************************************************************
	/// 移除所有目标对象
	/// @author	Gan Shu Long
	/// @date	2026-03-24
	//********************************************************************
	void RemoveAll();

	//********************************************************************
	/// 通过对象指针移除目标对象
	/// @author	Gan Shu Long
	/// @date	2026-03-24
	/// @param[in]	pIAtkObject  对象指针
	//********************************************************************
	void RemoveObject(IAtkObject* pIAtkObject);

	//********************************************************************
	/// 通过对象路径名称移除目标对象
	/// @author	Gan Shu Long
	/// @date	2026-03-24
	/// @param[in]	strObjPathName  对象路径名称
	//********************************************************************
	void RemoveTarget(std::string strObjPathName);

	//********************************************************************
	/// 获得目标对象数量
	/// @author	Gan Shu Long
	/// @date	2026-03-24
	/// @return	目标对象数量
	//********************************************************************
	int GetCount();

	//********************************************************************
	/// 通过索引获得目标对象
	/// @author	Gan Shu Long
	/// @date	2026-03-24
	/// @param[in]	index  对象索引
	/// @return	目标对象
	//********************************************************************
	ISnTarget* Item(int index);
	
private:
	CObjManage*						m_IAsGObjManage;
	CSensor*							m_pCSensor;

	std::vector<ISnTarget*>		m_ISnTargetVector;			//已选对象列表
};
