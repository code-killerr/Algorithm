.model small
.stack
.data
.code
Begin: MOV BX,0  ;���ڴ����λ��16������
       MOV CH,4  ;ch��ʼΪ4��ʾ������λ����+-
       MOV CL,4  
INPUT: SHL BX,CL ;��ǰ�������������4λ
       MOV AH,1  ;�Ӽ���ȡ��
       INT 21H;��ȡ1��4�ֽ�������AL
       CMP AL,30H ;<0��
       JB INPUT   ;����"0~F"������������
       CMP AL,39H ; ��"0~9"��JB��ʾС����ת
       JA AF      ;���ǣ�ת"A~F"�Ĵ��� JA��ʾ������ת
       AND AL,0FH ;ת��Ϊ��0000B~1001B 0��9ASCII��Ϊ30-39����ȥ������λתΪ0-9
       JMP BINARY
AF:    AND AL,11011111B ;ת��Ϊ��д��ĸ
       CMP AL,41H  ;�ж�<A��
       JB INPUT    ;����"A~F"������������ JBС����ת
       CMP AL,46H  ;>F��
       JA INPUT    ;����"A~F"������������  jA������ת
       AND AL,0FH  ;ת��Ϊ1010B~1111B  0FH = 00001111 A-F 41-46,ȥ������λ1-6
       ADD AL,9		;+9��Ϊ�����ֵ
BINARY: OR BL,AL   ;�������������������ϣ���������
        DEC CH	   ;ch -1��ת��input
        JNZ INPUT
        MOV CX,16  ;��16λ��������һλλ��ת����ASCII����ʾ
DISP:   MOV DL,0
        ROL BX,1   ;ѭ����λһ��
        RCL DL,1   ;��CF����λһ����������
        OR DL,30H
        MOV AH,2   ;		������ʾ
        INT 21H
        LOOP DISP
  STOP: ret
  end begin





