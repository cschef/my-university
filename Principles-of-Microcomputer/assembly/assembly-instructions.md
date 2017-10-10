# 汇编指令系统

下文中用到的标记
```
dest - destination - 目的操作数
src - source - 源操作数
B/W - Byte/Word - 操作数可以是字节数据，也可以是字数据

reg - register - 通用寄存器
sreg - segment register - 段寄存器
mem - memory - 内存单元
```

## 数据传送指令

|通用数据传送指令|||
|:-|:-|:-|
|mov dest,src (B/W)|`dest <- src`|复制字节或字|
|push src (W)|`SP <- SP-2` , `(SP+1)_(SP) <- src`|字进栈|
|pop dest (W)|`dest <- (SP+1)_(SP)` , `SP <- SP+2`|字出栈|
|xchg dest,src (B/W)|`dest <-> src`|交换字节或字|