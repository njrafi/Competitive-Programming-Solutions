SELECT 
    CASE 
        when (A + B) <= C or (B + C) <= A or (A + C) <= B then 'Not A Triangle'
        WHEN A = B and B = C and C = A THEN 'Equilateral'
        when A = B or B=C or C = A then 'Isosceles'
        ELSE 'Scalene'
    END AS gg
    FROM TRIANGLES;