import numpy as np
import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    employee = employee.drop_duplicates(subset=['salary'])
    if len(employee['salary']) < N:
        return pd.DataFrame({'SecondHighestSalary': [np.nan]})
    employee = employee.sort_values(by='salary', ascending=False)
    return pd.DataFrame({'getNthHighestSalary({})'.format(N): employee['salary'].head(N).tail(1)})

if __name__ == "__main__":
    employee = pd.DataFrame({"salary": [100, 200]})
    res = nth_highest_salary(employee, 2)
    print(res)
