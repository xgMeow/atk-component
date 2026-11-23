#pragma once
#include "../IAtkObj.h"
#include "../ICEnum.h"
class CCoverageDefinition;
class CObjManage;
class ICvResolution;
class ICvBounds;

///
/// 网格
///
class IATKOBJECT_API ICvGrid
{
public:
    ICvGrid(const ICvGrid&) = delete;
    ICvGrid& operator=(const ICvGrid&) = delete;

	ICvGrid(CCoverageDefinition* pCCoverageDefinition, CObjManage* IAsGObjManage);
	~ICvGrid();

	//********************************************************************
	/// 设置 覆盖区域类型
	/// @author	Gan Shu Long
	/// @date	2023-12-9
	/// @param[in]	boundsType boundsType 覆盖区域类型
	//********************************************************************
	void SetBoundsType(ECvBounds boundsType);

	//********************************************************************
	/// 获得覆盖区域类型
	/// @author	Gan Shu Long
	/// @date	2023-12-9
	/// @return	覆盖区域类型
	//********************************************************************
	ECvBounds GetBoundsType();

	//********************************************************************
	/// 设置 网格分辨率类型
	/// @author	Gan Shu Long
	/// @date	2023-12-9
	/// @param[in]	resolutionType resolutionType 网格分辨率类型
	//********************************************************************
	void SetResolutionType(ECvResolution resolutionType);

	//********************************************************************
	/// 获得 网格分辨率类型
	/// @author	Gan Shu Long
	/// @date	2023-12-9
	/// @return	网格分辨率类型
	//********************************************************************
	ECvResolution GetResolutionType();	
	
	//********************************************************************
	/// 获得覆盖区域
	/// @author	Gan Shu Long
	/// @date	2026-01-19
	/// @return	覆盖区域
	//********************************************************************
	ICvBounds* GetBounds() { return m_Bounds; }

	//********************************************************************
	/// 获得 网格分辨率
	/// @author	Gan Shu Long
	/// @date	2026-01-19
	/// @return	网格分辨率
	//********************************************************************
	ICvResolution* GetResolution() { return m_Resolution; }

private:
	CObjManage*								m_IAsGObjManage;                ///<根对象信息
	ICvBounds* m_Bounds;				//覆盖区域
	ICvResolution* m_Resolution;		//网格分辨率

	CCoverageDefinition* m_pCCoverageDefinition;
};
