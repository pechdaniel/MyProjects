use Lab1bun;

delete from Parking_Place
delete from Manager
delete from Employees
delete from Shops_Customers
delete from Customers
delete from Shops
delete from Mall
delete from Helicopter_Pad
delete from Floors
delete from Bathrooms

insert into Helicopter_Pad values('HP3',35)
insert into Helicopter_Pad values('HP5',32)
insert into Mall values('Ma5','Ionci Mall','Satucul Mic street',50,'HP5')
insert into Bathrooms values('B2',10)
insert into Bathrooms values('B4',null)

update Helicopter_Pad
set Altitude=30
where Altitude>34

update Mall
set Shop_count=47
where MaID='Ma5'

update Bathrooms
set Nr_Toilets=20
where BID='B4'

delete from Mall where MaID='Ma5'
delete from Bathrooms where BID='B2'

delete from Parking_Place
delete from Manager
delete from Employees
delete from Shops_Customers
delete from Customers
delete from Shops
delete from Mall
delete from Helicopter_Pad
delete from Floors
delete from Bathrooms

insert into Helicopter_Pad values('HP1',10)
insert into Helicopter_Pad values('HP1',10)
insert into Helicopter_Pad values('HP2',null)
insert into Helicopter_Pad values('HP3',35)
insert into Helicopter_Pad values('HP4',49)
insert into Helicopter_Pad values('HP5',32)
insert into Helicopter_Pad values('HP6',50)

insert into Mall values('Ma1','Iulus Mall','Iulius street',70,'HP1')
insert into Mall values('Ma2','Polus Mall','Gradinarilor street',150,'HP2')
insert into Mall values('Ma3','Gold Plaza','b-dul Bucuresti',80,'HP3')
insert into Mall values('Ma4','City Mall','Mamaia street',200,'HP4')
insert into Mall values('Ma5','Ionci Mall','Satucul Mic street',50,'HP5')
insert into Mall values('Ma6','RoMall','Sesamy street',190,'HP6')
insert into Mall values('Ma7','Ricola Mall','Urubentilor street',70,'HP6')

insert into Bathrooms values('B1',7)
insert into Bathrooms values('B2',10)
insert into Bathrooms values('B3',2)
insert into Bathrooms values('B4',null)
insert into Bathrooms values('B5',17)

insert into Floors values('F1',37,'B1')
insert into Floors values('F2',70,'B2')
insert into Floors values('F3',59,'B3')
insert into Floors values('F4',39,'B4')
insert into Floors values('F5',40,'B5')

insert into Shops values('Sh1','Armani','Clothing','F1','Ma1')
insert into Shops values('Sh2','H&M','Clothing','F2','Ma1')
insert into Shops values('Sh3','NewYorker','Clothing','F1','Ma1')
insert into Shops values('Sh4','Subway','FastFood','F1','Ma2')
insert into Shops values('Sh5','KFC','FastFood','F3','Ma2')
insert into Shops values('Sh6','Amanet','Exchange','F2','Ma3')

insert into Customers values('C1','Vladov',200)
insert into Customers values('C2','Vladimir',270)
insert into Customers values('C3','Vladovik',480)
insert into Customers values('C4','Vlad',370)
insert into Customers values('C5','Klaus',209)
insert into Customers values('C6','Omi',500)
insert into Customers values('C7','Iulian Mures',189)
insert into Customers values('C8','Marian Goga',900)

insert into Shops_Customers values('Sh1','C1',20)
insert into Shops_Customers values('Sh1','C2',19)
insert into Shops_Customers values('Sh1','C3',23)
insert into Shops_Customers values('Sh2','C4',21)
insert into Shops_Customers values('Sh4','C5',40)
insert into Shops_Customers values('Sh4','C6',28)
insert into Shops_Customers values('Sh3','C7',30)
insert into Shops_Customers values('Sh2','C8',20)

insert into Manager values('M1','Maria',28,2,'Ma3')
insert into Manager values('M3','Julian',32,4,'Ma2')
insert into Manager values('M2','Klaus',26,1,'Ma4')
insert into Manager values('M4','Irinel',27,0,'Ma3')

insert into Employees values('E1','Marian Goga',2998,'Sh3')
insert into Employees values('E2','Irinescu Ioan',3484,'Sh2')
insert into Employees values('E3','Iulian Mures',7284,'Sh2')
insert into Employees values('E4','Junike Lucian',2642,'Sh3')
insert into Employees values('E5','Oriandru Kuronda',3614,'Sh1')

insert into Parking_Place values('PP1','Amsterdam street','Ma2')
insert into Parking_Place values('PP2','Logika street','Ma3')
insert into Parking_Place values('PP3','Bucuresti street','Ma1')
insert into Parking_Place values('PP4','Iubireni street','Ma3')
insert into Parking_Place values('PP5','Lucescu street','Ma4')

--a)___________________________________________________________________

-- prints the name of the customers and the name of the shops
select Customer_Name from Customers
union all
select Shop_Name from Shops

-- prints the name of the customers that ends with r or starts with Vlad
select Customer_Name from Customers
where Customer_Name like '%r' or Customer_Name like 'Vlad%'


--b)____________________________________________________________________

-- prints the employee names that are the same as the custommers names

select Customer_Name from Customers
intersect
select Employee_Name from Employees
select *
from Employees
select *
from Customers
-- prints the malls having 70, 50 or 80 shops

select Mall_Name,Shop_count from Mall
where Shop_count in (50,70,80)


--c)____________________________________________________________________

-- prints the mall shops are different than 70, 50 and 80

select Mall_Name, Shop_Count from Mall
where Shop_count not in (50,70,80)

-- prints the names of employees that are not customers

select Employee_Name from Employees
except
select Customer_Name from Customers


--d)_____________________________________________________________________

-- prints the shops that are the same for the employees and the customers

select distinct S.Shop_Name,S.ShID
from ((Shops S
inner join Employees E on E.ShID=S.ShID)
inner join Shops_Customers SC on SC.ShID=S.ShID)

-- prints all the shops and any employees they might have 

select distinct S.Shop_Name,E.Employee_Name
from Shops S
left outer join Employees e on S.ShID=E.ShID

-- prints the first 5 employees that might work where customers go
-- in decreasing order

select top 5 S.ShID, E.Employee_Name
from Shops_Customers S
right outer join Employees E on E.ShID=S.ShID
order by ShID desc

-- prints all floors with bathrooms in decreasing order
-- by the FID

select F.FID,B.BID
from Floors F
full outer join Bathrooms B on B.BID=F.BID
order by F.FID desc

--e)_________________________________________________________________

-- prints the first two shopIDs from Shops that had custommers 
-- with a budget above 300

select ShID
from Shops
where ShID in (select ShID
		from Shops_Customers S
		where S.CID in(select C.CID
				from Customers C
				where C.Budget>300))
select *
from Customers
select *
from Shops_Customers

-- for every mall, prints the helicopter pad that has an altitude
-- between 32 and 50
-- ordered deacrisingly by MaID

select MaID
from Mall M
where M.HPID in(select HPID
				from Helicopter_Pad
				where Altitude>32 and Altitude<50)
order by MaID desc
select *
from Helicopter_Pad

--f)_____________________________________________________________________

-- prints the name of the mall which has a manager older than 27

select Mall_Name,MaID
from Mall
where exists(select MID
			from Manager
			where Manager.MaID=Mall.MaID and Age>27)
select *
from Manager
-- prints the floors that have bathrooms with the number of toilets smaller
-- than 10

select FID
from Floors
where exists (select BID
			from Bathrooms
			where Bathrooms.BID=Floors.BID and Nr_Toilets<10)
select *
from Bathrooms
select *
from Floors
--g)____________________________________________________________________

-- prints the shopID from Shops_Customers for a customer 
-- that is older than 29

select distinct H.ShID
from(select *
	from Shops_Customers
	where Shops_Customers.Age>29) H

-- prints the shopID from Shops that have employees with salary more than
-- 3000

select distinct H.ShID
from(select *
	from Employees
	where Salary>3000) H
select *
from Employees

--h)___________________________________________________________________

-- prints the shops that had at least 2 customers

select S.ShID,S.Shop_Name
from Shops S
inner join Shops_Customers SC on S.ShID=SC.ShID
group by S.ShID,S.Shop_Name
having count(*)>1
-- prints the average budget of every customer older than 20

select AVG(C.Budget) as 'Average salary'
from Customers C
where C.Budget in (select H.Budget
					from Customers H
					where H.CID in
					(select CID
					from Shops_Customers
					where Age>29))

-- prints the total number of toilets on a floor 
-- with an area greater than 20

select SUM(Nr_Toilets) as 'Total toilets'
from Bathrooms
where BID in (select F.BID
				from Floors F
				where F.Area>20)

-- prints the minimum budget of any customer older than 30

select MIN(C.Budget) as 'Minimum salary'
from Customers C
where C.Budget in (select H.Budget
					from Customers H
					where H.CID in
					(select CID
					from Shops_Customers
					where Age>30))


--i)___________________________________________________________________

-- prints the mall with it's address of some malls with Helli pad at 
-- at an altitude over 40

select concat(M.Mall_Name,' on ',M.Mall_Address) as 'Location'
from Mall M
where M.HPID = any(select H.HPID
					from Helicopter_Pad H
					where H.HPID=M.HPID and H.Altitude>40)

-- prints the mall with it's address of all malls with Helli pad at 
-- at an altitude over 30

select concat(M.Mall_Name,' on ',M.Mall_Address) as 'Location'
from Mall M
where M.HPID = all(select H.HPID
					from Helicopter_Pad H
					where H.HPID=M.HPID and H.Altitude>30)

-- prints all from shops_custoomers, for a custommer with the name that
-- starts with V

select *
from Shops_Customers SC
where SC.Age=any(select Age
				from Shops_Customers
				where CID in(select H.CID
							from Customers H
							where H.Customer_Name like 'V%'))

-- prints all from shops_custoomers, for a custommer with the name that
-- does not start with V

select *
from Shops_Customers SC
where SC.Age=any(select Age
				from Shops_Customers
				where CID not in(select H.CID
							from Customers H
							where H.Customer_Name like 'V%'))