git
---

Git是目前世界上最先进的分布式版本控制系统（没有之一）。

# 学习方法
下面提供两种学习git的途径。
1. 速成型。
2. 一步一脚印型。

## 速成型

以下两个教程，可用于速成学习。建议先看《Git教程》，再用《git简易指南》来回顾和练习。

Git教程
> http://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000

git - 简易指南
> http://www.bootcss.com/p/git-guide/

## 一步一脚印型

速成教程，讲的会简易一些，会省去一些不常用或者非必要性的功能的讲解；相对而言，一步一脚印型，则会讲的细致一些，面面俱到，并且还会介绍一些原理性的东西，以便于记忆及更好的掌握。

这种路径，自然就是去看经典的书籍啦。给大家推荐一本书，《Pro Git》，看完前3章内容（起步、Git基础、Git分支），将完全可以胜任日常的操作。大家可以在本项目仓库的"专题资料/git"中找到本书的中文和英文版。

# 远程仓库

git作为分布式版本控制系统，可以仅用于维护本地的一个小仓库，也可以将本地的仓库推送到服务器上面，以供多人访问或者异地办公。要想使用远程仓库，并非要去租用一个服务器并且去学习搭建git服务。有很多网站提供了免费的git仓库托管，比如github、csdn、码云。本培训资料就是一个git仓库噢，托管在码云上面，你不会还不知道吧？

# 图形界面工具

除了使用命令行的方式操作git，还可以通过一些图形界面工具来操作，比如Tortoisegit。另外，如果是使用了基于eclipse二次开发的IDE，可以安装EGit插件。瑞萨的e2studio，就是基于eclipse的。关于EGit的使用，可以参考如下博客。也可以在安装EGit插件后，在eclipse中的Help->Help Contents中查看。

Eclipse上GIT插件EGIT使用手册
> http://blog.csdn.net/luckarecs/article/details/7427605

不过，我建议大家还是从命令行工具入门，这样有助于掌握基本的操作及原理，并且经典的教程也都是讲命令行操作的，如果起初就想使用图形界面工具的话，是找不到好的教程的。在有了基础之后，再去选择是用命令行还是图形界面，或者是混合使用。