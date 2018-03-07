Git
===
## 学习资料
- [ProGit中文版][id] 
 [id]:https://git-scm.com/book/zh/v2

- [廖雪峰的Git教程][id]
[id]:http://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000

- [Git-简易指南][id]
[id]:http://www.bootcss.com/p/git-guide/


## 安装Git

在Windows上安装Git，可以从Git官网直接[下载安装程序](https://git-scm.com/downloads)，然后按默认选项安装即可。

安装完成后，在开始菜单找到`Git-->Git Bash`，蹦出一个类似命令行窗口的东西，说明Git安装成功！

安装完成后，在命令行输入：

```
$ git config --global user.name "Your Name"
$ git config --global user.email "email@example.com"
```

注意`git config`命令的`--global`参数，表示你这台机器上所有的Git仓库都会使用这个配置，当然也可以对某个仓库指定不同的用户名和Email地址。

>首先明确，所有版本控制系统，只能跟踪文本文件的改动，比如TXT文件，网页，所有程序代码等等。而视频，图片这些二进制文件，git是没法跟踪的。Microsoft的Word格式也是二进制格式。因此，版本控制系统没法跟踪Word文件的改动，如果要真正使用版本控制系统，就要以纯文本方式编写文件。

##创建版本库

**选择一个合适的地方，创建一个空目录：**

>`mkdir --folder`此命令为创建一个文件夹
>
>`cd --path`change directory  的简写，改变目录的意思，如`cd F:/GitPlace`切换F盘下面的GitPlace目录。
>
>`pwd` print working directory，打印工作目录，他会显示我们当前所在的目录路径。
>
>`ls` list，列出当前目录中的所有文件，可以通过`ls -ah`命令看见创建的Git仓库

**初始化一个Git仓库，使用```git init```命令。**
```
$ git init
Initialized empty Git repository in F:/windows/Desktop/C程序设计/我的程序设计/.git/
```
**添加文件到Git仓库，分两步：**
-  第一步，使用命令```git add <file>```，注意，可反复多次使用，添加多个文件；

>当需要add文件夹时使用命令`git add ./dir`dir指文件夹floder名称

-  第二步，使用命令```git commit```，完成。

 ***格式如下：注意用  `git commit`命令后面要跟  `-m"explain "`注释***

>$ git commit -m "wrote a readme file"
>[master (root-commit) cb926e7] wrote a readme file
> 1 file changed, 2 insertions(+)
> create mode 100644 readme.txt



##时光穿梭机
-  要随时掌握工作区的状态，使用```git status```命令。
-  如果```git status```告诉你有文件被修改过，用```git diff``` 可以查看修改内容。

##版本回退
-  HEAD指向的版本就是当前版本，因此，Git允许我们在版本的历史之间穿梭，使用命令```git reset --hard commit_id```。
-  穿梭前，用```git log```可以查看提交历史，以便确定要回退到哪个版本。

> 可以加上`--pretty=oneline`参数

```
$ git log --pretty=oneline
3628164fb26d48395383f8f31179f24e0882e1e0 append GPL
ea34578d5496d7dd233c827ed32a8cd576c5ee85 add distributed
cb926e7ea50ad11b8f9e909c05226233bf755030 wrote a readme file
```
> 前面的数字时`commit id`(版本号)

>在Git中，用HEAD表示当前版本，也就是最新的提交3628164...882e1e0（注意我的提交ID和你的肯定不一样），上一个版本就是`HEAD^`，上上一个版本就是`HEAD^^`，当然往上100个版本写100个^比较容易数不过来，所以写成HEAD~100。

- 回退到以前版本，可以使用`git reset`命令

```
$ git reset --hard HEAD^
HEAD is now at ea34578 add distributed
```

-  要重返未来，用```git reflog```查看命令历史，以便确定要回到未来的哪个版本。

```
$ git reflog
ea34578 HEAD@{0}: reset: moving to HEAD^
3628164 HEAD@{1}: commit: append GPL
ea34578 HEAD@{2}: commit: add distributed
cb926e7 HEAD@{3}: commit (initial): wrote a readme file
```
确定了版本号后
```
$ git reset --hard 3628164
HEAD is now at 3628164 append GPL
```


##撤销修改
-  场景1：当你改乱了工作区某个文件的内容，想直接丢弃工作区的修改时，用命令```git checkout -- file```。
-  场景2：当你不但改乱了工作区某个文件的内容，还添加到了暂存区时，想丢弃修改，分两步，第一步用命令```git reset HEAD file```，就回到了场景1，第二步按场景1操作。

> `git reset`命令既可以回退版本，也可以把暂存区的修改回退到工作区。
> 当我们用`HEAD`时，表示最新的版本。


-  场景3：已经提交了不合适的修改到版本库时(已经**commit**)，想要撤销本次提交，参考版本回退一节，不过前提是没有推送到远程库。

##删除文件
-  命令```git rm```用于删除一个文件。如果一个文件已经被提交到版本库，那么你永远不用担心误删，但是要小心，你只能恢复文件到最新版本，你会丢失最近一次提交后你修改的内容。

> 在工作区中用`rm`命令删除了一个文件
> 如果确定也要从版本库中删除该文件，
> 就用命令`git rm <file>`删除掉，并且`git commit -m" "

-  删错了，命令```git checkout```其实是用版本库里的版本替换工作区的版本，无论工作区是修改还是删除，都可以“一键还原”。

## 远程仓库
### SSH公匙
##### 什么是SSH公匙
SSH是一种网络协议，用于计算机之间的加密登录。目前是每一台 Linux 电脑的标准配置。而大多数 Git 服务器都会选择使用 SSH 公钥来进行授权，所以想要在 GitHub 提交代码的第一步就是要先添加 SSH key 配置。
##### 生成SSH公匙
> 可以现在`Git Bash`下输入`ssh`查看是否安装SSH，出现提示命令说明已安装有SSH
一般Windows安装Git Bash都带了SSH的

- 首先先确认一下是否已经有一个公钥了。SSH 公钥默认储存在账户的主目录下的 ~/.ssh 目录。进去看看：
```
$ cd ~/.ssh
$ ls
authorized_keys2  id_dsa       known_hosts
config            id_dsa.pub
```
> 关键是看有没有`something`和`something.pub`来命名的一对文件。这个`something`通常是`id_dsa`或`id_rsa`。有`.pub`后缀的文件就是公匙，另一个是密匙。

- 如果没有上面这两个文件，甚至连`.ssh`这个文件也没有，可以输入`ssh-keygen -t rsa`，然后连续三次回车生成

```
$ ssh-keygen -t rsa

Generating public/private rsa key pair.

Enter file in which to save the key (/c/Users/wangxiao/.ssh/id_rsa): Enter passp               hrase (empty for no passphrase):
Enter same passphrase again:
Your identification has been saved in /c/Users/wangxiao/.ssh/id_rsa.
Your public key has been saved in /c/Users/wangxiao/.ssh/id_rsa.pub.
The key fingerprint is:
SHA256:b/xwR1JvPX21wt4oHv9GL0xbQ/Rlt1tV7mNfbuvUKQU wangxiao@DESKTOP-PNIDKT9
The key's randomart image is:
+---[RSA 2048]----+
|                o|
|               o=|
|             Eo.O|
|            ...=B|
|        S   .oo*@|
|         o  .oB*X|
|          =o.*o*B|
|         ..++.*oo|
|           ...+= |
+----[SHA256]-----+

```
- 然后查看`.pub`公匙文件


```
$ cat ~/.ssh/id_rsa.pub

```

##### Github上添加SSH
> 添加成功后，输入`ssh -T git@github.com `进行测试

##### SSH警告
> 第一次使用Git连接Github时会得到一个警告

```
The authenticity of host 'github.com (xx.xx.xx.xx)' can't be established.
RSA key fingerprint is xx.xx.xx.xx.xx.
Are you sure you want to continue connecting (yes/no)?
```
> 这是因为Git使用SSH连接，而SSH连接在第一次验证GitHub服务器的Key时，需要你确认GitHub的Key的指纹信息是否真的来自GitHub的服务器，输入`yes`回车即可。Git会输出一个警告，告诉你已经把GitHub的Key添加到本机的一个信任列表里了：

```
Warning: Permanently added 'github.com' (RSA) to the list of known hosts.
```
> 这个警告只会出现一次，后面的操作就不会有任何警告了。

- 然后出现下面提示说明成功在GitHub上添加了SSH

```
Hi LittlePrinceWX! You've successfully authenticated, but GitHub does not provide shell access.
```


##添加远程库--GitHub
-  要关联一个远程库，使用命令```git remote add origin git@server-name:path/repo-name.git```；

> **origin**是远程库的名字，当只有一个远程库是，就一般默认使用这个名字

- 查看我们当前项目有哪些远程仓库可以执行如下命令：`git remote -v`
> 如果要删除关联的远程库，可以用如下代码

```
git remote rm origin
```

-  关联后，使用命令```git push -u origin master```第一次推送master分支的所有内容；

> 由于远程库是空的，当我们第一次推送`master`分支时，加上了`-u`参数，Git不但会把本地的`master`分支，还会把本地的`master`分支和远程的`master`分支关联起来。


-  此后，每次本地提交后，只要有必要，就可以使用命令```git push origin master```推送最新修改；

> 分布式版本系统的最大好处之一是在本地工作完全不需要考虑远程库的存在，也就是有没有联网都可以正常工作，而SVN在没有联网的时候是拒绝干活的！当有网络的时候，再把本地提交推送一下就完成了同步，真是太方便了！


###### 报错
在Github里(Create a new repo)创建远程仓库的时候，
如果你勾选了Initial this repository with a README
(就是创建仓库的时候自动给你创建一个README文件)，
那么到了你将本地仓库内容推送到远程仓库(git push -u origin master)的时候
就会报一个**failed to push some refs to  git@github.com:michaelliao/learngit.git**。
```
$ git push -u origin master
To github.com:LittlePrinceWX/njupt_code.git
 ! [rejected]        master -> master (fetch first)
error: failed to push some refs to 'git@github.com:LittlePrinceWX/njupt_code.git'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally. This is usually caused by another repository pushing
hint: to the same ref. You may want to first integrate the remote changes
hint: (e.g., 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```

**这是由于你创建的那个仓库里面的README文件不在本地仓库目录中**，
这是我们可以通过一下命令将内容合并：`$ git pull --rebase origin master`，
这时候就不会报错了，上面是将github仓库文件合并到本地版本库，并没有提交。
接下来只需要把本地文件提交到远程库就行了，代码`$ git push origin master`


##从远程库克隆
要克隆一个仓库，首先必须知道仓库的地址，然后使用git clone命令克隆。
```
git clone git@github.com:LittlePrinceWX/njupt_code.git
```
Git支持多种协议，包括https，但通过ssh支持的原生git协议速度最快。

##创建与合并分支
Git鼓励大量使用分支：
-  查看分支：```git branch```

> 执行 git init 初始化git仓库之后会默认生成一个主分支 master ，
> 也是你所在的默认分支，也基本是实际开发正式环境下的分支，
> 一般情况下 master 分支不会轻易直接在上面操作的，
> 你们可以输入 git branch 查看下当前分支情况：

-  创建分支：```git branch <name>```

> 执行 git branch a 就新建了一个名字叫 a 的分支，
> 这时候分支 a 跟分支 master 是一模一样的内容

-  切换分支：```git checkout <name>```

> 但是可以看到 master 分支前有个 * 号，
> 即虽然新建了一个 a 的分支，但是当前所在的分支还是在 master 上，
> 如果我们想在 a 分支上进行开发，首先要先切换到 a 分支上才行，
> 所以下一步要切换分支
> 
> **git checkout a**
> 
> 执行这个命令，然后再输入 git branch 查看下分支情况：

-  创建+切换分支：```git checkout -b <name>```

> 那有人就说了，我要先新建再切换，未免有点麻烦，有没有一步到位的，聪明：
> 
> git checkout -b a
> 
> 这个命令的意思就是新建一个a分支，并且自动切换到a分支


-  合并某分支到当前分支：```git merge <name>```

> git merge 就是合并分支用到的命令，针对这个情况，需要先做两步，
> 第一步是切换到 master 分支，如果你已经在了就不用切换了，
> 第二步执行 git merge a ，意思就是把a分支的代码合并过来，
> 不出意外，这个时候a分支的代码就顺利合并到 master 分支来了。

-  删除分支：`git branch -d <name>`

> 有新建分支，那肯定有删除分支，
> 假如这个分支新建错了，或者a分支的代码已经顺利合并到 master 分支来了，
> 那么a分支没用了，需要删除，这个时候执行 git branch -d a 就可以把a分支删除了。
> 
> git branch -D
> 
> 有些时候可能会删除失败，比如如果a分支的代码还没有合并到master，
> 你执行 git branch -d a 是删除不了的，
> 它会智能的提示你a分支还有未合并的代码，
> 但是如果你非要删除，那就执行 git branch -D a 就可以强制删除a分支

## git bash 下操作文件及文件夹命令

1.  `cd`change directory 的简写，切换目录
2. `cd ..`回退到上一目录
3. `pwd`print working directory，打印工作目录
4. `ls`list，列出当前目录中的所有文件
5. `touch`新建一个文件
6. `rm`删除一个文件
7. `mkdir`新建一个目录，就是新建一个文件夹
8. `rm -r`删除一个文件夹
9. `mv`移动文件，mv file folder
10. `reset`清屏，把git bash命令窗口中的所有内容清空


## 使用码云

[廖雪峰教程](https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000/00150154460073692d151e784de4d718c67ce836f72c7c4000)

[我的码云](https://gitee.com/b16010810njupt/events)

## 使用GitHub

[知乎-从零开始学习GitHub系列][id]
[id]:https://zhuanlan.zhihu.com/stormzhang?topic=GitHub

[我的GitHub][id]
[id]:https://github.com/LittlePrinceWX