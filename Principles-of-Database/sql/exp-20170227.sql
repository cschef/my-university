create database [15111204011丁鹏]
go

create table student
(
sno char(5) primary key,
sname char(8) unique,
ssex char(2),
sage smallint,
sdept char(8)
)
go

create table course
(
cno char(1) primary key,
cname char(20),
cpno char(1),
ccredit smallint,
foreign key (cpno) references course(cno)
)
go

create table sc
(
sno char(5) not null,
cno char(1) not null,
grade smallint,
primary key (sno, cno),
foreign key (sno) references student(sno),
foreign key (cno) references course(cno)
)
go

/*******************************************************/

use [15111204011丁鹏]
go

insert student
values('12001','李伟','男',20,'CS')
insert student
values('12002','王琳','女',20,'IS')
insert student
values('12003','郭文静','女',18,'MA')
insert student
values('12004','周静','男',19,'IS')
insert student
values('12005','李菊','女',17,'CS')
go

insert course
values('2','数学',null,3)
insert course
values('5','C语言',null,4)
insert course
values('6','概率统计',null,3)
insert course
values('3','数据结构','5',4)
insert course
values('4','数据处理','2',2)
insert course
values('1','DB_Design','3',3)
go

insert sc
values('12001','1',86)
insert sc
values('12001','2',90)
insert sc
values('12001','3',80)
insert sc
values('12001','4',75)
insert sc
values('12001','5',95)
insert sc
values('12002','2',90)
insert sc
values('12002','3',88)
insert sc
values('12002','4',80)
insert sc
values('12002','5',86)
insert sc
values('12003','2',56)
insert sc
values('12003','3',50)
insert sc
values('12003','5',90)
insert sc
values('12004','2',89)
insert sc
values('12004','4',55)
insert sc
values('12004','5',95)
go

/*******************************************************/

select *
from student
go

select sno, sdept
from student
go

select all sdept
from student
go

select distinct sdept
from student
go

select sname as 姓名, '出生年是：' as 出生年份, 2016-sage as 出生年
from student
go

select sno, sname, sdept
from student
where sdept='IS'
go

select distinct sno
from sc
where grade<60
go

select sname, sage, ssex
from student
where sage between 20 and 24
go

select sname, sage, ssex
from student
where sage not between 20 and 24
go

select sname, sdept
from student
where sdept in ('IS', 'CS')
go

select sname, sdept
from student
where sdept not in ('IS', 'CS')
go

select *
from student
where sno like '12002'
go

select *
from course
where cname like '数%'
go

select *
from course
where cname like 'DB\_Design' escape '\'
go

select *
from course
where cname like 'DB_Design'
go

select *
from course
where cname like 'DB\_%\%' escape '\'
go

select cno, cname, cpno
from course
where cpno is null
go