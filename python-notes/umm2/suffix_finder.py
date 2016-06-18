import os


def suffix_finder(dir_path, suffix):
    result = []

    files = os.listdir(dir_path)
    for f in files:
        if f.endswith(suffix) and f[1:].count('.') == 1:
            result.append(dir_path + '/' + f)
    return result
