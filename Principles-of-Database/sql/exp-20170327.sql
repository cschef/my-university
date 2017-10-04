create database [15111204011丁鹏]
go

use [15111204011丁鹏]
go

select *
from 学生
go

select 教师编号,姓名,职称
from 教师
go

select 姓名,YEAR(GETDATE())-YEAR(出生日期) as 年龄
from 教师
go

select 学号
from 课程注册
go

select distinct 学号
from 课程注册
go

select top 3 *
from 课程注册
go

select *
from 课程注册
where 成绩>=50
go

select 姓名,学号,出生日期
from 学生
where YEAR(出生日期) between 1970 and 1982
go

select 班级代码,班级名称
from 班级
where 系部代码 in ('01','02');
go

select *
from 学生
where 姓名 like '周%'
go

insert into 课程(课程号,课程名,学分)
values('0005','Photoshop_7.1',4)
select 课程号,课程名
from 课程
where 课程名 like 'Photoshop/_7.1' escape '/'
go

select *
from 教师
where 备注 is null
go

select 学号,成绩
from 课程注册
where 课程号='0001' and 成绩>=70 and 成绩<79
go

select 学号,成绩
from 课程注册
where 课程号='0001'
order by 成绩 desc
go

select *
from 学生
order by 班级代码 desc, 学号 asc
go

select COUNT(*) 教师总数
from 教师
go

select AVG(成绩) 平均分
from 课程注册
go

select 课程号,COUNT(*) 选课人数
from 课程注册
group by 课程号 having COUNT(*)>=4
go

select *
from 课程注册
order by 学号
compute sum(成绩)
go

select *
from 课程注册
order by 学号
compute sum(成绩) by 学号
go

select * into 课程注册副本
from 课程注册
go
select*
from 课程注册副本
go

select * into 教师副本
from 教师
where 1=2
go

select *
from 课程注册
where 专业代码='0102'
union
select *
from 课程注册
where 成绩>=70 and 成绩<79
order by 成绩
go

select *
from 课程注册
where 课程号='0001'
union
select *
from 课程注册
where 课程号='0002'
order by 课程号 asc
go

select 学号,姓名,性别,学生.系部代码,学生.专业代码,专业.专业代码,专业名称,专业.系部代码
from 学生 cross join 专业
go

select 学号,姓名,性别,学生.系部代码,学生.专业代码,专业.专业代码,专业.专业名称,专业.系部代码
from 学生 inner join 专业 on 学生.专业代码=专业.专业代码
go