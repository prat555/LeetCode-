WITH DuplicateTIV AS (
    SELECT tiv_2015
    FROM Insurance
    GROUP BY tiv_2015
    HAVING COUNT(*) > 1
),
UniqueLocation AS (
    SELECT lat, lon
    FROM Insurance
    GROUP BY lat, lon
    HAVING COUNT(*) = 1
)
SELECT ROUND(SUM(i.tiv_2016), 2) AS tiv_2016
FROM Insurance i
INNER JOIN DuplicateTIV dt ON i.tiv_2015 = dt.tiv_2015
INNER JOIN UniqueLocation ul ON i.lat = ul.lat AND i.lon = ul.lon;