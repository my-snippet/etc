from fortytwo import fib, identity, just_pass

import unittest


class TestDecorator(unittest.TestCase):

    def test_fib(self):
        self.assertEqual(fib(1), 1)
        self.assertEqual(fib(2), 1)
        self.assertEqual(fib(3), 2)
        self.assertEqual(fib(4), 3)
        self.assertEqual(fib(5), 5)

    def test_double(self):
        for i in range(10):
            self.assertEqual(identity(i), i*2)

    def test_decorated_func_name_without_wraps(self):
        self.assertEqual(identity.__name__, 'wrapper')

    def test_decorated_func_name_with_wraps(self):
        self.assertEqual(just_pass.__name__, 'just_pass')
