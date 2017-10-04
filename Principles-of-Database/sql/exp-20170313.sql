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

select student.*,cno,grade/*左连接*/
from student left join sc ON (student.sno=sc.sno)
select student.*,cno,grade
from student,sc
where student.sno=sc.sno

select sname,sage
from student
where sage<any
(select sage
from student
where sdept='IS')
and sdept<>'IS'
select sname,sage
from student
where sage<
(select max(sage)
from student
where sdept='IS')and sdept<>'IS'

select sname
from student
where not exists
(select *
from course
where not exists
(select *
from sc
where student.sno=sc.sno and course.cno=sc.cno) )

select sc1.sno,sc1.cno
from sc sc1
where not exists
(select sc2.*
from sc sc2
where sc2.sno='12003' and not exists
(select sc3.*
from sc sc3
where sc1.sno=sc3.sno
and sc2.sno=sc3.sno))

select *  /*集合*/
from student
where sdept='IS'
union
select *
from student
where sdept='CS'
select *
from student
where sdept='IS' or sdept='CS'

select *
from student
where sage=19
intersect
select *
from student
where sdept='IS'
select *
from student
where sage=19 and sdept='IS'

select sno
from student
except
select sno
from sc
where cno='2'
select sno
from student
where sno not in(
select sno
from sc
where cno='2')

/*******************************************************/

create view is_view
as
select *
from student
where sdept='IS'
go
select *
from is_view
go

create view isc_view
as
select sno,sname,sage
from student
where sdept='IS'
with check option
go
select *
from isc_view
go

create view c2_view(sno,sname,cno,grade)
as
select sc.sno,sname,cno,grade
from student join sc on (student.sname=sc.sno)
where cno='2'
go
select *
from c2_view
go

create view c1_view(sno,sname,cno,grade)
as
select sc.sno,sname,cno,grade
from student join sc on(student.sno=sc.sno)
where cno='2' and grade>85
go
select *
from c1_view
go

create view c29_view
as
select *
from c2_view
where grade>85
go
select *
from c29_view
go

create view sab_view(sno,sname,sbiryear)
as
select sno,sname,2013-sage
from student
go
select *
from sab_view
go

drop view sab_view
go
select *
from sab_view
go

create view sab_view
as
select sno,sname,2013-sage sbiryear
from student
go
select *
from sab_view
go

create view sca_view(sno,ccount,cavg)
as
select sno,COUNT(*),AVG(grade)
from sc
group by sno
go
select *
from sca_view
go

insert into is_view
values('12006','张三丰','男',20,'IS')
go
select *
from is_view
go

update isc_view
set sname='张琳'
where sno='12002'
go
select *
from isc_view
go

delete from is_view
where sno='12006'
go
select *
from is_view
go

select *
from is_view
where sage<20
go

select *
from student
where sdept='IS' and sage<20
go

select*
from sab_view
where sbiryear<1994
go

select sno,sname,2013-sage sbiryear
from student
where 2013-sage<1994
go

select sno ,ccount, cavg
from sca_view
where ccount>3
go

select sno, count(*) ccount,avg(grade) cavg
from sc
group by sno having count(*)>3
go

select sno,cavg
from sca_view
where ccount>(select ccount
from sca_view
where sno='12003')
go

select sno,AVG(grade) cavg
from sc
group by sno having COUNT(*) >
(select COUNT(*) ccount
from sc
where sno='12003')
go

select *
from sca_view
go

create view view1(ccount,cavg)
as
select COUNT(*),AVG(grade)
from sc
group by cno
go
select *
from view1
go