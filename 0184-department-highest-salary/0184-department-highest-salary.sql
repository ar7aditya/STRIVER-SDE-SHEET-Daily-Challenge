select d.name as Department , e.name as Employee , e.salary as Salary 
from Employee e
JOIN Department d
ON e.departmentId = d.id 
where 
1 > ( select count(distinct salary) from Employee e2 where e2.salary > e.salary and e2.departmentId = d.id)

