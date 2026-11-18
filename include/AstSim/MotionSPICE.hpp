/// @file      MotionSPICE.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-26

#pragma once

#include "AstGlobal.h"
#include "AstCore/EventInterval.hpp"
#include "AstCore/BodyEphemerisSPK.hpp"
#include "AstCore/JplSpk.hpp"
#include "AstUtil/SPKParser.hpp"
#include "AstSim/MotionProfile.hpp"
#include "AstSim/MotionWithIntervalStep.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief SPICE星历预报器/运动模型类
/// @details  读取SPICE星历文件，生成星历数据
class AST_SIM_API MotionSPICE: public MotionWithIntervalStep
{
public:
    AST_OBJECT(MotionSPICE)
    static MotionSPICE* New();
    MotionSPICE() : spiceIndex_() {}
    ~MotionSPICE() {}
public:
    errc_t makeEphemerisSpec(ScopedPtr<Ephemeris>& eph) const override;
    errc_t makeEphemerisSimple(ScopedPtr<Ephemeris>& eph) const override;
    void accept(MotionProfileVisitor& visitor) override;

    const std::string& getSpiceFile() const {return spk_.getFilePath();}
    errc_t setSpiceFile(StringView spiceFile);

    int getSpiceIndex() const {return spiceIndex_;}
    void setSpiceIndex(int spiceIndex){spiceIndex_ = spiceIndex;}
protected:
    int spiceIndex_{};                    ///< SPICE星历索引号
private:
    JplSpk spk_{};                       ///< SPICE星历接口
};

/*! @} */

AST_NAMESPACE_END