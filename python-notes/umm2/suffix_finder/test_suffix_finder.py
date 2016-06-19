from suffix_finder import suffix_finder

import unittest
import os
import shutil


class TestSuffixFinder(unittest.TestCase):

    def setUp(self):
        self.dir_path = os.getcwd() + '/' + 'test_dir'
        os.makedirs(self.dir_path)

        self.suffixes = ['.suffix1', '.suffix2']
        self.suffix1_file_paths = []
        for i in range(10):
            suffix1_path = self.dir_path + '/' + \
                'file_suffix1_' + str(i) + self.suffixes[0]
            suffix2_path = self.dir_path + '/' + \
                'file_suffix2_' + str(i) + self.suffixes[1]

            self.suffix1_file_paths.append(suffix1_path)

            with open(suffix1_path, 'w') as f:
                pass
            with open(suffix2_path, 'w') as f:
                pass

    def tearDown(self):
        shutil.rmtree(self.dir_path)

    def test_check_result_and_pre_defined_files_same(self):
        result = suffix_finder(self.dir_path, self.suffixes[0])
        self.assertEqual(set(self.suffix1_file_paths), (set(result)))
