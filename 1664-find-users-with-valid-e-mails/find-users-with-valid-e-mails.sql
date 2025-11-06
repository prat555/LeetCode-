SELECT * FROM Users
WHERE mail REGEXP '^[A-Za-z][A-Za-z0-9_.-]*@leetcode[.]com$' COLLATE utf8mb4_0900_as_cs;