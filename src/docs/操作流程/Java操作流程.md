\page component_flow_java Java 操作流程

Java 通过 ATKComponentJava.jar 与 ATKComponentJava.dll 使用 Component 模式：先安装 JDK 并配置环境变量，再复制案例脚本、依赖库与 AstroData 数据到当前目录，最后编译并运行案例脚本。

## 一、Java 安装与环境配置

JDK（Java Development Kit），官网下载地址： https://www.oracle.com/java/technologies/download

本章以 1.8.0_301 版本安装包 jdk-8u301-windows-x64.exe 为例，按默认流程安装

直接双击安装，默认安装路径`C:\Program Files\Java\jdk1.8.0_301`。

### 配置 Java 路径到系统环境变量

JAVA_HOME 设置参考路径：`C:\Program Files\Java\jdk1.8.0_301`

Path 添加路径：`%JAVA_HOME%\bin`

Path 添加路径：`%JAVA_HOME%\jre\bin`

CLASSPATH 添加路径：`.;%JAVA_HOME%\lib;%JAVA_HOME%\lib\tools.jar;`

注意，添加到Path的路径建议上移到第一行，不然可能会被电脑上其他软件里的Java环境影响。

### 系统环境变量配置过程（以 JAVA_HOME 为例）

1. 右键点击此电脑，再点击弹出框属性。
\image html java-env-1.png "打开电脑属性"
2. 点击控制面板框下系统高级设置，再点击系统属性框高级选项下的环境变量。
\image html java-env-2.png "打开系统环境变量"
3. 在弹出的环境变量框系统变量中新建（已存在则点击编辑）并输入变量名 JAVA_HOME 与 JAVA 路径，最后点击确定。
\image html java-env-3.png "新建系统环境变量"
4. 新建完变量 `JAVA_HOME` 后，再依此点击环境变量框最下方确定，以及系统属性框最下方的确定，至此，新建环境变量 `JAVA_HOME` 保存成功
\image html java-env-4.png "保存系统环境变量"

## 二、操作步骤

以下步骤均在同一工作目录中完成（下文称当前目录），本文以 `ATK安装根目录\IntegratingWithATK\component` 作为该目录；命令中的 `ATK安装根目录` 需替换为实际安装路径。

### 1. 复制案例脚本

将参考案例文件 `ATK安装根目录/Help/Examples/08-二次开发案例/ATKComponentJavaTest.java` 复制到当前目录的 `com/atk/test` 目录下。

Windows（cmd）：

```bat
mkdir com\atk\test
copy "ATK安装根目录\Help\Examples\08-二次开发案例\ATKComponentJavaTest.java" "com\atk\test\"
```

Linux：

```sh
mkdir -p com/atk/test
cp "ATK安装根目录/Help/Examples/08-二次开发案例/ATKComponentJavaTest.java" com/atk/test/
```

案例脚本的包名为 com.atk.test，因此文件必须放在 com/atk/test 目录下；若修改包名，需同步调整目录结构。脚本含中文注释，文件需保持 UTF-8 无 BOM 编码。

### 2. 复制依赖库

在 `ATK安装根目录\IntegratingWithATK\component` 目录中执行以下命令，将 Java 案例所需的依赖库复制到当前目录。

Windows（cmd）：

```bat
.\GetAllDeps.bat "Java"
```

Linux：

```sh
sed -i 's/\r$//' GetAllDeps.sh && ./GetAllDeps.sh Java
```

复制出的依赖文件主要包括：

- `ATKComponentJava.jar`：ATK Component 模式接口类封装包，提供 Component 模式下所有公用类对象与函数的接口封装。
- `ATKComponentJava.dll`：ATK Component 模式 Java 接口动态库，提供 Component 模式的 Java 调用，并链接加载同目录下的其他依赖动态库；Linux 下为对应的动态库文件。

\image html java-deps-1.png "依赖文件"

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

### 4. 编译与运行

在当前目录中编译并运行案例脚本。

Windows（cmd）：

```bat
chcp 65001
javac -cp ATKComponentJava.jar -encoding utf-8 com/atk/test/ATKComponentJavaTest.java
java "-Dfile.encoding=UTF-8" -cp ".;ATKComponentJava.jar" com/atk/test/ATKComponentJavaTest
```

Linux：

```sh
export LD_LIBRARY_PATH=$PWD
javac -cp ATKComponentJava.jar -encoding utf-8 com/atk/test/ATKComponentJavaTest.java
java -cp ".:ATKComponentJava.jar" com/atk/test/ATKComponentJavaTest
```

命令说明：

- `chcp 65001`：将 Windows 命令行代码页切换为 UTF-8，避免中文输出乱码。
- `-encoding utf-8`：指定按 UTF-8 编码读取源码，避免含中文注释的脚本编译报错。
- `-cp`：指定类路径，Windows 下多个路径用 `;` 分隔，Linux 下用 `:` 分隔。
- `-Dfile.encoding=UTF-8`：指定 Java 运行时使用 UTF-8 编码。
- `export LD_LIBRARY_PATH=$PWD`：Linux 下将当前目录加入动态库搜索路径，运行时才能加载依赖动态库。

## 三、案例实现

### 案例流程图

\image html java-case-flow-1.png "Java案例流程图"

### 案例源码

案例源码即步骤 1 中复制的 `ATKComponentJavaTest.java`，包含一个轨道快速转移案例的具体实现过程。运行案例时直接使用该文件即可，无需手动输入；其内容如下（以 ATK 安装目录中的案例文件为准）。

```java
//ATKComponentJavaTest.java
package com.atk.test;

import com.atk.component.*;

public class ATKComponentJavaTest{
  //加载ATKComponent模式动态库与依赖库
  static {
    try {
	  //windows
	  System.loadLibrary("./ATKComponentJava");
	  //linux
	  //System.load("/root/git/IAtkObject/IAtkObjectDll/build/libIAtkObjectDll.so");
    } catch (UnsatisfiedLinkError e) {
      System.err.println("load dll failed\n" + e);
      System.exit(1);
    }
  }
  
  public static void main(String []argv) {
	//设置保存路径
	String curPath = System.getProperty("user.dir");
	ATKComponentJavaModule.SetSaveFileBasePath(curPath);
	//新建根结点
	IAtkObjectRoot pIAtkObjectRoot = new IAtkObjectRoot();
	//调用轨道快速转移函数
	TestFastTransfer(pIAtkObjectRoot);
	//仿真运行
	pIAtkObjectRoot.GetAnimation().PlayForward();
	//保存场景
	pIAtkObjectRoot.SaveScenario();
	//关闭场景
	pIAtkObjectRoot.CloseScenario();
  }
  
  //轨道快速转移函数
  public static void TestFastTransfer(IAtkObjectRoot pIAtkObjectRoot){
	//场景新建与属性设置
	IScenario pIScenario = (IScenario)pIAtkObjectRoot.GetChildren().New(EATKObjectType.eScenario,"FastTransfer");
	pIScenario.SetTimePeriod("5 Nov 2022 00:00:00.000", "6 Nov 2022 00:00:00.000");
	//卫星新建与轨道预报设置为机动规划
	ISatellite pISatellite = (ISatellite)pIScenario.GetChildren().New(EATKObjectType.eSatellite,"Satellite1");
	//设置二维属性轨迹显示时长
	IVeGfxLeadTrailData pIVeGfxLeadTrailData = pISatellite.GetGraphics().GetPassData().GetGroundTrack();
	pIVeGfxLeadTrailData.SetTrailDataType(ELeadTrailData.eDataTime);
	IVeLeadTrailData pIVeLeadTrailData = pIVeGfxLeadTrailData.GetTrailData();
	IVeLeadTrailDataTime pIVeLeadTrailDataTime = (IVeLeadTrailDataTime)(pIVeGfxLeadTrailData.GetTrailData());
	pIVeLeadTrailDataTime.SetTime(24*60*60);
	pISatellite.SetPropagatorType(EVePropagatorType.ePropagatorAstromaster);
	IVADriverMCS pIVADriverMCS = (IVADriverMCS)(pISatellite.GetPropagator());
	IVAMCSSegmentCollection pIVAMCSSegmentCollection = pIVADriverMCS.GetMainSequence();
	//机动规划添加段，新添加卫星会有默认初始段
	if (EVASegmentType.eVASegmentTypeInitialState != pIVAMCSSegmentCollection.Item(0).GetType()){
		return;
	}
	IVAMCSInitialState pIVAMCSInitialState = (IVAMCSInitialState)(pIVAMCSSegmentCollection.Item(0));
	IVAMCSPropagate pIVAMCSPropagate = (IVAMCSPropagate)(pIVAMCSSegmentCollection.Insert(EVASegmentType.eVASegmentTypePropagate, "Propagate", "-"));
	IVAMCSTargetSequence pIVAMCSTargetSequence = (IVAMCSTargetSequence)(pIVAMCSSegmentCollection.Insert(EVASegmentType.eVASegmentTypeTargetSequence, "TargetSequence", "-"));
	IVAMCSManeuver pIVAMCSManeuver = (IVAMCSManeuver)(pIVAMCSTargetSequence.GetSegments().Insert(EVASegmentType.eVASegmentTypeManeuver, "Maneuver", "-"));
	IVAMCSPropagate pIVAMCSPropagate1 = (IVAMCSPropagate)(pIVAMCSSegmentCollection.Insert(EVASegmentType.eVASegmentTypePropagate, "Propagate", "-"));
	IVAMCSTargetSequence pIVAMCSTargetSequence1	= (IVAMCSTargetSequence)(pIVAMCSSegmentCollection.Insert(EVASegmentType.eVASegmentTypeTargetSequence, "TargetSequence1", "-"));
	IVAMCSManeuver pIVAMCSManeuver1 = (IVAMCSManeuver)(pIVAMCSTargetSequence1.GetSegments().Insert(EVASegmentType.eVASegmentTypeManeuver, "Maneuver", "-"));
	IVAMCSPropagate pIVAMCSPropagate2 = (IVAMCSPropagate)(pIVAMCSSegmentCollection.Insert(EVASegmentType.eVASegmentTypePropagate, "Propagate", "-"));
	//初始段属性设置
	pIVAMCSInitialState.SetOrbitEpoch("5 Nov 2022 00:00:00.000");
	pIVAMCSInitialState.SetElementType(EVAElementType.eVAElementTypeKeplerian);
	IVAElementKeplerian pIVAElementKeplerian = (IVAElementKeplerian)(pIVAMCSInitialState.GetElement());
	pIVAElementKeplerian.SetSemiMajorAxis(6700000);
	pIVAElementKeplerian.SetEccentricity(0);
	pIVAElementKeplerian.SetInclination(0);
	pIVAElementKeplerian.SetRAAN(0);
	pIVAElementKeplerian.SetArgOfPeriapsis(0);
	pIVAElementKeplerian.SetTrueAnomaly(0);
    //第一个预报段属性设置
	IVAStoppingConditionElement pIVAStoppingConditionElement = pIVAMCSPropagate.GetStoppingConditions().Add("Duration");
	IVAStoppingCondition pIVAStoppingCondition = (IVAStoppingCondition)(pIVAStoppingConditionElement.GetProperties());
	pIVAStoppingCondition.SetTrip(7200);
	pIVAStoppingCondition.SetTolerance(0.0001);
	//第一个瞄准段中机动段属性设置
	pIVAMCSManeuver.SetManeuverType(EVAManeuverType.eVAManeuverTypeImpulsive);
	IVAManeuverImpulsive pIVAManeuverImpulsive = (IVAManeuverImpulsive)(pIVAMCSManeuver.GetManeuver());
	IVAAttitudeControlImpulsiveThrustVector pIVAAttitudeControlImpulsiveThrustVector = (IVAAttitudeControlImpulsiveThrustVector)(pIVAManeuverImpulsive.GetAttitudeControl());
	pIVAAttitudeControlImpulsiveThrustVector.SetThrustAxesName("Satellite VNC(Earth)");
	pIVAMCSManeuver.EnableControlParameter(EVAControlManeuver.eVAControlManeuverImpulsiveCartesianX);
	pIVAMCSManeuver.GetResults().Add("Radius_Of_Apoapsis");
	//第一个瞄准段添加属性页
	IVAProfileDifferentialCorrector pIVAProfileDifferentialCorrector = (IVAProfileDifferentialCorrector)(pIVAMCSTargetSequence.GetProfiles().Add("Differential Corrector"));
	IVADCControl pIVADCControl = pIVAProfileDifferentialCorrector.GetControlParameters().GetControlByPaths("Maneuver", "ImpulseX");
	IVADCResult pIVADCResult = pIVAProfileDifferentialCorrector.GetResults().GetResultByPaths("Maneuver", "StateCalc"+"RadiusOfApoapsis");
	//属性页中控制变量属性设置
	pIVADCControl.SetEnable(true);
	pIVADCControl.SetMaxStep(100);
	pIVADCControl.SetCorrection(2781.50365947627);
	pIVADCControl.SetPerturbation(0.1);
	pIVADCControl.SetScalingValue(1);
	//属性页中约束条件属性设置
	pIVADCResult.SetEnable(true);
	pIVADCResult.SetDesiredValue(84328394);
	pIVADCResult.SetScalingValue(1);
	pIVADCResult.SetTolerance(0.1);
	pIVADCResult.SetWeight(1);
	//第二个预报段属性设置
	IVAStoppingConditionElement pIVAStoppingConditionElement1 = pIVAMCSPropagate1.GetStoppingConditions().Add("RMagnitude");
	IVAStoppingCondition pIVAStoppingCondition1 = (IVAStoppingCondition)(pIVAStoppingConditionElement1.GetProperties());
	pIVAStoppingCondition1.SetTrip(42164197);
	pIVAStoppingCondition1.SetTolerance(1e-6);
	pIVAStoppingCondition1.SetRepeatCount(1);
	pIVAStoppingCondition1.SetCriterion(EVACriterion.eVACriterionCrossEither);
	//第二个瞄准段中机动段属性设置
	pIVAMCSManeuver1.SetManeuverType(EVAManeuverType.eVAManeuverTypeImpulsive);
	IVAManeuverImpulsive pIVAManeuverImpulsive1 = (IVAManeuverImpulsive)(pIVAMCSManeuver1.GetManeuver());
	IVAAttitudeControlImpulsive pIVAAttitudeControlImpulsive1 = (IVAAttitudeControlImpulsive)(pIVAManeuverImpulsive1.GetAttitudeControl());
	IVAAttitudeControlImpulsiveThrustVector pIVAAttitudeControlImpulsiveThrustVector1 = (IVAAttitudeControlImpulsiveThrustVector)(pIVAAttitudeControlImpulsive1);
	pIVAAttitudeControlImpulsiveThrustVector1.SetThrustAxesName("Satellite VNC(Earth)");
	pIVAMCSManeuver1.EnableControlParameter(EVAControlManeuver.eVAControlManeuverImpulsiveCartesianX);
	pIVAMCSManeuver1.EnableControlParameter(EVAControlManeuver.eVAControlManeuverImpulsiveCartesianZ);
	pIVAMCSManeuver1.GetResults().Add("Eccentricity");
	pIVAMCSManeuver1.GetResults().Add("Cosine_of_Vertical_FPA");
    //第二个瞄准段添加属性页
	IVAProfileDifferentialCorrector pIVAProfileDifferentialCorrector1 = (IVAProfileDifferentialCorrector)(pIVAMCSTargetSequence1.GetProfiles().Add("Differential Corrector"));
	//属性页中控制变量属性设置
	IVADCControl pIVADCControl1 = pIVAProfileDifferentialCorrector1.GetControlParameters().Item(0);
	pIVADCControl1.SetEnable(true);
	pIVADCControl1.SetMaxStep(300);
	pIVADCControl1.SetCorrection(-1581.97670664023);
	pIVADCControl1.SetPerturbation(0.1);
	pIVADCControl1.SetScalingValue(1);
	IVADCControl pIVADCControl2 = pIVAProfileDifferentialCorrector1.GetControlParameters().Item(1);
	pIVADCControl2.SetEnable(true);
	pIVADCControl2.SetMaxStep(300);
	pIVADCControl2.SetCorrection(-2771.82057041661);
	pIVADCControl2.SetPerturbation(0.1);
	pIVADCControl2.SetScalingValue(1);
	//属性页中约束条件属性设置
	IVADCResult pIVADCResult1 = pIVAProfileDifferentialCorrector1.GetResults().Item(0);
	pIVADCResult1.SetEnable(true);
	pIVADCResult1.SetDesiredValue(0);
	pIVADCResult1.SetScalingValue(1);
	pIVADCResult1.SetTolerance(0.1);
	pIVADCResult1.SetWeight(1);
	IVADCResult pIVADCResult2 = pIVAProfileDifferentialCorrector1.GetResults().Item(1);
	pIVADCResult2.SetEnable(true);
	pIVADCResult2.SetDesiredValue(0);
	pIVADCResult2.SetScalingValue(1);
	pIVADCResult2.SetTolerance(0.1);
	pIVADCResult2.SetWeight(1);
	//第三个预报段属性设置
	IVAStoppingConditionElement pIVAStoppingConditionElement2 = pIVAMCSPropagate2.GetStoppingConditions().Add("Duration");
	IVAStoppingCondition pIVAStoppingCondition2 = (IVAStoppingCondition)(pIVAStoppingConditionElement2.GetProperties());
	pIVAStoppingCondition2.SetTrip(86400);
	pIVAStoppingCondition2.SetTolerance(0.0001);
	//机动规划运行
	pIVADriverMCS.RunMCS();
	pIVADriverMCS.ApplyAllProfileChanges();
	//生成数据到文件
	String strReportFilePath = pIAtkObjectRoot.OutputDataReport(pISatellite, "J2000 Position Velocity", "5 Nov 2022 00:00:00.000", "6 Nov 2022 00:00:00.000");
	//输出数据报告目录
	System.out.println("输出数据报告:"+strReportFilePath);
  }
}
```

## 四、案例结果

1. 成功执行Java案例脚本ATKComponentJavaTest.java，会在cmd命令框中输出数据报告目录。
\image html java-result-1.png "cmd命令框输出"
2. 同时生成的还有卫星数据报告J2000 Position Velocity.txt以及轨道快速转移想定文件FastTransfer.xml，以上文件均存放在输出目录Output。
\image html java-result-2.png "生成的想定文件与数据报告"
3. 打开ATK检查生成的想定文件，选择轨道快速转移想定文件FastTransfer.xml，点击“开始”按钮运行动画，拉动下方时间轴查看二维视图下的轨迹效果。
\image html java-result-3.png "二维视图下的轨道快速转移效果图"
4. 点击ATK“三维视图”按钮切换至三维视图，查看三维效果。
\image html java-result-4.png "三维视图下的轨道快速转移效果图"

## 五、可见性案例参考

### 案例源码

```java
//AccessTest.java
package com.atk.test;

import com.atk.component.*;

public class AccessTest{
  static {
    try {
      //加载ATKComponent模式动态库与依赖库
	  System.loadLibrary("./ATKComponentJava");
    } catch (UnsatisfiedLinkError e) {
      System.err.println("load dll failed\n" + e);
      System.exit(1);
    }
  }
  
  public static void main(String []argv) {  
	//新建根结点
	IAtkObjectRoot pIAtkObjectRoot = new IAtkObjectRoot();
	
	//场景新建与属性设置
	IScenario pIScenario = (IScenario)pIAtkObjectRoot.GetChildren().New(EATKObjectType.eScenario,"ScenarioJava");
	pIScenario.SetTimePeriod("25 Dec 2025 09:00:00.000	", "31 Dec 2025 00:00:00.000");

	//新建卫星与地面站
	ISatellite pISatellite = (ISatellite)pIScenario.GetChildren().New(EATKObjectType.eSatellite, "Satellite");
	IFacility pIFacility = (IFacility)pIScenario.GetChildren().New(EATKObjectType.eFacility, "Facility");
	//仿真运行，计算卫星轨道数据
	pIAtkObjectRoot.GetAnimation().Reset();
	
	//设置可见性对象
	IAtkAccess pIAtkAccess = pISatellite.GetAccessToObject(pIFacility);
	//设置可见性计算时间
	pIAtkAccess.SetAccessTimePeriod("25 Dec 2025 09:00:00.000	", "31 Dec 2025 00:00:00.000");
	//设置步长
	pIAtkAccess.SetTimeStep(60);
	//设置是否使用光延迟
	pIAtkAccess.SetUseLTD(true); 
	//可见性计算
	pIAtkAccess.ComputeAccess();
	//打印可见性计算结果
	vector_vector_string  vvs = pIAtkAccess.ComputedAccessIntervalTimes();
	System.out.println(vvs);
	
	//仿真运行
	pIAtkObjectRoot.GetAnimation().PlayForward();
	//保存场景
	pIAtkObjectRoot.SaveScenario();
	//关闭场景
	pIAtkObjectRoot.CloseScenario();
  }
}
```

### 案例执行命令

将上述源码保存为 `AccessTest.java`，按与上文相同的方式放在当前目录的 `com/atk/test` 目录下，然后执行以下命令。

Windows（cmd）：

```bat
chcp 65001
javac -cp ATKComponentJava.jar -encoding utf-8 com/atk/test/AccessTest.java
java "-Dfile.encoding=UTF-8" -cp ".;ATKComponentJava.jar" com/atk/test/AccessTest
```

Linux：

```sh
export LD_LIBRARY_PATH=$PWD
javac -cp ATKComponentJava.jar -encoding utf-8 com/atk/test/AccessTest.java
java -cp ".:ATKComponentJava.jar" com/atk/test/AccessTest
```
