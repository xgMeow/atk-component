#pragma once
#include "../IAtkObj.h"
#include "../IClassInfo.h" 
#include "../ICEnum.h"
#include <vector>
#include <string>
struct CCRAntenna;
struct CObjData;
class IAntennaModel;
class ICROrientation;

///
/// 天线控制
///
class IATKOBJECT_API IAntennaControl :public IClassInfo
{
public:
    IAntennaControl(const IAntennaControl&) = delete;
    IAntennaControl& operator=(const IAntennaControl&) = delete;

	IAntennaControl(CCRAntenna* pCCRAntenna, CObjData* pObjData);
	virtual ~IAntennaControl();

	//********************************************************************
	/// 获得 支持的嵌入式模型
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return 支持的嵌入式模型
	//********************************************************************
	std::vector<std::string> GetSupportedEmbeddedModels();

	//********************************************************************
	/// 按名称设置 嵌入式模型
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @param[in]	strEmbeddedModel  嵌入式模型
	/// [0] 'Gaussian'
	/// [1] 'Isotropic'
	/// [2] 'Parabolic'
	/// [3] 'External Antenna Pattern'
	//********************************************************************
	void SetEmbeddedModel(std::string strEmbeddedModel);

	//********************************************************************
	/// 获得  嵌入式模型
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return	 嵌入式模型
	//********************************************************************
	IAntennaModel* GetEmbeddedModel() { return m_EmbeddedModel; }

	//********************************************************************
	/// 获得  指向
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @return	 指向
	//********************************************************************
	ICROrientation* GetEmbeddedModelOrientation() { return m_EmbeddedModelOrientation; }

private:
	//********************************************************************
	/// 获得  模型类型字符串
	/// @author	Gan Shu Long
	/// @date	2026-03-16
	/// @param[in]	eAntennaModelType   模型类型
	/// @return  模型类型字符串
	//********************************************************************
	std::string ModelTypeToStr(EAntennaModelType eAntennaModelType);

private:
	CCRAntenna*				m_pCCRAntenna;							//天线结构体

	IAntennaModel*			m_EmbeddedModel;						//嵌入式模型
	ICROrientation*			m_EmbeddedModelOrientation;		//嵌入式模型指向
};
