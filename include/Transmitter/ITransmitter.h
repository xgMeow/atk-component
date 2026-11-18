#pragma once
#include "../IAtkObject.h"
#include "ITransmitterModel.h"
class CObjManage;
struct CObjData;
class CTransmitter;

///
/// 发射器
///
class IATKOBJECT_API ITransmitter :public IAtkObject
{
public:
    ITransmitter(const ITransmitter&) = delete;
    ITransmitter& operator=(const ITransmitter&) = delete;

	ITransmitter(CObjData* pObjData, CObjManage* IAsGObjManage, IAtkObjectRoot* Root);
	~ITransmitter();
	
	//********************************************************************
	/// 获得 支持的发射器模型名称
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return 支持的发射器模型名称
	//********************************************************************
	std::vector<std::string> GetSupportedModels();

	//********************************************************************
	/// 按名称设置 发射器模型
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	strModelName  发射器模型名称
	/// "[0] 'Simple Transmitter Model'"
	/// "[1] 'Medium Transmitter Model'"
	/// "[2] 'Complex Transmitter Model'"
	/// "[3] 'Simple Re-Transmitter Model'"
	/// "[4] 'Medium Re-Transmitter Model'"
	/// "[5] 'Complex Re-Transmitter Model'"
	//********************************************************************
	void SetModel(std::string strModelName);
	
	//********************************************************************
	/// 设置 发射器模型类型
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @param[in]	eTransmitterModelType  发射器模型类型
	//********************************************************************
	void SetTransmitterModelType(ETransmitterModelType eTransmitterModelType);

	//********************************************************************
	/// 获得 发射器模型类型
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	发射器模型类型
	//********************************************************************
	ETransmitterModelType GetTransmitterModelType();

	//********************************************************************
	/// 获得  发射器模型
	/// @author	Gan Shu Long
	/// @date	2026-03-25
	/// @return	 发射器模型
	//********************************************************************
	ITransmitterModel* GetModel() { return m_Model; }

private:
	CTransmitter*					m_CTransmitter;
	ITransmitterModel*			m_Model;						//发射器模型
};
