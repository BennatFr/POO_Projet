CREATE TABLE People(
   ID_People INT IDENTITY(1, 1),
   last_Name VARCHAR(50) NOT NULL,
   first_Name VARCHAR(50) NOT NULL,
   PRIMARY KEY(ID_People)
);

CREATE TABLE Country(
   ID_Country INT IDENTITY(1, 1),
   name VARCHAR(56) NOT NULL,
   PRIMARY KEY(ID_Country)
);

CREATE TABLE City(
   ID_City INT IDENTITY(1, 1),
   name VARCHAR(35) NOT NULL,
   postal_Number VARCHAR(10) NOT NULL,
   PRIMARY KEY(ID_City)
);

CREATE TABLE Methode_Payment(
   ID_Payment_Methode INT IDENTITY(1, 1),
   type VARCHAR(2),
   PRIMARY KEY(ID_Payment_Methode)
);

CREATE TABLE Type(
   ID_Type INT IDENTITY(1, 1),
   name VARCHAR(50) NOT NULL,
   PRIMARY KEY(ID_Type)
);

CREATE TABLE Bill(
   ID_Bill INT IDENTITY(1, 1),
   ID_Client INT NOT NULL,
   client_Last_Name VARCHAR(50) NOT NULL,
   client_First_Name VARCHAR(50) NOT NULL,
   bill_Date DATETIME NOT NULL,
   personnel_Fisrt_Name VARCHAR(50) NOT NULL,
   personnel_Last_Name VARCHAR(50) NOT NULL,
   PRIMARY KEY(ID_Bill)
);

CREATE TABLE Bill_Item(
   ID_Item INT IDENTITY(1, 1),
   reference VARCHAR(10) NOT NULL,
   name VARCHAR(50) NOT NULL,
   type VARCHAR(50) NOT NULL,
   PRIMARY KEY(ID_Item)
);

CREATE TABLE Client(
   ID_Client INT IDENTITY(1, 1),
   birthdate DATE NOT NULL,
   first_Buy_Website DATE NOT NULL,
   ID_People INT NOT NULL,
   PRIMARY KEY(ID_Client),
   FOREIGN KEY(ID_People) REFERENCES People(ID_People)
);

CREATE TABLE Command(
   ID_Command INT IDENTITY(1, 1),
   reference VARCHAR(20) NOT NULL,
   date_Estimation DATETIME,
   date_Issue DATE NOT NULL,
   settlement_Balance DATE,
   ID_Client INT NOT NULL,
   PRIMARY KEY(ID_Command),
   FOREIGN KEY(ID_Client) REFERENCES Client(ID_Client)
);

CREATE TABLE Payment(
   ID_Payment INT IDENTITY(1, 1),
   payment_Date DATETIME,
   ID_Payment_Methode INT NOT NULL,
   ID_Command INT NOT NULL,
   PRIMARY KEY(ID_Payment),
   FOREIGN KEY(ID_Payment_Methode) REFERENCES Methode_Payment(ID_Payment_Methode),
   FOREIGN KEY(ID_Command) REFERENCES Command(ID_Command)
);

CREATE TABLE Item(
   ID_Item INT IDENTITY(1, 1),
   reference VARCHAR(10) NOT NULL,
   name VARCHAR(50) NOT NULL,
   replenishment DECIMAL(13,3),
   stock DECIMAL(13,3) NOT NULL,
   ID_Type INT NOT NULL,
   PRIMARY KEY(ID_Item),
   FOREIGN KEY(ID_Type) REFERENCES Type(ID_Type)
);

CREATE TABLE Address(
   ID_Address INT IDENTITY(1, 1),
   street_Number INT NOT NULL,
   street VARCHAR(95) NOT NULL,
   additionnal_Data VARCHAR(50),
   ID_City INT NOT NULL,
   ID_Country INT NOT NULL,
   PRIMARY KEY(ID_Address),
   FOREIGN KEY(ID_City) REFERENCES City(ID_City),
   FOREIGN KEY(ID_Country) REFERENCES Country(ID_Country)
);

CREATE TABLE Price(
   ID_Price INT IDENTITY(1, 1),
   price DECIMAL(15,2) NOT NULL,
   VAT DECIMAL(4,3) NOT NULL,
   date_Price DATETIME NOT NULL,
   ID_Item INT NOT NULL,
   PRIMARY KEY(ID_Price),
   FOREIGN KEY(ID_Item) REFERENCES Item(ID_Item)
);

CREATE TABLE Personnel(
   ID_Personnel INT IDENTITY(1, 1),
   hire_Date DATE NOT NULL,
   ID_Address INT NOT NULL,
   ID_Personnel_1 INT NOT NULL,
   ID_People INT NOT NULL,
   PRIMARY KEY(ID_Personnel),
   FOREIGN KEY(ID_Address) REFERENCES Address(ID_Address),
   FOREIGN KEY(ID_Personnel_1) REFERENCES Personnel(ID_Personnel),
   FOREIGN KEY(ID_People) REFERENCES People(ID_People)
);

CREATE TABLE Command_Contain(
   ID_Command INT,
   ID_Item INT,
   quantity DECIMAL(13,3) NOT NULL,
   discount DECIMAL(5,2),
   PRIMARY KEY(ID_Command, ID_Item),
   FOREIGN KEY(ID_Command) REFERENCES Command(ID_Command),
   FOREIGN KEY(ID_Item) REFERENCES Item(ID_Item)
);

CREATE TABLE Get_Client_Address(
   ID_Client INT,
   ID_Address INT,
   is_Billing BIT NOT NULL,
   PRIMARY KEY(ID_Client, ID_Address),
   FOREIGN KEY(ID_Client) REFERENCES Client(ID_Client),
   FOREIGN KEY(ID_Address) REFERENCES Address(ID_Address)
);

CREATE TABLE Bill_Contain(
   ID_Bill INT,
   ID_Item INT,
   price DECIMAL(15,2) NOT NULL,
   quantity DECIMAL(13,3) NOT NULL,
   VAT DECIMAL(4,3) NOT NULL,
   discount DECIMAL(4,3),
   PRIMARY KEY(ID_Bill, ID_Item),
   FOREIGN KEY(ID_Bill) REFERENCES Bill(ID_Bill),
   FOREIGN KEY(ID_Item) REFERENCES Bill_Item(ID_Item)
);
