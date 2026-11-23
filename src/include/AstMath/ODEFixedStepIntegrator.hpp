/// @file      ODEFixedStepIntegrator.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-16

#pragma once

#include "AstGlobal.h"
#include "ODEIntegrator.hpp"
#include "ODEWorkspace.hpp"

AST_NAMESPACE_BEGIN


/// @brief 固定步长积分器
/// @details 固定步长积分器是一种简单的积分器，每步积分的时间间隔相同。
/// @ingroup ODE
class AST_MATH_API ODEFixedStepIntegrator : public ODEIntegrator
{
public:
    AST_OBJECT(ODEFixedStepIntegrator);

    class Workspace;
    ODEFixedStepIntegrator();
    ~ODEFixedStepIntegrator();
    using ODEIntegrator::integrate;

    /// @brief 获取步长
    double getStepSize() const{ return stepSize_; }

    /// @brief 设置步长
    void setStepSize(double stepSize){ stepSize_ = stepSize; }

    /// @brief 获取积分过程中统计到的积分步数
    int getNumSteps() const;

    /// @brief 获取工作空间
    const Workspace& getWorkspace() const{ return workspace_; }
    Workspace& getWorkspace(){ return workspace_; }

    /// @see ODEIntegrator
    errc_t integrate(ODE& ode, double* y, double& t, double tf) override;

    /// @see ODEIntegrator
    errc_t integrateOneStep(ODE& ode, double* y, double& t, double tf) override;

protected:
    void resetWorkspace(int dimension, int stage);
public:
    /// @brief 固定步长积分器工作空间
    class Workspace : public ODEWorkspace
    {
    public:
        Workspace();

        Workspace(const Workspace&) = delete;
        Workspace& operator=(const Workspace&) = delete;

        ~Workspace();
        void reset(int dimension, int stage);
        void clear();
    public:
        int numSteps_;              ///< 总步数(统计数据)
        int dimension_;             ///< 状态向量维度
        int stage_;                 ///< 多步法阶数
        double largestStepSize_;    ///< 最大步长(统计数据)
        double smallestStepSize_;   ///< 最小步长(统计数据)
        double** KArr_;             ///< 多步法中间结果数组
        double* absErrPerLen_;      ///< 每步绝对误差数组
        double* ymid_;              ///< 每步中点状态向量
        double  nextAbsStepSize_;   ///< 下一步绝对步长，用于步长自适应调整
    };
private:
    Workspace workspace_;           ///< 工作空间
    double stepSize_;               ///< 步长
};

AST_NAMESPACE_END
