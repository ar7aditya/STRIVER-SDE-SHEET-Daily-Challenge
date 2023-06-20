# Write your MySQL query statement below

                    # mine query
# select distinct salary as SecondHighestSalary from Employee e1 where 1=
# (select count(distinct(e2.salary)) from Employee e2 where e2.salary > e1.salary );


SELECT DISTINCT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE Salary< (SELECT MAX(salary) FROM Employee)
