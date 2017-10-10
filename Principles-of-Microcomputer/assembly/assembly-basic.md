# 汇编语言基础

## 8086寄存器组

Intel 80x86 cpu
1.8086/80286   16bit字长 --> 寄存器都是16bit
2.80386/80486  32bit字长 --> 寄存器都是32bit

二进制（binary）B  十六进制（hexadecimal）H  十进制（decimal）D（D可省略）

位 × 8 --> 字节 × 2 --> 字 × 2 --> 双字

![](https://dn-anything-about-doc.qbox.me/userid12501labid332time1419944230704)
![](https://dn-anything-about-doc.qbox.me/userid12501labid332time1419944173776)

|数据寄存器|||
|:-:|:-|:-|
|AX|AH-AL|mul,div|
|BX|||
|CX||循环计数|
|DX|||

|地址寄存器||
|:-:|:-|
|SI||
|DI||
|SP||
|BP||

|段寄存器||
|:-:|:-|
|CS|code|
|DS|data|
|ES|extra|
|SS|stack|

|控制寄存器||
|:-:|:-|
|IP||
|FLAGS||

AX=1234H --> AH=12, AL=34 （内存中顺序相反）

## 内存

8086 有 20 根地址线，可访问存储空间为 2^20=1MB，地址从 0 开始编号，00000H~FFFFFH

![](https://dn-anything-about-doc.qbox.me/document-uid12501labid332timestamp1458138725718.png/wm)

