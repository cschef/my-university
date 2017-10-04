create database [15111204011丁鹏]
go

use [15111204011丁鹏]

create table s
(
	sno char(9) primary key,
	sname char(6) not null,
	ssex char(2),
	sage int,
	sdept varchar(8)
)
create table c
(
	cno char(4)  primary key,
	cname varchar(20) not null,
	cpno char(4),
	ccredit int,
	
)
create table sc
(
	sno char(9),
	cno char(4),
	score int,
	primary key(sno,cno),
	
)
go

--------------------------------------------------

insert into s
values('201506001','赵菁菁','女','23','CS')
insert into s
values('201506002','李大勇','男','20','CS')
insert into s
values('201506003','张丰平','男','19','CS')
insert into s
values('201506004','张大衡','男','18','IS')
insert into s
values('201506005','张向东','男','20','IS')
insert into s
values('201506006','张向丽','女','20','IS')
insert into s
values('201506007','王小芳','女','20','CS')
insert into s
values('201506008','王民生','男','25','MA')
insert into s
values('201506009','王小民','女','18','MA')
insert into s
values('201506010','李一晨','女','22','MA')
insert into s
values('201506011','张开毅','男','20','WM')
insert into s
values('201506012','杨小磊','女','20','EN')
insert into s
values('201506013','李小晨','女','19','MA')
insert into s
values('201506014','张力成','男','22','CS')
insert into s
values('201506015','李小蕾','女','21','EN')
insert into s
values('201506016','刘小社','男','21','CM')
insert into s
values('201506017','刘星耀','男','18','CM')
insert into s
values('201506018','李仁贵','男','19','EN')
insert into s
values('201506019','林自许','男','20','WM')
insert into s
values('201506020','马仁翔','男','21',null)
insert into s
values('201506021','刘仁峰','男','25','CS')
insert into s
values('201506022','牛站强','男','22',null)
insert into s
values('201506023','李婷婷','女','18',null)
insert into s
values('201506024','严小丽','女','20',null)
insert into s
values('201506025','朱小鸥','女','30','WM')

--------------------------------------------------

insert c
values('0001','数据库原理','0005',4)
insert c
values('0002','高等数学',null,2)
insert c
values('0003','软件工程','0001',4)
insert c
values('0004','操作系统','0006',3)
insert c
values('0005','数据结构与算法','0007',4)
insert c
values('0006','数据挖掘原理',null,2)
insert c
values('0007','C语言程序设计','0006',4)
insert c
values('0008','大学英语',null,4)
insert c
values('0009','计算机网络',null,4)
insert c
values('0010','人工智能',null,1)

--------------------------------------------------

insert sc
values('201506001','0001',75)
insert sc
values('201506002','0001',85)
insert sc
values('201506002','0003',53)
insert sc
values('201506003','0001',86)
insert sc
values('201506004','0001',74)
insert sc
values('201506005','0001',58)
insert sc
values('201506006','0001',84)
insert sc
values('201506004','0002',46)
insert sc
values('201506005','0002',89)
insert sc
values('201506006','0002',65)
insert into sc
values('201506008','0002','72')
insert into sc
values('201506009','0002','76')
insert into sc
values('201506010','0008','86')
insert into sc
values('201506011','0008','62')
insert into sc
values('201506015','0008','0')
insert into sc
values('201506018','0008','58')
insert into sc
values('201506001','0004','62')
insert into sc
values('201506002','0004','85')
insert into sc
values('201506021','0009','54')
insert into sc
values('201506001','0005','58')
insert into sc
values('201506021','0006','58')
insert into sc
values('201506001','0007','70')
insert into sc
values('201506005','0010','65')
insert into sc
values('201506016','0008',null)
insert into sc
values('201506017','0008',null)

--------------------------------------------------


--1---------------------------------------------
select *
from s
where sname like '刘%'

--2---------------------------------------------
select *
from s
where sname like '李__'

select *
from s
where sname like '李%' and LEN(sname)=3

--3---------------------------------------------
select *
from s
where YEAR(GETDATE())-sage>1995

--4---------------------------------------------
select 性别=
	case
		when ssex='男' then '男生'
		when ssex='女' then '女生'
		else '条件不明'
	end,sno 学号,sname 姓名,sage 年龄,sdept 院系
from s

--5---------------------------------------------
select *
from c
where cname like '%数据%'

--6---------------------------------------------
select sno 学号,sname 姓名,ssex 性别,sage 年龄,sdept 院系
from s
where sno like '_______[12349]%'
	or sno like '________[12349]%'

select sno 学号,sname 姓名,ssex 性别,sage 年龄,sdept 院系
from s
where SUBSTRING(sno,8,1) in ('1','2','3','4','9')
	or SUBSTRING(sno,9,1) in ('1','2','3','4','9')

--7---------------------------------------------
select sname,score
from s,sc
where s.sno=sc.sno and cno='0001'
order by score desc

--8---------------------------------------------
select *
from s
where sno in (
	select distinct x.sno
	from sc x,sc y
	where x.sno=y.sno and x.cno='0001' and y.cno='0002'
	)

--9---------------------------------------------
select *
from c
order by cpno

--10--------------------------------------------
select sname,sage
from s
where sage >(
	select AVG(sage)
	from s
	)
order by sage desc

--11--------------------------------------------
select sno 学号,sname 姓名,ssex 性别,YEAR(GETDATE())-sage 出生年份,sdept 院系
from s
order by 出生年份

--12--------------------------------------------
select 院系=
	case
		when sdept='CS' then '计算机系'
		when sdept='IS' then '信息系'
		when sdept='MA' then '数学系'
		when sdept='EN' then '外语系'
		when sdept='CM' then '中医系'
		when sdept='WM' then '西医系'
		else '院系不明'
	end,sno 学号,sname 姓名,ssex 性别,sage 年龄
from s
order by 院系 desc

--13--------------------------------------------
select sdept 院系,院系规模=
	case
		when COUNT(sdept)>=5 then '规模很大'
		when COUNT(sdept)>=4 and COUNT(sdept)<5 then '规模一般'
		when COUNT(sdept)>=2 and COUNT(sdept)<4 then '规模稍小'
		else '规模很小'
	end
from s
where sdept != 'null'
group by sdept

--14--------------------------------------------
select sno,cno,score
from sc
where score<70 and score<80
order by cno desc,score desc

--15--------------------------------------------
select COUNT(*) 学生总人数,AVG(sage) 平均年龄
from s

--16--------------------------------------------
select sno 学号,COUNT(sno) 选修课程数
from sc
group by sno

--17--------------------------------------------
select cno 课程号,COUNT(cno) 选修总人数,MAX(score) 最高成绩,MIN(score) 最低成绩,AVG(score) 平均成绩
from sc
group by cno

--18--------------------------------------------
select sno 学号,AVG(score) 平均成绩
from sc
group by sno having AVG(score) > (
	select AVG(score)
	from sc
	where sno='201506001'
	group by sno
	)

--19--------------------------------------------
select cno,COUNT(*) 总人数,sum(
	case
		when score>=60 then 1
		else 0
	end) 及格人数,str(sum(
		case
			when score>=60 then 1
			else 0
		end)*100/COUNT(*),5)+'%' 及格率
from sc
group by cno

--20--------------------------------------------
select sno
from sc
group by sno having COUNT(*) >= all(
	select COUNT(*)
	from sc
	group by sno
	) union
		select sno
		from sc
		group by sno having COUNT(*) <= all(
			select COUNT(*)
			from sc
			group by sno
			)

--21--------------------------------------------
select sdept,SUM(
	case
		when ssex='男' then 1
		else 0
	end
	) 男生人数,SUM(
	case
		when ssex='女' then 1
		else 0
	end
	) 女生人数
from s
where sdept != 'null'
group by sdept

--22--------------------------------------------
select sno 学号,AVG(score) 平均成绩
from sc
where score < 60
group by sno having COUNT(*) >= 2