import pandas as pd

def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    res = pd.merge(person, address, 'left', 'personId')
    res = res[['firstName', 'lastName', 'city', 'state']]
    return res
