.model small
.stack
.data
.code
Begin: MOV BX,0  ;用于存放四位的16进制数
       MOV CH,4  ;ch初始为4表示输入四位数字+-
       MOV CL,4  
INPUT: SHL BX,CL ;将前面输入的数左移4位
       MOV AH,1  ;从键盘取数
       INT 21H;读取1个4字节数放入AL
       CMP AL,30H ;<0吗？
       JB INPUT   ;不是"0~F"的数重新输入
       CMP AL,39H ; 是"0~9"吗？JB表示小于跳转
       JA AF      ;不是，转"A~F"的处理 JA表示大于跳转
       AND AL,0FH ;转换为：0000B~1001B 0到9ASCII码为30-39所以去掉高四位转为0-9
       JMP BINARY
AF:    AND AL,11011111B ;转换为大写字母
       CMP AL,41H  ;判断<A？
       JB INPUT    ;不是"A~F"的数重新输入 JB小于跳转
       CMP AL,46H  ;>F吗？
       JA INPUT    ;不是"A~F"的数重新输入  jA大于跳转
       AND AL,0FH  ;转换为1010B~1111B  0FH = 00001111 A-F 41-46,去掉高四位1-6
       ADD AL,9		;+9变为代表的值
BINARY: OR BL,AL   ;将键盘输入的数进行组合？？？？？
        DEC CH	   ;ch -1跳转至input
        JNZ INPUT
        MOV CX,16  ;将16位二进制数一位位地转换成ASCII码显示
DISP:   MOV DL,0
        ROL BX,1   ;循环移位一个
        RCL DL,1   ;带CF的移位一个？？？？
        OR DL,30H
        MOV AH,2   ;		进行显示
        INT 21H
        LOOP DISP
  STOP: ret
  end begin





