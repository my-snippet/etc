from temparature import Temparature

import unittest


class TestTemparature(unittest.TestCase):

    def test_setter_get(self):
        tmpt = Temparature(10)
        self.assertEqual(tmpt.farenheit, 50)
        tmpt.temparature = 20
        self.assertEqual(tmpt.celsius, 20)
        self.assertEqual(tmpt.farenheit, 68)
