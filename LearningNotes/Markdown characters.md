### Headers(标题)

Setext-style

    Header 1
    ======
    Header 2
    ------

atx-style
    # Header 1
    ## Header 2
    ...

    ###### Header 6

### Blockquotes(引用)

> This is the **Blockquotes**  


`	> This is the **Blockquotes**   `  (**Shift-Ctrl-Q**)



### Lists

Ordered(numbered)  (**Shift-Ctrl-O**)

1. Red

2. Blue

3. Green





    1. Red

    2. Blue

    3. Green

Unordered(bulleted)   (**Shift-Ctrl-L**)

- Red

- Blue

- Green



        * Red

        * Blue

        * Green



        - Red

        - Blue

        - Green



        + Red

        + Blue

        + Green



Nest Lists

* Colors

 1. Red

 2. Blue

 3. Green

 4. Yellow

   - Dark Yellow

   - Light Yellow

   - Green Yellow





```

* Colors

 1. Red

 2. Blue

 3. Green

 4. Yellow

   - Dark Yellow

   - Light Yellow

   - Green Yellow



```



### Code



A `code span`    (**Ctrl-K**)



    A `code span`



### Fenced Code Blockd(代码块)



    ```

    var your = 'code here';

    ```

Syntax Highlight(语法高亮)



    ```[language name]

    var your = 'code here';

    ```

Javascript

``` [JavaScript]

function syntaxHighlight(a, b) {

    return a + b;

} 

```

```[c]

#include <iostream>



int main(char *argv[]) {

    return -2e3 + 121;

}

```



### Enphasis



Italic - *Italic*(斜体字) 

 

`*Italic*`  (**Ctrl-I**)



Bold - **bold**(黑体字)



`**bold** or __bold__`  (**Ctrl-B**)



Underline - ++underline++



`++underline++` (**Shift-Ctrl-U**)



Highlight - ==highlight==



`==highlight==` (**Ctrl-T**)



### Horizntal Rules



Three or more hyphens(-), asterisks(*), or underscores(_)



Page break



`* * *`



Section break



`- - -`



Margin break (add margin bottom)



`_ _ _`

### Table(GFM)(表格)

| name  | age | gender    | money  |
|-------|:---:|-----------|-------:|
| rhio  | 384 | robot     | $3,000 |
| haroo | .3  | bird      | $430   |
| jedi  | ?   | undefined | $0     |


```
| name  | age | gender    | money  |
|-------|:---:|-----------|-------:|
| rhio  | 384 | robot     | $3,000 |
| haroo | .3  | bird      | $430   |
| jedi  | ?   | undefined | $0     |
```



#### 单元格和表头



使用 | 来分隔不同的单元格，使用 - 来分隔表头和其他行：

```

name | age

---- | ---

LearnShare | 12

Mike |  32

```

name | age

---- | ---

LearnShare | 12

Mike |  32



为了美观，可以使用空格对齐不同行的单元格，并在左右两侧都使用 | 来标记单元格边界：

```

|    name    | age |
| ---------- | --- |
| LearnShare |  12 |
| Mike       |  32 |
```

|    name    | age |
| ---------- | --- |
| LearnShare |  12 |
| Mike       |  32 |

>为了使 Markdown 更清晰，| 和 - 两侧需要至少有一个空格（最左侧和最右侧的 | 外就不需要了）。


##### 对齐

在表头下方的分隔线标记中加入 :，即可标记下方单元格内容的对齐方式：

-  :--- 代表左对齐

-  :--: 代表居中对齐

-  ---: 代表右对齐

```

| left | center | right |
| :--- | :----: | ----: |
| aaaa | bbbbbb | ccccc |
| a    | b      | c     |

```

| left | center | right |
| :--- | :----: | ----: |
| aaaa | bbbbbb | ccccc |
| a    | b      | c     |

>如果不使用对齐标记，单元格中的内容默认左对齐；表头单元格中的内容会一直居中对齐（不同的实现可能会有不同表现）。

##### 插入其他内容

表格中可以插入其他 Markdown 中的行内标记：

```
|     name     | age |             blog                |
| ------------ | --- | ------------------------------- |
| _LearnShare_ |  12 | [LearnShare](http://xianbai.me) |
| __Mike__     |  32 | [Mike](http://mike.me)          |

```

|     name     | age |             blog                |
| ------------ | --- | ------------------------------- |
| _LearnShare_ |  12 | [LearnShare](http://xianbai.me) |
| __Mike__     |  32 | [Mike](http://mike.me)          |


### Links(链接)

Inline - link

`A [Link](http://example.com "Title")`

Reference-style - [link][id]

```

A [Link][id].
[id]: http://example.com "Title"

```

### Image(图片)  

Inline - Image     **(Shift-Ctrl-I)**

`![Alt Text](http://bit.ly/1drEdWK "Title")`

> 文件夹`AltiumDesigner-res`里的图片
	![](AltiumDesigner-res/schematic_1.jpg)

Reference-style Image
   A ![Alt Text][logo].
    [logo]: http://bit.ly/1drEdWK "Title"
Image Style (Haroopad Flavored Markdown)
    ![Alt Text](http://bit.ly/1drEdWK "Title" "width:30px")
    ![Alt Text](http://bit.ly/1drEdWK "Title" "width:30px;float:right")
    ![Alt Text][logo].
    [logo]: http://bit.ly/1drEdWK "Title" "width:50px"

### Math Expression

Inline Math expression
$x^2$  (**Shift-Ctrl-M** )

`$x^2$ or $$x^2$$`

Block Math expression  (**Shift-Ctrl-J**)

```
$
x^2
$

```

### Tasklist

This statement is useful when you create the TODO or Checklist.

example

    - [ ] first task

    - [x] second task is done

    - [ ] third task



- [ ] first task

- [x] second task is done

- [ ] third task

## Shortcuts (快捷键)

##### Markdown Editing

Shortcut                    | Example            | Description       |          
----------------------------|:------------------:|-------------------|:--------:
COMMAND (CTRL) - 1          | #                  | Header 1          |
COMMAND (CTRL) - 2          | ##                 | Header 2          |    
COMMAND (CTRL) - 3          | ###                | Header 3          |
COMMAND (CTRL) - 4          | ####               | Header 4          |
COMMAND (CTRL) - 5          | #####              | Header 5          |
COMMAND (CTRL) - 6          | ######             | Header 6			 |
COMMAND (CTRL) - B          | \*\*Bold\*\*       | bold				 |黑体字
COMMAND (CTRL) - I          | \*Italic\*         | italic			 |斜体字
COMMAND (CTRL) - L          | \[link\](url)      | link  			 |
COMMAND (CTRL) - K          | \`code\`           | inline code		 |行内代码
COMMAND (CTRL) - E          | @\[]()             | embed 			 |
COMMAND (CTRL) - U          | \~~strike~~        | strike			 |删除线
COMMAND (CTRL) - T          | \==highlight==     | highlight		 |
SHIFT - CTRL - I            | \!\[]()            | image			 |图片
SHIFT - CTRL - U            | \+\+underline\+\+  | underline		 |下划线
SHIFT - CTRL - T            | [TOC]              | table of content  |
SHIFT - CTRL - C            | - [ ] task         | task list  		 |任务清单
SHIFT - CTRL - O            | 1. markdown        | ordered list		 |有序列表
SHIFT - CTRL - L            | * haroopad         | unordered list	 |无序列表
SHIFT - CTRL - J            | $math$             | inline math		 |数学符号
SHIFT - CTRL - M            | $$math$$           | block math		 |数学公式
SHIFT - CTRL - Q            | > blockquote       | blockquote		 |引用
SHIFT - CTRL - F            | [^id]              | footnote reference|
SHIFT - CTRL - R            | [^id]: text        | footnote 		 |
SHIFT - ALT - ENTER         | \- \- \-           | section break  	 |分节符
SHIFT - CTRL - ENTER        | \* \* \*           | page break		 |分页符
SHIFT - CTRL - ALT - ENTER  | \_ \_ \_           | sentence break	 |分段符



