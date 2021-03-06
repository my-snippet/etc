#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os
import sys


def suffix_finder(dir_path, suffix):
    '''
    os.listdir을 이용하면 해당 디렉토리가 가진 노드(파일 또는 서브디렉토리)를
    알 수 있습니다. 여기서 '파일이냐 디렉토리냐'를 명확히 구분하지 않고
    확장자(extension)의 여부로 판별하기로 한다면 문제는 한결 쉽게 풀립니다.

    문자열 끝이 찾으려는 확장자와 같고, 확장자가 가진 '.'의 개수보다 많지
    않다는 하에 조건은 참이 됩니다. 예를 들면 '.xyz'와 '.com.xyz'는 다른
    확장자입니다.

    * 다만 첫 문자는 dot 파일일 수 있으니 제외하여 검사하기로 합니다.
    * 그외 prefix로 점을 여러개 붙인 '..[file name]'와 같은 유형의 파일은
    고려하지 않았습니다.
    '''
    result = []

    dir_abspath = os.path.abspath(dir_path)
    files = os.listdir(dir_abspath)
    for f in files:
        if f.endswith(suffix) and suffix.count('.') == f[1:].count('.'):
            result.append(dir_abspath + '/' + f)
    print(result)
    return result


if __name__ == "__main__":
    suffix_finder(sys.argv[1], sys.argv[2])
