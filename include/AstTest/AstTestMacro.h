/// @file      AstTestMacro.h
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      15.11.2025

#pragma once

#include "AstGlobal.h"
#include <cmath>						// for fabs
#include <cstdio>						// for printf
#include <iostream> 					// for std::cout 
#include "AstTest/TestConfig.hpp"		// for test config
#include "AstUtil/Environment.hpp"		// for env check
#ifdef AST_WITH_GTEST
#include <gtest/gtest.h>
#else
#include "AstTest/TestFramework.hpp"		// 内置的 gtest 兼容测试框架
#endif

#define GTEST_MAIN() \
int main(int argc, char **argv) { \
  std::printf("Running main() from %s\n", __FILE__); \
  testing::InitGoogleTest(&argc, argv); \
  return RUN_ALL_TESTS(); \
}

#ifndef GTEST_SKIP
#	define GTEST_SKIP() return GTEST_SUCCESS_("Test skipped")  // 兼容老版本gtest
#endif


