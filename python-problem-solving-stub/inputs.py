def checker(pred, values, error_msg=''):
    if pred(values):
        return values
    else:
        raise ValueError(error_msg)


def inputs(pred, values=None, error_msg=''):
    if values is None:
        raise ValueError("No value inserted")
    elif callable(values):
        return checker(pred, values(), error_msg)
    else:
        return checker(pred, values, error_msg)


def user_inputs():
    return input()
