DATA SEGMENT
  VAL1 DW 12
  CRLF DW 0DH,0AH,'$'
DATA ENDS
CODE SEGMENT

   ASSUME CS:CODE,DS:DATA
   START: 
    BANDO PROC FAR  ;������BANDO
   		  PUSH DS  ;���÷���DOS
          SUB AX,AX
          PUSH AX
          MOV AX,DATA
          MOV DS,AX  ;��DS��ֵ
          PUSH VAL1
          CALL PARIS
          RET
 BANDO ENDP
 PARIS PROC NEAR  ;PARIS�ӳ���
          PUSH BP
          MOV BP,SP
          PUSH BX
          MOV BX,[BP+4] ;�Ӷ�ջ��ȡ��VAL1
          CALL OUTBIN  ;���ö�������ʾ�ӳ���
          MOV CX,8    ;��ʾ8���ո�
   SPACE: MOV DL,' '
          MOV AH,2
          INT 21H
          LOOP SPACE
          CALL OUTOCT  ;���ð˽�����ʾ�ӳ���
          CALL DISP_CRLF
          POP BX
          POP BP
          RET 2
 PARIS ENDP
 OUTBIN PROC NEAR  ;��������ʾ�ӳ���
          PUSH BX
          MOV CX,16
   ONEBIT:ROL BX,1
          MOV DX,BX
          AND DX,1
          OR DL,30H ;ת��ΪASCII��
          MOV AH,2
          INT 21H
          LOOP ONEBIT
          POP BX
          RET
 OUTBIN ENDP
 OUTOCT PROC NEAR  ;�˽�����ʾ�ӳ���
          ROL BX,1;16λ������������6λ�˽����������λ��1λ
          MOV DX,BX
          AND DX,1
          OR DL,30H ;ת��ΪASCII��
          MOV AH,2
          INT 21H
          MOV CX,5  ;���»���5λ�˽�����
     NEXT:PUSH CX
          MOV CL,3 ;1λ�˽���������3λ��������
          ROL BX,CL
          MOV DX,BX
          AND DX,07H
          OR DL,30H ;ת��ΪASCII��
          MOV AH,2
          INT 21H
          POP CX
          LOOP NEXT
          RET
 OUTOCT ENDP
 DISP_CRLF PROC NEAR ;��ʾ�س������ӳ���
          LEA DX,CRLF
          MOV AH,09H
          INT 21H
          RET
 DISP_CRLF ENDP
      CODE ENDS
end start

