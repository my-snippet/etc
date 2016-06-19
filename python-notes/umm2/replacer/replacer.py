def replacer(text, from_, to):
    return text.replace(from_, to)


def replacer_f(f, from_, to):
    with open(f, 'r') as f:
        return replacer(f.read(), from_, to)
