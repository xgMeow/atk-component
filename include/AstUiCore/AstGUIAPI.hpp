/// @file      GuiAPI.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-18

#pragma once

#include "AstGlobal.h"

class QMainWindow;

AST_NAMESPACE_BEGIN


/// @brief 初始化Gui
/// @return errc_t
AST_UICORE_CAPI errc_t aGUIInit();


/// @brief 初始化Qt应用程序
/// @details 缺少 Qt 平台插件（如 Windows 下的 qwindows.dll）时会降级为 QCoreApplication，
///          此时日志与翻译功能仍可正常使用，但所有 GUI 功能不可用。
/// @return errc_t
AST_UICORE_CAPI errc_t aQAppInit(int argc, char *argv[]);

/// @brief 判断当前是否具备可用的 GUI 环境
/// @details 仅当已成功创建 QApplication（即平台插件可用）时返回 true。
///          返回 false 时不应创建任何 QWidget 派生对象。
/// @return 具备可用 GUI 环境返回 true
AST_UICORE_CAPI bool aGuiAvailable();

/// @brief 创建主窗口
/// @return QMainWindow*，GUI 环境不可用时返回 nullptr
AST_UICORE_CAPI QMainWindow* aUiNewMainWindow();


AST_NAMESPACE_END
