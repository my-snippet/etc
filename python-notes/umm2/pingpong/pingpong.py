class Pingpong():

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
