from replacer import replacer, replacer_f

import unittest
import os


class TestReplacer(unittest.TestCase):

    def setUp(self):
        self.words = []
        self.kind_of_words = 10
        self.each_word_num = 100

        for i in range(self.kind_of_words):
            self.words.append('word' + str(i))

        self.text = ''
        self.file_name = 'replace_file.txt'
        with open(self.file_name, 'w+') as f:
            for i in range(self.each_word_num):
                for j in range(self.kind_of_words):
                    f.write(self.words[j])

            f.seek(0)
            self.text = f.read()

    def tearDown(self):
        os.remove(self.file_name)

    def test_replacer_should_affects_only_from_and_to(self):
        from_ = self.words[0]
        to = self.words[1]
        text = replacer(self.text, from_, to)

        self.assertEqual(text.count(from_), 0)
        self.assertEqual(text.count(to), self.each_word_num * 2)
        for i in range(2, self.kind_of_words):
            self.assertEqual(text.count(self.words[i]), self.each_word_num)

    def test_replacer_using_file_text(self):
        from_ = self.words[0]
        to = self.words[1]
        text = replacer_f(self.file_name, from_, to)
        self.assertEqual(text.count(from_), 0)
        self.assertEqual(text.count(to), self.each_word_num * 2)
        for i in range(2, self.kind_of_words):
            self.assertEqual(text.count(self.words[i]), self.each_word_num)
