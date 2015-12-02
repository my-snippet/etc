# -*- coding: utf-8 -*-
import csv
import os

from sendgrid_email import send_email


SCORE_TABLE_PATH = 'data/confidential/score-table-1.csv'
SCORE_POINTS_PATH = 'data/score-points.csv'
RESULT_TABLE_PATH = 'data/confidential/result-table-1.csv'
PERFECT_SCORE = 9


class ScoreUsingCSV():

    def __init__(self):
        self.SCORE_TABLE_PATH = SCORE_TABLE_PATH
        self.SCORE_POINTS_PATH = SCORE_POINTS_PATH
        self.PERFECT_SCORE = PERFECT_SCORE
        self.RESULT_TABLE_PATH = RESULT_TABLE_PATH

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
        point = self.PERFECT_SCORE - sum(cut_in_marks.values())
        if point < 0:
            point = 0
        return point

    def make_score_comment(self, cut_in_marks):
        def point_comment():
            return str(point) + "점입니다."

        def cut_in_marks_comment(comment):
            comment = comment + "<br><br>"
            comment = comment + "&lt;사유&gt;<br>"
            for key, value in cut_in_marks.items():
                if value == 'o':
                    pass
                comment = comment + "'" + str(key) + "'의 사유로 " +\
                    str(value) + "점 감점<br>"
            return comment

        point = self.point_calculator(cut_in_marks)
        comment = point_comment()
        if point == self.PERFECT_SCORE:
            return comment
        return cut_in_marks_comment(comment)

    def write_score_result(self, keys, comment_key='코멘트'):
        def write_from_score_table():
            def make_score_result_dicts():
                score_line[comment_key] = self.make_score_comment(cut_in_marks)
                dicts = {}
                for key in keys:
                    dicts.update({key: score_line[key]})
                return dicts

            with open(self.RESULT_TABLE_PATH, 'w') as csvfile:
                writer = csv.DictWriter(csvfile, fieldnames=keys)

                writer.writeheader()
                for score_line in score_table:
                    cut_in_marks = self.signsToPoints(score_line, score_points)
                    writer.writerow(make_score_result_dicts())

        with open(self.SCORE_TABLE_PATH, 'r') as csvfile:
            score_table = csv.DictReader(csvfile)
            score_points = self.get_score_points()
            write_from_score_table()

    def send_email_from_result(self, comment_key='코멘트'):
        with open(self.RESULT_TABLE_PATH, 'r') as csvfile:
            reader = csv.DictReader(csvfile)
            for row in reader:
                send_email(
                    row['코멘트'],
                    [os.environ['DEFAULT_TO'], os.environ['DEFAULT_TO_2'], row['이메일']])
