use L4;

go
create or alter procedure RunTableTests
as
begin
	declare @ds date
	declare @de date
	declare @tableId int
	declare @position int
	declare @tableName varchar(50)
	declare @datestart datetime
	declare @dateend datetime
	declare @testId int
	declare @rows int

	set @testId = 1
	set @position = 1
	while @position < 4
	begin
		select @tableId=tt.TableID, @rows=tt.NoOfRows  from TestTables tt where tt.Position = @position and tt.TestID = @testId
		select @tableName=t.Name  from Tables t where @tableId = t.TableID
		print @tableName
		set @datestart = GETDATE()
		
		declare @command varchar(100)
		
		set @command = 'insertIntoTable '+ @tableName + ',' + cast(@rows as varchar(5))
		exec (@command)
		
		set @dateend=GETDATE()
        insert into TestRunTables
		values(1,@tableId,@datestart,@dateend)

		set @position = @position +1
	end
	select * from Dogs
    select * from Dog_Shelter
    select * from Shelter_Contract
	set @testId =3
	set @position=3
	while @position!=0
	begin
		
		select @tableId=tt.TableID, @rows = tt.NoOfRows  from TestTables tt where @testId = tt.TestID and tt.Position = @position
		select @tableName = t.Name from Tables t where t.TableID = @tableId

		set @datestart = GETDATE()
		declare @commanddel varchar(100)
		set @commanddel = 'deleteFromTable '+ @tableName +','+ cast(@rows as varchar(5))
		exec (@commanddel)
		set @dateend = GETDATE()
        insert into TestRunTables
		values(3,@tableId,@datestart,@dateend)
		
		set @position = @position -1
	end
end

exec RunTableTests