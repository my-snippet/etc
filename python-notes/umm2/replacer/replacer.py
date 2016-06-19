#!/usr/bin/env python
import sys


def replacer(text, from_, to):
    return text.replace(from_, to)


def replacer_f(file_path, from_, to):
    result = ''
    with open(file_path, 'r') as f:
        result = replacer(f.read(), from_, to)

    print(result)
    return result


if __name__ == "__main__":
    replacer_f(sys.argv[1], sys.argv[2], sys.argv[3])
