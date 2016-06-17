from selenium_login import login

import unittest
from os import environ
from selenium import webdriver
from selenium.webdriver.common.keys import Keys


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

    @unittest.skip("")
    def test_saint_login_inputbox_selector(self):
        self.assertTrue(
            self.browser.find_element_by_name('login_submit')
        )

    def test_saint_login(self):
        id_field = self.browser.find_element_by_id('logonuidfield')
        id_field.send_keys(self.username)
        password_field = self.browser.find_element_by_id('logonpassfield')
        password_field.send_keys(self.password)
        id_field.send_keys(Keys.ENTER)

        session_text = self.browser.find_element_by_class_name("fontS02")
        self.assertIn("님 접속을 환영합니다.", session_text.text)


    @unittest.skip("")
    def test_login(self):
        self.assertTrue(
            login(self.url, self.username, self.password)
        )
