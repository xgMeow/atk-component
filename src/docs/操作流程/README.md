\page component_flow 快速上手

Component 模式通过库文件提供的函数接口对 ATK 进行操作与计算，所提供的变量均需使用 Set 函数设置变量值，暂不支持直接设置。Component 模式使用 IAtkObjectRoot 类作为初始操作指针。

本组文档按语言分别给出接入 Component 模式、编写并运行一个完整案例的操作流程。各语言案例均完成同一项任务：半径为 6700 km 的近地停泊轨道（LEO）上的卫星，经机动规划快速转移至半径为 42164.197 km 的地球同步轨道（GEO），并输出卫星数据报告与想定文件。

各语言的操作流程：

- \subpage component_flow_cpp "C++ 操作流程"
- \subpage component_flow_java "Java 操作流程"
- \subpage component_flow_python "Python 操作流程"
- \subpage component_flow_MATLAB "MATLAB 操作流程"
- \subpage component_flow_octave "Octave 操作流程"

接口参考：Component 模式的类与函数接口按主题划分为对象、工具、机动规划、可视化四组，见 \ref by_object "对象"、\ref by_tool "工具"、\ref by_maneuver "机动规划"、\ref by_vis "可视化"。
