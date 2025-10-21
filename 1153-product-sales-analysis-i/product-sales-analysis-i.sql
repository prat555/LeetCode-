select p.product_name, s.year, s.price
from sales s inner join product p
using (product_id);