.model small
.stack
.code
Begin:MOV AH,1   ;�Ӽ�������һ���ַ�
      INT 21H
      CMP AL,'a'   ;�����ַ�<'a'��
      JB STOP
      CMP AL,'z'   ;�����ַ�>'z'��
      JA STOP
      SUB AL,20H  ;ת��Ϊ��д��ĸ��AND AL,1101 1111BҲ����
      MOV DL,AL  ;��ʾһ���ַ�
      MOV AH,2
      INT 21H
      JMP Begin
STOP: RET
end Begin
