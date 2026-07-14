CREATE DATABASE TEST;

USE  TEST;
CREATE TABLE TEST1(
	ISBN VARCHAR(10) PRIMARY KEY ,
	BName VARCHAR(20),
	Price INT,
	AUTHOR VARCHAR(30),
	ADOB DATE,
	Address VARCHAR(30)
);

INSERT INTO TEST1 VALUES('1-20-2131', 'Java', 250 , 'Anand', '2001-01-29', 'Kathmandu'),
						('1-69-2141', 'Python', 350 , 'Biplob', '2005-01-29', 'Balaju');
select * from TEST1;
 
EXEC sp_rename 'TEST1.BName' ,'Book_name','column';
EXEC sp_rename 'TEST1','TESTTGSDFG';