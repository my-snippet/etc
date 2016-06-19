# -*- coding: utf-8 -*-
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
        '''
        텍스트는 10개의 단어로 이루어져 있으며 모두 동일한 단어수를 가집니다.
        예를 들어, word0, word1, ... word10으로 구성됩니다. 만약 word0를 모두 
        word1로 바꾼다면 텍스트 내에 word0는 0개이며, word1은 그외 다른 
        단어 갯수의 2배가 됩니다.

        프로그램은 관여하는 두 단어(바꿀 단어, 바뀔 단어) 외에는 영향을 
        미쳐서는 안됩니다. 이를 단어 단위로 확인하기로 합니다.
        '''

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
