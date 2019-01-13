use L4;

go
create or alter procedure deleteFromTable
	@table varchar(50),
	@rows int
as
begin
	declare @id1 int
	declare @id2 int
	declare @id3 int
	declare @id4 int

	if( @table = 'Dogs' )
	begin
		while @rows > 0
		begin
			select top 1 @id1 = D.DID from Dogs D order by D.DID asc
			delete from Dogs
			where DID = @id1
			set @id1 = @id1 - 1
			set @rows = @rows - 1
		end
	end

	if( @table = 'Found' )
	begin
		while @rows > 0
		begin
			select top 1 @id2 = FID from Found order by FID asc
			delete from Found
			where FID = @id2
			set @rows = @rows - 1
		end
	end

	if( @table = 'Person' )
	begin
		while @rows > 0
		begin
			select top 1 @id4 = S.PID from Person S where S.PID = @id3 order by S.PID asc
			delete from Person
			where PID = @id4
			set @rows = @rows - 1
		end
	end
end

--execute deleteFromTable 'Dog_Shelter',2