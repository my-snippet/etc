from selenium import webdriver
from selenium.webdriver.common.keys import Keys


def login(url, username, password):
    browser = webdriver.Firefox()
    browser.implicitly_wait(3)

    browser.get(url)
    id_field = browser.find_element_by_id('logonuidfield')
    id_field.send_keys(username)
    password_field = browser.find_element_by_id('logonpassfield')
    password_field.send_keys(password)
    id_field.send_keys(Keys.ENTER)

    return browser
