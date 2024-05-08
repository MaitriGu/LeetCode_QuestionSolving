class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        index_map = {score[i]: i for i in range(len(score))}
        sorted_scores = sorted(score, reverse=True)
        ranks = {}
        for i, s in enumerate(sorted_scores):
            if i == 0:
                ranks[s] = "Gold Medal"
            elif i == 1:
                ranks[s] = "Silver Medal"
            elif i == 2:
                ranks[s] = "Bronze Medal"
            else:
                ranks[s] = str(i + 1)
        result = [ranks[score[i]] for i in range(len(score))]
        return result
