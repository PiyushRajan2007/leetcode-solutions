# Write your MySQL query statement below
WITH FilteredStadium AS (
    -- Step 1: Filter rows with >= 100 people first
    SELECT 
        id, 
        visit_date, 
        people
    FROM 
        Stadium
    WHERE 
        people >= 100
),
GroupedStadium AS (
    -- Step 2: Use an island-grouping trick. 
    -- If IDs are consecutive, (id - ROW_NUMBER()) will stay constant!
    SELECT 
        id, 
        visit_date, 
        people,
        id - ROW_NUMBER() OVER (ORDER BY id) AS island_group
    FROM 
        FilteredStadium
),
IslandCounts AS (
    -- Step 3: Count how many rows are in each consecutive island group
    SELECT 
        id, 
        visit_date, 
        people,
        COUNT(*) OVER (PARTITION BY island_group) AS group_size
    FROM 
        GroupedStadium
)
-- Step 4: Keep only the rows belonging to an island of size 3 or greater
SELECT 
    id, 
    visit_date, 
    people
FROM 
    IslandCounts
WHERE 
    group_size >= 3
ORDER BY 
    visit_date ASC;