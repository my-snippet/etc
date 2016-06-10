from functools import wraps


def double(func):
    def wrapper(*args, **kwargs):
        result = func(*args, *kwargs)
        return result * 2
    return wrapper

def fib(n):
    if n < 2:
        return n
    else:
        return fib(n-1) + fib(n-2)

@double
def identity(n):
    return n

def save_meta_data(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        return func(*args, *kwargs)
    return wrapper

@save_meta_data
def just_pass():
    pass
