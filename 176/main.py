import numpy as np
import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    employee = employee.drop_duplicates(subset=['salary'])
    if len(employee['salary']) < 2:
        return pd.DataFrame({'SecondHighestSalary': [np.nan]})
    employee = employee.sort_values(by='salary', ascending=False)
    return pd.DataFrame({'SecondHighestSalary': employee['salary'].head(2).tail(1)})

if __name__ == "__main__":
    employee = pd.DataFrame({"salary": [100, 200]})
    res = second_highest_salary(employee)
    print(res)
