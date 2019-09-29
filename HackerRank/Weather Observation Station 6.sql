select distinct city from station
where substring(city,1,1) = 'a' or
substring(city,1,1) = 'e' or
substring(city,1,1) = 'i' or
substring(city,1,1) = 'o' or
substring(city,1,1) = 'u' 