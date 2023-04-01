create table Staff(
    Staff_ID    number primary key,
    Staff_Name  varchar2(50),
    Staff_Age   number,
    Staff_Address   varchar2(50),
    Monthly_Package number 
);
insert into Staff values ('1','ARYAN','22','MUMBAI','18000');
insert into Staff values('2','SUSHIL','32','DELHI','20000');
insert into Staff values('3','MONTY','25','MOHALI','22000');
insert into Staff values('4','AMIT','20','ALLAHABAD','12000');

create table Payments(
    Payment_ID  number,
    Payment_Date    date,
    PStaff_ID number,
    Amount  float
);
insert into Payments values('101','30-Dec-2009','1','3000.00');
insert into Payments values('102','22-Feb-2010','3','2500.00');
insert into Payments values('103','23-Feb-2010','4','3500.00');
insert into Payments values('104','28-Feb-2010','5','3800.00');

select * from Staff inner join Payments on Staff.Staff_ID = Payments.PStaff_ID;
select * from Staff left join Payments on Staff.Staff_ID = Payments.PStaff_ID;
select * from Staff right join Payments on Staff.Staff_ID = Payments.PStaff_ID;
select * from Staff full join Payments on Staff.Staff_ID = Payments.PStaff_ID;



create table Customer(
    Customer_ID    number primary key,
    C_Name  varchar2(50),
    C_Email   varchar2(50),
    C_Address   varchar2(50)
);
insert into Customer values ('100','Aarav','aarav@gmail.com','Ahmedabad');
insert into Customer values ('101','Aryan','aryan@yahoo.com','Delhi');
insert into Customer values ('102','Dhruv','dhruv@outlook.com','Mumbai');
insert into Customer values ('103','Nitya','nitya@gmail.com','Pune');
insert into Customer values ('104','Vikram','vikram@yahoo.com','Chennai');
insert into Customer values ('105','Yuvika','yuvika@gmail.com','Kolkata');

create table Orders(
    Order_ID  number primary key,
    Customer_ID number,
    Order_Date date,
    Contact  number,
    foreign key(Customer_ID) references Customer(Customer_ID)
);
insert into Orders values('202262005','100','18-Sep-2012','9123564615');
insert into Orders values('202262001','101','28-Jul-2021','7990254615');
insert into Orders values('202263003','102','10-Dec-2022','8795162381');
insert into Orders values('202262004','103','19-May-2017','9898785123');
insert into Orders values('202263005','104','10-Jan-2019','7895136324');
insert into Orders values('202262002','105','13-Jun-2011','6351789641');

select Customer_ID, C_Name from Customer where C_Email like '%gmail.com';
select * from Customer where C_Name not like 'A%';
select C_Name,Order_Date,Contact,C_Email,C_Address from Customer inner join Orders on Customer.Customer_ID = Orders.Customer_ID;
select Customer.Customer_ID, C_Name, C_Email, C_Address, Contact from Customer full join Orders on Customer.Customer_ID = Orders.Customer_ID;

create table books(
    ISBN    number,
    Title   varchar2(500),
    Unit_Price  number,
    Author_Name varchar(500) primary key,
    Publisher_Name  varchar2(500),
    Publish_Year    number
);
insert into books values('1001','Harry Potter','3100','J.K. Rowling','Scholastic Press','1998');
insert into books values('1002','The Hitchhikers Guide to the Galaxy','4500','Douglas Adams','Mass Market Paperback','2000');
insert into books values('1003','Changeling','800','Delia Sherman','Springer','2008');
insert into books values('1004','Giving Good Weight','1280','John McPhee','Spiegel & Grau','2006');
insert into books values('1005','Writing','1700','Marguerite Duras','Paperback','2001');

create table authors(
    Author  varchar2(500),
    Country varchar2(500),
    foreign key(Author) references books(Author_Name)
);

insert into authors values('J.K. Rowling','U.K.');
insert into authors values('Douglas Adams','U.K.');
insert into authors values('Delia Sherman','Japan');
insert into authors values('John McPhee','U.S.A.');
insert into authors values('Marguerite Duras','Germay');

select count(*) from books;
select * from books where rownum<=3;
select Title from books where Unit_Price>1000 and Unit_Price<3000;
select Title, Author_Name, Country, Publish_Year from books inner join authors on books.Author_Name = authors.Author;
select Title from books where Publisher_Name = 'Scholastic Press' or Publisher_Name = 'Paperback';
select Title, Author_Name, Country from books inner join authors on books.Author_Name = authors.Author;
select Author_Name, Title from books inner join authors on books.Author_Name = authors.Author where Country = 'U.K.';


create table Salesman(
    Salesman_ID number primary key,
    Salesman_Name   varchar2(50),
    Salesman_City   varchar2(50),
    Commission  float
);
insert into Salesman values('5001','James Hoog','New York','0.15');
insert into Salesman values('5002','Nail Knite','Paris','0.13');
insert into Salesman values('5005','Pit Alex','London','0.11');
insert into Salesman values('5006','Mc Lyon','Paris','0.14');
insert into Salesman values('5007','Paul Adam','Rome','0.12');

create table Customer(
    Customer_ID number primary  key,
    Customer_Name   varchar2(50),
    Customer_City   varchar2(50),
    Grade   number,
    Salesman_ID number references Salesman(Salesman_ID) 
);
insert into Customer values('3002','Brad Swift','New York','300','5001');
insert into Customer values('3003','Becky Parker','California','200','5002');
insert into Customer values('3004','William Bowery','London','100','5005');
insert into Customer values('3005','Steve Chen','Paris','100','5006');
insert into Customer values('3006','Justin Rud','New Jersey','300','5007');

update Salesman set Commission = Commission + Commission*0.0015;
select Salesman_Name, Customer_Name,Salesman.Salesman_City from Salesman inner join Customer on Customer.Customer_City = Salesman.Salesman_City;
select Salesman.* from Salesman join Customer on Salesman.Salesman_ID = Customer.Salesman_ID where Salesman.Salesman_City != Customer.Customer_City;