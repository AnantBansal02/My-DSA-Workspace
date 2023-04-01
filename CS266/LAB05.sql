create table branch_(
    B_Code varchar2(50) primary key,
    B_Name  varchar2(50),
    check(B_Name in ('CSE', 'IT', 'ECE'))
);
create table student(
    S_Roll_No  number primary key,
    S_Name  varchar2(50),
    S_DOB   date,
    S_Gender varchar2(9),
    B_Code varchar2(50),
    check(S_Gender in ('M', 'F', 'O')),
    foreign key(B_Code) references branch_(B_Code)
);

create table course(
    C_Code  varchar2(50) primary key,
    C_Name  varchar2(50),
    C_Credits   number,
    B_Code varchar2(50),
    foreign key(B_Code) references branch_(B_Code),
    check(C_Name in ('DBMS','OS','Maths','CN','Statistics','DSA'))
);
create table enrolled_students(
    S_Roll_no   number,
    C_Code  varchar2(50),
    B_Code varchar2(50),
    foreign key(S_Roll_No) references student(S_Roll_no),
    foreign key(C_Code) references course(C_Code),
    foreign key(B_Code) references branch_(B_Code)
);
create table sports(
    Sport_ID    varchar2(50) primary key,
    Sport_Name  varchar2(50),
    S_Roll_No   number,
    foreign key(S_Roll_no) references student(S_Roll_No)
);

INSERT INTO branch_ VALUES('B001', 'CSE');
INSERT INTO branch_ VALUES('B002', 'IT');
INSERT INTO branch_ VALUES('B003', 'ECE');

INSERT INTO student VALUES(1, 'John Doe', date '2002-01-15', 'M', 'B001');
INSERT INTO student VALUES(2, 'Jane Smith', date '2003-02-20', 'F', 'B002');
INSERT INTO student VALUES(3, 'Bob Johnson', date '2001-05-10', 'M', 'B003');
INSERT INTO student VALUES(4, 'Alice Williams', date '2002-08-02', 'F', 'B001');
INSERT INTO student VALUES(5, 'Charlie Brown', date '2000-12-25', 'M', 'B002');
INSERT INTO student VALUES(6, 'Emily Davis', date '2001-06-08', 'F', 'B002');
INSERT INTO student VALUES(7, 'David Lee', date '2003-11-12', 'M', 'B003');
INSERT INTO student VALUES(8, 'Karen Chen', date '2000-03-17', 'F', 'B001');
INSERT INTO student VALUES(9, 'Samuel Kim', date '2002-09-30', 'M', 'B002');
INSERT INTO student VALUES(10, 'Hannah Lee', date '2001-07-03', 'F', 'B003');

INSERT INTO course VALUES ('C001', 'DBMS', 3, 'B001');
INSERT INTO course VALUES  ('C002', 'OS', 4, 'B001');
INSERT INTO course VALUES  ('C003', 'Maths', 3, 'B002');
INSERT INTO course VALUES  ('C004', 'CN', 4, 'B002');
INSERT INTO course VALUES  ('C005', 'Statistics', 3, 'B003');
INSERT INTO course VALUES  ('C006', 'DSA', 4, 'B003');

INSERT INTO enrolled_students VALUES('1','C001','B001');  
INSERT INTO enrolled_students VALUES('1','C002','B001');  
INSERT INTO enrolled_students VALUES('2','C001','B001');  
INSERT INTO enrolled_students VALUES('3','C003','B002');
INSERT INTO enrolled_students VALUES('3','C003','B002');
INSERT INTO enrolled_students VALUES('4','C004','B002');
INSERT INTO enrolled_students VALUES('5','C005','B003');
INSERT INTO enrolled_students VALUES('5','C006','B003');
INSERT INTO enrolled_students VALUES('6','C005','B003');
INSERT INTO enrolled_students VALUES('7','C004','B002');
INSERT INTO enrolled_students VALUES('8','C001','B001');  
INSERT INTO enrolled_students VALUES('9','C005','B003');
INSERT INTO enrolled_students VALUES('10','C001','B001');  

INSERT INTO sports VALUES('S0011','Chess','1');
INSERT INTO sports VALUES('S0032','Volleyball','3');
INSERT INTO sports VALUES('S0073','Table Tennis','7');
INSERT INTO sports VALUES('S0044','Carrom','4');
INSERT INTO sports VALUES('S0055','Cricket','5');
INSERT INTO sports VALUES('S0041','Chess','4');
INSERT INTO sports VALUES('S0092','Volleyball','9');
INSERT INTO sports VALUES('S0103','Table Tennis','10');
INSERT INTO sports VALUES('S0024','Carrom','2');
INSERT INTO sports VALUES('S0065','Cricket','6');

select student.S_Roll_No, S_Name, S_Gender, C_Name
from student 
join enrolled_students 
on enrolled_students.S_Roll_No = student.S_Roll_No
join course
on enrolled_students.C_Code = course.C_Code
where C_Name = 'OS' or C_Name = 'DBMS';

select student.S_Roll_no, S_Name, S_Gender, Sport_Name
from student 
join sports
on sports.S_Roll_No = student.S_Roll_no
where S_Gender = 'F';

select student.*, C_Name, Sport_Name from student
join enrolled_students
on enrolled_students.S_Roll_No = student.S_Roll_No
join sports
on sports.S_Roll_No = student.S_Roll_no
join course
on enrolled_students.C_Code = course.C_Code
where C_Name = 'DBMS' and Sport_Name is not null;

select * from student 
join sports on sports.S_Roll_No = student.S_Roll_no 
where (student.S_DOB like '%NOV%' or student.S_DOB like '%DEC%') 
AND sports.Sport_Name in ('Chess');

select * from student
join sports on sports.S_Roll_No = student.S_Roll_no 
where student.S_Name like 'A%';

select Sport_Name, count(Sport_Name) as count 
from sports 
group by Sport_Name 
order by count(Sport_Name) desc;

select Distinct course.C_Name , count(Distinct student.S_Roll_No) as student_count
from student 
join enrolled_students 
on enrolled_students.S_Roll_No = student.S_Roll_No
join course
on enrolled_students.C_Code = course.C_Code
group by  course.C_name order by student_count;

select Distinct branch_.B_name , count(Distinct enrolled_students.S_Roll_No) as student_count from enrolled_students
join branch_ on branch_.B_Code = enrolled_students.B_Code
group by branch_.B_Name order by student_count;

select Distinct Course.C_Name , count(Distinct enrolled_students.S_Roll_No) as student_count from enrolled_students
join course
on enrolled_students.C_Code = course.C_Code
group by course.C_Name
having count(Distinct enrolled_students.S_Roll_No) > 2;

select * from course where C_Credits = 1 or C_Credits = 2;

select * from student
join course on course.B_Code = student.B_Code
where course.C_Credits = 1 or course.C_Credits = 2;

SELECT s1.S_Roll_No, s2.S_Roll_No, s1.Sport_name 
FROM Sports s1 
JOIN Sports s2 ON s1.Sport_name = s2.Sport_name AND s1.S_Roll_No < s2.S_Roll_No;

SELECT * 
FROM Sports 
WHERE Sport_Name = 'Chess' AND S_Roll_No NOT IN ( 
    SELECT S_Roll_No 
    FROM enrolled_students 
    join course
    on course.C_Code = enrolled_students.C_Code
    WHERE C_Name IN ('Maths') 
);

UPDATE student set Student.S_Name='Shankar' 
where Student.S_Roll_No = 5;
SELECT * 
FROM student 
WHERE S_Roll_No = 5;

delete from enrolled_students 
join course
on enrolled_students.C_Code = course.C_Code 
where C_Name='Maths' and S_Roll_No in( 
select S_Roll_No 
from sports 
where Sport_Name ='Volleyball')

Statement 1 Edit • CREATE TABLE Actor ( • actor_id INT PRIMARY KEY, • actor_name VARCHAR(255) NOT NULL, • gender VARCHAR(10) )