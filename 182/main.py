import numpy as np
import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    email_counts = person.groupby('email').size().reset_index(name='num')
    duplicated_emails_df = email_counts[email_counts['num'] > 1][['email']]
    return duplicated_emails_df

if __name__ == "__main__":
    # employee = pd.DataFrame({'id': [1,2,3,4],
    #                          'name': ['Joe', 'Henry', 'Sam', 'Max'],
    #                          'salary': [70000, 80000, 60000, 90000],
    #                          'managerId': [3, 4, np.nan, np.nan]}).set_index('id')
    # res = find_employees(employee)
    # print(res)
    pass
