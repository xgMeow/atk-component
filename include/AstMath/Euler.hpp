/// @file      Euler.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      15.11.2025

#pragma once

#include "AstGlobal.h"
#include "AstMath/AttitudeConvertProto.hpp"

AST_NAMESPACE_BEGIN

/// @brief 欧拉角
/// @ingroup Attitude
class Euler
{
public:
    // 欧拉角转序
    enum ERotationOrder
    {
        eX = 1,
        eY = 2,
        eZ = 3,
        eXYZ = 123,
        eXZY = 132,
        eYXZ = 213,
        eYZX = 231,
        eZXY = 312,
        eZYX = 321,
        eXYX = 121,
        eXZX = 131,
        eYXY = 212,
        eYZY = 232,
        eZXZ = 313,
        eZYZ = 323
    };

    /// @brief 转换为旋转矩阵
    /// @param seq 欧拉角旋转序
    /// @param mtx 输出旋转矩阵
    /// @return 错误码
	errc_t toMatrix(int seq, Matrix3d& mtx) const{return aEulerToMatrix(*this, seq,mtx); }

    /// @brief 转换为四元数
    /// @param seq 欧拉角旋转序
    /// @param quat 输出四元数
    /// @return 错误码
    errc_t toQuat(int seq, Quaternion& quat) const{return aEulerToQuat(*this, seq, quat); }

    /// @brief 从旋转矩阵转换
    /// @param mtx 输入旋转矩阵
    /// @param seq 欧拉角旋转序
    /// @return 错误码
    errc_t fromMatrix(const Matrix3d& mtx, int seq){return aMatrixToEuler(mtx, seq, *this); }

    /// @brief 从四元数转换
    /// @param quat 输入四元数
    /// @param seq 欧拉角旋转序
    /// @return 错误码
    errc_t fromQuat(const Quaternion& quat, int seq){return aQuatToEuler(quat, seq, *this); }

    double angle1() const{return angle1_;}
    double angle2() const{return angle2_;}
    double angle3() const{return angle3_;}
    double& angle1(){return angle1_;}
    double& angle2(){return angle2_;}
    double& angle3(){return angle3_;}

    A_DEF_POD_ITERABLE(double)

public:
    // 设置为public只是为了聚合初始化，不要直接访问成员变量
	double	angle1_;	///< 第一个角
	double	angle2_;	///< 第二个角
	double	angle3_;	///< 第三个角
};


AST_NAMESPACE_END

AST_DECL_TYPE_ALIAS(Euler)