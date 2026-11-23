/// @file      VisView.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-06

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/ObjectNamed.hpp"
#include "AstCore/Frame.hpp"
#include "VisGroup.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 可视化视图：场景的顶级容器
/// @details 持有所有可视化对象的分组，高层 API（trajectory/groundTrack/planet）
///          通过虚函数或 friend 机制把对象挂进 objects_。
class AST_VISUALIZATION_API VisView: public ObjectNamed
{
public:
    VisView();

    /// @brief 场景对象分组
    VisGroup* objects() const { return objects_.get(); }

    Frame* frame() const{return frame_.get();}

    void setFrame(Frame* frame){frame_ = frame;}
private:
    SharedPtr<VisGroup> objects_{};           ///< 可视化元素
    WeakPtr<Frame> frame_{};                  ///< 可视化视图的参考系(世界坐标系)
};


/*! @} */

AST_NAMESPACE_END
