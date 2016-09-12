------------------------------------------------------------
-- ������� 01
------------------------------------------------------------
CREATE PROCEDURE Query01
-- ��� ������� �������� ������� ����� � ����� ���������� �����������, ������������ ���� �������.
AS
BEGIN
	SELECT ProductID, COUNT(SupplierID) AS 'Number of Suppliers'
	FROM Shipments
	GROUP BY ProductID 
END;
GO
EXEC Query01;
GO
ALTER PROCEDURE Query02 @ProductID int
-- �������� ����� ����������� �������� ��� ������� ?.
AS
BEGIN
	SELECT s.SupplierName
	FROM Suppliers s JOIN Shipments t ON s.SupplierID = t.SupplierID
	WHERE t.ProductID = @ProductID
END;
GO
EXEC Query02 @ProductID = 881; 
GO
ALTER PROCEDURE Query03
-- ���������� ����������� (������ � �����), ������� ������ �� ����������.
AS
BEGIN
	SELECT s.SupplierID, s.SupplierName
	FROM Suppliers s 
	WHERE NOT EXISTS (SELECT * FROM Shipments t WHERE s.SupplierID = t.SupplierID)
END;
GO
EXEC Query03;
GO
ALTER PROCEDURE Query04  @Color nvarchar(10)
-- �������� ����� ����������� �� ������� ���� ������ �������� ����� ?.
AS
BEGIN
	SELECT DISTINCT s.SupplierName
	FROM Suppliers s JOIN Shipments t ON s.SupplierID = t.SupplierID JOIN 
		Products p ON t.ProductID = p.ProductID
	WHERE p.Color = @Color
END;
GO
EXEC Query04 'BLACK';
GO
ALTER PROCEDURE Query05
-- ����� ��� ������ (��������), ������������ ������������ � �������� ������ ��������.
AS
BEGIN
	SELECT DISTINCT p.ProductName
	FROM Products p JOIN Shipments t ON p.ProductID = t.ProductID JOIN
		Suppliers s ON t.SupplierID = s.SupplierID
	WHERE s.Status > (SELECT AVG(Status) FROM Suppliers)
END;
GO
EXEC Query05;
GO
------------------------------------------------------------
-- ������� 02
------------------------------------------------------------
CREATE PROCEDURE Query06 @City nvarchar(20)
-- ��������� ��������� ��������� ���� ���������, ������������ ������������ �� ������ ?.
AS
BEGIN
	SELECT SUM(p.Price*t.Qty) AS 'Total Summa'
	FROM Products p JOIN Shipments t ON p.ProductID = t.ProductID JOIN 
		Suppliers s ON t.SupplierID = s.SupplierID AND s.City = @City
END;
GO
EXEC Query06 @City = 'High Wycombe'
GO
ALTER PROCEDURE Query07
-- �������� ����� ����������� ���� ����� ���������.
AS
BEGIN
	SELECT s.SupplierName
	FROM Suppliers s
	WHERE NOT EXISTS (	SELECT *
						FROM Products p
						WHERE NOT EXISTS (	SELECT *
											FROM Shipments t
											WHERE t.ProductID = p.ProductID AND t.SupplierID = s.SupplierID))
END;
GO
EXEC Query07;
GO
ALTER PROCEDURE Query08 @ProductID int
-- �������� ����� �����������, ������� �� ���������� ������� � ������� ?.
AS
BEGIN
	SELECT DISTINCT s.SupplierName
	FROM Suppliers s
	WHERE NOT EXISTS (	SELECT * 
						FROM Shipments t
						WHERE t.SupplierID = s.SupplierID AND t.ProductID = @ProductID)
END;
GO
EXEC Query08 @ProductID = 881;
GO 
ALTER PROCEDURE Query09 @SupplierID int
-- �������� ����� ����������� �� ������� ���� ��� ����� ���������, ������� ���������� ��������� ��� ������� ?.
AS
BEGIN
	SELECT DISTINCT s.SupplierName
	FROM Suppliers s JOIN Shipments t ON s.SupplierID = t.SupplierID
	WHERE t.ProductID IN (SELECT ProductID FROM Shipments WHERE SupplierID = @SupplierID)
END;
GO
EXEC Query09 @SupplierID = 502
GO
CREATE PROCEDURE Query10 @City nvarchar(20)
-- ��������� ��������� ��������� ���� ������������ ���������, ����������� � ������ ?.
AS
BEGIN
	SELECT SUM(p.Price*t.Qty) AS 'Total Summa'
	FROM Products p JOIN Shipmets t ON p.ProductID = t.ProductID 
	WHERE p.City = @City
END;
GO
EXEC Query10 @City = 'Missoula'
GO
------------------------------------------------------------
-- ������� 03
------------------------------------------------------------
CREATE PROCEDURE Query11
-- �������� ��� ���� ���� �����������, ����������� � ����� ������.
AS
BEGIN
	SELECT first.SupplierName AS 'First Name', second.SupplierName AS 'Second Name'
	FROM Suppliers first, Suppliers second
	WHERE first.City = second.City AND first.SupplierID > second.SupplierID
END;
GO
EXEC Query11;
GO
CREATE PROCEDURE Query12
-- ���������� ����� ���������� �����������, ����������� � ���������.
AS
BEGIN
	SELECT COUNT(DISTINCT SupplierID) FROM Shipments
END;
GO
EXEC Query12;
GO
CREATE PROCEDURE Query13 @SupplierID int
-- ��������� ��������� ��������� ���� ���������, ������������ ����������� ��� ������� ?.
AS
BEGIN
	SELECT SUM(p.Price*t.Qty) AS 'Total Summa'
	FROM Products p JOIN Shipments t ON p.ProductID = t.ProductID
	WHERE t.SupplierID = @SupplierID
END;
GO
EXEC Query13 @SupplierID = 25;
GO
CREATE PROCEDURE Query14
-- ��� ������� ���������� ������� ����� � ����� ����� �������� � ������.
AS
BEGIN
	SELECT t.SupplierID, SUM(p.Price*t.Qty) AS 'Total Summa'
	FROM Products p JOIN Shipments t ON p.ProductID = t.ProductID
	GROUP BY t.SupplierID
END;
GO
EXEC Query14
GO
CREATE PROCEDURE Query15 @SupplierID int 
-- ���������� ����� ���������, ������������ ����������� ��� ������� ?.
AS
BEGIN
	SELECT p.Color
	FROM Products p JOIN Shipments t ON p.ProductID = t.ProductID
	WHERE t.SupplierID = @SupplierID
END;
GO
EXEC Query15 @SupplierID = 25;
GO
------------------------------------------------------------
-- ������� 04
------------------------------------------------------------
ALTER PROCEDURE Query16
-- ����� ���� �����������, ������������ ��������, ���� ������� ���������� �� ����� ��� �� 10% �� ������� ������� ���� ���������.
AS
BEGIN
	DECLARE @AvgPrice money
	SET @AvgPrice = (SELECT AVG(Price) FROM Products)
	SELECT @AvgPrice
	SELECT DISTINCT s.SupplierName
	FROM Suppliers s JOIN Shipments t ON s.SupplierID = t.SupplierID JOIN
	Products p ON t.ProductID = p.ProductID
	WHERE p.Price BETWEEN 0.9*@AvgPrice AND 1.1*@AvgPrice
END;
GO
EXEC Query16;
GO
ALTER PROCEDURE Query17
-- ������� ���������� ��� ���� ���������, �����, ��� ��������� � ������������ �� ������� ��������� � ����� ������.
AS
BEGIN
	SELECT t.SupplierID, t.ProductID
	FROM Shipments t JOIN Suppliers s ON t.SupplierID = s.SupplierID JOIN
		Products p ON t.ProductID = p.ProductID
	WHERE s.City = p.City
END;
GO
EXEC Query17;
GO
ALTER PROCEDURE Query18
-- ������� ������ ���������, ������������ ����� ��� ����� �����������
-- �������� ��� ���� ������ ���������� � ����� ��������, ������ ������ �����, � ������� ������ ��������� �� ���������� ������ �������.
AS
BEGIN
	SELECT t.ProductID
	FROM Shipments t
	GROUP BY t.ProductID
	HAVING COUNT (t.SupplierID) > 1;
--	SELECT s.SupplierID, p.ProductID
--	FROM Suppliers s CROSS JOIN Products p
--	EXCEPT
--	SELECT t.SupplierID, t.ProductID
--	FROM Shipments t
END
GO
EXEC Query18;
GO
ALTER PROCEDURE Query19
-- ������� ����� �����������, ������ ������� ������ �������� �������� ������� � ������� �����������.
AS
BEGIN
	SELECT s.SupplierName, s.Status
	FROM Suppliers s
	WHERE s.Status < (SELECT AVG(Status) FROM Suppliers)
END;
GO
EXEC Query19;
GO
CREATE PROCEDURE Query20 @ProductID int
-- ���������� � ��������� ������������ � ����������� ���������� ��������� � ������� ?.
AS
BEGIN
	SELECT MAX(t.Qty) AS 'MaxQ', MIN(t.Qty) AS 'MinQ'
	FROM Shipments t
	WHERE t.ProductID = @ProductID
END;
GO
EXEC Query20 @ProductID = 881;
GO
------------------------------------------------------------
-- ������� 05
------------------------------------------------------------
ALTER PROCEDURE Query21 @SupplierID int, @ProductID int
-- ���������� ����� ���������� ��������� � ������� ?, ������������ ����������� ��� ������� ?.
AS
BEGIN
	SELECT COUNT(ProductID)
	FROM Shipments 
	WHERE SupplierID = @SupplierID AND ProductID = @ProductID 
END;
GO
EXEC Query21 @SupplierID = 448, @ProductID = 900;
GO
CREATE PROCEDURE Query22 @City nvarchar(20), @Status int
-- ���������� ����� ����������� �� ������ ? �� �������� ������ ?.
AS
BEGIN
	SELECT SupplierName
	FROM Suppliers 
	WHERE City = @City AND Status > @Status 
END;
GO
EXEC Query22 @City = 'Edmonton',  @Status = 50;
GO
ALTER PROCEDURE Query23
AS
-- ����� ���� �����������, ������������ ������� ��������. ���� ����� ��������� ���������� �� ���� ������ �������� �������� �� ����� ��� � 4 ����.
BEGIN
	SELECT DISTINCT s.SupplierName
	FROM Suppliers s JOIN Shipments t ON s.SupplierID = t.SupplierID JOIN
		Products p ON t.ProductID = p.ProductID  
	WHERE p.Price >= (SELECT MAX(Price) FROM Products)/4
END;
GO
EXEC Query23;
GO
CREATE PROCEDURE Query24 @Weight decimal(10,2)
AS
-- ���������� ������ � ��� ���� ����� ���������, ��� ������� ��������� ?.
BEGIN
	SELECT ProductID, Weight
	FROM Products
	WHERE Weight >  @Weight
END;
GO
EXEC Query24 @Weight = 10000.00;
GO
ALTER PROCEDURE Query25
AS
-- ��� ������� �������� ������� ����� � ����� ����� �������� � ������.
BEGIN
	SELECT ProductID, SUM(Qty) AS 'Total Number'
	FROM Shipments
	GROUP BY ProductID
END;
GO
EXEC Query25;
GO
------------------------------------------------------------
-- ������� 06
------------------------------------------------------------
CREATE PROCEDURE Query26
-- ������� �������� ���������, ���� ������� ������ ������� ������� ���� � ������� ���������.
AS
BEGIN
	SELECT ProductName
	FROM Products
	WHERE Price > (SELECT AVG(Price) FROM Products)
END;
GO
EXEC Query26; 
GO
CREATE PROCEDURE Query27
-- ���������� ����� ���������� ������������ ���������.
AS
BEGIN
	SELECT COUNT(DISTINCT ProductID) AS 'Total Number'
	FROM Shipments
END;
GO
EXEC Query27; 
GO
ALTER PROCEDURE Query28 @MinPrice money, @MaxPrice money
-- ����� ���� �����������, ������������ ��������, ����������� � ������� ��������� �� ? �� ? ������������.
AS
BEGIN
	SELECT DISTINCT s.SupplierName
	FROM Suppliers s JOIN Shipments t ON s.SupplierID = t.SupplierID JOIN
		Products p ON t.ProductID = p.ProductID
	WHERE p.Price BETWEEN @MinPrice AND @MaxPrice
END;
GO
EXEC Query28 @MinPrice = 500.00, @MaxPrice = 1000.00;
GO
CREATE PROCEDURE Query29
-- ���������� ��������, ������� ����� �� ������������.
AS
BEGIN
	SELECT p.ProductID, p.ProductName
	FROM Products p
	WHERE NOT EXISTS (SELECT * FROM Shipments t WHERE t.ProductID = p.ProductID)
END;
GO
EXEC Query29; 
GO
CREATE PROCEDURE Query30
-- ����� ��� ���� �������� �������, �����, ��� ��������� �� ������� ������ ���������� �������, ����������� � ������ ������.
AS
BEGIN
	SELECT DISTINCT s.City AS 'First City', p.City AS 'Second City'
	FROM Suppliers s JOIN Shipments t ON s.SupplierID = t.SupplierID JOIN
		Products p ON t.ProductID = p.ProductID
END;
GO
EXEC Query30; 
GO



							



