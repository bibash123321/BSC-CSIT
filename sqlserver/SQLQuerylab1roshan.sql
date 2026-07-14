
CREATE DATABASE Lab1;
USE Lab1;

-- Create the Student table
CREATE TABLE Student (
    StudentID INT PRIMARY KEY,
    SName VARCHAR(50),
    Gender CHAR(1), -- M/F/O
    Age INT,
    Class VARCHAR(20),
    Marks INT,
    Email VARCHAR(100),
    Address VARCHAR(255)
);

INSERT INTO Student VALUES
(1, 'Rahul', 'M', 18, '12A', 88, 'rahul@gmail.com', 'Kathmandu'),
(2, 'Anita', 'F', 19, '12B', 92, 'anita@yahoo.com', 'Lalitpur'),
(3, 'Suresh', 'M', 20, '11A', 75, 'suresh@hotmail.com', 'Bhaktapur'),
(4, 'Reema', 'F', 17, '12A', 85, 'reema@gmail.com', 'Kathmandu'),
(5, 'Bikash', 'M', 18, '12B', 90, 'bikash@gmail.com', 'Lalitpur'),
(6, 'Niraj', 'M', 19, '11B', 80, 'niraj@ymail.com', 'Pokhara'),
(7, 'Anju', 'F', 17, '11A', 95, 'anju@yahoo.com', 'Biratnagar'),
(8, 'Rekha', 'F', 18, '12C', 82, NULL, 'Kathmandu'),
(9, 'Manoj', 'M', 21, '12C', 67, 'manoj@outlook.com', 'Dharan'),
(10, 'Kiran', 'M', 18, '11B', 78, 'kiran@gmail.com', 'Pokhara'),
(11, 'Rina', 'F', 19, '11A', 91, 'rina@gmail.com', 'Kathmandu'),
(12, 'Gita', 'F', 20, '12A', 79, NULL, NULL),
(13, 'Raju', 'M', 18, '11C', 87, 'raju@yahoo.com', 'Birgunj'),
(14, 'Sarita', 'F', 17, '11C', 94, 'sarita@yahoo.com', 'Biratnagar'),
(15, 'Rekha', 'F', 19, '12B', 83, 'rekha@gmail.com', 'Kathmandu');

select *
from student;

SELECT SName, Email, Marks FROM Student;

SELECT * FROM Student
WHERE Address LIKE '%Kathmandu%';

SELECT * FROM Student
WHERE Address LIKE '%Kathmandu%';

SELECT * FROM Student
WHERE Email LIKE '%@gmail.com';

UPDATE Student
SET Address = 'Butwal'
WHERE StudentID = 3;

SELECT * FROM Student
WHERE Marks > 80 AND Age < 20;

SELECT COUNT(*) AS Yahoo_Count
FROM Student
WHERE Email LIKE '%@yahoo.com';

SELECT * FROM Student
WHERE Email IS NULL;

SELECT * FROM Student
ORDER BY SName ASC;

SELECT Class, MAX(Marks) AS Max_Marks
FROM Student
GROUP BY Class;

DELETE FROM Student
WHERE Address IS NULL OR Address = '';

ALTER TABLE Student
ADD PhoneNumber VARCHAR(15);

CREATE VIEW ContactList AS
SELECT SName, Email, PhoneNumber FROM Student;

SELECT * FROM Student
WHERE SName LIKE 'R%a';

SELECT Address, COUNT(*) AS Num_Students
FROM Student
GROUP BY Address;

SELECT Gender, COUNT(*) AS Count
FROM Student
GROUP BY Gender;

DELIMITER $$
CREATE TRIGGER PreventEmailUpdate
BEFORE UPDATE ON Student
FOR EACH ROW
BEGIN
  IF NEW.Email IS NOT NULL AND OLD.Email IS NOT NULL AND NEW.Email <> OLD.Email THEN
    SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Email updates are not allowed once entered.';
  END IF;
END$$
DELIMITER ;

SELECT * FROM Student S1
WHERE EXISTS (
  SELECT 1 FROM Student S2
  WHERE S1.Address = S2.Address AND S1.SName <> S2.SName
);

EXEC sp_rename 'Student.Marks', 'TotalMarks', 'COLUMN';







