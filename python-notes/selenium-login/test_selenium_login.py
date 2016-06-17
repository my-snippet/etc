from selenium_login import login

import unittest
from os import environ
from selenium import webdriver


class TestSeleniumLogin(unittest.TestCase):

    def setUp(self):
        self.url = environ.get('LOGIN_URL')
        self.username = environ.get('ID')
        self.password = environ.get('PASSWORD')

        self.browser = webdriver.Firefox()
        self.browser.implicitly_wait(3)
        self.browser.get(self.url)

    def tearDown(self):
        self.browser.quit()

    def test_saint_login_id_selectors(self):
        self.assertTrue(
            self.browser.find_element_by_id('logonuidfield')
        )

    def test_saint_login_password_selectors(self):
        self.assertTrue(
            self.browser.find_element_by_id('logonpassfield')
        )

    def test_login(self):
        self.assertTrue(
            login(self.url, self.username, self.password)
        )
