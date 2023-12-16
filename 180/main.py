import numpy as np
import pandas as pd

def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    nums = logs['num']
    res = set()
    for i in range(1, len(nums) - 1):
        if nums[i - 1] == nums[i] == nums[i + 1]:
            res.add(nums[i])
            i += 3
        elif nums[i] != nums[i + 1]:
            i += 2
        else: # nums[i] != nums[i - 1]
            i += 1
    return pd.DataFrame({'ConsecutiveNums': list(res)})

if __name__ == "__main__":
    logs = pd.DataFrame({'id': [1,2,3,4,5,6,7], 'num': [1,1,1,2,1,2,2]})
    res = consecutive_numbers(logs)
    print(res)
