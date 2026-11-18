#pragma once
#include <string>
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
struct CObjData;
class CVehicleGfx3D;
class CFacilityGfx3D;
class CSensorGfx3D;
class CObjectBase;
class CVGTBase;
class IVORefCrdn;

///
/// 三维向量集合
///
class IATKOBJECT_API IVORefCrdnCollection
{
public:
    IVORefCrdnCollection(const IVORefCrdnCollection&) = delete;
    IVORefCrdnCollection& operator=(const IVORefCrdnCollection&) = delete;

	IVORefCrdnCollection(CObjData* pObjData, CVehicleGfx3D* pCVehGfx3D);
	IVORefCrdnCollection(CObjData* pObjData, CFacilityGfx3D* pCFacGfx3D);
	IVORefCrdnCollection(CObjData* pObjData, CSensorGfx3D* pCSenGfx3D);
	~IVORefCrdnCollection();

	//********************************************************************
	/// 添加三维向量元素
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eType  向量类型
	/// @param[in]	strName  向量名称
	/// @return	向量元素	属性指针
	//********************************************************************
	IVORefCrdn* Add(EGeometricElemType eType, std::string strName);

	//********************************************************************
	/// 获得指定三维向量元素
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eType  向量类型
	/// @param[in]	strName  向量名称
	/// @return	向量元素	属性指针
	//********************************************************************
	IVORefCrdn* GetCrdnByName(EGeometricElemType eType, std::string strName);

	//********************************************************************
	/// 移除指定三维向量元素
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	nIndex  第nIndex向量元素
	//********************************************************************
	void Remove(int nIndex);

	//********************************************************************
	/// 移除所有三维向量元素
	/// @author	Dong Min
	/// @date	2023-11-3
	//********************************************************************
	void RemoveAll();

	//********************************************************************
	/// 移除指定三维向量元素
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	Type  向量类型
	/// @param[in]	strName  向量名称
	//********************************************************************
	void RemoveByName(EGeometricElemType Type, std::string strName);

	//********************************************************************
	/// 获得可支持的向量名称
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	可支持的向量名称	
	//********************************************************************
	std::vector<std::string> GetAvailableCrdns();

	//********************************************************************
	/// 获得集合个数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	集合个数	
	//********************************************************************
	int GetCount();

	//********************************************************************
	/// 获得指定三维向量元素
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	nIndex  第nIndex三维向量元素
	/// @return	指定三维向量元素
	//********************************************************************
	IVORefCrdn* Item(int nIndex);

private:
	CObjData*						m_pObjData;

	CVehicleGfx3D*              m_pCVehGfx3D;		//Vehicle三维向量指针
	CFacilityGfx3D*             m_pCFacGfx3D;		//Facility三维向量指针
	CSensorGfx3D*               m_pCSenGfx3D;		//Sensor三维向量指针


	std::vector<IVORefCrdn*>		m_vecVORefCrdn;     //元素数组


	//********************************************************************
	/// 获得输入字符串中VGT天体对象及名称
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	strInput  输入特定格式字符串，例CentralBody/Earth Earth(True) Vector
	/// @param[out]	pCB  对象指针，例Earth指针
	/// @param[out]	pVGTBase  VGT指针，例Earth(True)指针 
	/// @param[out]	type  VGT类型，例输入Vector，type类型为eVectorElem
	/// @return	指定三维向量元素
	//********************************************************************
	bool GetVGTCBAndName(std::string strInput,
		CObjectBase* &pCB,
		CVGTBase* &pVGTBase,
		EGeometricElemType& type);

};

