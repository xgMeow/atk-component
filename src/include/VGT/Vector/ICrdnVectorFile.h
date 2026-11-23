#pragma once
#include "../../IAtkObj.h"
#include "ICrdnVector.h"


///
/// VGT元素 向量文件
///
class IATKOBJECT_API ICrdnVectorFile :public ICrdnVector
{
public:
    ICrdnVectorFile(const ICrdnVectorFile&) = delete;
    ICrdnVectorFile& operator=(const ICrdnVectorFile&) = delete;

	ICrdnVectorFile(CObjectBase* pCObjectBase, CObjManage* IAsGObjManage, CVGTBase* pCVGTBase);
	virtual ~ICrdnVectorFile();

	IATKOBJECT_VGT_SETGET_DECL(FilePath, std::string);
	IATKOBJECT_VGT_SETGET_CTIMEABS_DECL(Epoch);
	IATKOBJECT_VGT_SETGET_VGT_DECL(ReferenceAxes);
};
