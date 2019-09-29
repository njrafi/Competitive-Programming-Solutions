select distinct CITY from station 
where left(CITY,1) in ('a','e','i','o','u') and
right(CITY,1) in ('a','e','i','o','u')