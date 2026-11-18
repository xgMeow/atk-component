#pragma once
#include <string>
#include "../IAtkObj.h"
#include "../ICEnum.h"
#include "../IClassInfo.h"
struct CObjData;
struct CObjBasicConstr;
struct CObjSunConstr;
struct CObjCommConstr;

///
/// 设置约束
///
class IATKOBJECT_API IAccessConstraint :public IClassInfo
{
public:
    IAccessConstraint(const IAccessConstraint&) = delete;
    IAccessConstraint& operator=(const IAccessConstraint&) = delete;

    IAccessConstraint(CObjData* pCObjData, EAccessConstraints eConstraint);
    virtual ~IAccessConstraint();

    //********************************************************************
    /// 获取角度值
    /// @author	Dong Min
    /// @date	2023-11-3
    /// @return	角度值
    //********************************************************************
	std::string GetConstraintName() { return m_ConstraintName; }

    //********************************************************************
    /// 获取角度值
    /// @author	Dong Min
    /// @date	2023-11-3
    /// @return	角度值
    //********************************************************************
	EAccessConstraints GetConstraintType() { return m_ConstraintType; }

protected:
	CObjData*              m_pcObjData;
    std::string            m_ConstraintName;   //约束名称
    EAccessConstraints     m_ConstraintType;   //约束类型

    void SetCosntParam(EAccessConstraints eConstraint);
    //获取底层C对象
    bool GetCObjConstr(CObjData* pCObjData, EAccessConstraints eConstraint, CObjBasicConstr* &pBasicConstr, CObjSunConstr* &pSunConstr, CObjCommConstr* &pCommConstr);

};
