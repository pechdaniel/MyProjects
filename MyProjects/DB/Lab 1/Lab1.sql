use Lab1bun;
CREATE TABLE Helicopter_Pad(
HPID CHAR(20) NOT NULL,
Altitude INT,
PRIMARY KEY(HPID)
);

CREATE TABLE Mall(
MaID CHAR(20) NOT NULL,
Mall_Name VARCHAR(20),
Mall_Address CHAR(20),
Shop_count INT,
HPID CHAR(20) NOT NULL,
PRIMARY KEY(MaID),
FOREIGN KEY(HPID) REFERENCES Helicopter_Pad(HPID),
);

create table Agency(
AID CHAR(20) not null,
Agency_Name VARCHAR(20),
Employee_Count int,
Primary key(AID)
);

create table Agency_Mall(
MaID CHAR(20),
AID char(20),
Primary key(MaID,AID),
Foreign key(MaID) references Mall(MaID),
foreign key(AID) references Agency(AID)
);

CREATE TABLE Bathrooms(
BID CHAR(20) NOT NULL,
Nr_Toilets INT,
PRIMARY KEY(BID)
);

CREATE TABLE Floors(
FID CHAR(20) NOT NULL,
Area INT,
BID CHAR(20) NOT NULL,
PRIMARY KEY(FID),
FOREIGN KEY(BID) REFERENCES Bathrooms(BID)
);

CREATE TABLE Shops(
ShID CHAR(20) NOT NULL,
Shop_Name VARCHAR(20),
Shop_Type VARCHAR(20),
FID CHAR(20) NOT NULL,
MaID CHAR(20) NOT NULL,
PRIMARY KEY(ShID),
FOREIGN KEY(FID) REFERENCES Floors(FID),
FOREIGN KEY(MaID) REFERENCES Mall(MaID)
);

CREATE TABLE Customers(
CID CHAR(20) NOT NULL,
Customer_Name VARCHAR(20),
Budget INT,
PRIMARY KEY(CID)
);

CREATE TABLE Shops_Customers(
ShID CHAR(20) NOT NULL,
CID CHAR(20) NOT NULL,
Age INT,
PRIMARY KEY(ShID,CID),
FOREIGN KEY(ShID) REFERENCES Shops(ShID),
FOREIGN KEY(CID) REFERENCES Customers(CID)
);

CREATE TABLE Manager(
MID CHAR(20) NOT NULL,
Manager_Name VARCHAR(20),
Age INT,
Experience INT,
MaID CHAR(20) NOT NULL,
PRIMARY KEY(MID),
FOREIGN KEY(MaID) REFERENCES Mall(MaID)
);

CREATE TABLE Employees(
EID CHAR(20) NOT NULL,
Employee_Name VARCHAR(20),
Salary INT,
ShID CHAR(20) NOT NULL,
PRIMARY KEY(EID),
FOREIGN KEY(ShID) REFERENCES Shops(ShID)
);

CREATE TABLE Parking_Place(
PPID CHAR(20) NOT NULL,
Parking_Location CHAR(20),
MaID CHAR(20) NOT NULL,
PRIMARY KEY(PPID),
FOREIGN KEY(MaID) REFERENCES Mall(MaID)
);