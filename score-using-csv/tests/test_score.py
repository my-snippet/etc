import unittest
import csv

import score


class TestScoreUsingCSV(unittest.TestCase):

    def setUp(self):
        self.SCORE_TABLE_PATH = score.SCORE_TABLE_PATH
        self.SCORE_POINTS_PATH = score.SCORE_POINTS_PATH
        self.score = score.ScoreUsingCSV()

    def test_point_calculator(self):
        """
        Sample scores are [4, 3, 2, 9]
        """
        expected_scores = [4, 3, 2, 9]
        result_scores = []

        with open(self.SCORE_TABLE_PATH, 'r') as csvfile:
            score_table = csv.DictReader(csvfile)
            score_points = self.score.get_score_points()
            for idx, score_line in enumerate(score_table, start=0):
                self.assertEqual(
                    expected_scores[idx],
                    self.score.point_calculator(score_line, score_points)
                )
