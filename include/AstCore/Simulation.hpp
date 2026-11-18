/// @file      Simulation.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-16

#pragma once

#include "AstCore/SimulationAPI.hpp"
#include "AstCore/DataPort.hpp"
#include "AstCore/BlockSin.hpp"
#include "AstCore/BlockAdd.hpp"
#include "AstCore/BlockGain.hpp"
#include "AstCore/BlockSum.hpp"
#include "AstCore/BlockSubtract.hpp"
#include "AstCore/BlockProduct.hpp"
#include "AstCore/BlockDivide.hpp"
#include "AstCore/BlockGain.hpp"
#include "AstCore/BlockUnaryMinus.hpp"
#include "AstCore/BlockAbs.hpp"
#include "AstCore/BlockSign.hpp"
#include "AstCore/BlockLogicalOperator.hpp"
#include "AstCore/BlockRelationalOperator.hpp"
#include "AstCore/BlockSaturation.hpp"
#include "AstCore/BlockDeadZone.hpp"
#include "AstCore/BlockConstant.hpp"
// Astrodynamics blocks
#include "AstCore/BlockDynamicSystem.hpp"
#include "AstCore/BlockRelativity.hpp"
#include "AstCore/BlockThirdBodyPointMass.hpp"
#include "AstCore/BlockThirdBodyGravity.hpp"
#include "AstCore/BlockTwoBody.hpp"
#include "AstCore/BlockGravity.hpp"
#include "AstCore/BlockMotion.hpp"
#include "AstCore/BlockDrag.hpp"
#include "AstCore/BlockSRP.hpp"
#include "AstCore/BlockMass.hpp"
#include "AstCore/BlockGravityPartial.hpp"
#include "AstCore/BlockStateTransitionMatrix.hpp"
#include "AstCore/BlockDragSensitivity.hpp"
#include "AstCore/BlockSRPSensitivity.hpp"
#include "AstCore/AstroBlockFactory.hpp"