from eighteen import FrequencyList

import unittest


class TestWhat(unittest.TestCase):

    def test_correct_contents(self):
        self.intList = FrequencyList(list(range(10)))
        for i in range(10):
            self.assertEqual(self.intList[i], i)

    def test_frequency(self):
        self.repeatList = FrequencyList([1] * 3 + [2] * 2)
        freqs = self.repeatList.frequency()
        self.assertEqual(freqs[1], 3)
        self.assertEqual(freqs[2], 2)
