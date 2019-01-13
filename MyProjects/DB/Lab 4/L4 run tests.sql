use L4;

go
create or alter procedure runTests
as
begin
	declare @datestarttest datetime
	declare @dateendtest datetime
	set @datestarttest = getdate()
	delete from TestRuns
	delete from TestRunTables
	delete from TestRunViews

	declare @testId int
	declare @tableId int
	declare @position int
	declare @noofrows int
	declare @tableName varchar(50)
	declare @datestart datetime
	declare @dateend datetime
	declare @testcount int
	declare @viewpos int
	declare @viewId int
	declare @viewName varchar(50)
	set @testcount=1
	set @position = 1
	set @testId = 1 
	set @viewpos=1
	insert into TestRuns
	values ('insert',null,null)
	while @position < 4
	begin
	--selectam nr de linii care trebuie sa il inseram si id-ul tabelului corespunzator pozitiei
		select @tableId=tt.TableID, @noofrows=tt.NoOfRows  from TestTables tt where tt.Position = @position and tt.TestID = @testId
		select @tableName=t.Name  from Tables t where @tableId = t.TableID
		--print convert(varchar(4),@tableId) + ' '+convert(varchar(4),@position)+' ' +@tableName
		
		print 'table name' + @tableName
		--setam data de inceput
		set @datestart = GETDATE()
		print 'start' + convert(varchar(100),@datestart)
		--formam comanda in functie de numele tabelei si o executam
		declare @command varchar(100)
		
		set @command = 'insert_table_'+ @tableName + ' ' + convert(varchar(4),@noofrows)
		exec (@command)
		--setam data de sfarsit
		print 'end' + convert(varchar(100),@dateend)
		set @dateend=GETDATE()
		--inseram in tabelele de test
		declare @description varchar(50)
		set @description = 'insert into'+@tableName
		--selectez ultimul id introdus in testrun pentru ca testrunid e setat identity
		select top 1 @testcount=tr.TestRunID from TestRuns tr order by tr.TestRunID desc
		insert into TestRunTables
		values(@testcount,@tableId,@datestart,@dateend)

		set @position = @position +1
	end

	set @testId =3
	while @viewpos <4
	begin
		select @viewId=tv.ViewID from TestViews tv where tv.TestID = @testId and tv.ViewID = @viewpos
		select @viewName=v.Name from Views v where v.ViewID = @viewId
		
		set @datestart=GETDATE()
		declare @commandview varchar(100)
		set @commandview = 'select * from ' + @viewName
		exec (@commandview)
		set @dateend = GETDATE()

		set @viewpos = @viewpos + 1
		set @description = 'view '+@viewName
		
		select top 1 @testcount=tr.TestRunID from TestRuns tr order by tr.TestRunID desc
		
		insert into TestRunViews
		values(@testcount,@viewId,@datestart,@dateend)
	end

	set @testId =2
	while @position >= 4 and @position < 7
	begin
		-- la fel ca la insert cautam tabelul pe care vrem sa operam
		select @tableId=tt.TableID, @noofrows = tt.NoOfRows  from TestTables tt where @testId = tt.TestID and tt.Position = @position
		select @tableName = t.Name from Tables t where t.TableID = @tableId

		set @datestart = GETDATE()
		declare @commanddel varchar(100)
		set @commanddel = 'delete_table_'+@tableName +' '+ convert(varchar(5),@noofrows)
		exec (@commanddel)
		set @dateend = GETDATE()

		declare @descriptiondel varchar(50)
		set @descriptiondel = 'delete from'+@tableName
		
		set @position = @position +1

	end

	set @dateendtest= getdate()

	update TestRuns
	set Description = 'test',StartAt = @datestarttest,EndAt = @dateendtest
end