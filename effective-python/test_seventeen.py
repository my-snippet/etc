from seventeen import normalize

import unittest


class TestDefensiveIteration(unittest.TestCase):

    def setUp(self):
        self.visits = [15, 30, 80]

    def test_no_next_iter(self):
        percentages = normalize(self.visits)
        self.assertEqual([], percentages)
