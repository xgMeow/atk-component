/// @file      UiSweepOutputList.hpp
/// @brief     扫参输出表格，以 QTableWidget 内嵌编辑方式管理输出列表
/// @details   支持名称的行内编辑，表达式列通过按钮弹窗选择
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-11

#pragma once

#include "AstGlobal.h"
#include "AstAnalyzer/SweepStudy.hpp"
#include <QWidget>

class QTableWidget;
class QPushButton;

AST_NAMESPACE_BEGIN

class Expr;

/// @brief 扫参输出表格，以表格行内编辑方式管理 SweepOutput 列表
class AST_UICORE_API UiSweepOutputList : public QWidget
{
    Q_OBJECT
public:
    explicit UiSweepOutputList(QWidget* parent = nullptr);
    UiSweepOutputList(const UiSweepOutputList&) = delete;
    UiSweepOutputList& operator=(const UiSweepOutputList&) = delete;

    /// @brief 绑定 SweepStudy，用于读写输出
    void setStudy(SweepStudy* study);

    /// @brief 从 study 重建所有行
    void refreshTable();

private slots:
    void onAddOutput();
    void onRemoveOutput();
    void onCellChanged(int row, int col);
    void onExprClicked(int row);

private:
    void setupUi();

    /// @brief 获取当前绑定的 SweepStudy（通过 WeakPtr 判断生命周期）
    SweepStudy* study() const;

    /// @brief 弹出表达式选择对话框，返回选中的表达式（调用方负责管理生命周期）
    Expr* browseExpression(QWidget* parent);

    // ---- 列索引 ----
    enum OutCol {
        OUT_NAME = 0,
        OUT_EXPR,
        OUT_COUNT
    };

    WeakPtr<SweepStudy> study_{};

    QTableWidget* table_{};
    QPushButton*  addBtn_{};
    QPushButton*  removeBtn_{}; 
};

AST_NAMESPACE_END
