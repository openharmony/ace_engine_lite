# JS应用开发框架模拟器调试工程使用说明



1、环境说明

​    本工程基于QT Creator搭建，开发者使用前需要下载QT Creator。下载地址：https://www.qt.io/offline-installers ，建议下载稳定版本。下载完成后双击安装程序进行安装，安装前需要注册账号（已注册直接登录）。登录完成后，按照引导界面进行安装即可，需要注意在选择组件界面时要勾选minGW(两个列表中的minGW选项都要勾选)组件。

2、打开工程

​    打开QT Creator，依次点击 文件----打开文件和项目，在弹出的文件选择框中选择工程项目（工程项目路径：'\foundation\ace\ace_engine_lite\frameworks\tools\qt\simulator\simulator.pro'）。第一次打开项目时，需要在Configure Project界面的kits列表中勾选minGW（仅勾选minGW），然后点击configure project按钮加载工程。

3、编译

​    依次点击 构建---编译项目，或者直接在项目树中右键，在右键菜单中选择重新构建即可。

4、调试

​    编译完成后，点击调试按钮即可运行调试项目。

5、配置属性参数（首次必须配置jsBundle路径，否则无法运行js应用）

​    项目运行后，在桌面程序下面的文本框中选择jsBundle路径，然后点击重启按钮即可加载运行js应用。