import csv


SCORE_TABLE_PATH='data/sample-score-table.csv'
SCORE_POINTS_PATH='data/score-points.csv'


class ScoreUsingCSV():

    def __init__(self):
        self.SCORE_TABLE_PATH = SCORE_TABLE_PATH
        self.SCORE_POINTS_PATH = SCORE_POINTS_PATH

    def get_score_points(self):
        """
        It returns dict instance
        """
    
        with open(self.SCORE_POINTS_PATH) as csvfile:
            reader = csv.DictReader(csvfile)
            return next(reader)
    
    def point_calculator(self, score_line, score_points):
        score = 9

        for key in score_line.keys():
            if score_line[key] == '2':
                score = score - 2
            elif score_line[key] == '1':
                score = score - 1
            elif score_line[key] == 'x':
                score = score - int(score_points[key])

        if score < 0:
            score = 0

        return score

    def score(self):
        with open(self.SCORE_TABLE_PATH, 'r') as csvfile:
            score_table = csv.DictReader(csvfile)
            score_points = self.get_score_points()
            for score_line in score_table:
                print(self.point_calculator(score_line, score_points))
