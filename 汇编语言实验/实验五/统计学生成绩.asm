;PROGRAM TITLE GOES HERE――result
;************************************
;改进增加了数据输出
;change-author:CodeKiller
datas    segment                     ;define data segment 定义数据段
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
         push     ds                  ; save old data segment 防止ds中拥有数据被覆盖,将ds数据压栈
         sub      ax,ax               ; put zero in AX AX清0
         push     ax                  ; save it on stack AX 压栈
; set DS register to current data segment
         mov      ax,datas          ; datas segment addr 将数据存储于AX
         mov      ds,ax               ; into DS register 将数据转移到ds段寄存器
; MAIN PART OF PROGRAM GOES HERE
         mov      s5, 48               ; initialize counter 初始化各个变量
         mov      s6, 48
         mov      s7, 48
         mov      s8, 48
         mov      s9, 48
         mov      s10, 48
         mov      cx, 10              ; initialize loop count value 设置循环次数为10,10个数据
         mov      bx, offset grade      ; initialize first addr 把grade的地址偏移送到bx以便后期读取数据
compare:
         mov      ax, [bx]             ; get a result 将第一个数据传入ax
         cmp      ax, 60               ; <60? 判断是否小于60
         jl        five					;如果小于转到five进行计数
         cmp     ax, 70                ; <70? 判断是否小于70 包括70
         jl       six					;小于转到six
         cmp     ax, 80                ; <80? 判断是否小于80 包括80
         jl       seven					;小于转到seven
         cmp     ax, 90                ; <90? 判断是否小于90小于转到eight
         jl       eight
         cmp     ax, 100               ; =100? 和100对比是否为100
         jne      nine					;不等于100转移到nine
         inc      s10					;等于100 S10自加
         jmp     short change_addr ;short代表在-128 - 127字节内跳转
  nine:  inc       s9
         jmp     short change_addr 
  eight:  inc      s8
         jmp     short change_addr
  seven:  inc      s7
         jmp     short change_addr
  six:    inc       s6
         jmp     short change_addr
  five:   inc       s5 ;s5自加1
change_addr:
         add     bx, 2   ;跳转到第二个数据
         loop    compare ;cx减1并跳转compare继续对比
         mov cx,6
         mov si,offset wordall
         mov di,offset s5
print: 						;最后没有结束符会导致打印到最后停不下来
		 mov ah,9
		 mov dx,[si]
		 int 21h;输出说明语句
		 
		 mov ah,2
		 mov dx,[di]
		 int 21h;输出数据
		 
		 add dx,1
		 sub dx,dx
		 mov ah,2
		 mov dx,0ah
		 int 21h;换行
		 
		 add si,2;跳到下一个语句
		 add di,2
		
		 dec cx
		 cmp cx,0
		 jne print;控制循环
		 
		 
         mov AX,4C00H                          ; return to DOS 程序结束
;main     endp                         ; end of main part of program
; ------------------------------
codes  ends
;***************************
 end     start                 ; end assembly




