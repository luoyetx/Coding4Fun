select d.Name Department, e.Name Employee, e.Salary
from Employee as e, Department as d
where d.Id = e.DepartmentID and 3 > (
    select count(distinct(e2.Salary))
    from Employee as e2
    where e2.Salary > e.Salary and e2.DepartmentID = e.DepartmentID
)
