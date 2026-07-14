--Lab No. 1 Use of Single Table

--1.Create a database 'Collge' 
CREATE DATABASE College;

--2 Connect a College database
use College;

--3 Create a table Student
CREATE TABLE Student
(sid int primary key,
sname varchar(20),
address varchar(20),
marks int,
DOB date
);

--4. Insert any 5 records to student table 
insert into student
values(1,'Aditi','Kathmandu',180,'2005-06-08'),
(2,'Binika','Kathmandu',180,'2005-10-19');

--5.Display records of Student table

select sid,sname,address,marks,DOB
From Student;
 -- or select * from student 

 -- display name and marks of all students
 select sname,marks 
 from Student

--adding new field on the existing table 
alter table Student
add email varchar(30)

select *
from Student

--remove marks field
alter table Student
drop column marks;

select *
from Student

--createtable for deleting the given database,table,field within the table
create table test
(id int );

insert into test
values(
10
);

select * 
from test

drop table test;

select * 
from test

--change field name 
--change field address to location
exec sp_rename 'Student.address','location','column';

select *
from student

-- change table name
--change student to Biddharthi

exec sp_rename 'Student', 'Biddharthi';
select *
from Biddharthi

exec sp_rename 'Biddharthi','Student';
select*
from Student

insert into student
values(6,'Ram','Kathmandu','2005-10-01','ram@gmail.com');
select*
from Student

insert into student
values(7, 'Hari', 'Pokhara', '2006-7-8','hari@gmail.com'),
(8, 'Hari', 'Pokhara', '2006-7-8','hari@gmail.com');

select*
from Student

create table test
(id int,name varchar(20),
DOB Date,
Email Varchar(20),
marks int,
gender varchar(5)
);
select*
from test

insert into student
select id,name,DOB,email
from test;


create table tests
(id int,name varchar(20),
DOB Date,
address varchar(30),
Email Varchar(20),
marks int,
gender varchar(5)
);
select*
from tests

insert into student
select id,name,address,DOB,email
from tests;

select *
from Student

select*
from tests

select *
from Student

--display all records of student in ascending order of their dob
select*
from student 
order by DOB;-- ascending in default

select *
from student
order by DOB DESC;

--where clause
select sname
from student
where DOB > '2005-06-01';

--display records of all student of address kathmandu or bhaktapur or pokhara
select *
from student
where location = 'Itahari' OR location = 'Bhaktapur' OR location = 'Pokhara';

--display records of all student of address kathmandu or bhaktapur or pokhara along with dob

select*
from student
where location = 'Itahari' AND DOB > '2010 -01-01';

--display records of all student of address ktm or lalitpur or pokhara
-- use of IN
select *
from student
where location IN ('Itahari','Bhaktapur','pokhara');

--display records of all student of address not in ktm or lalitpur or pokhara
select *
from student
where location NOT IN ('Itahari','Bhaktapur','pokhara');

--use of like (wildcards)
--Display records of all students of name start with 'A' OR of location length 7
select *
from student
where sname like 'A%' or location like '_';

select * 
from student

select * from student

--display name and DOB of all students of DOB between '2010-01-10' to '2024-01-01';
select sname , DOB
from student
where DOB between '2010-01-10' and '2024-01-01';

--alternate query
select sname, DOB
from student
where DOB >  '2010-01-10' and DOB < '2024-01-01';

--display name and DOB of all students of DOB  not between '2010-01-10' to '2024-01-01';
select sname , DOB
from student
where DOB not between '2010-01-10' and '2024-01-01';

--alternate query
select sname, DOB
from student
where DOB < '2010-01-10' or DOB > '2024-01-01';

--null/not null
select sname, email
from student
Where email IS NULL;

select sname, email
from student
Where email IS NOT NULL;


--display name of students of dob less than 2015-01-01 with field name student_name
Select sname as student_name
From student
Where DOB < '2015-01-01';

--Alternate way
Select sname  student_name
From student
Where DOB < '2015-01-01';

--Update table content
update student
Set DOB = '2024-01-01'
where email like '%gmail.com';
select*
From student 

--Delete record of all students of location is Pokhara
Delete From student
where location = 'Pokhara';
select*
From student

--add new attribute on the table
alter table Student
add marks int;

--count no of students of email in a @yahoo.com
select count (sid) as 'No. of student'
from student
where email like '%@yahoo.com';
a
--find minimum and maximum marks of students
select min(marks) as 'Minimum Marks',max(marks) as 'Maximum Marks'
from student

--average 
select avg (marks) as 'Average marks'
from student

--sum
select sum (marks) as 'Total marks'
from student

--find name and marks of a oldest student
select sname,marks
from student
where dob = (select min(dob) from student);

--display name of student who get maximum marks
select sname,marks
from student
where marks = (select max(marks) from student);

--group by clause
--find average marks of the student at every address level
select avg(marks) as 'Average marks',location
from student
group by(location);

--find total no of the student at every address level
select count(sid) as 'Total no',location
from student
group by(location);

--having clause
--find total students and their address in every address level with total student greater than 2
select count(sid) as 'Total no',location
from student
group by(location)
having count(sid) > 2;

--displaying data from multiple tables (join operation)
CREATE TABLE Course
(cid varchar(10) primary key,
cname varchar(20),
credithr int,
teachername varchar(20),
sid int,
foreign key (sid) references student(sid)
);

 insert into Course
 values('C1','Computer Science',100,'Ema Gurung',1);

 select *
 from course

 --find related records of these two tables
 select *
 from student as s cross join course as c
 where s.sid = c.sid;