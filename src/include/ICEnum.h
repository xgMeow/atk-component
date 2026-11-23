#pragma once

//enum EVeAttitude
//{
//	eAttitudeUnknown = -1,
//	eAttitudeStandard = 0
//};

//对象类型
enum EATKObjectType
{
	eRoot                = -1,
	eAdvCAT				 = 0,
	eAircraft,
	eCoverageDefinition,
	eFacility,
	eGroundVehicle,
	ePlanet,
	eReceiver,
	eSatellite,
	eScenario,
	eSensor,
	eShip,
	eStar,
	eTransmitter,
	eSatelliteCollection,
	eChain,
	eSubmarine,
	eLaunchVehicle,
	eAreaTarget,
	eMissile,
	eFigureOfMerit,
	eAntenna,
};

//卫星预报器类型
enum EVePropagatorType
{
	eUnknownPropagator        = 0,
	ePropagatorTwoBody,
	ePropagatorJ2Perturbation,
	ePropagatorHPOP,
	ePropagatorSGP4,
	ePropagatorStkExternal,
	ePropagatorAstromaster,
	ePropagatorGreatArc,
	ePropagatorSimpleAscent,
	ePropagatorJ4Perturbation,
	ePropagatorVinti,
	ePropagatorBallistic,
	ePropagatorRealisticBallistic,
};

//传感器类型
enum ESnPattern
{
	eSnSimpleConic = 0,
	eSnRectangular = 1,
	eSnComplexConic = 3,
	eSnHalfPower = 4,
	eSnSAR = 5
};

//传感器：指向：旋转：扫描模式
enum ESnScanMode
{
	eSnContinuous = 0,
	eSnUnidirectional = 1,
	eSnBidirectional = 2
};

//传感器位置类型
enum ESnLocation
{
	eSnFixed = 0
};

//传感器指向类型
enum ESnPointing
{
	eSnPtFixed = 0,
	eSnPtSpinning = 1,
	eSnPtTargeted = 2,
	eSnPtGrazingAlt = 3,
	eSnPtExternal = 4,
};

//传感器指向瞄准类型
enum ESnPtTrgtBsightType
{
	eSnPtTrgtBsightTracking = 0,
	eSnPtTrgtBsightFixed = 1
};

//传感器指向类型：目标定向；瞄准类型：追踪；追踪模式
enum ETrackModeType
{
	eTrackModeReceive = 0,
	eTrackModeTransmit = 1,
	eTrackModeTranspond = 2
};

//传感器 二维视图 显示相交类型
enum EIntersectionType
{
	eIntersectionNone = 0,
	eIntersectionCentralBody = 1,
	eIntersectionTerrain = 2
};

//约束类型
enum EAccessConstraints
{
	eCstrNone                 = -1,
	//基本约束				  
	eCstrAzimuthAngle         = 0,
	eCstrElevationAngle       = 1,
	eCstrRange                = 2,
	eCstrAzimuthRate          = 3,
	eCstrElevationRate        = 4,
	eCstrRangeRate            = 5,
	eCstrAngularRate          = 6,
	eCstrAltitude             = 7,
	eCstrPropagationDelay     = 8,
	eCstrLineOfSight          = 9,
	//太阳约束				  
	eCstrSunElevationAngle    = 10,
	eCstrSunGroundElevAngle   = 11,
	eCstrLunarElevationAngle  = 12,
	eCstrLOSSunExclusion      = 13,
	eCstrLOSLunarExclusion    = 14,
	eCstrBSSunExclusion       = 15,
	eCstrBSLunarExclusion     = 16,
	//通信约束
	eCstrFrequency            = 17,
	eCstrNoiseTemperature     = 18,
	eCstrRcvdIsotropicPower   = 19,
	eCstrFluxDensity          = 20,
	eCstrLinkEIRP             = 21,
	eCstrDopplerShift         = 22,
	CstrCOverNo               = 23,
	eCstrPowerAtReceiverInput = 24,
	eCstrCOverN               = 25,
	eCstrBitErrorRate         = 26,
	eCstrLinkMargin           = 27,
	eCstrEbOverNo             = 28,
	eCstrPolRelAngle          = 29,
	eCstrGOverT               = 30
};

//名称相同约束的类型
enum EVACalcObjectElem
{
	eVACalcObjectElemBrouwerLyddaneMeanLong = 0,
	eVACalcObjectElemBrouwerLyddaneMeanShort = 1,
	eVACalcObjectElemKozaiIzsakMean = 2,   //Mean Elems
	eVACalcObjectElemOsculating = 3    //Keplerian Elems
};

//约束段采用状态类型
enum EVASegmentState
{
	eVASegmentStateError = 0,
	eVASegmentStateInitial = 1,
	eVASegmentStateFinal = 2,
};

//坐标系
enum EVeCoordinateSystem
{
	eVeCoordinateSystemCentralBodyFixed = 0,
	eVeCoordinateSystemInertial         = 1
};

//轨道圈数经纬度类型
enum EVeBreakAngleType
{
	eBreakAngleTypeUnknown = -1,
	eBreakByLatitude       = 0,
	eBreakByLongitude      = 1
};

//轨道圈数方向类型
enum EVeDirection
{
	eAscending  = 0,
	eDescending = 1
};

//标准姿态模式
enum EAttitudeStandardType
{
	eRouteAttitudeStandard = 0,
	eTrajectoryAttitudeStandard = 1,
	eOrbitAttitudeStandard = 2
};

//姿态模式	Satellite.h:///<姿态生成方式. 0=Standard;1=Multi Segment;2=动力学解算;3=hold;4=STK File
enum EVeAttitude
{
	eAttitudeUnknown  = -1,
	eAttitudeStandard = 0,
	eAttitudeMultiSegment = 1,
	eAttitudeHold = 3,
	eAttitudeSTKExternal = 4,
};

//姿态类型
enum EVeProfile
{
	eProfileUnknown = -1,
	eProfileNadirAlignmentWithECIVelocityConstraint,
	eProfileNadirAlignmentWithECFVelocityConstraint,
	eProfileECIVelocityAlignmentWithNadirConstraint ,
	eProfileECFVelocityAlignmentWithNadirConstraint,
	eProfileSunAlignmentWithNadirConstraint
};

//偏置姿态类型
enum EVeProfileOffset
{
	eProfileOffsetUnknown = -1,
	eProfileOffsetQuaternion = 0,
	eProfileOffsetEuler = 1,
	eProfileOffsetYPR = 2
};

//YPR转序序列
enum EYPRSequence
{
	eYPRSequenceUnknown = -1,
	eYPRSequenceRPY = 123,
	eYPRSequenceRYP = 132,
	eYPRSequencePRY = 213,
	eYPRSequencePYR = 231,
	eYPRSequenceYRP = 312,
	eYPRSequenceYPR = 321
};

//弹道学落点类型
enum EVeImpactLocation
{
	eImpactLocationUnknown = -1,
	eImpactLocationPoint = 0,
	eImpactLocationLaunchAzEl = 1
};

//弹道学增量类型
enum EVeLaunchControl
{
	eLaunchControlUnknown = -1,
	eLaunchControlFixedDeltaV = 0,
	eLaunchControlFixedDeltaVMinEcc = 1,
	eLaunchControlFixedApogeeAlt = 2,
	eLaunchControlFixedTimeOfFlight = 3
};

//导弹类型
enum EVeMissileType
{
	eLRM = 0,
	eMRM = 1,
	eSRM = 2
};

//HPOP大气模型
enum EAtmosphericDensityModel
{
	e1976StandardAtmosModel = 0,
	eMSIS00                 = 1,
	eMSIS86                 = 2,
	eMSIS90                 = 3
};

//HPOP三体引力
enum EThirdBodyGravType
{
	ePointMass = 0,
	eGravField = 1
};

//HPOP太阳光压模型
enum ESRPModel
{
	eSRPModelUnknown   = -1,
	eSRPModelSpherical = 0
};

//坐标系
enum ECoordinateSystem
{
	eCoordinateSystemUnknown = -1,
	eCoordinateSystemJ2000   = 0,
	eCoordinateSystemFixed,
	eCoordinateSystemICRF,
	eCoordinateSystemTrueOfDate,
	eCoordinateSystemMeanOfDate,
	eCoordinateSystemTEMEOfDate,
	eCoordinateSystemTrueEclipticOfDate,
	eCoordinateSystemMeanEclipticOfDate,
	eCoordinateSystemJ2000Ecliptic
};

//坐标类型
enum EOrbitStateType
{
	eOrbitStateCartesian = 0,
	eOrbitStateClassical = 1,
	eOrbitStateSpherical = 2
};

//轨道根数Location类型
enum EClassicalLocation
{
	eLocationUnknown            = -1,
	eLocationArgumentOfLatitude = 0,
	eLocationEccentricAnomaly   = 1,
	eLocationMeanAnomaly        = 2,
	eLocationTimePastAN         = 3,
	eLocationTimePastPerigee    = 4,
	eLocationTrueAnomaly        = 5
};

//轨道根数AscNode类型
enum EOrientationAscNode
{
	eAscNodeUnknown = -1,
	eAscNodeRAAN    = 0,
	eAscNodeLAN     = 1
};

//轨道根数SizeShape类型
enum EClassicalSizeShape
{
	eSizeShapeUnknown       = -1,
	eSizeShapeSemimajorAxis = 0,
	eSizeShapeRadius        = 1,
	eSizeShapeAltitude      = 2,
	eSizeShapePeriod        = 3,
	eSizeShapeMeanMotion    = 4
};

//球坐标航迹角类型
enum ESphericalFPA
{
	eSphericalFPAUnknown    = -1,
	eSphericalFPAHorizontal = 0,
	eSphericalFPAVertical   = 1
};

//机动规划段类型
enum EVASegmentType
{
	eVASegmentTypeInitialState = 0,
	eVASegmentTypePropagate,
	eVASegmentTypeManeuver,
	eVASegmentTypeTargetSequence,
	eVASegmentTypeSequence,
	eVASegmentTypeBackwardSequence,
	eVASegmentTypeUpdate,
	eVASegmentTypeStop,
	eVASegmentTypeReturn,
	eVASegmentTypeHold,
	eVASegmentTypeEnd,
	eVASegmentTypeLambertTarget,
	eVASegmentRPOSetInitialState,
	eVASegmentRPOFMCircumnav,
	eVASegmentRPOFMW,
	eVASegmentRPOHop,
	eVASegmentRPOPerchEqualSpacing,
	eVASegmentRPOTearDrop,
	eVASegmentRPONMCircumnav,
	eVASegmentRPOFollowSun,
	eVASegmentRPOExitGEO,
	eVASegmentRPOGEORendezvousDrifting,
	eVASegmentRPOGEORendezvousNolead,
	eVASegmentRPOHopAndStop,
	eVASegmentTypeFollow,
	eVASegmentRPOCoast,
	eVASegmentRPOGEOTargetDrift,
	eVASegmentRPONoncoplanarRendezvous,
	eVASegmentRPOConeApproach,
	eVASegmentRPOCorridorApproach,
	eVASegmentRPOFastRendezvous,
	eVASegmentRPOFollowSunMotion,
	eVASegmentRPOGEOAltDrift,
	eVASegmentRPOGEODrift,
	eVASegmentRPOGEOTargetAltDrift,
	eVASegmentRPONMCircumnavToRbar,
	eVASegmentRPONoncoplanarFastRendezvous,
	eVASegmentRPORbarToNMCircumnav,
	eVASegmentRPORbarToVbar,
	eVASegmentRPOSetDeltaV,
	eVASegmentRPOStopPlaneCross,
	eVASegmentRPOStopRelMotion,
	eVASegmentRPOVbarToNMCircumnav,
	eVASegmentRPOVbarToRbar,
};

//机动规划段坐标类型
enum EVAElementType
{
	eVAElementTypeUnknown   = 0,
	eVAElementTypeCartesian = 1,
	eVAElementTypeKeplerian = 2
};

//初始段控制变量类型
enum EVAControlInitState
{
	eVAControlInitStateEpoch                        = 0,
	eVAControlInitStateCartesianX                   ,
	eVAControlInitStateCartesianY                   ,
	eVAControlInitStateCartesianZ                   ,
	eVAControlInitStateCartesianVx                  ,
	eVAControlInitStateCartesianVy                  ,
	eVAControlInitStateCartesianVz                  ,
	eVAControlInitStateKeplerianSMA                 ,
	eVAControlInitStateKeplerianApoapsisAltSize     ,
	eVAControlInitStateKeplerianApoapsisRadSize     ,
	eVAControlInitStateKeplerianPeriapsisAltSize    ,
	eVAControlInitStateKeplerianPeriapsisRadSize    ,
	eVAControlInitStateKeplerianPeriod              ,
	eVAControlInitStateKeplerianMeanMotion          ,
	eVAControlInitStateKeplerianEcc				    ,
	eVAControlInitStateKeplerianApoapsisAltShape	,
	eVAControlInitStateKeplerianApoapsisRadShape	,
	eVAControlInitStateKeplerianPeriapsisAltShape   ,
	eVAControlInitStateKeplerianPeriapsisRadShape   ,
	eVAControlInitStateKeplerianInc                 ,
	eVAControlInitStateKeplerianRAAN                ,
	eVAControlInitStateKeplerianLAN                 ,
	eVAControlInitStateKeplerianW                   ,
	eVAControlInitStateKeplerianTA                  ,
	eVAControlInitStateKeplerianMeanAnomaly         ,
	eVAControlInitStateKeplerianArgLat              ,
	eVAControlInitStateKeplerianEccAnomaly          ,
	eVAControlInitStateKeplerianTimePastAN          ,
	eVAControlInitStateKeplerianTimePastPeriapsis   ,
	eVAControlInitStateDryMass                      ,
	eVAControlInitStateFuelMass                     ,
	eVAControlInitStateSRPArea                      ,
	eVAControlInitStateDragArea                     ,
	eVAControlInitStateCr                           ,
	eVAControlInitStateCd                         
};

//停止条件控制变量类型
enum EVAControlStoppingCondition
{
	eVAControlStoppingConditionTripValue = 0
};

//停止条件类型
enum EVAStoppingCondition
{
	eVAStoppingConditionBasic = 0
};

//停止条件触发条件
enum EVACriterion
{
	eVACriterionCrossDecreasing	= 0,
	eVACriterionCrossEither     = 1,
	eVACriterionCrossIncreasing = 2
};

//机动类型
enum EVAManeuverType
{
	eVAManeuverTypeImpulsive = 0,
	eVAManeuverTypeFinite    = 1
};

//机动段控制变量类型
enum EVAControlManeuver
{
	eVAControlManeuverFiniteCartesianX       = 0,
	eVAControlManeuverFiniteCartesianY       = 1,
	eVAControlManeuverFiniteCartesianZ       = 2,
	eVAControlManeuverFiniteSphericalAz      = 3,
	eVAControlManeuverFiniteSphericalElev    = 4,
	eVAControlManeuverImpulsiveCartesianX    = 5,
	eVAControlManeuverImpulsiveCartesianY    = 6,
	eVAControlManeuverImpulsiveCartesianZ    = 7,
	eVAControlManeuverImpulsiveSphericalAz   = 8,
	eVAControlManeuverImpulsiveSphericalElev = 9,
	eVAControlManeuverImpulsiveSphericalMag  = 10
};

//机动段坐标类型
enum EDirectionType
{
	eDirRADec = 0,
	eDirXYZ   = 1
};

//机动段脉冲坐标类型
enum EVAImpDeltaVRep
{
	eVACartesianImpDeltaV = 0,
	eVASphericalImpDeltaV = 1
};

//瞄准序列段动作类型
enum EVATargetSeqAction
{
	eVATargetSeqActionRunActiveProfiles     = 0,   //迭代
	eVATargetSeqActionRunNominalSeq         = 1,   //正常运行
	eVATargetSeqActionRunActiveProfilesOnce = 2    //应用迭代结果运行
};

//瞄准序列段属性页插入位置
enum EVAProfileInsertDirection
{
	eVAProfileInsertBefore = 0,
	eVAProfileInsertAfter  = 1
};

//瞄准序列段属性页模式类型
enum EVAProfileMode
{
	eVAProfileModeIterate   = 0,   //迭代
	eVAProfileModeNotActive = 1,   //不激活
	eVAProfileModeRunOnce   = 2,   //运行一次
	eVAProfileModeActive    = 3
};

//瞄准序列段属性页类型
enum EVAProfile
{
	eVAProfileDifferentialCorrector  = 0,
	eVAProfileSQPOptimizer           = 1,
	eVAProfileEvolutionOptimizer     = 2
};

//瞄准序列段属性页归一化参数
enum EVADCScalingMethod
{
	eVADCScalingMethodOneNoScaling = 0,
	eVADCScalingMethodInitialValue = 1,
	eVADCScalingMethodSpecifiedValue,
	eVADCScalingMethodTolerance,
};

//更新段控制变量属性值
enum EVAControlUpdate
{
	eVAControlUpdateDryMassVal  = 0,
	eVAControlUpdateFuelMassVal = 1,
	eVAControlUpdateSRPAreaVal  = 2,
	eVAControlUpdateDragAreaVal = 3,
	eVAControlUpdateCrVal       = 4,
	eVAControlUpdateCdVal       = 5
};

//更新段属性类型
enum EVAUpdateParam
{
	eVAUpdateParamDryMass  = 0,
	eVAUpdateParamFuelMass = 1,
	eVAUpdateParamSRPArea  = 2,
	eVAUpdateParamDragArea = 3,
	eVAUpdateParamCr       = 4,
	eVAUpdateParamCd       = 5
};

//更新段属性操作类型
enum EVAUpdateAction
{
	eVAUpdateActionNoChange	     = 0,
	eVAUpdateActionAddValue      = 1,
	eVAUpdateActionSubtractValue = 2,
	eVAUpdateActionSetToNewValue = 3
};

//序列段传递类型
enum EVASequenceStateToPass
{
	eVASequenceStateToPassInitial = 0,
	eVASequenceStateToPassFinal   = 1
};

//返回段是否返回控制变量到他的父级段
enum EVAReturnControl
{
	eVAReturnControlEnable                     = 0,
	eVAReturnControlDisable                    = 1,
	eVAReturnControlEnableExceptProfilesBypass = 2
};

//兰勃特瞄准段控制变量属性值
enum EVAControlLambert
{
	eVAControlLambertCartesianX						= 0,
	eVAControlLambertCartesianY						,
	eVAControlLambertCartesianZ						,
	eVAControlLambertCartesianVx					,
	eVAControlLambertCartesianVy					,
	eVAControlLambertCartesianVz					,
	eVAControlLambertKeplerianSMA					,
	eVAControlLambertKeplerianApoapsisAltSize		,
	eVAControlLambertKeplerianApoapsisRadSize		,
	eVAControlLambertKeplerianPeriapsisAltSize		,
	eVAControlLambertKeplerianPeriapsisRadSize		,
	eVAControlLambertKeplerianPeriod				,
	eVAControlLambertKeplerianMeanMotion			,
	eVAControlLambertKeplerianEcc					,
	eVAControlLambertKeplerianApoapsisAltShape		,
	eVAControlLambertKeplerianApoapsisRadShape		,
	eVAControlLambertKeplerianPeriapsisAltShape		,
	eVAControlLambertKeplerianPeriapsisRadShape		,
	eVAControlLambertKeplerianInc					,
	eVAControlLambertKeplerianRAAN					,
	eVAControlLambertKeplerianLAN					,
	eVAControlLambertKeplerianW						,
	eVAControlLambertKeplerianTA					,
	eVAControlLambertKeplerianMeanAnomaly			,
	eVAControlLambertKeplerianArgLat				,
	eVAControlLambertKeplerianEccAnomaly			,
	eVAControlLambertKeplerianTimePastAN			,
	eVAControlLambertKeplerianTimePastPeriapsis		
};		

//跟随段控制变量类型
enum EVAControlFollow
{
	eVAControlFollowFuelMass = 0,
	eVAControlFollowCd,
	eVAControlFollowCr,
	eVAControlFollowDragArea,
	eVAControlFollowDryMass,
	eVAControlFollowSRPArea,
	eVAControlFollowXOffset,
	eVAControlFollowYOffset,
	eVAControlFollowZOffset,
};

//跟随段跟随类型
enum EVAFollowJoin
{
	eVAFollowJoinSpecify = 0,
	eVAFollowJoinAtBeginning,
	eVAFollowJoinAtEnd,
	eVAFollowJoinAtFinalEpochOfPreviousSeg,
};

//跟随段分离类型
enum EVAFollowSeparation
{
	eVAFollowSeparationSpecify = 0,
	eVAFollowSeparationAtEndOfLeadersEphem,
};

//跟随段航天器参数设置方式
enum EVAFollowSpacecraftAndFuelTank
{
	eVAFollowSpacecraftAndFuelTankSpecify = 0,
	eVAFollowSpacecraftAndFuelTankInherit,
};

//二维轨迹类型
enum ELeadTrailData
{
	eDataUnknown = -1,
	eDataPoint   = 0,
	eDataTime    = 1,
	eDataAll     = 2,
	eDataNone    = 3
};

//二维显示类型
enum EVeGfxAttributes
{
	eAttributesUnknown = -1,
	eAttributesBasic   = 0,
	eAttributesCustom  = 1
};

//二维显示线型
enum ELineStyle
{
	eSolid         = 0,
	eDashed        = 1,
	eDotted        = 2,
	eDotDashed     = 3,
	eDashDotDotted = 4
};

//二维显示线宽
enum ELineWidth
{
	e1 = 1,
	e2 = 2,
	e3 = 3,
	e4 = 4,
	e5 = 5
};

//三维向量类型
enum EGeometricElemType
{
	eVectorElem = 0,
	eAxesElem = 1,
	ePointElem = 2
};

//三维数据显示显示位置类型
enum EVOLocation
{
	e3DWindow = 0,
	eObject   = 1
};

//三维数据显示X轴原点类型
enum EVOXOrigin
{
	eXOriginLeft   = 0,
	eXOriginRight  = 1,
	eXOriginCenter = 2
};

//三维数据显示Y轴原点类型
enum EVOYOrigin
{
	eYOriginTop = 0,
	eYOriginBottom = 1,
	eYOriginCenter = 2
};

//地面站坐标类型
enum EPositionType
{
	eCartesian = 0,		///<笛卡尔坐标
	eCylindrical = 1,		///<柱坐标
	eGeocentric = 2,		///<地心坐标
	eGeodetic = 3,			///<地理坐标
	eSpherical = 4,		///<球坐标
};

//固定指向偏置姿态类型
enum EOrientationType
{
	eAzEl = 0,
	eQuaternion = 1,
	eEulerAngles = 2,
	eYPRAngles = 3,
	eRADec = 4,
	eMatrix = 5
};

//天线指向方位高度角视轴类型
enum EAzElAboutBoresight
{
	eAzElAboutBoresightUnknown = -1,
	eAzElAboutBoresightHold = 0,
	eAzElAboutBoresightRotate = 1
};

//欧拉旋转序列选项
enum EEulerOrientationSequence
{
	e121 = 0,	///<121 rotation.
	e123 = 1,	///<123 rotation.
	e131 = 2,	///<131 rotation.
	e132 = 3,	///<132 rotation.
	e212 = 4,	///<212 rotation.
	e213 = 5,	///<213 rotation.
	e231 = 6,	///<231 rotation.
	e232 = 7,	///<232 rotation.
	e312 = 8,	///<312 rotation.
	e313 = 9,	///<313 rotation.
	e321 = 10,	///<321 rotation.
	e323 = 11	///<323 rotation.
};

//YPR序列选项
enum EYPRAnglesSequence
{
	eRPY = 0,
	eRYP = 1,
	ePRY = 2,
	ePYR = 3,
	eYRP = 4,
	eYPR = 5
};

//传感器2D图形投影类型
enum ESnProjectionDistanceType
{
	eProjectionDistanceTypeUnknown = -1,
	eConstantAlt                   = 0,
	eObjectAlt                     = 1
};

//覆盖区域的边界类型//0=Global; 1=LatLon Region; 2=Latitude Bounds; 3=Latitude Line; 4=Lontitude Line; 5 = custom region; 6=custom boundary
enum ECvBounds
{
	eBoundsGlobal = 0,
	eBoundsLatLonRegion = 1,
	eBoundsLat = 2,
	eBoundsLatLine = 3,
	eBoundsLonLine = 4,
	eBoundsCustomRegions = 5,
	eBoundsCustomBoundary = 6
};

//间隔类型: 0 = Area; 1 = Distance; 2 = Lat / Lon
enum ECvResolution
{
	eResolutionArea     = 0,
	eResolutionDistance = 1,
	eResolutionLatLon   = 2
}; 

//品质因子类型
enum EFmDefinitionType
{
	eFmSimpleCoverage = 0,			//简单覆盖
	eFmNAssetCoverage = 1,			//多重覆盖
	eFmCoverageTime,					//覆盖时间
	eFmRevisitTime,							//重访时间
	eFmAccessDuration,					//访问时长
	eFmNumOfAccesses,				//访问次数
	eFmNumberOfGaps,					//覆盖间隔次数
	eFmAccessSeparation,				//访问间隔
	eFmTimeAverageGap,				//时间平均间隔
	eFmResponseTime,					//响应时间
	eFmConstraint,							//可见性约束
	eFmDilutionOfPrecision,				//精度衰减因子
	eFmAgeOfData,							//数据时龄
	eFmSystemResponseTime,		//系统响应时间
	eFmSystemAgeOfData,				//系统数据时龄
	eFmNavigationAccuracy,			//导航精度
	//eFmAttitudeCovariance,	// 补充
	//eFmCrdnVector,			// 补充
	//eFmCrdnCalcScalar,		// 补充	/// Scalar Calculation ???
	//eFmPointingDOP,		    // 补充
	//eFmPointingAccuracy  	// 补充
};

//有效条件类型
enum EFmSatisfactionType
{
	eFmGreaterThan = 1,		//>
	eFmAtLeast = 2,				//>=
	eFmEqualTo = 3,				//=
	eFmAtMost = 4,				//<=
	eFmLessThan = 5			//<
};

//计算类型
enum EFmCompute
{
	eMinimum = 1,							//最小值
	eMaximum = 2,							//最大值
	ePercentAbove = 3,					//高于百分比
	eAverage = 4,								//平均值
	eMaxPercentPerDay = 5,			//每日最大百分比
	eMinPerDay = 6,							//每日最小
	eMinPercentPerDay = 7,				//每日最小百分比
	eStdDeviation = 8,						//标准差
	ePerDayStdDev = 9,					//每日标准差
	ePercent = 10,							//百分比
	ePercentPerDay = 11,				//每日百分比
	ePercentPerDayStdDev = 12,	//每日百分比标准差
	ePercentTimeAbove = 13,			//百分比时间高于
	eTotal = 14,									//总计
	eTotalTimeAbove = 15,				//总计时间高于
	eRMS = 16,									//未使用???
	ePercentBelow = 17,					//百分比低于
	ePercentBelowGapsOnly = 18,	//间隔时间百分比低于
	eMaxPerDay = 19,						//每日最大
	eNumPercentBelow = 20,			//百分比低于 的值
	eAvgPerDay = 21,						//每日平均
	eInSpan = 22,								//在范围内
	eInSpanPerDay = 23,					//每日在范围内
	ePerDay = 24,								//每日
	eSum = 32									//总值
};

//结尾间隔段
enum EFmEndGapOption
{
	eIgnore = 0,			//最小
	eInclude = 1			//最大
};

//约束类型
enum EFmConstraint
{
	eFmAltitude = 1,
	eFmAngularRate = 2,
	eFmAzimuthAngle = 3,
	eFmAzimuthRate = 4,
	eFmElevationAngle = 5,
	eFmElevationRate = 6,
	eFmLOSLunarExclusion = 7,
	eFmLOSSunExclusion = 8,
	eFmLunarElevationAngle = 9,
	eFmSunElevationAngle = 10,
	eFmPropagationDelay = 11,
	eFmRange = 12,
	eFmRangeRate = 13
};

//跨对象类型
enum EFmAcrossAssets
{
	eFmAcsMinimum = 1,
	eFmAcsMaximum = 2,
	eFmAcsAverage = 4,
	eFmAcsSum = 32
}; 

//方法类型
enum EFmMethod
{
	eFmDopNone = -1,
	eFmGDOP = 0,
	eFmPDOP = 1,
	eFmHDOP,
	eFmVDOP,
	eFmPDOP_3,
	eFmHDOP_3,
	eFmVDOP_3,
	eFmTDOP
};

//类型
enum EFmComputeType
{
	eFmDopOverdetermined = 0,
	eFmDopBestFour = 1,
	eFmDopBestN,
	eFmDopBestFourAcc,
	eFmDopBestNAcc
};

//无效值类型
enum EFmInvalidValueActionType
{
	eInvalidValueActionInclude = 0,
	eInvalidValueActionIgnore = 1
};

//取色类型
enum EFmGfxColorMethod
{
	eColorRamp = 0,
	eExplicit = 1
};

//轮廓线插值类型
enum EFmGfxContourType
{
	eBlockFill = 0,
	eSmoothFill = 1
};

//插值采样类型
enum EFmGfxSampleType
{
	eSampleSizeLowRes,
	eSampleSizeMedRes,
	eSampleSizeHiRes,
	eSampleSizeCustom
};

//接收器模型类型
enum EReceiverModelType
{
	eReceiverModelTypeUnknown = -1,
	eReceiverModelTypeSimple = 0,
	eReceiverModelTypeMedium = 1,
	eReceiverModelTypeComplex = 2
};

//天线极化类型
enum EPolarizationType {
	ePolarizationTypeUnknown = -1,
	ePolarizationTypeLinear = 0,
	ePolarizationTypeHorizontal = 1,
	ePolarizationTypeVertical   = 2,
	ePolarizationTypeLHC = 3,
	ePolarizationTypeRHC = 4
};

//天线极化参考轴
enum EPolarizationReferenceAxis
{
	ePolarizationReferenceAxisX = 0,
	ePolarizationReferenceAxisY = 1,
	ePolarizationReferenceAxisZ = 2
};

//链路裕量类型
enum ELinkMarginType
{
	eLinkMarginTypeNone             = 0,
	eLinkMarginTypeFluxDensity      = 1,
	eLinkMarginTypeRip              = 2,
	eLinkMarginTypeRcvdCarrierPower = 3,
	eLinkMarginTypeCOverN           = 4,
	eLinkMarginTypeCOverNo          = 5,
	eLinkMarginTypeEbOverNo         = 6,
	eLinkMarginTypeBer              = 7
};

//解调器类型 数字载波调制类型
enum EDemodulatorModelType { 
	eDemodulatorModelTypeUnknown = -1,
	eDemodulatorModelTypeBPSK = 0,
	eDemodulatorModelTypeQPSK = 1,
	eDemodulatorModelType8psk = 2,
	eDemodulatorModelType16psk = 3,
	eDemodulatorModelTypeBPSKBCH_511_259 = 4,
	eDemodulatorModelTypeBPSKConv_4_3_8 = 5
};

//滤波器类型
enum ERFFilterModelType {
	eRFFilterModelTypeUnknown = -1,
	eRFFilterModelTypeBessel = 0,
	eRFFilterModelTypeButterworth = 1,
	eRFFilterModelTypeChebyshev = 2,
	eRFFilterModelTypeGaussianWindow = 3,
	eRFFilterModelTypeRaisedCosine = 4
};

//系统噪声温度计算类型
enum ENoiseTempComputeType {
	eNoiseTempComputeTypeCalculate = 0,
	eNoiseTempComputeTypeConstant = 1
};

//天线模型类型
enum EAntennaModelType {
	eAntennaModelTypeUnknown = -1,
	eAntennaModelTypeGaussian = 0,
	eAntennaModelTypeIsotropic = 1,
	eAntennaModelTypeParabolic = 2,
	eAntennaModelTypeExternal = 3
};

//发送器模型类型
enum ETransmitterModelType
{
	eTransmitterModelTypeUnknown = -1,
	eTransmitterModelTypeSimple  = 0,
	eTransmitterModelTypeMedium = 1,
	eTransmitterModelTypeComplex = 2,
	eReTransmitterModelTypeSimple = 3,
	eReTransmitterModelTypeMedium = 4,
	eReTransmitterModelTypeComplex = 5
};

//调制器类型 数字载波调制类型
enum EModulatorModelType {
	eModulatorModelTypeUnknown = -1,
	eModulatorModelTypeBPSK = 0,
	eModulatorModelTypeQPSK = 1,
	eModulatorModelType8psk = 2,
	eModulatorModelType16psk = 3,
	eModulatorModelTypeBPSKBCH_511_259 = 4,
	eModulatorModelTypeBPSKConv_4_3_8 = 5,
	eModulatorModelTypePCM_FM = 6,
	eModulatorModelTypeCPM = 7
};

//行星位置资源类型
enum EPlPositionSourceType {
	ePosUnknown			= -1,
	ePosFile					= 0,
	ePosCentralBody	= 1
};

//覆盖性对象是否参与计算
enum ECvAssetStatus
{
	eActive = 0,
	eInactive = 1
};

//时间类型
enum ETimeType
{
	eUTCTIME = 0,
	eRELATIVETIME = 1
};

//批量坐标转换工具转换参数
enum EDataSequence
{
	eTIME = 0,
	ePOSITION = 1,
	eVELOCITY = 2
};

//文件类型
enum EImportExportFileType
{
	eTxt = 0,		
	eEPHEMERIS = 1
};

//VGT角类型
enum ECrdnAngleType
{
	eCrdnAngleTypeBetweenVectors = 0,
	eCrdnAngleTypeBetweenPlanes = 1,
	eCrdnAngleTypeDihedralAngle = 2,
	eCrdnAngleTypeRotation = 3,
	eCrdnAngleTypeToPlane = 4,
	eCrdnAngleTypeConstant = 5,
};

//VGT轴类型
enum ECrdnAxesType
{
	eCrdnAxesTypeAlignedAndConstrained = 0,
	eCrdnAxesTypeAngularOffset = 1,
	eCrdnAxesTypeFixed = 2,
	eCrdnAxesTypeFixedAtEpoch = 3,
	eCrdnAxesTypeLaunch = 4,
	eCrdnAxesTypeLaunchInertial = 5,
	eCrdnAxesTypeLagrangeLibration = 6,
	eCrdnAxesTypeSpinning = 7,
	eCrdnAxesTypeTopocentric = 8,
	eCrdnAxesTypeTrajectory = 9,
};

//VGT面类型
enum ECrdnPlaneType
{
	eCrdnPlaneTypeNormal = 0,
	eCrdnPlaneTypeQuadrant = 1,
	eCrdnPlaneTypeTrajectory = 2,
	eCrdnPlaneTypeTriad = 3,
	eCrdnPlaneTypeTwoVectors = 4
};

//VGT点类型
enum ECrdnPointType
{
	eCrdnPointTypeBPlane = 0,
	eCrdnPointTypeFixedInSystem = 1,
	eCrdnPointTypeFixedAtEpoch = 2,
	eCrdnPointTypePlaneIntersection = 3,
	eCrdnPointTypeLagrangeLibration = 4,
	eCrdnPointTypePlaneProjection = 5
};

//VGT固定点坐标类型
enum ECrdnPointCoordType
{
	eCoordTypeCartesian = 0,
	eCoordTypeSpherical = 1
};

//VGT系统类型
enum ECrdnSystemType
{
	eCrdnSystemTypeAssembled = 0,
	eCrdnSystemTypeLaunch = 1,
	eCrdnSystemTypeLaunchInertial = 2,
	eCrdnSystemTypeTopocentric = 3
};

//VGT向量类型
enum ECrdnVectorType
{
	eCrdnVectorTypeAcc = 0,//加速度向量
	eCrdnVectorTypeAngularVelocity = 1,//角速度向量
	eCrdnVectorTypeCrossProduct = 2,//叉积向量
	eCrdnVectorTypeDerivative = 3,//导数向量
	eCrdnVectorTypeDisplacement = 4,//位移向量
	eCrdnVectorTypeFile = 5,//向量文件
	eCrdnVectorTypeFixedInAxes = 6,//固定向量
	eCrdnVectorTypeTwoPlanesIntersection = 7,//交线向量
	eCrdnVectorTypeLinearCombination = 8,//线性组合向量
	eCrdnVectorTypeOrbitNormal = 9,//轨道向量
	eCrdnVectorTypeProjection = 10,//投影向量
	eCrdnVectorTypeProjectAlong = 11,//方向投影向量
	eCrdnVectorTypeReflection = 12,//反射向量
	eCrdnVectorTypeScaled = 13,//缩放向量
	eCrdnVectorTypeVelocity = 14 //速度向量
}; 

enum ELibrationPoint {
	eLibrationPointL1 = 1,
	eLibrationPointL2 = 2,
	eLibrationPointL3 = 3,
	eLibrationPointL4 = 4,
	eLibrationPointL5 = 5,
	eLibrationPointPrimary = 6,
	eLibrationPointSecondary = 7,
};

enum EAttitudeType
{
	eAttitudeQuaternion,
	eAttitudeEuler,
	eAttitudeYPR,
};

enum ETrajectoryAxesType {
	eAxesVVLH,
	eAxesLVLH,
	eAxesICR,
	eAxesVNC,
	eAxesRIC,
	eAxesBBR
};

enum EPlaneQuadrant {
	eXY,
	eYX,
	eXZ,
	eZX,
	eYZ,
	eZY
};

enum ESignalSense
{
	eSignalSenseTransmit = -1, // 发射器
	eSignalSenseReceive = 1 // 接收器
};

enum EInheritDimensionType {
	eNone,
	eFromA,
	eFromB
};

//量纲单位
enum EDimension
{
	eDimDynamic = -1,       ///< 动态量纲，需要调用函数动态获取，见：CDynProperty::GetTrait  和 AsEDataRole::eAsDimRole
	eDimNoUnit = 0,        ///< 单位量纲
	eDimDistance = 1,        ///< Distance                        
	eDimTime = 2,        ///< Time                            
	eDimDate = 3,        ///< Date                            
	eDimAngle = 4,        ///< Angle                           
	eDimRate = 5,        ///< Velocity                        
	eDimAngleRate = 7,        ///< Angular Velocity                
	eDimMass = 8,        ///< Mass                            
	eDimPower = 9,        ///< Power                           
	eDimFrequency = 10,       ///< Frequency                       
	eDimAccel = 11,       ///< Acceleration                    
	eDimArea = 12,       ///< Area (Distance^2)               
	eDimGravParam = 13,       ///< Gravitational Param 万有引力常数
	eDimRateSqrd = 14,       ///< Velocity^2                      
	eDimAreaRate = 15,       ///< Area/Time
	eDimGravParamCB = 16,       ///< Celestial Gravitational Param 天体引力系数
	eDimAngleSqrd = 17,       ///< Angle^2          
	eDimVoltage = 18,       ///< Volt
	eDimAmpere = 19,       ///< Ampere
	eDimTemperature = 22,       ///< Temperature                     
	eDimRatio = 24,       ///< Ratio i.e dB                    
	eDimPowerAreaDensity = 28,       ///< Power Area Density unit(单位面积功率，例如SolarFlux)     
	eDimPowerSpectralDensity = 29,       ///< Power Spectral Density unit(单位频率功率)     
	eDimForce = 30,       ///< Force                           
	eDimPressure = 31,       ///< Pressure                        
	eDimVolume = 34,       ///< Volume (Distance^3)             
	eDimDensity = 35,       ///< Density (Mass/Distance^3)       
	eDimFtoP = 36,       ///< Force Per Pressure              
	eDimFtoPSqrd = 37,       ///< Force Per Pressure Squared      
	eDimFtoPCubed = 38,       ///< Force Per Pressure Cubed        
	eDimInvP = 39,       ///< Inverse Pressure                
	eDimMassRate = 42,       ///< Mass per small time unit        
	eDimForceRate = 43,       ///< Force per small time unit       
	eDimTorque = 46,	    ///< Torque  
	eDimAngMomentum = 47,		///< Angular momentum 
	eDimAngleAccel = 48,		///< Angular acceleration 
	eDimMomentOfInertia = 50,		///< moment of inertia 转动惯量
	eDimFile = 51,       ///< 文件，给对象属性用，支持通过属性配置接口自动处理相关逻辑
	eDimEnd                               ///< 此枚举请不要赋值，量纲结尾标志用 add by ccn 260120
};

enum EMeanOscType {
	eOsc,
	eKozaiIzsakMean,  //K
	eBroLydMeanLong,  //BLL
	eBroLydMeanShort, //BLS
};

enum EOrbitVectorType {
	eOrbitVectorEcc,
	eOrbitVectorPeriapsis,
	eOrbitVectorApoapsis,
	eOrbitVectorAngMomentum,
	eOrbitVectorNormal,
};

//脉冲频率类型
enum ESnVOPulseFrequencyPreset
{
	ePulseFrequencyFast		= 0,	//Fast: 0.333 Hz.
	ePulseFrequencyMedium	= 1,	//Medium: 0.167 Hz.
	ePulseFrequencySlow		= 2,	//Slow: 0.083 Hz.
	ePulseFrequencyCustom	= 3		//Custom: user-specified.  默认0.0
};

//位置类型
enum ELLAPositionType
{
	eLLAPosUnknown = -1,
	eLLAPosGeocentric = 0,	
	eLLAPosGeodetic = 1
};

//高级接近分析误差椭球类型
enum EAdvCatEllipType
{
	eACFixed = 0,
	eACFixedOrbitClass,
	eACQuadraticInTime,
	eACQuadInTimeOrbitClass,
	eACCovariance,
	eACCovarianceOffset,
	eACCovProjTCN
};

//高级接近分析误差椭球类型
enum EConjTcaType
{
	eGlobalOnly = 0,
	eLocalOnly,
	eGlobalPlusLocal,
	eLocalPlusEndPoints
};

//接近分析工具过滤器方法
enum ECATMethod
{
	eAnalyticalMethod = 0,
	eNumericalMethod
};

//机动分析工具判断方法
enum EJudMethodType
{
	eConfidenceLevel = 0,   //置信概率
	eMahalanobisDistar      //马氏距离
};

//机动分析工具检测参数
enum EOrbitalElemType
{
	eSemimajorAxis = 0,   //半长轴
	eInclination,         //倾角
	eRAAN                 //升交点赤经
};

//机动分析工具机动量估计方法
enum EEstMethodType
{
	eCrossPropagation = 0,   //交叉弧段预报估计
	eTimeOfMostOutliers                    //引起最多异常点的数据时刻
};

//机动分析工具平滑方法
enum ESmoothMethodType
{
	eRLOWESS = 0,   //鲁棒低阶局部加权回归
	eLOWESS,        //低阶局部加权回归
	eNoSmoothing    //不平滑
};

//区域目标类型
enum EAreaType
{
	ePattern,			//模式
	eEllipse,			//椭圆
};

//获取轨道数据的数据类型
enum EDataType
{
	eDataLLA = 0,   //纬经高
	eDataPosVel,    //位置速度
	eDataPos        //位置
};

//获取轨道数据所支持的坐标系类型
enum EDataCoorinateSystem
{
	eDataCBF = 0,   //纬经高
	eDataCBI,       //位置速度
};

//刈幅类型
enum EVeGfxElevation
{
	eElevationUnknown = 0,
	eElevationGroundElevation,					//地面仰角
	eElevationVehicleHalfAngle,					//飞行器半锥角
	eElevationSwathHalfWidth,						//刈幅半幅宽
	eElevationGroundElevationEnvelope,     //地面仰角包络
	eElevationVehicleHalfAngleEnvelope,     //飞行器半锥角包络
};

//刈幅显示设置类型
enum EVeGfxOptions
{
	eOptionsNoGraphics = 0,		//不显示
	eOptionsEdgeLimits,				//显示边缘
	eOptionsFilledLimits				//显示填充
};

//可见性报告类型
enum EAccessReportType
{
	eACCESS_ERROR_REP = -1,
	eACCESS_INTRVL_REP = 0,		///<可见性报告
	eACCESS_AER_REP,				///<可见AER报告
	eACCESS_AER_RATE_REP,		///<可见性参数变化率报告
	eNACCESS_INTRVL_REP,			///<不可见报告
	eNACCESS_AER_REP,			///<不可见AER报告
	eACCESS_COMM_REP,		///<5-通信报告
	eACCESS_SUMMARY_REP,			///<可见性统计报告
	eACCESS_AER_SUMMARY_REP,		///<可见AER统计报告
	eNACCESS_SUMMARY_REP,		///<不可见统计报告
	eACCESS_INTRVL_REP_ELAPSED,		///<可见性报告（相对时）
	eNACCESS_INTRVL_REP_ELAPSED,		///<不可见报告（相对时）
	eACCESS_SUMMARY_REP_ELAPSED,		///<可见性统计报告（相对时）
	eNACCESS_SUMMARY_REP_ELAPSED,	///<不可见统计报告（相对时）
	eACCESS_RANGE_RATE_REP,		///<可见性距离变化率报告
	
	eACCESS_HLANGLE_REP,			///<可见俯仰角曲线
	eACCESS_AZIMUTHANGLE_REP,	///<可见方位角曲线
	eACCESS_DISTANCE_REP,		///<可见视线距曲线
	eACCESS_ANGLERATE_REP,		///<可见角度变化率曲线
	
	eACCESS_ANGLEPOLAR_REP,		///<可见俯仰角方位角极坐标曲线
	eACCESS_BIE_REP,				///<可见时段百分比饼图
	eACCESS_TASKBIE_REP,			///<全任务周期可见百分比饼图
	
	eACCESS_CUSTOM_REP			///<可见性自定义报告
};

//覆盖性报告类型
enum ECoverageReportType
{
	eCOVERAGE_INTRVL_REP,			///<覆盖分析报告
	eCOVERAGE_FOM_REP,				///<品质参数值
	eCOVERAGE_SATISFACTION_REP,		///<有效覆盖报告
	eCOVERAGE_DAILY_REP,				///<每日覆盖分析报告
	eCOVERAGE_FOM_STATIC_REP,		///<品质参数统计报告
	eCOVERAGE_PROBABILITY_OF_COVERAGE_REP,	///<覆盖概率报告
	eCOVERAGE_UNCOVERAGE_REP,		///<未覆盖报告
	eCOVERAGE_INTRVL_REP_ELAPSED,		///<覆盖分析报告（相对时）
	eCOVERAGE_SATISFACTION_REP_ELAPSED,	///<有效覆盖报告（相对时）
	eCOVERAGE_UNCOVERAGE_REP_ELAPSED,	///<未覆盖报告（相对时）
	
	//eCOVERAGE_ALL_DOPS_REP,			///<精度衰减因子报告
	//eCOVERAGE_ALL_ACC_REP,			///<导航精度报告
	//eCOVERAGE_BEST_N_REP,			///<最优N报告
	//eCOVERAGE_BEST_N_ACC_REP,		///<最优N报告(Acc)

	//eCOVERAGE_CUSTOM_REP,			///<自定义覆盖分析报告
};

//高度参考类型
enum EAltRefType
{
	eWGS84,
};

//历元类型
enum ECrdnSmartIntervalState
{
	eCrdnSmartIntervalStateExplicit,	///<显式使用自定义历元
	eCrdnSmartIntervalStateImplicit		///<隐式使用场景历元
};