CREATE DATABASE STC;#建立数据库
CREATE DATABASE SPJ;
USE STC;#选定数据库
CREATE TABLE Student(#创建表
	Sno CHAR(9) NOT NULL,
	Sname CHAR(20) NOT NULL,
	Ssex CHAR(2) CHECK(Ssex="M"||Ssex="F"),
	Sage SMALLINT,
	Sdept CHAR(20) NOT NULL,
	PRIMARY KEY(Sno)
);
CREATE TABLE Course(Cno CHAR(4) NOT NULL,
		    Cname CHAR(40) NOT NULL,
		    Cpno CHAR(4),
		    Ccredit SMALLINT,
		    PRIMARY KEY(Cno)
);
CREATE TABLE SC(Sno CHAR(9) NOT NULL,
		Cno CHAR(4) NOT NULL,
		Grade SMALLINT CHECK(Grade>=0||Grade<=100),
		PRIMARY KEY(Sno,Cno),
		FOREIGN KEY(Sno) REFERENCES Student(Sno)
		FOREIGN KEY(Cno) REFERENCES Course(Sno)
		);

USE SPJ;
CREATE TABLE S(Sno CHAR(4) NOT NULL,
	       Sname CHAR(20) NOT NULL,
	       STATUS SMALLINT,
	       City CHAR(20),
	       PRIMARY KEY(Sno)
);
CREATE TABLE P(Pno CHAR(4) NOT NULL,
	       Pname CHAR(20) NOT NULL,
	       Color CHAR(4),
	       Weight SMALLINT,
	       PRIMARY KEY(Pno)
);
CREATE TABLE J(Jno CHAR(4) NOT NULL,
	       Jname CHAR(20) NOT NULL,
	       City CHAR(20),
	       PRIMARY KEY(Jno)
);
CREATE TABLE SPG(Sno CHAR(4) NOT NULL,
		 Pno CHAR(4) NOT NULL,
		 Jno CHAR(4) NOT NULL,
		 Qty SMALLINT,
		 PRIMARY KEY(Sno,Pno,Jno)
		 #FOREIGN KEY (`Sno`) REFERENCES `S` (`Sno`)
);
INSERT INTO stc.`student`(Sno,Sname,Ssex,Sage,Sdept,入学时间) 
VALUES("201215121","李勇","M",20,"CS",NULL);
INSERT INTO stc.`student` VALUES("201215122","刘晨","F",19,"CS",NULL);
INSERT INTO stc.`student` VALUES("201215123","王敏","F",18,"CS",NULL);
INSERT INTO stc.`student` VALUES("201215127","张立","M",19,"IS",NULL);
UPDATE stc.`student` SET Sdept = "MA" WHERE Sno = 201215123;

INSERT INTO stc.`course` VALUES("1","数据库","5",4);
INSERT INTO stc.`course` VALUES("2","数学",NULL,2);
INSERT INTO stc.`course` VALUES("3","信息系统","1",4);
INSERT INTO stc.`course` VALUES("4","操作系统","6",3);
INSERT INTO stc.`course` VALUES("5","数据结构","7",4);
INSERT INTO stc.`course` VALUES("6","数据处理",NULL,2);
INSERT INTO stc.`course` VALUES("7","PASCAL语言","6",4);

INSERT INTO stc.`sc` VALUES("201215121","1",92);
INSERT INTO stc.`sc` VALUES("201215121","2",85);
INSERT INTO stc.`sc` VALUES("201215121","3",88);
INSERT INTO stc.`sc` VALUES("201215122","2",90);
INSERT INTO stc.`sc` VALUES("201215122","3",80);
INSERT INTO stc.`sc` VALUES("201215122","5",111);

INSERT INTO spj.`s` VALUES("S1","精益",20,"天津");
INSERT INTO spj.`s` VALUES("S2","盛锡",10,"北京");
INSERT INTO spj.`s` VALUES("S3","东方红",30,"北京");
INSERT INTO spj.`s` VALUES("S4","丰泰盛",20,"天津");
INSERT INTO spj.`s` VALUES("S5","为民",30,"上海");

INSERT INTO spj.`p` VALUES("P1","螺母","红",12);
INSERT INTO spj.`p` VALUES("P2","螺栓","绿",17);
INSERT INTO spj.`p` VALUES("P3","螺丝刀","蓝",14);
INSERT INTO spj.`p` VALUES("P4","螺丝刀","红",14);
INSERT INTO spj.`p` VALUES("P5","凸轮","蓝",40);
INSERT INTO spj.`p` VALUES("P6","齿轮","红",30);

INSERT INTO spj.`j` VALUES("J1","三建","北京");
INSERT INTO spj.`j` VALUES("J2","一汽","长春");
INSERT INTO spj.`j` VALUES("J3","弹簧厂","天津");
INSERT INTO spj.`j` VALUES("J4","造船厂","天津");
INSERT INTO spj.`j` VALUES("J5","机车厂","唐山");
INSERT INTO spj.`j` VALUES("J6","无线电厂","常州");
INSERT INTO spj.`j` VALUES("J7","半导体厂","南京");

INSERT INTO spj.`spg` VALUES("S1","P1","J1",200);
INSERT INTO spj.`spg` VALUES("S1","P1","J3",100);
INSERT INTO spj.`spg` VALUES("S1","P1" ,"J4",700);
INSERT INTO spj.`spg` VALUES("S1","P2","J2",100);
INSERT INTO spj.`spg` VALUES("S2","P3","J1",400);
INSERT INTO spj.`spg` VALUES("S2","P3","J2",200);
INSERT INTO spj.`spg` VALUES("S2","P3","J4",500);
INSERT INTO spj.`spg` VALUES("S2","P3","J5",400);
INSERT INTO spj.`spg` VALUES("S2","P5","J1",400);
INSERT INTO spj.`spg` VALUES("S2","P5","J2",100);
INSERT INTO spj.`spg` VALUES("S3","P1","J1",200);
INSERT INTO spj.`spg` VALUES("S3","P3","J1",200);
INSERT INTO spj.`spg` VALUES("S4","P5","J1",100);
INSERT INTO spj.`spg` VALUES("S4","P6","J3",300);
INSERT INTO spj.`spg` VALUES("S4","P6","J4",200);
INSERT INTO spj.`spg` VALUES("S5","P2","J4",100);
INSERT INTO spj.`spg` VALUES("S5","P3","J1",200);
INSERT INTO spj.`spg` VALUES("S5","P6","J2",200);
INSERT INTO spj.`spg` VALUES("S5","P6","J4",500);

SELECT * FROM student;
SELECT * FROM course;
SELECT * FROM sc;
SELECT * FROM s;
SELECT * FROM p;
SELECT * FROM j;
SELECT * FROM spg;
ALTER TABLE SPG ADD FOREIGN KEY (Sno) REFERENCES S(Sno);#添加外键
USE STC;
SHOW TABLES;#展示库中的表
DESC student;#显示表中项目
SELECT * FROM student;#展示所有数据
#drop table SC cascade;#删除表
ALTER TABLE stc.student ADD nation CHAR(20);#在student中增加增加nation属性为char(20)
ALTER TABLE stc.`student` DROP COLUMN nation;#在student表中删除nation属性
ALTER TABLE stc.`student` ADD 入学时间 DATE;
INSERT INTO stc.`student`(Sno,Sname,Ssex,Sage,Sdept,入学时间) VALUES("2001110","aaa",NULL,NULL," ",NULL);
INSERT INTO stc.`course`(Cno,Cname,Cpno,Ccredit) VALUES("3","aaa",NULL,NULL);
INSERT INTO stc.SC(Sno,Cno,Grade)VALUES("2001110","3",80);#在主键所在的表中拥有该数据才能插入
SELECT * FROM stc.`sc`;
UPDATE stc.`sc` SET Grade = 70 WHERE Sno = 2001110;#更改表中数据
DELETE FROM stc.sc WHERE Sno = 2001110;

CREATE INDEX IXsage ON student(Sno ASC,Sage DESC);#建立索引以学号升序排列，如果相同则以年龄降序排列

DROP INDEX IXsage ON student;#删除


ALTER TABLE student ADD UNIQUE(Sname);#添加Sname唯一索引

ALTER TABLE spj.`s` ADD UNIQUE(Sname);
UPDATE p SET color = '蓝' WHERE color = '红';#红的改成蓝的
UPDATE spg SET Sno = 'S3' WHERE Sno = 's5' AND pno = 'P6' AND Jno = 'J4';
DELETE FROM spg WHERE sno = 's2';#删除S2
DELETE FROM s WHERE Sno = 's2';
INSERT INTO spj.`spg` VALUES("S2","P4","J6",200);#没有S2无法添加


SELECT Sname,City FROM spj.`s`;#查询名称和位置
SELECT Pname,Color,Weight FROM spj.`p`;#查询名称，颜色，重量
SELECT Jno FROM spj.`spg` WHERE Sno = "S1";#找出使用供应商S1所供应零件的工程号码；
SELECT Pname,Qty FROM spj.`p`,spj.`spg` WHERE Jno = "J2" AND P.`Pno` = spg.`Pno` ORDER BY qty DESC;#找出工程项目J2使用的各种零件的名称及数量，并按数量降序排列；
SELECT s.`Sname`,spg.`Sno` FROM spj.`s`,spj.`spg` WHERE Jno = "J1" AND s.`Sno` = spg.`Sno`;#找出工程J1零件的供应商号码SNO；
SELECT Jno,SUM(Qty) FROM spj.`spg` GROUP BY Jno;#找出每个工程及使用零件数量的总和；

SELECT Sno,Sname FROM stc.`student` WHERE sdept = "CS";# 查询计算机系的学生学号和姓名。

SELECT student.Sno,Sname FROM stc.`student`,stc.`sc` WHERE sc.Sno = student.Sno GROUP BY Sname;# 查询选修了课程的学生学号和姓名。

SELECT Sno,Grade FROM stc.`sc` WHERE Cno = "1" ORDER BY grade DESC;# 查询选修1号课程的学生学号和成绩，并要求对查询结果按成绩降序排列，如果成绩相同则按学号升序排列。

SELECT Sno,Grade*0.75 FROM stc.`sc` WHERE Cno = "1" AND Grade > 80 AND Grade < 90;# 查询选修1号课程且成绩在80~90之间的学生学号和成绩，并将成绩乘以系数0.75输出。
SELECT * FROM stc.student WHERE sdept = "cs" OR "ma" AND Sname LIKE "张%";# 查询计算机系和数学系姓张的学生的信息。
SELECT Sno,Cno FROM stc.`sc` WHERE Grade = NULL;# 查询缺少了成绩的学生的学号和课程号。
SELECT student.Sno,student.Sname,sc.Cno,Grade FROM stc.`student`,stc.`sc`,stc.`course` WHERE sc.Sno = student.Sno AND course.Cno = sc.Cno;# 查询学生的学号、姓名、选修的课程名及成绩。
SELECT Cno,Grade,Sname FROM stc.`sc`,stc.`student` WHERE Grade > 90;# 查询选修1号课程且成绩在90分以上的学生学号、姓名及成绩。
# 查询每一门课程及先修课信息，包括课程号、课程名、先修课号和先修课程名。
SELECT student.*,sc.Cno,grade FROM stc.`student` LEFT OUTER JOIN stc.sc ON student.Sno = sc.Sno; # 查询每个学生的基本信息以及他所选修课程的课程号（包括没有选课的学生）。

SELECT spg.Pno FROM spj.`spg`,spj.`p`,spj.`s` WHERE City = "上海" AND spg.Sno = S.`Sno` AND spg.`Pno` = p.`Pno`;#找出上海厂商供应的所有零件号码；
SELECT j.`Jname` FROM spj.`spg`,spj.`j`,spj.`s` WHERE J.`Jno` = spg.`Jno` AND spg.`Sno` = s.`Sno` AND s.`City` = "上海" ;#找出使用上海产的零件的工程名称；
SELECT Jno FROM spg WHERE Jno NOT IN (SELECT Jno FROM spj.`spg`,spj.`s` WHERE spg.`Sno` = s.`Sno` AND city = "天津");#找出没有使用天津产的零件的工程号码；
UPDATE spj.`p` SET color = "红" WHERE Pno = "p1" OR Pno = "P4" OR Pno = "P6";
SELECT spg.Sno FROM spj.`spg`,spj.`p`,spj.`j` WHERE P.Color = "红" AND spg.`Jno` = "J1" AND spg.`Jno` = j.`Jno` AND spg.`Pno` = p.`Pno`;#找出供应工程J1零件为红色的供应商号码SNO；
SELECT Jno FROM spj.J WHERE Jno NOT IN (SELECT spg.Jno FROM spj.`s`,spj.`p`,spj.`spg` WHERE s.`city` = "天津" AND p.`Color` = "红" AND spg.`sno` = s.`sno` AND spg.`Pno` = p.`Pno`);#找出没有使用天津供应商生产的红色零件的工程号JNO；
#找出至少使用了供应商S1所供应的全部零件的工程号码JNO；
SELECT COUNT(*) FROM stc.student;#查询学生的总人数。
SELECT COUNT(DISTINCT Sno) FROM stc.`sc`;#查询选修了课程的学生人数。
SELECT Cno,COUNT(Sno) FROM stc.`sc` GROUP BY Cno;#查询课程的课程号和选修该课程的人数
SELECT sc.Sno,Sname FROM stc.`student`,stc.`sc` WHERE student.Sno = sc.`Sno` GROUP BY Sno HAVING COUNT(*)>2;#查询选修课超过2门课的学生学号、姓名。
SELECT sc.`Sno`,Sname FROM stc.`student`,stc.`sc`,stc.`course` WHERE course.`Cname` = "数据库" AND student.Sno = sc.`Sno` AND sc.`Cno` = course.`Cno`;#查询选修了数据库的学生学号和姓名。

#创建视图CS：选课成绩小于90分的学生的学号、所选课程号和课程成绩。
CREATE VIEW CS_student
AS SELECT Sno,Cno,Grade FROM stc.`sc` WHERE Grade < 90;

#创建视图：视图由学生姓名、系别及他所选课程名组成。
CREATE VIEW Sdata 
AS SELECT Sname,Sdept,GROUP_CONCAT(Cname) 
FROM stc.`student`,stc.`course`,stc.`sc` 
WHERE sc.`Cno` = course.`Cno` AND sc.`Sno` = student.`Sno` 
GROUP BY Sname;
#3. 创建视图：视图由学生姓名及所选课程名和所有课程成绩都比原来多5分组成。
CREATE VIEW Cgrade 
AS SELECT Sname,Cname,Grade+5 FROM stc.`course`,stc.`sc`,stc.`student`
WHERE sc.`Cno` = course.`Cno` AND sc.`Sno` = student.`Sno`;
#创建分组视图：将学生的学号及他的平均成绩定义为一个视图。
CREATE VIEW Savg
AS SELECT Sno,AVG(Grade)
FROM stc.`sc` GROUP BY(Sno);
#创建基于视图的视图：基于1中建立的视图CS，定义一个包括学号、所选课程数目和平均成绩的视图。
CREATE VIEW CS2 
AS SELECT Sno,COUNT(Cno),AVG(Grade) FROM CS_student GROUP BY Sno;

SELECT Sname FROM stc.`student` WHERE sdept = 'IS';#查询所有选修‘信息系统’的学生姓名。

INSERT INTO stc.`student` VALUES('3390552','bbb','M',22,'IS',NULL);
INSERT INTO stc.cs_student VALUES('3390552','6',70);#插入一条元组到1中所建视图CS，若是视图的定义中存在WHIT CHECK OPTION子句对插入操作有何影响。
#插入视图的语句会将数据放在sc表中，视图只是虚表，会将数据存入它所涉及的表中，如果涉及其它表主键会报错
#insert into stc.cgrade values('大白兔','组成原理',87);数据不全缺少主键会报错没有字段列表
UPDATE stc.`cs_student` SET grade = cs_student.`Grade` + 10;#对1中所建视图CS（存在WHIT CHECK OPTION子句）的成绩均增加10分,减去10分，不满足条件的项消失
UPDATE stc.`cs_student` SET grade = cs_student.`Grade` - 10;#只对其中有的项有效
ALTER VIEW CS_student
AS SELECT Sno,Cno,Grade FROM stc.`sc` WHERE Grade < 90 WITH CHECK OPTION;#重建视图
UPDATE stc.`cs_student` SET grade = cs_student.`Grade` + 10;#显示check option不符，查询失败
drop view stc.`Savg`,stc.`cgrade`#取消3，4中所建视图








