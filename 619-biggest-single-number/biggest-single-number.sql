select max(num) as num from mynumbers where num in 
(select num from mynumbers group by 1 having count(num)=1)
