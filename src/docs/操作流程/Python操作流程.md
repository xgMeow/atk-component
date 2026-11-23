\page component_flow_python Python 操作流程

Python 通过接口模块 ATKComponentPythonModule 使用 Component 模式：先准备 Python 3.8 运行环境，再复制案例脚本、依赖库与 AstroData 数据到当前目录，最后运行案例脚本。

## 一、案例介绍

本案例实现半径为6700km的近地停泊轨道（LEO轨道）快速转移到半径为42164.197km的地球同步轨道（GEO轨道）的轨道机动规划设计。案例基于Component模式调用，通过 Python 3.8.0 测试运行。

### 运行环境

案例脚本需由 Python 3.8 解释运行：Windows 下使用 `python` 命令，Linux 下使用 `python3.8` 命令；系统中存在多个 Python 版本时，需显式指定 3.8 版本。ATK 安装目录 `IntegratingWithATK/python-3.8.0-embed-amd64` 下提供了嵌入式 Python 3.8 解释器 python.exe，也可直接使用。

\image html python-intro-2.png "嵌入式Python解释器文件"

### 依赖文件

- `ATKComponentPythonModule.py`，ATKComponent模式接口文件，提供Component模式下所有公用类对象与函数的接口模块，在Python案例脚本中导入该模块后，就能调用这些公用的类对象与函数；由步骤 2 的依赖复制命令复制到当前目录。

- `_ATKComponentPythonModule.pyd`，ATKComponent模式动态库，供接口模块调用，包含Component模式下所有公用类对象与函数的具体实现；由步骤 2 的依赖复制命令复制到当前目录，Linux 下为对应的动态库文件。

- `ATKComponentPythonTest.py`，Python案例脚本，位于 `ATK安装根目录/Help/Examples/08-二次开发案例`，需复制到当前目录（见步骤 1）。包含一个轨道快速转移案例的具体实现过程，由 Python 3.8 解释运行。如果脚本包含中文或者目录包含中文，需要先设置文件为UTF-8无BOM编码格式，再编辑案例代码。

## 二、操作步骤

以下步骤均在同一工作目录中完成（下文称当前目录），本文以 `ATK安装根目录\IntegratingWithATK\component` 作为该目录；命令中的 `ATK安装根目录` 需替换为实际安装路径。

### 1. 复制案例脚本

将参考案例文件 `ATK安装根目录/Help/Examples/08-二次开发案例/ATKComponentPythonTest.py` 复制到当前目录。

Windows（cmd）：

```bat
copy "ATK安装根目录\Help\Examples\08-二次开发案例\ATKComponentPythonTest.py" .
```

Linux：

```sh
cp "ATK安装根目录/Help/Examples/08-二次开发案例/ATKComponentPythonTest.py" .
```

案例脚本会将所在目录加入 Python 的系统路径以导入接口模块，依赖文件需与脚本位于同一目录；AstroData 需位于运行命令时的当前目录。脚本含中文注释，文件需保持 UTF-8 无 BOM 编码。

### 2. 复制依赖库

在 `ATK安装根目录\IntegratingWithATK\component` 目录中执行以下命令，将 Python 案例所需的依赖库复制到当前目录。

Windows（cmd）：

```bat
.\GetAllDeps.bat "Python"
```

Linux：

```sh
sed -i 's/\r$//' GetAllDeps.sh && ./GetAllDeps.sh Python
```

复制出的依赖文件主要包括：

- `ATKComponentPythonModule.py`：ATK Component 模式接口模块，提供 Component 模式下所有公用类对象与函数的接口封装。
- `_ATKComponentPythonModule.pyd`：ATK Component 模式动态库，供接口模块调用，包含 Component 模式下所有公用类对象与函数的具体实现；Linux 下为对应的动态库文件。
- `AstroLib.dll` 等其他 Component 模式运行所需的依赖动态库。

\image html python-intro-1.png "依赖文件"

### 3. 复制 AstroData

将 `ATK安装根目录/AstroData` 文件夹复制到当前目录。AstroData 为 ATK 仿真所需的星历与天文数据，缺失时无法正常创建场景与卫星对象。

Windows（cmd）：

```bat
xcopy "ATK安装根目录\AstroData" ".\AstroData" /e /i /y
```

Linux：

```sh
cp -r "ATK安装根目录/AstroData" .
```

### 4. 运行

在当前目录运行案例脚本。

Windows（cmd）：

```bat
python ATKComponentPythonTest.py
```

Linux：

```sh
python3.8 ATKComponentPythonTest.py
```

案例在 Python 3.8.0 下测试通过，请使用 Python 3.8 运行；Linux 下系统存在多个 Python 版本时，需按上面的命令显式使用 `python3.8`，避免 `python` 指向其他版本导致接口模块导入失败。若不希望单独安装 Python，Windows 下也可使用 ATK 自带的嵌入式解释器，将命令中的 `python` 替换为 `..\python-3.8.0-embed-amd64\python.exe`。

## 三、案例实现

本案例使用Python脚本实现，通过在案例脚本中导入ATKComponent模式接口模块ATKComponentPythonModule，调用接口模块中公用的类接口与函数接口，完成场景与卫星类对象的新建与设置，动画的仿真运行，数据报告与想定文件的输出保存。最后通过 Python 3.8 解释器运行该案例脚本，完成案例实现。具体流程如下所示。

### 案例流程图

\image html python-impl-1.png "Python案例流程图"

### 案例源码

案例源码即步骤 1 中复制的 `ATKComponentPythonTest.py`，包含一个轨道快速转移案例的具体实现过程。运行案例时直接使用该文件即可，无需手动输入；其内容如下（以 ATK 安装目录中的案例文件为准）。

```py
#ATKComponentPythonTest.py
# -*- coding: utf-8 -*-

#1，使用内嵌式python解释器时，需要将当前路径加入Python系统环境路径
import sys
import os
curPath = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0,curPath)

#2，导入ATKComponent模式接口模块，并取个简短的别名
import ATKComponentPythonModule as ATKModule
	
#3，设置保存文件的基础路径和调用语言，用来兼容处理不同系统/模式/语言情况下，输出位置不统一的问题
ATKModule.SetSaveFileBasePath(curPath);
ATKModule.SetCallCodeType("python");

#倾角转换实现函数
def TestInclinationChange(pIAtkObjectRoot):
	#新建场景
	pIScenario = pIAtkObjectRoot.GetChildren().New(ATKModule.eScenario, "InclinationChange");
	pIScenario.SetTimePeriod("5 Nov 2022 00:00:00.000", "8 Nov 2022 00:00:00.000");
	#新建卫星
	pISatellite = pIScenario.GetChildren().New(ATKModule.eSatellite, "SatInclinationChange");

	#设置二维属性轨迹显示时长
	pIVeGfxLeadTrailData = pISatellite.GetGraphics().GetPassData().GetGroundTrack();
	pIVeGfxLeadTrailData.SetTrailDataType(ATKModule.eDataTime);
	pIVeLeadTrailDataTime = pIVeGfxLeadTrailData.GetTrailData();
	pIVeLeadTrailDataTime.SetTime(24*60*60);
	
	pISatellite.SetPropagatorType(ATKModule.ePropagatorAstromaster);
	pIVADriverMCS = pISatellite.GetPropagator();
	pIVAMCSSegmentCollection = pIVADriverMCS.GetMainSequence();
	
	if (ATKModule.eVASegmentTypeInitialState != pIVAMCSSegmentCollection.Item(0).GetType()):
		return;
	pIVAMCSInitialState = pIVAMCSSegmentCollection.Item(0);
	
	pIVAMCSPropagate = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypePropagate, "Propagate", "-");
	pIVAMCSTargetSequence = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypeTargetSequence, "TargetSequence", "-");
	pIVAMCSSegmentCollection0 = pIVAMCSTargetSequence.GetSegments();
	pIVAMCSManeuver = pIVAMCSSegmentCollection0.Insert(ATKModule.eVASegmentTypeManeuver, "Maneuver", "-");
	
	pIVAMCSPropagate1 = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypePropagate, "Propagate1", "-");
	pIVAMCSTargetSequence1 = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypeTargetSequence, "TargetSequence1", "-");
	pIVAMCSSegmentCollection1 = pIVAMCSTargetSequence1.GetSegments();
	pIVAMCSManeuver1 = pIVAMCSSegmentCollection1.Insert(ATKModule.eVASegmentTypeManeuver, "Maneuver", "-");
	
	pIVAMCSPropagate2 = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypePropagate, "Propagate2", "-");
	pIVAMCSTargetSequence2 = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypeTargetSequence, "TargetSequence2", "-");
	pIVAMCSSegmentCollection2 = pIVAMCSTargetSequence2.GetSegments();
	pIVAMCSManeuver2 = pIVAMCSSegmentCollection2.Insert(ATKModule.eVASegmentTypeManeuver, "Maneuver", "-");
	
	pIVAMCSPropagate3 = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypePropagate, "Propagate3", "-");
	
	pIVAMCSInitialState.SetOrbitEpoch("5 Nov 2022 00:00:00.000");
	pIVAMCSInitialState.SetElementType(ATKModule.eVAElementTypeKeplerian);
	pIVAElementKeplerian = pIVAMCSInitialState.GetElement();
	pIVAElementKeplerian.SetSemiMajorAxis(6570000);
	pIVAElementKeplerian.SetEccentricity(0);
	pIVAElementKeplerian.SetInclination(28);
	pIVAElementKeplerian.SetRAAN(0);
	pIVAElementKeplerian.SetArgOfPeriapsis(0);
	pIVAElementKeplerian.SetTrueAnomaly(0);
	
	pIVAStoppingConditionElement = pIVAMCSPropagate.GetStoppingConditions().Add("Duration");
	pIVAStoppingCondition = pIVAStoppingConditionElement.GetProperties();
	pIVAStoppingCondition.SetTrip(7200);
	pIVAStoppingCondition.SetTolerance(0.0001);

	pIVAMCSManeuver.SetManeuverType(ATKModule.eVAManeuverTypeImpulsive);
	pIVAManeuverImpulsive = pIVAMCSManeuver.GetManeuver();
	pIVAAttitudeControlImpulsiveThrustVector = pIVAManeuverImpulsive.GetAttitudeControl();
	pIVAAttitudeControlImpulsiveThrustVector.SetThrustAxesName("Satellite VNC(Earth)");
	pIVAMCSManeuver.EnableControlParameter(ATKModule.eVAControlManeuverImpulsiveCartesianX);
	pIVAMCSManeuver.GetResults().Add("Radius_Of_Apoapsis");
	
	pIVAProfileDifferentialCorrector = pIVAMCSTargetSequence.GetProfiles().Add("Differential Corrector");
	pIVADCControl = pIVAProfileDifferentialCorrector.GetControlParameters().GetControlByPaths("Maneuver", "ImpulseX");
	pIVADCResult = pIVAProfileDifferentialCorrector.GetResults().GetResultByPaths("Maneuver", "StateCalc"+"RadiusOfApoapsis");
	pIVADCControl = pIVAProfileDifferentialCorrector.GetControlParameters().Item(0);
	pIVADCControl.SetEnable(True);
	pIVADCControl.SetMaxStep(100);
	#pIVADCControl.SetCorrection(2456.42862556706);
	pIVADCControl.SetPerturbation(0.1);
	pIVADCControl.SetScalingValue(1);
	pIVADCResult = pIVAProfileDifferentialCorrector.GetResults().Item(0);
	pIVADCResult.SetEnable(True);
	pIVADCResult.SetDesiredValue(42160000);
	pIVADCResult.SetScalingValue(1);
	pIVADCResult.SetTolerance(0.1);
	pIVADCResult.SetWeight(1);

	pIVAStoppingConditionElement1 = pIVAMCSPropagate1.GetStoppingConditions().Add("Apoapsis");
	pIVAStoppingCondition1 = pIVAStoppingConditionElement1.GetProperties();
	pIVAStoppingCondition1.SetTolerance(0.0001);
	pIVAStoppingCondition1.SetRepeatCount(1);

	pIVAMCSManeuver1.SetManeuverType(ATKModule.eVAManeuverTypeImpulsive);
	pIVAManeuverImpulsive1 = pIVAMCSManeuver1.GetManeuver();
	pIVAAttitudeControlImpulsiveThrustVector1 = pIVAManeuverImpulsive1.GetAttitudeControl();
	pIVAAttitudeControlImpulsiveThrustVector1.SetThrustAxesName("Satellite VNC(Earth)");
	pIVAMCSManeuver1.EnableControlParameter(ATKModule.eVAControlManeuverImpulsiveCartesianX);
	pIVAMCSManeuver1.GetResults().Add("Eccentricity");

	pIVAProfileDifferentialCorrector1 = pIVAMCSTargetSequence1.GetProfiles().Add("Differential Corrector");
	pIVADCControl1 = pIVAProfileDifferentialCorrector1.GetControlParameters().Item(0);
	pIVADCControl1.SetEnable(True);
	pIVADCControl1.SetMaxStep(100);
	pIVADCControl1.SetCorrection(1480.06329844802);
	pIVADCControl1.SetPerturbation(0.1);
	pIVADCControl1.SetScalingValue(1);
	pIVADCResult1 = pIVAProfileDifferentialCorrector1.GetResults().Item(0);
	pIVADCResult1.SetEnable(True);
	pIVADCResult1.SetDesiredValue(0);
	pIVADCResult1.SetScalingValue(1);
	pIVADCResult1.SetTolerance(0.001);
	pIVADCResult1.SetWeight(1);

	pIVAStoppingConditionElement2 = pIVAMCSPropagate2.GetStoppingConditions().Add("AscendingNode");
	pIVAStoppingCondition2 = pIVAStoppingConditionElement2.GetProperties();
	pIVAStoppingCondition2.SetRepeatCount(2);
	pIVAStoppingCondition2.SetTolerance(1e-6);

	pIVAMCSManeuver2.SetManeuverType(ATKModule.eVAManeuverTypeImpulsive);
	pIVAManeuverImpulsive2 = pIVAMCSManeuver2.GetManeuver();
	pIVAAttitudeControlImpulsiveThrustVector2 = pIVAManeuverImpulsive2.GetAttitudeControl();
	pIVAAttitudeControlImpulsiveThrustVector2.SetThrustAxesName("Satellite VNC(Earth)");
	pIVAMCSManeuver2.EnableControlParameter(ATKModule.eVAControlManeuverImpulsiveCartesianX);
	pIVAMCSManeuver2.EnableControlParameter(ATKModule.eVAControlManeuverImpulsiveCartesianY);
	pIVAMCSManeuver2.GetResults().Add("Eccentricity");
	pIVAMCSManeuver2.GetResults().Add("Inclination");

	pIVAProfileDifferentialCorrector2 = pIVAMCSTargetSequence2.GetProfiles().Add("Differential Corrector");
	pIVADCControl2 = pIVAProfileDifferentialCorrector2.GetControlParameters().Item(0);
	pIVADCControl2.SetEnable(True);
	pIVADCControl2.SetMaxStep(100);
	pIVADCControl2.SetCorrection(-359.983751789857);
	pIVADCControl2.SetPerturbation(0.1);
	pIVADCControl2.SetScalingValue(1);
	pIVADCControl3 = pIVAProfileDifferentialCorrector2.GetControlParameters().Item(1);
	pIVADCControl3.SetEnable(True);
	pIVADCControl3.SetMaxStep(100);
	pIVADCControl3.SetCorrection(-1444.72488992759);
	pIVADCControl3.SetPerturbation(0.1);
	pIVADCControl3.SetScalingValue(1);
	pIVADCResult2 = pIVAProfileDifferentialCorrector2.GetResults().Item(0);
	pIVADCResult2.SetEnable(True);
	pIVADCResult2.SetDesiredValue(0);
	pIVADCResult2.SetScalingValue(1);
	pIVADCResult2.SetTolerance(0);
	pIVADCResult2.SetWeight(1);
	pIVADCResult3 = pIVAProfileDifferentialCorrector2.GetResults().Item(1);
	pIVADCResult3.SetEnable(True);
	pIVADCResult3.SetDesiredValue(0);
	pIVADCResult3.SetScalingValue(1);
	pIVADCResult3.SetTolerance(0.001);
	pIVADCResult3.SetWeight(1);
	
	pIVAStoppingConditionElement3 = pIVAMCSPropagate3.GetStoppingConditions().Add("Duration");
	pIVAStoppingCondition3 = pIVAStoppingConditionElement3.GetProperties();
	pIVAStoppingCondition3.SetTrip(129600);
	pIVAStoppingCondition3.SetTolerance(1e-5);

	pIVADriverMCS.RunMCS();
	pIVADriverMCS.ApplyAllProfileChanges();

#霍曼转移实现函数
def TestHohmannTransfer(pIAtkObjectRoot):
	#新建场景
	pIScenario = pIAtkObjectRoot.GetChildren().New(ATKModule.eScenario, "HohmannTransfer");
	pIScenario.SetTimePeriod("5 Nov 2022 00:00:00.000", "7 Nov 2022 00:00:00.000");
	#新建卫星
	pISatellite = pIScenario.GetChildren().New(ATKModule.eSatellite, "Sat_Hohmann");

	#设置二维属性轨迹显示时长
	pIVeGfxLeadTrailData = pISatellite.GetGraphics().GetPassData().GetGroundTrack();
	pIVeGfxLeadTrailData.SetTrailDataType(ATKModule.eDataTime);
	pIVeLeadTrailDataTime = pIVeGfxLeadTrailData.GetTrailData();
	pIVeLeadTrailDataTime.SetTime(24*60*60);
	
	pISatellite.SetPropagatorType(ATKModule.ePropagatorAstromaster);
	pIVADriverMCS = pISatellite.GetPropagator();
	pIVAMCSSegmentCollection = pIVADriverMCS.GetMainSequence();

	if (ATKModule.eVASegmentTypeInitialState != pIVAMCSSegmentCollection.Item(0).GetType()):
		return;
	pIVAMCSInitialState = pIVAMCSSegmentCollection.Item(0);
	pIVAMCSPropagate = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypePropagate, "Propagate", "-");
	pIVAMCSTargetSequence = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypeTargetSequence, "TargetSequence", "-");
	pIVAMCSManeuver = pIVAMCSTargetSequence.GetSegments().Insert(ATKModule.eVASegmentTypeManeuver, "Maneuver", "-");
	pIVAMCSPropagate1 = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypePropagate, "Propagate1", "-");
	pIVAMCSTargetSequence1 = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypeTargetSequence, "TargetSequence1", "-");
	pIVAMCSManeuver1 = pIVAMCSTargetSequence1.GetSegments().Insert(ATKModule.eVASegmentTypeManeuver, "Maneuver", "-");
	pIVAMCSPropagate2 = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypePropagate, "Propagate2", "-");

	pIVAMCSInitialState.SetOrbitEpoch("5 Nov 2022 00:00:00.000");
	pIVAMCSInitialState.SetElementType(ATKModule.eVAElementTypeKeplerian);
	pIVAElementKeplerian = pIVAMCSInitialState.GetElement();
	pIVAElementKeplerian.SetSemiMajorAxis(6700000);
	pIVAElementKeplerian.SetEccentricity(0);
	pIVAElementKeplerian.SetInclination(28);
	pIVAElementKeplerian.SetRAAN(0);
	pIVAElementKeplerian.SetArgOfPeriapsis(0);
	pIVAElementKeplerian.SetTrueAnomaly(0);

	pIVAStoppingConditionElement = pIVAMCSPropagate.GetStoppingConditions().Add("Duration");
	pIVAStoppingCondition = pIVAStoppingConditionElement.GetProperties();
	pIVAStoppingCondition.SetTrip(7200);
	pIVAStoppingCondition.SetTolerance(0.0001);

	pIVAMCSManeuver.SetManeuverType(ATKModule.eVAManeuverTypeImpulsive);
	pIVAManeuverImpulsive = pIVAMCSManeuver.GetManeuver();
	pIVAAttitudeControlImpulsiveThrustVector = pIVAManeuverImpulsive.GetAttitudeControl();
	pIVAAttitudeControlImpulsiveThrustVector.SetThrustAxesName("Satellite VNC(Earth)");
	pIVAMCSManeuver.EnableControlParameter(ATKModule.eVAControlManeuverImpulsiveCartesianX);
	pIVAMCSManeuver.GetResults().Add("Radius_Of_Apoapsis");

	pIVAProfileDifferentialCorrector = pIVAMCSTargetSequence.GetProfiles().Add("Differential Corrector");
	pIVADCControl = pIVAProfileDifferentialCorrector.GetControlParameters().GetControlByPaths("Maneuver", "ImpulseX");
	pIVADCResult = pIVAProfileDifferentialCorrector.GetResults().GetResultByPaths("Maneuver", "StateCalc"+"RadiusOfApoapsis");
	pIVADCControl = pIVAProfileDifferentialCorrector.GetControlParameters().Item(0);
	pIVADCControl.SetEnable(True);
	pIVADCControl.SetMaxStep(100);
	pIVADCControl.SetPerturbation(0.1);
	pIVADCControl.SetScalingValue(1);
	pIVADCResult = pIVAProfileDifferentialCorrector.GetResults().Item(0);
	pIVADCResult.SetEnable(True);
	pIVADCResult.SetDesiredValue(42238000);
	pIVADCResult.SetScalingValue(1);
	pIVADCResult.SetTolerance(0.1);
	pIVADCResult.SetWeight(1);

	pIVAStoppingConditionElement1 = pIVAMCSPropagate1.GetStoppingConditions().Add("Apoapsis");
	pIVAStoppingCondition1 = pIVAStoppingConditionElement1.GetProperties();
	pIVAStoppingCondition1.SetTolerance(0.0001);
	pIVAStoppingCondition1.SetRepeatCount(1);
	pIVAStoppingCondition1.SetCentralBodyName("Earth");

	pIVAMCSManeuver1.SetManeuverType(ATKModule.eVAManeuverTypeImpulsive);
	pIVAManeuverImpulsive1 = pIVAMCSManeuver1.GetManeuver();
	pIVAAttitudeControlImpulsiveThrustVector1 = pIVAManeuverImpulsive1.GetAttitudeControl();
	pIVAAttitudeControlImpulsiveThrustVector1.SetThrustAxesName("Satellite VNC(Earth)");
	pIVAMCSManeuver1.EnableControlParameter(ATKModule.eVAControlManeuverImpulsiveCartesianX);
	pIVAMCSManeuver1.GetResults().Add("Eccentricity");

	pIVAProfileDifferentialCorrector1 = pIVAMCSTargetSequence1.GetProfiles().Add("Differential Corrector");
	pIVADCControl1 = pIVAProfileDifferentialCorrector1.GetControlParameters().Item(0);
	pIVADCControl1.SetEnable(True);
	pIVADCControl1.SetMaxStep(100);
	pIVADCControl1.SetPerturbation(0.1);
	pIVADCControl1.SetScalingValue(1);
	pIVADCResult1 = pIVAProfileDifferentialCorrector1.GetResults().Item(0);
	pIVADCResult1.SetEnable(True);
	pIVADCResult1.SetDesiredValue(0);
	pIVADCResult1.SetScalingValue(1);
	pIVADCResult1.SetTolerance(0.001);
	pIVADCResult1.SetWeight(1);

	pIVAStoppingConditionElement2 = pIVAMCSPropagate2.GetStoppingConditions().Add("Duration");
	pIVAStoppingCondition2 = pIVAStoppingConditionElement2.GetProperties();
	pIVAStoppingCondition2.SetTrip(86400);
	pIVAStoppingCondition2.SetTolerance(0.0001);

	pIVADriverMCS.RunMCS();
	pIVADriverMCS.ApplyAllProfileChanges();

#轨道快速转移实现函数
def TestFastTransfer(pIAtkObjectRoot):
	#1，场景新建与属性设置
	pIScenario = pIAtkObjectRoot.GetChildren().New(ATKModule.eScenario, "FastTransfer");
	pIScenario.SetTimePeriod("5 Nov 2022 00:00:00.000", "6 Nov 2022 00:00:00.000");
	#2，卫星新建与轨道预报设置为机动规划
	pISatellite = pIScenario.GetChildren().New(ATKModule.eSatellite, "Satellite1");
	#设置二维属性轨迹显示时长
	pIVeGfxLeadTrailData = pISatellite.GetGraphics().GetPassData().GetGroundTrack();
	pIVeGfxLeadTrailData.SetTrailDataType(ATKModule.eDataTime);
	pIVeLeadTrailDataTime = pIVeGfxLeadTrailData.GetTrailData();
	pIVeLeadTrailDataTime.SetTime(24*60*60);
	pISatellite.SetPropagatorType(ATKModule.ePropagatorAstromaster);
	pIVADriverMCS = pISatellite.GetPropagator();
	pIVAMCSSegmentCollection = pIVADriverMCS.GetMainSequence();
	#3，机动规划添加段，新添加卫星会有默认初始段
	if (ATKModule.eVASegmentTypeInitialState != pIVAMCSSegmentCollection.Item(0).GetType()):
		return;
	pIVAMCSInitialState = pIVAMCSSegmentCollection.Item(0);
	pIVAMCSPropagate = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypePropagate, "Propagate", "-");
	pIVAMCSTargetSequence = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypeTargetSequence, "TargetSequence", "-");
	pIVAMCSManeuver = pIVAMCSTargetSequence.GetSegments().Insert(ATKModule.eVASegmentTypeManeuver, "Maneuver", "-");
	pIVAMCSPropagate1 = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypePropagate, "Propagate", "-");
	pIVAMCSTargetSequence1 = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypeTargetSequence, "TargetSequence1", "-");
	pIVAMCSManeuver1 = pIVAMCSTargetSequence1.GetSegments().Insert(ATKModule.eVASegmentTypeManeuver, "Maneuver", "-");
	pIVAMCSPropagate2 = pIVAMCSSegmentCollection.Insert(ATKModule.eVASegmentTypePropagate, "Propagate", "-");
	#4，初始段属性设置
	pIVAMCSInitialState.SetOrbitEpoch("5 Nov 2022 00:00:00.000");
	pIVAMCSInitialState.SetElementType(ATKModule.eVAElementTypeKeplerian);
	pIVAElementKeplerian = pIVAMCSInitialState.GetElement();
	pIVAElementKeplerian.SetSemiMajorAxis(6700000);
	pIVAElementKeplerian.SetEccentricity(0);
	pIVAElementKeplerian.SetInclination(0);
	pIVAElementKeplerian.SetRAAN(0);
	pIVAElementKeplerian.SetArgOfPeriapsis(0);
	pIVAElementKeplerian.SetTrueAnomaly(0);
	#5，第一个预报段属性设置
	pIVAStoppingConditionElement = pIVAMCSPropagate.GetStoppingConditions().Add("Duration");
	pIVAStoppingCondition = pIVAStoppingConditionElement.GetProperties();
	pIVAStoppingCondition.SetTrip(7200);
	pIVAStoppingCondition.SetTolerance(0.0001);
	#6，第一个瞄准段中机动段属性设置
	pIVAMCSManeuver.SetManeuverType(ATKModule.eVAManeuverTypeImpulsive);
	pIVAManeuverImpulsive = pIVAMCSManeuver.GetManeuver();
	pIVAAttitudeControlImpulsiveThrustVector = pIVAManeuverImpulsive.GetAttitudeControl();
	pIVAAttitudeControlImpulsiveThrustVector.SetThrustAxesName("Satellite VNC(Earth)");
	pIVAMCSManeuver.EnableControlParameter(ATKModule.eVAControlManeuverImpulsiveCartesianX);
	pIVAMCSManeuver.GetResults().Add("Radius_Of_Apoapsis");
	#7，第一个瞄准段添加属性页
	pIVAProfileDifferentialCorrector = pIVAMCSTargetSequence.GetProfiles().Add("Differential Corrector");
	pIVADCControl = pIVAProfileDifferentialCorrector.GetControlParameters().GetControlByPaths("Maneuver", "ImpulseX");
	pIVADCResult = pIVAProfileDifferentialCorrector.GetResults().GetResultByPaths("Maneuver", "StateCalc"+"RadiusOfApoapsis");
	#8，属性页中控制变量属性设置
	pIVADCControl.SetEnable(True);
	pIVADCControl.SetMaxStep(100);
	#pIVADCControl.SetCorrection(2781.50365947627);
	pIVADCControl.SetPerturbation(0.1);
	pIVADCControl.SetScalingValue(1);
	#9，属性页中约束条件属性设置
	pIVADCResult.SetEnable(True);
	pIVADCResult.SetDesiredValue(84328394);
	pIVADCResult.SetScalingValue(1);
	pIVADCResult.SetTolerance(0.1);
	pIVADCResult.SetWeight(1);
	#10，第二个预报段属性设置
	pIVAStoppingConditionElement1 = pIVAMCSPropagate1.GetStoppingConditions().Add("RMagnitude");
	pIVAStoppingCondition1 = pIVAStoppingConditionElement1.GetProperties();
	pIVAStoppingCondition1.SetTrip(42164197);
	pIVAStoppingCondition1.SetTolerance(1e-6);
	pIVAStoppingCondition1.SetRepeatCount(1);
	pIVAStoppingCondition1.SetCriterion(ATKModule.eVACriterionCrossEither);
	#11，第二个瞄准段中机动段属性设置
	pIVAMCSManeuver1.SetManeuverType(ATKModule.eVAManeuverTypeImpulsive);
	pIVAManeuverImpulsive1 = pIVAMCSManeuver1.GetManeuver();
	pIVAAttitudeControlImpulsiveThrustVector1 = pIVAManeuverImpulsive1.GetAttitudeControl();
	pIVAAttitudeControlImpulsiveThrustVector1.SetThrustAxesName("Satellite VNC(Earth)");
	pIVAMCSManeuver1.EnableControlParameter(ATKModule.eVAControlManeuverImpulsiveCartesianX);
	pIVAMCSManeuver1.EnableControlParameter(ATKModule.eVAControlManeuverImpulsiveCartesianZ);
	pIVAMCSManeuver1.GetResults().Add("Eccentricity");
	pIVAMCSManeuver1.GetResults().Add("Cosine_of_Vertical_FPA");
	#12，第二个瞄准段添加属性页
	pIVAProfileDifferentialCorrector1 = pIVAMCSTargetSequence1.GetProfiles().Add("Differential Corrector");
	#13，属性页中控制变量属性设置
	pIVADCControl1 = pIVAProfileDifferentialCorrector1.GetControlParameters().Item(0);
	pIVADCControl1.SetEnable(True);
	pIVADCControl1.SetMaxStep(300);
	pIVADCControl1.SetCorrection(-1581.97670664023);
	pIVADCControl1.SetPerturbation(0.1);
	pIVADCControl1.SetScalingValue(1);
	pIVADCControl2 = pIVAProfileDifferentialCorrector1.GetControlParameters().Item(1);
	pIVADCControl2.SetEnable(True);
	pIVADCControl2.SetMaxStep(300);
	pIVADCControl2.SetCorrection(-2771.82057041661);
	pIVADCControl2.SetPerturbation(0.1);
	pIVADCControl2.SetScalingValue(1);
	#14，属性页中约束条件属性设置
	pIVADCResult1 = pIVAProfileDifferentialCorrector1.GetResults().Item(0);
	pIVADCResult1.SetEnable(True);
	pIVADCResult1.SetDesiredValue(0);
	pIVADCResult1.SetScalingValue(1);
	pIVADCResult1.SetTolerance(0.1);
	pIVADCResult1.SetWeight(1);
	pIVADCResult2 = pIVAProfileDifferentialCorrector1.GetResults().Item(1);
	pIVADCResult2.SetEnable(True);
	pIVADCResult2.SetDesiredValue(0);
	pIVADCResult2.SetScalingValue(1);
	pIVADCResult2.SetTolerance(0.1);
	pIVADCResult2.SetWeight(1);
	#15，第三个预报段属性设置
	pIVAStoppingConditionElement2 = pIVAMCSPropagate2.GetStoppingConditions().Add("Duration");
	pIVAStoppingCondition2 = pIVAStoppingConditionElement2.GetProperties();
	pIVAStoppingCondition2.SetTrip(86400);
	pIVAStoppingCondition2.SetTolerance(0.0001);
	#16，机动规划运行
	pIVADriverMCS.RunMCS();
	pIVADriverMCS.ApplyAllProfileChanges();
	#17，生成数据到文件
	strReportFilePath = pIAtkObjectRoot.OutputDataReport(pISatellite, "J2000 Position Velocity", "5 Nov 2022 00:00:00.000", "6 Nov 2022 00:00:00.000");
	#18，输出数据报告目录
	print("output data reports:"+strReportFilePath)

#4，新建根节点
pIAtkObjectRoot = ATKModule.IAtkObjectRoot();
#5，调用实现函数
TestFastTransfer(pIAtkObjectRoot);
#TestHohmannTransfer(pIAtkObjectRoot);
#TestInclinationChange(pIAtkObjectRoot);
#6，仿真运行
pIAtkObjectRoot.GetAnimation().PlayForward();
#7，保存场景
pIAtkObjectRoot.SaveScenario();
#8，关闭场景
pIAtkObjectRoot.CloseScenario();
```

## 四、案例结果

成功运行Python案例脚本ATKComponentPythonTest.py之后，会在cmd命令框中输出数据报告目录，效果如下图所示。

\image html python-result-1.png "cmd命令框输出"

同时生成的还有：卫星数据报告J2000 Position Velocity.txt以及轨道快速转移想定文件FastTransfer.xml。以上文件均存放在输出目录Output，如下图所示。

\image html python-result-2.png "生成的想定与数据报告"

打开ATK检查生成的想定文件，选择轨道快速转移想定文件FastTransfer.xml，点击“开始”按钮运行动画，拉动下方时间轴查看二维视图下的轨迹效果，如下图所示。

\image html python-result-3.png "二维视图下的轨道快速转移效果图"

点击ATK“三维视图”按钮切换至三维视图，查看三维效果，如下图所示。

\image html python-result-4.png "三维视图下的轨道快速转移效果图"
