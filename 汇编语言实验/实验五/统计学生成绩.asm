;PROGRAM TITLE GOES HERE�D�Dresult
;************************************
;�Ľ��������������
;change-author:CodeKiller
datas    segment                     ;define data segment �������ݶ�
  grade   dw          56,69,84,82,73,88,99,63,100,80
  s5      dw          0
  s6      dw          0
  s7      dw          0
  s8      dw          0
  s9      dw          0
  s10     dw          0
  word1   db           'grade below 60:$'
  word2	  db		   'grade below 70:$'
  word3   db		   'grade below 80:$'
  word4   db		   'grade below 90:$'
  word5   db		   'grade below 100:$'
  word6   db           'grade is 100:$'
  wordall dw word1,word2,word3,word4,word5,word6
datas  ends
;************************************
codes segment                       ;defi*...............................ne code segment
;----------------------------
;main      proc      far               ; main part of program
assume  cs:codes, ds:datas
start:                          ; starting execution address
; set up stack for return
         push     ds                  ; save old data segment ��ֹds��ӵ�����ݱ�����,��ds����ѹջ
         sub      ax,ax               ; put zero in AX AX��0
         push     ax                  ; save it on stack AX ѹջ
; set DS register to current data segment
         mov      ax,datas          ; datas segment addr �����ݴ洢��AX
         mov      ds,ax               ; into DS register ������ת�Ƶ�ds�μĴ���
; MAIN PART OF PROGRAM GOES HERE
         mov      s5, 48               ; initialize counter ��ʼ����������
         mov      s6, 48
         mov      s7, 48
         mov      s8, 48
         mov      s9, 48
         mov      s10, 48
         mov      cx, 10              ; initialize loop count value ����ѭ������Ϊ10,10������
         mov      bx, offset grade      ; initialize first addr ��grade�ĵ�ַƫ���͵�bx�Ա���ڶ�ȡ����
compare:
         mov      ax, [bx]             ; get a result ����һ�����ݴ���ax
         cmp      ax, 60               ; <60? �ж��Ƿ�С��60
         jl        five					;���С��ת��five���м���
         cmp     ax, 70                ; <70? �ж��Ƿ�С��70 ����70
         jl       six					;С��ת��six
         cmp     ax, 80                ; <80? �ж��Ƿ�С��80 ����80
         jl       seven					;С��ת��seven
         cmp     ax, 90                ; <90? �ж��Ƿ�С��90С��ת��eight
         jl       eight
         cmp     ax, 100               ; =100? ��100�Ա��Ƿ�Ϊ100
         jne      nine					;������100ת�Ƶ�nine
         inc      s10					;����100 S10�Լ�
         jmp     short change_addr ;short������-128 - 127�ֽ�����ת
  nine:  inc       s9
         jmp     short change_addr 
  eight:  inc      s8
         jmp     short change_addr
  seven:  inc      s7
         jmp     short change_addr
  six:    inc       s6
         jmp     short change_addr
  five:   inc       s5 ;s5�Լ�1
change_addr:
         add     bx, 2   ;��ת���ڶ�������
         loop    compare ;cx��1����תcompare�����Ա�
         mov cx,6
         mov si,offset wordall
         mov di,offset s5
print: 						;���û�н������ᵼ�´�ӡ�����ͣ������
		 mov ah,9
		 mov dx,[si]
		 int 21h;���˵�����
		 
		 mov ah,2
		 mov dx,[di]
		 int 21h;�������
		 
		 add dx,1
		 sub dx,dx
		 mov ah,2
		 mov dx,0ah
		 int 21h;����
		 
		 add si,2;������һ�����
		 add di,2
		
		 dec cx
		 cmp cx,0
		 jne print;����ѭ��
		 
		 
         mov AX,4C00H                          ; return to DOS �������
;main     endp                         ; end of main part of program
; ------------------------------
codes  ends
;***************************
 end     start                 ; end assembly




