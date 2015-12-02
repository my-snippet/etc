import csv


def get_score_points(path):
    with open(path) as csvfile:
        reader = csv.DictReader(csvfile)
        return next(reader)


def get_key(path):
    with open(path) as csvfile:
        score_table = {}
        keyReader = csv.reader(csvfile, delimiter=',', quotechar='|')
        for col in next(keyReader):
            score_table.update({col: None})
        return score_table


SCORE_TABLE_PATH='data/sample-score-table.csv'
SCORE_POINTS_PATH='data/score-points.csv'
score_table = get_key(SCORE_TABLE_PATH)
score_points = get_score_points(SCORE_POINTS_PATH)
print(score_table)
print(score_points)
