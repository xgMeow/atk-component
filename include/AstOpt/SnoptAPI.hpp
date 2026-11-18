/// @file      SnoptAPI.hpp
/// @brief
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      27.11.2025

#pragma once

#include "AstGlobal.h"
#include "snopt_ast.h"

AST_NAMESPACE_BEGIN


struct SnoptCAPI
{
	decltype(&snoptproto::snopta_) snopta;
	decltype(&snoptproto::sninit_) sninit;
	decltype(&snoptproto::snjac_)  snjac;
	decltype(&snoptproto::snmema_) snmema;
	decltype(&snoptproto::snseti_) snseti;
	decltype(&snoptproto::snsetr_) snsetr;
	decltype(&snoptproto::snset_)  snset;
	A_DEF_POD_ITERABLE(void*)
};


/// @brief 加载snopt动态库函数
/// @param sharedLibPath
/// @return 成功返回非空，失败返回空
AST_OPT_CAPI SnoptCAPI* aSnopt_Load(const char* sharedLibPath);


AST_OPT_CAPI void aSnopt_Unload();


AST_OPT_CAPI SnoptCAPI* aSnopt_Find();


AST_OPT_CAPI SnoptCAPI* aSnopt_Get();







AST_NAMESPACE_END

