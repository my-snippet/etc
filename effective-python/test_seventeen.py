from seventeen import normalize

import unittest


class TestDefensiveIteration(unittest.TestCase):

    def setUp(self):
        self.visits = [15, 30, 80]

    def test_stop_iter_exeception(self):
        normalize(self.visits)
        self.assertEqual([], normalize(self.visits))
