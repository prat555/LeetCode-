select s.machine_id, round(avg(e.timestamp-s.timestamp),3) as processing_time
from activity s join activity  e
using (machine_id, process_id)
where s.activity_type='start' and e.activity_type='end'
group by 1;