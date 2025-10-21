select s.student_id, s.student_name, j.subject_name, count(e.subject_name) as attended_exams
from students s cross join subjects j left join examinations e
using (student_id, subject_name)
group by 1,2,3 order by s.student_id, s.student_name
