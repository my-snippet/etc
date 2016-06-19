from pingpong import Pingpong

import unittest


class TestPingpong(unittest.TestCase):

    def setUp(self):
        self.pingpong = Pingpong()
        self.data = [1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 2, 1, 0, -1, 0, 1]

    def test_is_change_should_detect_multiples_of_seven(self):
        for i in range(1, 100):
            self.assertTrue(Pingpong.is_change(i*7))
