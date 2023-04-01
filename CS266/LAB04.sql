create table Department(
    Department_ID   number primary key,
    Department_Name varchar2(50)
);
create table Employee(
    Emp_Number    number,
    Emp_Name    varchar2(50),
    Department_ID   number,
    Emp_Salary  number,
    Joining_Year    number,
    Emp_Email    varchar2(50),
    foreign key(Department_ID) references Department(Department_ID)
);
create table Increment_(
    Emp_Number  number,
    Salary_Increment    number
);
create table Teachers(
    Teacher_ID  number,
    Teacher_Name    varchar2(50)
);
create table Students(
    Student_ID  number primary key,
    Teacher_ID  number
);
insert into Department values('1','CSE');
insert into Department values('2','IT');
insert into Department values('3','Mechanical');
insert into Department values('4','Civil');
insert into Department values('5','Student_Affairs');
insert into Department values('6','Academic');
insert into Department values('7','Accounts');


INSERT INTO Employee VALUES (1, 'John Doe', 1, 50000, 2015, 'abc@gmail.com');
INSERT INTO Employee VALUES (2, 'Jane Doe', 2, 55000, 2016, 'sample');
INSERT INTO Employee VALUES (3, 'Bob Smith', 4, 52000, 2014, 'xyz@outlook.com');
INSERT INTO Employee VALUES (4, 'Alice Johnson', 7, 60000, 2017, 'qwe@yahoo.com');
INSERT INTO Employee VALUES (5, 'XYZ', 6, 75000, 2013, 'zxc@hotmail.com');
INSERT INTO Employee VALUES (6, 'Sarah Lee', 5, 63000, 2018, 'gsg@google.com');
INSERT INTO Employee VALUES (6, 'Sarah Lee', 5, 63000, 2018, 'gsg@google.com');
INSERT INTO Employee VALUES (7, 'David Green', 3, 57500, 2012, 'qff@outlook.com');
INSERT INTO Employee VALUES (8, 'Rachel Davis', 2, 57000, 2019, 'gzv@hotmail.com');
INSERT INTO Employee VALUES (8, 'Rachel Davis', 2, 57000, 2019, 'gzv@hotmail.com');
INSERT INTO Employee VALUES (9, 'James Brown', 1, 62000, 2016, 'rqf@yahoo.com');
INSERT INTO Employee VALUES (10, 'Michael Scott', 4, 55000, 2014, 'fvb@gmail.com');
INSERT INTO Employee (Emp_Number, Emp_Name, Emp_Salary, Joining_Year, Emp_Email)
VALUES (11, 'PQR', 55000, 2014,'wfg@gmail.com');


INSERT INTO Increment_ VALUES (1, 1000);
INSERT INTO Increment_ VALUES (2, 1500);
INSERT INTO Increment_ VALUES (3, 2000);
INSERT INTO Increment_ VALUES (4, 1700);
INSERT INTO Increment_ VALUES (5, 1200);
INSERT INTO Increment_ VALUES (6, 1300);
INSERT INTO Increment_ VALUES (7, 1400);
INSERT INTO Increment_ VALUES (8, 1500);
INSERT INTO Increment_ VALUES (9, 1600);
INSERT INTO Increment_ VALUES (10, 1700);

INSERT INTO Teachers VALUES (1, 'Sarah Johnson');
INSERT INTO Teachers VALUES (2, 'David Brown');
INSERT INTO Teachers VALUES (3, 'Rachel Davis');
INSERT INTO Teachers VALUES (4, 'James Smith');
INSERT INTO Teachers VALUES (5, 'Michael Lee');
INSERT INTO Teachers VALUES (5, 'Michael Lee');
INSERT INTO Teachers VALUES (3, 'Rachel Davis');


INSERT INTO Students VALUES (1, 1);
INSERT INTO Students VALUES (2, 2);
INSERT INTO Students VALUES (3, 1);
INSERT INTO Students VALUES (4, 3);
INSERT INTO Students VALUES (5, 2);
INSERT INTO Students VALUES (6, 4);
INSERT INTO Students VALUES (7, 5);
INSERT INTO Students VALUES (8, 2);
INSERT INTO Students VALUES (9, 4);
INSERT INTO Students VALUES(10, 3);

select * from Department;
select * from Employee;
select * from Increment_;
select * from Teachers;
select * from Students;

select max(Emp_Salary) from Employee where Emp_Salary < (select max(Emp_Salary) from Employee);
SELECT Teacher_ID, Teacher_Name, COUNT(*) FROM Teachers GROUP BY Teacher_ID, Teacher_Name HAVING COUNT(*) > 1;
select Emp_Number, Emp_name, round(Emp_Salary/12) from Employee;
select * from Employee where rownum = 1;
select * from Department order by rownum desc offset 0 rows fetch next 1 rows only;
select * from Employee where rownum <= 5;
select * from Employee order by Emp_salary desc offset 0 rows fetch next 3 rows only;
create table Employee_2 as select * from Employee where 1 = 0; 
desc Employee_2;
select * from Employee offset 0 rows fetch next 50 percent rows only;
select * from Teachers inner join Students on Teachers.Teacher_ID=Students.Teacher_ID;
select * from Employee where Department_ID is null;
select * from Increment_ union select * from Increment_;
select * from employee where Emp_Name = 'XYZ' or Emp_Name = 'PQR';
select * from employee where Emp_Name not like 'XYZ' and Emp_Name not like 'PQR';
select * from employee where Joining_year like '%2017%';
select Department_ID, max(Emp_Salary) from employee group by Department_ID;
select * from employee where Joining_year like '%2016%' and Emp_Salary>10000;
SELECT RPAD('*', LEVEL, '*') AS output FROM DUAL CONNECT BY LEVEL <= 3;
SELECT * from employee where Emp_Email like '%@%.com';
SELECT ROWNUM AS num 
FROM DUAL 
CONNECT BY ROWNUM <= 100;
SELECT Emp_Number, Emp_Name, Department_ID, Emp_Salary, Joining_Year, Emp_Email, COUNT(*) FROM employee GROUP BY Emp_Number, Emp_Name, Department_ID, Emp_Salary, Joining_Year, Emp_Email HAVING COUNT(*) > 1;
DELETE FROM employee WHERE ROWID NOT IN (SELECT MIN(ROWID) FROM employee GROUP BY Emp_Number, Emp_Name, Department_ID, Emp_Salary, Joining_Year, Emp_Email);
select * from Teachers inner join Students on Teachers.Teacher_ID=Students.Teacher_id;
select * from Teachers left join Students on Teachers.Teacher_ID=Students.Teacher_id;
select * from Teachers right join Students on Teachers.Teacher_ID=Students.Teacher_id;
select * from Teachers full outer join Students on Teachers.Teacher_ID=Students.Teacher_id;
select Department.Department_ID, Department.Department_Name from Department join employee on Department.Department_ID=employee.Department_ID group by Department.Department_ID, Department.Department_Name;
select employee.Emp_Name, Department.Department_Name from employee join Department on Department.Department_ID=employee.Department_ID;
SELECT Department.Department_Name, LISTAGG(employee.Emp_Name, ', ')
WITHIN GROUP (ORDER BY employee.Emp_Name) AS employees
FROM Department
JOIN employee ON Department.Department_ID = employee.Department_ID
GROUP BY Department.Department_Name;

SELECT employee.Emp_Name, Department.Department_Name,
Increment_.Salary_Increment
FROM employee
JOIN Department ON employee.Department_ID = Department.Department_ID
JOIN Increment_ ON employee.Emp_Number = Increment_.Emp_Number;