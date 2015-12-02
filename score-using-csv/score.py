# -*- coding: utf-8 -*-
import csv


SCORE_TABLE_PATH='data/sample-score-table.csv'
SCORE_POINTS_PATH='data/score-points.csv'
PERFECT_SCORE = 9


class ScoreUsingCSV():

    def __init__(self):
        self.SCORE_TABLE_PATH = SCORE_TABLE_PATH
        self.SCORE_POINTS_PATH = SCORE_POINTS_PATH
        self.PERFECT_SCORE = PERFECT_SCORE

    def get_score_points(self):
        """
        It returns dict instance
        """

        with open(self.SCORE_POINTS_PATH) as csvfile:
            reader = csv.DictReader(csvfile)
            return next(reader)

    def signsToPoints(self, score_line, score_points):
        cut_in_marks = {}
        for key in score_line.keys():
            if score_line[key] == '2':
                cut_in_marks[key] = 2
            elif score_line[key] == '1':
                cut_in_marks[key] = 1
            elif score_line[key] == 'x':
                cut_in_marks[key] = int(score_points[key])

        return cut_in_marks

    def point_calculator(self, cut_in_marks):
        print(cut_in_marks.values())
        return self.PERFECT_SCORE - sum(cut_in_marks.values())

    def make_score_comment(self, score_line):
        for key, value in score_line.items():
            if value == 'o':
                pass
            print("사유 : '%s'의 사유로 %s점 감점" % (key, value))

    def score(self):
        with open(self.SCORE_TABLE_PATH, 'r') as csvfile:
            score_table = csv.DictReader(csvfile)
            score_points = self.get_score_points()
            for score_line in score_table:
                print(self.point_calculator(score_line, score_points))
                print(self.make_score_comment(score_line))
