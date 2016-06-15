from phonebook import Phonebook

import unittest
from string import ascii_uppercase


class TestPhoneBook(unittest.TestCase):

    def setUp(self):
        self.members = {}
        for idx, name in enumerate(ascii_uppercase):
            self.members.update({name: '920-1234-567' + str(idx)})
        self.book = Phonebook()

    def test_add_book(self):
        self.assertTrue(self.book.add_book())
