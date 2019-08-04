CREATE DATABASE test
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
CREATE TABLE SPJ(Sno CHAR(4) NOT NULL,
		 Pno CHAR(4) NOT NULL,
		 Jno CHAR(4) NOT NULL,
		 Qty SMALLINT,
		 PRIMARY KEY(Sno,Pno,Jno)
		 #FOREIGN KEY (`Sno`) REFERENCES `S` (`Sno`)
);
ALTER TABLE SPJ ADD FOREIGN KEY (Sno) REFERENCES S(Sno);#添加外键

INSERT INTO test.`s` VALUES("S1","精益",20,"天津");
INSERT INTO test.`s` VALUES("S2","盛锡",10,"北京");
INSERT INTO test.`s` VALUES("S3","东方红",30,"北京");
INSERT INTO test.`s` VALUES("S4","丰泰盛",20,"天津");
INSERT INTO test.`s` VALUES("S5","为民",30,"上海");

INSERT INTO test.`p` VALUES("P1","螺母","红",12);
INSERT INTO test.`p` VALUES("P2","螺栓","绿",17);
INSERT INTO test.`p` VALUES("P3","螺丝刀","蓝",14);
INSERT INTO test.`p` VALUES("P4","螺丝刀","红",14);
INSERT INTO test.`p` VALUES("P5","凸轮","蓝",40);
INSERT INTO test.`p` VALUES("P6","齿轮","红",30);

INSERT INTO test.`j` VALUES("J1","三建","北京");
INSERT INTO test.`j` VALUES("J2","一汽","长春");
INSERT INTO test.`j` VALUES("J3","弹簧厂","天津");
INSERT INTO test.`j` VALUES("J4","造船厂","天津");
INSERT INTO test.`j` VALUES("J5","机车厂","唐山");
INSERT INTO test.`j` VALUES("J6","无线电厂","常州");
INSERT INTO test.`j` VALUES("J7","半导体厂","南京");

INSERT INTO test.`spj` VALUES("S1","P1","J1",200);
INSERT INTO test.`spj` VALUES("S1","P1","J3",100);
INSERT INTO test.`spj` VALUES("S1","P1" ,"J4",700);
INSERT INTO test.`spj` VALUES("S1","P2","J2",100);
INSERT INTO test.`spj` VALUES("S2","P3","J1",400);
INSERT INTO test.`spj` VALUES("S2","P3","J2",200);
INSERT INTO test.`spj` VALUES("S2","P3","J4",500);
INSERT INTO test.`spj` VALUES("S2","P3","J5",400);
INSERT INTO test.`spj` VALUES("S2","P5","J1",400);
INSERT INTO test.`spj` VALUES("S2","P5","J2",100);
INSERT INTO test.`spj` VALUES("S3","P1","J1",200);
INSERT INTO test.`spj` VALUES("S3","P3","J1",200);
INSERT INTO test.`spj` VALUES("S4","P5","J1",100);
INSERT INTO test.`spj` VALUES("S4","P6","J3",300);
INSERT INTO test.`spj` VALUES("S4","P6","J4",200);
INSERT INTO test.`spj` VALUES("S5","P2","J4",100);
INSERT INTO test.`spj` VALUES("S5","P3","J1",200);
INSERT INTO test.`spj` VALUES("S5","P6","J2",200);
INSERT INTO test.`spj` VALUES("S5","P6","J4",500);

SELECT * FROM s;
SELECT * FROM p;
SELECT * FROM j;
SELECT * FROM spj;

Alter table p add constraint color check (color = '红' or color = '绿' or color = '蓝');


insert into p values("P8"'三通','绿',30);

update p set p.color = '蓝' where p.pno = 'P8';

select sno from spj,p where p.`Pno` = spj.`Pno` and p.`Color` = '蓝' and spj.`Jno`= 'J2' group by spj.`Jno`;

select j.`Jname` from j,spj where j.`Jno` = spj.`Jno` and spj.`Sno` = 'S2' group by j.`Jname`;

SELECT p.`Pno` FROM p,spj,s WHERE spj.`Pno` = p.`Pno` and spj.`Sno` = s.`Sno` AND s.`City` = "上海" group by p.`Pno`;

create view SPJview as select s.sname,s.city as Scity,p.Pname,p.color,j.Jname,j.city as Jcity,spj.Qty from s,p,j,spj where spj.pno = p.pno and spj.jno = j.Jno and spj.sno = s.sno;

select spj.`Jno`,count(spj.`Pno`) from spj group by spj.`Jno`;

select sname,Scity,Jname,Jcity,Qty from SPJview where Pname = '螺母';