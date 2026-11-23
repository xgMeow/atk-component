#pragma once
#include "../../IAtkObj.h"
#include "IVeAttProfile.h"
#include "../../ICEnum.h"
#include <vector>
#include <string>
struct CObjData;
struct CVehAttSegment;

///
/// 偏置姿态
///
class IATKOBJECT_API IVeProfileConstraintOffset : public IVeAttProfile
{
public:
    IVeProfileConstraintOffset(const IVeProfileConstraintOffset&) = delete;
    IVeProfileConstraintOffset& operator=(const IVeProfileConstraintOffset&) = delete;

	IVeProfileConstraintOffset(CObjData* pObjData);
	~IVeProfileConstraintOffset();

	//********************************************************************
	/// 获得支持的偏置姿态类型
	/// @author	Gan Shu Long
	/// @date	2026-02-04
	/// @return	支持的偏置姿态类型
	//********************************************************************
	std::vector<std::string> GetSupportedTypes();

	//********************************************************************
	/// 判断是否支持输入偏置姿态类型
	/// @author	Gan Shu Long
	/// @date	2026-02-04
	/// @param[in]	eProfileOffset   偏置姿态类型
	/// @return	是否支持输入偏置类型
	//********************************************************************
	bool IsProfileOffsetTypeSupported(EVeProfileOffset eProfileOffset);

	//********************************************************************
	/// 设置偏置姿态类型
	/// @author	Gan Shu Long
	/// @date	2026-02-04
	/// @param[in]	eProfileOffset   偏置姿态类型
	//********************************************************************
	void SetProfileOffsetType(EVeProfileOffset eProfileOffset);
	
	//********************************************************************
	/// 获得偏置姿态类型
	/// @author	Gan Shu Long
	/// @date	2026-02-04
	/// @return	偏置姿态类型
	//********************************************************************
	EVeProfileOffset GetProfileOffsetType();

	//********************************************************************
	/// 设置四元数
	/// @author	Gan Shu Long
	/// @date	2026-02-04
	/// @param[in]	dqx
	/// @param[in]	dqy
	/// @param[in]	dqz
	/// @param[in]	dqs
	//********************************************************************
	void AssignQuaternion(double dqx, double dqy, double dqz, double dqs);

	//********************************************************************
	/// 获取四元数
	/// @author	Gan Shu Long
	/// @date	2026-02-04
	/// @param[in]	dqx
	/// @param[in]	dqy
	/// @param[in]	dqz
	/// @param[in]	dqs
	//********************************************************************
	void QueryQuaternion(double& dqx, double& dqy, double& dqz, double& dqs);

	//********************************************************************
	/// 设置欧拉角
	/// @author	Gan Shu Long
	/// @date	2026-02-04
	/// @param[in]	dEuler1
	/// @param[in]	dEuler2
	/// @param[in]	dEuler3
	/// @param[in]	iSeq		转序序列
	//********************************************************************
	void AssignEuler(double dEuler1, double dEuler2, double dEuler3, int iSeq);

	//********************************************************************
	/// 获取欧拉角
	/// @author	Gan Shu Long
	/// @date	2026-02-04
	/// @param[in]	dEuler1
	/// @param[in]	dEuler2
	/// @param[in]	dEuler3
	/// @param[in]	iSeq		转序序列
	//********************************************************************
	void QueryEuler(double& dEuler1, double& dEuler2, double& dEuler3, int iSeq);

	//********************************************************************
	/// 设置YPR角
	/// @author	Gan Shu Long
	/// @date	2026-02-04
	/// @param[in]	dAngle1	偏航角
	/// @param[in]	dAngle2	俯仰角
	/// @param[in]	dAngle3	滚转角
	/// @param[in]	eYPRSequence		转序序列
	//********************************************************************
	void AssignYPR(double dAngle1, double dAngle2, double dAngle3, EYPRSequence eYPRSequence);

	//********************************************************************
	/// 获取YPR角
	/// @author	Gan Shu Long
	/// @date	2026-02-04
	/// @param[in]	dAngle1	偏航角
	/// @param[in]	dAngle2	俯仰角
	/// @param[in]	dAngle3	滚转角
	/// @param[in]	eYPRSequence		转序序列
	//********************************************************************
	void QueryYPR(double& dAngle1, double& dAngle2, double& dAngle3, EYPRSequence eYPRSequence);

private:
	//********************************************************************
	/// 设置四元数到底层对象	底层只保存四元数值
	/// @author	Gan Shu Long
	/// @date	2026-02-04
	/// @param[in]	dqx
	/// @param[in]	dqy
	/// @param[in]	dqz
	/// @param[in]	dqs
	//********************************************************************
	void SetQuaternionToCobj(double dqx, double dqy, double dqz, double dqs);

	//********************************************************************
	/// 设置转序序列到底层对象
	/// @author	Gan Shu Long
	/// @date	2026-02-04
	/// @param[in]	iSeq 转序序列
	//********************************************************************
	void SetSeqToCobj(int iSeq);

private:
	CObjData*									m_pObjData;
};
