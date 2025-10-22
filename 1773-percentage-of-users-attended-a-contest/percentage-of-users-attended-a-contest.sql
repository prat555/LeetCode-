select r.contest_id, round(count(user_id)*100/(select count(*) from users),2) as percentage
from users u join register r
using (user_id) group by 1
order by 2 desc, 1 asc