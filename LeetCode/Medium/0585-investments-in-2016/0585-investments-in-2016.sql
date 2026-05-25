# Write your MySQL query statement below
SELECT 
    ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM 
    Insurance
WHERE 
    -- Condition 1: tiv_2015 is not unique
    tiv_2015 IN (
        SELECT tiv_2015 
        FROM Insurance 
        GROUP BY tiv_2015 
        HAVING COUNT(*) > 1
    )
    -- Condition 2: The (lat, lon) pair is completely unique
    AND (lat, lon) IN (
        SELECT lat, lon 
        FROM Insurance 
        GROUP BY lat, lon 
        HAVING COUNT(*) = 1
    );