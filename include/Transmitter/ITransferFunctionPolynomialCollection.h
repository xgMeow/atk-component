#pragma once
#include "../IAtkObj.h"
#include <vector>

///
/// 频率转换方法集合
///
class IATKOBJECT_API ITransferFunctionPolynomialCollection
{
public:
    ITransferFunctionPolynomialCollection(const ITransferFunctionPolynomialCollection&) = delete;
    ITransferFunctionPolynomialCollection& operator=(const ITransferFunctionPolynomialCollection&) = delete;

	ITransferFunctionPolynomialCollection(std::vector<double>* pPolynomialCollection);
	~ITransferFunctionPolynomialCollection();

	//********************************************************************
	/// 添加系数
	/// @author	Gan Shu Long
	/// @date	2026-03-26
	/// @param[in]	dCoefficient 添加系数
	//********************************************************************
	void Add(double dCoefficient);

	//********************************************************************
	/// 插入系数
	/// @author	Gan Shu Long
	/// @date	2026-03-26
	/// @param[in]	index 指定序号
	/// @param[in]	dCoefficient 添加系数
	//********************************************************************
	void InsertAt(int index, double dCoefficient);

	//********************************************************************
	/// 移除系数
	/// @author	Gan Shu Long
	/// @date	2026-03-26
	/// @param[in]	index 指定序号
	//********************************************************************
	void RemoveAt(int index);

	//********************************************************************
	/// 获取集合个数
	/// @author	Gan Shu Long
	/// @date	2026-03-26
	/// @return	集合个数
	//********************************************************************
	int GetCount();

	//********************************************************************
	///  获取指定序号椭圆设置
	/// @author	Gan Shu Long
	/// @date	2026-03-26
	/// @param[in]	index  指定序号
	/// @return	系数
	//********************************************************************
	double Item(int index);
	
private:
	std::vector<double>*		m_pPolynomialCollection;
};
