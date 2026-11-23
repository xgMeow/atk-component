\page component_flow_cpp C++ 操作流程

以下以 Visual Studio 2015 为例，说明使用 Component 动态库进行二次开发的操作流程：先准备接口文件与编译环境，再在 Windows 或 Linux 下编译运行示例工程，然后按从零创建新项目的步骤建立并运行自己的工程，最后用 ATK 打开生成文件查看仿真轨迹。

## 一、接口说明

### 目录结构说明

进入文件目录`<ATK根目录>/IntegratingWithATK/component`，该目录下的结构如下：

\note 在不同操作系统下目录结构有所不同。

```
component
 ├─bin                二进制目录（动态库目录）
 ├─include            包含目录（头文件目录）
 ├─lib                链接库目录
 ├─src                示例代码
 ├─Java               Java接口源文件
 ├─vs2015             Visual Studio 2015 工程配置文件
 ├─vs2017             Visual Studio 2017 工程配置文件
 ├─vs2019             Visual Studio 2019 工程配置文件
 ├─vs2022             Visual Studio 2022 工程配置文件
 ├─configure          用于生成make编译配置
 ├─xmake.lua          xmake 编译配置
 └─xmake.sh           xmake 编译配置
```

### 编译环境准备

#### Windows 下

在Windows下使用Component动态库，需要安装 Visual Studio ，且版本为 Visual Studio 2015及以上。

Visual Studio的下载链接为：<https://visualstudio.microsoft.com/>。

#### Linux（麒麟等系统）下

在linux下使用Component动态库，使用系统自带的g++或gcc作为编译器即可。

构建工具根据使用习惯，可以使用选择以下任意一种：`make`、`xmake`、`cmake`、`qt`、`meson`，推荐使用`xmake`构建工具。

### 数据准备

在运行c++项目前，需要将ATK根目录下的`AstroData`文件夹复制到`<ATK根目录>/IntegratingWithATK/component/bin`处。

## 二、在 Windows 下使用

### 运行示例项目

进入文件目录`<ATK根目录>/IntegratingWithATK/component`，根据所安装的Visual Studio版本打开相关的项目配置文件

例如，如果安装是Vistual Studio 2022，则打开`vs2022`文件夹下的解决方案(.sln文件)

打开解决方案后，**需要重定向工程**，在工程配置中选择电脑所安装的Windows SDK版本

配置修改完成后即可编译

从零开始创建新项目时，按以下步骤操作。

### 新建项目

打开 VS2015，点击新建项目，新建空项目，并设置项目名称与位置，设置完成后点击确定。

\image html cpp-new-project-1.png "新建项目步骤"

\image html cpp-new-project-2.png "新建项目"

### 文件配置

在 ATK 安装包目录中，点击IntegratingWithATK文件夹，点开Component文件夹。

\image html cpp-file-setup-1.png "ATK.Component 包含文件文件夹"

\image html cpp-file-setup-2.png "ATK.Component 包含动态库文件夹"

\image html cpp-file-setup-3.png "ATK.Component 包含库文件夹"

将所有文件添加至工程Test根目录中。

\image html cpp-file-setup-4.png "Lib 库与头文件添加"

将需要的配置文件添加至此文件夹。（AstroData文件夹在ATK安装目录下）。

\image html cpp-file-setup-5.png "配置文件添加"

### 项目新建项

项目添加文件，项目右键->添加->新建项。

\image html cpp-new-item-1.png "新建文件步骤"

### 设置添加项的名称与位置

设置文件名称及位置，点击添加，完成后点击生成。

\image html cpp-item-name-1.png "新建文件"

### 项目环境配置

打开项目右键->属性。

\image html cpp-project-settings-1.png "属性设置步骤"

配置平台改为所有配置，所有平台模式，点击常规->输出目录，将输出目录修改为项目目录。

\image html cpp-project-settings-2.png "修改输出目录"

点击C/C++->常规->附加包含目录，将头文件目录添加至附加包含目录。点击应用按钮将环境配置应用到项目，点击确定按钮。

\image html cpp-project-settings-3.png "附加包含目录设置"

### 添加包含文件，编写代码

\image html cpp-include-code-1.png "包含文件"

\image html cpp-include-code-2.png "设置代码"

### 设置编译平台为X64

在菜单栏选择生成->配置管理器，选择X64平台，点击关闭按钮。

\image html cpp-build-x64-1.png "配置管理器"

\image html cpp-build-x64-2.png "选择编译平台"

在菜单栏选择生成->生成解决方案进行编译。

\image html cpp-build-x64-3.png "生成解决方案"

点击本地Windows调试器按钮，项目执行。

### 查看生成文件

生成文件在项目目录下的Output目录中。

\image html cpp-output-files-1.png "生成文件"

### 仿真轨迹

使用ATK打开生成文件，可以查看仿真轨迹。

\image html cpp-simulation-1.png "仿真轨迹"

## 三、在 Linux 下使用

### 运行示例项目

进入文件目录`<ATK根目录>/IntegratingWithATK/component`

在linux下，示例项目采用`xmake`进行配置，配置文件为`xmake.sh`

在命令行中进入该目录，运行以下命令即可编译：

```sh
./configure
make
```

注意需要给`./configure`赋予可执行权限：

```sh
chmod +x ./configure
```

## 四、代码示例

```cpp
// 代码结构功能流程说明
//（1）包含所需头文件，并添加执行函数
//（2）添加根节点
//（3）想定新建与属性设置
//（4）卫星新建与轨道预报设置为机动规划
//（5）机动规划添加段，新添加卫星会有默认初始段
//（6）初始段属性设置
//（7）第一个预报段属性设置
//（8）第一个瞄准段中机动段属性设置
//（9）第一个瞄准段添加属性页，并设置属性页中控制变量与约束条件的属性
//（10）第二个预报段属性设置
//（11）第二个瞄准段中机动段属性设置
//（12）第二个瞄准段添加属性页，并设置属性页中控制变量与约束条件的属性
//（13）第三个预报段属性设置
//（14）机动规划运行
//（15）生成数据到文件
//（16）想定保存及关闭

#pragma once
#include <iostream>
#include <stdlib.h>
#include "IAtkObjectH.h"    //包含头文件
using namespace std;

int main()
{
	IAtkObjectRoot* pRoot = new IAtkObjectRoot();

	//
	//想定新建与属性设置
	//
	IScenario* pIScen = (IScenario*)pRoot->GetChildren()->New(eScenario, "FastTransfer");
	if (nullptr == pIScen)
	{
		printf("please copy AstroData to bin");
#ifdef _WIN32
		system(R"(xcopy ..\..\..\AstroData\*             .\AstroData              /e /i /y /q)");
#endif
		return -1;
	}
	pIScen->SetTimePeriod("5 Nov 2022 00:00:00.000", "6 Nov 2022 00:00:00.000");

	//
	//卫星新建与轨道预报设置为机动规划
	//
	ISatellite* pISatellite = (ISatellite*)pIScen->GetChildren()->New(eSatellite, "Satellite1");
	pISatellite->SetPropagatorType(ePropagatorAstromaster);
	IVADriverMCS* pIVADriverMCS = (IVADriverMCS*)pISatellite->GetPropagator();
	IVAMCSSegmentCollection* pIVAMCSSegmentCollection = pIVADriverMCS->GetMainSequence();
	//
	//机动规划添加段，新添加卫星会有默认初始段
	//
	IVAMCSInitialState* pIVAMCSInitialState = nullptr;
	if (eVASegmentTypeInitialState == pIVAMCSSegmentCollection->Item(0)->GetType())
	{
		pIVAMCSInitialState = (IVAMCSInitialState*)pIVAMCSSegmentCollection->Item(0);
	}
	IVAMCSPropagate* pIVAMCSPropagate = (IVAMCSPropagate*)pIVAMCSSegmentCollection->Insert(eVASegmentTypePropagate, "Propagate", "-");
	IVAMCSTargetSequence* pIVAMCSTargetSequence = (IVAMCSTargetSequence*)pIVAMCSSegmentCollection->Insert(eVASegmentTypeTargetSequence, "TargetSequence", "-");
	IVAMCSManeuver* pIVAMCSManeuver = (IVAMCSManeuver*)pIVAMCSTargetSequence->GetSegments()->Insert(eVASegmentTypeManeuver, "Maneuver", "-");
	IVAMCSPropagate* pIVAMCSPropagate1 = (IVAMCSPropagate*)pIVAMCSSegmentCollection->Insert(eVASegmentTypePropagate, "Propagate", "-");
	IVAMCSTargetSequence* pIVAMCSTargetSequence1 = (IVAMCSTargetSequence*)pIVAMCSSegmentCollection->Insert(eVASegmentTypeTargetSequence, "TargetSequence1", "-");
	IVAMCSManeuver* pIVAMCSManeuver1 = (IVAMCSManeuver*)pIVAMCSTargetSequence1->GetSegments()->Insert(eVASegmentTypeManeuver, "Maneuver", "-");
	IVAMCSPropagate* pIVAMCSPropagate2 = (IVAMCSPropagate*)pIVAMCSSegmentCollection->Insert(eVASegmentTypePropagate, "Propagate", "-");

	//
	//初始段属性设置
	//
	pIVAMCSInitialState->SetOrbitEpoch("5 Nov 2022 00:00:00.000");
	pIVAMCSInitialState->SetElementType(eVAElementTypeKeplerian);
	IVAElementKeplerian* pIVAElementKeplerian = (IVAElementKeplerian*)pIVAMCSInitialState->GetElement();
	pIVAElementKeplerian->SetSemiMajorAxis(6700000);
	pIVAElementKeplerian->SetEccentricity(0);
	pIVAElementKeplerian->SetInclination(0);
	pIVAElementKeplerian->SetRAAN(0);
	pIVAElementKeplerian->SetArgOfPeriapsis(0);
	pIVAElementKeplerian->SetTrueAnomaly(0);

	//
	//第一个预报段属性设置
	//
	IVAStoppingConditionElement* pIVAStoppingConditionElement = pIVAMCSPropagate->GetStoppingConditions()->Add("Duration");
	IVAStoppingCondition* pIVAStoppingCondition = (IVAStoppingCondition*)pIVAStoppingConditionElement->GetProperties();
	pIVAStoppingCondition->SetTrip(7200);
	pIVAStoppingCondition->SetTolerance(0.0001);

	//
	//第一个瞄准段中机动段属性设置
	//
	pIVAMCSManeuver->SetManeuverType(eVAManeuverTypeImpulsive);
	IVAManeuverImpulsive* pIVAManeuverImpulsive = (IVAManeuverImpulsive*)pIVAMCSManeuver->GetManeuver();
	IVAAttitudeControlImpulsiveThrustVector* pIVAAttitudeControlImpulsiveThrustVector = (IVAAttitudeControlImpulsiveThrustVector*)pIVAManeuverImpulsive->GetAttitudeControl();
	pIVAAttitudeControlImpulsiveThrustVector->SetThrustAxesName("Satellite VNC(Earth)");
	pIVAMCSManeuver->EnableControlParameter(eVAControlManeuverImpulsiveCartesianX);
	pIVAMCSManeuver->GetResults()->Add("Radius_Of_Apoapsis");

	//
	//第一个瞄准段添加属性页
	//
	IVAProfileDifferentialCorrector* pIVAProfileDifferentialCorrector1 = (IVAProfileDifferentialCorrector*)pIVAMCSTargetSequence->GetProfiles()->Add("Differential Corrector");
	IVADCControl* pIVADCControl = pIVAProfileDifferentialCorrector1->GetControlParameters()->GetControlByPaths("Maneuver", "ImpulseX");
	IVADCResult* pIVADCResult = pIVAProfileDifferentialCorrector1->GetResults()->GetResultByPaths("Maneuver", "StateCalcRadiusOfApoapsis");
	//
	//属性页中控制变量属性设置
	//
	pIVADCControl->SetEnable(true);
	pIVADCControl->SetMaxStep(100);
	pIVADCControl->SetCorrection(2781.50365947627);
	pIVADCControl->SetPerturbation(0.1);
	pIVADCControl->SetScalingValue(1);
	//
	//属性页中约束条件属性设置
	//
	pIVADCResult->SetEnable(true);
	pIVADCResult->SetDesiredValue(84328394);
	pIVADCResult->SetScalingValue(1);
	pIVADCResult->SetTolerance(0.1);
	pIVADCResult->SetWeight(1);

	//
	//第二个预报段属性设置
	//
	IVAStoppingConditionElement* pIVAStoppingConditionElement1 = pIVAMCSPropagate1->GetStoppingConditions()->Add("RMagnitude");
	IVAStoppingCondition* pIVAStoppingCondition1 = (IVAStoppingCondition*)pIVAStoppingConditionElement1->GetProperties();
	pIVAStoppingCondition1->SetTrip(42164197);
	pIVAStoppingCondition1->SetTolerance(1e-6);
	pIVAStoppingCondition1->SetRepeatCount(1);
	pIVAStoppingCondition1->SetCriterion(eVACriterionCrossEither);

	//
	//第二个瞄准段中机动段属性设置
	//
	pIVAMCSManeuver1->SetManeuverType(eVAManeuverTypeImpulsive);
	IVAManeuverImpulsive* pIVAManeuverImpulsive1 = (IVAManeuverImpulsive*)pIVAMCSManeuver1->GetManeuver();
	IVAAttitudeControlImpulsiveThrustVector* pIVAAttitudeControlImpulsiveThrustVector1 = (IVAAttitudeControlImpulsiveThrustVector*)pIVAManeuverImpulsive1->GetAttitudeControl();
	pIVAAttitudeControlImpulsiveThrustVector1->SetThrustAxesName("Satellite VNC(Earth)");
	pIVAMCSManeuver1->EnableControlParameter(eVAControlManeuverImpulsiveCartesianX);
	pIVAMCSManeuver1->EnableControlParameter(eVAControlManeuverImpulsiveCartesianZ);
	pIVAMCSManeuver1->GetResults()->Add("Eccentricity");
	pIVAMCSManeuver1->GetResults()->Add("Cosine_of_Vertical_FPA");

	//
	//第二个瞄准段添加属性页
	//
	IVAProfileDifferentialCorrector* pIVAProfileDifferentialCorrector11 = (IVAProfileDifferentialCorrector*)pIVAMCSTargetSequence1->GetProfiles()->Add("Differential Corrector");
	//
	//属性页中控制变量属性设置
	//
	IVADCControl* pIVADCControl1 = pIVAProfileDifferentialCorrector11->GetControlParameters()->Item(0);
	pIVADCControl1->SetEnable(true);
	pIVADCControl1->SetMaxStep(300);
	pIVADCControl1->SetCorrection(1525.77028425155);
	pIVADCControl1->SetPerturbation(0.1);
	pIVADCControl1->SetScalingValue(1);
	IVADCControl* pIVADCControl2 = pIVAProfileDifferentialCorrector11->GetControlParameters()->Item(1);
	pIVADCControl2->SetEnable(true);
	pIVADCControl2->SetMaxStep(300);
	pIVADCControl2->SetCorrection(2538.06226518692);
	pIVADCControl2->SetPerturbation(0.1);
	pIVADCControl2->SetScalingValue(1);
	//
	//属性页中约束条件属性设置
	//
	IVADCResult* pIVADCResult1 = pIVAProfileDifferentialCorrector11->GetResults()->Item(0);
	pIVADCResult1->SetEnable(true);
	pIVADCResult1->SetDesiredValue(0);
	pIVADCResult1->SetScalingValue(1);
	pIVADCResult1->SetTolerance(0.1);
	pIVADCResult1->SetWeight(1);
	IVADCResult* pIVADCResult2 = pIVAProfileDifferentialCorrector11->GetResults()->Item(1);
	pIVADCResult2->SetEnable(true);
	pIVADCResult2->SetDesiredValue(0);
	pIVADCResult2->SetScalingValue(1);
	pIVADCResult2->SetTolerance(0.1);
	pIVADCResult2->SetWeight(1);

	//
	//第三个预报段属性设置
	//
	IVAStoppingConditionElement* pIVAStoppingConditionElement2 = pIVAMCSPropagate2->GetStoppingConditions()->Add("Duration");
	IVAStoppingCondition* pIVAStoppingCondition2 = (IVAStoppingCondition*)pIVAStoppingConditionElement2->GetProperties();
	pIVAStoppingCondition2->SetTrip(86400);
	pIVAStoppingCondition2->SetTolerance(0.0001);

	//
	//机动规划运行
	//
	pIVADriverMCS->RunMCS();
	pIVADriverMCS->ApplyAllProfileChanges();

	//
	//生成数据到文件
	//
	std::string strReportFilePath = pRoot->OutputDataReport(pISatellite, "J2000 Position Velocity", "5 Nov 2022 00:00:00.000", "6 Nov 2022 00:00:00.000");
	std::cout << "报告文件位置： " << strReportFilePath << std::endl;

	//
	//想定保存及关闭
	//
	pRoot->SaveScenario();
	pRoot->CloseScenario();

	delete pRoot;
	pRoot = nullptr;
	system("Pause");
}

```
