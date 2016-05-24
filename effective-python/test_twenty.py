from twenty import log_static

import unittest
import time


class TestDynamic(unittest.TestCase):

    def setUp(self):
        pass 

    def test_log_static_return_same_timestamp(self):
        first_time = log_static('')
        time.sleep(1)
        second_time = log_static('')
        self.assertEqual(first_time, second_time)
