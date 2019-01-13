use L4;

go
create or alter procedure insertIntoTable
	@table varchar(50),
	@rows int
as
begin
	declare @id1 int
	declare @id2 int
	declare @id3 int
	declare @id4 int
	declare @myname varchar(50)
	declare @id5 int
	declare @date date

	if( @table = 'Dogs' )
	begin
		select top 1 @id1 = DID from Dogs order by DID desc
		while @rows > 0
		begin
			set @myname = 'Dog' + cast(@id1 as varchar(5))
			set @id1 = @id1 + 1
			insert into Dogs
			values (@id1, @myname, @id1)
			set @rows = @rows - 1
		end
	end

	if( @table = 'Found' )
	begin
		select top 1 @id2 = FID from Found order by FID desc
		while @rows > 0
		begin
			set @date = getdate()
			set @myname = 'Address nr ' + cast(@id2 as varchar(50))
			set @id2 = @id2 + 1
			insert into Found
			values (@id2, @myname, @date)
			set @rows = @rows - 1
		end
	end

	if( @table = 'Person' )
	begin
		select top 1 @id3 = S.PID from Person S order by S.PID desc
		while @rows > 0
		begin
			set @id3 = @id3 + 1
			set @myname = 'Person' + cast(@id3 as varchar(50))
			insert into Person
			values (@id3, @myname)
			set @rows = @rows - 1
		end
	end
end

exec insertIntoTable 'Dog_Shelter',2