#pragma once
#include <vector>
#include <string>
#include "IAtkObj.h"
#include "ICEnum.h"
class CObjManage;
struct CObjData;
class IAtkObject;
class IAtkObjectRoot;

///
/// 对象集合
///
class IATKOBJECT_API IAtkObjectCollection
{
public:
    IAtkObjectCollection(const IAtkObjectCollection&) = delete;
    IAtkObjectCollection& operator=(const IAtkObjectCollection&) = delete;

	IAtkObjectCollection(const std::string strObjName, CObjManage* IAsGObjManage, IAtkObjectRoot* Root);
	~IAtkObjectCollection();

	//********************************************************************
	/// 新建对象(不进行计算,不产生星历)
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eClassType  插入对象的类的类型
	/// @param[in]	strInstName  插入对象的名称
	/// @param[in]	strCentralBodyName  中心天体名称
	/// @return	对象属性
	//********************************************************************
	IAtkObject* New(EATKObjectType eClassType, std::string strInstName, std::string strCentralBodyName = "");

public:
	int                  GetCount();                          //包含子对象个数
	std::vector<int>     GetSupportedChildTypes();            //对象所支持添加的子对象类型
	IAtkObject*          Item(int nIndex);                    //按添加顺序，获得第nIndex个子对象
	IAtkObject*          Item(std::string strName);           //按添加顺序，获得此名称的子对象


	std::vector<IAtkObject*>            m_vecIAtkObj;                        //I子对象
	std::vector<long long>              m_vecObjID;                          //C子对象


private:
	CObjManage*                         m_IAsGObjManage;
	IAtkObjectRoot*                     m_Root;
	std::string                         m_strParentPath;                     //父对象路径

	//新建二次开发对象
	IAtkObject* NewIObject(EATKObjectType eClassType, CObjData* pObjData);
	//使用ID获取IAtkObject
	CObjData* GetIObjByID(long long objID);    
	//查询子对象ID获取IAtkObject
	void GetIObjBySub(CObjData* pObjData, long long objID, CObjData* &pIDObjData);
	//使用对象名称获取CObjData
	CObjData* GetCObjByName(std::string strObjName, std::string strObjClass = "");
	//查询子对象名称获取CObjData
	void GetCObjBySub(CObjData* pObjData, std::string strObjName, std::string strObjClass, CObjData* &pIDObjData);
	//C对象类型转化I类型
	EATKObjectType GetIObjTypeByC(CObjData* pObjData);
	//I对象类型转化C类型
	std::string GetCObjTypeByI(EATKObjectType eType);


};
