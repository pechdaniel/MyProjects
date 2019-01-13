use Practice;

create table Antrenamente(
AID int primary key identity,
Locatie varchar(50)
);


create table Sportivi(
SpID int primary key identity(1,1),
Nume varchar(50),
Varsta int,
AID int foreign key references Antrenamente(AID)
);


create table Cluburi_Sportive(
CLID int primary key identity,
Nume_Club varchar(50),
Sportivi int,
SpID int foreign key references Sportivi(SpID)
);


create table Competitii(
CID int primary key identity,
Locatie varchar(50)
);


create table S_C(
SpID int foreign key references Sportivi(SpID),
CID int foreign key references Competitii(CID),
constraint PK_sc primary key(SpID,CID)
);


delete from Cluburi_Sportive
delete from Sportivi
delete from Antrenamente

insert into Antrenamente values ('San andreas'),('Miami'),('Broadway'),('Singapore'),('Baia Mare'),('Budapest')
insert into Sportivi ([Nume],[Varsta],[AID]) values ('Adrian',12,1),('Misu',14,2),('Loti',12,3),('Georgica',14,4),('Dica',12,5),('Gica',14,6)
insert into Cluburi_Sportive ([Nume_Club],[Sportivi]) values ('CSM',200),('DES',201),('JNF',202),('LER',203),('JSU',204),('ADH',205)
insert into Competitii values ('San andreas'),('Miami'),('Broadway'),('Singapore'),('Baia Mare'),('Budapest')
insert into S_C values (8,1),(10,3),(9,2),(11,4),(12,5),(13,6)

select * from Sportivi S
where s.Nume like 'G%'

go
create or alter procedure selectJoin
as
begin
	select * from Competitii c
	inner join S_C s on s.CID=c.CID and s.SpID>11 and Locatie like 'Ba%'
end

go
create or alter view MyViewHere
as
	select distinct C.CID as 'MyID',C.Locatie as 'Location' from Competitii c
	inner join S_C s on s.CID=c.CID and s.SpID>11 and Locatie like 'Ba%'
go

exec selectJoin

select * from MyViewHere