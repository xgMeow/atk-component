\page component_flow_octave Octave 操作流程

GNU Octave 没有专用的接口封装包，调用 ATK 的方式与 MATLAB 相同：用 .m 脚本加载 Java 封装包 ATKComponentJava.jar 与 ATKComponentJava.dll，再通过 Component 模式接口操作 ATK。两者能调用的接口完全一致，差别只在 Octave 的 Java 互操作写法——静态方法、枚举常量、构造器都要分别改用 javaMethod、java_get、javaObject。以下依次说明案例介绍、运行环境、操作步骤、案例实现、结果核对，以及从 MATLAB 脚本改写到 Octave 时的改写要点。

## 一、案例介绍

本案例实现半径为6700km的近地停泊轨道（LEO轨道）快速转移到半径为42164.197km的地球同步轨道（GEO轨道）的轨道机动规划设计。案例基于Component模式，通过GNU Octave运行.m脚本调Java封装包实现，与 \ref component_flow_MATLAB "MATLAB 操作流程" 是同一套案例代码，只在 Java 互操作写法上做了改写。

本案例依赖以下文件（均包含在 `IntegratingWithATK\component\Java`）：

- ATKComponentJava.jar，ATKComponent模式接口类封装包，提供Component模式下所有公用类对象与函数的接口封装；

- ATKComponentJava.dll，ATK Component模式Java接口动态库，提供Component模式的Java调用，并链接加载同目录的其他依赖动态库；Linux 下为对应的动态库文件；

- ATKComponentOctaveTest.m，Octave案例脚本，建议创建在 `IntegratingWithATK\component\Java`，具体内容参考下文案例实现里的代码。包含一个轨道快速转移案例的具体实现过程，该脚本由 Octave 解释运行。Octave 默认按 UTF-8 读取脚本，中文注释保存为 UTF-8 即可，不需要像 MATLAB 那样先转成 GBK；

- AstroData 数据目录，ATK 仿真所需的星历与天文数据，见操作步骤 2。

\image html octave-intro-1.png "依赖文件"

## 二、运行环境

### Octave 需要带 Java 接口

Octave 调 ATK 封装包走的是 Octave 自带的 Java 接口，所用 Octave 发行版必须在编译时启用 Java 支持。在 Octave 命令窗口确认：

```octave
usejava ("jvm")   % 返回 1 表示当前会话有可用 JVM，返回 0 则无法调用 ATK 封装包
version -java     % 查看当前使用的 JVM 版本与位数
```

`usejava ("jvm")` 返回 0 时，需更换一个带 Java 支持的 Octave 发行版，或按发行版说明补齐 Java 支持，本文不再展开。

### JDK 版本与位数

- Octave 启动 JVM 时按 `JAVA_HOME` 定位 JDK；未设置 `JAVA_HOME` 时，Windows 版会到注册表 `HKEY_LOCAL_MACHINE\SOFTWARE\JavaSoft` 下查找。

- JDK 位数必须与 Octave 位数一致（64 位 Octave 配 64 位 JDK）。位数不匹配时 JVM 加载失败，`usejava ("jvm")` 会返回 0 或直接报错。

- 建议按 \ref component_flow_java "Java 操作流程" 安装并配置 JDK 1.8（`JAVA_HOME` 与 `Path`），与 ATK 封装包的编译环境保持一致。

- JVM 每个 Octave 会话只加载一次，改完 `JAVA_HOME` 需重启 Octave 才生效。

### 内存

机动规划的计算量较大，JVM 默认堆上限可能不足。需要时在 `java.opts` 中加大上限：

```
-Xmx2048m
```

`java.opts` 所在目录由环境变量 `OCTAVE_JAVA_DIR` 指定，未设置时取 `which javaclasspath` 所在目录；文件内容为一行一个 `-X` / `-D` 选项，在 Octave 初始化 JVM 时传入。会话内可用 `javamem ()` 查看当前堆的占用与上限。

## 三、操作步骤

以下步骤均在同一工作目录中完成（下文称当前目录），本文以 `ATK安装根目录\IntegratingWithATK\component\Java` 作为该目录；命令中的 `ATK安装根目录` 需替换为实际安装路径。

### 1. 复制依赖库

Octave 与 MATLAB 共用同一套 Java 封装包，在 `ATK安装根目录\IntegratingWithATK\component` 目录中执行以下命令，将依赖库复制到当前目录。

Windows（cmd）：

```bat
.\GetAllDeps.bat "Java"
```

Linux：

```sh
sed -i 's/\r$//' GetAllDeps.sh && ./GetAllDeps.sh Java
```

> 待确认：若安装目录中的 GetAllDeps 提供了 Octave 专用参数，把上面的 `"Java"` 换成对应参数。

复制出的依赖文件主要包括：

- `ATKComponentJava.jar`：ATK Component 模式接口类封装包，提供 Component 模式下所有公用类对象与函数的接口封装。
- `ATKComponentJava.dll`：ATK Component 模式 Java 接口动态库，提供 Component 模式的 Java 调用，并链接加载同目录下的其他依赖动态库；Linux 下为对应的动态库文件。
- `AstroLib.dll` 等其他 Component 模式运行所需的依赖动态库。

### 2. 复制 AstroData

将 `ATK安装根目录/AstroData` 文件夹复制到当前目录。AstroData 为 ATK 仿真所需的星历与天文数据，缺失时无法正常创建场景与卫星对象。

Windows（cmd）：

```bat
xcopy "ATK安装根目录\AstroData" ".\AstroData" /e /i /y
```

Linux：

```sh
cp -r "ATK安装根目录/AstroData" .
```

### 3. 新建案例脚本

将下文「案例源码」保存为当前目录下的 `ATKComponentOctaveTest.m`。脚本用 `pwd` 定位同目录的封装包与输出目录，因此必须在当前目录启动 Octave；脚本不使用函数定义，Octave 不要求文件名与函数名一致。

MATLAB 案例里的 `initATK.m` 做三件事：把封装包加入类路径、加载动态库、设置输出路径。Octave 案例脚本已把这三步内联，不需要再单独运行 `initATK.m`。

### 4. 运行

在当前目录启动 Octave 并运行案例脚本。

Windows（cmd）：

```bat
octave --no-gui ATKComponentOctaveTest.m
```

Linux：

```sh
octave-cli ATKComponentOctaveTest.m
```

也可在 Octave 图形界面中把当前目录切到该目录后，直接执行脚本名 `ATKComponentOctaveTest`。脚本运行期间会输出数据报告路径，运行结束后场景会保存到 `Output` 目录。

## 四、案例实现

### 案例流程图

\image html octave-impl-1.png "Octave案例流程图"

### 案例源码

```octave
%ATKComponentOctaveTest.m
%	GNU Octave 案例脚本：轨道快速转移（LEO → GEO），接口与 MATLAB 案例一致
%	前置步骤：把 ATK 安装目录下的 IntegratingWithATK/component/Java 设为 Octave 当前目录

%1，确认当前 Octave 会话启用了 Java 支持
if (! usejava ("jvm"))
  error ("当前 Octave 未启用 Java 支持（usejava('jvm') 返回 0），请先按文档准备 JDK 环境");
end

%2，垃圾回收
javaMethod ("gc", "java.lang.System");

%3，把 ATK 的 Java 封装包加入动态类路径
jarPath = fullfile (pwd, "ATKComponentJava.jar");
if (! any (strcmpi (javaclasspath ("-all"), jarPath)))
  javaaddpath (jarPath);
end

%4，加载 ATKComponent 模式动态库及其依赖库
javaMethod ("loadLibrary", "com.atk.component.ATKLibraryLoader");

%5，设置调用语言与默认输出路径
%	语言标识按封装包实际支持的取值填写，封装包只区分既定语言时用 "MATLAB"
javaMethod ("SetCallCodeType", "com.atk.component.ATKComponentJavaModule", "Octave");
javaMethod ("SetSaveFileBasePath", "com.atk.component.ATKComponentJavaModule", pwd);

%6，枚举常量：Octave 不能写成 类名.常量名，统一用 java_get 取出后复用
eScenario      = java_get ("com.atk.component.EATKObjectType", "eScenario");
eSatellite     = java_get ("com.atk.component.EATKObjectType", "eSatellite");
eDataTime      = java_get ("com.atk.component.ELeadTrailData", "eDataTime");
eAstromaster   = java_get ("com.atk.component.EVePropagatorType", "ePropagatorAstromaster");
ePropagate     = java_get ("com.atk.component.EVASegmentType", "eVASegmentTypePropagate");
eTargetSequence = java_get ("com.atk.component.EVASegmentType", "eVASegmentTypeTargetSequence");
eManeuver      = java_get ("com.atk.component.EVASegmentType", "eVASegmentTypeManeuver");
eKeplerian     = java_get ("com.atk.component.EVAElementType", "eVAElementTypeKeplerian");
eImpulsive     = java_get ("com.atk.component.EVAManeuverType", "eVAManeuverTypeImpulsive");
eImpulseX      = java_get ("com.atk.component.EVAControlManeuver", "eVAControlManeuverImpulsiveCartesianX");
eImpulseZ      = java_get ("com.atk.component.EVAControlManeuver", "eVAControlManeuverImpulsiveCartesianZ");
eCrossEither   = java_get ("com.atk.component.EVACriterion", "eVACriterionCrossEither");

%7，新建根结点
pIAtkObjectRoot = javaObject ("com.atk.component.IAtkObjectRoot");

%8，场景新建与属性设置
pIAtkChildren = pIAtkObjectRoot.GetChildren ();
pIScenario = pIAtkChildren.New (eScenario, "FastTransfer");
pIScenario.SetTimePeriod ("5 Nov 2022 00:00:00.000", "6 Nov 2022 00:00:00.000");

%9，卫星新建与轨道预报设置为机动规划
pIScenarioChildren = pIScenario.GetChildren ();
pISatellite = pIScenarioChildren.New (eSatellite, "Satellite1");

%10，设置二维属性轨迹显示时长
pIVeGraphics = pISatellite.GetGraphics ();
pIVePassData = pIVeGraphics.GetPassData ();
pIVeGfxLeadTrailData = pIVePassData.GetGroundTrack ();
pIVeGfxLeadTrailData.SetTrailDataType (eDataTime);
pIVeLeadTrailData = pIVeGfxLeadTrailData.GetTrailData ();
pIVeLeadTrailData.SetTime (24*60*60);

pISatellite.SetPropagatorType (eAstromaster);
pIVADriverMCS = pISatellite.GetPropagator ();
pIVAMCSSegmentCollection = pIVADriverMCS.GetMainSequence ();

%11，机动规划添加段，新添加卫星会有默认初始段
pIVAMCSInitialState = pIVAMCSSegmentCollection.Item (int32 (0));
pIVAMCSPropagate = pIVAMCSSegmentCollection.Insert (ePropagate, "Propagate", "-");
pIVAMCSTargetSequence = pIVAMCSSegmentCollection.Insert (eTargetSequence, "TargetSequence", "-");
pIVAMCSTargetSegments = pIVAMCSTargetSequence.GetSegments ();
pIVAMCSManeuver = pIVAMCSTargetSegments.Insert (eManeuver, "Maneuver", "-");
pIVAMCSPropagate1 = pIVAMCSSegmentCollection.Insert (ePropagate, "Propagate", "-");
pIVAMCSTargetSequence1 = pIVAMCSSegmentCollection.Insert (eTargetSequence, "TargetSequence1", "-");
pIVAMCSTargetSegments1 = pIVAMCSTargetSequence1.GetSegments ();
pIVAMCSManeuver1 = pIVAMCSTargetSegments1.Insert (eManeuver, "Maneuver", "-");
pIVAMCSPropagate2 = pIVAMCSSegmentCollection.Insert (ePropagate, "Propagate", "-");

%12，初始段属性设置
pIVAMCSInitialState.SetOrbitEpoch ("5 Nov 2022 00:00:00.000");
pIVAMCSInitialState.SetElementType (eKeplerian);
pIVAElementKeplerian = pIVAMCSInitialState.GetElement ();
pIVAElementKeplerian.SetSemiMajorAxis (6700000);
pIVAElementKeplerian.SetEccentricity (0);
pIVAElementKeplerian.SetInclination (0);
pIVAElementKeplerian.SetRAAN (0);
pIVAElementKeplerian.SetArgOfPeriapsis (0);
pIVAElementKeplerian.SetTrueAnomaly (0);

%13，第一个预报段属性设置
pIVAStoppingConditions = pIVAMCSPropagate.GetStoppingConditions ();
pIVAStoppingConditionElement = pIVAStoppingConditions.Add ("Duration");
pIVAStoppingCondition = pIVAStoppingConditionElement.GetProperties ();
pIVAStoppingCondition.SetTrip (7200);
pIVAStoppingCondition.SetTolerance (0.0001);

%14，第一个瞄准段中机动段属性设置
pIVAMCSManeuver.SetManeuverType (eImpulsive);
pIVAManeuverImpulsive = pIVAMCSManeuver.GetManeuver ();
pIVAAttitudeControlImpulsiveThrustVector = pIVAManeuverImpulsive.GetAttitudeControl ();
pIVAAttitudeControlImpulsiveThrustVector.SetThrustAxesName ("Satellite VNC(Earth)");
pIVAMCSManeuver.EnableControlParameter (eImpulseX);
pIVAMCSManeuverResults = pIVAMCSManeuver.GetResults ();
pIVAMCSManeuverResults.Add ("Radius_Of_Apoapsis");

%15，第一个瞄准段添加属性页
pIVAMCSTargetProfiles = pIVAMCSTargetSequence.GetProfiles ();
pIVAProfileDifferentialCorrector = pIVAMCSTargetProfiles.Add ("Differential Corrector");

%16，属性页中控制变量属性设置
pIVADCControlParameters = pIVAProfileDifferentialCorrector.GetControlParameters ();
pIVADCControl = pIVADCControlParameters.GetControlByPaths ("Maneuver", "ImpulseX");
pIVADCControl.SetEnable (true);
pIVADCControl.SetMaxStep (100);
pIVADCControl.SetCorrection (2781.50365947627);
pIVADCControl.SetPerturbation (0.1);
pIVADCControl.SetScalingValue (1);

%17，属性页中约束条件属性设置
pIVADCResults = pIVAProfileDifferentialCorrector.GetResults ();
pIVADCResult = pIVADCResults.GetResultByPaths ("Maneuver", "StateCalcRadiusOfApoapsis");
pIVADCResult.SetEnable (true);
pIVADCResult.SetDesiredValue (84328394);
pIVADCResult.SetScalingValue (1);
pIVADCResult.SetTolerance (0.1);
pIVADCResult.SetWeight (1);

%18，第二个预报段属性设置
pIVAStoppingConditions1 = pIVAMCSPropagate1.GetStoppingConditions ();
pIVAStoppingConditionElement1 = pIVAStoppingConditions1.Add ("RMagnitude");
pIVAStoppingCondition1 = pIVAStoppingConditionElement1.GetProperties ();
pIVAStoppingCondition1.SetTrip (42164197);
pIVAStoppingCondition1.SetTolerance (1e-6);
pIVAStoppingCondition1.SetRepeatCount (int32 (1));
pIVAStoppingCondition1.SetCriterion (eCrossEither);

%19，第二个瞄准段中机动段属性设置
pIVAMCSManeuver1.SetManeuverType (eImpulsive);
pIVAManeuverImpulsive1 = pIVAMCSManeuver1.GetManeuver ();
pIVAAttitudeControlImpulsiveThrustVector1 = pIVAManeuverImpulsive1.GetAttitudeControl ();
pIVAAttitudeControlImpulsiveThrustVector1.SetThrustAxesName ("Satellite VNC(Earth)");
pIVAMCSManeuver1.EnableControlParameter (eImpulseX);
pIVAMCSManeuver1.EnableControlParameter (eImpulseZ);
pIVAMCSManeuver1Results = pIVAMCSManeuver1.GetResults ();
pIVAMCSManeuver1Results.Add ("Eccentricity");
pIVAMCSManeuver1Results.Add ("Cosine_of_Vertical_FPA");

%20，第二个瞄准段添加属性页
pIVAMCSTargetProfiles1 = pIVAMCSTargetSequence1.GetProfiles ();
pIVAProfileDifferentialCorrector1 = pIVAMCSTargetProfiles1.Add ("Differential Corrector");

%21，属性页中控制变量属性设置
pIVADCControlParameters1 = pIVAProfileDifferentialCorrector1.GetControlParameters ();
pIVADCControl1 = pIVADCControlParameters1.Item (int32 (0));
pIVADCControl1.SetEnable (true);
pIVADCControl1.SetMaxStep (300);
pIVADCControl1.SetCorrection (-1581.97670664023);
pIVADCControl1.SetPerturbation (0.1);
pIVADCControl1.SetScalingValue (1);
pIVADCControl2 = pIVADCControlParameters1.Item (int32 (1));
pIVADCControl2.SetEnable (true);
pIVADCControl2.SetMaxStep (300);
pIVADCControl2.SetCorrection (-2771.82057041661);
pIVADCControl2.SetPerturbation (0.1);
pIVADCControl2.SetScalingValue (1);

%22，属性页中约束条件属性设置
pIVADCResults1 = pIVAProfileDifferentialCorrector1.GetResults ();
pIVADCResult1 = pIVADCResults1.Item (int32 (0));
pIVADCResult1.SetEnable (true);
pIVADCResult1.SetDesiredValue (0);
pIVADCResult1.SetScalingValue (1);
pIVADCResult1.SetTolerance (0.1);
pIVADCResult1.SetWeight (1);
pIVADCResult2 = pIVADCResults1.Item (int32 (1));
pIVADCResult2.SetEnable (true);
pIVADCResult2.SetDesiredValue (0);
pIVADCResult2.SetScalingValue (1);
pIVADCResult2.SetTolerance (0.1);
pIVADCResult2.SetWeight (1);

%23，第三个预报段属性设置
pIVAStoppingConditions2 = pIVAMCSPropagate2.GetStoppingConditions ();
pIVAStoppingConditionElement2 = pIVAStoppingConditions2.Add ("Duration");
pIVAStoppingCondition2 = pIVAStoppingConditionElement2.GetProperties ();
pIVAStoppingCondition2.SetTrip (86400);
pIVAStoppingCondition2.SetTolerance (0.0001);

%24，机动规划运行
pIVADriverMCS.RunMCS ();
pIVADriverMCS.ApplyAllProfileChanges ();

%25，生成数据到文件，并输出数据报告目录
strReportFilePath = pIAtkObjectRoot.OutputDataReport (pISatellite, "J2000 Position Velocity", "5 Nov 2022 00:00:00.000", "6 Nov 2022 00:00:00.000");
printf ("输出数据报告：%s\n", strReportFilePath);

%26，仿真运行
pIAnimation = pIAtkObjectRoot.GetAnimation ();
pIAnimation.PlayForward ();

%27，保存场景
pIAtkObjectRoot.SaveScenario ();

%28，关闭场景
pIAtkObjectRoot.CloseScenario ();
```

### MATLAB 与 Octave 的写法差异

Octave 的 Java 接口只支持对象方法用点号调用，静态成员、构造器、枚举常量都要走函数形式，这是从 MATLAB 脚本改写时的主要工作量。逐条对照如下：

| 用途 | MATLAB 写法 | Octave 写法 |
| --- | --- | --- |
| 新建 Java 对象 | `p = IAtkObjectRoot();` | `p = javaObject ("com.atk.component.IAtkObjectRoot");` |
| 调用静态方法 | `ATKComponentJavaModule.SetSaveFileBasePath (pwd);` | `javaMethod ("SetSaveFileBasePath", "com.atk.component.ATKComponentJavaModule", pwd);` |
| 取枚举常量 | `EATKObjectType.eScenario` | `java_get ("com.atk.component.EATKObjectType", "eScenario");` |
| 导入包 | `import com.atk.component.*;` | 不支持，类名一律写全限定名 |
| 调用对象方法 | `p.GetChildren ()` | `p.GetChildren ()`（相同） |
| 字符串拼接 | `"StateCalc" + 'RadiusOfApoapsis'` | 用完整字符串 `"StateCalcRadiusOfApoapsis"`，Octave 的 `+` 不做字符串拼接 |
| 脚本编码 | 需 GBK | UTF-8 |

改写时还需注意：

- 整型参数：Java 侧声明为 `int` 的参数（如集合下标 `Item (...)`、`SetRepeatCount (...)`）用 `int32 (...)` 包装后传入。

- 逻辑参数：`SetEnable (true)` 传入的是 Octave 的 logical 值；若报签名不匹配，可改传 `javaObject ("java.lang.Boolean", true)`。

- 对象比较：Octave 的 `==` 不能直接比较两个 Java 对象，判断枚举或类型是否相同时用 `javaMethod ("equals", a, b)`。

- 返回值：Java 的 `String` 返回值会自动转成 Octave 的 char，`printf`、`disp` 可直接输出；`String[]` 之类的数组返回值不会自动转换，需用 `char (...)` 逐个取值。

### 常见报错与处理

| 现象 | 原因 | 处理 |
| --- | --- | --- |
| `no method ... matching signature` | 参数类型不匹配（整型、逻辑值，或重载方法选错） | 按上面的规则补 `int32 (...)`，或改传 `javaObject ("java.lang.Boolean", true)` |
| `usejava ("jvm")` 返回 0 | Octave 发行版未启用 Java 接口，或 JDK 位数与 Octave 不一致 | 换带 Java 支持的发行版；`JAVA_HOME` 指向与 Octave 同位数的 JDK |
| `ClassNotFoundException: com.atk.component.*` | `ATKComponentJava.jar` 未加入类路径 | `javaaddpath` 传绝对路径，再用 `javaclasspath ("-all")` 确认 |
| `UnsatisfiedLinkError: no ATKComponentJava in java.library.path` | 动态库不在搜索路径内，或同目录的依赖库缺失 | 从封装包与依赖库所在目录启动 Octave；必要时显式加载：`javaMethod ("load", "java.lang.System", fullfile (pwd, "ATKComponentJava.dll"))` |

## 五、案例结果

成功运行Octave案例脚本ATKComponentOctaveTest.m之后，Octave命令窗口会输出数据报告目录，并生成卫星数据报告“J2000 Position Velocity.txt”以及轨道快速转移想定文件“FastTransfer.xml”。以上文件均存放在输出目录Output。

\image html octave-result-1.png "生成的想定与数据报告"

打开ATK检查生成的想定文件，选择轨道快速转移想定文件“FastTransfer.xml”，点击“开始”按钮运行动画，拉动下方时间轴查看二维视图下的轨迹效果。

\image html octave-result-2.png "ATK二维视图下的轨道快速转移效果图"

点击ATK“三维视图”按钮切换至三维视图，查看三维效果。

\image html octave-result-3.png "ATK三维视图下的轨道快速转移效果图"

## 六、待补与待确认

本文档的 Java 互操作写法依据 Octave 官方 Java 接口规则推演，以下几点需按实际环境核对后定稿：

1. 实测通过的 Octave 版本号（含 JVM 位数），补到「二、运行环境」；
2. `GetAllDeps` 是否有 Octave 专用参数（步骤 1 的待确认处）；
3. `SetCallCodeType` 的取值：封装包只区分既定语言时用 `"MATLAB"`；
4. 图片：`octave-intro-1.png`、`octave-impl-1.png`、`octave-result-1.png`、`octave-result-2.png`、`octave-result-3.png` 尚未提供，需放入 `docs\操作流程\media`；
5. 若 ATK 的案例目录中已提供 Octave 版本脚本，以实际脚本替换「案例源码」；
6. `ATKLibraryLoader` 的类名与 `loadLibrary` 方法名按 jar 实际内容核对（对应 MATLAB 案例中 `initATK.m` 的加载步骤）。
