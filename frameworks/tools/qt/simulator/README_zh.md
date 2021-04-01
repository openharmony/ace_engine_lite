# JS应用开发框架模拟器调试工程使用说明



1、环境说明

​      本工程基于QT Creator搭建，开发者使用前需要下载QT Creator。下载地址：https://www.qt.io/offline-installers ，建议下载稳定版本。

​    下载完成后双击安装程序进行安装，安装前需要注册账号（已注册直接登录）。登录完成后，按照引导界面进行安装即可，需要注意在选择组件界面时要勾选minGW组件。

2、打开工程

​      打开QT Creator，依次点击 文件----打开文件和项目，在弹出的文件选择框中选择工程项目（工程项目路径：\foundation\ace\ace_engine_lite\frameworks\tools\qt\simulator\simulator.pro）。第一次打开项目时，需要在Configure Project界面的kits列表中勾选minGW，然后点击configure project按钮加载工程。

3、设置JS bundle路径

​      simulator.pro工程加载完成后，在左边的项目树中依次展开 entry----Sources，双击main.cpp文件，修改jsAbility.Launch("D:\\app\\slider","MyApplication",0)函数中的第一个参数为要运行的jsbundle路径。

4、编译

​     依次点击 构建---编译项目，或者直接在项目树中右键，在右键菜单中选择重新构建即可。

5、调试

​     编译完成后，点击调试按钮即可运行调试项目。