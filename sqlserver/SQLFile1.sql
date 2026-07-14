-- Lab 1 : Use of single table

CREATE DATABASE Publication;

USE  Publication;

CREATE TABLE Books(
	ISBN VARCHAR(10) PRIMARY KEY ,
	BName VARCHAR(20),
	Price INT,
	AUTHOR VARCHAR(30),
	ADOB DATE,
	Address VARCHAR(30)
);

INSERT INTO Books VALUES('1-20-2131', 'Java', 250 , 'Anand', '2001-01-29', 'Kathmandu'),
						('1-69-2141', 'Python', 350 , 'Biplob', '2005-01-29', 'Balaju');
select * from books;

select BName, AUTHOR from Books
;
ALTER TABLE Books
ADD Email VARCHAR(20);
ALTER TABLE Books
DROP COLUMN Address;