select e.name, b.bonus
from employee e left join bonus b
using (empId)
where b.bonus<1000 || b.bonus is null