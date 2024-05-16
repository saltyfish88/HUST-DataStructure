结束了,垃圾课设,只有82分

## 文件说明
* LastTry
  > Qt代码
* Total
  > 命令行版本代码
* Windows
  > `Windows`下可执行文件
* 资料
  > 数独问题相关论文，包括任务书中参考目录中的论文以及自己找到的一些论文
  - `2018-数据结构实验（2017级）-更正版.rar` ：任务书以及报告格式说明书压缩包
  - `CS1703-U201714668-葛松.docx` ：**报告**
  - `README.md`：使用说明

## Total 为SAT求解器

使用方法：在linux环境下

```shell
cd build
# 求解filename
./DSCourseDesign -f filename
# 求解filename 并打印出内部储存结构
./DSCourseDesign -p -f filename
# 求解filename 并将结果保存为同名的拓展名为.res的文件，注意可能会出现由于文件名带有路径而导致出现乱码的情况
./DSCourseDesign -s -f filename
```

若要在Windows下运行，请自行编译

可以通过修改selectVar.cpp 中最后一行SelectVar()的注释来使用不同的选取变元方式

## LastTry 为Qt的数独游戏源码

## Windows 为 windows 下的Qt运行可执行文件

使用方法

双击CourseDesign.exe

1. 点击`generate` 会生成一个新的数独并覆盖当前的数据，注意可能生成需要一些时间
2. 点击`submit` 可以提交当前的答案，正确会以绿色显示，错误会以红色显示
3. 点击 `solve` 可以通过SAT求解器求得正确答案
4. 点击`clear`可以清除所有已填位置

极少情况下可能会出现缺少dll的提示，请下载缺少的dll文件放在windows目录下即可正常运行