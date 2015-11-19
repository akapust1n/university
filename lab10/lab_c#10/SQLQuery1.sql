------------------------------------------------------------
-- ВАРИАНТ 01
------------------------------------------------------------
CREATE PROCEDURE Query01
-- Для каждого продукта указать номер и общее количество поставщиков, поставляющих этот продукт.
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
-- Получить имена поставщиков продукта под номером ?.
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
-- Определить поставщиков (номера и имена), которые ничего не поставляют.
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
-- Получить имена поставщиков по крайней мере одного продукта цвета ?.
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
-- Найти все товары (названия), поставляемые поставщиками с статусом болеше среднего.
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
-- ВАРИАНТ 02
------------------------------------------------------------
CREATE PROCEDURE Query06 @City nvarchar(20)
-- Вычислить суммарную стоимость всех продуктов, поставляемых поставщиками из города ?.
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
-- Получить имена поставщиков всех типов продуктов.
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
-- Получить имена поставщиков, которые не поставляют продукт с номером ?.
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
-- Получить имена поставщиков по крайней мере тех типов продуктов, которые поставляет поставщик под номером ?.
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
-- Вычислить суммарную стоимость всех поставляемых продуктов, находящихся в городе ?.
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
-- ВАРИАНТ 03
------------------------------------------------------------
CREATE PROCEDURE Query11
-- Получить все пары имен поставщиков, находящихся в одном городе.
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
-- Определить общее количество поставщиков, участвующих в поставках.
AS
BEGIN
	SELECT COUNT(DISTINCT SupplierID) FROM Shipments
END;
GO
EXEC Query12;
GO
CREATE PROCEDURE Query13 @SupplierID int
-- Вычислить суммарную стоимость всех продуктов, поставляемых поставщиком под номером ?.
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
-- Для каждого поставщика указать номер и общий объем поставки в штуках.
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
-- Определить цвета продуктов, поставляемых поставщиком под номером ?.
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
-- ВАРИАНТ 04
------------------------------------------------------------
ALTER PROCEDURE Query16
-- Найти всех поставщиков, поставляющих продукты, цена которых отличается не более чем на 10% от текущей средней цены продуктов.
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
-- Выбрать информацию обо всех поставках, таких, что поставщик и поставляемый им продукт находятся в одном городе.
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
-- Указать номера продуктов, поставляемых более чем одним поставщиком
-- Получить все пары «номер поставщика – номер продукта», причем только такие, в которых данный поставщик не поставляет данный продукт.
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
-- Указать имена поставщиков, статус которых меньше текущего среднего статуса в таблице поставщиков.
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
-- Определить в поставках максимальное и минимальное количество продуктов с номером ?.
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
-- ВАРИАНТ 05
------------------------------------------------------------
ALTER PROCEDURE Query21 @SupplierID int, @ProductID int
-- Определить общее количество продуктов с номером ?, поставляемых поставщиком под номером ?.
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
-- Определить имена поставщиков из города ? со статусом больше ?.
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
-- Найти всех поставщиков, поставляющих дорогие продукты. Цена таких продуктов отличается от цены самого дорогого продукта не более чем в 4 раза.
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
-- Определить номера и вес всех типов продуктов, вес которых превышает ?.
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
-- Для каждого продукта выбрать номер и общий объем поставки в штуках.
BEGIN
	SELECT ProductID, SUM(Qty) AS 'Total Number'
	FROM Shipments
	GROUP BY ProductID
END;
GO
EXEC Query25;
GO
------------------------------------------------------------
-- ВАРИАНТ 06
------------------------------------------------------------
CREATE PROCEDURE Query26
-- Указать названия продуктов, цена которых больше текущей средней цены в таблице продуктов.
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
-- Определить общее количество поставляемых продуктов.
AS
BEGIN
	SELECT COUNT(DISTINCT ProductID) AS 'Total Number'
	FROM Shipments
END;
GO
EXEC Query27; 
GO
ALTER PROCEDURE Query28 @MinPrice money, @MaxPrice money
-- Найти всех поставщиков, поставляющих продукты, находящиеся в ценовом диапазоне от ? до ? включительно.
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
-- Определить продукты, которые никем не поставляются.
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
-- Найти все пары названий городов, таких, что поставщик из первого города поставляет продукт, находящийся в другом городе.
AS
BEGIN
	SELECT DISTINCT s.City AS 'First City', p.City AS 'Second City'
	FROM Suppliers s JOIN Shipments t ON s.SupplierID = t.SupplierID JOIN
		Products p ON t.ProductID = p.ProductID
END;
GO
EXEC Query30; 
GO



							



