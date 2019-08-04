DATA SEGMENT
  VAL1 DW 12
  CRLF DW 0DH,0AH,'$'
DATA ENDS
CODE SEGMENT

   ASSUME CS:CODE,DS:DATA
   START: 
    BANDO PROC FAR  ;主程序BANDO
   		  PUSH DS  ;设置返回DOS
          SUB AX,AX
          PUSH AX
          MOV AX,DATA
          MOV DS,AX  ;给DS赋值
          PUSH VAL1
          CALL PARIS
          RET
 BANDO ENDP
 PARIS PROC NEAR  ;PARIS子程序
          PUSH BP
          MOV BP,SP
          PUSH BX
          MOV BX,[BP+4] ;从堆栈中取出VAL1
          CALL OUTBIN  ;调用二进制显示子程序
          MOV CX,8    ;显示8个空格
   SPACE: MOV DL,' '
          MOV AH,2
          INT 21H
          LOOP SPACE
          CALL OUTOCT  ;调用八进制显示子程序
          CALL DISP_CRLF
          POP BX
          POP BP
          RET 2
 PARIS ENDP
 OUTBIN PROC NEAR  ;二进制显示子程序
          PUSH BX
          MOV CX,16
   ONEBIT:ROL BX,1
          MOV DX,BX
          AND DX,1
          OR DL,30H ;转换为ASCII码
          MOV AH,2
          INT 21H
          LOOP ONEBIT
          POP BX
          RET
 OUTBIN ENDP
 OUTOCT PROC NEAR  ;八进制显示子程序
          ROL BX,1;16位二进制数包含6位八进制数，最高位仅1位
          MOV DX,BX
          AND DX,1
          OR DL,30H ;转换为ASCII码
          MOV AH,2
          INT 21H
          MOV CX,5  ;余下还有5位八进制数
     NEXT:PUSH CX
          MOV CL,3 ;1位八进制数包含3位二进制数
          ROL BX,CL
          MOV DX,BX
          AND DX,07H
          OR DL,30H ;转换为ASCII码
          MOV AH,2
          INT 21H
          POP CX
          LOOP NEXT
          RET
 OUTOCT ENDP
 DISP_CRLF PROC NEAR ;显示回车换行子程序
          LEA DX,CRLF
          MOV AH,09H
          INT 21H
          RET
 DISP_CRLF ENDP
      CODE ENDS
end start

