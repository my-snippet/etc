class Pingpong():

    @staticmethod
    def pingpong(index):
        def iter(count, result, addend):
            def next_(addend):
                return result + addend
            if count < index:
                if Pingpong.is_change(count):
                    return iter(count+1, next_(addend * (-1)), addend * (-1))
                return iter(count+1, next_(addend), addend)
            return result
        return iter(1, 1, 1)

    @staticmethod
    def is_change(index):
        def is_multiple_of_seven():
            if (index % 7) == 0:
                return True

        def is_number_contains_seven():
            if str(index).find('7') != -1:
                return True

        if is_multiple_of_seven() or is_number_contains_seven():
            return True
        return False
