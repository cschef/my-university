create database SPJ
go

use SPJ
go

create table S
(
SNO char(8) primary key,
SNAME char(10),
CITY char(10)
)
go

create table P
(
PNO char(8) primary key,
PNAME char(10),
COLOR char(8),
WEIGHT smallint
)
go

create table J
(
JNO char(8) primary key,
JNAME char(10),
CITY char(8)
)
go

create table SPJ
(
SNO char(8) not null,
PNO char(8) not null,
JNO char(8) not null,
QTY int,
primary key (SNO,PNO,JNO),
foreign key (SNO) references S(SNO), 
foreign key (PNO) references P(PNO), 
foreign key (JNO) references J(JNO), 
)
go

/********************************************/

insert into S
values('s1','精艺','天津')
insert into S
values('s2','昇锡','北京')
insert into S
values('s3','东方红','上海')
insert into S
values('s4','泰丰','天津')
insert into S
values('s5','中华','北京')
go

insert into P
values('p1','螺母','红',12)
insert into P
values('p2','螺栓','绿',16)
insert into P
values('p3','螺丝刀','蓝',15)
insert into P
values('p4','钳子','红',30)
insert into P
values('p5','凸轮','蓝',40)
go

insert into J
values('j1','三建','北京')
insert into J
values('j2','一汽','天津')
insert into J
values('j3','冰箱厂','广州')
insert into J
values('j4','造船厂','天津')
insert into J
values('j5','电子厂','深圳')
insert into J
values('j6','弹簧厂','温州')
insert into J
values('j7','手表厂','南京')
go

insert into SPJ
values('s1','p1','j1','200')
insert into SPJ
values('s1','p1','j3','100')
insert into SPJ
values('s1','p1','j4','700')
insert into SPJ
values('s1','p2','j2','100')
insert into SPJ
values('s2','p3','j1','200')
insert into SPJ
values('s2','p3','j2','250')
insert into SPJ
values('s2','p3','j4','200')
insert into SPJ
values('s2','p3','j5','300')
insert into SPJ
values('s2','p5','j1','600')
insert into SPJ
values('s2','p5','j2','500')
insert into SPJ
values('s3','p1','j1','200')
insert into SPJ
values('s3','p3','j1','100')
insert into SPJ
values('s4','p5','j1','350')
insert into SPJ
values('s4','p4','j3','200')
insert into SPJ
values('s4','p4','j4','450')
insert into SPJ
values('s5','p2','j4','150')
insert into SPJ
values('s5','p3','j1','200')
insert into SPJ
values('s5','p4','j2','300')
insert into SPJ
values('s5','p4','j4','500')
go

/*****************************************************/

select distinct SNO
from SPJ
where JNO='j1'
go

select SNO
from SPJ
where JNO='j1' and PNO='p1'
go

select SNO
from P,SPJ
where P.PNO=SPJ.PNO and COLOR='红' and JNO='j1'
go

select JNO
from J
where JNO not in
(
select  JNO
from S,P,SPJ
where S.SNO=SPJ.SNO and P.PNO=SPJ.PNO and CITY='天津' and COLOR='红'
)
go

select distinct x1.JNO
from SPJ x1
where not exists
(
select x2.*
from SPJ x2
where x2.SNO='s1'and not exists 
(
select x3.*
from SPJ x3
where x1.JNO=x3.JNO and x2.PNO=x3.PNO
)
)
go