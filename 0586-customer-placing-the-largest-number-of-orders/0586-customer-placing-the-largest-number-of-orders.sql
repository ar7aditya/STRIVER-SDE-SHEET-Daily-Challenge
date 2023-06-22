# Write your MySQL query statement below


# with ct1 as (select customer_number , count(customer_number) as tot from Orders group by customer_number)
# select c.customer_number from ct1 c where c.tot = (select max(p.tot) from ct1 p );

select customer_number from orders 
group by customer_number
order by count(customer_number) desc
limit 1;