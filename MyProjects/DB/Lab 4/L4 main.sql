use L4;

delete from Shelter_Contract
delete from Dog_Shelter
delete from Dogs
delete from Person
delete from Found

insert into Dogs ([DID],[Dog_Name],[Age]) values (1,'Rex',2),(2,'Ronnie',1),(3,'Max',0),(4,'Patty',3),(5,'Rimm',5),(6,'Casper',7)
insert into Dogs ([DID],[Dog_Name],[Age]) values (7,'Rexy',2),(8,'Ronny',1),(9,'Maxy',0),(10,'Patt',3),(11,'Rimmy',5),(12,'Craspy',7)
insert into Person ([PID],[Person_Name]) values (1,'Andy'),(2,'Shannon'),(3,'Mathew'),(4,'Alex'),(5,'Gunther'),(6,'Paul')
insert into Found ([FID],[Address_Found],[Time_Found]) values (1,'Main street',getdate()),(2,'Second street',getdate())
go
create or alter procedure RunMe
as
begin
delete from TestRunViews
delete from TestRuns
delete from TestRunTables

DECLARE @ds  datetime
DECLARE @de  datetime
SET @ds = GETDATE()

INSERT INTO TestRuns(TestRunID,Description, StartAT, EndAt) VALUES (2,'View', @ds, @ds)

execute RunViewTests

SET @de = GETDATE()
UPDATE TestRuns
SET EndAt = @de
WHERE Description = 'View'

SET @ds = GETDATE()
INSERT INTO TestRuns(TestRunID,Description, StartAT, EndAt) VALUES (1,'Insert', @ds, @ds)
INSERT INTO TestRuns(TestRunID,Description, StartAT, EndAt) VALUES (3,'Delete', @ds, @ds)
EXECUTE RunTableTests 

SET @de = GETDATE()
UPDATE TestRuns
SET EndAt = @de
WHERE Description = 'Insert' OR Description = 'Delete'
select * from TestRuns
select * from TestRunTables
select * from TestRunViews
select * from Dogs
select * from Dog_Shelter
select * from Person
end
go

create or alter procedure updateRows
@newnr int
as
begin
	update TestTables
	set NoOfRows=@newnr
end

go
execute updateRows 1
select * from TestTables

exec RunMe