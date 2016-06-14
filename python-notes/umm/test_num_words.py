from num_words import num_words

import unittest


class TestNumbersWords(unittest.TestCase):

    def setUp(self):
        self.text = 'a b ' * 10 + 'c ' * 11

    def test_num_words(self):
        # 2 <- 10: a, b
        self.assertEqual(2, num_words(10, self.text))

        # 1 <- 11: c
        self.assertEqual(1, num_words(11, self.text))
