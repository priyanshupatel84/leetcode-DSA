# Write your MySQL query statement below
select a1.machine_id, round(avg(abs(a1.timestamp-a2.timestamp)), 3) as processing_time
from Activity a1
join Activity a2 on a1.machine_id = a2.machine_id and a1.process_id = a2.process_id and a1.activity_type='start' and a2.activity_type='end'
group by a1.machine_id;
