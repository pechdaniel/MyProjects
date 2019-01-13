use L4;

go
create view view1
as
-- prints all the dogs that have a name that starts with 'R'
select * from Dogs D
where D.Dog_Name like 'R%'
go


create view view2
as
-- prints all the dogs that are adopted
select distinct D.Dog_Name as 'Dog Name'
from Dogs D
inner join Shelter_Contract S on (S.DID=D.DID)
go


create view view3
as
-- prints the shelters that gave to adoption
select distinct DS.DSID,DS.Shelter_Address
from Dog_Shelter DS
inner join (select D.DID from Dogs D inner join Shelter_Contract S on (S.DID=D.DID)) G on (G.DID=DS.DID)
group by DS.DSID,DS.Shelter_Address