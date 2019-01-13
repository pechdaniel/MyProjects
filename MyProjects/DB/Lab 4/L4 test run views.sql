use L4;

go
create or alter procedure RunViewTests
as
begin
	declare @viewName1 varchar(50)
	select @viewName1 = Name
	from Views
	where ViewID = 1

	declare @s varchar(50)
	set @s = 'Select * from ' + @viewName1

	declare @ds1 datetime
	declare @de1 datetime
	set @ds1 = GETDATE()
	exec (@s)
	set @de1 = GETDATE()
	insert into TestRunViews(TestRunID, ViewID, StartAT, EndAt) values (2, 1, @ds1, @de1)
	
	declare @viewName2 varchar(50)
	select @viewName2 = Name
	from Views
	where ViewID = 2

	declare @s2 varchar(50)
	set @s2 = 'Select * from ' + @viewName2

	declare @ds2 datetime
	declare @de2 datetime
	set @ds2 = GETDATE()
	exec (@s2)
	set @de2 = GETDATE()
	insert into TestRunViews(TestRunID, ViewID, StartAT, EndAt) values (2, 2, @ds2, @de2)
	
	declare @viewName3 varchar(50)
	select @viewName3 = Name
	from Views
	where ViewID = 3

	declare @s3 varchar(50)
	set @s3 = 'Select * from ' + @viewName3

	declare @ds3 datetime
	declare @de3 datetime
	set @ds3 = GETDATE()
	exec (@s3)
	set @de3 = GETDATE()
	insert into TestRunViews(TestRunID, ViewID, StartAT, EndAt) values (2, 3, @ds3, @de3)
end