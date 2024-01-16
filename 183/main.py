import numpy as np
import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    df = customers[~customers['id'].isin(orders['customerId'])]
    df = df[['name']].rename(columns={'name': 'Customers'})
    return df

if __name__ == "__main__":
    # employee = pd.DataFrame({'id': [1,2,3,4],
    #                          'name': ['Joe', 'Henry', 'Sam', 'Max'],
    #                          'salary': [70000, 80000, 60000, 90000],
    #                          'managerId': [3, 4, np.nan, np.nan]}).set_index('id')
    # res = find_employees(employee)
    # print(res)
    pass
