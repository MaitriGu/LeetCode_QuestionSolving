# Write your MySQL query statement below
Select contest_id,ROUND(COUNT(DISTINCT user_id)*100.0/(Select COUNT(user_id)
From Users),2) as percentage
From Register 
Group By contest_id
Order By percentage desc,contest_id asc;

