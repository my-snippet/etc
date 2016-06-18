from suffix_finder import suffix_finder

import unittest
import os
import shutil


class TestSuffixFinder(unittest.TestCase):

    def setUp(self):
        self.path = os.getcwd()
        self.test_dir = 'test_dir'
        os.makedirs(self.test_dir)

        self.suffixes = ['.suffix1', '.suffix2']
        self.suffix1_paths = []
        for i in range(10):
            suffix1_path = self.path + '/' + self.test_dir + '/' + \
                'file_suffix1_' + str(i) + self.suffixes[0]
            suffix2_path = self.path + '/' + self.test_dir + '/' + \
                'file_suffix2_' + str(i) + self.suffixes[1]

            self.suffix1_paths.append(suffix1_path)

            with open(suffix1_path, 'w') as f:
                pass
            with open(suffix2_path, 'w') as f:
                pass

    def tearDown(self):
        shutil.rmtree(self.test_dir)

    def test_check_result_and_pre_defined_files_same(self):
        result = suffix_finder(self.test_dir)
        assertEqual(set(files), (set(result)))
