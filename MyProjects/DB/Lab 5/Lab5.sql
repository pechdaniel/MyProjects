use Lab5;

create table Dogs(
DID int primary key,
Dog_Name char(20),
Age int
);

create table Person(
PID int primary key,
Person_Name char(20),
Age int
);

create table Shelter_Contract(
SHID int primary key,
DID int foreign key references Dogs(DID),
PID int foreign key references Person(PID),
Duration int
);

delete from Shelter_Contract
delete from Person
delete from Dogs

insert into Dogs ([DID],[Dog_Name],[Age]) values (1,'Antiq',2),(2,'Ronnie',1),(3,'Max',0),(4,'Patty',3),(5,'Shimmi',5),(6,'Casper',7)
insert into Dogs ([DID],[Dog_Name],[Age]) values (7,'Army',2),(8,'Ronny',1),(9,'Maxy',0),(10,'Patt',3),(11,'Shanga',5),(12,'Craspy',7)
insert into Person ([PID],[Person_Name],[Age]) values (1,'Andy',30),(2,'Shannon',48),(3,'Mathew',29),(4,'Alex',70),(5,'Gunther',34),(6,'Paul',21)
insert into Person ([PID],[Person_Name],[Age]) values (7,'Andrew',30),(8,'Sharon',48),(9,'Matt',29),(10,'Alec',70),(11,'Gertrude',34),(12,'Penn',21)
insert into Shelter_Contract ([SHID],[DID],[PID],[Duration]) values (1,1,1,2),(2,2,4,2),(3,3,9,4),(4,5,8,3),(5,9,3,6),(6,7,7,3)

-- a Write queries on Ta such that their corresponding execution plans contain the following operators
-- clustered index scan
	select Age from Dogs
-- clustered index seek
	select Age from Dogs
	where Dog_Name like 'A%'
-- nonclustered index scan
	create nonclustered index [myIndex1] on Dogs(Age)
	select Age from Dogs

	drop index myIndex1 on Dogs
-- nonclustered index seek
	select Age from Dogs where Age>=1
-- key lookup
	select * from Dogs with (index =MyIndex1)  where Age>=1

-- b Write a query on table Tb with a WHERE clause of the form WHERE b2 = value and analyze its execution plan. 
-- Create a nonclustered index that can speed up the query. 
-- Recheck the query’s execution plan (operators, SELECT’s estimated subtree cost)
	
-- clustered 0.0032952
	select Age from Person
	where Age >=30

-- nonclustered 0.0032908
	create nonclustered index myIndex2 on Person(Age)
	select Age from Person
	where Age >=30

	drop index myIndex2 on Person

-- c Create a view that joins at least 2 tables. Check whether existing indexes are helpful; 
-- if not, reassess existing indexes / examine the cardinality of the tables
drop view MyView

create view MyView
as
-- selects the contract id's that are greater than 1 and in which the dog name and person mane start with the same letter
select distinct S.SHID from Shelter_Contract S
inner join (select D.DID from Dogs D inner join Person P on (substring(D.Dog_Name,1,1)=substring(P.Person_Name,1,1))) M 
on S.DID=M.DID
where S.SHID>1

-- clustered 0.00111683
select * from MyView

-- nonclustered 0.00
create nonclustered index [MyIndex3] on Shelter_Contract(SHID)
select * from MyView

drop index MyIndex3 on Shelter_Contract