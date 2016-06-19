# -*- coding: utf-8 -*-
from pingpong import Pingpong

import unittest


class TestPingpong(unittest.TestCase):

    def setUp(self):
        self.pingpong = Pingpong()
        self.data = [1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 2, 1, 0, -1, 0, 1]

    def test_is_change_should_detect_multiples_of_seven(self):
        for i in range(1, 100):
            self.assertTrue(Pingpong.is_change(i*7))

    def test_is_change_should_detect_number_contains_seven(self):
        '''
        데이터 중에 7이 한개라도 포함되면 그것을 감지할 수 있어야 한다. 예를 
        들어, 7, 17, ..., 97이나 70, 71, ...79, 또는 700, 701, ...709 등이 
        해당한다. 
        '''
        seven = 7
        seventy = 70
        seven_hundred = 700
        for i in range(0, 10):
            self.assertTrue(Pingpong.is_change(seven+10*i))
            self.assertTrue(Pingpong.is_change(seventy+i))
            self.assertTrue(Pingpong.is_change(seven_hundred+i))

        self.assertFalse(Pingpong.is_change(6))
