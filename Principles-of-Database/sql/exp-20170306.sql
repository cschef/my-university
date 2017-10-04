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
where sage<20 and sdept='IS'
go

select sname,sdept
from student
where sdept='IS' OR sdept='CS'
go

select *
from sc
order by cno,grade asc
go

select *
from sc
order by cno,grade desc
go

select *
from student
where ssex='女'
order by sage desc
go

select COUNT(*)
from student
go

select MAX(grade)
from sc
where cno='1'
go

select sno,COUNT(*) 选课门数,MAX(grade) 最高分,MIN(grade) 最低分,AVG(grade) 平均分
from sc
group by sno
go

select cno,COUNT(*) 选修人数
from sc
group by cno
go

select cno,COUNT(*) 选修人数
from sc
group by cno having COUNT(*)>=4
go

select student.*,sc.*
from student,sc
where student.sno=sc.sno
go

select student.sno,sname,ssex,sage,sdept,cno,grade
from student,sc
where student.sno=sc.sno
go

select x.cname,y.cname as pname
from course as x,course as y
where x.cpno=y.cno
go

select student.*,sc.cno,sc.grade
from student left join sc on (student.sno=sc.sno)
go

select student.sname,grade
from student,sc
where sc.sno=student.sno
	and cno='2' and grade>85
go

select sname,cname,grade
from student,sc,course
where sc.sno=student.sno 
	and sc.cno=course.cno
go

select *
from student
where sdept in
(select sdept
 from student
 where sname='王琳'
)
go

select x.*
from student x,student y
where x.sdept=y.sdept
	and y.sname='王琳'
go

select sname,sage
from student
where sno in
(select sno
 from sc
 where cno in
 (select cno
  from course
  where cname='数据结构'
 )
)
go

select sname,sage
from student,sc,course
where student.sno=sc.sno
	and sc.cno=course.cno
	and cname='数据结构'
go

select sname
from student
where EXISTS
(select *
 from sc
 where student.sno=sc.sno
 and cno='1'
)
go

select sname
from student
where sno in
(select sno
 from sc
 where cno='1'
)
go

create table stud
(sno char(5),
 ccount smallint,
 cavg numeric(6,2)
)
insert into stud(sno,ccount,cavg)
select sno,COUNT(*),AVG(grade)
from sc
group by sno
go

update sc
set grade=0
where 'IS'=
(select sdept
 from student
 where sc.sno=student.sno
)
go

update sc
set grade=98
where '李伟'=
(select sname
 from student
 where sc.sno=student.sno
)
go

delete
from sc
where 'IS'=
(select sdept
 from student
 where sc.sno=student.sno
)
go

delete
from sc
where sno in
(select sno
 from student
 where sdept='IS'
)
go

select sname,sage
from student
where sage<any
	(select sage
	 from student
	 where sdept='IS')
	and sdept<>'IS'
go

select sname,sage
from student
where sage<
	(select max(sage)
	 from student
	 where sdept='IS')
	and sdept<>'IS'
go

select sname,sage
from student
where sage<all
	(select sage
	 from student
	 where sdept='IS')
	and sdept<>'IS'
go

select sname,sage
from student
where sage<
	(select min(sage)
	 from student
	 where sdept='IS')
	and sdept<>'IS'
go

select sname
from student
where exists
	(select *
	 from sc
	 where student.sno=sc.sno and cno='1')
go

select s1.*
from student s1
where exists
	(select s2.*
	 from student s2
	 where s1.sdept=s2.sdept and sname='王琳')
go

select sname
from student
where not exists
	(select *
	 from course
	 where not exists
		(select *
		 from sc
		 where student.sno=sc.sno and course.cno=sc.cno
		 )
	 )
go

select sc1.sno
from sc sc1
where not exists
	(select sc2.*
	 from sc sc2
	 where sc2.sno='12003' and not exists
		(select sc3.*
		 from sc sc3
		 where sc1.sno=sc3.sno and sc2.cno=sc3.cno
		 )
	 )
go