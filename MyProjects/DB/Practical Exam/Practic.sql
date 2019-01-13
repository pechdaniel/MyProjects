use Practic;

--    1
create table Customers(
CID int primary key identity,
C_Name varchar(50),
DOB date
);

create table Cards(
C_NR int primary key,
CVV int
);

create table Bank_Acc(
BAID int primary key identity(1,1),
IBAN int,
Current_Bal float,
C_NR int foreign key references Cards(C_NR)
);

create table C_B(
CID int foreign key references Customers(CID),
BAID int foreign key references Bank_Acc(BAID),
constraint PK_CBAkeys primary key(CID,BAID)
);

create table ATM(
AID int primary key identity,
Address varchar(50)
);

create table Tranzaction(
TID int primary key,
Ammount float,
W_Time datetime,
AID int foreign key references ATM(AID),
C_NR int foreign key references Cards(C_NR)
);

--   2
go
create or alter procedure One
	@card int not null
as
begin
	delete from Tranzaction
	where C_NR=@card
end
go

--   3
go
create or alter view Two
as
select distinct C.C_NR as 'Card Number',T.AID as 'ATM' from Cards C
inner join Tranzaction T on C.C_NR=T.C_NR
go

--   4
go
create or alter view Aux
as
select * from Cards
go

go
create or alter procedure Three
as
begin
	 declare @card int
	 declare @nr int
	 declare @sum float

	 select @nr=count(C_NR) from Cards

	 while @nr>0
	 begin
			select top 1 @card=C_NR from Aux

			select @sum=sum(Ammount) from Tranzaction where C_NR=@card

			if (@sum>2000)
			begin
					print @sum+' '
			end

			delete from Aux where C_NR=@card
			set @nr=@nr-1
	 end
end


exec Three