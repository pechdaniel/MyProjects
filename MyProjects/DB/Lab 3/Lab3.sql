use Lab1bun;
-----------------------------------------A
go
create procedure do1
as
begin
alter table Mall 
alter column Mall_Name nvarchar(20)
end;
go

go
create procedure undo1
as
begin
alter table Mall 
alter column Mall_Name varchar(20)
end;
go
-----------------------------------------B
go
create procedure do2
as
begin
alter table Agency
add Location_Address varchar(20)
end;
go

go 
create procedure undo2
as
begin
alter table Agency
drop column Location_Address
end;
go
-----------------------------------------C
go
create procedure do3
as
begin
alter table Agency
add LocationAddress varchar(20)
alter table Agency
add constraint addrconstr
default 'Romania' for LocationAddress
end;
go

go
create procedure undo3
as
begin
alter table Agency
drop constraint addrconstr
alter table Agency
drop column LocationAddress
end;
go
-----------------------------------------D
go
create procedure do4
as
begin
create table Jaguar(
Dots int not null
);
alter table Jaguar
add constraint PK_Dots primary key clustered(Dots);
end;
go

go
create procedure undo4
as
begin
alter table Jaguar
drop constraint PK_Dots
drop table Jaguar
end;
go
-----------------------------------------E
go
create procedure do5
as
begin
create table Jaguar1(
Dots1 int not null,
Years1 int not null
);
alter table Jaguar1
add constraint PK_Dots1 primary key clustered(Dots1)
alter table Jaguar1
drop constraint PK_Dots1
alter table Jaguar1
drop column Dots1
alter table Jaguar1
add constraint PK_Years1 primary key clustered(Years1)
end;
go

go
create procedure undo5
as
begin
alter table Jaguar1
drop constraint PK_Years1
drop table Jaguar1
end;
go
-----------------------------------------F
go
create procedure do6
as
begin
create table Cub(
Birth_Date char(20) not null,
primary key(Birth_Date)
);
create table Jaguar2(
Dots2 int not null,
Years2 int not null,
primary key(Dots2)
);
alter table Jaguar2
add Birth_Date char(20)
alter table Jaguar2
add constraint FK_BD foreign key(Birth_Date) references Cub(Birth_Date)
end;
go

go
create procedure undo6
as
begin
alter table Jaguar2
drop constraint FK_BD
alter table Jaguar2
drop column Birth_Date
drop table Jaguar2
drop table Cub
end;
go
-----------------------------------------G
go
create procedure do7
as
begin
create table MyTable(
TID int not null,
primary key(TID)
);
end;
go

create procedure undo7
as
begin
drop table MyTable
end;
go

---------------------------------------------------------------------------------------------------

CREATE TABLE MyVersion  
	(  
	   Version_ID int IDENTITY (1,1) NOT NULL,
	   CurrentVersion int,  
	   CONSTRAINT PK_Version_ID PRIMARY KEY CLUSTERED (Version_ID)  
	); 
Insert into MyVersion Values(0);

go
Create PROCEDURE TakeMeToVersion
	@versionTo int
AS
BEGIN
	DECLARE @versionFrom int

	SET @versionFrom = (select V.CurrentVersion
							from MyVersion V)

	DECLARE @query varchar(2000)

	IF @versionTo <= 7 AND @versionTo >=0
		IF @versionTo > @versionFrom
		BEGIN
			 WHILE @versionTo>@versionFrom
				BEGIN
					set @versionFrom = @versionFrom + 1
					set @query = 'do' + CAST(@versionFrom AS VARCHAR(5))
					exec @query
				END
		END
		ELSE  
		BEGIN 
			WHILE @versionTo<@versionFrom
				BEGIN
					IF @versionFrom!=0
					BEGIN
						set @query = 'undo' + CAST(@versionFrom AS VARCHAR(5))
						exec @query
					END
					set @versionFrom = @versionFrom - 1
				END
		END
		update MyVersion 
		set CurrentVersion = @versionTo
END
go

exec TakeMeToVersion  5;
select CurrentVersion
from MyVersion