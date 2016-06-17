from selenium_login import login

import unittest
from os import environ


class TestSeleniumLogin(unittest.TestCase):

    def setUp(self):
        self.login_url = environ.get('LOGIN_URL')
        self.username = environ.get('ID')
        self.password = environ.get('PASSWORD')

    def test_login(self):
        self.assertTrue(
            login(self.login_url, self.username, self.password)
        )
