.model small
.stack
.code
Begin:MOV AH,1   ;从键盘输入一个字符
      INT 21H
      CMP AL,'a'   ;输入字符<'a'吗？
      JB STOP
      CMP AL,'z'   ;输入字符>'z'吗？
      JA STOP
      SUB AL,20H  ;转换为大写字母或AND AL,1101 1111B也可以
      MOV DL,AL  ;显示一个字符
      MOV AH,2
      INT 21H
      JMP Begin
STOP: RET
end Begin
