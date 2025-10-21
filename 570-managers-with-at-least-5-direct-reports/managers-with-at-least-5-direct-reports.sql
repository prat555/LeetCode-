select m.name from employee e inner join employee m
on (e.managerId=m.id)
group by m.id having count(*)>=5