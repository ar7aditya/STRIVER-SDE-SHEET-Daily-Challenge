# Write your MySQL query statement below
select firstName , lastName , city , state from Person p
LEFT JOIN
Address a
ON p.personId = a.personId;
