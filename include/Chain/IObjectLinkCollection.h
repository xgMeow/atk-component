#pragma once
#include "../IAtkObj.h"
#include "IObjectLink.h"
#include <string>
#include <vector>
class CChain;
class CObjManage;
class IAtkObject;

///
/// 链路对象列表
///
class IATKOBJECT_API IObjectLinkCollection
{
public:
    IObjectLinkCollection(const IObjectLinkCollection&) = delete;
    IObjectLinkCollection& operator=(const IObjectLinkCollection&) = delete;

	IObjectLinkCollection(CChain* pCChain, CObjManage* IAsGObjManage, IAtkObjectRoot* Root);
	~IObjectLinkCollection();

	//********************************************************************
	/// 增加链接对象通过对象路径名称
	/// @author	Gan Shu Long
	/// @date	2024-01-26
	/// @param[in]	strObjPathName  对象名称
	//********************************************************************
	void Add(std::string strObjPathName);

	//********************************************************************
	/// 增加链接对象通过对象指针
	/// @author	Gan Shu Long
	/// @date	2024-01-26
	/// @param[in]	pIAtkObject  对象指针
	//********************************************************************
	void AddObject(IAtkObject* pIAtkObject);

	//********************************************************************
	/// 搜索链接对象路径名称是否存在
	/// @author	Gan Shu Long
	/// @date	2024-01-26
	/// @param[in]	strObjPathName  对象名称
	/// @return	是否存在
	//********************************************************************
	bool Contains(std::string strObjPathName);

	//********************************************************************
	/// 获得链接对象索引
	/// @author	Gan Shu Long
	/// @date	2024-01-26
	/// @param[in]	strObjPathName  对象名称
	/// @return	对象索引 -1表示不存在
	//********************************************************************
	int IndexOf(std::string strObjPathName);

	//********************************************************************
	/// 通过索引移除链接对象
	/// @author	Gan Shu Long
	/// @date	2024-01-26
	/// @param[in]	index  对象索引
	//********************************************************************
	void Remove(int index);

	//********************************************************************
	/// 移除所有链接对象
	/// @author	Gan Shu Long
	/// @date	2024-01-26
	//********************************************************************
	void RemoveAll();

	//********************************************************************
	/// 通过对象路径名称移除链接对象
	/// @author	Gan Shu Long
	/// @date	2024-01-26
	/// @param[in]	strObjPathName  对象名称
	//********************************************************************
	void RemoveName(std::string strObjPathName);

	//********************************************************************
	/// 通过对象指针移除链接对象
	/// @author	Gan Shu Long
	/// @date	2024-01-26
	/// @param[in]	pIAtkObject  对象指针
	//********************************************************************
	void RemoveObject(IAtkObject* pIAtkObject);

	//********************************************************************
	/// 获取所有链接对象
	/// @author	Gan Shu Long
	/// @date	2024-01-26
	/// @return	链接对象列表
	//********************************************************************
	std::vector<IObjectLink*> AvailableObjects();

	//********************************************************************
	/// 通过索引获得链接对象
	/// @author	Gan Shu Long
	/// @date	2024-01-26
	/// @param[in]	index  对象索引
	/// @return	链接对象
	//********************************************************************
	IObjectLink* Item(int index);

	//********************************************************************
	/// 获得链接对象数量
	/// @author	Gan Shu Long
	/// @date	2024-01-26
	/// @return	链接对象数量
	//********************************************************************
	int GetCount()
	{
		return static_cast<int>(m_IObjectLinkVector.size());
	};
	
private:
	CObjManage*                 m_IAsGObjManage;
	CChain*						m_pCChain;

	IAtkObjectRoot*                   m_Root;                ///<根对象信息
	std::vector<IObjectLink*>	m_IObjectLinkVector;		//链中的对象集合
};
