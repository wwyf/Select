# 选课系统
github: https://github.com/WalkerYF/Select

## 1. 提供功能
1. 学生端
    1. 注册一个学生
    2. 根据所输入的课程名称选课
    3. 退课
    4. 查看自己选课情况
    5. 查看某课程或所有课程选课情况（该课程最大人数还有已选人数）
2. 教师端
    1. 教师端不提供注册，需要自己写入教师账户数据库中
    2. 可以增加课程
    3. 可以查看课程信息（包括选课人数及选课名单）
    4. 暂时不可以删除课程

## 2. 快速入门

### 初次打开
程序会自动在./src/data目录下寻找数据文件，并加载 


初次使用没有课程信息  
所以必须使用教师账号密码登录来添加课程  
(教师账号密码可自己向数据文件中添加)  
(默认：用户名：admin， 密码：admin)

### 学生端界面
```
---------------------------------------
      Welcome to the student client
      Your are  ×××××××××
       s : select a course
       r : return a course
       w : watch your classes
       p : print a course
       a : print all course
       q : quit the client
---------------------------------------
```
### 教师端界面
```
---------------------------------------
      Welcome to the teacher client
      Your are  ××××××××
       w : watch  a course
       a : add    a course
       p : print all course
       q : quit the client
---------------------------------------
```

### 退出系统
退出系统之前   
系统自动用程序内的数据直接覆盖原数据文件保存    
然后才会退出  

## 3. 文件说明 

###  ./bin/data： 存放着各种数据

1. ./bin/data/lesson 存放课程数据
2. ./bin/data/student 存放学生信息
3. ./bin/data/teacher 存放老师信息

> 注意：   
> 程序中存放数据的文件的路径是以**相对路径**形式存放在程序中   
> 请务必在bin目录下运行程序，才能成功加载数据

### 其他文件
1. ./src/makefile 在./../bin/下生成可执行文件(注意是相对目录)   
这里同样需要在src目录下调用make命令方可正确创建可执行文件
2. ./bin/test.in  测试数据 用于创建课程
3. ./bin/test2.in 测试数据 用于学生选课


## 4. 已知bug
课程名字不能有空格


## 5. 未实现功能
也有点多   
也不一一列举了   


## 6. 开发环境说明
   在ubuntu16.04 下开发，在Linux环境和win环境测试均可用

# 更新日志

## v1.2    
修复在某些情况下无法退出系统的bug
修复在某些情况学生可以选已经满人的课程的bug

## v1.3
修复默认命令不能直接回车跳过的bug
修正了若干拼写错误