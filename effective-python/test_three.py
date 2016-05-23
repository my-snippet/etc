from three import to_str

import unittest


class TestStringTypes(unittest.TestCase):

    def setUp(self):
        self.str_type = u"str"
        self.bytes_type = b"bytes"

    def test_assertFalse(self):
        self.assertFalse(False)

    def test_setup_variable_type(self):
        self.assertTrue(isinstance(self.str_type, str))
        self.assertTrue(isinstance(self.bytes_type, bytes))

    def test_bytes_to_str(self):
        bytes_to_str = to_str(self.bytes_type)
        self.assertTrue(isinstance(bytes_to_str, str))
