import numpy as np
import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    scores['rank'] = scores['score'].rank(method='dense', ascending=False)
    return scores[['score', 'rank']].sort_values(by='score', ascending=False)

if __name__ == "__main__":
    scores = pd.DataFrame({'id': [1,2,3,4,5,6], 'score': [3.50, 3.65, 4.00, 3.85, 4.00, 3.65]})
    res = order_scores(scores=scores)
    print(res)
