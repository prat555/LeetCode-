with py as (select product_id, min(year) as year from sales group by 1)
select s.product_id, p.year as first_year, s.quantity, s.price from sales s inner join py p
using (product_id,year)