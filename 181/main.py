import numpy as np
import pandas as pd

def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    df = employee.merge(employee, 'inner', left_on='managerId', right_on='id', suffixes=['_e', '_m'])
    df = df.loc[df['salary_e'] > df['salary_m'], ['name_e']]
    return df.rename(columns = {'name_e': 'Employee'})

if __name__ == "__main__":
    employee = pd.DataFrame({'id': [1,2,3,4],
                             'name': ['Joe', 'Henry', 'Sam', 'Max'],
                             'salary': [70000, 80000, 60000, 90000],
                             'managerId': [3, 4, np.nan, np.nan]}).set_index('id')
    res = find_employees(employee)
    print(res)
